---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - class

---

<div class="doxyPage">

# `reporter_tap` Class

<p>TAP (Test Anything Protocol) implementation of <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a></span>. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
class micro_os_plus::micro_test_plus::detail::reporter_tap { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>"
</div>

## Base class

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Abstract base class for the reporters that display test results, including operand values for failures. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#details">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a788b72a9bc3181ad600738402eb1839c">reporter_tap</a> (const reporter_tap &amp;)=delete</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deleted copy constructor to prevent copying. <a href="#a788b72a9bc3181ad600738402eb1839c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a8ab19d5802719647f6429e69f3b86345">reporter_tap</a> (const runner_options &amp;opts)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructor for the <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap">reporter_tap</a> class. <a href="#a8ab19d5802719647f6429e69f3b86345">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a14652a1ac9c36386c738551529b9525b">reporter_tap</a> (reporter_tap &amp;&amp;)=delete</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deleted move constructor to prevent moving. <a href="#a14652a1ac9c36386c738551529b9525b">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#afec3839d3e8a890d8d3adafd81951d30">~reporter_tap</a> () override</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Destructor for the <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap">reporter_tap</a> class. <a href="#afec3839d3e8a890d8d3adafd81951d30">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Operators Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#acbdac50fb2a1302e4a97c8160e7fd7cb">operator&lt;&lt;</a> (bool v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for boolean values. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#acbdac50fb2a1302e4a97c8160e7fd7cb">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5d29d78c80c20d3fe96ac9d0f4a969b3">operator&lt;&lt;</a> (char c)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for a single character. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5d29d78c80c20d3fe96ac9d0f4a969b3">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ad84ba0969733f2120622d26951259f95">operator&lt;&lt;</a> (const char *s)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for a constant character string. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ad84ba0969733f2120622d26951259f95">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aedfa17028026f6eaa871214da441e90c">operator&lt;&lt;</a> (indentation m)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/indentation">indentation</a></span> manipulator. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aedfa17028026f6eaa871214da441e90c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#af4b5f0d3207f22b402bf4079a7547c1c">operator&lt;&lt;</a> (reporter &amp;(*func)(reporter &amp;))</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for stream manipulators, such as <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">endl</a></span>. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#af4b5f0d3207f22b402bf4079a7547c1c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac894cb9cbf11f2f57acb388310eede4c">operator&lt;&lt;</a> (std::nullptr_t)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for nullptr. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac894cb9cbf11f2f57acb388310eede4c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a54158cb2ca77354223506355247cab9a">operator&lt;&lt;</a> (std::string_view sv)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for std::string_view. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a54158cb2ca77354223506355247cab9a">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;typename T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a3ff526c7ae5db0669d7db2adebf7cb2d">operator&lt;&lt;</a> (T *v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator to display any pointer. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a3ff526c7ae5db0669d7db2adebf7cb2d">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0cdaf2313f78a256b80f7bb7b279e2e6">operator&lt;&lt;</a> (T v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for arithmetic types. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0cdaf2313f78a256b80f7bb7b279e2e6">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a8ab19d5802719647f6429e69f3b86345">reporter_tap</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#afe3745c4194923880428e105848f6a13">operator=</a> (const reporter_tap &amp;)=delete</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deleted copy assignment operator to prevent copying. <a href="#afe3745c4194923880428e105848f6a13">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a8ab19d5802719647f6429e69f3b86345">reporter_tap</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a9da35382cc3f903728f5f1bed2c4a745">operator=</a> (reporter_tap &amp;&amp;)=delete</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deleted move assignment operator to prevent moving. <a href="#a9da35382cc3f903728f5f1bed2c4a745">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aa8802baefcb360f48451418c783ac413">abort_session</a> (const reflection::source_location &amp;location, bool is_requirement) override</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Reports the abort of the test execution. <a href="#aa8802baefcb360f48451418c783ac413">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#acaae91eea2deed1fe3f43b6453e7e656">begin_session</a> (const runner &amp;runner) override</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Marks the beginning of a test session. <a href="#acaae91eea2deed1fe3f43b6453e7e656">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a2c05a737bfe80c955a998dc801e964b5">begin_suite</a> (const suite &amp;suite) override</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Marks the beginning of a test suite. <a href="#a2c05a737bfe80c955a998dc801e964b5">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a0302f9f5b977b05139d73df3bbc18d69">begin_test_case</a> (const test_case &amp;test_case) override</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Marks the beginning of a test case. <a href="#a0302f9f5b977b05139d73df3bbc18d69">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const char *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#afc9cc4d9f74c89a0f1fbe4d39c40db92">comment_prefix</a> (void) const noexcept override</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns the TAP comment prefix string <span class="doxyComputerOutput">"# "</span>. <a href="#afc9cc4d9f74c89a0f1fbe4d39c40db92">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a287bad0e5eccee7df4a2c8517959bd0e">end_line</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends a line ending to the internal output buffer. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a287bad0e5eccee7df4a2c8517959bd0e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a7033819609bfad2db2ecc7a024e91b2c">end_session</a> (const runner &amp;runner) override</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Marks the end of a test session. <a href="#a7033819609bfad2db2ecc7a024e91b2c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a2d5ddae3195ab52a957927a1b455f7b8">end_suite</a> (const suite &amp;suite) override</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Marks the end of a test suite. <a href="#a2d5ddae3195ab52a957927a1b455f7b8">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ad15f7dbbf6a683441df40c502125adc3">end_test_case</a> (const test_case &amp;test_case) override</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Marks the end of a test case. <a href="#ad15f7dbbf6a683441df40c502125adc3">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a406cf77b7adcd5fe9417ce7bce4f3afb">fail</a> (const failure_info &amp;failure, const std::string &amp;expression, const test_case &amp;test_case)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Reports a failed condition. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a406cf77b7adcd5fe9417ce7bce4f3afb">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a314df80e98fe6fa5de008d6708a14925">fail_suite</a> (const std::string &amp;message, const suite &amp;suite) override</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Reports a failure of a test suite outside its test cases. <a href="#a314df80e98fe6fa5de008d6708a14925">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a804b593aefa158d92a72da43de57d242">flush_streams</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Flushes the standard output stream and the output file. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a804b593aefa158d92a72da43de57d242">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a083ecdfa952d7f8c372a61fbea309357">has_output_file_error</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns whether the output file could not be opened. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a083ecdfa952d7f8c372a61fbea309357">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ad9e6ccebc1904f723409ddb0caaddb3e">pass</a> (const std::string &amp;message, const std::string &amp;expression, const test_case &amp;test_case)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Reports a passed condition. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ad9e6ccebc1904f723409ddb0caaddb3e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a319f35d4af8c72af8b14a89b421c1c74">skip_suite</a> (const suite &amp;suite) override</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Reports a test suite skipped by the filter. <a href="#a319f35d4af8c72af8b14a89b421c1c74">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a31ccd7af941d06241ce16df9274abc38">skip_test_case</a> (const test_case &amp;test_case) override</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Reports a test case skipped by the filter. <a href="#a31ccd7af941d06241ce16df9274abc38">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914b">micro_test_plus::verbosity</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a467d1332df523b9acaa3ff82b0ebb714">verbosity</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deprecated access to the verbosity level. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a467d1332df523b9acaa3ff82b0ebb714">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ae074822d712fc3db3c09f5f2d2237072">write_buffer_to_console</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Writes the current buffered content to the console. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ae074822d712fc3db3c09f5f2d2237072">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a841b146b309b93422ae707094ba044f6">writes_passed_checks</a> (void) const noexcept override</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns whether the passed checks are written anywhere. <a href="#a841b146b309b93422ae707094ba044f6">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Protected Member Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5859ce31641330b243cfb5d1c6080859">clear_buffer</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Clears the output buffer. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5859ce31641330b243cfb5d1c6080859">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5cf73aaf67484b50c25ef42363d49337">commit_outer_results</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Writes the results of the outer test case, if any, before a nested test case begins or is skipped. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5cf73aaf67484b50c25ef42363d49337">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a37cba38a47d66a928a936ee081c6d88c">write_buffer_to_file</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Writes the current buffered content to the output file. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a37cba38a47d66a928a936ee081c6d88c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#abaee31ffca8e65c9af34f7f67227c5b3">write_console</a> (const char *format,...)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Writes formatted text to the console. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#abaee31ffca8e65c9af34f7f67227c5b3">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a90a541c6a9b1ddd3da9440358bfc704e">write_file</a> (const char *format,...)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Writes formatted text to the output file. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a90a541c6a9b1ddd3da9440358bfc704e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aeafdc8e05a6d80d9445f17ff354ee215">write_info</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Writes the informational (non-result) lines to the console and to the output file. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aeafdc8e05a6d80d9445f17ff354ee215">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">write_line</a> (bool to_console, const char *format,...)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Writes formatted lines to the output file and, when requested, to the console. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Private Member Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#af80ba6907c9f13b08f8cb8726d65c510">commit_buffer</a> (void) override</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Writes the results buffered for the outer test case before a nested test case begins. <a href="#af80ba6907c9f13b08f8cb8726d65c510">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a3bd1c7d455abc782062d0e23a3ef1015">output_fail_prefix</a> (const std::string &amp;message, const bool has_expression, const reflection::source_location &amp;location, const test_case &amp;test_case) override</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Outputs the prefix for a failing condition. <a href="#a3bd1c7d455abc782062d0e23a3ef1015">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aaea110287f115fbaf80b0248f724c5b6">output_fail_suffix</a> (const reflection::source_location &amp;location, check_kind kind, const test_case &amp;test_case) override</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Outputs the suffix for a failing condition. <a href="#aaea110287f115fbaf80b0248f724c5b6">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ac6c05f92e47ad71f72b44f9beb0b98f1">output_pass_prefix</a> (const std::string &amp;message, const test_case &amp;test_case) override</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Outputs the prefix for a passing condition. <a href="#ac6c05f92e47ad71f72b44f9beb0b98f1">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a37c4235afdd9b704fd65d25d130bee86">output_pass_suffix</a> (const test_case &amp;test_case) override</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Outputs the suffix for a passing condition. <a href="#a37c4235afdd9b704fd65d25d130bee86">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">add_empty_line_</a> { true }</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Whether to write an empty line before the next console output. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">std::span&lt; char *const  &gt;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a3e47f2c530c5019bde9fe56867bc581f">arguments_</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The command-line arguments passed to the test runner. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a3e47f2c530c5019bde9fe56867bc581f">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">std::string</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output accumulation buffer. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a970a08a00e70f1574033085350656230">buffer_has_failures_</a> { false }</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Whether the output buffer contains a failed check. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a970a08a00e70f1574033085350656230">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a69616e251ebb3d22e481ada0831bec3c">colours_</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>ANSI colour codes for output formatting. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a69616e251ebb3d22e481ada0831bec3c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter">expression_formatter</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac928cbe8852ca0c0273482b905c6301b">expression_</a> { <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a69616e251ebb3d22e481ada0831bec3c">colours_</a> }</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Expression formatter for pass and fail reporting. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac928cbe8852ca0c0273482b905c6301b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0d73674812cca717a754137b4b26ed89">has_output_file_error_</a> { false }</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Whether the output file could not be opened. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0d73674812cca717a754137b4b26ed89">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">FILE *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> { nullptr }</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Optional output file, receiving a copy of the test report. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">std::string</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac3878d2e85ed2cae4c71c793d7a8f52e">output_file_path_</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Path of the optional output file. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac3878d2e85ed2cae4c71c793d7a8f52e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914b">micro_test_plus::verbosity</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The verbosity level for test reporting. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Private Member Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">size_t</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#acc89e5828b613327923fa1b18172d9c1">condition_begin_</a> = std::string::npos</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The position in the buffer where the expression of a failed check begins. <a href="#acc89e5828b613327923fa1b18172d9c1">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">size_t</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ac4dcc7a6454d79e473033ddec5882ee8">description_begin_</a> = 0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The position in the buffer where the description of a passed check begins. <a href="#ac4dcc7a6454d79e473033ddec5882ee8">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Protected Static Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">static void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac6dca3d3fa34870f3960fe5e226e45d8">format_elapsed_time</a> (const stopwatch &amp;stopwatch, char(&amp;message)[elapsed_time_size_])</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats the elapsed time of a suite or of the session. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac6dca3d3fa34870f3960fe5e226e45d8">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">static void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a6bf3aac88a5e66e2f93eb32c54dbdd14">format_session_totals</a> (const runner &amp;runner, char(&amp;message)[totals_size_])</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats the totals of the test session. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a6bf3aac88a5e66e2f93eb32c54dbdd14">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">static void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a570030599ccc9f4133ed6a9eda2c2a1c">format_suite_totals</a> (const suite &amp;suite, char(&amp;message)[totals_size_])</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats the totals of a suite. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a570030599ccc9f4133ed6a9eda2c2a1c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">static void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a60b8564f54a6a1230e6d4ce110de93f5">format_test_case_totals</a> (const test_case &amp;test_case, char(&amp;message)[totals_size_])</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats the totals of a test case. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a60b8564f54a6a1230e6d4ce110de93f5">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Protected Static Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">static constexpr size_t</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2bf85bc5dd65df1816b52b7fd7c6c627">elapsed_time_size_</a> = 32</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Size of the array that receives the elapsed time text. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2bf85bc5dd65df1816b52b7fd7c6c627">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">static constexpr size_t</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7ee7d450c03e89bb0beb6cd97056aa4e">indent_size_</a> = 4</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Number of spaces per nesting level. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7ee7d450c03e89bb0beb6cd97056aa4e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">static constexpr size_t</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aaa55b147a670878984952ca1112cecd8">totals_size_</a> = 94 + 6 * (std::numeric_limits&lt;size_t&gt;::digits10 + 1)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Size of the array that receives the totals text. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aaa55b147a670878984952ca1112cecd8">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>TAP (Test Anything Protocol) implementation of <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a></span>.</p>


<p><span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap">reporter_tap</a></span> provides a concrete implementation of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a></span> abstract interface that formats test results according to the Test Anything Protocol (TAP). It accumulates output in an internal string buffer and writes it to the standard output stream.</p>


<p>The reporter is created by the runner, as selected by the <span class="doxyComputerOutput">--<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a></span> command-line option, or by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#ad22d04df014c5b0658b6e7bd239f15b0">runner_options::selected_reporter</a></span>; it is the default. A different output format requires a new class derived from <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a></span>, and an extension of the runner to create it.</p>


<p>All members are defined within the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail">micro_os_plus::micro_test_plus::detail</a></span> namespace, since the reporters are internal to the framework.</p>


<p>Definition at line 94 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h">reporter-tap.h</a>.</p>


<div class="doxySectionDef">

## Public Constructors

### reporter\_tap() {#a788b72a9bc3181ad600738402eb1839c}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::reporter_tap::reporter_tap (const reporter_tap &amp;)</td>
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


<p>The reporter owns the output buffer and the output file, which must not be shared.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h/#l00112">112</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h">reporter-tap.h</a>.</p>


<p>Reference <a href="#a8ab19d5802719647f6429e69f3b86345">reporter_tap</a>.</p>

</div>
</div>

### reporter\_tap() {#a8ab19d5802719647f6429e69f3b86345}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::reporter_tap::reporter_tap (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options">runner_options</a> &amp; opts)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel explicit">explicit</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Constructor for the <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap">reporter_tap</a> class.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">opts</td>
<td class="doxyParamItemDescription"><p>The session options, passed to <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#acfabd0e10d233ad305b6f4fc125a97f2">runner::initialise()</a></span> or parsed by it from the command line.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Delegates construction to the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a></span> base class with the supplied options. If tracing is enabled, the function signature is output for diagnostic purposes.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h/#l00103">103</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h">reporter-tap.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp/#l00229">229</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp">reporter-tap.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a8ab19d5802719647f6429e69f3b86345">229</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a8ab19d5802719647f6429e69f3b86345">reporter_tap::reporter_tap</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options">runner_options</a>&amp; opts) : <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a>{ opts }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">230</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">231</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">232</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">233</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">234</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">micro_os_plus::micro_test_plus::detail::reporter::reporter</a>.</p>


<p>Referenced by <a href="#a788b72a9bc3181ad600738402eb1839c">reporter_tap</a>, <a href="#a14652a1ac9c36386c738551529b9525b">reporter_tap</a>, <a href="#afe3745c4194923880428e105848f6a13">operator=</a> and <a href="#a9da35382cc3f903728f5f1bed2c4a745">operator=</a>.</p>

</div>
</div>

### reporter\_tap() {#a14652a1ac9c36386c738551529b9525b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::reporter_tap::reporter_tap (reporter_tap &amp;&amp;)</td>
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


<p>The reporter is owned by the runner, through a pointer, and is never relocated.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h/#l00121">121</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h">reporter-tap.h</a>.</p>


<p>Reference <a href="#a8ab19d5802719647f6429e69f3b86345">reporter_tap</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Destructor

### \~reporter\_tap() {#afec3839d3e8a890d8d3adafd81951d30}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::reporter_tap::~reporter_tap ()</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Destructor for the <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap">reporter_tap</a> class.</p>


<p>The output file, if any, is closed by the base class destructor.</p>


<p>No resources are owned directly by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap">reporter_tap</a></span>; the destructor performs no explicit clean-up. If tracing is enabled, the function signature is output for diagnostic purposes.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h/#l00151">151</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h">reporter-tap.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp/#l00242">242</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp">reporter-tap.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#afec3839d3e8a890d8d3adafd81951d30">242</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#afec3839d3e8a890d8d3adafd81951d30">reporter_tap::~reporter_tap</a> ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">243</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">244</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">245</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">246</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">247</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Operators

### operator&lt;&lt;() {#acbdac50fb2a1302e4a97c8160e7fd7cb}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">reporter &amp; micro_os_plus::micro_test_plus::detail::reporter::operator&lt;&lt; (bool v)</td>
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


<p>This operator overload appends <span class="doxyComputerOutput">"true"</span> or <span class="doxyComputerOutput">"false"</span> to the internal output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a></span>, as the expression formatter does. Being a non-template function, it is selected for <span class="doxyComputerOutput">bool</span> values instead of the arithmetic template, which would format them as numbers.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00272">272</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00576">576</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">576</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a54158cb2ca77354223506355247cab9a">reporter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">577</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">578</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>.append (v ? </span><span class="doxyHighlightStringLiteral">"true"</span><span class="doxyHighlight"> : </span><span class="doxyHighlightStringLiteral">"false"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">579</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">580</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">micro_os_plus::micro_test_plus::detail::reporter::reporter</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">micro_os_plus::micro_test_plus::detail::reporter::buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a5d29d78c80c20d3fe96ac9d0f4a969b3}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">reporter &amp; micro_os_plus::micro_test_plus::detail::reporter::operator&lt;&lt; (char c)</td>
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


<p>This operator overload appends the specified character to the internal output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00249">249</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00539">539</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">539</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a54158cb2ca77354223506355247cab9a">reporter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> c)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">540</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">541</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>.append (1, c);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">542</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">543</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">micro_os_plus::micro_test_plus::detail::reporter::reporter</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">micro_os_plus::micro_test_plus::detail::reporter::buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#ad84ba0969733f2120622d26951259f95}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">reporter &amp; micro_os_plus::micro_test_plus::detail::reporter::operator&lt;&lt; (const char * s)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Output operator for a constant character string.</p>


<p>Also selected for the non-const <span class="doxyComputerOutput">char</span> pointers and arrays, which the pointer template does not accept. A null pointer is output as <span class="doxyComputerOutput">"nullptr"</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">s</td>
<td class="doxyParamItemDescription"><p>The string to output, or a null pointer.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to the current reporter instance.</p></dd>
</dl>


<p>This operator overload appends the contents of the provided C-style string to the internal output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a></span>, or <span class="doxyComputerOutput">"nullptr"</span> for a null pointer, as the expression formatter does; the <span class="doxyComputerOutput">char*</span> values also reach this overload, and <span class="doxyComputerOutput">std::string::append()</span> must not be called with a null pointer.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00263">263</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00554">554</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">554</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a54158cb2ca77354223506355247cab9a">reporter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* s)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">555</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">556</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (s == </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">557</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">558</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"nullptr"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">559</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">560</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">561</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">562</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>.append (s);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">563</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">564</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">565</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">micro_os_plus::micro_test_plus::detail::reporter::reporter</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">micro_os_plus::micro_test_plus::detail::reporter::buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#aedfa17028026f6eaa871214da441e90c}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">reporter &amp; micro_os_plus::micro_test_plus::detail::reporter::operator&lt;&lt; (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/indentation">indentation</a> m)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Output operator for the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/indentation">indentation</a></span> manipulator.</p>


<p>Appends <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7ee7d450c03e89bb0beb6cd97056aa4e">indent_size_</a></span> spaces for each indentation level.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">m</td>
<td class="doxyParamItemDescription"><p>The indentation manipulator produced by <span class="doxyComputerOutput">indent(n)</span>.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to the current reporter instance.</p></dd>
</dl>


<p>This operator overload appends spaces to the internal output buffer, <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7ee7d450c03e89bb0beb6cd97056aa4e">indent_size_</a></span> for each of the <span class="doxyComputerOutput">m.level</span> indentation levels, allowing <span class="doxyComputerOutput">*this &lt;&lt; indent(n) &lt;&lt; "text"</span> chaining in both reporters.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00331">331</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00515">515</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">515</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a54158cb2ca77354223506355247cab9a">reporter::operator&lt;&lt;</a>(<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/indentation">indentation</a> m)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">516</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">517</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>.append (m.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/indentation/#a6b8b1c2610c1f1591bc87068deeefd5a">level</a> * <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7ee7d450c03e89bb0beb6cd97056aa4e">indent_size_</a>, </span><span class="doxyHighlightCharLiteral">' '</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">518</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">519</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">micro_os_plus::micro_test_plus::detail::reporter::reporter</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">micro_os_plus::micro_test_plus::detail::reporter::buffer_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7ee7d450c03e89bb0beb6cd97056aa4e">micro_os_plus::micro_test_plus::detail::reporter::indent_size_</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/indentation/#a6b8b1c2610c1f1591bc87068deeefd5a">micro_os_plus::micro_test_plus::detail::indentation::level</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#af4b5f0d3207f22b402bf4079a7547c1c}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">reporter &amp; micro_os_plus::micro_test_plus::detail::reporter::operator&lt;&lt; (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a> &amp;(*)(<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a> &amp;) func)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Output operator for stream manipulators, such as <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">endl</a></span>.</p>


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


<p>This operator overload enables manipulators, such as <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">endl</a></span>, to be used with the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a></span> stream in a manner similar to standard C++ streams. When a manipulator function is passed, it is invoked with the current <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a></span> instance.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00319">319</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00501">501</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">501</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a54158cb2ca77354223506355247cab9a">reporter::operator&lt;&lt;</a>(<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a>&amp; (*func) (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a>&amp;))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">502</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">503</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Call the endl function.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">504</span><span class="doxyLineContent"><span class="doxyHighlight">    (*func) (*this);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">505</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">506</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">micro_os_plus::micro_test_plus::detail::reporter::reporter</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#ac894cb9cbf11f2f57acb388310eede4c}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">reporter &amp; micro_os_plus::micro_test_plus::detail::reporter::operator&lt;&lt; (std::nullptr_t)</td>
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


<p>This operator overload appends the string <span class="doxyComputerOutput">"nullptr"</span> to the internal output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a></span>, as the expression formatter does.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00280">280</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00588">588</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">588</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a54158cb2ca77354223506355247cab9a">reporter::operator&lt;&lt;</a>(std::nullptr_t)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">589</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">590</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"nullptr"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">591</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">592</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">micro_os_plus::micro_test_plus::detail::reporter::reporter</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">micro_os_plus::micro_test_plus::detail::reporter::buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a54158cb2ca77354223506355247cab9a}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">reporter &amp; micro_os_plus::micro_test_plus::detail::reporter::operator&lt;&lt; (std::string_view sv)</td>
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


<p>This operator overload appends the contents of the provided <span class="doxyComputerOutput">std::string_view</span> to the internal output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00240">240</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00527">527</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">527</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a54158cb2ca77354223506355247cab9a">reporter::operator&lt;&lt;</a>(std::string_view sv)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">528</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">529</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>.append (sv);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">530</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">531</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">micro_os_plus::micro_test_plus::detail::reporter::reporter</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">micro_os_plus::micro_test_plus::detail::reporter::buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a3ff526c7ae5db0669d7db2adebf7cb2d}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;typename T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">reporter &amp; micro_os_plus::micro_test_plus::detail::reporter::operator&lt;&lt; (T * v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Output operator to display any pointer.</p>


<p>The <span class="doxyComputerOutput">char</span> pointers are excluded, so that they are output as strings by the <span class="doxyComputerOutput">const char*</span> overload, as the <span class="doxyComputerOutput">const char</span> pointers are.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The type pointed to, other than <span class="doxyComputerOutput">char</span>.</p></td>
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


<p>The address is formatted by the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a622a2bb23e2c98ecfa3a2ccb53e19910">detail::append_pointer()</a></span> helper, shared with the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter">detail::expression_formatter</a></span>, so that the pointers are displayed identically in the expressions and in the messages.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00310">310</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reporter-inlines-h/#l00084">84</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reporter-inlines-h">reporter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">84</span><span class="doxyLineContent"><span class="doxyHighlight">  reporter::operator&lt;&lt; (T* v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">85</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">86</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a622a2bb23e2c98ecfa3a2ccb53e19910">append_pointer</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>, v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">87</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">88</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">micro_os_plus::micro_test_plus::detail::reporter::reporter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a622a2bb23e2c98ecfa3a2ccb53e19910">micro_os_plus::micro_test_plus::detail::append_pointer</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">micro_os_plus::micro_test_plus::detail::reporter::buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a0cdaf2313f78a256b80f7bb7b279e2e6}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">reporter &amp; micro_os_plus::micro_test_plus::detail::reporter::operator&lt;&lt; (T v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Output operator for arithmetic types.</p>


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


<p>This template operator overload allows the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a></span> to output values of any arithmetic type (integral or floating-point) in a consistent and readable format. The value is formatted using the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">detail::append_number()</a></span> helper, without a type suffix (unlike the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter">detail::expression_formatter</a></span> operators, which add one).</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00292">292</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reporter-inlines-h/#l00101">101</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reporter-inlines-h">reporter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">101</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a54158cb2ca77354223506355247cab9a">reporter::operator&lt;&lt;</a>(T v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">102</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">103</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">append_number</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>, v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">104</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">105</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">micro_os_plus::micro_test_plus::detail::reporter::reporter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">micro_os_plus::micro_test_plus::detail::append_number</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">micro_os_plus::micro_test_plus::detail::reporter::buffer_</a>.</p>

</div>
</div>

### operator=() {#afe3745c4194923880428e105848f6a13}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">reporter_tap &amp; micro_os_plus::micro_test_plus::detail::reporter_tap::operator= (const <a href="#a8ab19d5802719647f6429e69f3b86345">reporter_tap</a> &amp;)</td>
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


<p>The reporter owns the output buffer and the output file, which must not be shared.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h/#l00131">131</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h">reporter-tap.h</a>.</p>


<p>Reference <a href="#a8ab19d5802719647f6429e69f3b86345">reporter_tap</a>.</p>

</div>
</div>

### operator=() {#a9da35382cc3f903728f5f1bed2c4a745}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">reporter_tap &amp; micro_os_plus::micro_test_plus::detail::reporter_tap::operator= (<a href="#a8ab19d5802719647f6429e69f3b86345">reporter_tap</a> &amp;&amp;)</td>
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


<p>The reporter is owned by the runner, through a pointer, and is never relocated.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h/#l00142">142</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h">reporter-tap.h</a>.</p>


<p>References <a href="#a8ab19d5802719647f6429e69f3b86345">reporter_tap</a>, <a href="#aa8802baefcb360f48451418c783ac413">abort_session</a>, <a href="#acaae91eea2deed1fe3f43b6453e7e656">begin_session</a>, <a href="#a2c05a737bfe80c955a998dc801e964b5">begin_suite</a>, <a href="#a0302f9f5b977b05139d73df3bbc18d69">begin_test_case</a>, <a href="#afc9cc4d9f74c89a0f1fbe4d39c40db92">comment_prefix</a>, <a href="#af80ba6907c9f13b08f8cb8726d65c510">commit_buffer</a>, <a href="#a7033819609bfad2db2ecc7a024e91b2c">end_session</a>, <a href="#a2d5ddae3195ab52a957927a1b455f7b8">end_suite</a>, <a href="#ad15f7dbbf6a683441df40c502125adc3">end_test_case</a>, <a href="#a314df80e98fe6fa5de008d6708a14925">fail_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">micro_os_plus::micro_test_plus::detail::reporter::micro_test_plus::runner</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">micro_os_plus::micro_test_plus::detail::reporter::micro_test_plus::test_case</a>, <a href="#a3bd1c7d455abc782062d0e23a3ef1015">output_fail_prefix</a>, <a href="#aaea110287f115fbaf80b0248f724c5b6">output_fail_suffix</a>, <a href="#ac6c05f92e47ad71f72b44f9beb0b98f1">output_pass_prefix</a>, <a href="#a37c4235afdd9b704fd65d25d130bee86">output_pass_suffix</a>, <a href="#a319f35d4af8c72af8b14a89b421c1c74">skip_suite</a>, <a href="#a31ccd7af941d06241ce16df9274abc38">skip_test_case</a> and <a href="#a841b146b309b93422ae707094ba044f6">writes_passed_checks</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Member Functions

### abort\_session() {#aa8802baefcb360f48451418c783ac413}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter_tap::abort_session (const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> &amp; location, bool is_requirement)</td>
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

<p>Reports the abort of the test execution.</p>


<p>Displays the buffered check results, followed by a <span class="doxyComputerOutput">Bail out!</span> line with the location of the failed requirement, or of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a7bc806540e65c21095ef1ea1ef970db2">runner::abort()</a></span> call.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">location</td>
<td class="doxyParamItemDescription"><p>The source location of the failed requirement, or of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a7bc806540e65c21095ef1ea1ef970db2">runner::abort()</a></span> call.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">is_requirement</td>
<td class="doxyParamItemDescription"><p><span class="doxyComputerOutput">true</span> if the abort is caused by a failed requirement.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Since <span class="doxyComputerOutput"><a href="#ad15f7dbbf6a683441df40c502125adc3">end_test_case()</a></span> is not called for the running test cases, this member function writes the buffered lines, if any, in its place (after a failed requirement, they end with it), followed by an unindented <span class="doxyComputerOutput">Bail out! &lt;reason&gt; at &lt;file&gt;:&lt;line&gt;</span> line, with the file name escaped as the reason, which tells the TAP consumers that the run stopped early (see the TAP 14 specification), not that the output was truncated. The reason is <span class="doxyComputerOutput">Requirement failed</span> after a failed requirement, and <span class="doxyComputerOutput">Test execution aborted</span> for an explicit call of <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a7bc806540e65c21095ef1ea1ef970db2">runner::abort()</a></span>.</p>


<p>Both are always written to the output file, as in <span class="doxyComputerOutput"><a href="#ad15f7dbbf6a683441df40c502125adc3">end_test_case()</a></span>, and, unless the verbosity is silent, to <span class="doxyComputerOutput">stdout</span>, preceded by an empty line when <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">add_empty_line_</a></span> is set. With quiet verbosity, which otherwise displays only the summary, they are displayed as well, since the summary is never reached.</p>


<p>The buffer is then cleared, so that its lines are not written again, should the abort handler throw an exception that the application catches.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h/#l00274">274</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h">reporter-tap.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp/#l00946">946</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp">reporter-tap.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aa8802baefcb360f48451418c783ac413">946</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#aa8802baefcb360f48451418c783ac413">reporter_tap::abort_session</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; location,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">947</span><span class="doxyLineContent"><span class="doxyHighlight">                               </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> is_requirement)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">948</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">949</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">950</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">951</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">952</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">953</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// The type of `line()` depends on the toolchain (`uint_least32_t` for</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">954</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// `std::source_location`); widen it implicitly, without a cast that</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">955</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// would be useless on some platforms.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">956</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> line = location.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#aab9d006004611ac0526852a09f675c66">line</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">957</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// The reason is escaped, as the descriptions.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">958</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string file_name</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">959</span><span class="doxyLineContent"><span class="doxyHighlight">        = tap_text (<a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-utility-functions/#ga791f22f0c85b6436c9016821907b0653">utility::extract_file_name</a> (location.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#a3df499675aacb7ab9192cfb9a5371874">file_name</a> ()), </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">960</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* reason</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">961</span><span class="doxyLineContent"><span class="doxyHighlight">        = is_requirement ? </span><span class="doxyHighlightStringLiteral">"Requirement failed"</span><span class="doxyHighlight"> : </span><span class="doxyHighlightStringLiteral">"Test execution aborted"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">962</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">963</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a37cba38a47d66a928a936ee081c6d88c">write_buffer_to_file</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">964</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">965</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> to_console = (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> != <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">verbosity::silent</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">966</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">967</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (to_console)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">968</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">969</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">add_empty_line_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">970</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">971</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#abaee31ffca8e65c9af34f7f67227c5b3">write_console</a> (</span><span class="doxyHighlightStringLiteral">"\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">972</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">973</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">974</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ae074822d712fc3db3c09f5f2d2237072">write_buffer_to_console</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">975</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">976</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">977</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">write_line</a> (to_console, </span><span class="doxyHighlightStringLiteral">"Bail out! %s at %s:%lu\n"</span><span class="doxyHighlight">, reason,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">978</span><span class="doxyLineContent"><span class="doxyHighlight">                file_name.c_str (), line);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">979</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">980</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a804b593aefa158d92a72da43de57d242">flush_streams</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">981</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">982</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5859ce31641330b243cfb5d1c6080859">clear_buffer</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">983</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">micro_os_plus::micro_test_plus::detail::reporter::add_empty_line_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5859ce31641330b243cfb5d1c6080859">micro_os_plus::micro_test_plus::detail::reporter::clear_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-utility-functions/#ga791f22f0c85b6436c9016821907b0653">micro_os_plus::micro_test_plus::utility::extract_file_name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#a3df499675aacb7ab9192cfb9a5371874">micro_os_plus::micro_test_plus::reflection::source_location::file_name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a804b593aefa158d92a72da43de57d242">micro_os_plus::micro_test_plus::detail::reporter::flush_streams</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#aab9d006004611ac0526852a09f675c66">micro_os_plus::micro_test_plus::reflection::source_location::line</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">micro_os_plus::micro_test_plus::silent</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">micro_os_plus::micro_test_plus::detail::reporter::verbosity_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ae074822d712fc3db3c09f5f2d2237072">micro_os_plus::micro_test_plus::detail::reporter::write_buffer_to_console</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a37cba38a47d66a928a936ee081c6d88c">micro_os_plus::micro_test_plus::detail::reporter::write_buffer_to_file</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#abaee31ffca8e65c9af34f7f67227c5b3">micro_os_plus::micro_test_plus::detail::reporter::write_console</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">micro_os_plus::micro_test_plus::detail::reporter::write_line</a>.</p>


<p>Referenced by <a href="#a9da35382cc3f903728f5f1bed2c4a745">operator=</a>.</p>

</div>
</div>

### begin\_session() {#acaae91eea2deed1fe3f43b6453e7e656}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter_tap::begin_session (const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">runner</a> &amp; runner)</td>
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

<p>Marks the beginning of a test session.</p>


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


<p>If verbosity is not silent, emits a blank line to <span class="doxyComputerOutput">stdout</span> and then calls <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aeafdc8e05a6d80d9445f17ff354ee215">write_info()</a></span> to output build and environment information. The TAP version header <span class="doxyComputerOutput">"TAP version 14"</span> is then written to the output file (if open) and, unless verbosity is silent, to <span class="doxyComputerOutput">stdout</span>. The <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">add_empty_line_</a></span> flag is cleared so that the first suite header is not separated by an extra blank line.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h/#l00163">163</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h">reporter-tap.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp/#l00262">262</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp">reporter-tap.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#acaae91eea2deed1fe3f43b6453e7e656">262</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#acaae91eea2deed1fe3f43b6453e7e656">reporter_tap::begin_session</a> ([[maybe_unused]] </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">runner</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">runner</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">263</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">264</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">265</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">266</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">267</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">268</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> != <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">verbosity::silent</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">269</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">270</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#abaee31ffca8e65c9af34f7f67227c5b3">write_console</a> (</span><span class="doxyHighlightStringLiteral">"\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">271</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">272</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">273</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aeafdc8e05a6d80d9445f17ff354ee215">write_info</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">274</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">275</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">write_line</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> != <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">verbosity::silent</a>, </span><span class="doxyHighlightStringLiteral">"TAP version 14\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">276</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">277</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a804b593aefa158d92a72da43de57d242">flush_streams</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">278</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">279</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">add_empty_line_</a> = </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">280</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">micro_os_plus::micro_test_plus::detail::reporter::add_empty_line_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a804b593aefa158d92a72da43de57d242">micro_os_plus::micro_test_plus::detail::reporter::flush_streams</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">micro_os_plus::micro_test_plus::detail::reporter::micro_test_plus::runner</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">micro_os_plus::micro_test_plus::silent</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">micro_os_plus::micro_test_plus::detail::reporter::verbosity_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#abaee31ffca8e65c9af34f7f67227c5b3">micro_os_plus::micro_test_plus::detail::reporter::write_console</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aeafdc8e05a6d80d9445f17ff354ee215">micro_os_plus::micro_test_plus::detail::reporter::write_info</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">micro_os_plus::micro_test_plus::detail::reporter::write_line</a>.</p>


<p>Referenced by <a href="#a9da35382cc3f903728f5f1bed2c4a745">operator=</a>.</p>

</div>
</div>

### begin\_suite() {#a2c05a737bfe80c955a998dc801e964b5}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter_tap::begin_suite (const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a> &amp; suite)</td>
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

<p>Marks the beginning of a test suite.</p>


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


<p>Emits a <span class="doxyComputerOutput">"# Subtest: &lt;name&gt;"</span> comment line to mark the start of a TAP test case block for the suite; the line breaks in the name are replaced by spaces (see <span class="doxyComputerOutput">tap_text()</span>). The line is written to the output file when one is open. Under normal or verbose verbosity, it is also written to <span class="doxyComputerOutput">stdout</span>, preceded by a blank line when <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">add_empty_line_</a></span> is set.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h/#l00183">183</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h">reporter-tap.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp/#l00339">339</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp">reporter-tap.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a2c05a737bfe80c955a998dc801e964b5">339</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a2c05a737bfe80c955a998dc801e964b5">reporter_tap::begin_suite</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">340</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">341</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">342</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s '%s'\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">343</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">344</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">345</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string name = tap_text (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> (), </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">346</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">347</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> to_console = (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">verbosity::normal</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">348</span><span class="doxyLineContent"><span class="doxyHighlight">                             || <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">verbosity::verbose</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">349</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">350</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (to_console &amp;&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">add_empty_line_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">351</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">352</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#abaee31ffca8e65c9af34f7f67227c5b3">write_console</a> (</span><span class="doxyHighlightStringLiteral">"\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">353</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">354</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">355</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">write_line</a> (to_console, </span><span class="doxyHighlightStringLiteral">"# Subtest: %s\n"</span><span class="doxyHighlight">, name.c_str ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">356</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">357</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a804b593aefa158d92a72da43de57d242">flush_streams</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">358</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">359</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (to_console)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">360</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">361</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">add_empty_line_</a> = </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">362</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">363</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">micro_os_plus::micro_test_plus::detail::reporter::add_empty_line_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a804b593aefa158d92a72da43de57d242">micro_os_plus::micro_test_plus::detail::reporter::flush_streams</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">micro_os_plus::micro_test_plus::detail::runnable_base::name</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">micro_os_plus::micro_test_plus::normal</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">micro_os_plus::micro_test_plus::verbose</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">micro_os_plus::micro_test_plus::detail::reporter::verbosity_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#abaee31ffca8e65c9af34f7f67227c5b3">micro_os_plus::micro_test_plus::detail::reporter::write_console</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">micro_os_plus::micro_test_plus::detail::reporter::write_line</a>.</p>


<p>Referenced by <a href="#a9da35382cc3f903728f5f1bed2c4a745">operator=</a>.</p>

</div>
</div>

### begin\_test\_case() {#a0302f9f5b977b05139d73df3bbc18d69}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter_tap::begin_test_case (const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a> &amp; test_case)</td>
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

<p>Marks the beginning of a test case.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">test_case</td>
<td class="doxyParamItemDescription"><p>Reference to the test case.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>For a nested test case, the results of the checks already performed by the outer test case, if any, are written first (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5cf73aaf67484b50c25ef42363d49337">commit_outer_results()</a></span>), so that the output follows the execution order.</p>


<p>A <span class="doxyComputerOutput">"# Subtest: &lt;name&gt;"</span> comment line (indented according to nesting depth), with the line breaks in the name replaced by spaces, is then written to the output file and, under normal or verbose verbosity, to <span class="doxyComputerOutput">stdout</span> as well.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h/#l00232">232</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h">reporter-tap.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp/#l00547">547</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp">reporter-tap.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a0302f9f5b977b05139d73df3bbc18d69">547</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a0302f9f5b977b05139d73df3bbc18d69">reporter_tap::begin_test_case</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">548</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">549</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">550</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s '%s'\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">551</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">552</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">553</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5cf73aaf67484b50c25ef42363d49337">commit_outer_results</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">554</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">555</span><span class="doxyLineContent"><span class="doxyHighlight">    std::string <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">indent</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7ee7d450c03e89bb0beb6cd97056aa4e">indent_size_</a> * <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#af2b6792d06fa335f2b617e4d39bbba3c">nesting_depth</a> (), </span><span class="doxyHighlightCharLiteral">' '</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">556</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">557</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string name = tap_text (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> (), </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">558</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">559</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> to_console = (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">verbosity::normal</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">560</span><span class="doxyLineContent"><span class="doxyHighlight">                             || <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">verbosity::verbose</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">561</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">562</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (to_console &amp;&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">add_empty_line_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">563</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">564</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#abaee31ffca8e65c9af34f7f67227c5b3">write_console</a> (</span><span class="doxyHighlightStringLiteral">"\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">565</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">566</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">567</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">write_line</a> (to_console, </span><span class="doxyHighlightStringLiteral">"%s# Subtest: %s\n"</span><span class="doxyHighlight">, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">indent</a>.c_str (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">568</span><span class="doxyLineContent"><span class="doxyHighlight">                name.c_str ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">569</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">570</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a804b593aefa158d92a72da43de57d242">flush_streams</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">571</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">572</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (to_console)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">573</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">574</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">add_empty_line_</a> = </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">575</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">576</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">micro_os_plus::micro_test_plus::detail::reporter::add_empty_line_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5cf73aaf67484b50c25ef42363d49337">micro_os_plus::micro_test_plus::detail::reporter::commit_outer_results</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a804b593aefa158d92a72da43de57d242">micro_os_plus::micro_test_plus::detail::reporter::flush_streams</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">micro_os_plus::micro_test_plus::detail::indent</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7ee7d450c03e89bb0beb6cd97056aa4e">micro_os_plus::micro_test_plus::detail::reporter::indent_size_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">micro_os_plus::micro_test_plus::detail::reporter::micro_test_plus::test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">micro_os_plus::micro_test_plus::detail::runnable_base::name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#af2b6792d06fa335f2b617e4d39bbba3c">micro_os_plus::micro_test_plus::test_case::nesting_depth</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">micro_os_plus::micro_test_plus::normal</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">micro_os_plus::micro_test_plus::verbose</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">micro_os_plus::micro_test_plus::detail::reporter::verbosity_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#abaee31ffca8e65c9af34f7f67227c5b3">micro_os_plus::micro_test_plus::detail::reporter::write_console</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">micro_os_plus::micro_test_plus::detail::reporter::write_line</a>.</p>


<p>Referenced by <a href="#a9da35382cc3f903728f5f1bed2c4a745">operator=</a>.</p>

</div>
</div>

### comment\_prefix() {#afc9cc4d9f74c89a0f1fbe4d39c40db92}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const char * micro_os_plus::micro_test_plus::detail::reporter_tap::comment_prefix (void)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel noexcept">noexcept</span>
<span class="doxyMemberLabel virtual">virtual</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Returns the TAP comment prefix string <span class="doxyComputerOutput">"# "</span>.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The string <span class="doxyComputerOutput">"# "</span>, used to prefix comment lines in TAP output.</p></dd>
</dl>


<p>Returns <span class="doxyComputerOutput">"# "</span>. The TAP reporter prefixes all comment lines, including the informational lines emitted by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aeafdc8e05a6d80d9445f17ff354ee215">write_info()</a></span>, with the TAP comment marker.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h/#l00286">286</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h">reporter-tap.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp/#l00708">708</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp">reporter-tap.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#afc9cc4d9f74c89a0f1fbe4d39c40db92">708</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#afc9cc4d9f74c89a0f1fbe4d39c40db92">reporter_tap::comment_prefix</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">709</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">710</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> </span><span class="doxyHighlightStringLiteral">"# "</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">711</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Referenced by <a href="#a9da35382cc3f903728f5f1bed2c4a745">operator=</a>.</p>

</div>
</div>

### end\_line() {#a287bad0e5eccee7df4a2c8517959bd0e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter::end_line (void)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends a line ending to the internal output buffer.</p>


<p>Nothing is written to the console or to the output file; the buffer is written by the concrete reporters, at the end of each test case or suite.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>This member function appends a newline character to the internal output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a></span>. The buffer itself is written later, by the concrete reporters, at the end of each test case or suite, which then also flush the streams.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00350">350</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00238">238</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a287bad0e5eccee7df4a2c8517959bd0e">238</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a287bad0e5eccee7df4a2c8517959bd0e">reporter::end_line</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">239</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">240</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">241</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">micro_os_plus::micro_test_plus::detail::reporter::buffer_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">micro_os_plus::micro_test_plus::detail::endl</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">micro_os_plus::micro_test_plus::detail::reporter::micro_test_plus::runner</a>.</p>

</div>
</div>

### end\_session() {#a7033819609bfad2db2ecc7a024e91b2c}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter_tap::end_session (const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">runner</a> &amp; runner)</td>
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

<p>Marks the end of a test session.</p>


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


<p>Emits the TAP plan line (<span class="doxyComputerOutput">1..N</span>, where N is the total number of test suites) followed by a comment line summarising passed checks, failed checks, executed test cases, suite count, and elapsed time. The numbers of test cases and of suites skipped by the filter follow the respective counts, only when not zero. Both lines are written to the output file when one is open, and, unless verbosity is silent, to <span class="doxyComputerOutput">stdout</span>. With quiet verbosity, the plan matches the <span class="doxyComputerOutput">ok</span>/<span class="doxyComputerOutput">not ok</span> lines of the suites displayed by <span class="doxyComputerOutput"><a href="#a2d5ddae3195ab52a957927a1b455f7b8">end_suite()</a></span> and <span class="doxyComputerOutput"><a href="#a319f35d4af8c72af8b14a89b421c1c74">skip_suite()</a></span>, so that the console output is a complete TAP document, which node-tap and the other TAP consumers read as failed when a suite failed; no empty line precedes it.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h/#l00173">173</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h">reporter-tap.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp/#l00297">297</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp">reporter-tap.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a7033819609bfad2db2ecc7a024e91b2c">297</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a7033819609bfad2db2ecc7a024e91b2c">reporter_tap::end_session</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">runner</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">runner</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">298</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">299</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">300</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">301</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">302</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">303</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> message_summary[32];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">304</span><span class="doxyLineContent"><span class="doxyHighlight">    snprintf (message_summary, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (message_summary),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">305</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightStringLiteral">"1..%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">306</span><span class="doxyLineContent"><span class="doxyHighlight">              <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">runner</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#ac29e4b993bb3fe795eb8900231cbf5c4">total_suites_count</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">307</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">308</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> message_totals[<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aaa55b147a670878984952ca1112cecd8">totals_size_</a>];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">309</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a6bf3aac88a5e66e2f93eb32c54dbdd14">format_session_totals</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">runner</a>, message_totals);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">310</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">311</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> message_time[<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2bf85bc5dd65df1816b52b7fd7c6c627">elapsed_time_size_</a>];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">312</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac6dca3d3fa34870f3960fe5e226e45d8">format_elapsed_time</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">runner</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a13b3cf196a1b12cb90a12c4b84223d15">stopwatch_</a>, message_time);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">313</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">314</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> to_console = (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> != <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">verbosity::silent</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">315</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">316</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (to_console &amp;&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">add_empty_line_</a> &amp;&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> != <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba556966c7830465dc4623d62e32cec31d">verbosity::quiet</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">317</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">318</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#abaee31ffca8e65c9af34f7f67227c5b3">write_console</a> (</span><span class="doxyHighlightStringLiteral">"\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">319</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">320</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">321</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">write_line</a> (to_console, </span><span class="doxyHighlightStringLiteral">"%s\n# { total: %s%s }\n"</span><span class="doxyHighlight">, message_summary,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">322</span><span class="doxyLineContent"><span class="doxyHighlight">                message_totals, message_time);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">323</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">324</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a804b593aefa158d92a72da43de57d242">flush_streams</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">325</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">micro_os_plus::micro_test_plus::detail::reporter::add_empty_line_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2bf85bc5dd65df1816b52b7fd7c6c627">micro_os_plus::micro_test_plus::detail::reporter::elapsed_time_size_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a804b593aefa158d92a72da43de57d242">micro_os_plus::micro_test_plus::detail::reporter::flush_streams</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac6dca3d3fa34870f3960fe5e226e45d8">micro_os_plus::micro_test_plus::detail::reporter::format_elapsed_time</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a6bf3aac88a5e66e2f93eb32c54dbdd14">micro_os_plus::micro_test_plus::detail::reporter::format_session_totals</a>, <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">micro_os_plus::micro_test_plus::detail::reporter::micro_test_plus::runner</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba556966c7830465dc4623d62e32cec31d">micro_os_plus::micro_test_plus::quiet</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">micro_os_plus::micro_test_plus::silent</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a13b3cf196a1b12cb90a12c4b84223d15">micro_os_plus::micro_test_plus::runner::stopwatch_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#ac29e4b993bb3fe795eb8900231cbf5c4">micro_os_plus::micro_test_plus::runner::total_suites_count</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aaa55b147a670878984952ca1112cecd8">micro_os_plus::micro_test_plus::detail::reporter::totals_size_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">micro_os_plus::micro_test_plus::detail::reporter::verbosity_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#abaee31ffca8e65c9af34f7f67227c5b3">micro_os_plus::micro_test_plus::detail::reporter::write_console</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">micro_os_plus::micro_test_plus::detail::reporter::write_line</a>.</p>


<p>Referenced by <a href="#a9da35382cc3f903728f5f1bed2c4a745">operator=</a>.</p>

</div>
</div>

### end\_suite() {#a2d5ddae3195ab52a957927a1b455f7b8}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter_tap::end_suite (const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a> &amp; suite)</td>
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

<p>Marks the end of a test suite.</p>


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


<p>Emits the TAP plan line for the suite's test cases, and for the failure of the suite body, if any (see <span class="doxyComputerOutput"><a href="#a314df80e98fe6fa5de008d6708a14925">fail_suite()</a></span>), followed by an <span class="doxyComputerOutput">ok</span>/<span class="doxyComputerOutput">not ok</span> result line that includes the suite index, name, pass/fail status, check counts, test case count, and elapsed time; the name is escaped (see <span class="doxyComputerOutput">tap_text()</span>). Any output accumulated in <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a></span> is written to the output file and, with normal or verbose verbosity, when verbosity is verbose or the suite failed, to <span class="doxyComputerOutput">stdout</span> as well; the plan and result lines are written to <span class="doxyComputerOutput">stdout</span> with normal or verbose verbosity. With quiet verbosity, only the result line is written to <span class="doxyComputerOutput">stdout</span>, without the plan and without an empty line, so that the session plan written by <span class="doxyComputerOutput"><a href="#a7033819609bfad2db2ecc7a024e91b2c">end_session()</a></span> counts the displayed lines. The buffer is cleared on exit.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h/#l00193">193</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h">reporter-tap.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp/#l00381">381</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp">reporter-tap.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a2d5ddae3195ab52a957927a1b455f7b8">381</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a2d5ddae3195ab52a957927a1b455f7b8">reporter_tap::end_suite</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">382</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">383</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">384</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">385</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightStringLiteral">"%s '%s' +%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">386</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightStringLiteral">" -%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">387</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightStringLiteral">" in xc%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">388</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightStringLiteral">", xs%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">389</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightStringLiteral">" | cs%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a> </span><span class="doxyHighlightStringLiteral">"\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">390</span><span class="doxyLineContent"><span class="doxyHighlight">        __PRETTY_FUNCTION__, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> (), <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">totals</a> ().<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">391</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">totals</a> ().<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#ab1684c7c6101a4d534356d9d16807bee">failed_checks</a> (), <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">totals</a> ().<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a5909350d1852fa54f2cf4c260d99b820">executed_checks</a> (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">392</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">totals</a> ().<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">executed_test_cases</a> (), <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aff1a81aff41ab5dc80e2fac1c5a78a31">child_test_cases_count_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">393</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">394</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">395</span><span class="doxyLineContent"><span class="doxyHighlight">    std::string <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">indent</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7ee7d450c03e89bb0beb6cd97056aa4e">indent_size_</a>, </span><span class="doxyHighlightCharLiteral">' '</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">396</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">397</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// The name is not included, since its length is not bounded; it is</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">398</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// passed to each write.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">399</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> passed = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">totals</a> ().<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a14690f9880df505f9dd90a9f2c3dfc96">passed</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">400</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* result = passed ? </span><span class="doxyHighlightStringLiteral">"ok"</span><span class="doxyHighlight"> : </span><span class="doxyHighlightStringLiteral">"not ok"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">401</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* status = passed ? </span><span class="doxyHighlightStringLiteral">"passed"</span><span class="doxyHighlight"> : </span><span class="doxyHighlightStringLiteral">"FAILED"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">402</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">403</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> message_totals[<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aaa55b147a670878984952ca1112cecd8">totals_size_</a>];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">404</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a570030599ccc9f4133ed6a9eda2c2a1c">format_suite_totals</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>, message_totals);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">405</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">406</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> message_time[<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2bf85bc5dd65df1816b52b7fd7c6c627">elapsed_time_size_</a>];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">407</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac6dca3d3fa34870f3960fe5e226e45d8">format_elapsed_time</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a95145ab410f5c0b6e514ac366aff8d84">stopwatch_</a>, message_time);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">408</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">409</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string name = tap_text (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> (), </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">410</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">411</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a37cba38a47d66a928a936ee081c6d88c">write_buffer_to_file</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">412</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">413</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> to_console = (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">verbosity::normal</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">414</span><span class="doxyLineContent"><span class="doxyHighlight">                             || <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">verbosity::verbose</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">415</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">416</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// At this point, the buffer may contain output from the test case, which</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">417</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// should be displayed.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">418</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (to_console)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">419</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">420</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">add_empty_line_</a> &amp;&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">totals</a> ().<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">executed_test_cases</a> () &gt; 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">421</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">422</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#abaee31ffca8e65c9af34f7f67227c5b3">write_console</a> (</span><span class="doxyHighlightStringLiteral">"\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">423</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">424</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">425</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (passed) [[likely]]</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">426</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">427</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightComment">// Successful test suite.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">428</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">429</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">verbosity::verbose</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">430</span><span class="doxyLineContent"><span class="doxyHighlight">              {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">431</span><span class="doxyLineContent"><span class="doxyHighlight">                </span><span class="doxyHighlightComment">// With verbosity, show full TAP output accumulated in the</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">432</span><span class="doxyLineContent"><span class="doxyHighlight">                </span><span class="doxyHighlightComment">// buffer.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">433</span><span class="doxyLineContent"><span class="doxyHighlight">                <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ae074822d712fc3db3c09f5f2d2237072">write_buffer_to_console</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">434</span><span class="doxyLineContent"><span class="doxyHighlight">              }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">435</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">436</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">437</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">438</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightComment">// Failed test suite.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">439</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">440</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightComment">// Show full TAP output accumulated in the buffer for failed suite</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">441</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightComment">// cases, as it may contain useful information about the failure.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">442</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ae074822d712fc3db3c09f5f2d2237072">write_buffer_to_console</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">443</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">444</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">445</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">446</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// The plan counts the test cases and the failure of the suite body,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">447</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// if any, which is numbered after them.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">448</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">write_line</a> (to_console,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">449</span><span class="doxyLineContent"><span class="doxyHighlight">                </span><span class="doxyHighlightStringLiteral">"%s1..%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">450</span><span class="doxyLineContent"><span class="doxyHighlight">                </span><span class="doxyHighlightStringLiteral">"\n%s %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">451</span><span class="doxyLineContent"><span class="doxyHighlight">                </span><span class="doxyHighlightStringLiteral">" - %s # { %s, %s%s }\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">452</span><span class="doxyLineContent"><span class="doxyHighlight">                <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">indent</a>.c_str (), <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#abc92cbb8ab8d04e7c75bf18aa7189d98">test_point_number_</a>, result,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">453</span><span class="doxyLineContent"><span class="doxyHighlight">                <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a69687627342981d42471b17f1d83311f">own_index_</a>, name.c_str (), status, message_totals,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">454</span><span class="doxyLineContent"><span class="doxyHighlight">                message_time);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">455</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">456</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba556966c7830465dc4623d62e32cec31d">verbosity::quiet</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">457</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">458</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// Only the test point of the suite, counted by the session plan.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">459</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#abaee31ffca8e65c9af34f7f67227c5b3">write_console</a> (</span><span class="doxyHighlightStringLiteral">"%s %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">460</span><span class="doxyLineContent"><span class="doxyHighlight">                       </span><span class="doxyHighlightStringLiteral">" - %s # { %s, %s%s }\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">461</span><span class="doxyLineContent"><span class="doxyHighlight">                       result, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a69687627342981d42471b17f1d83311f">own_index_</a>, name.c_str (), status,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">462</span><span class="doxyLineContent"><span class="doxyHighlight">                       message_totals, message_time);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">463</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">464</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">465</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a804b593aefa158d92a72da43de57d242">flush_streams</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">466</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">467</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5859ce31641330b243cfb5d1c6080859">clear_buffer</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">468</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">469</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">add_empty_line_</a> = </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">470</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">micro_os_plus::micro_test_plus::detail::reporter::add_empty_line_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aff1a81aff41ab5dc80e2fac1c5a78a31">micro_os_plus::micro_test_plus::detail::runnable_base::child_test_cases_count_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5859ce31641330b243cfb5d1c6080859">micro_os_plus::micro_test_plus::detail::reporter::clear_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2bf85bc5dd65df1816b52b7fd7c6c627">micro_os_plus::micro_test_plus::detail::reporter::elapsed_time_size_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a5909350d1852fa54f2cf4c260d99b820">micro_os_plus::micro_test_plus::counters::executed_checks</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">micro_os_plus::micro_test_plus::counters::executed_test_cases</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#ab1684c7c6101a4d534356d9d16807bee">micro_os_plus::micro_test_plus::counters::failed_checks</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a804b593aefa158d92a72da43de57d242">micro_os_plus::micro_test_plus::detail::reporter::flush_streams</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac6dca3d3fa34870f3960fe5e226e45d8">micro_os_plus::micro_test_plus::detail::reporter::format_elapsed_time</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a570030599ccc9f4133ed6a9eda2c2a1c">micro_os_plus::micro_test_plus::detail::reporter::format_suite_totals</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">micro_os_plus::micro_test_plus::detail::indent</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7ee7d450c03e89bb0beb6cd97056aa4e">micro_os_plus::micro_test_plus::detail::reporter::indent_size_</a>, <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">micro_os_plus::micro_test_plus::detail::runnable_base::name</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">micro_os_plus::micro_test_plus::normal</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a69687627342981d42471b17f1d83311f">micro_os_plus::micro_test_plus::detail::runnable_base::own_index_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a14690f9880df505f9dd90a9f2c3dfc96">micro_os_plus::micro_test_plus::counters::passed</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">micro_os_plus::micro_test_plus::counters::passed_checks</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba556966c7830465dc4623d62e32cec31d">micro_os_plus::micro_test_plus::quiet</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a95145ab410f5c0b6e514ac366aff8d84">micro_os_plus::micro_test_plus::suite::stopwatch_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#abc92cbb8ab8d04e7c75bf18aa7189d98">micro_os_plus::micro_test_plus::detail::runnable_base::test_point_number_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">micro_os_plus::micro_test_plus::detail::runnable_base::totals</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aaa55b147a670878984952ca1112cecd8">micro_os_plus::micro_test_plus::detail::reporter::totals_size_</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">micro_os_plus::micro_test_plus::verbose</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">micro_os_plus::micro_test_plus::detail::reporter::verbosity_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ae074822d712fc3db3c09f5f2d2237072">micro_os_plus::micro_test_plus::detail::reporter::write_buffer_to_console</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a37cba38a47d66a928a936ee081c6d88c">micro_os_plus::micro_test_plus::detail::reporter::write_buffer_to_file</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#abaee31ffca8e65c9af34f7f67227c5b3">micro_os_plus::micro_test_plus::detail::reporter::write_console</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">micro_os_plus::micro_test_plus::detail::reporter::write_line</a>.</p>


<p>Referenced by <a href="#a9da35382cc3f903728f5f1bed2c4a745">operator=</a>.</p>

</div>
</div>

### end\_test\_case() {#ad15f7dbbf6a683441df40c502125adc3}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter_tap::end_test_case (const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a> &amp; test_case)</td>
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

<p>Marks the end of a test case.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">test_case</td>
<td class="doxyParamItemDescription"><p>Reference to the test case.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Emits the TAP plan line for the test case's checks and nested test cases, followed by an <span class="doxyComputerOutput">ok</span>/<span class="doxyComputerOutput">not ok</span> result line that includes the test case index, escaped name, pass/fail status, and check counts. As in node-tap, the result is <span class="doxyComputerOutput">not ok</span> when a check or a nested test case failed; the number of failed nested test cases is added when it is not zero. Any output accumulated in <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a></span> is written to the output file and, with normal or verbose verbosity, when verbosity is verbose or the test case failed, to <span class="doxyComputerOutput">stdout</span> as well. With normal verbosity, for a passing test case, the plan written to <span class="doxyComputerOutput">stdout</span> counts only the nested test cases, since the individual check lines are not displayed. The buffer is cleared on exit.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h/#l00242">242</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h">reporter-tap.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp/#l00593">593</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp">reporter-tap.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ad15f7dbbf6a683441df40c502125adc3">593</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ad15f7dbbf6a683441df40c502125adc3">reporter_tap::end_test_case</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">594</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">595</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">596</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s '%s' i%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">597</span><span class="doxyLineContent"><span class="doxyHighlight">                   </span><span class="doxyHighlightStringLiteral">" +%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">598</span><span class="doxyLineContent"><span class="doxyHighlight">                   </span><span class="doxyHighlightStringLiteral">" -%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">599</span><span class="doxyLineContent"><span class="doxyHighlight">                   </span><span class="doxyHighlightStringLiteral">" in xc%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">600</span><span class="doxyLineContent"><span class="doxyHighlight">                   </span><span class="doxyHighlightStringLiteral">", xs%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">601</span><span class="doxyLineContent"><span class="doxyHighlight">                   </span><span class="doxyHighlightStringLiteral">" | cs%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a> </span><span class="doxyHighlightStringLiteral">"\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">602</span><span class="doxyLineContent"><span class="doxyHighlight">                   __PRETTY_FUNCTION__, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">603</span><span class="doxyLineContent"><span class="doxyHighlight">                   <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#af2b6792d06fa335f2b617e4d39bbba3c">nesting_depth</a> (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">604</span><span class="doxyLineContent"><span class="doxyHighlight">                   <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">totals</a> ().<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">605</span><span class="doxyLineContent"><span class="doxyHighlight">                   <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">totals</a> ().<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#ab1684c7c6101a4d534356d9d16807bee">failed_checks</a> (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">606</span><span class="doxyLineContent"><span class="doxyHighlight">                   <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">totals</a> ().<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a5909350d1852fa54f2cf4c260d99b820">executed_checks</a> (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">607</span><span class="doxyLineContent"><span class="doxyHighlight">                   <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">totals</a> ().<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">executed_test_cases</a> (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">608</span><span class="doxyLineContent"><span class="doxyHighlight">                   <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aff1a81aff41ab5dc80e2fac1c5a78a31">child_test_cases_count_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">609</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">610</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">611</span><span class="doxyLineContent"><span class="doxyHighlight">    std::string <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">indent</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7ee7d450c03e89bb0beb6cd97056aa4e">indent_size_</a> * <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#af2b6792d06fa335f2b617e4d39bbba3c">nesting_depth</a> (), </span><span class="doxyHighlightCharLiteral">' '</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">612</span><span class="doxyLineContent"><span class="doxyHighlight">    std::string indent2 (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7ee7d450c03e89bb0beb6cd97056aa4e">indent_size_</a> * (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#af2b6792d06fa335f2b617e4d39bbba3c">nesting_depth</a> () + 1), </span><span class="doxyHighlightCharLiteral">' '</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">613</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">614</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// The nested test cases skipped by the filter keep their index, and are</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">615</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// counted in the plan.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">616</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> plan_count = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">totals</a> ().<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a5909350d1852fa54f2cf4c260d99b820">executed_checks</a> ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">617</span><span class="doxyLineContent"><span class="doxyHighlight">                        + <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">totals</a> ().<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">executed_test_cases</a> ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">618</span><span class="doxyLineContent"><span class="doxyHighlight">                        + <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">totals</a> ().<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a2e5ea7bbb9bd5a05213dee741f08599d">skipped_test_cases</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">619</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">620</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// The name and the indentation are not included, since their lengths</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">621</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// are not bounded; they are passed to each write.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">622</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> passed = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">totals</a> ().<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a14690f9880df505f9dd90a9f2c3dfc96">passed</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">623</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* result = passed ? </span><span class="doxyHighlightStringLiteral">"ok"</span><span class="doxyHighlight"> : </span><span class="doxyHighlightStringLiteral">"not ok"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">624</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* status = passed ? </span><span class="doxyHighlightStringLiteral">"passed"</span><span class="doxyHighlight"> : </span><span class="doxyHighlightStringLiteral">"FAILED"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">625</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">626</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> message_totals[<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aaa55b147a670878984952ca1112cecd8">totals_size_</a>];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">627</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a60b8564f54a6a1230e6d4ce110de93f5">format_test_case_totals</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>, message_totals);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">628</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">629</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string name = tap_text (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> (), </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">630</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">631</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a37cba38a47d66a928a936ee081c6d88c">write_buffer_to_file</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">632</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">633</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> to_console = (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">verbosity::normal</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">634</span><span class="doxyLineContent"><span class="doxyHighlight">                             || <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">verbosity::verbose</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">635</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">636</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// At this point, the buffer may contain output from the test case, which</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">637</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// should be displayed.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">638</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (to_console)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">639</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">640</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">add_empty_line_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">641</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">642</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#abaee31ffca8e65c9af34f7f67227c5b3">write_console</a> (</span><span class="doxyHighlightStringLiteral">"\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">643</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">644</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">645</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (passed) [[likely]]</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">646</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">647</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightComment">// Successful test case.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">648</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">verbosity::verbose</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">649</span><span class="doxyLineContent"><span class="doxyHighlight">              {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">650</span><span class="doxyLineContent"><span class="doxyHighlight">                </span><span class="doxyHighlightComment">// With verbosity, show full TAP output accumulated in the</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">651</span><span class="doxyLineContent"><span class="doxyHighlight">                </span><span class="doxyHighlightComment">// buffer.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">652</span><span class="doxyLineContent"><span class="doxyHighlight">                <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ae074822d712fc3db3c09f5f2d2237072">write_buffer_to_console</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">653</span><span class="doxyLineContent"><span class="doxyHighlight">              }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">654</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">655</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">656</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">657</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightComment">// Failed test case.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">658</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">659</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightComment">// Show full TAP output accumulated in the buffer for failed</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">660</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightComment">// test cases, as it may contain useful information about the</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">661</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightComment">// failure.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">662</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ae074822d712fc3db3c09f5f2d2237072">write_buffer_to_console</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">663</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">664</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">665</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">666</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (passed &amp;&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">verbosity::normal</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">667</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">668</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// Without verbosity, show only the summary line and count only</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">669</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// test cases, not checks, as the TAP output is not shown; the</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">670</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// output file has all the lines, so its plan counts the checks.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">671</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a90a541c6a9b1ddd3da9440358bfc704e">write_file</a> (</span><span class="doxyHighlightStringLiteral">"%s1..%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a> </span><span class="doxyHighlightStringLiteral">"\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">672</span><span class="doxyLineContent"><span class="doxyHighlight">                    indent2.c_str (), plan_count);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">673</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">674</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#abaee31ffca8e65c9af34f7f67227c5b3">write_console</a> (</span><span class="doxyHighlightStringLiteral">"%s1..%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a> </span><span class="doxyHighlightStringLiteral">"\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">675</span><span class="doxyLineContent"><span class="doxyHighlight">                       indent2.c_str (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">676</span><span class="doxyLineContent"><span class="doxyHighlight">                       <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">totals</a> ().<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">executed_test_cases</a> ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">677</span><span class="doxyLineContent"><span class="doxyHighlight">                           + <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">totals</a> ().<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a2e5ea7bbb9bd5a05213dee741f08599d">skipped_test_cases</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">678</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">679</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">680</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">681</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">write_line</a> (to_console,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">682</span><span class="doxyLineContent"><span class="doxyHighlight">                    </span><span class="doxyHighlightStringLiteral">"%s1..%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a> </span><span class="doxyHighlightStringLiteral">"\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">683</span><span class="doxyLineContent"><span class="doxyHighlight">                    indent2.c_str (), plan_count);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">684</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">685</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">686</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">write_line</a> (to_console,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">687</span><span class="doxyLineContent"><span class="doxyHighlight">                </span><span class="doxyHighlightStringLiteral">"%s%s %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">688</span><span class="doxyLineContent"><span class="doxyHighlight">                </span><span class="doxyHighlightStringLiteral">" - %s # { %s, %s }\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">689</span><span class="doxyLineContent"><span class="doxyHighlight">                <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">indent</a>.c_str (), result, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a69687627342981d42471b17f1d83311f">own_index_</a>, name.c_str (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">690</span><span class="doxyLineContent"><span class="doxyHighlight">                status, message_totals);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">691</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">692</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a804b593aefa158d92a72da43de57d242">flush_streams</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">693</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">694</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5859ce31641330b243cfb5d1c6080859">clear_buffer</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">695</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">696</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">add_empty_line_</a> = </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">697</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">micro_os_plus::micro_test_plus::detail::reporter::add_empty_line_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aff1a81aff41ab5dc80e2fac1c5a78a31">micro_os_plus::micro_test_plus::detail::runnable_base::child_test_cases_count_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5859ce31641330b243cfb5d1c6080859">micro_os_plus::micro_test_plus::detail::reporter::clear_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a5909350d1852fa54f2cf4c260d99b820">micro_os_plus::micro_test_plus::counters::executed_checks</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">micro_os_plus::micro_test_plus::counters::executed_test_cases</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#ab1684c7c6101a4d534356d9d16807bee">micro_os_plus::micro_test_plus::counters::failed_checks</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a804b593aefa158d92a72da43de57d242">micro_os_plus::micro_test_plus::detail::reporter::flush_streams</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a60b8564f54a6a1230e6d4ce110de93f5">micro_os_plus::micro_test_plus::detail::reporter::format_test_case_totals</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">micro_os_plus::micro_test_plus::detail::indent</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7ee7d450c03e89bb0beb6cd97056aa4e">micro_os_plus::micro_test_plus::detail::reporter::indent_size_</a>, <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">micro_os_plus::micro_test_plus::detail::reporter::micro_test_plus::test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">micro_os_plus::micro_test_plus::detail::runnable_base::name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#af2b6792d06fa335f2b617e4d39bbba3c">micro_os_plus::micro_test_plus::test_case::nesting_depth</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">micro_os_plus::micro_test_plus::normal</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a69687627342981d42471b17f1d83311f">micro_os_plus::micro_test_plus::detail::runnable_base::own_index_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a14690f9880df505f9dd90a9f2c3dfc96">micro_os_plus::micro_test_plus::counters::passed</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">micro_os_plus::micro_test_plus::counters::passed_checks</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a2e5ea7bbb9bd5a05213dee741f08599d">micro_os_plus::micro_test_plus::counters::skipped_test_cases</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">micro_os_plus::micro_test_plus::detail::runnable_base::totals</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aaa55b147a670878984952ca1112cecd8">micro_os_plus::micro_test_plus::detail::reporter::totals_size_</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">micro_os_plus::micro_test_plus::verbose</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">micro_os_plus::micro_test_plus::detail::reporter::verbosity_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ae074822d712fc3db3c09f5f2d2237072">micro_os_plus::micro_test_plus::detail::reporter::write_buffer_to_console</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a37cba38a47d66a928a936ee081c6d88c">micro_os_plus::micro_test_plus::detail::reporter::write_buffer_to_file</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#abaee31ffca8e65c9af34f7f67227c5b3">micro_os_plus::micro_test_plus::detail::reporter::write_console</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a90a541c6a9b1ddd3da9440358bfc704e">micro_os_plus::micro_test_plus::detail::reporter::write_file</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">micro_os_plus::micro_test_plus::detail::reporter::write_line</a>.</p>


<p>Referenced by <a href="#a9da35382cc3f903728f5f1bed2c4a745">operator=</a>.</p>

</div>
</div>

### fail() {#a406cf77b7adcd5fe9417ce7bce4f3afb}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter::fail (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info">failure_info</a> &amp; failure, const std::string &amp; expression, const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a> &amp; test_case)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Reports a failed condition.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">failure</td>
<td class="doxyParamItemDescription"><p>The failure details: the kind of the check, the message to display, whether the expression text is displayed, and the source location of the failure.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">expression</td>
<td class="doxyParamItemDescription"><p>The string representation of the expression.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">test_case</td>
<td class="doxyParamItemDescription"><p>The test case that owns this check.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Outputs a fail prefix (which includes the message and the source location), followed, when <span class="doxyComputerOutput">failure.has_expression</span> is true, by the pre-formatted expression string, and a fail suffix.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00442">442</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00621">621</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a406cf77b7adcd5fe9417ce7bce4f3afb">621</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a406cf77b7adcd5fe9417ce7bce4f3afb">reporter::fail</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info">failure_info</a>&amp; failure, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string&amp; expression,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">622</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">623</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">624</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a24888ee49f3e3abb1a849e309a099189">output_fail_prefix</a> (failure.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info/#ad7484cdab2c4142c2df255dc9aadfea6">message</a>, failure.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info/#a6d4c667be4b4a4709ea29505c9d23f12">has_expression</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">625</span><span class="doxyLineContent"><span class="doxyHighlight">                        failure.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info/#a8c259595885388a6a550576d1d3fab35">location</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">626</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">627</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (failure.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info/#a6d4c667be4b4a4709ea29505c9d23f12">has_expression</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">628</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">629</span><span class="doxyLineContent"><span class="doxyHighlight">        *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; expression;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">630</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">631</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">632</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#adce64d6a989f193c1d0c306039a3639c">output_fail_suffix</a> (failure.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info/#a8c259595885388a6a550576d1d3fab35">location</a>, failure.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info/#af7c2c1b52b97d5d2af89155e16bf8c41">kind</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">633</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">634</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a970a08a00e70f1574033085350656230">buffer_has_failures_</a> = </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">635</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a970a08a00e70f1574033085350656230">micro_os_plus::micro_test_plus::detail::reporter::buffer_has_failures_</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info/#a6d4c667be4b4a4709ea29505c9d23f12">micro_os_plus::micro_test_plus::detail::failure_info::has_expression</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info/#af7c2c1b52b97d5d2af89155e16bf8c41">micro_os_plus::micro_test_plus::detail::failure_info::kind</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info/#a8c259595885388a6a550576d1d3fab35">micro_os_plus::micro_test_plus::detail::failure_info::location</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info/#ad7484cdab2c4142c2df255dc9aadfea6">micro_os_plus::micro_test_plus::detail::failure_info::message</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">micro_os_plus::micro_test_plus::detail::reporter::micro_test_plus::test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a24888ee49f3e3abb1a849e309a099189">micro_os_plus::micro_test_plus::detail::reporter::output_fail_prefix</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#adce64d6a989f193c1d0c306039a3639c">micro_os_plus::micro_test_plus::detail::reporter::output_fail_suffix</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a1980019eed5ac5b1eef65302eb9cc9cd">micro_os_plus::micro_test_plus::test_case::fail_unexpected_exception</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">micro_os_plus::micro_test_plus::detail::reporter::micro_test_plus::runner</a>.</p>

</div>
</div>

### fail\_suite() {#a314df80e98fe6fa5de008d6708a14925}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter_tap::fail_suite (const std::string &amp; message, const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a> &amp; suite)</td>
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

<p>Reports a failure of a test suite outside its test cases.</p>


<p>Adds a <span class="doxyComputerOutput">not ok &lt;n&gt; - &lt;message&gt;</span> test point, at the indentation of the test cases, to the output buffer, which <span class="doxyComputerOutput"><a href="#a2d5ddae3195ab52a957927a1b455f7b8">end_suite()</a></span> displays.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">message</td>
<td class="doxyParamItemDescription"><p>The message to display.</p></td>
</tr>
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


<p>Adds a <span class="doxyComputerOutput">not ok &lt;n&gt; - &lt;message&gt;</span> line, with the message escaped (see <span class="doxyComputerOutput">tap_text()</span>), to the output buffer, indented as the test cases of the suite, where <span class="doxyComputerOutput">&lt;n&gt;</span> is the current test point number of the suite, which follows the test cases already run, and is therefore counted in the plan of the suite. Since there is no source location, no YAML diagnostics block follows. The line is displayed by <span class="doxyComputerOutput"><a href="#a2d5ddae3195ab52a957927a1b455f7b8">end_suite()</a></span>, with the other buffered output of the failed suite.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h/#l00222">222</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h">reporter-tap.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp/#l00520">520</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp">reporter-tap.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a314df80e98fe6fa5de008d6708a14925">520</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a314df80e98fe6fa5de008d6708a14925">reporter_tap::fail_suite</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string&amp; message, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">521</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">522</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">523</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s '%s'\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">524</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">525</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">526</span><span class="doxyLineContent"><span class="doxyHighlight">    *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">indent</a> (1) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"not ok "</span><span class="doxyHighlight"> &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#abc92cbb8ab8d04e7c75bf18aa7189d98">test_point_number_</a> &lt;&lt; </span><span class="doxyHighlightStringLiteral">" - "</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">527</span><span class="doxyLineContent"><span class="doxyHighlight">          &lt;&lt; tap_text (message, </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">) &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">endl</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">528</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">529</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a970a08a00e70f1574033085350656230">buffer_has_failures_</a> = </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">530</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a970a08a00e70f1574033085350656230">micro_os_plus::micro_test_plus::detail::reporter::buffer_has_failures_</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">micro_os_plus::micro_test_plus::detail::endl</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">micro_os_plus::micro_test_plus::detail::indent</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">micro_os_plus::micro_test_plus::detail::runnable_base::name</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#abc92cbb8ab8d04e7c75bf18aa7189d98">micro_os_plus::micro_test_plus::detail::runnable_base::test_point_number_</a>.</p>


<p>Referenced by <a href="#a9da35382cc3f903728f5f1bed2c4a745">operator=</a>.</p>

</div>
</div>

### flush\_streams() {#a804b593aefa158d92a72da43de57d242}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter::flush_streams (void)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Flushes the standard output stream and the output file.</p>


<p>Only the C streams are flushed; the internal output buffer is not written.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>This member function flushes the <span class="doxyComputerOutput">stdout</span> stream and, if open, the output file, so that everything already written to them becomes visible. It does not write the contents of the internal buffer.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00380">380</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00472">472</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a804b593aefa158d92a72da43de57d242">472</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a804b593aefa158d92a72da43de57d242">reporter::flush_streams</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">473</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">474</span><span class="doxyLineContent"><span class="doxyHighlight">    fflush (stdout);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">475</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">476</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">477</span><span class="doxyLineContent"><span class="doxyHighlight">        fflush (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">478</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">479</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">micro_os_plus::micro_test_plus::detail::reporter::output_file_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a66f620b093f92e0def6bf5297fb6d6ee">micro_os_plus::micro_test_plus::detail::reporter_human::abort_session</a>, <a href="#aa8802baefcb360f48451418c783ac413">abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#aa3cefeb72e745b2424b48ed4a31102e7">micro_os_plus::micro_test_plus::detail::reporter_human::begin_session</a>, <a href="#acaae91eea2deed1fe3f43b6453e7e656">begin_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a58c85919422801369d1d4d9a8efe77d0">micro_os_plus::micro_test_plus::detail::reporter_human::begin_suite</a>, <a href="#a2c05a737bfe80c955a998dc801e964b5">begin_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a04cef97a62731931038355a1b5f23556">micro_os_plus::micro_test_plus::detail::reporter_human::begin_test_case</a>, <a href="#a0302f9f5b977b05139d73df3bbc18d69">begin_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#adf27b1d3d7cb168f295e4bf198bb0dbf">micro_os_plus::micro_test_plus::detail::reporter_human::commit_buffer</a>, <a href="#af80ba6907c9f13b08f8cb8726d65c510">commit_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ace9c2dfffc49a97516b96dacaf87b943">micro_os_plus::micro_test_plus::detail::reporter_human::end_session</a>, <a href="#a7033819609bfad2db2ecc7a024e91b2c">end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a>, <a href="#a2d5ddae3195ab52a957927a1b455f7b8">end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a>, <a href="#ad15f7dbbf6a683441df40c502125adc3">end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">micro_os_plus::micro_test_plus::detail::reporter::micro_test_plus::runner</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#aca37d52611ed87d102dce89c3c6cc99d">micro_os_plus::micro_test_plus::detail::reporter_human::skip_suite</a>, <a href="#a319f35d4af8c72af8b14a89b421c1c74">skip_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af28ab5a9448645fb8976c0b139bf302b">micro_os_plus::micro_test_plus::detail::reporter_human::skip_test_case</a> and <a href="#a31ccd7af941d06241ce16df9274abc38">skip_test_case</a>.</p>

</div>
</div>

### has\_output\_file\_error() {#a083ecdfa952d7f8c372a61fbea309357}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::detail::reporter::has_output_file_error (void)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Returns whether the output file could not be opened.</p>


<p>Checked by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#acfabd0e10d233ad305b6f4fc125a97f2">runner::initialise()</a></span>, which reports it as an option error; the report is then written only to the console.</p>


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
<td class="doxyParamItemDescription"><p>The output file was requested but could not be opened.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">false</td>
<td class="doxyParamItemDescription"><p>No output file was requested, or it was opened.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Returns the flag set by the constructor when <span class="doxyComputerOutput">fopen()</span> failed.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00396">396</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00486">486</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a083ecdfa952d7f8c372a61fbea309357">486</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a083ecdfa952d7f8c372a61fbea309357">reporter::has_output_file_error</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">487</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">488</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0d73674812cca717a754137b4b26ed89">has_output_file_error_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">489</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0d73674812cca717a754137b4b26ed89">micro_os_plus::micro_test_plus::detail::reporter::has_output_file_error_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">micro_os_plus::micro_test_plus::detail::reporter::micro_test_plus::runner</a>.</p>

</div>
</div>

### pass() {#ad9e6ccebc1904f723409ddb0caaddb3e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter::pass (const std::string &amp; message, const std::string &amp; expression, const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a> &amp; test_case)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Reports a passed condition.</p>


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
<td class="doxyParamItemName">test_case</td>
<td class="doxyParamItemDescription"><p>The test case that owns this check.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Outputs a pass prefix, followed by either the provided message or, if the message is empty, the evaluated expression string itself. A pass suffix is then appended to complete the output.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00427">427</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00601">601</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ad9e6ccebc1904f723409ddb0caaddb3e">601</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ad9e6ccebc1904f723409ddb0caaddb3e">reporter::pass</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string&amp; message, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string&amp; expression,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">602</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">603</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">604</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aede54e424adbe77bdb6b87d40f2d3517">output_pass_prefix</a> (message, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">605</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">606</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (message.empty ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">607</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">608</span><span class="doxyLineContent"><span class="doxyHighlight">        *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; expression;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">609</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">610</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">611</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a82f4940bc3915b3fdcb58823f9bdb535">output_pass_suffix</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">612</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">micro_os_plus::micro_test_plus::detail::reporter::micro_test_plus::test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aede54e424adbe77bdb6b87d40f2d3517">micro_os_plus::micro_test_plus::detail::reporter::output_pass_prefix</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a82f4940bc3915b3fdcb58823f9bdb535">micro_os_plus::micro_test_plus::detail::reporter::output_pass_suffix</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">micro_os_plus::micro_test_plus::detail::reporter::micro_test_plus::runner</a>.</p>

</div>
</div>

### skip\_suite() {#a319f35d4af8c72af8b14a89b421c1c74}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter_tap::skip_suite (const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a> &amp; suite)</td>
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

<p>Reports a test suite skipped by the filter.</p>


<p>Displays an <span class="doxyComputerOutput">ok &lt;index&gt; - &lt;name&gt; # SKIP filtered</span> line, instead of the suite body and results.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">suite</td>
<td class="doxyParamItemDescription"><p>Reference to the skipped test suite.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Emits an <span class="doxyComputerOutput">ok &lt;index&gt; - &lt;name&gt; # SKIP filtered</span> line, with the name escaped (see <span class="doxyComputerOutput">tap_text()</span>), without a test case block, so that the suite keeps its place in the TAP plan of the session. The line is written to the output file when one is open. Unless verbosity is silent, it is also written to <span class="doxyComputerOutput">stdout</span>; under normal or verbose verbosity, it is preceded by a blank line when <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">add_empty_line_</a></span> is set. With quiet verbosity, it is written as the result lines of <span class="doxyComputerOutput"><a href="#a2d5ddae3195ab52a957927a1b455f7b8">end_suite()</a></span>, which the session plan counts.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h/#l00207">207</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h">reporter-tap.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp/#l00484">484</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp">reporter-tap.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a319f35d4af8c72af8b14a89b421c1c74">484</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a319f35d4af8c72af8b14a89b421c1c74">reporter_tap::skip_suite</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">485</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">486</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">487</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s '%s'\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">488</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">489</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">490</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string name = tap_text (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> (), </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">491</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">492</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> to_console = (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> != <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">verbosity::silent</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">493</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">494</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (to_console &amp;&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">add_empty_line_</a> &amp;&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> != <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba556966c7830465dc4623d62e32cec31d">verbosity::quiet</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">495</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">496</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#abaee31ffca8e65c9af34f7f67227c5b3">write_console</a> (</span><span class="doxyHighlightStringLiteral">"\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">497</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">498</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">499</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">write_line</a> (to_console,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">500</span><span class="doxyLineContent"><span class="doxyHighlight">                </span><span class="doxyHighlightStringLiteral">"ok %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">501</span><span class="doxyLineContent"><span class="doxyHighlight">                </span><span class="doxyHighlightStringLiteral">" - %s # SKIP filtered\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">502</span><span class="doxyLineContent"><span class="doxyHighlight">                <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a69687627342981d42471b17f1d83311f">own_index_</a>, name.c_str ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">503</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">504</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a804b593aefa158d92a72da43de57d242">flush_streams</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">505</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">506</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">add_empty_line_</a> = </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">507</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">micro_os_plus::micro_test_plus::detail::reporter::add_empty_line_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a804b593aefa158d92a72da43de57d242">micro_os_plus::micro_test_plus::detail::reporter::flush_streams</a>, <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">micro_os_plus::micro_test_plus::detail::runnable_base::name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a69687627342981d42471b17f1d83311f">micro_os_plus::micro_test_plus::detail::runnable_base::own_index_</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba556966c7830465dc4623d62e32cec31d">micro_os_plus::micro_test_plus::quiet</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">micro_os_plus::micro_test_plus::silent</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">micro_os_plus::micro_test_plus::detail::reporter::verbosity_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#abaee31ffca8e65c9af34f7f67227c5b3">micro_os_plus::micro_test_plus::detail::reporter::write_console</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">micro_os_plus::micro_test_plus::detail::reporter::write_line</a>.</p>


<p>Referenced by <a href="#a9da35382cc3f903728f5f1bed2c4a745">operator=</a>.</p>

</div>
</div>

### skip\_test\_case() {#a31ccd7af941d06241ce16df9274abc38}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter_tap::skip_test_case (const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a> &amp; test_case)</td>
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

<p>Reports a test case skipped by the filter.</p>


<p>Displays an <span class="doxyComputerOutput">ok &lt;index&gt; - &lt;name&gt; # SKIP filtered</span> line, indented by its nesting depth.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">test_case</td>
<td class="doxyParamItemDescription"><p>Reference to the skipped test case.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>As in <span class="doxyComputerOutput"><a href="#a0302f9f5b977b05139d73df3bbc18d69">begin_test_case()</a></span>, for a nested test case, the results of the checks already performed by the outer test case, if any, are written first (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5cf73aaf67484b50c25ef42363d49337">commit_outer_results()</a></span>), so that the output follows the execution order.</p>


<p>An <span class="doxyComputerOutput">ok &lt;index&gt; - &lt;name&gt; # SKIP filtered</span> line, with the name escaped, indented according to the nesting depth, without a test case block, is then written to the output file and, under normal or verbose verbosity, to <span class="doxyComputerOutput">stdout</span>, preceded by a blank line when <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">add_empty_line_</a></span> is set.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h/#l00256">256</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h">reporter-tap.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp/#l00894">894</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp">reporter-tap.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a31ccd7af941d06241ce16df9274abc38">894</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a31ccd7af941d06241ce16df9274abc38">reporter_tap::skip_test_case</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">895</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">896</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">897</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s '%s'\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">898</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">899</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">900</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5cf73aaf67484b50c25ef42363d49337">commit_outer_results</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">901</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">902</span><span class="doxyLineContent"><span class="doxyHighlight">    std::string <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">indent</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7ee7d450c03e89bb0beb6cd97056aa4e">indent_size_</a> * <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#af2b6792d06fa335f2b617e4d39bbba3c">nesting_depth</a> (), </span><span class="doxyHighlightCharLiteral">' '</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">903</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">904</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string name = tap_text (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> (), </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">905</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">906</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> to_console = (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">verbosity::normal</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">907</span><span class="doxyLineContent"><span class="doxyHighlight">                             || <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">verbosity::verbose</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">908</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">909</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (to_console &amp;&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">add_empty_line_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">910</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">911</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#abaee31ffca8e65c9af34f7f67227c5b3">write_console</a> (</span><span class="doxyHighlightStringLiteral">"\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">912</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">913</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">914</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">write_line</a> (to_console,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">915</span><span class="doxyLineContent"><span class="doxyHighlight">                </span><span class="doxyHighlightStringLiteral">"%sok %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">916</span><span class="doxyLineContent"><span class="doxyHighlight">                </span><span class="doxyHighlightStringLiteral">" - %s # SKIP filtered\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">917</span><span class="doxyLineContent"><span class="doxyHighlight">                <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">indent</a>.c_str (), <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a69687627342981d42471b17f1d83311f">own_index_</a>, name.c_str ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">918</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">919</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a804b593aefa158d92a72da43de57d242">flush_streams</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">920</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">921</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">add_empty_line_</a> = </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">922</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">micro_os_plus::micro_test_plus::detail::reporter::add_empty_line_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5cf73aaf67484b50c25ef42363d49337">micro_os_plus::micro_test_plus::detail::reporter::commit_outer_results</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a804b593aefa158d92a72da43de57d242">micro_os_plus::micro_test_plus::detail::reporter::flush_streams</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">micro_os_plus::micro_test_plus::detail::indent</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7ee7d450c03e89bb0beb6cd97056aa4e">micro_os_plus::micro_test_plus::detail::reporter::indent_size_</a>, <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">micro_os_plus::micro_test_plus::detail::reporter::micro_test_plus::test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">micro_os_plus::micro_test_plus::detail::runnable_base::name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#af2b6792d06fa335f2b617e4d39bbba3c">micro_os_plus::micro_test_plus::test_case::nesting_depth</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">micro_os_plus::micro_test_plus::normal</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a69687627342981d42471b17f1d83311f">micro_os_plus::micro_test_plus::detail::runnable_base::own_index_</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">micro_os_plus::micro_test_plus::verbose</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">micro_os_plus::micro_test_plus::detail::reporter::verbosity_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#abaee31ffca8e65c9af34f7f67227c5b3">micro_os_plus::micro_test_plus::detail::reporter::write_console</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">micro_os_plus::micro_test_plus::detail::reporter::write_line</a>.</p>


<p>Referenced by <a href="#a9da35382cc3f903728f5f1bed2c4a745">operator=</a>.</p>

</div>
</div>

### verbosity() {#a467d1332df523b9acaa3ff82b0ebb714}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_test_plus::verbosity micro_os_plus::micro_test_plus::detail::reporter::verbosity (void)</td>
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

<p>Deprecated access to the verbosity level.</p>


<p>Kept from the v5.0.1 <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a></span> class, for the applications that read it through the deprecated <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a65250ff363fbb3b5869bbe4de9578e86">runner::reporter()</a></span> (<span class="doxyComputerOutput">tr.reporter ().<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a467d1332df523b9acaa3ff82b0ebb714">verbosity</a> ()</span>). The level is the one returned by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a1dd0221dca8e7382f0b625ff6316ed92">runner::verbosity_level()</a></span>, from the same session options.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The verbosity level of the session.</p></dd>
</dl>


<div class="doxyXrefSect">
<dl class="doxyXrefSectList">
<dt class="doxyXrefSectTitle"><a href=/micro-test-plus-xpack/docs/api/pages/deprecated/#_deprecated000051>Deprecated</a></dt>
<dd class="doxyXrefSectDescription">
<p>use <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a1dd0221dca8e7382f0b625ff6316ed92">runner::verbosity_level()</a> (since 5.1.0)</p>
</dd>
</dl>
</div>

<p>Returns the level stored in <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a></span>, set by the constructor.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00413">413</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reporter-inlines-h/#l00113">113</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reporter-inlines-h">reporter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a467d1332df523b9acaa3ff82b0ebb714">113</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a467d1332df523b9acaa3ff82b0ebb714">reporter::verbosity</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight"> -&gt; <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914b">micro_test_plus::verbosity</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">114</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">115</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">116</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">micro_os_plus::micro_test_plus::detail::reporter::verbosity_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">micro_os_plus::micro_test_plus::detail::reporter::micro_test_plus::runner</a>.</p>

</div>
</div>

### write\_buffer\_to\_console() {#ae074822d712fc3db3c09f5f2d2237072}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter::write_buffer_to_console (void)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Writes the current buffered content to the console.</p>


<p>The console is the standard output stream; the buffer is written verbatim, without appending a line ending, and is not cleared.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>This member function writes the contents of the internal output buffer to the console without appending a newline character. The buffer is not cleared; the caller is responsible for clearing it when appropriate.</p>


<p>The buffer is written with its size, not as a C string, so that a zero character in a message does not end the output.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00365">365</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00253">253</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ae074822d712fc3db3c09f5f2d2237072">253</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ae074822d712fc3db3c09f5f2d2237072">reporter::write_buffer_to_console</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">254</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">255</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Pass only the string, do not add an `\n` here.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">256</span><span class="doxyLineContent"><span class="doxyHighlight">    fwrite (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>.data (), 1, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>.size (), stdout);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">257</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">micro_os_plus::micro_test_plus::detail::reporter::buffer_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a66f620b093f92e0def6bf5297fb6d6ee">micro_os_plus::micro_test_plus::detail::reporter_human::abort_session</a>, <a href="#aa8802baefcb360f48451418c783ac413">abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#adf27b1d3d7cb168f295e4bf198bb0dbf">micro_os_plus::micro_test_plus::detail::reporter_human::commit_buffer</a>, <a href="#af80ba6907c9f13b08f8cb8726d65c510">commit_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a>, <a href="#a2d5ddae3195ab52a957927a1b455f7b8">end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a>, <a href="#ad15f7dbbf6a683441df40c502125adc3">end_test_case</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">micro_os_plus::micro_test_plus::detail::reporter::micro_test_plus::runner</a>.</p>

</div>
</div>

### writes\_passed\_checks() {#a841b146b309b93422ae707094ba044f6}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::detail::reporter_tap::writes_passed_checks (void)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
<span class="doxyMemberLabel virtual">virtual</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Returns whether the passed checks are written anywhere.</p>


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
<td class="doxyParamItemDescription"><p>An output file is open, or the verbosity is normal or verbose.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">false</td>
<td class="doxyParamItemDescription"><p>There is no output file, and the verbosity is quiet or silent.</p></td>
</tr>
</table>
</dd>
</dl>

<p>The buffered test points are always written to the output file, if open, since its plans count all the checks; without one, they are written to <span class="doxyComputerOutput">stdout</span> only with normal or verbose verbosity. With quiet verbosity, only the buffer of an aborted test execution is displayed (see <span class="doxyComputerOutput"><a href="#aa8802baefcb360f48451418c783ac413">abort_session()</a></span>), which then includes only the failed checks.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h/#l00299">299</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h">reporter-tap.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp/#l00723">723</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp">reporter-tap.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a841b146b309b93422ae707094ba044f6">723</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a841b146b309b93422ae707094ba044f6">reporter_tap::writes_passed_checks</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">724</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">725</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight"> || <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">verbosity::normal</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">726</span><span class="doxyLineContent"><span class="doxyHighlight">           || <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">verbosity::verbose</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">727</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">micro_os_plus::micro_test_plus::normal</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">micro_os_plus::micro_test_plus::detail::reporter::output_file_</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">micro_os_plus::micro_test_plus::verbose</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">micro_os_plus::micro_test_plus::detail::reporter::verbosity_</a>.</p>


<p>Referenced by <a href="#a9da35382cc3f903728f5f1bed2c4a745">operator=</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Protected Member Functions

### clear\_buffer() {#a5859ce31641330b243cfb5d1c6080859}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter::clear_buffer (void)</td>
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

<p>Clears the output buffer.</p>


<p>Also resets <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a970a08a00e70f1574033085350656230">buffer_has_failures_</a></span>, so that the flag always describes the current content of the buffer.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Empties <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a></span>, keeping its capacity, and resets <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a970a08a00e70f1574033085350656230">buffer_has_failures_</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00786">786</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00643">643</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5859ce31641330b243cfb5d1c6080859">643</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5859ce31641330b243cfb5d1c6080859">reporter::clear_buffer</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">644</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">645</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>.clear ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">646</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a970a08a00e70f1574033085350656230">buffer_has_failures_</a> = </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">647</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">micro_os_plus::micro_test_plus::detail::reporter::buffer_</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a970a08a00e70f1574033085350656230">micro_os_plus::micro_test_plus::detail::reporter::buffer_has_failures_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a66f620b093f92e0def6bf5297fb6d6ee">micro_os_plus::micro_test_plus::detail::reporter_human::abort_session</a>, <a href="#aa8802baefcb360f48451418c783ac413">abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#adf27b1d3d7cb168f295e4bf198bb0dbf">micro_os_plus::micro_test_plus::detail::reporter_human::commit_buffer</a>, <a href="#af80ba6907c9f13b08f8cb8726d65c510">commit_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a>, <a href="#a2d5ddae3195ab52a957927a1b455f7b8">end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a>, <a href="#ad15f7dbbf6a683441df40c502125adc3">end_test_case</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2c1e2c756b442d4832c161c8127faacf">micro_os_plus::micro_test_plus::detail::reporter::writes_passed_checks</a>.</p>

</div>
</div>

### commit\_outer\_results() {#a5cf73aaf67484b50c25ef42363d49337}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter::commit_outer_results (void)</td>
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

<p>Writes the results of the outer test case, if any, before a nested test case begins or is skipped.</p>


<p>Called by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa5f6b45879c1e0986ce4ebf9f374a182">begin_test_case()</a></span> and <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a1986653001ad23e18de13822bbcd022f">skip_test_case()</a></span> of the concrete reporters, so that the output follows the execution order.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>For a nested test case, the outer test case may have performed checks before it; their results are written first, by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a844e80839c81133b52ee3beabf64d942">commit_buffer()</a></span>. For a top-level test case, the buffer is expected to be empty, since the checks are performed only by the test cases, and each one writes its results when it ends; should it not be, its content is written in the same way, rather than lost or attributed to the next test case, and the run continues.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00936">936</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00860">860</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5cf73aaf67484b50c25ef42363d49337">860</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5cf73aaf67484b50c25ef42363d49337">reporter::commit_outer_results</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">861</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">862</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (!<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>.empty ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">863</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">864</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a844e80839c81133b52ee3beabf64d942">commit_buffer</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">865</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">866</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">micro_os_plus::micro_test_plus::detail::reporter::buffer_</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a844e80839c81133b52ee3beabf64d942">micro_os_plus::micro_test_plus::detail::reporter::commit_buffer</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a04cef97a62731931038355a1b5f23556">micro_os_plus::micro_test_plus::detail::reporter_human::begin_test_case</a>, <a href="#a0302f9f5b977b05139d73df3bbc18d69">begin_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a844e80839c81133b52ee3beabf64d942">micro_os_plus::micro_test_plus::detail::reporter::commit_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af28ab5a9448645fb8976c0b139bf302b">micro_os_plus::micro_test_plus::detail::reporter_human::skip_test_case</a> and <a href="#a31ccd7af941d06241ce16df9274abc38">skip_test_case</a>.</p>

</div>
</div>

### write\_buffer\_to\_file() {#a37cba38a47d66a928a936ee081c6d88c}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter::write_buffer_to_file (void)</td>
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

<p>Writes the current buffered content to the output file.</p>


<p>The buffer is written without appending a line ending, and is not cleared. ANSI colour sequences are removed, so the file receives plain text even when the console output is coloured. If no output file is open, the call has no effect.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Writes the contents of <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a></span> to <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a></span> without appending a newline. If <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a></span> is null, the call is a no-op.</p>


<p>The buffer may contain ANSI colour sequences, added when the console is a terminal, which must not reach the file; they are removed by <span class="doxyComputerOutput">write_without_colours()</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00691">691</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00269">269</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a37cba38a47d66a928a936ee081c6d88c">269</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a37cba38a47d66a928a936ee081c6d88c">reporter::write_buffer_to_file</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">270</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">271</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> == </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">272</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">273</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">274</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">275</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">276</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Pass only the string, do not add an `\n` here.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">277</span><span class="doxyLineContent"><span class="doxyHighlight">    write_without_colours (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">278</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">micro_os_plus::micro_test_plus::detail::reporter::buffer_</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">micro_os_plus::micro_test_plus::detail::reporter::output_file_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a66f620b093f92e0def6bf5297fb6d6ee">micro_os_plus::micro_test_plus::detail::reporter_human::abort_session</a>, <a href="#aa8802baefcb360f48451418c783ac413">abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#adf27b1d3d7cb168f295e4bf198bb0dbf">micro_os_plus::micro_test_plus::detail::reporter_human::commit_buffer</a>, <a href="#af80ba6907c9f13b08f8cb8726d65c510">commit_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a>, <a href="#a2d5ddae3195ab52a957927a1b455f7b8">end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a>, <a href="#ad15f7dbbf6a683441df40c502125adc3">end_test_case</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2c1e2c756b442d4832c161c8127faacf">micro_os_plus::micro_test_plus::detail::reporter::writes_passed_checks</a>.</p>

</div>
</div>

### write\_console() {#abaee31ffca8e65c9af34f7f67227c5b3}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter::write_console (const char * format, ...)</td>
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

<p>Writes formatted text to the console.</p>


<p>All reporter console output is routed through this function, so that it reaches the standard output stream via a single path, shared with the output of the user <span class="doxyComputerOutput">printf()</span> calls. Using one stream-based path keeps the reporter and user output in the same buffer, preserving their relative order.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">format</td>
<td class="doxyParamItemDescription"><p>A <span class="doxyComputerOutput">printf()</span>-style format string.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">...</td>
<td class="doxyParamItemDescription"><p>The arguments referred to by the format string.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>The arguments are forwarded to <span class="doxyComputerOutput">vfprintf()</span> on <span class="doxyComputerOutput">stdout</span>. The stream is explicit, so the compiler does not rewrite the call into <span class="doxyComputerOutput">puts()</span> or <span class="doxyComputerOutput">putchar()</span>, and all console output shares the same <span class="doxyComputerOutput">FILE</span>-based path.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00709">709</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00288">288</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#abaee31ffca8e65c9af34f7f67227c5b3">288</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#abaee31ffca8e65c9af34f7f67227c5b3">reporter::write_console</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* format, ...)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">289</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">290</span><span class="doxyLineContent"><span class="doxyHighlight">    va_list args;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">291</span><span class="doxyLineContent"><span class="doxyHighlight">    va_start (args, format);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">292</span><span class="doxyLineContent"><span class="doxyHighlight">    vfprintf (stdout, format, args);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">293</span><span class="doxyLineContent"><span class="doxyHighlight">    va_end (args);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">294</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5b6052e6c28235b76d855b2b7bc176dd">micro_os_plus::micro_test_plus::detail::reporter::~reporter</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a66f620b093f92e0def6bf5297fb6d6ee">micro_os_plus::micro_test_plus::detail::reporter_human::abort_session</a>, <a href="#aa8802baefcb360f48451418c783ac413">abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#aa3cefeb72e745b2424b48ed4a31102e7">micro_os_plus::micro_test_plus::detail::reporter_human::begin_session</a>, <a href="#acaae91eea2deed1fe3f43b6453e7e656">begin_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a58c85919422801369d1d4d9a8efe77d0">micro_os_plus::micro_test_plus::detail::reporter_human::begin_suite</a>, <a href="#a2c05a737bfe80c955a998dc801e964b5">begin_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a04cef97a62731931038355a1b5f23556">micro_os_plus::micro_test_plus::detail::reporter_human::begin_test_case</a>, <a href="#a0302f9f5b977b05139d73df3bbc18d69">begin_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#adf27b1d3d7cb168f295e4bf198bb0dbf">micro_os_plus::micro_test_plus::detail::reporter_human::commit_buffer</a>, <a href="#af80ba6907c9f13b08f8cb8726d65c510">commit_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af17a48a165abd908031ddc3a0821f81e">micro_os_plus::micro_test_plus::detail::reporter_human::display_open_names</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ace9c2dfffc49a97516b96dacaf87b943">micro_os_plus::micro_test_plus::detail::reporter_human::end_session</a>, <a href="#a7033819609bfad2db2ecc7a024e91b2c">end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a>, <a href="#a2d5ddae3195ab52a957927a1b455f7b8">end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a>, <a href="#ad15f7dbbf6a683441df40c502125adc3">end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#aca37d52611ed87d102dce89c3c6cc99d">micro_os_plus::micro_test_plus::detail::reporter_human::skip_suite</a>, <a href="#a319f35d4af8c72af8b14a89b421c1c74">skip_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af28ab5a9448645fb8976c0b139bf302b">micro_os_plus::micro_test_plus::detail::reporter_human::skip_test_case</a>, <a href="#a31ccd7af941d06241ce16df9274abc38">skip_test_case</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2c1e2c756b442d4832c161c8127faacf">micro_os_plus::micro_test_plus::detail::reporter::writes_passed_checks</a>.</p>

</div>
</div>

### write\_file() {#a90a541c6a9b1ddd3da9440358bfc704e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter::write_file (const char * format, ...)</td>
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

<p>Writes formatted text to the output file.</p>


<p>If no output file is open, the call has no effect, so callers do not need to check <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a></span> themselves.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">format</td>
<td class="doxyParamItemDescription"><p>A <span class="doxyComputerOutput">printf()</span>-style format string.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">...</td>
<td class="doxyParamItemDescription"><p>The arguments referred to by the format string.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>The arguments are forwarded to <span class="doxyComputerOutput">vfprintf()</span> on <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a></span>. If <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a></span> is null, the arguments are ignored.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00728">728</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00302">302</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a90a541c6a9b1ddd3da9440358bfc704e">302</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a90a541c6a9b1ddd3da9440358bfc704e">reporter::write_file</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* format, ...)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">303</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">304</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> == </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">305</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">306</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">307</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">308</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">309</span><span class="doxyLineContent"><span class="doxyHighlight">    va_list args;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">310</span><span class="doxyLineContent"><span class="doxyHighlight">    va_start (args, format);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">311</span><span class="doxyLineContent"><span class="doxyHighlight">    vfprintf (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a>, format, args);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">312</span><span class="doxyLineContent"><span class="doxyHighlight">    va_end (args);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">313</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">micro_os_plus::micro_test_plus::detail::reporter::output_file_</a>.</p>


<p>Referenced by <a href="#ad15f7dbbf6a683441df40c502125adc3">end_test_case</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2c1e2c756b442d4832c161c8127faacf">micro_os_plus::micro_test_plus::detail::reporter::writes_passed_checks</a>.</p>

</div>
</div>

### write\_info() {#aeafdc8e05a6d80d9445f17ff354ee215}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter::write_info (void)</td>
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

<p>Writes the informational (non-result) lines to the console and to the output file.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Constructs and emits two informational lines, each prefixed by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a324aa273975068c140ab6eecc7e722c9">comment_prefix()</a></span>: the first lists the program name (without the path) and any command-line arguments; the second identifies the compiler (Clang, GCC, or MSVC) together with the version string, floating-point availability on bare-metal targets, exception support, and any active debug or trace macros. Both lines are written to the output file when one is open, and to <span class="doxyComputerOutput">stdout</span> when the verbosity is <span class="doxyComputerOutput">normal</span> or <span class="doxyComputerOutput">verbose</span>, except when both <span class="doxyComputerOutput">MICRO_OS_PLUS_STARTUP_ENABLED</span> and <span class="doxyComputerOutput">MICRO_OS_PLUS_DIAG_TRACE_ENABLED</span> are defined, since the startup code already displays this information.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00771">771</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00390">390</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aeafdc8e05a6d80d9445f17ff354ee215">390</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aeafdc8e05a6d80d9445f17ff354ee215">reporter::write_info</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">391</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">392</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_STARTUP_ENABLED) \</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">393</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">    &amp;&amp; defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">394</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// The startup code already displays this information.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">395</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> to_console = </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">396</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">397</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> to_console = (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">verbosity::normal</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">398</span><span class="doxyLineContent"><span class="doxyHighlight">                             || <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">verbosity::verbose</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">399</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(MICRO_OS_PLUS_STARTUP_ENABLED) &amp;&amp; ...</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">400</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">401</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (!<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a3e47f2c530c5019bde9fe56867bc581f">arguments_</a>.empty ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">402</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">403</span><span class="doxyLineContent"><span class="doxyHighlight">        std::string line;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">404</span><span class="doxyLineContent"><span class="doxyHighlight">        line.reserve (256);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">405</span><span class="doxyLineContent"><span class="doxyHighlight">        line.append (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a324aa273975068c140ab6eecc7e722c9">comment_prefix</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">406</span><span class="doxyLineContent"><span class="doxyHighlight">        line.append (</span><span class="doxyHighlightStringLiteral">"Running: "</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">407</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">408</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// Append only the file name part of argv[0].</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">409</span><span class="doxyLineContent"><span class="doxyHighlight">        line.append (<a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-utility-functions/#ga791f22f0c85b6436c9016821907b0653">utility::extract_file_name</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a3e47f2c530c5019bde9fe56867bc581f">arguments_</a>[0]));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">410</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">411</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* argument : <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a3e47f2c530c5019bde9fe56867bc581f">arguments_</a>.subspan (1))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">412</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">413</span><span class="doxyLineContent"><span class="doxyHighlight">            line.append (</span><span class="doxyHighlightStringLiteral">" "</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">414</span><span class="doxyLineContent"><span class="doxyHighlight">            line.append (argument);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">415</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">416</span><span class="doxyLineContent"><span class="doxyHighlight">        line.append (</span><span class="doxyHighlightStringLiteral">"\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">417</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">418</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">write_line</a> (to_console, </span><span class="doxyHighlightStringLiteral">"%s"</span><span class="doxyHighlight">, line.c_str ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">419</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">420</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">421</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">422</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// Build the "Built with ..." line, including the compiler version</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">423</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// (via __VERSION__); the same line goes to the file and to stdout.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">424</span><span class="doxyLineContent"><span class="doxyHighlight">      std::string line;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">425</span><span class="doxyLineContent"><span class="doxyHighlight">      line.reserve (256);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">426</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a324aa273975068c140ab6eecc7e722c9">comment_prefix</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">427</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">"Built with "</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">428</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">429</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">"clang "</span><span class="doxyHighlight"> __VERSION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">430</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#elif defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">431</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">"GCC "</span><span class="doxyHighlight"> __VERSION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">432</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#elif defined(_MSC_VER)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">433</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">"MSVC"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">434</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> msvc_ver[16];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">435</span><span class="doxyLineContent"><span class="doxyHighlight">      snprintf (msvc_ver, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (msvc_ver), </span><span class="doxyHighlightStringLiteral">" - %d"</span><span class="doxyHighlight">, _MSC_VER);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">436</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (msvc_ver);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">437</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">438</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">"an unknown compiler"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">439</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">440</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if !(defined(__APPLE__) || defined(__linux__) || defined(__unix__) \</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">441</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">      || defined(_WIN32))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">442</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// This is relevant only on bare-metal.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">443</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__ARM_PCS_VFP) || defined(__ARM_FP)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">444</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">", with FP"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">445</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">446</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">", no FP"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">447</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__ARM_PCS_VFP) || defined(__ARM_FP)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">448</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// !(defined(__APPLE__) || defined(__linux__) || defined(__unix__) || defined(_WIN32))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">449</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__cpp_exceptions)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">450</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">", with exceptions"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">451</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">452</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">", no exceptions"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">453</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__cpp_exceptions)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">454</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_DEBUG_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">455</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">", with MICRO_OS_PLUS_DEBUG_ENABLED"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">456</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(MICRO_OS_PLUS_DEBUG_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">457</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">458</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">", with MICRO_OS_PLUS_DIAG_TRACE_ENABLED"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">459</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">460</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">461</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">write_line</a> (to_console, </span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, line.c_str ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">462</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">463</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a3e47f2c530c5019bde9fe56867bc581f">micro_os_plus::micro_test_plus::detail::reporter::arguments_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a324aa273975068c140ab6eecc7e722c9">micro_os_plus::micro_test_plus::detail::reporter::comment_prefix</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-utility-functions/#ga791f22f0c85b6436c9016821907b0653">micro_os_plus::micro_test_plus::utility::extract_file_name</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">micro_os_plus::micro_test_plus::normal</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">micro_os_plus::micro_test_plus::verbose</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">micro_os_plus::micro_test_plus::detail::reporter::verbosity_</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">micro_os_plus::micro_test_plus::detail::reporter::write_line</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#aa3cefeb72e745b2424b48ed4a31102e7">micro_os_plus::micro_test_plus::detail::reporter_human::begin_session</a>, <a href="#acaae91eea2deed1fe3f43b6453e7e656">begin_session</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2c1e2c756b442d4832c161c8127faacf">micro_os_plus::micro_test_plus::detail::reporter::writes_passed_checks</a>.</p>

</div>
</div>

### write\_line() {#aa97f2ba65009154090dc68e42c94db71}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter::write_line (bool to_console, const char * format, ...)</td>
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

<p>Writes formatted lines to the output file and, when requested, to the console.</p>


<p>The text is formatted once, and the same text is written to the output file, if open, and, when <span class="doxyComputerOutput">to_console</span> is true, to <span class="doxyComputerOutput">stdout</span>. As in <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a37cba38a47d66a928a936ee081c6d88c">write_buffer_to_file()</a></span>, the ANSI colour sequences are removed from the file copy, so a console line with colours and its plain file line are written by one call. The format normally ends with a line ending; any empty line or buffered output that precedes the console line is written by the caller, before this call.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">to_console</td>
<td class="doxyParamItemDescription"><p>Whether to write the text to <span class="doxyComputerOutput">stdout</span> as well.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">format</td>
<td class="doxyParamItemDescription"><p>A <span class="doxyComputerOutput">printf()</span>-style format string.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">...</td>
<td class="doxyParamItemDescription"><p>The arguments referred to by the format string.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>The text is formatted with <span class="doxyComputerOutput">vsnprintf()</span> into a local array, which holds the usual lines without an allocation; a longer text, for example with a long test name, is formatted again, from a copy of the arguments, into a string of the exact length. The array is kept small, since the lines that end the nested test cases are written at the deepest point of the stack. The text is then written with its length to the output file, without the colour sequences (see <span class="doxyComputerOutput">write_without_colours()</span>), and, when requested, to <span class="doxyComputerOutput">stdout</span>, unchanged. When there is nowhere to write, or the formatting fails, nothing is written.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00755">755</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00329">329</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">329</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">reporter::write_line</a> (</span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> to_console, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* format, ...)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">330</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">331</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> == </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight"> &amp;&amp; !to_console)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">332</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">333</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">334</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">335</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">336</span><span class="doxyLineContent"><span class="doxyHighlight">    va_list args;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">337</span><span class="doxyLineContent"><span class="doxyHighlight">    va_start (args, format);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">338</span><span class="doxyLineContent"><span class="doxyHighlight">    va_list args_copy;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">339</span><span class="doxyLineContent"><span class="doxyHighlight">    va_copy (args_copy, args);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">340</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">341</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> local_text[128];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">342</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> length</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">343</span><span class="doxyLineContent"><span class="doxyHighlight">        = vsnprintf (local_text, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (local_text), format, args);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">344</span><span class="doxyLineContent"><span class="doxyHighlight">    va_end (args);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">345</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">346</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (length &lt; 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">347</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">348</span><span class="doxyLineContent"><span class="doxyHighlight">        va_end (args_copy);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">349</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">350</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">351</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">352</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> size = </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (length);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">353</span><span class="doxyLineContent"><span class="doxyHighlight">    std::string long_text;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">354</span><span class="doxyLineContent"><span class="doxyHighlight">    std::string_view text{ local_text, size };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">355</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (size &gt;= </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (local_text))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">356</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">357</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// The terminating null character is written over the one kept by</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">358</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// the string after its content.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">359</span><span class="doxyLineContent"><span class="doxyHighlight">        long_text.resize (size);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">360</span><span class="doxyLineContent"><span class="doxyHighlight">        vsnprintf (long_text.data (), size + 1, format, args_copy);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">361</span><span class="doxyLineContent"><span class="doxyHighlight">        text = long_text;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">362</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">363</span><span class="doxyLineContent"><span class="doxyHighlight">    va_end (args_copy);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">364</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">365</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">366</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">367</span><span class="doxyLineContent"><span class="doxyHighlight">        write_without_colours (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a>, text);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">368</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">369</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">370</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (to_console)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">371</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">372</span><span class="doxyLineContent"><span class="doxyHighlight">        fwrite (text.data (), 1, text.size (), stdout);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">373</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">374</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">micro_os_plus::micro_test_plus::detail::reporter::output_file_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a66f620b093f92e0def6bf5297fb6d6ee">micro_os_plus::micro_test_plus::detail::reporter_human::abort_session</a>, <a href="#aa8802baefcb360f48451418c783ac413">abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#aa3cefeb72e745b2424b48ed4a31102e7">micro_os_plus::micro_test_plus::detail::reporter_human::begin_session</a>, <a href="#acaae91eea2deed1fe3f43b6453e7e656">begin_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a58c85919422801369d1d4d9a8efe77d0">micro_os_plus::micro_test_plus::detail::reporter_human::begin_suite</a>, <a href="#a2c05a737bfe80c955a998dc801e964b5">begin_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a04cef97a62731931038355a1b5f23556">micro_os_plus::micro_test_plus::detail::reporter_human::begin_test_case</a>, <a href="#a0302f9f5b977b05139d73df3bbc18d69">begin_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ace9c2dfffc49a97516b96dacaf87b943">micro_os_plus::micro_test_plus::detail::reporter_human::end_session</a>, <a href="#a7033819609bfad2db2ecc7a024e91b2c">end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a>, <a href="#a2d5ddae3195ab52a957927a1b455f7b8">end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a>, <a href="#ad15f7dbbf6a683441df40c502125adc3">end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#aca37d52611ed87d102dce89c3c6cc99d">micro_os_plus::micro_test_plus::detail::reporter_human::skip_suite</a>, <a href="#a319f35d4af8c72af8b14a89b421c1c74">skip_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af28ab5a9448645fb8976c0b139bf302b">micro_os_plus::micro_test_plus::detail::reporter_human::skip_test_case</a>, <a href="#a31ccd7af941d06241ce16df9274abc38">skip_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aeafdc8e05a6d80d9445f17ff354ee215">micro_os_plus::micro_test_plus::detail::reporter::write_info</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2c1e2c756b442d4832c161c8127faacf">micro_os_plus::micro_test_plus::detail::reporter::writes_passed_checks</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Private Member Functions

### commit\_buffer() {#af80ba6907c9f13b08f8cb8726d65c510}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter_tap::commit_buffer (void)</td>
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

<p>Writes the results buffered for the outer test case before a nested test case begins.</p>


<p>Keeps the TAP stream in execution order, with the checks of the outer test case before the nested test case, as node-tap does.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>The buffered <span class="doxyComputerOutput">ok</span>/<span class="doxyComputerOutput">not ok</span> lines of the outer test case are written to the output file and, with verbose verbosity, or with normal verbosity when they include a failure, to <span class="doxyComputerOutput">stdout</span>, preceded by an empty line when <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">add_empty_line_</a></span> is set. The buffer is then cleared, so that the nested test case starts with an empty buffer, and the remaining lines of the outer test case are written by its <span class="doxyComputerOutput"><a href="#ad15f7dbbf6a683441df40c502125adc3">end_test_case()</a></span>.</p>


<p>With normal verbosity, the passed checks committed here are not displayed, even if the outer test case fails later; the output file always contains them.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h/#l00368">368</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h">reporter-tap.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp/#l00999">999</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp">reporter-tap.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#af80ba6907c9f13b08f8cb8726d65c510">999</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#af80ba6907c9f13b08f8cb8726d65c510">reporter_tap::commit_buffer</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1000</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1001</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a37cba38a47d66a928a936ee081c6d88c">write_buffer_to_file</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1002</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1003</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">verbosity::verbose</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1004</span><span class="doxyLineContent"><span class="doxyHighlight">        || (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">verbosity::normal</a> &amp;&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a970a08a00e70f1574033085350656230">buffer_has_failures_</a>))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1005</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1006</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">add_empty_line_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1007</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1008</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#abaee31ffca8e65c9af34f7f67227c5b3">write_console</a> (</span><span class="doxyHighlightStringLiteral">"\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1009</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">add_empty_line_</a> = </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1010</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1011</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1012</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ae074822d712fc3db3c09f5f2d2237072">write_buffer_to_console</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1013</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1014</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1015</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a804b593aefa158d92a72da43de57d242">flush_streams</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1016</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1017</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5859ce31641330b243cfb5d1c6080859">clear_buffer</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1018</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">micro_os_plus::micro_test_plus::detail::reporter::add_empty_line_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a970a08a00e70f1574033085350656230">micro_os_plus::micro_test_plus::detail::reporter::buffer_has_failures_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5859ce31641330b243cfb5d1c6080859">micro_os_plus::micro_test_plus::detail::reporter::clear_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a804b593aefa158d92a72da43de57d242">micro_os_plus::micro_test_plus::detail::reporter::flush_streams</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">micro_os_plus::micro_test_plus::normal</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">micro_os_plus::micro_test_plus::verbose</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">micro_os_plus::micro_test_plus::detail::reporter::verbosity_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ae074822d712fc3db3c09f5f2d2237072">micro_os_plus::micro_test_plus::detail::reporter::write_buffer_to_console</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a37cba38a47d66a928a936ee081c6d88c">micro_os_plus::micro_test_plus::detail::reporter::write_buffer_to_file</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#abaee31ffca8e65c9af34f7f67227c5b3">micro_os_plus::micro_test_plus::detail::reporter::write_console</a>.</p>


<p>Referenced by <a href="#a9da35382cc3f903728f5f1bed2c4a745">operator=</a>.</p>

</div>
</div>

### output\_fail\_prefix() {#a3bd1c7d455abc782062d0e23a3ef1015}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter_tap::output_fail_prefix (const std::string &amp; message, const bool has_expression, const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> &amp; location, const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a> &amp; test_case)</td>
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
<td class="doxyParamItemName">test_case</td>
<td class="doxyParamItemDescription"><p>The test case that owns this check.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>This member function outputs the prefix for a failing check result, as a TAP <span class="doxyComputerOutput">"not ok &lt;n&gt;"</span> line, indented one level deeper than the test case, followed by the message, if provided, escaped (see <span class="doxyComputerOutput">tap_text()</span>), so that a <span class="doxyComputerOutput">#</span> does not start a directive and a line break does not end the test point line. It then opens the TAP 14 YAML diagnostics block (<span class="doxyComputerOutput">---</span>) and, when the failure has an expression, starts a <span class="doxyComputerOutput">condition:</span> field, so that the expression follows on the same line; the position where the expression begins is kept in <span class="doxyComputerOutput"><a href="#acc89e5828b613327923fa1b18172d9c1">condition_begin_</a></span>, so that <span class="doxyComputerOutput"><a href="#aaea110287f115fbaf80b0248f724c5b6">output_fail_suffix()</a></span> can quote it. Without an expression, <span class="doxyComputerOutput"><a href="#acc89e5828b613327923fa1b18172d9c1">condition_begin_</a></span> is set to <span class="doxyComputerOutput">std::string::npos</span>. No colours are used.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h/#l00336">336</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h">reporter-tap.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp/#l00797">797</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp">reporter-tap.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a3bd1c7d455abc782062d0e23a3ef1015">797</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a3bd1c7d455abc782062d0e23a3ef1015">reporter_tap::output_fail_prefix</a> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">798</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string&amp; message, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> has_expression,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">799</span><span class="doxyLineContent"><span class="doxyHighlight">      [[maybe_unused]] </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; location,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">800</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">801</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">802</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> level = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#af2b6792d06fa335f2b617e4d39bbba3c">nesting_depth</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">803</span><span class="doxyLineContent"><span class="doxyHighlight">    *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">indent</a> (level + 1) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"not ok "</span><span class="doxyHighlight"> &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#abc92cbb8ab8d04e7c75bf18aa7189d98">test_point_number_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">804</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">805</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (!message.empty ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">806</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">807</span><span class="doxyLineContent"><span class="doxyHighlight">        *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; </span><span class="doxyHighlightStringLiteral">" - "</span><span class="doxyHighlight"> &lt;&lt; tap_text (message, </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">808</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">809</span><span class="doxyLineContent"><span class="doxyHighlight">    *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">endl</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">810</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">811</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// https://testanything.org/tap-version-14-specification.html</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">812</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// 2-space indentation for YAML diagnostics.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">813</span><span class="doxyLineContent"><span class="doxyHighlight">    *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">indent</a> (level + 1) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"  ---"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">814</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#acc89e5828b613327923fa1b18172d9c1">condition_begin_</a> = std::string::npos;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">815</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (has_expression)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">816</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">817</span><span class="doxyLineContent"><span class="doxyHighlight">        *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">endl</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">818</span><span class="doxyLineContent"><span class="doxyHighlight">        *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">indent</a> (level + 1) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"  condition: "</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">819</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#acc89e5828b613327923fa1b18172d9c1">condition_begin_</a> = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>.size ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">820</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">821</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">micro_os_plus::micro_test_plus::detail::reporter::buffer_</a>, <a href="#acc89e5828b613327923fa1b18172d9c1">condition_begin_</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">micro_os_plus::micro_test_plus::detail::endl</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">micro_os_plus::micro_test_plus::detail::indent</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">micro_os_plus::micro_test_plus::detail::reporter::micro_test_plus::test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#af2b6792d06fa335f2b617e4d39bbba3c">micro_os_plus::micro_test_plus::test_case::nesting_depth</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#abc92cbb8ab8d04e7c75bf18aa7189d98">micro_os_plus::micro_test_plus::detail::runnable_base::test_point_number_</a>.</p>


<p>Referenced by <a href="#a9da35382cc3f903728f5f1bed2c4a745">operator=</a>.</p>

</div>
</div>

### output\_fail\_suffix() {#aaea110287f115fbaf80b0248f724c5b6}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter_tap::output_fail_suffix (const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> &amp; location, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a0726a1bc3b6f16245cb8a4b42fe0e70c">check_kind</a> kind, const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a> &amp; test_case)</td>
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
<td class="doxyParamItemName">kind</td>
<td class="doxyParamItemDescription"><p>The kind of the check; not used, since a failed requirement is reported like any other failed check.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">test_case</td>
<td class="doxyParamItemDescription"><p>The test case that owns this check.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Completes the TAP 14 YAML diagnostics block of a failing check, by ending the line opened by the prefix (the <span class="doxyComputerOutput">---</span> line, or the <span class="doxyComputerOutput">condition:</span> field), adding the <span class="doxyComputerOutput">at:</span> field with the file name and the line number, and closing the block (<span class="doxyComputerOutput">...</span>). As for a pass, the streams are flushed when the test case ends.</p>


<p>The location fields are named <span class="doxyComputerOutput">fileName:</span> and <span class="doxyComputerOutput">lineNumber:</span>, as written by node-tap; its reporters (for example the JUnit one, used by the CI systems to annotate the failures) read the file name only from <span class="doxyComputerOutput">fileName:</span> or <span class="doxyComputerOutput">file:</span>, not from <span class="doxyComputerOutput">filename:</span>. There is no <span class="doxyComputerOutput">columnNumber:</span>, since <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a></span> does not provide a column.</p>


<p>The expression, which follows <span class="doxyComputerOutput"><a href="#acc89e5828b613327923fa1b18172d9c1">condition_begin_</a></span> in the buffer, is first replaced by its YAML double-quoted form (see <span class="doxyComputerOutput">yaml_double_quoted()</span>), so that the operands that start a YAML flow collection or a quoted scalar (for example <span class="doxyComputerOutput">{1, 2}</span> or <span class="doxyComputerOutput">'a'</span>), or contain <span class="doxyComputerOutput">: </span> or <span class="doxyComputerOutput"> #</span>, do not make the diagnostics block invalid.</p>


<p>A failed requirement is reported like any other failed check, as node-tap does for a failed assertion followed by a throw; no marker is added, since any text after <span class="doxyComputerOutput">---</span> or after the condition would make the block, or the value, invalid. That the test case stopped is shown by the plan, which follows this test point; without exceptions, the abort of the test execution is reported by the <span class="doxyComputerOutput">Bail out!</span> line written by <span class="doxyComputerOutput"><a href="#aa8802baefcb360f48451418c783ac413">abort_session()</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h/#l00351">351</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h">reporter-tap.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp/#l00853">853</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp">reporter-tap.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aaea110287f115fbaf80b0248f724c5b6">853</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#aaea110287f115fbaf80b0248f724c5b6">reporter_tap::output_fail_suffix</a> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">854</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; location,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">855</span><span class="doxyLineContent"><span class="doxyHighlight">      [[maybe_unused]] <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a0726a1bc3b6f16245cb8a4b42fe0e70c">check_kind</a> kind, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">856</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">857</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#acc89e5828b613327923fa1b18172d9c1">condition_begin_</a> != std::string::npos)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">858</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">859</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string condition = yaml_double_quoted (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">860</span><span class="doxyLineContent"><span class="doxyHighlight">            std::string_view{ <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a> }.substr (<a href="#acc89e5828b613327923fa1b18172d9c1">condition_begin_</a>));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">861</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>.replace (<a href="#acc89e5828b613327923fa1b18172d9c1">condition_begin_</a>, std::string::npos, condition);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">862</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#acc89e5828b613327923fa1b18172d9c1">condition_begin_</a> = std::string::npos;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">863</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">864</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">865</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> level = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#af2b6792d06fa335f2b617e4d39bbba3c">nesting_depth</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">866</span><span class="doxyLineContent"><span class="doxyHighlight">    *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">endl</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">867</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">868</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// https://testanything.org/tap-version-14-specification.html</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">869</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// 2-space indentation for YAML diagnostics.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">870</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">871</span><span class="doxyLineContent"><span class="doxyHighlight">    *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">indent</a> (level + 1) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"  at:"</span><span class="doxyHighlight"> &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">endl</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">872</span><span class="doxyLineContent"><span class="doxyHighlight">    *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">indent</a> (level + 1) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"    fileName: "</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">873</span><span class="doxyLineContent"><span class="doxyHighlight">          &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-utility-functions/#ga791f22f0c85b6436c9016821907b0653">utility::extract_file_name</a> (location.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#a3df499675aacb7ab9192cfb9a5371874">file_name</a> ()) &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">endl</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">874</span><span class="doxyLineContent"><span class="doxyHighlight">    *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">indent</a> (level + 1) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"    lineNumber: "</span><span class="doxyHighlight"> &lt;&lt; location.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#aab9d006004611ac0526852a09f675c66">line</a> ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">875</span><span class="doxyLineContent"><span class="doxyHighlight">          &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">endl</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">876</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">877</span><span class="doxyLineContent"><span class="doxyHighlight">    *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">indent</a> (level + 1) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"  ..."</span><span class="doxyHighlight"> &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">endl</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">878</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">micro_os_plus::micro_test_plus::detail::reporter::buffer_</a>, <a href="#acc89e5828b613327923fa1b18172d9c1">condition_begin_</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">micro_os_plus::micro_test_plus::detail::endl</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-utility-functions/#ga791f22f0c85b6436c9016821907b0653">micro_os_plus::micro_test_plus::utility::extract_file_name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#a3df499675aacb7ab9192cfb9a5371874">micro_os_plus::micro_test_plus::reflection::source_location::file_name</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">micro_os_plus::micro_test_plus::detail::indent</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#aab9d006004611ac0526852a09f675c66">micro_os_plus::micro_test_plus::reflection::source_location::line</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">micro_os_plus::micro_test_plus::detail::reporter::micro_test_plus::test_case</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#af2b6792d06fa335f2b617e4d39bbba3c">micro_os_plus::micro_test_plus::test_case::nesting_depth</a>.</p>


<p>Referenced by <a href="#a9da35382cc3f903728f5f1bed2c4a745">operator=</a>.</p>

</div>
</div>

### output\_pass\_prefix() {#ac6c05f92e47ad71f72b44f9beb0b98f1}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter_tap::output_pass_prefix (const std::string &amp; message, const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a> &amp; test_case)</td>
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
<td class="doxyParamItemName">test_case</td>
<td class="doxyParamItemDescription"><p>The test case that owns this check.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>This member function outputs the prefix for a passing check result, as a TAP <span class="doxyComputerOutput">"ok &lt;n&gt; - "</span> line, where <span class="doxyComputerOutput">&lt;n&gt;</span> is the test point number of the check, which counts the checks and the nested test cases of the test case, indented one level deeper than the test case, followed by the message, if provided. No colours are used.</p>


<p>The position where the description begins is kept in <span class="doxyComputerOutput"><a href="#ac4dcc7a6454d79e473033ddec5882ee8">description_begin_</a></span>, since, when there is no message, the caller appends the expression after this member function returns.</p>


<p>The prefix/suffix member functions help shorten the code generated by the template member functions.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h/#l00311">311</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h">reporter-tap.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp/#l00745">745</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp">reporter-tap.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ac6c05f92e47ad71f72b44f9beb0b98f1">745</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ac6c05f92e47ad71f72b44f9beb0b98f1">reporter_tap::output_pass_prefix</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string&amp; message,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">746</span><span class="doxyLineContent"><span class="doxyHighlight">                                    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">747</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">748</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> level = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#af2b6792d06fa335f2b617e4d39bbba3c">nesting_depth</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">749</span><span class="doxyLineContent"><span class="doxyHighlight">    *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">indent</a> (level + 1) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"ok "</span><span class="doxyHighlight"> &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#abc92cbb8ab8d04e7c75bf18aa7189d98">test_point_number_</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">750</span><span class="doxyLineContent"><span class="doxyHighlight">          &lt;&lt; </span><span class="doxyHighlightStringLiteral">" - "</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">751</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#ac4dcc7a6454d79e473033ddec5882ee8">description_begin_</a> = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>.size ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">752</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (!message.empty ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">753</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">754</span><span class="doxyLineContent"><span class="doxyHighlight">        *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; message;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">755</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">756</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">micro_os_plus::micro_test_plus::detail::reporter::buffer_</a>, <a href="#ac4dcc7a6454d79e473033ddec5882ee8">description_begin_</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">micro_os_plus::micro_test_plus::detail::indent</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">micro_os_plus::micro_test_plus::detail::reporter::micro_test_plus::test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#af2b6792d06fa335f2b617e4d39bbba3c">micro_os_plus::micro_test_plus::test_case::nesting_depth</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#abc92cbb8ab8d04e7c75bf18aa7189d98">micro_os_plus::micro_test_plus::detail::runnable_base::test_point_number_</a>.</p>


<p>Referenced by <a href="#a9da35382cc3f903728f5f1bed2c4a745">operator=</a>.</p>

</div>
</div>

### output\_pass\_suffix() {#a37c4235afdd9b704fd65d25d130bee86}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter_tap::output_pass_suffix (const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a> &amp; test_case)</td>
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

<p>Outputs the suffix for a passing condition.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">test_case</td>
<td class="doxyParamItemDescription"><p>The test case that owns this check.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>The description, either the message or the expression, which follows <span class="doxyComputerOutput"><a href="#ac4dcc7a6454d79e473033ddec5882ee8">description_begin_</a></span> in the buffer, is replaced by its escaped form (see <span class="doxyComputerOutput">tap_text()</span>), so that a <span class="doxyComputerOutput">#</span> does not start a directive and a line break does not end the test point line. The pass output is then completed by appending <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">endl</a></span>, which adds a line ending to the buffer. The streams are not flushed, since nothing was written to them; the buffer is written, and the streams flushed, when the test case ends.</p>


<p>The prefix/suffix member functions help shorten the code generated by the template member functions.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h/#l00322">322</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h">reporter-tap.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp/#l00773">773</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp">reporter-tap.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a37c4235afdd9b704fd65d25d130bee86">773</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a37c4235afdd9b704fd65d25d130bee86">reporter_tap::output_pass_suffix</a> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">774</span><span class="doxyLineContent"><span class="doxyHighlight">      [[maybe_unused]] </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">775</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">776</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string description = tap_text (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">777</span><span class="doxyLineContent"><span class="doxyHighlight">        std::string_view{ <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a> }.substr (<a href="#ac4dcc7a6454d79e473033ddec5882ee8">description_begin_</a>), </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">778</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>.replace (<a href="#ac4dcc7a6454d79e473033ddec5882ee8">description_begin_</a>, std::string::npos, description);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">779</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">780</span><span class="doxyLineContent"><span class="doxyHighlight">    *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">endl</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">781</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">micro_os_plus::micro_test_plus::detail::reporter::buffer_</a>, <a href="#ac4dcc7a6454d79e473033ddec5882ee8">description_begin_</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">micro_os_plus::micro_test_plus::detail::endl</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">micro_os_plus::micro_test_plus::detail::reporter::micro_test_plus::test_case</a>.</p>


<p>Referenced by <a href="#a9da35382cc3f903728f5f1bed2c4a745">operator=</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Protected Member Attributes

### add\_empty\_line\_ {#a38252f2ef24feabcb7f55e7bdac30bd2}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::detail::reporter::add_empty_line_ { true }</td>
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

<p>Whether to write an empty line before the next console output.</p>


<p>Set and cleared by the concrete reporters, to separate the groups of console lines, such as the suites and the failed test cases; the output file is not affected.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01084">1084</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">1084</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">add_empty_line_</a>{ </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight"> };</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a66f620b093f92e0def6bf5297fb6d6ee">micro_os_plus::micro_test_plus::detail::reporter_human::abort_session</a>, <a href="#aa8802baefcb360f48451418c783ac413">abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#aa3cefeb72e745b2424b48ed4a31102e7">micro_os_plus::micro_test_plus::detail::reporter_human::begin_session</a>, <a href="#acaae91eea2deed1fe3f43b6453e7e656">begin_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a58c85919422801369d1d4d9a8efe77d0">micro_os_plus::micro_test_plus::detail::reporter_human::begin_suite</a>, <a href="#a2c05a737bfe80c955a998dc801e964b5">begin_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a04cef97a62731931038355a1b5f23556">micro_os_plus::micro_test_plus::detail::reporter_human::begin_test_case</a>, <a href="#a0302f9f5b977b05139d73df3bbc18d69">begin_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#adf27b1d3d7cb168f295e4bf198bb0dbf">micro_os_plus::micro_test_plus::detail::reporter_human::commit_buffer</a>, <a href="#af80ba6907c9f13b08f8cb8726d65c510">commit_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af17a48a165abd908031ddc3a0821f81e">micro_os_plus::micro_test_plus::detail::reporter_human::display_open_names</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ace9c2dfffc49a97516b96dacaf87b943">micro_os_plus::micro_test_plus::detail::reporter_human::end_session</a>, <a href="#a7033819609bfad2db2ecc7a024e91b2c">end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a>, <a href="#a2d5ddae3195ab52a957927a1b455f7b8">end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a>, <a href="#ad15f7dbbf6a683441df40c502125adc3">end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#aca37d52611ed87d102dce89c3c6cc99d">micro_os_plus::micro_test_plus::detail::reporter_human::skip_suite</a>, <a href="#a319f35d4af8c72af8b14a89b421c1c74">skip_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af28ab5a9448645fb8976c0b139bf302b">micro_os_plus::micro_test_plus::detail::reporter_human::skip_test_case</a> and <a href="#a31ccd7af941d06241ce16df9274abc38">skip_test_case</a>.</p>

</div>
</div>

### arguments\_ {#a3e47f2c530c5019bde9fe56867bc581f}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::span&lt;char* const&gt; micro_os_plus::micro_test_plus::detail::reporter::arguments_ {}</td>
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

<p>The command-line arguments passed to the test runner.</p>


<p>A view of the <span class="doxyComputerOutput">argv[]</span> array of <span class="doxyComputerOutput">main()</span>, copied from the session options by the constructor, and listed by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aeafdc8e05a6d80d9445f17ff354ee215">write_info()</a></span>, which is called only by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a00e5e3b4f1ddfeeff6deb614d120caef">begin_session()</a></span>, within <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#acfabd0e10d233ad305b6f4fc125a97f2">runner::initialise()</a></span>; it is not used afterwards.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01127">1127</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a3e47f2c530c5019bde9fe56867bc581f">1127</a></span><span class="doxyLineContent"><span class="doxyHighlight">      std::span&lt;char* const&gt; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a3e47f2c530c5019bde9fe56867bc581f">arguments_</a>{};</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">micro_os_plus::micro_test_plus::detail::reporter::reporter</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aeafdc8e05a6d80d9445f17ff354ee215">micro_os_plus::micro_test_plus::detail::reporter::write_info</a>.</p>

</div>
</div>

### buffer\_ {#a0972f104175c075295a8aa385e90aad4}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::string micro_os_plus::micro_test_plus::detail::reporter::buffer_ {}</td>
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


<p>Accumulates all reporter output until it is written to the console or the output file via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ae074822d712fc3db3c09f5f2d2237072">write_buffer_to_console()</a></span> or <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a37cba38a47d66a928a936ee081c6d88c">write_buffer_to_file()</a></span>.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01049">1049</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">1049</a></span><span class="doxyLineContent"><span class="doxyHighlight">      std::string <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>{};</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">micro_os_plus::micro_test_plus::detail::reporter::reporter</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a66f620b093f92e0def6bf5297fb6d6ee">micro_os_plus::micro_test_plus::detail::reporter_human::abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5859ce31641330b243cfb5d1c6080859">micro_os_plus::micro_test_plus::detail::reporter::clear_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5cf73aaf67484b50c25ef42363d49337">micro_os_plus::micro_test_plus::detail::reporter::commit_outer_results</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a287bad0e5eccee7df4a2c8517959bd0e">micro_os_plus::micro_test_plus::detail::reporter::end_line</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#acbdac50fb2a1302e4a97c8160e7fd7cb">micro_os_plus::micro_test_plus::detail::reporter::operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5d29d78c80c20d3fe96ac9d0f4a969b3">micro_os_plus::micro_test_plus::detail::reporter::operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ad84ba0969733f2120622d26951259f95">micro_os_plus::micro_test_plus::detail::reporter::operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aedfa17028026f6eaa871214da441e90c">micro_os_plus::micro_test_plus::detail::reporter::operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac894cb9cbf11f2f57acb388310eede4c">micro_os_plus::micro_test_plus::detail::reporter::operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a54158cb2ca77354223506355247cab9a">micro_os_plus::micro_test_plus::detail::reporter::operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a3ff526c7ae5db0669d7db2adebf7cb2d">micro_os_plus::micro_test_plus::detail::reporter::operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0cdaf2313f78a256b80f7bb7b279e2e6">micro_os_plus::micro_test_plus::detail::reporter::operator&lt;&lt;</a>, <a href="#a3bd1c7d455abc782062d0e23a3ef1015">output_fail_prefix</a>, <a href="#aaea110287f115fbaf80b0248f724c5b6">output_fail_suffix</a>, <a href="#ac6c05f92e47ad71f72b44f9beb0b98f1">output_pass_prefix</a>, <a href="#a37c4235afdd9b704fd65d25d130bee86">output_pass_suffix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ae074822d712fc3db3c09f5f2d2237072">micro_os_plus::micro_test_plus::detail::reporter::write_buffer_to_console</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a37cba38a47d66a928a936ee081c6d88c">micro_os_plus::micro_test_plus::detail::reporter::write_buffer_to_file</a>.</p>

</div>
</div>

### buffer\_has\_failures\_ {#a970a08a00e70f1574033085350656230}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::detail::reporter::buffer_has_failures_ { false }</td>
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

<p>Whether the output buffer contains a failed check.</p>


<p>Set by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a406cf77b7adcd5fe9417ce7bce4f3afb">fail()</a></span> and reset by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5859ce31641330b243cfb5d1c6080859">clear_buffer()</a></span>. When a nested test case begins, the concrete reporters use it to decide whether the results already buffered for the outer test case are displayed with normal verbosity.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01060">1060</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a970a08a00e70f1574033085350656230">1060</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a970a08a00e70f1574033085350656230">buffer_has_failures_</a>{ </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight"> };</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5859ce31641330b243cfb5d1c6080859">micro_os_plus::micro_test_plus::detail::reporter::clear_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#adf27b1d3d7cb168f295e4bf198bb0dbf">micro_os_plus::micro_test_plus::detail::reporter_human::commit_buffer</a>, <a href="#af80ba6907c9f13b08f8cb8726d65c510">commit_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a406cf77b7adcd5fe9417ce7bce4f3afb">micro_os_plus::micro_test_plus::detail::reporter::fail</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#afd98d9a322823d67448d4ba301846392">micro_os_plus::micro_test_plus::detail::reporter_human::fail_suite</a> and <a href="#a314df80e98fe6fa5de008d6708a14925">fail_suite</a>.</p>

</div>
</div>

### colours\_ {#a69616e251ebb3d22e481ada0831bec3c}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">colours micro_os_plus::micro_test_plus::detail::reporter::colours_ {}</td>
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


<p>Empty strings by default; the human reporter assigns <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ad59e204218aa41581652a072be0e8a8a">detail::colours_red_green</a></span> when colours are enabled by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#a48ed4dd71eff02911c2d6943ba616850">runner_options::colour</a></span>, explicitly or because the console is a terminal.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01039">1039</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a69616e251ebb3d22e481ada0831bec3c">1039</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a69616e251ebb3d22e481ada0831bec3c">colours_</a>{};</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a82221fa355584dbaa75c7e66fbefa6b8">micro_os_plus::micro_test_plus::detail::reporter_human::reporter_human</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a66f620b093f92e0def6bf5297fb6d6ee">micro_os_plus::micro_test_plus::detail::reporter_human::abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ace9c2dfffc49a97516b96dacaf87b943">micro_os_plus::micro_test_plus::detail::reporter_human::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#afd98d9a322823d67448d4ba301846392">micro_os_plus::micro_test_plus::detail::reporter_human::fail_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a032be7e38aad40c8bc44b2376ad90e29">micro_os_plus::micro_test_plus::detail::reporter_human::output_fail_prefix</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a043919044274838f8030d53630e3b1f5">micro_os_plus::micro_test_plus::detail::reporter_human::output_pass_prefix</a>.</p>

</div>
</div>

### expression\_ {#ac928cbe8852ca0c0273482b905c6301b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter micro_os_plus::micro_test_plus::detail::reporter::expression_ { <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a69616e251ebb3d22e481ada0831bec3c">colours_</a> }</td>
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


<p>Used by the checks (<span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-expectations/#gaf4f5f9632b5a290c1894984661a41a86">test_case::expect()</a></span>, <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-requirements/#gace68a1bd4dd258082f4b1fc01fcd008a">test_case::require()</a></span>, and <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">detail::check_result</a></span>), which are friends, to pre-format expressions at construction time; <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ad9e6ccebc1904f723409ddb0caaddb3e">pass()</a></span> and <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a406cf77b7adcd5fe9417ce7bce4f3afb">fail()</a></span> then append the formatted text to <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a></span>. The applications format their own types by defining <span class="doxyComputerOutput">operator&lt;&lt;</span> for the public <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter">expression_formatter</a></span> alias.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01073">1073</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac928cbe8852ca0c0273482b905c6301b">1073</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter">expression_formatter</a> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac928cbe8852ca0c0273482b905c6301b">expression_</a>{ <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a69616e251ebb3d22e481ada0831bec3c">colours_</a> };</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-expectations/#gaf4f5f9632b5a290c1894984661a41a86">micro_os_plus::micro_test_plus::test_case::expect</a> and <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-requirements/#gace68a1bd4dd258082f4b1fc01fcd008a">micro_os_plus::micro_test_plus::test_case::require</a>.</p>

</div>
</div>

### has\_output\_file\_error\_ {#a0d73674812cca717a754137b4b26ed89}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::detail::reporter::has_output_file_error_ { false }</td>
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

<p>Whether the output file could not be opened.</p>


<p>Set by the constructor, and returned by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a083ecdfa952d7f8c372a61fbea309357">has_output_file_error()</a></span>.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01116">1116</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0d73674812cca717a754137b4b26ed89">1116</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0d73674812cca717a754137b4b26ed89">has_output_file_error_</a>{ </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight"> };</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">micro_os_plus::micro_test_plus::detail::reporter::reporter</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a083ecdfa952d7f8c372a61fbea309357">micro_os_plus::micro_test_plus::detail::reporter::has_output_file_error</a>.</p>

</div>
</div>

### output\_file\_ {#a270178ed5fbe0d3f4d72766c2984582a}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">FILE* micro_os_plus::micro_test_plus::detail::reporter::output_file_ { nullptr }</td>
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

<p>Optional output file, receiving a copy of the test report.</p>


<p>When non-null, the report is written to this file in addition to the console, without colour sequences. With the TAP reporter, the file receives the full report, regardless of the verbosity; with the human reporter, most of it only with the normal and verbose levels (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a467d1332df523b9acaa3ff82b0ebb714">verbosity</a></span>). The file is opened by the constructor and closed by the destructor.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01108">1108</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">1108</a></span><span class="doxyLineContent"><span class="doxyHighlight">      FILE* <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a>{ </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight"> };</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">micro_os_plus::micro_test_plus::detail::reporter::reporter</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5b6052e6c28235b76d855b2b7bc176dd">micro_os_plus::micro_test_plus::detail::reporter::~reporter</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a804b593aefa158d92a72da43de57d242">micro_os_plus::micro_test_plus::detail::reporter::flush_streams</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a37cba38a47d66a928a936ee081c6d88c">micro_os_plus::micro_test_plus::detail::reporter::write_buffer_to_file</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a90a541c6a9b1ddd3da9440358bfc704e">micro_os_plus::micro_test_plus::detail::reporter::write_file</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">micro_os_plus::micro_test_plus::detail::reporter::write_line</a> and <a href="#a841b146b309b93422ae707094ba044f6">writes_passed_checks</a>.</p>

</div>
</div>

### output\_file\_path\_ {#ac3878d2e85ed2cae4c71c793d7a8f52e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::string micro_os_plus::micro_test_plus::detail::reporter::output_file_path_ {}</td>
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

<p>Path of the optional output file.</p>


<p>Copied by the constructor from the session options, so that the caller's string need not outlive <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#acfabd0e10d233ad305b6f4fc125a97f2">runner::initialise()</a></span>. Used to name the file in the confirmation message displayed when the file is closed (not displayed with the <span class="doxyComputerOutput">silent</span> verbosity).</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01095">1095</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac3878d2e85ed2cae4c71c793d7a8f52e">1095</a></span><span class="doxyLineContent"><span class="doxyHighlight">      std::string <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac3878d2e85ed2cae4c71c793d7a8f52e">output_file_path_</a>{};</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">micro_os_plus::micro_test_plus::detail::reporter::reporter</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5b6052e6c28235b76d855b2b7bc176dd">micro_os_plus::micro_test_plus::detail::reporter::~reporter</a>.</p>

</div>
</div>

### verbosity\_ {#a2560a0f1cf935e420a2e584ccddf1a1e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const micro_test_plus::verbosity micro_os_plus::micro_test_plus::detail::reporter::verbosity_</td>
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


<p>A copy of the level kept by the runner, set by the constructor from the same session options and not changed afterwards. The public accessor is <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a1dd0221dca8e7382f0b625ff6316ed92">runner::verbosity_level()</a></span>.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01028">1028</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">1028</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914b">micro_test_plus::verbosity</a> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a>;</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">micro_os_plus::micro_test_plus::detail::reporter::reporter</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5b6052e6c28235b76d855b2b7bc176dd">micro_os_plus::micro_test_plus::detail::reporter::~reporter</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a66f620b093f92e0def6bf5297fb6d6ee">micro_os_plus::micro_test_plus::detail::reporter_human::abort_session</a>, <a href="#aa8802baefcb360f48451418c783ac413">abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#aa3cefeb72e745b2424b48ed4a31102e7">micro_os_plus::micro_test_plus::detail::reporter_human::begin_session</a>, <a href="#acaae91eea2deed1fe3f43b6453e7e656">begin_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a58c85919422801369d1d4d9a8efe77d0">micro_os_plus::micro_test_plus::detail::reporter_human::begin_suite</a>, <a href="#a2c05a737bfe80c955a998dc801e964b5">begin_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a04cef97a62731931038355a1b5f23556">micro_os_plus::micro_test_plus::detail::reporter_human::begin_test_case</a>, <a href="#a0302f9f5b977b05139d73df3bbc18d69">begin_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#adf27b1d3d7cb168f295e4bf198bb0dbf">micro_os_plus::micro_test_plus::detail::reporter_human::commit_buffer</a>, <a href="#af80ba6907c9f13b08f8cb8726d65c510">commit_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ace9c2dfffc49a97516b96dacaf87b943">micro_os_plus::micro_test_plus::detail::reporter_human::end_session</a>, <a href="#a7033819609bfad2db2ecc7a024e91b2c">end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a>, <a href="#a2d5ddae3195ab52a957927a1b455f7b8">end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a>, <a href="#ad15f7dbbf6a683441df40c502125adc3">end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#aca37d52611ed87d102dce89c3c6cc99d">micro_os_plus::micro_test_plus::detail::reporter_human::skip_suite</a>, <a href="#a319f35d4af8c72af8b14a89b421c1c74">skip_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af28ab5a9448645fb8976c0b139bf302b">micro_os_plus::micro_test_plus::detail::reporter_human::skip_test_case</a>, <a href="#a31ccd7af941d06241ce16df9274abc38">skip_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a467d1332df523b9acaa3ff82b0ebb714">micro_os_plus::micro_test_plus::detail::reporter::verbosity</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aeafdc8e05a6d80d9445f17ff354ee215">micro_os_plus::micro_test_plus::detail::reporter::write_info</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a10056a6c708853ab83a99caec53b8a48">micro_os_plus::micro_test_plus::detail::reporter_human::writes_passed_checks</a> and <a href="#a841b146b309b93422ae707094ba044f6">writes_passed_checks</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Private Member Attributes

### condition\_begin\_ {#acc89e5828b613327923fa1b18172d9c1}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">size_t micro_os_plus::micro_test_plus::detail::reporter_tap::condition_begin_ = std::string::npos</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The position in the buffer where the expression of a failed check begins.</p>


<p>Set by <span class="doxyComputerOutput"><a href="#a3bd1c7d455abc782062d0e23a3ef1015">output_fail_prefix()</a></span>, after the <span class="doxyComputerOutput">condition:</span> key, and used by <span class="doxyComputerOutput"><a href="#aaea110287f115fbaf80b0248f724c5b6">output_fail_suffix()</a></span> to write the expression appended between the two calls as a YAML double-quoted scalar. It is <span class="doxyComputerOutput">std::string::npos</span> when the failure has no expression.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h/#l00391">391</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h">reporter-tap.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#acc89e5828b613327923fa1b18172d9c1">391</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="#acc89e5828b613327923fa1b18172d9c1">condition_begin_</a> = std::string::npos;</span></span></div>

</div>


<p>Referenced by <a href="#a3bd1c7d455abc782062d0e23a3ef1015">output_fail_prefix</a> and <a href="#aaea110287f115fbaf80b0248f724c5b6">output_fail_suffix</a>.</p>

</div>
</div>

### description\_begin\_ {#ac4dcc7a6454d79e473033ddec5882ee8}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">size_t micro_os_plus::micro_test_plus::detail::reporter_tap::description_begin_ = 0</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The position in the buffer where the description of a passed check begins.</p>


<p>Set by <span class="doxyComputerOutput"><a href="#ac6c05f92e47ad71f72b44f9beb0b98f1">output_pass_prefix()</a></span> and used by <span class="doxyComputerOutput"><a href="#a37c4235afdd9b704fd65d25d130bee86">output_pass_suffix()</a></span> to escape the description, which is the message, or the expression appended between the two calls when there is no message.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h/#l00379">379</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h">reporter-tap.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ac4dcc7a6454d79e473033ddec5882ee8">379</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="#ac4dcc7a6454d79e473033ddec5882ee8">description_begin_</a> = 0;</span></span></div>

</div>


<p>Referenced by <a href="#ac6c05f92e47ad71f72b44f9beb0b98f1">output_pass_prefix</a> and <a href="#a37c4235afdd9b704fd65d25d130bee86">output_pass_suffix</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Protected Static Functions

### format\_elapsed\_time() {#ac6dca3d3fa34870f3960fe5e226e45d8}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter::format_elapsed_time (const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch">stopwatch</a> &amp; stopwatch, char(&amp;) message=[elapsed_time_size_])</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel protected">protected</span>
<span class="doxyMemberLabel static">static</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Formats the elapsed time of a suite or of the session.</p>


<p>The text is appended to the summary lines by the concrete reporters, in the form <span class="doxyComputerOutput">", time: 1.234 ms"</span>; it is empty when the stopwatch has no elapsed time, so that the summary lines remain identical on the platforms without a clock.</p>


<p>The array has a fixed size, known at compile time, so that the compiler can verify that the text is never truncated.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">stopwatch</td>
<td class="doxyParamItemDescription"><p>The stopwatch of the suite or of the runner.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">message</td>
<td class="doxyParamItemDescription"><p>The character array that receives the null-terminated text.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>The elapsed time, in microseconds, is displayed in milliseconds, with three decimals. When it is zero, either because the stopwatch has no readings or because the interval was shorter than a microsecond, the text is empty.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00816">816</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00657">657</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac6dca3d3fa34870f3960fe5e226e45d8">657</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac6dca3d3fa34870f3960fe5e226e45d8">reporter::format_elapsed_time</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch">stopwatch</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch">stopwatch</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">658</span><span class="doxyLineContent"><span class="doxyHighlight">                                 </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> (&amp;message)[<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2bf85bc5dd65df1816b52b7fd7c6c627">elapsed_time_size_</a>])</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">659</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">660</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> elapsed = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch">stopwatch</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch/#a3719382123c6741054a89e4f76b55d90">elapsed</a> ().count ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">661</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (elapsed &gt; 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">662</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">663</span><span class="doxyLineContent"><span class="doxyHighlight">        snprintf (message, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (message),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">664</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">", time: %"</span><span class="doxyHighlight"> PRIu32 </span><span class="doxyHighlightStringLiteral">".%03"</span><span class="doxyHighlight"> PRIu32 </span><span class="doxyHighlightStringLiteral">" ms"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">665</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">uint32_t</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (elapsed / 1000),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">666</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">uint32_t</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (elapsed % 1000));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">667</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">668</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">669</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">670</span><span class="doxyLineContent"><span class="doxyHighlight">        message[0] = </span><span class="doxyHighlightCharLiteral">'\0'</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">671</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">672</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch/#a3719382123c6741054a89e4f76b55d90">micro_os_plus::micro_test_plus::detail::stopwatch::elapsed</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2bf85bc5dd65df1816b52b7fd7c6c627">micro_os_plus::micro_test_plus::detail::reporter::elapsed_time_size_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ace9c2dfffc49a97516b96dacaf87b943">micro_os_plus::micro_test_plus::detail::reporter_human::end_session</a>, <a href="#a7033819609bfad2db2ecc7a024e91b2c">end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a> and <a href="#a2d5ddae3195ab52a957927a1b455f7b8">end_suite</a>.</p>

</div>
</div>

### format\_session\_totals() {#a6bf3aac88a5e66e2f93eb32c54dbdd14}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter::format_session_totals (const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">runner</a> &amp; runner, char(&amp;) message=[totals_size_])</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel protected">protected</span>
<span class="doxyMemberLabel static">static</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Formats the totals of the test session.</p>


<p>The text is the part of the session summary line common to the concrete reporters, in the form <span class="doxyComputerOutput">"7 checks passed, 1 failed, in 3 test cases, 2 test suites"</span>; the numbers of test cases and of suites skipped by the filter follow the respective counts, as <span class="doxyComputerOutput">", 1 skipped"</span>, only when not zero. The label (<span class="doxyComputerOutput">Total:</span> or <span class="doxyComputerOutput">total:</span>), the markers, and the elapsed time are added by the callers.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">runner</td>
<td class="doxyParamItemDescription"><p>The runner of the test session.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">message</td>
<td class="doxyParamItemDescription"><p>The character array that receives the null-terminated text.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>The suites are counted by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#ac29e4b993bb3fe795eb8900231cbf5c4">runner::total_suites_count()</a></span>, which includes the suites skipped by the filter, counted separately by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a2c2a6d7cb45b714026d124d0ca432360">runner::skipped_suites_count()</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00859">859</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00743">743</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a6bf3aac88a5e66e2f93eb32c54dbdd14">743</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a6bf3aac88a5e66e2f93eb32c54dbdd14">reporter::format_session_totals</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">runner</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">runner</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">744</span><span class="doxyLineContent"><span class="doxyHighlight">                                   </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> (&amp;message)[<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aaa55b147a670878984952ca1112cecd8">totals_size_</a>])</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">745</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">746</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// The fixed text, four counts, two fragments, and the terminator.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">747</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">static_assert</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aaa55b147a670878984952ca1112cecd8">totals_size_</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">748</span><span class="doxyLineContent"><span class="doxyHighlight">                       &gt;= 54 + 4 * (std::numeric_limits&lt;size_t&gt;::digits10 + 1)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">749</span><span class="doxyLineContent"><span class="doxyHighlight">                              + 2 * (fragment_size - 1),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">750</span><span class="doxyLineContent"><span class="doxyHighlight">                   </span><span class="doxyHighlightStringLiteral">"totals_size_ too small for the session totals"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">751</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">752</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters">counters</a>&amp; totals = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">runner</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a2c8a999cc273356ea10ed34fb12dcf5a">totals</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">753</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> suites_count = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">runner</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#ac29e4b993bb3fe795eb8900231cbf5c4">total_suites_count</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">754</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">755</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> message_skipped_test_cases[fragment_size];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">756</span><span class="doxyLineContent"><span class="doxyHighlight">    format_skipped (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a2e5ea7bbb9bd5a05213dee741f08599d">skipped_test_cases</a> (), message_skipped_test_cases);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">757</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">758</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> message_skipped_suites[fragment_size];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">759</span><span class="doxyLineContent"><span class="doxyHighlight">    format_skipped (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">runner</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a2c2a6d7cb45b714026d124d0ca432360">skipped_suites_count</a> (), message_skipped_suites);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">760</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">761</span><span class="doxyLineContent"><span class="doxyHighlight">    snprintf (message, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (message),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">762</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightStringLiteral">"%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">763</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightStringLiteral">" check%s passed, %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">764</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightStringLiteral">" failed, in %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">765</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightStringLiteral">" test case%s%s, %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a> </span><span class="doxyHighlightStringLiteral">" "</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">766</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightStringLiteral">"test suite%s%s"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">767</span><span class="doxyLineContent"><span class="doxyHighlight">              totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> (), plural (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> ()),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">768</span><span class="doxyLineContent"><span class="doxyHighlight">              totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#ab1684c7c6101a4d534356d9d16807bee">failed_checks</a> (), totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">executed_test_cases</a> (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">769</span><span class="doxyLineContent"><span class="doxyHighlight">              plural (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">executed_test_cases</a> ()),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">770</span><span class="doxyLineContent"><span class="doxyHighlight">              message_skipped_test_cases, suites_count, plural (suites_count),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">771</span><span class="doxyLineContent"><span class="doxyHighlight">              message_skipped_suites);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">772</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">micro_os_plus::micro_test_plus::counters::executed_test_cases</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#ab1684c7c6101a4d534356d9d16807bee">micro_os_plus::micro_test_plus::counters::failed_checks</a>, <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">micro_os_plus::micro_test_plus::detail::reporter::micro_test_plus::runner</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">micro_os_plus::micro_test_plus::counters::passed_checks</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a2c2a6d7cb45b714026d124d0ca432360">micro_os_plus::micro_test_plus::runner::skipped_suites_count</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a2e5ea7bbb9bd5a05213dee741f08599d">micro_os_plus::micro_test_plus::counters::skipped_test_cases</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#ac29e4b993bb3fe795eb8900231cbf5c4">micro_os_plus::micro_test_plus::runner::total_suites_count</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a2c8a999cc273356ea10ed34fb12dcf5a">micro_os_plus::micro_test_plus::runner::totals</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aaa55b147a670878984952ca1112cecd8">micro_os_plus::micro_test_plus::detail::reporter::totals_size_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ace9c2dfffc49a97516b96dacaf87b943">micro_os_plus::micro_test_plus::detail::reporter_human::end_session</a> and <a href="#a7033819609bfad2db2ecc7a024e91b2c">end_session</a>.</p>

</div>
</div>

### format\_suite\_totals() {#a570030599ccc9f4133ed6a9eda2c2a1c}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter::format_suite_totals (const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a> &amp; suite, char(&amp;) message=[totals_size_])</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel protected">protected</span>
<span class="doxyMemberLabel static">static</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Formats the totals of a suite.</p>


<p>The text is the part of the suite result line common to the concrete reporters: <span class="doxyComputerOutput">"7 checks in 3 test cases"</span> for a passed suite, and <span class="doxyComputerOutput">"6 checks passed, 1 failed, in 3 test cases"</span> for a failed one; the number of test cases skipped by the filter follows, as <span class="doxyComputerOutput">", 1 skipped"</span>, only when not zero. The status, the enclosing markers, and the elapsed time are added by the callers.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">suite</td>
<td class="doxyParamItemDescription"><p>The suite that ended.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">message</td>
<td class="doxyParamItemDescription"><p>The character array that receives the null-terminated text.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>A passed suite has no failed checks, so only the number of checks is shown.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00880">880</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00780">780</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a570030599ccc9f4133ed6a9eda2c2a1c">780</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a570030599ccc9f4133ed6a9eda2c2a1c">reporter::format_suite_totals</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">781</span><span class="doxyLineContent"><span class="doxyHighlight">                                 </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> (&amp;message)[<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aaa55b147a670878984952ca1112cecd8">totals_size_</a>])</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">782</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">783</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters">counters</a>&amp; totals = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">totals</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">784</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">785</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> message_skipped[fragment_size];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">786</span><span class="doxyLineContent"><span class="doxyHighlight">    format_skipped (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a2e5ea7bbb9bd5a05213dee741f08599d">skipped_test_cases</a> (), message_skipped);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">787</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">788</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a14690f9880df505f9dd90a9f2c3dfc96">passed</a> ()) [[likely]]</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">789</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">790</span><span class="doxyLineContent"><span class="doxyHighlight">        snprintf (message, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (message),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">791</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">"%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">792</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">" check%s in %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">793</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">" test case%s%s"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">794</span><span class="doxyLineContent"><span class="doxyHighlight">                  totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> (), plural (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> ()),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">795</span><span class="doxyLineContent"><span class="doxyHighlight">                  totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">executed_test_cases</a> (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">796</span><span class="doxyLineContent"><span class="doxyHighlight">                  plural (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">executed_test_cases</a> ()), message_skipped);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">797</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">798</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">799</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">800</span><span class="doxyLineContent"><span class="doxyHighlight">        snprintf (message, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (message),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">801</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">"%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">802</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">" check%s passed, %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">803</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">" failed, in %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">804</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">" test case%s%s"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">805</span><span class="doxyLineContent"><span class="doxyHighlight">                  totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> (), plural (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> ()),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">806</span><span class="doxyLineContent"><span class="doxyHighlight">                  totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#ab1684c7c6101a4d534356d9d16807bee">failed_checks</a> (), totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">executed_test_cases</a> (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">807</span><span class="doxyLineContent"><span class="doxyHighlight">                  plural (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">executed_test_cases</a> ()), message_skipped);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">808</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">809</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">micro_os_plus::micro_test_plus::counters::executed_test_cases</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#ab1684c7c6101a4d534356d9d16807bee">micro_os_plus::micro_test_plus::counters::failed_checks</a>, <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a14690f9880df505f9dd90a9f2c3dfc96">micro_os_plus::micro_test_plus::counters::passed</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">micro_os_plus::micro_test_plus::counters::passed_checks</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a2e5ea7bbb9bd5a05213dee741f08599d">micro_os_plus::micro_test_plus::counters::skipped_test_cases</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">micro_os_plus::micro_test_plus::detail::runnable_base::totals</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aaa55b147a670878984952ca1112cecd8">micro_os_plus::micro_test_plus::detail::reporter::totals_size_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a> and <a href="#a2d5ddae3195ab52a957927a1b455f7b8">end_suite</a>.</p>

</div>
</div>

### format\_test\_case\_totals() {#a60b8564f54a6a1230e6d4ce110de93f5}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter::format_test_case_totals (const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a> &amp; test_case, char(&amp;) message=[totals_size_])</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel protected">protected</span>
<span class="doxyMemberLabel static">static</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Formats the totals of a test case.</p>


<p>The text is the part of the test case result line common to the concrete reporters: <span class="doxyComputerOutput">"7 checks"</span> for a passed test case, and <span class="doxyComputerOutput">"6 checks passed, 1 failed"</span> for a failed one, followed by the number of failed nested test cases, as <span class="doxyComputerOutput">", 1 test case failed"</span>, only when not zero, since a test case may fail because of a nested one alone. The status and the enclosing markers are added by the callers.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">test_case</td>
<td class="doxyParamItemDescription"><p>The test case that ended.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">message</td>
<td class="doxyParamItemDescription"><p>The character array that receives the null-terminated text.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>A passed test case has no failed checks and no failed nested test cases, so only the number of checks is shown.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00901">901</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00817">817</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a60b8564f54a6a1230e6d4ce110de93f5">817</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a60b8564f54a6a1230e6d4ce110de93f5">reporter::format_test_case_totals</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">818</span><span class="doxyLineContent"><span class="doxyHighlight">                                     </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> (&amp;message)[<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aaa55b147a670878984952ca1112cecd8">totals_size_</a>])</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">819</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">820</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters">counters</a>&amp; totals = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">totals</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">821</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">822</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a14690f9880df505f9dd90a9f2c3dfc96">passed</a> ()) [[likely]]</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">823</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">824</span><span class="doxyLineContent"><span class="doxyHighlight">        snprintf (message, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (message),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">825</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">"%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a> </span><span class="doxyHighlightStringLiteral">" check%s"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">826</span><span class="doxyLineContent"><span class="doxyHighlight">                  totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> (), plural (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> ()));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">827</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">828</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">829</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">830</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> message_test_cases[fragment_size] = </span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">831</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a85981e2e55a820cb49ee04aa82bbde56">failed_test_cases</a> () &gt; 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">832</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">833</span><span class="doxyLineContent"><span class="doxyHighlight">            snprintf (message_test_cases, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (message_test_cases),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">834</span><span class="doxyLineContent"><span class="doxyHighlight">                      </span><span class="doxyHighlightStringLiteral">", %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">835</span><span class="doxyLineContent"><span class="doxyHighlight">                      </span><span class="doxyHighlightStringLiteral">" test case%s failed"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">836</span><span class="doxyLineContent"><span class="doxyHighlight">                      totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a85981e2e55a820cb49ee04aa82bbde56">failed_test_cases</a> (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">837</span><span class="doxyLineContent"><span class="doxyHighlight">                      plural (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a85981e2e55a820cb49ee04aa82bbde56">failed_test_cases</a> ()));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">838</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">839</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">840</span><span class="doxyLineContent"><span class="doxyHighlight">        snprintf (message, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (message),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">841</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">"%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">842</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">" check%s passed, %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">843</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">" failed%s"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">844</span><span class="doxyLineContent"><span class="doxyHighlight">                  totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> (), plural (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> ()),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">845</span><span class="doxyLineContent"><span class="doxyHighlight">                  totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#ab1684c7c6101a4d534356d9d16807bee">failed_checks</a> (), message_test_cases);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">846</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">847</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#ab1684c7c6101a4d534356d9d16807bee">micro_os_plus::micro_test_plus::counters::failed_checks</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a85981e2e55a820cb49ee04aa82bbde56">micro_os_plus::micro_test_plus::counters::failed_test_cases</a>, <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">micro_os_plus::micro_test_plus::detail::reporter::micro_test_plus::test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a14690f9880df505f9dd90a9f2c3dfc96">micro_os_plus::micro_test_plus::counters::passed</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">micro_os_plus::micro_test_plus::counters::passed_checks</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">micro_os_plus::micro_test_plus::detail::runnable_base::totals</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aaa55b147a670878984952ca1112cecd8">micro_os_plus::micro_test_plus::detail::reporter::totals_size_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a> and <a href="#ad15f7dbbf6a683441df40c502125adc3">end_test_case</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Protected Static Attributes

### elapsed\_time\_size\_ {#a2bf85bc5dd65df1816b52b7fd7c6c627}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">size_t micro_os_plus::micro_test_plus::detail::reporter::elapsed_time_size_ = 32</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel constexpr">constexpr</span>
<span class="doxyMemberLabel protected">protected</span>
<span class="doxyMemberLabel static">static</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Size of the array that receives the elapsed time text.</p>


<p>Large enough for <span class="doxyComputerOutput">", time: 4294967295.999 ms"</span>, the longest text produced by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac6dca3d3fa34870f3960fe5e226e45d8">format_elapsed_time()</a></span>.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00795">795</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2bf85bc5dd65df1816b52b7fd7c6c627">795</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2bf85bc5dd65df1816b52b7fd7c6c627">elapsed_time_size_</a> = 32;</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ace9c2dfffc49a97516b96dacaf87b943">micro_os_plus::micro_test_plus::detail::reporter_human::end_session</a>, <a href="#a7033819609bfad2db2ecc7a024e91b2c">end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a>, <a href="#a2d5ddae3195ab52a957927a1b455f7b8">end_suite</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac6dca3d3fa34870f3960fe5e226e45d8">micro_os_plus::micro_test_plus::detail::reporter::format_elapsed_time</a>.</p>

</div>
</div>

### indent\_size\_ {#a7ee7d450c03e89bb0beb6cd97056aa4e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">size_t micro_os_plus::micro_test_plus::detail::reporter::indent_size_ = 4</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel constexpr">constexpr</span>
<span class="doxyMemberLabel protected">protected</span>
<span class="doxyMemberLabel static">static</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Number of spaces per nesting level.</p>


<p>Used by the concrete reporters to indent the lines of the nested test cases; four spaces is also the TAP 14 subtest indentation.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01018">1018</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7ee7d450c03e89bb0beb6cd97056aa4e">1018</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7ee7d450c03e89bb0beb6cd97056aa4e">indent_size_</a> = 4;</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a04cef97a62731931038355a1b5f23556">micro_os_plus::micro_test_plus::detail::reporter_human::begin_test_case</a>, <a href="#a0302f9f5b977b05139d73df3bbc18d69">begin_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af17a48a165abd908031ddc3a0821f81e">micro_os_plus::micro_test_plus::detail::reporter_human::display_open_names</a>, <a href="#a2d5ddae3195ab52a957927a1b455f7b8">end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a>, <a href="#ad15f7dbbf6a683441df40c502125adc3">end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aedfa17028026f6eaa871214da441e90c">micro_os_plus::micro_test_plus::detail::reporter::operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af28ab5a9448645fb8976c0b139bf302b">micro_os_plus::micro_test_plus::detail::reporter_human::skip_test_case</a> and <a href="#a31ccd7af941d06241ce16df9274abc38">skip_test_case</a>.</p>

</div>
</div>

### totals\_size\_ {#aaa55b147a670878984952ca1112cecd8}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">size_t micro_os_plus::micro_test_plus::detail::reporter::totals_size_ = 94 + 6 * (std::numeric_limits&lt;size_t&gt;::digits10 + 1)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel constexpr">constexpr</span>
<span class="doxyMemberLabel protected">protected</span>
<span class="doxyMemberLabel static">static</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Size of the array that receives the totals text.</p>


<p>Large enough for the longest text produced by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a6bf3aac88a5e66e2f93eb32c54dbdd14">format_session_totals()</a></span>, which is longer than the texts of the suites and of the test cases: 53 characters, four counts, two fragments of up to 20 characters and a count each (the longest fragment is <span class="doxyComputerOutput">", N test cases failed"</span>), and the terminator, with the counts of the largest <span class="doxyComputerOutput">size_t</span> value (10 digits on 32-bit targets, 20 on 64-bit ones). The fragments are counted at their maximum length, as the compiler does when it checks for truncation.</p>


<p>The array is a local variable of the functions that end the test cases, which run at the deepest point of the stack, so it is not larger than needed on the 32-bit embedded targets.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00837">837</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">838</span><span class="doxyLineContent"><span class="doxyHighlight">          = 94 + 6 * (std::numeric_limits&lt;size_t&gt;::digits10 + 1);</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ace9c2dfffc49a97516b96dacaf87b943">micro_os_plus::micro_test_plus::detail::reporter_human::end_session</a>, <a href="#a7033819609bfad2db2ecc7a024e91b2c">end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a>, <a href="#a2d5ddae3195ab52a957927a1b455f7b8">end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a>, <a href="#ad15f7dbbf6a683441df40c502125adc3">end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a6bf3aac88a5e66e2f93eb32c54dbdd14">micro_os_plus::micro_test_plus::detail::reporter::format_session_totals</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a570030599ccc9f4133ed6a9eda2c2a1c">micro_os_plus::micro_test_plus::detail::reporter::format_suite_totals</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a60b8564f54a6a1230e6d4ce110de93f5">micro_os_plus::micro_test_plus::detail::reporter::format_test_case_totals</a>.</p>

</div>
</div>

</div>

<hr/>

The documentation for this class was generated from the following files:

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reporter-inlines-h">reporter-inlines.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-tap-h">reporter-tap.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp">reporter-tap.cpp</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
