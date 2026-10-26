---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/classes/micro-os-plus/micro-test-plus/detail/reporter
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - class

---

<div class="doxyPage">

# `reporter` Class

<p>Abstract base class for the reporters that display test results, including operand values for failures. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
class micro_os_plus::micro_test_plus::detail::reporter { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>"
</div>

## Derived Classes

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human">reporter_human</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Human (standard output) implementation of <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a></span>. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap">reporter_tap</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>TAP (Test Anything Protocol) implementation of <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a></span>. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Classes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">struct</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/reporter/open-test-case">open_test_case</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>A test case that has begun and not yet ended. <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/reporter/open-test-case/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Friends Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aec75a9652b7e98188d506c462aa73e19">check_result</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The check result, which formats the expressions. <a href="#aec75a9652b7e98188d506c462aa73e19">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a68a030feff1f481126e9a6d170331420">micro_test_plus::runner</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The runner, which lists the test cases. <a href="#a68a030feff1f481126e9a6d170331420">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a904f410e240644fa77d65e686e6fc3eb">micro_test_plus::test_case</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The test case, which creates the checks. <a href="#a904f410e240644fa77d65e686e6fc3eb">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a7e04bcbd0745543c604fdd975829175a">reporter</a> (const runner_options &amp;opts)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructor for the reporter class. <a href="#a7e04bcbd0745543c604fdd975829175a">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a5b6052e6c28235b76d855b2b7bc176dd">~reporter</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Virtual destructor for the reporter class. <a href="#a5b6052e6c28235b76d855b2b7bc176dd">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Operators Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a7e04bcbd0745543c604fdd975829175a">reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#acbdac50fb2a1302e4a97c8160e7fd7cb">operator&lt;&lt;</a> (bool v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for boolean values. <a href="#acbdac50fb2a1302e4a97c8160e7fd7cb">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a7e04bcbd0745543c604fdd975829175a">reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a5d29d78c80c20d3fe96ac9d0f4a969b3">operator&lt;&lt;</a> (char c)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for a single character. <a href="#a5d29d78c80c20d3fe96ac9d0f4a969b3">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a7e04bcbd0745543c604fdd975829175a">reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ad84ba0969733f2120622d26951259f95">operator&lt;&lt;</a> (const char *s)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for a constant character string. <a href="#ad84ba0969733f2120622d26951259f95">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a7e04bcbd0745543c604fdd975829175a">reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aedfa17028026f6eaa871214da441e90c">operator&lt;&lt;</a> (indentation m)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/indentation">indentation</a></span> manipulator. <a href="#aedfa17028026f6eaa871214da441e90c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a7e04bcbd0745543c604fdd975829175a">reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#af4b5f0d3207f22b402bf4079a7547c1c">operator&lt;&lt;</a> (reporter &amp;(*func)(reporter &amp;))</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for stream manipulators, such as <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">endl</a></span>. <a href="#af4b5f0d3207f22b402bf4079a7547c1c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a7e04bcbd0745543c604fdd975829175a">reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ac894cb9cbf11f2f57acb388310eede4c">operator&lt;&lt;</a> (std::nullptr_t)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for nullptr. <a href="#ac894cb9cbf11f2f57acb388310eede4c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a7e04bcbd0745543c604fdd975829175a">reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a54158cb2ca77354223506355247cab9a">operator&lt;&lt;</a> (std::string_view sv)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for std::string_view. <a href="#a54158cb2ca77354223506355247cab9a">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;typename T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a7e04bcbd0745543c604fdd975829175a">reporter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a3ff526c7ae5db0669d7db2adebf7cb2d">operator&lt;&lt;</a> (T *v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator to display any pointer. <a href="#a3ff526c7ae5db0669d7db2adebf7cb2d">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a7e04bcbd0745543c604fdd975829175a">reporter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a0cdaf2313f78a256b80f7bb7b279e2e6">operator&lt;&lt;</a> (T v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for arithmetic types. <a href="#a0cdaf2313f78a256b80f7bb7b279e2e6">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a246e22554555caffce30c61ffe80e5f2">abort_session</a> (const reflection::source_location &amp;location, bool is_requirement)=0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Reports the abort of the test execution. <a href="#a246e22554555caffce30c61ffe80e5f2">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a00e5e3b4f1ddfeeff6deb614d120caef">begin_session</a> (const runner &amp;runner)=0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Marks the beginning of a test session. <a href="#a00e5e3b4f1ddfeeff6deb614d120caef">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aceec705f3b14971e03701afb35a8feef">begin_suite</a> (const suite &amp;suite)=0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Marks the beginning of a test suite. <a href="#aceec705f3b14971e03701afb35a8feef">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aa5f6b45879c1e0986ce4ebf9f374a182">begin_test_case</a> (const test_case &amp;test_case)=0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Marks the beginning of a test case. <a href="#aa5f6b45879c1e0986ce4ebf9f374a182">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const char *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a324aa273975068c140ab6eecc7e722c9">comment_prefix</a> (void) const noexcept=0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns the comment-prefix string used by this reporter format. <a href="#a324aa273975068c140ab6eecc7e722c9">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a287bad0e5eccee7df4a2c8517959bd0e">end_line</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends a line ending to the internal output buffer. <a href="#a287bad0e5eccee7df4a2c8517959bd0e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a1f1495d610d01955c8f8634810b54bb4">end_session</a> (const runner &amp;runner)=0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Marks the end of a test session. <a href="#a1f1495d610d01955c8f8634810b54bb4">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a89358dc17ea470ab4e829136284cd896">end_suite</a> (const suite &amp;suite)=0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Marks the end of a test suite. <a href="#a89358dc17ea470ab4e829136284cd896">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a145971ca001d89162c435f87b4cfeece">end_test_case</a> (const test_case &amp;test_case)=0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Marks the end of a test case. <a href="#a145971ca001d89162c435f87b4cfeece">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a406cf77b7adcd5fe9417ce7bce4f3afb">fail</a> (const failure_info &amp;failure, const std::string &amp;expression, const test_case &amp;test_case)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Reports a failed condition. <a href="#a406cf77b7adcd5fe9417ce7bce4f3afb">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a1bf7be6972ddc4f81cecb1552452db10">fail_suite</a> (const std::string &amp;message, const suite &amp;suite)=0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Reports a failure of a test suite outside its test cases. <a href="#a1bf7be6972ddc4f81cecb1552452db10">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a804b593aefa158d92a72da43de57d242">flush_streams</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Flushes the standard output stream and the output file. <a href="#a804b593aefa158d92a72da43de57d242">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a083ecdfa952d7f8c372a61fbea309357">has_output_file_error</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns whether the output file could not be opened. <a href="#a083ecdfa952d7f8c372a61fbea309357">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ad9e6ccebc1904f723409ddb0caaddb3e">pass</a> (const std::string &amp;message, const std::string &amp;expression, const test_case &amp;test_case)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Reports a passed condition. <a href="#ad9e6ccebc1904f723409ddb0caaddb3e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a01df0bb54bda2662826e84e685374ce0">skip_suite</a> (const suite &amp;suite)=0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Reports a test suite skipped by the filter. <a href="#a01df0bb54bda2662826e84e685374ce0">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a1986653001ad23e18de13822bbcd022f">skip_test_case</a> (const test_case &amp;test_case)=0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Reports a test case skipped by the filter. <a href="#a1986653001ad23e18de13822bbcd022f">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914b">micro_test_plus::verbosity</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a467d1332df523b9acaa3ff82b0ebb714">verbosity</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deprecated access to the verbosity level. <a href="#a467d1332df523b9acaa3ff82b0ebb714">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a0e6f0a129d495a7e9d57ef71412cd88f">writes_passed_checks</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns whether the passed checks are written anywhere. <a href="#a0e6f0a129d495a7e9d57ef71412cd88f">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a5859ce31641330b243cfb5d1c6080859">clear_buffer</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Clears the output buffer. <a href="#a5859ce31641330b243cfb5d1c6080859">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a844e80839c81133b52ee3beabf64d942">commit_buffer</a> (void)=0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Writes the results buffered for the outer test case before a nested test case begins or is skipped. <a href="#a844e80839c81133b52ee3beabf64d942">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a5cf73aaf67484b50c25ef42363d49337">commit_outer_results</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Writes the results of the outer test case, if any, before a nested test case begins or is skipped. <a href="#a5cf73aaf67484b50c25ef42363d49337">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">std::string_view</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#adb473d2a466c856bfe8151c7558383c1">console_lines</a> (bool failed) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns the buffered lines that the console displays when a test case or a suite ends, or when its results are committed. <a href="#adb473d2a466c856bfe8151c7558383c1">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a5ddd6ca6ce847ca89d7a3fcf9751f97d">enter_suite</a> (const suite &amp;suite, bool displayed)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Notes the suite that begins, for the headings displayed later. <a href="#a5ddd6ca6ce847ca89d7a3fcf9751f97d">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a2d5e5125b8c71fe0dedbe92d730647ec">mark_failure</a> (size_t begin)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Records that the lines appended to the buffer from a given position are a failure. <a href="#a2d5e5125b8c71fe0dedbe92d730647ec">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a24888ee49f3e3abb1a849e309a099189">output_fail_prefix</a> (const std::string &amp;message, const bool has_expression, const reflection::source_location &amp;location, const test_case &amp;test_case)=0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Outputs the prefix for a failing condition. <a href="#a24888ee49f3e3abb1a849e309a099189">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#adce64d6a989f193c1d0c306039a3639c">output_fail_suffix</a> (const reflection::source_location &amp;location, check_kind kind, const test_case &amp;test_case)=0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Outputs the suffix for a failing condition. <a href="#adce64d6a989f193c1d0c306039a3639c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aede54e424adbe77bdb6b87d40f2d3517">output_pass_prefix</a> (const std::string &amp;message, const test_case &amp;test_case)=0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Outputs the prefix for a passing condition. <a href="#aede54e424adbe77bdb6b87d40f2d3517">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a82f4940bc3915b3fdcb58823f9bdb535">output_pass_suffix</a> (const test_case &amp;test_case)=0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Outputs the suffix for a passing condition. <a href="#a82f4940bc3915b3fdcb58823f9bdb535">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/output-route">output_route</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#af33f2f6498a97383cdb75020e32ccf23">route</a> (record_kind kind) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Tells where a kind of record is written. <a href="#af33f2f6498a97383cdb75020e32ccf23">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a37cba38a47d66a928a936ee081c6d88c">write_buffer_to_file</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Writes the current buffered content to the output file. <a href="#a37cba38a47d66a928a936ee081c6d88c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#abaee31ffca8e65c9af34f7f67227c5b3">write_console</a> (const char *format,...)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Writes formatted text to the console. <a href="#abaee31ffca8e65c9af34f7f67227c5b3">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a887f23131eb91fecf060982dcbd3b1ca">write_console_text</a> (std::string_view text)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Writes a text to the console, unchanged. <a href="#a887f23131eb91fecf060982dcbd3b1ca">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a90a541c6a9b1ddd3da9440358bfc704e">write_file</a> (const char *format,...)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Writes formatted text to the output file. <a href="#a90a541c6a9b1ddd3da9440358bfc704e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aeafdc8e05a6d80d9445f17ff354ee215">write_info</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Writes the informational (non-result) lines to the console and to the output file. <a href="#aeafdc8e05a6d80d9445f17ff354ee215">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aa97f2ba65009154090dc68e42c94db71">write_line</a> (bool to_console, const char *format,...)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Writes formatted lines to the output file and, when requested, to the console. <a href="#aa97f2ba65009154090dc68e42c94db71">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a38252f2ef24feabcb7f55e7bdac30bd2">add_empty_line_</a> { true }</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Whether to write an empty line before the next console output. <a href="#a38252f2ef24feabcb7f55e7bdac30bd2">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">std::span&lt; char *const  &gt;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a3e47f2c530c5019bde9fe56867bc581f">arguments_</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The command-line arguments passed to the test runner. <a href="#a3e47f2c530c5019bde9fe56867bc581f">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">std::string</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output accumulation buffer. <a href="#a0972f104175c075295a8aa385e90aad4">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a970a08a00e70f1574033085350656230">buffer_has_failures_</a> { false }</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Whether the output buffer contains a failed check. <a href="#a970a08a00e70f1574033085350656230">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a69616e251ebb3d22e481ada0831bec3c">colours_</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>ANSI colour codes for output formatting. <a href="#a69616e251ebb3d22e481ada0831bec3c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a> *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ad0a2ebe9aedaecf71fc76993122e661f">current_suite_</a> { nullptr }</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The suite that has begun and not yet ended. <a href="#ad0a2ebe9aedaecf71fc76993122e661f">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter">expression_formatter</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ac928cbe8852ca0c0273482b905c6301b">expression_</a> { <a href="#a69616e251ebb3d22e481ada0831bec3c">colours_</a> }</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Expression formatter for pass and fail reporting. <a href="#ac928cbe8852ca0c0273482b905c6301b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">std::string</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ab8acd7e0c7bc5240a0912affd115305b">failures_</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The lines of the failed checks, for the quiet verbosity. <a href="#ab8acd7e0c7bc5240a0912affd115305b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a0d73674812cca717a754137b4b26ed89">has_output_file_error_</a> { false }</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Whether the output file could not be opened. <a href="#a0d73674812cca717a754137b4b26ed89">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">std::vector&lt; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/reporter/open-test-case">open_test_case</a> &gt;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ad7db34b25d785eacf98d4a50f1951d5b">open_test_cases_</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The test cases that have begun and not yet ended, outermost first. <a href="#ad7db34b25d785eacf98d4a50f1951d5b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">FILE *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> { nullptr }</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Optional output file, receiving a copy of the test report. <a href="#a270178ed5fbe0d3f4d72766c2984582a">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">std::string</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ac3878d2e85ed2cae4c71c793d7a8f52e">output_file_path_</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Path of the optional output file. <a href="#ac3878d2e85ed2cae4c71c793d7a8f52e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a6b07e60aa8baeb90821690d1ff9c65e6">suite_displayed_</a> { false }</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Whether the heading of the current suite was displayed on the console. <a href="#a6b07e60aa8baeb90821690d1ff9c65e6">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914b">micro_test_plus::verbosity</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The verbosity level for test reporting. <a href="#a2560a0f1cf935e420a2e584ccddf1a1e">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ac6dca3d3fa34870f3960fe5e226e45d8">format_elapsed_time</a> (const stopwatch &amp;stopwatch, char(&amp;message)[elapsed_time_size_])</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats the elapsed time of a suite or of the session. <a href="#ac6dca3d3fa34870f3960fe5e226e45d8">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">static void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a6bf3aac88a5e66e2f93eb32c54dbdd14">format_session_totals</a> (const runner &amp;runner, char(&amp;message)[totals_size_])</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats the totals of the test session. <a href="#a6bf3aac88a5e66e2f93eb32c54dbdd14">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">static void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a570030599ccc9f4133ed6a9eda2c2a1c">format_suite_totals</a> (const suite &amp;suite, char(&amp;message)[totals_size_])</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats the totals of a suite. <a href="#a570030599ccc9f4133ed6a9eda2c2a1c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">static void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a60b8564f54a6a1230e6d4ce110de93f5">format_test_case_totals</a> (const test_case &amp;test_case, char(&amp;message)[totals_size_])</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats the totals of a test case. <a href="#a60b8564f54a6a1230e6d4ce110de93f5">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a2bf85bc5dd65df1816b52b7fd7c6c627">elapsed_time_size_</a> = 32</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Size of the array that receives the elapsed time text. <a href="#a2bf85bc5dd65df1816b52b7fd7c6c627">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">static constexpr size_t</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a7ee7d450c03e89bb0beb6cd97056aa4e">indent_size_</a> = 4</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Number of spaces per nesting level. <a href="#a7ee7d450c03e89bb0beb6cd97056aa4e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">static constexpr size_t</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aaa55b147a670878984952ca1112cecd8">totals_size_</a> = 94 + 6 * (std::numeric_limits&lt;size_t&gt;::digits10 + 1)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Size of the array that receives the totals text. <a href="#aaa55b147a670878984952ca1112cecd8">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Abstract base class for the reporters that display test results, including operand values for failures.</p>


<p>The <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a></span> class is responsible for presenting test results within the µTest++ framework. It accumulates output in a buffer, using basic output operators for strings, characters, booleans, numbers, and pointers, and writes it to the console and to an optional output file.</p>


<p>For failed checks, the reporter prints the actual values of the operands, pre-formatted by its <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter">expression_formatter</a></span> (with type suffixes for numbers). The class supports multiple verbosity levels and colour-coded output to distinguish between passed and failed checks.</p>


<p>The pure virtual member functions report the beginning and end of the session, the suites, and the test cases, and format the pass and fail results; they are implemented by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human">reporter_human</a></span> and <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap">reporter_tap</a></span>. The concrete reporter is created by the runner, as selected by the <span class="doxyComputerOutput">--<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a></span> command-line option, or by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#ad22d04df014c5b0658b6e7bd239f15b0">runner_options::selected_reporter</a></span>.</p>


<p>The reporters are internal to the framework: their public members are the protocol between the runner, the test nodes, the checks, and the reporter, and custom reporters are not supported. The applications select a reporter with the <span class="doxyComputerOutput">--<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a></span> command-line option, or with the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options">runner_options</a></span>, and read the verbosity with <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a1dd0221dca8e7382f0b625ff6316ed92">runner::verbosity_level()</a></span>.</p>


<p>Definition at line 277 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxySectionDef">

## Friends

### check\_result {#aec75a9652b7e98188d506c462aa73e19}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">friend class check_result</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The check result, which formats the expressions.</p>


<p>It formats its expression into the expression formatter, and retrieves the text when it reports the check.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00295">295</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aec75a9652b7e98188d506c462aa73e19">295</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="#aec75a9652b7e98188d506c462aa73e19">check_result</a>;</span></span></div>

</div>


<p>Reference <a href="#aec75a9652b7e98188d506c462aa73e19">check_result</a>.</p>


<p>Referenced by <a href="#aec75a9652b7e98188d506c462aa73e19">check_result</a>.</p>

</div>
</div>

### micro\_test\_plus::runner {#a68a030feff1f481126e9a6d170331420}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">friend class <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">micro_test_plus::runner</a></td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The runner, which lists the test cases.</p>


<p>It writes the list of the test cases with <span class="doxyComputerOutput"><a href="#aa97f2ba65009154090dc68e42c94db71">write_line()</a></span>.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00303">303</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a68a030feff1f481126e9a6d170331420">303</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">micro_test_plus::runner</a>;</span></span></div>

</div>


<p>References <a href="#a7e04bcbd0745543c604fdd975829175a">reporter</a>, <a href="#a287bad0e5eccee7df4a2c8517959bd0e">end_line</a>, <a href="#a406cf77b7adcd5fe9417ce7bce4f3afb">fail</a>, <a href="#a804b593aefa158d92a72da43de57d242">flush_streams</a>, <a href="#a083ecdfa952d7f8c372a61fbea309357">has_output_file_error</a>, <a href="#a904f410e240644fa77d65e686e6fc3eb">micro_test_plus::test_case</a>, <a href="#ad9e6ccebc1904f723409ddb0caaddb3e">pass</a> and <a href="#a467d1332df523b9acaa3ff82b0ebb714">verbosity</a>.</p>


<p>Referenced by <a href="#a00e5e3b4f1ddfeeff6deb614d120caef">begin_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#aa3cefeb72e745b2424b48ed4a31102e7">micro_os_plus::micro_test_plus::detail::reporter_human::begin_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#acaae91eea2deed1fe3f43b6453e7e656">micro_os_plus::micro_test_plus::detail::reporter_tap::begin_session</a>, <a href="#a1f1495d610d01955c8f8634810b54bb4">end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ace9c2dfffc49a97516b96dacaf87b943">micro_os_plus::micro_test_plus::detail::reporter_human::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a7033819609bfad2db2ecc7a024e91b2c">micro_os_plus::micro_test_plus::detail::reporter_tap::end_session</a>, <a href="#a6bf3aac88a5e66e2f93eb32c54dbdd14">format_session_totals</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a23a8c557b9a14e415b3092fb766d4fad">micro_os_plus::micro_test_plus::detail::reporter_human::operator=</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a9da35382cc3f903728f5f1bed2c4a745">micro_os_plus::micro_test_plus::detail::reporter_tap::operator=</a>.</p>

</div>
</div>

### micro\_test\_plus::test\_case {#a904f410e240644fa77d65e686e6fc3eb}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">friend class <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">micro_test_plus::test_case</a></td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The test case, which creates the checks.</p>


<p>It passes the expression formatter to the check results created by <span class="doxyComputerOutput">expect()</span> and <span class="doxyComputerOutput">require()</span>.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00286">286</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a904f410e240644fa77d65e686e6fc3eb">286</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">micro_test_plus::test_case</a>;</span></span></div>

</div>


<p>Referenced by <a href="#aa5f6b45879c1e0986ce4ebf9f374a182">begin_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a04cef97a62731931038355a1b5f23556">micro_os_plus::micro_test_plus::detail::reporter_human::begin_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a0302f9f5b977b05139d73df3bbc18d69">micro_os_plus::micro_test_plus::detail::reporter_tap::begin_test_case</a>, <a href="#a145971ca001d89162c435f87b4cfeece">end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#ad15f7dbbf6a683441df40c502125adc3">micro_os_plus::micro_test_plus::detail::reporter_tap::end_test_case</a>, <a href="#a406cf77b7adcd5fe9417ce7bce4f3afb">fail</a>, <a href="#a60b8564f54a6a1230e6d4ce110de93f5">format_test_case_totals</a>, <a href="#a68a030feff1f481126e9a6d170331420">micro_test_plus::runner</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a23a8c557b9a14e415b3092fb766d4fad">micro_os_plus::micro_test_plus::detail::reporter_human::operator=</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a9da35382cc3f903728f5f1bed2c4a745">micro_os_plus::micro_test_plus::detail::reporter_tap::operator=</a>, <a href="#a24888ee49f3e3abb1a849e309a099189">output_fail_prefix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a032be7e38aad40c8bc44b2376ad90e29">micro_os_plus::micro_test_plus::detail::reporter_human::output_fail_prefix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a3bd1c7d455abc782062d0e23a3ef1015">micro_os_plus::micro_test_plus::detail::reporter_tap::output_fail_prefix</a>, <a href="#adce64d6a989f193c1d0c306039a3639c">output_fail_suffix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ab9fdb57e1a5497af22de7cf4a252ce4b">micro_os_plus::micro_test_plus::detail::reporter_human::output_fail_suffix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#aaea110287f115fbaf80b0248f724c5b6">micro_os_plus::micro_test_plus::detail::reporter_tap::output_fail_suffix</a>, <a href="#aede54e424adbe77bdb6b87d40f2d3517">output_pass_prefix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a043919044274838f8030d53630e3b1f5">micro_os_plus::micro_test_plus::detail::reporter_human::output_pass_prefix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#ac6c05f92e47ad71f72b44f9beb0b98f1">micro_os_plus::micro_test_plus::detail::reporter_tap::output_pass_prefix</a>, <a href="#a82f4940bc3915b3fdcb58823f9bdb535">output_pass_suffix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#aeb5fb6ae953d2250360968c5582f73ab">micro_os_plus::micro_test_plus::detail::reporter_human::output_pass_suffix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a37c4235afdd9b704fd65d25d130bee86">micro_os_plus::micro_test_plus::detail::reporter_tap::output_pass_suffix</a>, <a href="#ad9e6ccebc1904f723409ddb0caaddb3e">pass</a>, <a href="#a1986653001ad23e18de13822bbcd022f">skip_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af28ab5a9448645fb8976c0b139bf302b">micro_os_plus::micro_test_plus::detail::reporter_human::skip_test_case</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a31ccd7af941d06241ce16df9274abc38">micro_os_plus::micro_test_plus::detail::reporter_tap::skip_test_case</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Constructors

### reporter() {#a7e04bcbd0745543c604fdd975829175a}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::reporter::reporter (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options">runner_options</a> &amp; opts)</td>
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

<p>Constructor for the reporter class.</p>


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

<p>Copies the verbosity and the view of the command-line arguments from the session options, and opens the output file, if a non-empty path was given, keeping a copy of the path. If the file cannot be opened, an error message is written to <span class="doxyComputerOutput">stderr</span>, the report is written only to the console, and <span class="doxyComputerOutput"><a href="#a083ecdfa952d7f8c372a61fbea309357">has_output_file_error()</a></span> returns <span class="doxyComputerOutput">true</span>. The internal string buffer is pre-allocated to reduce dynamic allocation overhead.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00312">312</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00160">160</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a7e04bcbd0745543c604fdd975829175a">160</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a7e04bcbd0745543c604fdd975829175a">reporter::reporter</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options">runner_options</a>&amp; opts)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">161</span><span class="doxyLineContent"><span class="doxyHighlight">      : <a href="#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a>{ opts.verbosity_level }, <a href="#a3e47f2c530c5019bde9fe56867bc581f">arguments_</a>{ opts.arguments }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">162</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">163</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">164</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">165</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">166</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">167</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (opts.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#aacf79acd1554b6e8899524bc02ee6257">output_file_path</a> != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight"> &amp;&amp; opts.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#aacf79acd1554b6e8899524bc02ee6257">output_file_path</a>[0] != </span><span class="doxyHighlightCharLiteral">'\0'</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">168</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">169</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> = fopen (opts.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#aacf79acd1554b6e8899524bc02ee6257">output_file_path</a>, </span><span class="doxyHighlightStringLiteral">"w"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">170</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> == </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">171</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">172</span><span class="doxyLineContent"><span class="doxyHighlight">            fprintf (stderr, </span><span class="doxyHighlightStringLiteral">"error: Failed to open output file '%s'\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">173</span><span class="doxyLineContent"><span class="doxyHighlight">                     opts.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#aacf79acd1554b6e8899524bc02ee6257">output_file_path</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">174</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="#a0d73674812cca717a754137b4b26ed89">has_output_file_error_</a> = </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">175</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">176</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">177</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">178</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="#ac3878d2e85ed2cae4c71c793d7a8f52e">output_file_path_</a> = opts.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#aacf79acd1554b6e8899524bc02ee6257">output_file_path</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">179</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">180</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">181</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">182</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Pre-allocate buffer to reduce dynamic allocations.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">183</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>.reserve (128);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">184</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a3e47f2c530c5019bde9fe56867bc581f">arguments_</a>, <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>, <a href="#a0d73674812cca717a754137b4b26ed89">has_output_file_error_</a>, <a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#aacf79acd1554b6e8899524bc02ee6257">micro_os_plus::micro_test_plus::runner_options::output_file_path</a>, <a href="#ac3878d2e85ed2cae4c71c793d7a8f52e">output_file_path_</a> and <a href="#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a82221fa355584dbaa75c7e66fbefa6b8">micro_os_plus::micro_test_plus::detail::reporter_human::reporter_human</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a8ab19d5802719647f6429e69f3b86345">micro_os_plus::micro_test_plus::detail::reporter_tap::reporter_tap</a>, <a href="#a68a030feff1f481126e9a6d170331420">micro_test_plus::runner</a>, <a href="#acbdac50fb2a1302e4a97c8160e7fd7cb">operator&lt;&lt;</a>, <a href="#a5d29d78c80c20d3fe96ac9d0f4a969b3">operator&lt;&lt;</a>, <a href="#ad84ba0969733f2120622d26951259f95">operator&lt;&lt;</a>, <a href="#aedfa17028026f6eaa871214da441e90c">operator&lt;&lt;</a>, <a href="#af4b5f0d3207f22b402bf4079a7547c1c">operator&lt;&lt;</a>, <a href="#ac894cb9cbf11f2f57acb388310eede4c">operator&lt;&lt;</a>, <a href="#a54158cb2ca77354223506355247cab9a">operator&lt;&lt;</a>, <a href="#a3ff526c7ae5db0669d7db2adebf7cb2d">operator&lt;&lt;</a> and <a href="#a0cdaf2313f78a256b80f7bb7b279e2e6">operator&lt;&lt;</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Destructor

### \~reporter() {#a5b6052e6c28235b76d855b2b7bc176dd}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::reporter::~reporter ()</td>
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


<p>Virtual, so that the concrete reporters, owned through a pointer to this base class, are destroyed correctly.</p>


<p>If an output file was opened, it is flushed and closed, and a confirmation message naming the output file is written to <span class="doxyComputerOutput">stdout</span>, except with the <span class="doxyComputerOutput">silent</span> verbosity, which writes nothing to the console. If tracing is enabled, the function signature is output for diagnostic purposes.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00321">321</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00194">194</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a5b6052e6c28235b76d855b2b7bc176dd">194</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a5b6052e6c28235b76d855b2b7bc176dd">reporter::~reporter</a> ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">195</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">196</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">197</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">198</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">199</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">200</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">201</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">202</span><span class="doxyLineContent"><span class="doxyHighlight">        fflush (<a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">203</span><span class="doxyLineContent"><span class="doxyHighlight">        fclose (<a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">204</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">205</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> != <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">verbosity::silent</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">206</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">207</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="#abaee31ffca8e65c9af34f7f67227c5b3">write_console</a> (</span><span class="doxyHighlightStringLiteral">"Test output written to '%s'.\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">208</span><span class="doxyLineContent"><span class="doxyHighlight">                           <a href="#ac3878d2e85ed2cae4c71c793d7a8f52e">output_file_path_</a>.c_str ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">209</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">210</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">211</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> = </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">212</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#ac3878d2e85ed2cae4c71c793d7a8f52e">output_file_path_</a>.clear ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">213</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">214</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a>, <a href="#ac3878d2e85ed2cae4c71c793d7a8f52e">output_file_path_</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">micro_os_plus::micro_test_plus::silent</a>, <a href="#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> and <a href="#abaee31ffca8e65c9af34f7f67227c5b3">write_console</a>.</p>

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


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00361">361</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00669">669</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">669</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a54158cb2ca77354223506355247cab9a">reporter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">670</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">671</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>.append (v ? </span><span class="doxyHighlightStringLiteral">"true"</span><span class="doxyHighlight"> : </span><span class="doxyHighlightStringLiteral">"false"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">672</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">673</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a7e04bcbd0745543c604fdd975829175a">reporter</a> and <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>.</p>

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


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00338">338</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00632">632</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">632</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a54158cb2ca77354223506355247cab9a">reporter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> c)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">633</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">634</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>.append (1, c);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">635</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">636</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a7e04bcbd0745543c604fdd975829175a">reporter</a> and <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>.</p>

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


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00352">352</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00647">647</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">647</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a54158cb2ca77354223506355247cab9a">reporter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* s)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">648</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">649</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (s == </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">650</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">651</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"nullptr"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">652</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">653</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">654</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">655</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>.append (s);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">656</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">657</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">658</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a7e04bcbd0745543c604fdd975829175a">reporter</a> and <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>.</p>

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


<p>Appends <span class="doxyComputerOutput"><a href="#a7ee7d450c03e89bb0beb6cd97056aa4e">indent_size_</a></span> spaces for each indentation level.</p>


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


<p>This operator overload appends spaces to the internal output buffer, <span class="doxyComputerOutput"><a href="#a7ee7d450c03e89bb0beb6cd97056aa4e">indent_size_</a></span> for each of the <span class="doxyComputerOutput">m.level</span> indentation levels, allowing <span class="doxyComputerOutput">*this &lt;&lt; indent(n) &lt;&lt; "text"</span> chaining in both reporters.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00420">420</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00608">608</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">608</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a54158cb2ca77354223506355247cab9a">reporter::operator&lt;&lt;</a>(<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/indentation">indentation</a> m)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">609</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">610</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>.append (m.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/indentation/#a6b8b1c2610c1f1591bc87068deeefd5a">level</a> * <a href="#a7ee7d450c03e89bb0beb6cd97056aa4e">indent_size_</a>, </span><span class="doxyHighlightCharLiteral">' '</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">611</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">612</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a7e04bcbd0745543c604fdd975829175a">reporter</a>, <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>, <a href="#a7ee7d450c03e89bb0beb6cd97056aa4e">indent_size_</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/indentation/#a6b8b1c2610c1f1591bc87068deeefd5a">micro_os_plus::micro_test_plus::detail::indentation::level</a>.</p>

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
<td class="doxyMemberName">reporter &amp; micro_os_plus::micro_test_plus::detail::reporter::operator&lt;&lt; (<a href="#a7e04bcbd0745543c604fdd975829175a">reporter</a> &amp;(*)(<a href="#a7e04bcbd0745543c604fdd975829175a">reporter</a> &amp;) func)</td>
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


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00408">408</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00594">594</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">594</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a54158cb2ca77354223506355247cab9a">reporter::operator&lt;&lt;</a>(<a href="#a7e04bcbd0745543c604fdd975829175a">reporter</a>&amp; (*func) (<a href="#a7e04bcbd0745543c604fdd975829175a">reporter</a>&amp;))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">595</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">596</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Call the endl function.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">597</span><span class="doxyLineContent"><span class="doxyHighlight">    (*func) (*this);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">598</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">599</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a7e04bcbd0745543c604fdd975829175a">reporter</a>.</p>

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


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00369">369</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00681">681</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">681</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a54158cb2ca77354223506355247cab9a">reporter::operator&lt;&lt;</a>(std::nullptr_t)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">682</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">683</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"nullptr"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">684</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">685</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a7e04bcbd0745543c604fdd975829175a">reporter</a> and <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>.</p>

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


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00329">329</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00620">620</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">620</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a54158cb2ca77354223506355247cab9a">reporter::operator&lt;&lt;</a>(std::string_view sv)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">621</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">622</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>.append (sv);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">623</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">624</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a7e04bcbd0745543c604fdd975829175a">reporter</a> and <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>.</p>

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


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00399">399</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reporter-inlines-h/#l00084">84</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reporter-inlines-h">reporter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">84</span><span class="doxyLineContent"><span class="doxyHighlight">  reporter::operator&lt;&lt; (T* v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">85</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">86</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a622a2bb23e2c98ecfa3a2ccb53e19910">append_pointer</a> (<a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>, v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">87</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">88</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a7e04bcbd0745543c604fdd975829175a">reporter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a622a2bb23e2c98ecfa3a2ccb53e19910">micro_os_plus::micro_test_plus::detail::append_pointer</a> and <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>.</p>

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


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00381">381</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reporter-inlines-h/#l00101">101</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reporter-inlines-h">reporter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">101</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a54158cb2ca77354223506355247cab9a">reporter::operator&lt;&lt;</a>(T v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">102</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">103</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">append_number</a> (<a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>, v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">104</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">105</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a7e04bcbd0745543c604fdd975829175a">reporter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">micro_os_plus::micro_test_plus::detail::append_number</a> and <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Member Functions

### abort\_session() {#a246e22554555caffce30c61ffe80e5f2}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">virtual void micro_os_plus::micro_test_plus::detail::reporter::abort_session (const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> &amp; location, bool is_requirement)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Reports the abort of the test execution.</p>


<p>Called by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a7bc806540e65c21095ef1ea1ef970db2">runner::abort()</a></span> between <span class="doxyComputerOutput"><a href="#a00e5e3b4f1ddfeeff6deb614d120caef">begin_session()</a></span> and <span class="doxyComputerOutput"><a href="#a1f1495d610d01955c8f8634810b54bb4">end_session()</a></span>, before the abort handler and <span class="doxyComputerOutput">::abort()</span>; neither the <span class="doxyComputerOutput"><a href="#a145971ca001d89162c435f87b4cfeece">end_test_case()</a></span> of the running test cases, if any, nor <span class="doxyComputerOutput"><a href="#a1f1495d610d01955c8f8634810b54bb4">end_session()</a></span> are called afterwards. The abort is caused either by a failed <span class="doxyComputerOutput">require()</span>, when exceptions are disabled, after the failure was added to the output buffer, or by an explicit call of <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a7bc806540e65c21095ef1ea1ef970db2">runner::abort()</a></span>, from a test case body, from a suite body, or from the application.</p>


<p>Implementations display the buffered results, if any, with the context that identifies the running test case, followed by a line with the location of the abort, unless the verbosity is silent, and write them to the output file, if open, since the totals are never reached. They then clear the buffer, since the abort handler may throw an exception that the application catches, and the results must not be written again.</p>


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


<dl class="doxySectionUser">
<dt>Since</dt>
<dd><p>5.1.0</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00708">708</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>

</div>
</div>

### begin\_session() {#a00e5e3b4f1ddfeeff6deb614d120caef}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">virtual void micro_os_plus::micro_test_plus::detail::reporter::begin_session (const <a href="#a68a030feff1f481126e9a6d170331420">runner</a> &amp; runner)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Marks the beginning of a test session.</p>


<p>Called by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#acfabd0e10d233ad305b6f4fc125a97f2">runner::initialise()</a></span>, after the reporter is created; implementations display the session heading.</p>


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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00533">533</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<p>Reference <a href="#a68a030feff1f481126e9a6d170331420">micro_test_plus::runner</a>.</p>

</div>
</div>

### begin\_suite() {#aceec705f3b14971e03701afb35a8feef}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">virtual void micro_os_plus::micro_test_plus::detail::reporter::begin_suite (const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a> &amp; suite)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Marks the beginning of a test suite.</p>


<p>Called by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a432deda5a8721472e8775cbc98451722">suite::run()</a></span> before the suite body, for the suites registered with <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a4069fe957bbc7a9217ca2dd4d2034a97">runner::add_suite()</a></span> and for the static suites, and by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#acfabd0e10d233ad305b6f4fc125a97f2">runner::initialise()</a></span> for the top suite.</p>


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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00564">564</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a432deda5a8721472e8775cbc98451722">micro_os_plus::micro_test_plus::suite::run</a>.</p>

</div>
</div>

### begin\_test\_case() {#aa5f6b45879c1e0986ce4ebf9f374a182}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">virtual void micro_os_plus::micro_test_plus::detail::reporter::begin_test_case (const <a href="#a904f410e240644fa77d65e686e6fc3eb">test_case</a> &amp; test_case)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Marks the beginning of a test case.</p>


<p>Called by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#adb4333ecb107fee477156b661f0b1512">test_case::run()</a></span> before the test case body; the results buffered for an outer test case, if any, are written first (see <span class="doxyComputerOutput"><a href="#a5cf73aaf67484b50c25ef42363d49337">commit_outer_results()</a></span>), so that the buffer is empty when the body starts.</p>


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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00639">639</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<p>Reference <a href="#a904f410e240644fa77d65e686e6fc3eb">micro_test_plus::test_case</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#adb4333ecb107fee477156b661f0b1512">micro_os_plus::micro_test_plus::test_case::run</a>.</p>

</div>
</div>

### comment\_prefix() {#a324aa273975068c140ab6eecc7e722c9}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">virtual const char * micro_os_plus::micro_test_plus::detail::reporter::comment_prefix (void)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel noexcept">noexcept</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Returns the comment-prefix string used by this reporter format.</p>


<p>Used by <span class="doxyComputerOutput"><a href="#aeafdc8e05a6d80d9445f17ff354ee215">write_info()</a></span> to prefix the informational lines, so that they are valid comments in the output format.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A null-terminated prefix string.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00724">724</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<p>References <a href="#a5859ce31641330b243cfb5d1c6080859">clear_buffer</a>, <a href="#adb473d2a466c856bfe8151c7558383c1">console_lines</a>, <a href="#a5ddd6ca6ce847ca89d7a3fcf9751f97d">enter_suite</a>, <a href="#a2d5e5125b8c71fe0dedbe92d730647ec">mark_failure</a>, <a href="#af33f2f6498a97383cdb75020e32ccf23">route</a>, <a href="#a37cba38a47d66a928a936ee081c6d88c">write_buffer_to_file</a>, <a href="#abaee31ffca8e65c9af34f7f67227c5b3">write_console</a>, <a href="#a887f23131eb91fecf060982dcbd3b1ca">write_console_text</a>, <a href="#a90a541c6a9b1ddd3da9440358bfc704e">write_file</a>, <a href="#aeafdc8e05a6d80d9445f17ff354ee215">write_info</a>, <a href="#aa97f2ba65009154090dc68e42c94db71">write_line</a> and <a href="#a0e6f0a129d495a7e9d57ef71412cd88f">writes_passed_checks</a>.</p>


<p>Referenced by <a href="#aeafdc8e05a6d80d9445f17ff354ee215">write_info</a>.</p>

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


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00439">439</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00238">238</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a287bad0e5eccee7df4a2c8517959bd0e">238</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a287bad0e5eccee7df4a2c8517959bd0e">reporter::end_line</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">239</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">240</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">241</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">micro_os_plus::micro_test_plus::detail::endl</a> and <a href="#a68a030feff1f481126e9a6d170331420">micro_test_plus::runner</a>.</p>

</div>
</div>

### end\_session() {#a1f1495d610d01955c8f8634810b54bb4}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">virtual void micro_os_plus::micro_test_plus::detail::reporter::end_session (const <a href="#a68a030feff1f481126e9a6d170331420">runner</a> &amp; runner)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Marks the end of a test session.</p>


<p>Called by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a97f725cb167a2b464fac0eb88a0c8a46">runner::run()</a></span>, after all suites have run; implementations display the session summary.</p>


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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00548">548</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<p>Reference <a href="#a68a030feff1f481126e9a6d170331420">micro_test_plus::runner</a>.</p>

</div>
</div>

### end\_suite() {#a89358dc17ea470ab4e829136284cd896}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">virtual void micro_os_plus::micro_test_plus::detail::reporter::end_suite (const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a> &amp; suite)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Marks the end of a test suite.</p>


<p>Called by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a432deda5a8721472e8775cbc98451722">suite::run()</a></span> after the suite body, also when an exception escaped it, for the suites registered with <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a4069fe957bbc7a9217ca2dd4d2034a97">runner::add_suite()</a></span> and for the static suites, and by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a97f725cb167a2b464fac0eb88a0c8a46">runner::run()</a></span> for the top suite; implementations display the suite results.</p>


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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00582">582</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a432deda5a8721472e8775cbc98451722">micro_os_plus::micro_test_plus::suite::run</a>.</p>

</div>
</div>

### end\_test\_case() {#a145971ca001d89162c435f87b4cfeece}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">virtual void micro_os_plus::micro_test_plus::detail::reporter::end_test_case (const <a href="#a904f410e240644fa77d65e686e6fc3eb">test_case</a> &amp; test_case)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Marks the end of a test case.</p>


<p>Called by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#adb4333ecb107fee477156b661f0b1512">test_case::run()</a></span> after the test case body; implementations display the test case results and clear the output buffer.</p>


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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00654">654</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<p>Reference <a href="#a904f410e240644fa77d65e686e6fc3eb">micro_test_plus::test_case</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#adb4333ecb107fee477156b661f0b1512">micro_os_plus::micro_test_plus::test_case::run</a>.</p>

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
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter::fail (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info">failure_info</a> &amp; failure, const std::string &amp; expression, const <a href="#a904f410e240644fa77d65e686e6fc3eb">test_case</a> &amp; test_case)</td>
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


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00516">516</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00714">714</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a406cf77b7adcd5fe9417ce7bce4f3afb">714</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a406cf77b7adcd5fe9417ce7bce4f3afb">reporter::fail</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info">failure_info</a>&amp; failure, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string&amp; expression,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">715</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="#a904f410e240644fa77d65e686e6fc3eb">test_case</a>&amp; <a href="#a904f410e240644fa77d65e686e6fc3eb">test_case</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">716</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">717</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> begin = <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>.size ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">718</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">719</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a24888ee49f3e3abb1a849e309a099189">output_fail_prefix</a> (failure.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info/#ad7484cdab2c4142c2df255dc9aadfea6">message</a>, failure.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info/#a6d4c667be4b4a4709ea29505c9d23f12">has_expression</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">720</span><span class="doxyLineContent"><span class="doxyHighlight">                        failure.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info/#a8c259595885388a6a550576d1d3fab35">location</a>, <a href="#a904f410e240644fa77d65e686e6fc3eb">test_case</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">721</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">722</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (failure.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info/#a6d4c667be4b4a4709ea29505c9d23f12">has_expression</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">723</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">724</span><span class="doxyLineContent"><span class="doxyHighlight">        *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; expression;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">725</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">726</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">727</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#adce64d6a989f193c1d0c306039a3639c">output_fail_suffix</a> (failure.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info/#a8c259595885388a6a550576d1d3fab35">location</a>, failure.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info/#af7c2c1b52b97d5d2af89155e16bf8c41">kind</a>, <a href="#a904f410e240644fa77d65e686e6fc3eb">test_case</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">728</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">729</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a2d5e5125b8c71fe0dedbe92d730647ec">mark_failure</a> (begin);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">730</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info/#a6d4c667be4b4a4709ea29505c9d23f12">micro_os_plus::micro_test_plus::detail::failure_info::has_expression</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info/#af7c2c1b52b97d5d2af89155e16bf8c41">micro_os_plus::micro_test_plus::detail::failure_info::kind</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info/#a8c259595885388a6a550576d1d3fab35">micro_os_plus::micro_test_plus::detail::failure_info::location</a>, <a href="#a2d5e5125b8c71fe0dedbe92d730647ec">mark_failure</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info/#ad7484cdab2c4142c2df255dc9aadfea6">micro_os_plus::micro_test_plus::detail::failure_info::message</a>, <a href="#a904f410e240644fa77d65e686e6fc3eb">micro_test_plus::test_case</a>, <a href="#a24888ee49f3e3abb1a849e309a099189">output_fail_prefix</a> and <a href="#adce64d6a989f193c1d0c306039a3639c">output_fail_suffix</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a1980019eed5ac5b1eef65302eb9cc9cd">micro_os_plus::micro_test_plus::test_case::fail_unexpected_exception</a> and <a href="#a68a030feff1f481126e9a6d170331420">micro_test_plus::runner</a>.</p>

</div>
</div>

### fail\_suite() {#a1bf7be6972ddc4f81cecb1552452db10}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">virtual void micro_os_plus::micro_test_plus::detail::reporter::fail_suite (const std::string &amp; message, const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a> &amp; suite)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Reports a failure of a test suite outside its test cases.</p>


<p>Called by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a432deda5a8721472e8775cbc98451722">suite::run()</a></span> when an exception escapes the suite body, between <span class="doxyComputerOutput"><a href="#aceec705f3b14971e03701afb35a8feef">begin_suite()</a></span> and <span class="doxyComputerOutput"><a href="#a89358dc17ea470ab4e829136284cd896">end_suite()</a></span>; the suite has already advanced to its next test point, which numbers the failure after the test cases already run. Implementations add a failed line to the output buffer, at the indentation of the test cases, which <span class="doxyComputerOutput"><a href="#a89358dc17ea470ab4e829136284cd896">end_suite()</a></span> displays; there is no source location to show.</p>


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


<dl class="doxySectionUser">
<dt>Since</dt>
<dd><p>5.1.0</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00622">622</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a1d15dd97c94c3dabccb9e5a7444af0ec">micro_os_plus::micro_test_plus::suite::fail_unexpected_exception</a>.</p>

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


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00454">454</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00565">565</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a804b593aefa158d92a72da43de57d242">565</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a804b593aefa158d92a72da43de57d242">reporter::flush_streams</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">566</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">567</span><span class="doxyLineContent"><span class="doxyHighlight">    fflush (stdout);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">568</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">569</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">570</span><span class="doxyLineContent"><span class="doxyHighlight">        fflush (<a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">571</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">572</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a66f620b093f92e0def6bf5297fb6d6ee">micro_os_plus::micro_test_plus::detail::reporter_human::abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#aa8802baefcb360f48451418c783ac413">micro_os_plus::micro_test_plus::detail::reporter_tap::abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#aa3cefeb72e745b2424b48ed4a31102e7">micro_os_plus::micro_test_plus::detail::reporter_human::begin_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#acaae91eea2deed1fe3f43b6453e7e656">micro_os_plus::micro_test_plus::detail::reporter_tap::begin_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a58c85919422801369d1d4d9a8efe77d0">micro_os_plus::micro_test_plus::detail::reporter_human::begin_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a2c05a737bfe80c955a998dc801e964b5">micro_os_plus::micro_test_plus::detail::reporter_tap::begin_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a04cef97a62731931038355a1b5f23556">micro_os_plus::micro_test_plus::detail::reporter_human::begin_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a0302f9f5b977b05139d73df3bbc18d69">micro_os_plus::micro_test_plus::detail::reporter_tap::begin_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#adf27b1d3d7cb168f295e4bf198bb0dbf">micro_os_plus::micro_test_plus::detail::reporter_human::commit_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#af80ba6907c9f13b08f8cb8726d65c510">micro_os_plus::micro_test_plus::detail::reporter_tap::commit_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ace9c2dfffc49a97516b96dacaf87b943">micro_os_plus::micro_test_plus::detail::reporter_human::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a7033819609bfad2db2ecc7a024e91b2c">micro_os_plus::micro_test_plus::detail::reporter_tap::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a2d5ddae3195ab52a957927a1b455f7b8">micro_os_plus::micro_test_plus::detail::reporter_tap::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#ad15f7dbbf6a683441df40c502125adc3">micro_os_plus::micro_test_plus::detail::reporter_tap::end_test_case</a>, <a href="#a68a030feff1f481126e9a6d170331420">micro_test_plus::runner</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#aca37d52611ed87d102dce89c3c6cc99d">micro_os_plus::micro_test_plus::detail::reporter_human::skip_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a319f35d4af8c72af8b14a89b421c1c74">micro_os_plus::micro_test_plus::detail::reporter_tap::skip_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af28ab5a9448645fb8976c0b139bf302b">micro_os_plus::micro_test_plus::detail::reporter_human::skip_test_case</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a31ccd7af941d06241ce16df9274abc38">micro_os_plus::micro_test_plus::detail::reporter_tap::skip_test_case</a>.</p>

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


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00470">470</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00579">579</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a083ecdfa952d7f8c372a61fbea309357">579</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a083ecdfa952d7f8c372a61fbea309357">reporter::has_output_file_error</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">580</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">581</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a0d73674812cca717a754137b4b26ed89">has_output_file_error_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">582</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a0d73674812cca717a754137b4b26ed89">has_output_file_error_</a>.</p>


<p>Referenced by <a href="#a68a030feff1f481126e9a6d170331420">micro_test_plus::runner</a>.</p>

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
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter::pass (const std::string &amp; message, const std::string &amp; expression, const <a href="#a904f410e240644fa77d65e686e6fc3eb">test_case</a> &amp; test_case)</td>
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


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00501">501</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00694">694</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ad9e6ccebc1904f723409ddb0caaddb3e">694</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ad9e6ccebc1904f723409ddb0caaddb3e">reporter::pass</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string&amp; message, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string&amp; expression,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">695</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="#a904f410e240644fa77d65e686e6fc3eb">test_case</a>&amp; <a href="#a904f410e240644fa77d65e686e6fc3eb">test_case</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">696</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">697</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#aede54e424adbe77bdb6b87d40f2d3517">output_pass_prefix</a> (message, <a href="#a904f410e240644fa77d65e686e6fc3eb">test_case</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">698</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">699</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (message.empty ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">700</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">701</span><span class="doxyLineContent"><span class="doxyHighlight">        *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; expression;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">702</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">703</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">704</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a82f4940bc3915b3fdcb58823f9bdb535">output_pass_suffix</a> (<a href="#a904f410e240644fa77d65e686e6fc3eb">test_case</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">705</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a904f410e240644fa77d65e686e6fc3eb">micro_test_plus::test_case</a>, <a href="#aede54e424adbe77bdb6b87d40f2d3517">output_pass_prefix</a> and <a href="#a82f4940bc3915b3fdcb58823f9bdb535">output_pass_suffix</a>.</p>


<p>Referenced by <a href="#a68a030feff1f481126e9a6d170331420">micro_test_plus::runner</a>.</p>

</div>
</div>

### skip\_suite() {#a01df0bb54bda2662826e84e685374ce0}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">virtual void micro_os_plus::micro_test_plus::detail::reporter::skip_suite (const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a> &amp; suite)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Reports a test suite skipped by the filter.</p>


<p>Called by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a7c4dbf695c086ca4d3f0ce33e6d561f7">runner::run_suites()</a></span>, instead of running the suite, when its name does not match the first filter pattern; the suite has already been assigned its index. Implementations display a single line, without the suite body.</p>


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


<dl class="doxySectionUser">
<dt>Since</dt>
<dd><p>5.1.0</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00601">601</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>

</div>
</div>

### skip\_test\_case() {#a1986653001ad23e18de13822bbcd022f}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">virtual void micro_os_plus::micro_test_plus::detail::reporter::skip_test_case (const <a href="#a904f410e240644fa77d65e686e6fc3eb">test_case</a> &amp; test_case)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Reports a test case skipped by the filter.</p>


<p>Called instead of <span class="doxyComputerOutput"><a href="#aa5f6b45879c1e0986ce4ebf9f374a182">begin_test_case()</a></span> and <span class="doxyComputerOutput"><a href="#a145971ca001d89162c435f87b4cfeece">end_test_case()</a></span>, when the name of the test case, or of its suite, does not match the filter pattern of its level; the test case has already been assigned its index. Implementations display a single line, at the indentation of the test case.</p>


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


<dl class="doxySectionUser">
<dt>Since</dt>
<dd><p>5.1.0</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00674">674</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<p>Reference <a href="#a904f410e240644fa77d65e686e6fc3eb">micro_test_plus::test_case</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a38cf903fb0ba5b76b1eb2350b6385962">micro_os_plus::micro_test_plus::detail::runnable_base::after_test_case_create</a>.</p>

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


<p>Kept from the v5.0.1 <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a></span> class, for the applications that read it through the deprecated <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a65250ff363fbb3b5869bbe4de9578e86">runner::reporter()</a></span> (<span class="doxyComputerOutput">tr.reporter ().<a href="#a467d1332df523b9acaa3ff82b0ebb714">verbosity</a> ()</span>). The level is the one returned by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a1dd0221dca8e7382f0b625ff6316ed92">runner::verbosity_level()</a></span>, from the same session options.</p>


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
<dt class="doxyXrefSectTitle"><a href=/micro-test-plus-xpack/docs/api/pages/deprecated/#_deprecated000108>Deprecated</a></dt>
<dd class="doxyXrefSectDescription">
<p>use <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a1dd0221dca8e7382f0b625ff6316ed92">runner::verbosity_level()</a> (since 5.1.0)</p>
</dd>
</dl>
</div>

<p>Returns the level stored in <span class="doxyComputerOutput"><a href="#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a></span>, set by the constructor.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00487">487</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reporter-inlines-h/#l00113">113</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reporter-inlines-h">reporter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a467d1332df523b9acaa3ff82b0ebb714">113</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a467d1332df523b9acaa3ff82b0ebb714">reporter::verbosity</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight"> -&gt; <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914b">micro_test_plus::verbosity</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">114</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">115</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">116</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a>.</p>


<p>Referenced by <a href="#a68a030feff1f481126e9a6d170331420">micro_test_plus::runner</a>.</p>

</div>
</div>

### writes\_passed\_checks() {#a0e6f0a129d495a7e9d57ef71412cd88f}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::detail::reporter::writes_passed_checks (void)</td>
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

<p>Returns whether the passed checks are written anywhere.</p>


<p>Called by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-expectations/#gaf4f5f9632b5a290c1894984661a41a86">test_case::expect()</a></span> and <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-requirements/#gace68a1bd4dd258082f4b1fc01fcd008a">test_case::require()</a></span>, so that a passed check whose line is never written does not format its expression, its messages, or its line. The answer depends only on the verbosity and on the output file, which do not change during the session. A failed check is always formatted.</p>


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
<td class="doxyParamItemDescription"><p>The lines of the passed checks reach the console or the output file, at least in some cases.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">false</td>
<td class="doxyParamItemDescription"><p>The lines of the passed checks are never written.</p></td>
</tr>
</table>
</dd>
</dl>

<p>The passed checks are written to the output file, when it is open, whatever the verbosity; to the console only with the verbose verbosity level. With the normal verbosity, only the failed checks (with the names of the open test cases) are displayed, so the passed checks are only counted, without formatting them.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00744">744</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00290">290</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a0e6f0a129d495a7e9d57ef71412cd88f">290</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a0e6f0a129d495a7e9d57ef71412cd88f">reporter::writes_passed_checks</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">291</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">292</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight"> || <a href="#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">verbosity::verbose</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">293</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">micro_os_plus::micro_test_plus::verbose</a> and <a href="#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a>.</p>


<p>Referenced by <a href="#a324aa273975068c140ab6eecc7e722c9">comment_prefix</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-expectations/#gaf4f5f9632b5a290c1894984661a41a86">micro_os_plus::micro_test_plus::test_case::expect</a> and <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-requirements/#gace68a1bd4dd258082f4b1fc01fcd008a">micro_os_plus::micro_test_plus::test_case::require</a>.</p>

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


<p>Also resets <span class="doxyComputerOutput"><a href="#a970a08a00e70f1574033085350656230">buffer_has_failures_</a></span>, so that the flag always describes the current content of the buffer.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Empties <span class="doxyComputerOutput"><a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a></span> and <span class="doxyComputerOutput"><a href="#ab8acd7e0c7bc5240a0912affd115305b">failures_</a></span>, keeping their capacity, and resets <span class="doxyComputerOutput"><a href="#a970a08a00e70f1574033085350656230">buffer_has_failures_</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00954">954</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00738">738</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a5859ce31641330b243cfb5d1c6080859">738</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a5859ce31641330b243cfb5d1c6080859">reporter::clear_buffer</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">739</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">740</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>.clear ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">741</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#ab8acd7e0c7bc5240a0912affd115305b">failures_</a>.clear ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">742</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a970a08a00e70f1574033085350656230">buffer_has_failures_</a> = </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">743</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>, <a href="#a970a08a00e70f1574033085350656230">buffer_has_failures_</a> and <a href="#ab8acd7e0c7bc5240a0912affd115305b">failures_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a66f620b093f92e0def6bf5297fb6d6ee">micro_os_plus::micro_test_plus::detail::reporter_human::abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#aa8802baefcb360f48451418c783ac413">micro_os_plus::micro_test_plus::detail::reporter_tap::abort_session</a>, <a href="#a324aa273975068c140ab6eecc7e722c9">comment_prefix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#adf27b1d3d7cb168f295e4bf198bb0dbf">micro_os_plus::micro_test_plus::detail::reporter_human::commit_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#af80ba6907c9f13b08f8cb8726d65c510">micro_os_plus::micro_test_plus::detail::reporter_tap::commit_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a2d5ddae3195ab52a957927a1b455f7b8">micro_os_plus::micro_test_plus::detail::reporter_tap::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#ad15f7dbbf6a683441df40c502125adc3">micro_os_plus::micro_test_plus::detail::reporter_tap::end_test_case</a>.</p>

</div>
</div>

### commit\_buffer() {#a844e80839c81133b52ee3beabf64d942}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">virtual void micro_os_plus::micro_test_plus::detail::reporter::commit_buffer (void)</td>
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

<p>Writes the results buffered for the outer test case before a nested test case begins or is skipped.</p>


<p>The concrete reporters decide where the results are written, and with which verbosity levels; the buffer is cleared.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01086">1086</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<p>Reference <a href="#a5cf73aaf67484b50c25ef42363d49337">commit_outer_results</a>.</p>


<p>Referenced by <a href="#a5cf73aaf67484b50c25ef42363d49337">commit_outer_results</a>.</p>

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


<p>Called by <span class="doxyComputerOutput"><a href="#aa5f6b45879c1e0986ce4ebf9f374a182">begin_test_case()</a></span> and <span class="doxyComputerOutput"><a href="#a1986653001ad23e18de13822bbcd022f">skip_test_case()</a></span> of the concrete reporters, so that the output follows the execution order.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>For a nested test case, the outer test case may have performed checks before it; their results are written first, by <span class="doxyComputerOutput"><a href="#a844e80839c81133b52ee3beabf64d942">commit_buffer()</a></span>. For a top-level test case, the buffer is expected to be empty, since the checks are performed only by the test cases, and each one writes its results when it ends; should it not be, its content is written in the same way, rather than lost or attributed to the next test case, and the run continues.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01104">1104</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00956">956</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a5cf73aaf67484b50c25ef42363d49337">956</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a5cf73aaf67484b50c25ef42363d49337">reporter::commit_outer_results</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">957</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">958</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (!<a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>.empty ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">959</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">960</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a844e80839c81133b52ee3beabf64d942">commit_buffer</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">961</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">962</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a> and <a href="#a844e80839c81133b52ee3beabf64d942">commit_buffer</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a04cef97a62731931038355a1b5f23556">micro_os_plus::micro_test_plus::detail::reporter_human::begin_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a0302f9f5b977b05139d73df3bbc18d69">micro_os_plus::micro_test_plus::detail::reporter_tap::begin_test_case</a>, <a href="#a844e80839c81133b52ee3beabf64d942">commit_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af28ab5a9448645fb8976c0b139bf302b">micro_os_plus::micro_test_plus::detail::reporter_human::skip_test_case</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a31ccd7af941d06241ce16df9274abc38">micro_os_plus::micro_test_plus::detail::reporter_tap::skip_test_case</a>.</p>

</div>
</div>

### console\_lines() {#adb473d2a466c856bfe8151c7558383c1}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::string_view micro_os_plus::micro_test_plus::detail::reporter::console_lines (bool failed)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
<span class="doxyMemberLabel protected">protected</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Returns the buffered lines that the console displays when a test case or a suite ends, or when its results are committed.</p>


<p>With the verbose verbosity, all the buffered lines; with the normal verbosity, all the buffered lines of a failed test case or suite, otherwise none; with the quiet verbosity, only the lines of the failed checks; with the silent verbosity, none.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">failed</td>
<td class="doxyParamItemDescription"><p>Whether the test case or the suite failed, or, when committing the results of an outer test case, whether the buffer contains a failed check.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A view of <span class="doxyComputerOutput"><a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a></span> or of <span class="doxyComputerOutput"><a href="#ab8acd7e0c7bc5240a0912affd115305b">failures_</a></span>, valid until they are modified.</p></dd>
</dl>


<p>The quiet verbosity displays the failed checks, and the buffer may also contain the passed checks, for the output file; the lines of the failed checks are therefore kept separately, in <span class="doxyComputerOutput"><a href="#ab8acd7e0c7bc5240a0912affd115305b">failures_</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00812">812</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00302">302</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#adb473d2a466c856bfe8151c7558383c1">302</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#adb473d2a466c856bfe8151c7558383c1">reporter::console_lines</a> (</span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> failed) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">303</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">304</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">verbosity::verbose</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">305</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">306</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">307</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">308</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">verbosity::normal</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">309</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">310</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> failed ? std::string_view{ <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a> } : std::string_view{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">311</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">312</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba556966c7830465dc4623d62e32cec31d">verbosity::quiet</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">313</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">314</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#ab8acd7e0c7bc5240a0912affd115305b">failures_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">315</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">316</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> {};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">317</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>, <a href="#ab8acd7e0c7bc5240a0912affd115305b">failures_</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">micro_os_plus::micro_test_plus::normal</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba556966c7830465dc4623d62e32cec31d">micro_os_plus::micro_test_plus::quiet</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">micro_os_plus::micro_test_plus::verbose</a> and <a href="#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a66f620b093f92e0def6bf5297fb6d6ee">micro_os_plus::micro_test_plus::detail::reporter_human::abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#aa8802baefcb360f48451418c783ac413">micro_os_plus::micro_test_plus::detail::reporter_tap::abort_session</a>, <a href="#a324aa273975068c140ab6eecc7e722c9">comment_prefix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#adf27b1d3d7cb168f295e4bf198bb0dbf">micro_os_plus::micro_test_plus::detail::reporter_human::commit_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#af80ba6907c9f13b08f8cb8726d65c510">micro_os_plus::micro_test_plus::detail::reporter_tap::commit_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a2d5ddae3195ab52a957927a1b455f7b8">micro_os_plus::micro_test_plus::detail::reporter_tap::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#ad15f7dbbf6a683441df40c502125adc3">micro_os_plus::micro_test_plus::detail::reporter_tap::end_test_case</a>.</p>

</div>
</div>

### enter\_suite() {#a5ddd6ca6ce847ca89d7a3fcf9751f97d}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter::enter_suite (const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a> &amp; suite, bool displayed)</td>
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

<p>Notes the suite that begins, for the headings displayed later.</p>


<p>Called by <span class="doxyComputerOutput"><a href="#aceec705f3b14971e03701afb35a8feef">begin_suite()</a></span> of the concrete reporters, with the information whether the heading of the suite was displayed.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">suite</td>
<td class="doxyParamItemDescription"><p>The suite that begins.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">displayed</td>
<td class="doxyParamItemDescription"><p>Whether the heading was written to the console.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Records the suite and whether its heading was displayed; the quiet verbosity displays it later, if the suite has a failure.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00859">859</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00352">352</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a5ddd6ca6ce847ca89d7a3fcf9751f97d">352</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a5ddd6ca6ce847ca89d7a3fcf9751f97d">reporter::enter_suite</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>, </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> displayed)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">353</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">354</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#ad0a2ebe9aedaecf71fc76993122e661f">current_suite_</a> = &amp;<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">355</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a6b07e60aa8baeb90821690d1ff9c65e6">suite_displayed_</a> = displayed;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">356</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#ad0a2ebe9aedaecf71fc76993122e661f">current_suite_</a> and <a href="#a6b07e60aa8baeb90821690d1ff9c65e6">suite_displayed_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a58c85919422801369d1d4d9a8efe77d0">micro_os_plus::micro_test_plus::detail::reporter_human::begin_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a2c05a737bfe80c955a998dc801e964b5">micro_os_plus::micro_test_plus::detail::reporter_tap::begin_suite</a> and <a href="#a324aa273975068c140ab6eecc7e722c9">comment_prefix</a>.</p>

</div>
</div>

### mark\_failure() {#a2d5e5125b8c71fe0dedbe92d730647ec}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter::mark_failure (size_t begin)</td>
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

<p>Records that the lines appended to the buffer from a given position are a failure.</p>


<p>Sets <span class="doxyComputerOutput"><a href="#a970a08a00e70f1574033085350656230">buffer_has_failures_</a></span> and, with the quiet verbosity, which displays only the failures, copies the lines to <span class="doxyComputerOutput"><a href="#ab8acd7e0c7bc5240a0912affd115305b">failures_</a></span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">begin</td>
<td class="doxyParamItemDescription"><p>The position in <span class="doxyComputerOutput"><a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a></span> where the lines of the failure begin.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Only the quiet verbosity needs the copy, since the other levels display the buffer as a whole, or nothing.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00843">843</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00337">337</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a2d5e5125b8c71fe0dedbe92d730647ec">337</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a2d5e5125b8c71fe0dedbe92d730647ec">reporter::mark_failure</a> (</span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> begin)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">338</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">339</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba556966c7830465dc4623d62e32cec31d">verbosity::quiet</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">340</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">341</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#ab8acd7e0c7bc5240a0912affd115305b">failures_</a>.append (<a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>, begin, std::string::npos);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">342</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">343</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a970a08a00e70f1574033085350656230">buffer_has_failures_</a> = </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">344</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>, <a href="#a970a08a00e70f1574033085350656230">buffer_has_failures_</a>, <a href="#ab8acd7e0c7bc5240a0912affd115305b">failures_</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba556966c7830465dc4623d62e32cec31d">micro_os_plus::micro_test_plus::quiet</a> and <a href="#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a>.</p>


<p>Referenced by <a href="#a324aa273975068c140ab6eecc7e722c9">comment_prefix</a>, <a href="#a406cf77b7adcd5fe9417ce7bce4f3afb">fail</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#afd98d9a322823d67448d4ba301846392">micro_os_plus::micro_test_plus::detail::reporter_human::fail_suite</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a314df80e98fe6fa5de008d6708a14925">micro_os_plus::micro_test_plus::detail::reporter_tap::fail_suite</a>.</p>

</div>
</div>

### output\_fail\_prefix() {#a24888ee49f3e3abb1a849e309a099189}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">virtual void micro_os_plus::micro_test_plus::detail::reporter::output_fail_prefix (const std::string &amp; message, const bool has_expression, const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> &amp; location, const <a href="#a904f410e240644fa77d65e686e6fc3eb">test_case</a> &amp; test_case)</td>
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


<p>Called by <span class="doxyComputerOutput"><a href="#a406cf77b7adcd5fe9417ce7bce4f3afb">fail()</a></span> before the expression text; the prefix includes the message, if any, and the source location.</p>


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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01153">1153</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<p>Reference <a href="#a904f410e240644fa77d65e686e6fc3eb">micro_test_plus::test_case</a>.</p>


<p>Referenced by <a href="#a406cf77b7adcd5fe9417ce7bce4f3afb">fail</a>.</p>

</div>
</div>

### output\_fail\_suffix() {#adce64d6a989f193c1d0c306039a3639c}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">virtual void micro_os_plus::micro_test_plus::detail::reporter::output_fail_suffix (const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> &amp; location, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a0726a1bc3b6f16245cb8a4b42fe0e70c">check_kind</a> kind, const <a href="#a904f410e240644fa77d65e686e6fc3eb">test_case</a> &amp; test_case)</td>
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


<p>Called by <span class="doxyComputerOutput"><a href="#a406cf77b7adcd5fe9417ce7bce4f3afb">fail()</a></span> after the expression text, to complete the output. The kind of the check lets a reporter show that a failed requirement stops the test case, or aborts the test execution.</p>


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
<td class="doxyParamItemDescription"><p>The kind of the check (expectation or requirement).</p></td>
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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01174">1174</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<p>Reference <a href="#a904f410e240644fa77d65e686e6fc3eb">micro_test_plus::test_case</a>.</p>


<p>Referenced by <a href="#a406cf77b7adcd5fe9417ce7bce4f3afb">fail</a>.</p>

</div>
</div>

### output\_pass\_prefix() {#aede54e424adbe77bdb6b87d40f2d3517}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">virtual void micro_os_plus::micro_test_plus::detail::reporter::output_pass_prefix (const std::string &amp; message, const <a href="#a904f410e240644fa77d65e686e6fc3eb">test_case</a> &amp; test_case)</td>
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


<p>Called by <span class="doxyComputerOutput"><a href="#ad9e6ccebc1904f723409ddb0caaddb3e">pass()</a></span> before the expression text; the prefix includes the message, if any.</p>


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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01119">1119</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<p>Reference <a href="#a904f410e240644fa77d65e686e6fc3eb">micro_test_plus::test_case</a>.</p>


<p>Referenced by <a href="#ad9e6ccebc1904f723409ddb0caaddb3e">pass</a>.</p>

</div>
</div>

### output\_pass\_suffix() {#a82f4940bc3915b3fdcb58823f9bdb535}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">virtual void micro_os_plus::micro_test_plus::detail::reporter::output_pass_suffix (const <a href="#a904f410e240644fa77d65e686e6fc3eb">test_case</a> &amp; test_case)</td>
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


<p>Called by <span class="doxyComputerOutput"><a href="#ad9e6ccebc1904f723409ddb0caaddb3e">pass()</a></span> after the expression text, to complete the line.</p>


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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01134">1134</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<p>Reference <a href="#a904f410e240644fa77d65e686e6fc3eb">micro_test_plus::test_case</a>.</p>


<p>Referenced by <a href="#ad9e6ccebc1904f723409ddb0caaddb3e">pass</a>.</p>

</div>
</div>

### route() {#af33f2f6498a97383cdb75020e32ccf23}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">output_route micro_os_plus::micro_test_plus::detail::reporter::route (<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5">record_kind</a> kind)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
<span class="doxyMemberLabel protected">protected</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Tells where a kind of record is written.</p>


<p>The single place of the output policy. The output file receives all the records, whatever the verbosity, so that its content does not depend on the console. The console receives, with each verbosity level:</p>


<ul class="doxyList ">
<li><span class="doxyComputerOutput">silent</span>: nothing;</li>
<li><span class="doxyComputerOutput">quiet</span>: the failed checks, the failures of the suites, the totals, and the report of an aborted execution;</li>
<li><span class="doxyComputerOutput">normal</span>: in addition, the informational lines, the headings and results of the suites, the results of the test cases, and the skipped suites and test cases;</li>
<li><span class="doxyComputerOutput">verbose</span>: in addition, the headings of the test cases and the lines of the passed checks.</li>
</ul>

<p>The headings of the test cases that contain a failure are also displayed with the normal verbosity (see <span class="doxyComputerOutput"><a href="#adb473d2a466c856bfe8151c7558383c1">console_lines()</a></span>), but the passed checks are not; they are only counted, without being formatted (see <span class="doxyComputerOutput"><a href="#a0e6f0a129d495a7e9d57ef71412cd88f">writes_passed_checks()</a></span>). The concrete reporters adapt the quiet and normal levels to their format.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">kind</td>
<td class="doxyParamItemDescription"><p>The kind of record.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The destinations of the record.</p></dd>
</dl>


<p>The file receives all the records, when it is open, so that its content does not depend on the verbosity (a file of a <span class="doxyComputerOutput">silent</span> run is as complete as that of a <span class="doxyComputerOutput">verbose</span> one). The console follows the verbosity levels, as documented in the declaration.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00793">793</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00251">251</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#af33f2f6498a97383cdb75020e32ccf23">251</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#af33f2f6498a97383cdb75020e32ccf23">reporter::route</a> (<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5">record_kind</a> kind) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">252</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">253</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> console;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">254</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (kind == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5ae3a1f45168c36de6c9f4a81f84aaa640">record_kind::failed_check</a> || kind == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5afbb44b4487415b134bce9c790a27fe5e">record_kind::total</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">255</span><span class="doxyLineContent"><span class="doxyHighlight">        || kind == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5a5bb94a1c12413a2e5d14deabab29f2aa">record_kind::abort</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">256</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">257</span><span class="doxyLineContent"><span class="doxyHighlight">        console = (<a href="#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> != <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">verbosity::silent</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">258</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">259</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (kind == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5a50bcbe154487d5fbab186979293ec8f1">record_kind::test_case_heading</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">260</span><span class="doxyLineContent"><span class="doxyHighlight">             || kind == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5ad92bae248e3e6219914c8348b9b14a6e">record_kind::passed_check</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">261</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">262</span><span class="doxyLineContent"><span class="doxyHighlight">        console = (<a href="#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">verbosity::verbose</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">263</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">264</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_STARTUP_ENABLED) \</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">265</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">    &amp;&amp; defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">266</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (kind == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5acaf9b6b99962bf5c2264824231d7a40c">record_kind::info</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">267</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">268</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// The startup code already displays this information.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">269</span><span class="doxyLineContent"><span class="doxyHighlight">        console = </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">270</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">271</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(MICRO_OS_PLUS_STARTUP_ENABLED) &amp;&amp; ...</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">272</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">273</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">274</span><span class="doxyLineContent"><span class="doxyHighlight">        console = (<a href="#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">verbosity::normal</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">275</span><span class="doxyLineContent"><span class="doxyHighlight">                   || <a href="#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">verbosity::verbose</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">276</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">277</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">278</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> { console, <a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight"> };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">279</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5a5bb94a1c12413a2e5d14deabab29f2aa">micro_os_plus::micro_test_plus::detail::abort</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5ae3a1f45168c36de6c9f4a81f84aaa640">micro_os_plus::micro_test_plus::detail::failed_check</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5acaf9b6b99962bf5c2264824231d7a40c">micro_os_plus::micro_test_plus::detail::info</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">micro_os_plus::micro_test_plus::normal</a>, <a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5ad92bae248e3e6219914c8348b9b14a6e">micro_os_plus::micro_test_plus::detail::passed_check</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">micro_os_plus::micro_test_plus::silent</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5a50bcbe154487d5fbab186979293ec8f1">micro_os_plus::micro_test_plus::detail::test_case_heading</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5afbb44b4487415b134bce9c790a27fe5e">micro_os_plus::micro_test_plus::detail::total</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">micro_os_plus::micro_test_plus::verbose</a> and <a href="#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a66f620b093f92e0def6bf5297fb6d6ee">micro_os_plus::micro_test_plus::detail::reporter_human::abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#aa8802baefcb360f48451418c783ac413">micro_os_plus::micro_test_plus::detail::reporter_tap::abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#aa3cefeb72e745b2424b48ed4a31102e7">micro_os_plus::micro_test_plus::detail::reporter_human::begin_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#acaae91eea2deed1fe3f43b6453e7e656">micro_os_plus::micro_test_plus::detail::reporter_tap::begin_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a58c85919422801369d1d4d9a8efe77d0">micro_os_plus::micro_test_plus::detail::reporter_human::begin_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a2c05a737bfe80c955a998dc801e964b5">micro_os_plus::micro_test_plus::detail::reporter_tap::begin_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a04cef97a62731931038355a1b5f23556">micro_os_plus::micro_test_plus::detail::reporter_human::begin_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a0302f9f5b977b05139d73df3bbc18d69">micro_os_plus::micro_test_plus::detail::reporter_tap::begin_test_case</a>, <a href="#a324aa273975068c140ab6eecc7e722c9">comment_prefix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#adf27b1d3d7cb168f295e4bf198bb0dbf">micro_os_plus::micro_test_plus::detail::reporter_human::commit_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#af80ba6907c9f13b08f8cb8726d65c510">micro_os_plus::micro_test_plus::detail::reporter_tap::commit_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ace9c2dfffc49a97516b96dacaf87b943">micro_os_plus::micro_test_plus::detail::reporter_human::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a7033819609bfad2db2ecc7a024e91b2c">micro_os_plus::micro_test_plus::detail::reporter_tap::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a2d5ddae3195ab52a957927a1b455f7b8">micro_os_plus::micro_test_plus::detail::reporter_tap::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#ad15f7dbbf6a683441df40c502125adc3">micro_os_plus::micro_test_plus::detail::reporter_tap::end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#aca37d52611ed87d102dce89c3c6cc99d">micro_os_plus::micro_test_plus::detail::reporter_human::skip_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a319f35d4af8c72af8b14a89b421c1c74">micro_os_plus::micro_test_plus::detail::reporter_tap::skip_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af28ab5a9448645fb8976c0b139bf302b">micro_os_plus::micro_test_plus::detail::reporter_human::skip_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a31ccd7af941d06241ce16df9274abc38">micro_os_plus::micro_test_plus::detail::reporter_tap::skip_test_case</a> and <a href="#aeafdc8e05a6d80d9445f17ff354ee215">write_info</a>.</p>

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


<p>Writes the contents of <span class="doxyComputerOutput"><a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a></span> to <span class="doxyComputerOutput"><a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a></span> without appending a newline. If <span class="doxyComputerOutput"><a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a></span> is null, the call is a no-op.</p>


<p>The buffer may contain ANSI colour sequences, added when the console is a terminal, which must not reach the file; they are removed by <span class="doxyComputerOutput">write_without_colours()</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00764">764</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00368">368</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a37cba38a47d66a928a936ee081c6d88c">368</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a37cba38a47d66a928a936ee081c6d88c">reporter::write_buffer_to_file</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">369</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">370</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> == </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">371</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">372</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">373</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">374</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">375</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Pass only the string, do not add an `\n` here.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">376</span><span class="doxyLineContent"><span class="doxyHighlight">    write_without_colours (<a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a>, <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">377</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a> and <a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a66f620b093f92e0def6bf5297fb6d6ee">micro_os_plus::micro_test_plus::detail::reporter_human::abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#aa8802baefcb360f48451418c783ac413">micro_os_plus::micro_test_plus::detail::reporter_tap::abort_session</a>, <a href="#a324aa273975068c140ab6eecc7e722c9">comment_prefix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#adf27b1d3d7cb168f295e4bf198bb0dbf">micro_os_plus::micro_test_plus::detail::reporter_human::commit_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#af80ba6907c9f13b08f8cb8726d65c510">micro_os_plus::micro_test_plus::detail::reporter_tap::commit_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a2d5ddae3195ab52a957927a1b455f7b8">micro_os_plus::micro_test_plus::detail::reporter_tap::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#ad15f7dbbf6a683441df40c502125adc3">micro_os_plus::micro_test_plus::detail::reporter_tap::end_test_case</a>.</p>

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


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00877">877</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00387">387</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#abaee31ffca8e65c9af34f7f67227c5b3">387</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#abaee31ffca8e65c9af34f7f67227c5b3">reporter::write_console</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* format, ...)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">388</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">389</span><span class="doxyLineContent"><span class="doxyHighlight">    va_list args;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">390</span><span class="doxyLineContent"><span class="doxyHighlight">    va_start (args, format);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">391</span><span class="doxyLineContent"><span class="doxyHighlight">    vfprintf (stdout, format, args);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">392</span><span class="doxyLineContent"><span class="doxyHighlight">    va_end (args);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">393</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Referenced by <a href="#a5b6052e6c28235b76d855b2b7bc176dd">~reporter</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a66f620b093f92e0def6bf5297fb6d6ee">micro_os_plus::micro_test_plus::detail::reporter_human::abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#aa8802baefcb360f48451418c783ac413">micro_os_plus::micro_test_plus::detail::reporter_tap::abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#aa3cefeb72e745b2424b48ed4a31102e7">micro_os_plus::micro_test_plus::detail::reporter_human::begin_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#acaae91eea2deed1fe3f43b6453e7e656">micro_os_plus::micro_test_plus::detail::reporter_tap::begin_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a58c85919422801369d1d4d9a8efe77d0">micro_os_plus::micro_test_plus::detail::reporter_human::begin_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a2c05a737bfe80c955a998dc801e964b5">micro_os_plus::micro_test_plus::detail::reporter_tap::begin_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a04cef97a62731931038355a1b5f23556">micro_os_plus::micro_test_plus::detail::reporter_human::begin_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a0302f9f5b977b05139d73df3bbc18d69">micro_os_plus::micro_test_plus::detail::reporter_tap::begin_test_case</a>, <a href="#a324aa273975068c140ab6eecc7e722c9">comment_prefix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#adf27b1d3d7cb168f295e4bf198bb0dbf">micro_os_plus::micro_test_plus::detail::reporter_human::commit_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#af80ba6907c9f13b08f8cb8726d65c510">micro_os_plus::micro_test_plus::detail::reporter_tap::commit_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#aec7a63f892ff631e659c28607bf31242">micro_os_plus::micro_test_plus::detail::reporter_tap::display_open_headers</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#abcfa63d8c5ca8acd458383102b7e99e9">micro_os_plus::micro_test_plus::detail::reporter_human::display_open_names</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ace9c2dfffc49a97516b96dacaf87b943">micro_os_plus::micro_test_plus::detail::reporter_human::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a7033819609bfad2db2ecc7a024e91b2c">micro_os_plus::micro_test_plus::detail::reporter_tap::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a2d5ddae3195ab52a957927a1b455f7b8">micro_os_plus::micro_test_plus::detail::reporter_tap::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#ad15f7dbbf6a683441df40c502125adc3">micro_os_plus::micro_test_plus::detail::reporter_tap::end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#aca37d52611ed87d102dce89c3c6cc99d">micro_os_plus::micro_test_plus::detail::reporter_human::skip_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a319f35d4af8c72af8b14a89b421c1c74">micro_os_plus::micro_test_plus::detail::reporter_tap::skip_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af28ab5a9448645fb8976c0b139bf302b">micro_os_plus::micro_test_plus::detail::reporter_human::skip_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a31ccd7af941d06241ce16df9274abc38">micro_os_plus::micro_test_plus::detail::reporter_tap::skip_test_case</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a637a7a94e8ba373203339489a160b322">micro_os_plus::micro_test_plus::detail::reporter_tap::write_quiet_failures</a>.</p>

</div>
</div>

### write\_console\_text() {#a887f23131eb91fecf060982dcbd3b1ca}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter::write_console_text (std::string_view text)</td>
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

<p>Writes a text to the console, unchanged.</p>


<p>The text is written with its size, not as a C string, so that a zero character in a message does not end the output. No line ending is appended.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">text</td>
<td class="doxyParamItemDescription"><p>The text to write.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>The text is written with its size, not as a C string, so that a zero character in a message does not end the output.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00827">827</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00325">325</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a887f23131eb91fecf060982dcbd3b1ca">325</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a887f23131eb91fecf060982dcbd3b1ca">reporter::write_console_text</a> (std::string_view text)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">326</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">327</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Pass only the text, do not add an `\n` here.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">328</span><span class="doxyLineContent"><span class="doxyHighlight">    fwrite (text.data (), 1, text.size (), stdout);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">329</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a66f620b093f92e0def6bf5297fb6d6ee">micro_os_plus::micro_test_plus::detail::reporter_human::abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#aa8802baefcb360f48451418c783ac413">micro_os_plus::micro_test_plus::detail::reporter_tap::abort_session</a>, <a href="#a324aa273975068c140ab6eecc7e722c9">comment_prefix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#adf27b1d3d7cb168f295e4bf198bb0dbf">micro_os_plus::micro_test_plus::detail::reporter_human::commit_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#af80ba6907c9f13b08f8cb8726d65c510">micro_os_plus::micro_test_plus::detail::reporter_tap::commit_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a2d5ddae3195ab52a957927a1b455f7b8">micro_os_plus::micro_test_plus::detail::reporter_tap::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#ad15f7dbbf6a683441df40c502125adc3">micro_os_plus::micro_test_plus::detail::reporter_tap::end_test_case</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a637a7a94e8ba373203339489a160b322">micro_os_plus::micro_test_plus::detail::reporter_tap::write_quiet_failures</a>.</p>

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


<p>If no output file is open, the call has no effect, so callers do not need to check <span class="doxyComputerOutput"><a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a></span> themselves.</p>


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


<p>The arguments are forwarded to <span class="doxyComputerOutput">vfprintf()</span> on <span class="doxyComputerOutput"><a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a></span>. If <span class="doxyComputerOutput"><a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a></span> is null, the arguments are ignored.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00896">896</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00401">401</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a90a541c6a9b1ddd3da9440358bfc704e">401</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a90a541c6a9b1ddd3da9440358bfc704e">reporter::write_file</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* format, ...)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">402</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">403</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> == </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">404</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">405</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">406</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">407</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">408</span><span class="doxyLineContent"><span class="doxyHighlight">    va_list args;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">409</span><span class="doxyLineContent"><span class="doxyHighlight">    va_start (args, format);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">410</span><span class="doxyLineContent"><span class="doxyHighlight">    vfprintf (<a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a>, format, args);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">411</span><span class="doxyLineContent"><span class="doxyHighlight">    va_end (args);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">412</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a>.</p>


<p>Referenced by <a href="#a324aa273975068c140ab6eecc7e722c9">comment_prefix</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#ad15f7dbbf6a683441df40c502125adc3">micro_os_plus::micro_test_plus::detail::reporter_tap::end_test_case</a>.</p>

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


<p>Constructs and emits two informational lines, each prefixed by <span class="doxyComputerOutput"><a href="#a324aa273975068c140ab6eecc7e722c9">comment_prefix()</a></span>: the first lists the program name (without the path) and any command-line arguments; the second identifies the compiler (Clang, GCC, or MSVC) together with the version string, floating-point availability on bare-metal targets, exception support, and any active debug or trace macros. Both lines are written to the output file when one is open, and to <span class="doxyComputerOutput">stdout</span> when the verbosity is <span class="doxyComputerOutput">normal</span> or <span class="doxyComputerOutput">verbose</span> (see <span class="doxyComputerOutput"><a href="#af33f2f6498a97383cdb75020e32ccf23">route()</a></span>), except when both <span class="doxyComputerOutput">MICRO_OS_PLUS_STARTUP_ENABLED</span> and <span class="doxyComputerOutput">MICRO_OS_PLUS_DIAG_TRACE_ENABLED</span> are defined, since the startup code already displays this information.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00939">939</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00490">490</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aeafdc8e05a6d80d9445f17ff354ee215">490</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#aeafdc8e05a6d80d9445f17ff354ee215">reporter::write_info</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">491</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">492</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> to_console = <a href="#af33f2f6498a97383cdb75020e32ccf23">route</a> (<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5acaf9b6b99962bf5c2264824231d7a40c">record_kind::info</a>).<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/output-route/#a5ffc75b90c3290f21a2126bba91a759a">console</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">493</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">494</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (!<a href="#a3e47f2c530c5019bde9fe56867bc581f">arguments_</a>.empty ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">495</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">496</span><span class="doxyLineContent"><span class="doxyHighlight">        std::string line;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">497</span><span class="doxyLineContent"><span class="doxyHighlight">        line.reserve (256);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">498</span><span class="doxyLineContent"><span class="doxyHighlight">        line.append (<a href="#a324aa273975068c140ab6eecc7e722c9">comment_prefix</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">499</span><span class="doxyLineContent"><span class="doxyHighlight">        line.append (</span><span class="doxyHighlightStringLiteral">"Running: "</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">500</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">501</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// Append only the file name part of argv[0].</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">502</span><span class="doxyLineContent"><span class="doxyHighlight">        line.append (<a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-utility-functions/#ga791f22f0c85b6436c9016821907b0653">utility::extract_file_name</a> (<a href="#a3e47f2c530c5019bde9fe56867bc581f">arguments_</a>[0]));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">503</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">504</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* argument : <a href="#a3e47f2c530c5019bde9fe56867bc581f">arguments_</a>.subspan (1))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">505</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">506</span><span class="doxyLineContent"><span class="doxyHighlight">            line.append (</span><span class="doxyHighlightStringLiteral">" "</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">507</span><span class="doxyLineContent"><span class="doxyHighlight">            line.append (argument);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">508</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">509</span><span class="doxyLineContent"><span class="doxyHighlight">        line.append (</span><span class="doxyHighlightStringLiteral">"\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">510</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">511</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#aa97f2ba65009154090dc68e42c94db71">write_line</a> (to_console, </span><span class="doxyHighlightStringLiteral">"%s"</span><span class="doxyHighlight">, line.c_str ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">512</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">513</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">514</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">515</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// Build the "Built with ..." line, including the compiler version</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">516</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// (via __VERSION__); the same line goes to the file and to stdout.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">517</span><span class="doxyLineContent"><span class="doxyHighlight">      std::string line;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">518</span><span class="doxyLineContent"><span class="doxyHighlight">      line.reserve (256);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">519</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (<a href="#a324aa273975068c140ab6eecc7e722c9">comment_prefix</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">520</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">"Built with "</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">521</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">522</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">"clang "</span><span class="doxyHighlight"> __VERSION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">523</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#elif defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">524</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">"GCC "</span><span class="doxyHighlight"> __VERSION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">525</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#elif defined(_MSC_VER)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">526</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">"MSVC"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">527</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> msvc_ver[16];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">528</span><span class="doxyLineContent"><span class="doxyHighlight">      snprintf (msvc_ver, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (msvc_ver), </span><span class="doxyHighlightStringLiteral">" - %d"</span><span class="doxyHighlight">, _MSC_VER);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">529</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (msvc_ver);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">530</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">531</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">"an unknown compiler"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">532</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">533</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if !(defined(__APPLE__) || defined(__linux__) || defined(__unix__) \</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">534</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">      || defined(_WIN32))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">535</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// This is relevant only on bare-metal.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">536</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__ARM_PCS_VFP) || defined(__ARM_FP)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">537</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">", with FP"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">538</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">539</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">", no FP"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">540</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__ARM_PCS_VFP) || defined(__ARM_FP)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">541</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// bare-metal only</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">542</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__cpp_exceptions)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">543</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">", with exceptions"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">544</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">545</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">", no exceptions"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">546</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__cpp_exceptions)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">547</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_DEBUG_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">548</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">", with MICRO_OS_PLUS_DEBUG_ENABLED"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">549</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(MICRO_OS_PLUS_DEBUG_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">550</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">551</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">", with MICRO_OS_PLUS_DIAG_TRACE_ENABLED"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">552</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">553</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">554</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="#aa97f2ba65009154090dc68e42c94db71">write_line</a> (to_console, </span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, line.c_str ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">555</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">556</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a3e47f2c530c5019bde9fe56867bc581f">arguments_</a>, <a href="#a324aa273975068c140ab6eecc7e722c9">comment_prefix</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/output-route/#a5ffc75b90c3290f21a2126bba91a759a">micro_os_plus::micro_test_plus::detail::output_route::console</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-utility-functions/#ga791f22f0c85b6436c9016821907b0653">micro_os_plus::micro_test_plus::utility::extract_file_name</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5acaf9b6b99962bf5c2264824231d7a40c">micro_os_plus::micro_test_plus::detail::info</a>, <a href="#af33f2f6498a97383cdb75020e32ccf23">route</a> and <a href="#aa97f2ba65009154090dc68e42c94db71">write_line</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#aa3cefeb72e745b2424b48ed4a31102e7">micro_os_plus::micro_test_plus::detail::reporter_human::begin_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#acaae91eea2deed1fe3f43b6453e7e656">micro_os_plus::micro_test_plus::detail::reporter_tap::begin_session</a> and <a href="#a324aa273975068c140ab6eecc7e722c9">comment_prefix</a>.</p>

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


<p>The text is formatted once, and the same text is written to the output file, if open, and, when <span class="doxyComputerOutput">to_console</span> is true, to <span class="doxyComputerOutput">stdout</span>. As in <span class="doxyComputerOutput"><a href="#a37cba38a47d66a928a936ee081c6d88c">write_buffer_to_file()</a></span>, the ANSI colour sequences are removed from the file copy, so a console line with colours and its plain file line are written by one call. The format normally ends with a line ending; any empty line or buffered output that precedes the console line is written by the caller, before this call.</p>


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


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00923">923</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00428">428</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aa97f2ba65009154090dc68e42c94db71">428</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#aa97f2ba65009154090dc68e42c94db71">reporter::write_line</a> (</span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> to_console, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* format, ...)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">429</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">430</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> == </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight"> &amp;&amp; !to_console)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">431</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">432</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">433</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">434</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">435</span><span class="doxyLineContent"><span class="doxyHighlight">    va_list args;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">436</span><span class="doxyLineContent"><span class="doxyHighlight">    va_start (args, format);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">437</span><span class="doxyLineContent"><span class="doxyHighlight">    va_list args_copy;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">438</span><span class="doxyLineContent"><span class="doxyHighlight">    va_copy (args_copy, args);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">439</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">440</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> local_text[128];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">441</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> length</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">442</span><span class="doxyLineContent"><span class="doxyHighlight">        = vsnprintf (local_text, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (local_text), format, args);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">443</span><span class="doxyLineContent"><span class="doxyHighlight">    va_end (args);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">444</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">445</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (length &lt; 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">446</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">447</span><span class="doxyLineContent"><span class="doxyHighlight">        va_end (args_copy);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">448</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">449</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">450</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">451</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> size = </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (length);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">452</span><span class="doxyLineContent"><span class="doxyHighlight">    std::string long_text;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">453</span><span class="doxyLineContent"><span class="doxyHighlight">    std::string_view text{ local_text, size };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">454</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (size &gt;= </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (local_text))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">455</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">456</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// The terminating null character is written over the one kept by</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">457</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// the string after its content.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">458</span><span class="doxyLineContent"><span class="doxyHighlight">        long_text.resize (size);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">459</span><span class="doxyLineContent"><span class="doxyHighlight">        vsnprintf (long_text.data (), size + 1, format, args_copy);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">460</span><span class="doxyLineContent"><span class="doxyHighlight">        text = long_text;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">461</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">462</span><span class="doxyLineContent"><span class="doxyHighlight">    va_end (args_copy);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">463</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">464</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">465</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">466</span><span class="doxyLineContent"><span class="doxyHighlight">        write_without_colours (<a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a>, text);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">467</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">468</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">469</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (to_console)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">470</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">471</span><span class="doxyLineContent"><span class="doxyHighlight">        fwrite (text.data (), 1, text.size (), stdout);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">472</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">473</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a66f620b093f92e0def6bf5297fb6d6ee">micro_os_plus::micro_test_plus::detail::reporter_human::abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#aa8802baefcb360f48451418c783ac413">micro_os_plus::micro_test_plus::detail::reporter_tap::abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#aa3cefeb72e745b2424b48ed4a31102e7">micro_os_plus::micro_test_plus::detail::reporter_human::begin_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#acaae91eea2deed1fe3f43b6453e7e656">micro_os_plus::micro_test_plus::detail::reporter_tap::begin_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a58c85919422801369d1d4d9a8efe77d0">micro_os_plus::micro_test_plus::detail::reporter_human::begin_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a2c05a737bfe80c955a998dc801e964b5">micro_os_plus::micro_test_plus::detail::reporter_tap::begin_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a04cef97a62731931038355a1b5f23556">micro_os_plus::micro_test_plus::detail::reporter_human::begin_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a0302f9f5b977b05139d73df3bbc18d69">micro_os_plus::micro_test_plus::detail::reporter_tap::begin_test_case</a>, <a href="#a324aa273975068c140ab6eecc7e722c9">comment_prefix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ace9c2dfffc49a97516b96dacaf87b943">micro_os_plus::micro_test_plus::detail::reporter_human::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a7033819609bfad2db2ecc7a024e91b2c">micro_os_plus::micro_test_plus::detail::reporter_tap::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a2d5ddae3195ab52a957927a1b455f7b8">micro_os_plus::micro_test_plus::detail::reporter_tap::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#ad15f7dbbf6a683441df40c502125adc3">micro_os_plus::micro_test_plus::detail::reporter_tap::end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#aca37d52611ed87d102dce89c3c6cc99d">micro_os_plus::micro_test_plus::detail::reporter_human::skip_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a319f35d4af8c72af8b14a89b421c1c74">micro_os_plus::micro_test_plus::detail::reporter_tap::skip_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af28ab5a9448645fb8976c0b139bf302b">micro_os_plus::micro_test_plus::detail::reporter_human::skip_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a31ccd7af941d06241ce16df9274abc38">micro_os_plus::micro_test_plus::detail::reporter_tap::skip_test_case</a> and <a href="#aeafdc8e05a6d80d9445f17ff354ee215">write_info</a>.</p>

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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01318">1318</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a38252f2ef24feabcb7f55e7bdac30bd2">1318</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="#a38252f2ef24feabcb7f55e7bdac30bd2">add_empty_line_</a>{ </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight"> };</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a66f620b093f92e0def6bf5297fb6d6ee">micro_os_plus::micro_test_plus::detail::reporter_human::abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#aa8802baefcb360f48451418c783ac413">micro_os_plus::micro_test_plus::detail::reporter_tap::abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#aa3cefeb72e745b2424b48ed4a31102e7">micro_os_plus::micro_test_plus::detail::reporter_human::begin_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#acaae91eea2deed1fe3f43b6453e7e656">micro_os_plus::micro_test_plus::detail::reporter_tap::begin_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a58c85919422801369d1d4d9a8efe77d0">micro_os_plus::micro_test_plus::detail::reporter_human::begin_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a2c05a737bfe80c955a998dc801e964b5">micro_os_plus::micro_test_plus::detail::reporter_tap::begin_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a04cef97a62731931038355a1b5f23556">micro_os_plus::micro_test_plus::detail::reporter_human::begin_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a0302f9f5b977b05139d73df3bbc18d69">micro_os_plus::micro_test_plus::detail::reporter_tap::begin_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#adf27b1d3d7cb168f295e4bf198bb0dbf">micro_os_plus::micro_test_plus::detail::reporter_human::commit_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#af80ba6907c9f13b08f8cb8726d65c510">micro_os_plus::micro_test_plus::detail::reporter_tap::commit_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#aec7a63f892ff631e659c28607bf31242">micro_os_plus::micro_test_plus::detail::reporter_tap::display_open_headers</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#abcfa63d8c5ca8acd458383102b7e99e9">micro_os_plus::micro_test_plus::detail::reporter_human::display_open_names</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ace9c2dfffc49a97516b96dacaf87b943">micro_os_plus::micro_test_plus::detail::reporter_human::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a7033819609bfad2db2ecc7a024e91b2c">micro_os_plus::micro_test_plus::detail::reporter_tap::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a2d5ddae3195ab52a957927a1b455f7b8">micro_os_plus::micro_test_plus::detail::reporter_tap::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#ad15f7dbbf6a683441df40c502125adc3">micro_os_plus::micro_test_plus::detail::reporter_tap::end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#aca37d52611ed87d102dce89c3c6cc99d">micro_os_plus::micro_test_plus::detail::reporter_human::skip_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a319f35d4af8c72af8b14a89b421c1c74">micro_os_plus::micro_test_plus::detail::reporter_tap::skip_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af28ab5a9448645fb8976c0b139bf302b">micro_os_plus::micro_test_plus::detail::reporter_human::skip_test_case</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a31ccd7af941d06241ce16df9274abc38">micro_os_plus::micro_test_plus::detail::reporter_tap::skip_test_case</a>.</p>

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


<p>A view of the <span class="doxyComputerOutput">argv[]</span> array of <span class="doxyComputerOutput">main()</span>, copied from the session options by the constructor, and listed by <span class="doxyComputerOutput"><a href="#aeafdc8e05a6d80d9445f17ff354ee215">write_info()</a></span>, which is called only by <span class="doxyComputerOutput"><a href="#a00e5e3b4f1ddfeeff6deb614d120caef">begin_session()</a></span>, within <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#acfabd0e10d233ad305b6f4fc125a97f2">runner::initialise()</a></span>; it is not used afterwards.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01359">1359</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a3e47f2c530c5019bde9fe56867bc581f">1359</a></span><span class="doxyLineContent"><span class="doxyHighlight">      std::span&lt;char* const&gt; <a href="#a3e47f2c530c5019bde9fe56867bc581f">arguments_</a>{};</span></span></div>

</div>


<p>Referenced by <a href="#a7e04bcbd0745543c604fdd975829175a">reporter</a> and <a href="#aeafdc8e05a6d80d9445f17ff354ee215">write_info</a>.</p>

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


<p>Accumulates all reporter output until it is written to the console or the output file via <span class="doxyComputerOutput"><a href="#a887f23131eb91fecf060982dcbd3b1ca">write_console_text()</a></span> or <span class="doxyComputerOutput"><a href="#a37cba38a47d66a928a936ee081c6d88c">write_buffer_to_file()</a></span>.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01217">1217</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a0972f104175c075295a8aa385e90aad4">1217</a></span><span class="doxyLineContent"><span class="doxyHighlight">      std::string <a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a>{};</span></span></div>

</div>


<p>Referenced by <a href="#a7e04bcbd0745543c604fdd975829175a">reporter</a>, <a href="#a5859ce31641330b243cfb5d1c6080859">clear_buffer</a>, <a href="#a5cf73aaf67484b50c25ef42363d49337">commit_outer_results</a>, <a href="#adb473d2a466c856bfe8151c7558383c1">console_lines</a>, <a href="#a287bad0e5eccee7df4a2c8517959bd0e">end_line</a>, <a href="#a406cf77b7adcd5fe9417ce7bce4f3afb">fail</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#afd98d9a322823d67448d4ba301846392">micro_os_plus::micro_test_plus::detail::reporter_human::fail_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a314df80e98fe6fa5de008d6708a14925">micro_os_plus::micro_test_plus::detail::reporter_tap::fail_suite</a>, <a href="#a2d5e5125b8c71fe0dedbe92d730647ec">mark_failure</a>, <a href="#acbdac50fb2a1302e4a97c8160e7fd7cb">operator&lt;&lt;</a>, <a href="#a5d29d78c80c20d3fe96ac9d0f4a969b3">operator&lt;&lt;</a>, <a href="#ad84ba0969733f2120622d26951259f95">operator&lt;&lt;</a>, <a href="#aedfa17028026f6eaa871214da441e90c">operator&lt;&lt;</a>, <a href="#ac894cb9cbf11f2f57acb388310eede4c">operator&lt;&lt;</a>, <a href="#a54158cb2ca77354223506355247cab9a">operator&lt;&lt;</a>, <a href="#a3ff526c7ae5db0669d7db2adebf7cb2d">operator&lt;&lt;</a>, <a href="#a0cdaf2313f78a256b80f7bb7b279e2e6">operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a3bd1c7d455abc782062d0e23a3ef1015">micro_os_plus::micro_test_plus::detail::reporter_tap::output_fail_prefix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#aaea110287f115fbaf80b0248f724c5b6">micro_os_plus::micro_test_plus::detail::reporter_tap::output_fail_suffix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#ac6c05f92e47ad71f72b44f9beb0b98f1">micro_os_plus::micro_test_plus::detail::reporter_tap::output_pass_prefix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a37c4235afdd9b704fd65d25d130bee86">micro_os_plus::micro_test_plus::detail::reporter_tap::output_pass_suffix</a> and <a href="#a37cba38a47d66a928a936ee081c6d88c">write_buffer_to_file</a>.</p>

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


<p>Set by <span class="doxyComputerOutput"><a href="#a406cf77b7adcd5fe9417ce7bce4f3afb">fail()</a></span> and reset by <span class="doxyComputerOutput"><a href="#a5859ce31641330b243cfb5d1c6080859">clear_buffer()</a></span>. When a nested test case begins, the concrete reporters use it to decide whether the results already buffered for the outer test case are displayed with normal verbosity.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01228">1228</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a970a08a00e70f1574033085350656230">1228</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="#a970a08a00e70f1574033085350656230">buffer_has_failures_</a>{ </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight"> };</span></span></div>

</div>


<p>Referenced by <a href="#a5859ce31641330b243cfb5d1c6080859">clear_buffer</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#adf27b1d3d7cb168f295e4bf198bb0dbf">micro_os_plus::micro_test_plus::detail::reporter_human::commit_buffer</a> and <a href="#a2d5e5125b8c71fe0dedbe92d730647ec">mark_failure</a>.</p>

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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01207">1207</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a69616e251ebb3d22e481ada0831bec3c">1207</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a> <a href="#a69616e251ebb3d22e481ada0831bec3c">colours_</a>{};</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a82221fa355584dbaa75c7e66fbefa6b8">micro_os_plus::micro_test_plus::detail::reporter_human::reporter_human</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a66f620b093f92e0def6bf5297fb6d6ee">micro_os_plus::micro_test_plus::detail::reporter_human::abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ace9c2dfffc49a97516b96dacaf87b943">micro_os_plus::micro_test_plus::detail::reporter_human::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#afd98d9a322823d67448d4ba301846392">micro_os_plus::micro_test_plus::detail::reporter_human::fail_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a032be7e38aad40c8bc44b2376ad90e29">micro_os_plus::micro_test_plus::detail::reporter_human::output_fail_prefix</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a043919044274838f8030d53630e3b1f5">micro_os_plus::micro_test_plus::detail::reporter_human::output_pass_prefix</a>.</p>

</div>
</div>

### current\_suite\_ {#ad0a2ebe9aedaecf71fc76993122e661f}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const suite* micro_os_plus::micro_test_plus::detail::reporter::current_suite_ { nullptr }</td>
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

<p>The suite that has begun and not yet ended.</p>


<p>Set by <span class="doxyComputerOutput"><a href="#a5ddd6ca6ce847ca89d7a3fcf9751f97d">enter_suite()</a></span>; null outside the suites.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01283">1283</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ad0a2ebe9aedaecf71fc76993122e661f">1283</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>* <a href="#ad0a2ebe9aedaecf71fc76993122e661f">current_suite_</a>{ </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight"> };</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a66f620b093f92e0def6bf5297fb6d6ee">micro_os_plus::micro_test_plus::detail::reporter_human::abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#aa8802baefcb360f48451418c783ac413">micro_os_plus::micro_test_plus::detail::reporter_tap::abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#abcfa63d8c5ca8acd458383102b7e99e9">micro_os_plus::micro_test_plus::detail::reporter_human::display_open_names</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a2d5ddae3195ab52a957927a1b455f7b8">micro_os_plus::micro_test_plus::detail::reporter_tap::end_suite</a>, <a href="#a5ddd6ca6ce847ca89d7a3fcf9751f97d">enter_suite</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a637a7a94e8ba373203339489a160b322">micro_os_plus::micro_test_plus::detail::reporter_tap::write_quiet_failures</a>.</p>

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
<td class="doxyMemberName">expression_formatter micro_os_plus::micro_test_plus::detail::reporter::expression_ { <a href="#a69616e251ebb3d22e481ada0831bec3c">colours_</a> }</td>
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


<p>Used by the checks (<span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-expectations/#gaf4f5f9632b5a290c1894984661a41a86">test_case::expect()</a></span>, <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-requirements/#gace68a1bd4dd258082f4b1fc01fcd008a">test_case::require()</a></span>, and <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">detail::check_result</a></span>), which are friends, to pre-format expressions at construction time; <span class="doxyComputerOutput"><a href="#ad9e6ccebc1904f723409ddb0caaddb3e">pass()</a></span> and <span class="doxyComputerOutput"><a href="#a406cf77b7adcd5fe9417ce7bce4f3afb">fail()</a></span> then append the formatted text to <span class="doxyComputerOutput"><a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a></span>. The applications format their own types by defining <span class="doxyComputerOutput">operator&lt;&lt;</span> for the public <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter">expression_formatter</a></span> alias.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01307">1307</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ac928cbe8852ca0c0273482b905c6301b">1307</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter">expression_formatter</a> <a href="#ac928cbe8852ca0c0273482b905c6301b">expression_</a>{ <a href="#a69616e251ebb3d22e481ada0831bec3c">colours_</a> };</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-expectations/#gaf4f5f9632b5a290c1894984661a41a86">micro_os_plus::micro_test_plus::test_case::expect</a> and <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-requirements/#gace68a1bd4dd258082f4b1fc01fcd008a">micro_os_plus::micro_test_plus::test_case::require</a>.</p>

</div>
</div>

### failures\_ {#ab8acd7e0c7bc5240a0912affd115305b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::string micro_os_plus::micro_test_plus::detail::reporter::failures_ {}</td>
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

<p>The lines of the failed checks, for the quiet verbosity.</p>


<p>With the quiet verbosity, the console displays only the failed checks, while <span class="doxyComputerOutput"><a href="#a0972f104175c075295a8aa385e90aad4">buffer_</a></span> may also contain the passed checks, for the output file. Filled by <span class="doxyComputerOutput"><a href="#a2d5e5125b8c71fe0dedbe92d730647ec">mark_failure()</a></span> and emptied by <span class="doxyComputerOutput"><a href="#a5859ce31641330b243cfb5d1c6080859">clear_buffer()</a></span>; not used with the other verbosity levels.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01239">1239</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ab8acd7e0c7bc5240a0912affd115305b">1239</a></span><span class="doxyLineContent"><span class="doxyHighlight">      std::string <a href="#ab8acd7e0c7bc5240a0912affd115305b">failures_</a>{};</span></span></div>

</div>


<p>Referenced by <a href="#a5859ce31641330b243cfb5d1c6080859">clear_buffer</a>, <a href="#adb473d2a466c856bfe8151c7558383c1">console_lines</a>, <a href="#a2d5e5125b8c71fe0dedbe92d730647ec">mark_failure</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a637a7a94e8ba373203339489a160b322">micro_os_plus::micro_test_plus::detail::reporter_tap::write_quiet_failures</a>.</p>

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


<p>Set by the constructor, and returned by <span class="doxyComputerOutput"><a href="#a083ecdfa952d7f8c372a61fbea309357">has_output_file_error()</a></span>.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01348">1348</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a0d73674812cca717a754137b4b26ed89">1348</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="#a0d73674812cca717a754137b4b26ed89">has_output_file_error_</a>{ </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight"> };</span></span></div>

</div>


<p>Referenced by <a href="#a7e04bcbd0745543c604fdd975829175a">reporter</a> and <a href="#a083ecdfa952d7f8c372a61fbea309357">has_output_file_error</a>.</p>

</div>
</div>

### open\_test\_cases\_ {#ad7db34b25d785eacf98d4a50f1951d5b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::vector&lt;open_test_case&gt; micro_os_plus::micro_test_plus::detail::reporter::open_test_cases_ {}</td>
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

<p>The test cases that have begun and not yet ended, outermost first.</p>


<p>The last element is the test case that owns the buffered results.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01275">1275</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ad7db34b25d785eacf98d4a50f1951d5b">1275</a></span><span class="doxyLineContent"><span class="doxyHighlight">      std::vector&lt;open_test_case&gt; <a href="#ad7db34b25d785eacf98d4a50f1951d5b">open_test_cases_</a>{};</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a66f620b093f92e0def6bf5297fb6d6ee">micro_os_plus::micro_test_plus::detail::reporter_human::abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#aa8802baefcb360f48451418c783ac413">micro_os_plus::micro_test_plus::detail::reporter_tap::abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a04cef97a62731931038355a1b5f23556">micro_os_plus::micro_test_plus::detail::reporter_human::begin_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a0302f9f5b977b05139d73df3bbc18d69">micro_os_plus::micro_test_plus::detail::reporter_tap::begin_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#aec7a63f892ff631e659c28607bf31242">micro_os_plus::micro_test_plus::detail::reporter_tap::display_open_headers</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#abcfa63d8c5ca8acd458383102b7e99e9">micro_os_plus::micro_test_plus::detail::reporter_human::display_open_names</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#ad15f7dbbf6a683441df40c502125adc3">micro_os_plus::micro_test_plus::detail::reporter_tap::end_test_case</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a637a7a94e8ba373203339489a160b322">micro_os_plus::micro_test_plus::detail::reporter_tap::write_quiet_failures</a>.</p>

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


<p>When non-null, the report is written to this file in addition to the console, without colour sequences. The file receives the full report, regardless of the verbosity. The file is opened by the constructor and closed by the destructor.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01340">1340</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a270178ed5fbe0d3f4d72766c2984582a">1340</a></span><span class="doxyLineContent"><span class="doxyHighlight">      FILE* <a href="#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a>{ </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight"> };</span></span></div>

</div>


<p>Referenced by <a href="#a7e04bcbd0745543c604fdd975829175a">reporter</a>, <a href="#a5b6052e6c28235b76d855b2b7bc176dd">~reporter</a>, <a href="#a804b593aefa158d92a72da43de57d242">flush_streams</a>, <a href="#af33f2f6498a97383cdb75020e32ccf23">route</a>, <a href="#a37cba38a47d66a928a936ee081c6d88c">write_buffer_to_file</a>, <a href="#a90a541c6a9b1ddd3da9440358bfc704e">write_file</a>, <a href="#aa97f2ba65009154090dc68e42c94db71">write_line</a> and <a href="#a0e6f0a129d495a7e9d57ef71412cd88f">writes_passed_checks</a>.</p>

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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01329">1329</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ac3878d2e85ed2cae4c71c793d7a8f52e">1329</a></span><span class="doxyLineContent"><span class="doxyHighlight">      std::string <a href="#ac3878d2e85ed2cae4c71c793d7a8f52e">output_file_path_</a>{};</span></span></div>

</div>


<p>Referenced by <a href="#a7e04bcbd0745543c604fdd975829175a">reporter</a> and <a href="#a5b6052e6c28235b76d855b2b7bc176dd">~reporter</a>.</p>

</div>
</div>

### suite\_displayed\_ {#a6b07e60aa8baeb90821690d1ff9c65e6}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::detail::reporter::suite_displayed_ { false }</td>
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

<p>Whether the heading of the current suite was displayed on the console.</p>


<p>Set by <span class="doxyComputerOutput"><a href="#a5ddd6ca6ce847ca89d7a3fcf9751f97d">enter_suite()</a></span>; with the quiet verbosity, which does not display the headings, the heading is displayed when the first failure of the suite is.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01294">1294</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a6b07e60aa8baeb90821690d1ff9c65e6">1294</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="#a6b07e60aa8baeb90821690d1ff9c65e6">suite_displayed_</a>{ </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight"> };</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a66f620b093f92e0def6bf5297fb6d6ee">micro_os_plus::micro_test_plus::detail::reporter_human::abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#abcfa63d8c5ca8acd458383102b7e99e9">micro_os_plus::micro_test_plus::detail::reporter_human::display_open_names</a> and <a href="#a5ddd6ca6ce847ca89d7a3fcf9751f97d">enter_suite</a>.</p>

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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01196">1196</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a2560a0f1cf935e420a2e584ccddf1a1e">1196</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914b">micro_test_plus::verbosity</a> <a href="#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#a7e04bcbd0745543c604fdd975829175a">reporter</a>, <a href="#a5b6052e6c28235b76d855b2b7bc176dd">~reporter</a>, <a href="#adb473d2a466c856bfe8151c7558383c1">console_lines</a>, <a href="#a2d5e5125b8c71fe0dedbe92d730647ec">mark_failure</a>, <a href="#af33f2f6498a97383cdb75020e32ccf23">route</a>, <a href="#a467d1332df523b9acaa3ff82b0ebb714">verbosity</a> and <a href="#a0e6f0a129d495a7e9d57ef71412cd88f">writes_passed_checks</a>.</p>

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


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00984">984</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00753">753</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ac6dca3d3fa34870f3960fe5e226e45d8">753</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ac6dca3d3fa34870f3960fe5e226e45d8">reporter::format_elapsed_time</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch">stopwatch</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch">stopwatch</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">754</span><span class="doxyLineContent"><span class="doxyHighlight">                                 </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> (&amp;message)[<a href="#a2bf85bc5dd65df1816b52b7fd7c6c627">elapsed_time_size_</a>])</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">755</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">756</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> elapsed = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch">stopwatch</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch/#a3719382123c6741054a89e4f76b55d90">elapsed</a> ().count ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">757</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (elapsed &gt; 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">758</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">759</span><span class="doxyLineContent"><span class="doxyHighlight">        snprintf (message, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (message),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">760</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">", time: %"</span><span class="doxyHighlight"> PRIu32 </span><span class="doxyHighlightStringLiteral">".%03"</span><span class="doxyHighlight"> PRIu32 </span><span class="doxyHighlightStringLiteral">" ms"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">761</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">uint32_t</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (elapsed / 1000),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">762</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">uint32_t</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (elapsed % 1000));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">763</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">764</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">765</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">766</span><span class="doxyLineContent"><span class="doxyHighlight">        message[0] = </span><span class="doxyHighlightCharLiteral">'\0'</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">767</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">768</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch/#a3719382123c6741054a89e4f76b55d90">micro_os_plus::micro_test_plus::detail::stopwatch::elapsed</a> and <a href="#a2bf85bc5dd65df1816b52b7fd7c6c627">elapsed_time_size_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ace9c2dfffc49a97516b96dacaf87b943">micro_os_plus::micro_test_plus::detail::reporter_human::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a7033819609bfad2db2ecc7a024e91b2c">micro_os_plus::micro_test_plus::detail::reporter_tap::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a2d5ddae3195ab52a957927a1b455f7b8">micro_os_plus::micro_test_plus::detail::reporter_tap::end_suite</a>.</p>

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
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter::format_session_totals (const <a href="#a68a030feff1f481126e9a6d170331420">runner</a> &amp; runner, char(&amp;) message=[totals_size_])</td>
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


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01027">1027</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00839">839</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a6bf3aac88a5e66e2f93eb32c54dbdd14">839</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a6bf3aac88a5e66e2f93eb32c54dbdd14">reporter::format_session_totals</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="#a68a030feff1f481126e9a6d170331420">runner</a>&amp; <a href="#a68a030feff1f481126e9a6d170331420">runner</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">840</span><span class="doxyLineContent"><span class="doxyHighlight">                                   </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> (&amp;message)[<a href="#aaa55b147a670878984952ca1112cecd8">totals_size_</a>])</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">841</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">842</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// The fixed text, four counts, two fragments, and the terminator.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">843</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">static_assert</span><span class="doxyHighlight"> (<a href="#aaa55b147a670878984952ca1112cecd8">totals_size_</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">844</span><span class="doxyLineContent"><span class="doxyHighlight">                       &gt;= 54 + 4 * (std::numeric_limits&lt;size_t&gt;::digits10 + 1)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">845</span><span class="doxyLineContent"><span class="doxyHighlight">                              + 2 * (fragment_size - 1),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">846</span><span class="doxyLineContent"><span class="doxyHighlight">                   </span><span class="doxyHighlightStringLiteral">"totals_size_ too small for the session totals"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">847</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">848</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters">counters</a>&amp; totals = <a href="#a68a030feff1f481126e9a6d170331420">runner</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a2c8a999cc273356ea10ed34fb12dcf5a">totals</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">849</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> suites_count = <a href="#a68a030feff1f481126e9a6d170331420">runner</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#ac29e4b993bb3fe795eb8900231cbf5c4">total_suites_count</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">850</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">851</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> message_skipped_test_cases[fragment_size];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">852</span><span class="doxyLineContent"><span class="doxyHighlight">    format_skipped (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a2e5ea7bbb9bd5a05213dee741f08599d">skipped_test_cases</a> (), message_skipped_test_cases);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">853</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">854</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> message_skipped_suites[fragment_size];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">855</span><span class="doxyLineContent"><span class="doxyHighlight">    format_skipped (<a href="#a68a030feff1f481126e9a6d170331420">runner</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a2c2a6d7cb45b714026d124d0ca432360">skipped_suites_count</a> (), message_skipped_suites);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">856</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">857</span><span class="doxyLineContent"><span class="doxyHighlight">    snprintf (message, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (message),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">858</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightStringLiteral">"%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">859</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightStringLiteral">" check%s passed, %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">860</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightStringLiteral">" failed, in %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">861</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightStringLiteral">" test case%s%s, %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a> </span><span class="doxyHighlightStringLiteral">" "</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">862</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightStringLiteral">"test suite%s%s"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">863</span><span class="doxyLineContent"><span class="doxyHighlight">              totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> (), plural (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> ()),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">864</span><span class="doxyLineContent"><span class="doxyHighlight">              totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#ab1684c7c6101a4d534356d9d16807bee">failed_checks</a> (), totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">executed_test_cases</a> (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">865</span><span class="doxyLineContent"><span class="doxyHighlight">              plural (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">executed_test_cases</a> ()),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">866</span><span class="doxyLineContent"><span class="doxyHighlight">              message_skipped_test_cases, suites_count, plural (suites_count),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">867</span><span class="doxyLineContent"><span class="doxyHighlight">              message_skipped_suites);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">868</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">micro_os_plus::micro_test_plus::counters::executed_test_cases</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#ab1684c7c6101a4d534356d9d16807bee">micro_os_plus::micro_test_plus::counters::failed_checks</a>, <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a>, <a href="#a68a030feff1f481126e9a6d170331420">micro_test_plus::runner</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">micro_os_plus::micro_test_plus::counters::passed_checks</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a2c2a6d7cb45b714026d124d0ca432360">micro_os_plus::micro_test_plus::runner::skipped_suites_count</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a2e5ea7bbb9bd5a05213dee741f08599d">micro_os_plus::micro_test_plus::counters::skipped_test_cases</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#ac29e4b993bb3fe795eb8900231cbf5c4">micro_os_plus::micro_test_plus::runner::total_suites_count</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a2c8a999cc273356ea10ed34fb12dcf5a">micro_os_plus::micro_test_plus::runner::totals</a> and <a href="#aaa55b147a670878984952ca1112cecd8">totals_size_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ace9c2dfffc49a97516b96dacaf87b943">micro_os_plus::micro_test_plus::detail::reporter_human::end_session</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a7033819609bfad2db2ecc7a024e91b2c">micro_os_plus::micro_test_plus::detail::reporter_tap::end_session</a>.</p>

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


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01048">1048</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00876">876</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a570030599ccc9f4133ed6a9eda2c2a1c">876</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a570030599ccc9f4133ed6a9eda2c2a1c">reporter::format_suite_totals</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">877</span><span class="doxyLineContent"><span class="doxyHighlight">                                 </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> (&amp;message)[<a href="#aaa55b147a670878984952ca1112cecd8">totals_size_</a>])</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">878</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">879</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters">counters</a>&amp; totals = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">totals</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">880</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">881</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> message_skipped[fragment_size];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">882</span><span class="doxyLineContent"><span class="doxyHighlight">    format_skipped (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a2e5ea7bbb9bd5a05213dee741f08599d">skipped_test_cases</a> (), message_skipped);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">883</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">884</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a14690f9880df505f9dd90a9f2c3dfc96">passed</a> ()) [[likely]]</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">885</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">886</span><span class="doxyLineContent"><span class="doxyHighlight">        snprintf (message, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (message),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">887</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">"%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">888</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">" check%s in %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">889</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">" test case%s%s"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">890</span><span class="doxyLineContent"><span class="doxyHighlight">                  totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> (), plural (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> ()),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">891</span><span class="doxyLineContent"><span class="doxyHighlight">                  totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">executed_test_cases</a> (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">892</span><span class="doxyLineContent"><span class="doxyHighlight">                  plural (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">executed_test_cases</a> ()), message_skipped);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">893</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">894</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">895</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">896</span><span class="doxyLineContent"><span class="doxyHighlight">        snprintf (message, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (message),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">897</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">"%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">898</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">" check%s passed, %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">899</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">" failed, in %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">900</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">" test case%s%s"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">901</span><span class="doxyLineContent"><span class="doxyHighlight">                  totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> (), plural (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> ()),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">902</span><span class="doxyLineContent"><span class="doxyHighlight">                  totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#ab1684c7c6101a4d534356d9d16807bee">failed_checks</a> (), totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">executed_test_cases</a> (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">903</span><span class="doxyLineContent"><span class="doxyHighlight">                  plural (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">executed_test_cases</a> ()), message_skipped);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">904</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">905</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">micro_os_plus::micro_test_plus::counters::executed_test_cases</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#ab1684c7c6101a4d534356d9d16807bee">micro_os_plus::micro_test_plus::counters::failed_checks</a>, <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a14690f9880df505f9dd90a9f2c3dfc96">micro_os_plus::micro_test_plus::counters::passed</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">micro_os_plus::micro_test_plus::counters::passed_checks</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a2e5ea7bbb9bd5a05213dee741f08599d">micro_os_plus::micro_test_plus::counters::skipped_test_cases</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">micro_os_plus::micro_test_plus::detail::runnable_base::totals</a> and <a href="#aaa55b147a670878984952ca1112cecd8">totals_size_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a2d5ddae3195ab52a957927a1b455f7b8">micro_os_plus::micro_test_plus::detail::reporter_tap::end_suite</a>.</p>

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
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reporter::format_test_case_totals (const <a href="#a904f410e240644fa77d65e686e6fc3eb">test_case</a> &amp; test_case, char(&amp;) message=[totals_size_])</td>
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


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01069">1069</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00913">913</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a60b8564f54a6a1230e6d4ce110de93f5">913</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a60b8564f54a6a1230e6d4ce110de93f5">reporter::format_test_case_totals</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="#a904f410e240644fa77d65e686e6fc3eb">test_case</a>&amp; <a href="#a904f410e240644fa77d65e686e6fc3eb">test_case</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">914</span><span class="doxyLineContent"><span class="doxyHighlight">                                     </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> (&amp;message)[<a href="#aaa55b147a670878984952ca1112cecd8">totals_size_</a>])</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">915</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">916</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters">counters</a>&amp; totals = <a href="#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">totals</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">917</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">918</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a14690f9880df505f9dd90a9f2c3dfc96">passed</a> ()) [[likely]]</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">919</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">920</span><span class="doxyLineContent"><span class="doxyHighlight">        snprintf (message, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (message),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">921</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">"%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a> </span><span class="doxyHighlightStringLiteral">" check%s"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">922</span><span class="doxyLineContent"><span class="doxyHighlight">                  totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> (), plural (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> ()));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">923</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">924</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">925</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">926</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> message_test_cases[fragment_size] = </span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">927</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a85981e2e55a820cb49ee04aa82bbde56">failed_test_cases</a> () &gt; 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">928</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">929</span><span class="doxyLineContent"><span class="doxyHighlight">            snprintf (message_test_cases, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (message_test_cases),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">930</span><span class="doxyLineContent"><span class="doxyHighlight">                      </span><span class="doxyHighlightStringLiteral">", %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">931</span><span class="doxyLineContent"><span class="doxyHighlight">                      </span><span class="doxyHighlightStringLiteral">" test case%s failed"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">932</span><span class="doxyLineContent"><span class="doxyHighlight">                      totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a85981e2e55a820cb49ee04aa82bbde56">failed_test_cases</a> (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">933</span><span class="doxyLineContent"><span class="doxyHighlight">                      plural (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a85981e2e55a820cb49ee04aa82bbde56">failed_test_cases</a> ()));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">934</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">935</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">936</span><span class="doxyLineContent"><span class="doxyHighlight">        snprintf (message, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (message),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">937</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">"%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">938</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">" check%s passed, %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">939</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">" failed%s"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">940</span><span class="doxyLineContent"><span class="doxyHighlight">                  totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> (), plural (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> ()),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">941</span><span class="doxyLineContent"><span class="doxyHighlight">                  totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#ab1684c7c6101a4d534356d9d16807bee">failed_checks</a> (), message_test_cases);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">942</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">943</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#ab1684c7c6101a4d534356d9d16807bee">micro_os_plus::micro_test_plus::counters::failed_checks</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a85981e2e55a820cb49ee04aa82bbde56">micro_os_plus::micro_test_plus::counters::failed_test_cases</a>, <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a>, <a href="#a904f410e240644fa77d65e686e6fc3eb">micro_test_plus::test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a14690f9880df505f9dd90a9f2c3dfc96">micro_os_plus::micro_test_plus::counters::passed</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">micro_os_plus::micro_test_plus::counters::passed_checks</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">micro_os_plus::micro_test_plus::detail::runnable_base::totals</a> and <a href="#aaa55b147a670878984952ca1112cecd8">totals_size_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#ad15f7dbbf6a683441df40c502125adc3">micro_os_plus::micro_test_plus::detail::reporter_tap::end_test_case</a>.</p>

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


<p>Large enough for <span class="doxyComputerOutput">", time: 4294967295.999 ms"</span>, the longest text produced by <span class="doxyComputerOutput"><a href="#ac6dca3d3fa34870f3960fe5e226e45d8">format_elapsed_time()</a></span>.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00963">963</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a2bf85bc5dd65df1816b52b7fd7c6c627">963</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="#a2bf85bc5dd65df1816b52b7fd7c6c627">elapsed_time_size_</a> = 32;</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ace9c2dfffc49a97516b96dacaf87b943">micro_os_plus::micro_test_plus::detail::reporter_human::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a7033819609bfad2db2ecc7a024e91b2c">micro_os_plus::micro_test_plus::detail::reporter_tap::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a2d5ddae3195ab52a957927a1b455f7b8">micro_os_plus::micro_test_plus::detail::reporter_tap::end_suite</a> and <a href="#ac6dca3d3fa34870f3960fe5e226e45d8">format_elapsed_time</a>.</p>

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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01186">1186</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a7ee7d450c03e89bb0beb6cd97056aa4e">1186</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="#a7ee7d450c03e89bb0beb6cd97056aa4e">indent_size_</a> = 4;</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a04cef97a62731931038355a1b5f23556">micro_os_plus::micro_test_plus::detail::reporter_human::begin_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a0302f9f5b977b05139d73df3bbc18d69">micro_os_plus::micro_test_plus::detail::reporter_tap::begin_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#aec7a63f892ff631e659c28607bf31242">micro_os_plus::micro_test_plus::detail::reporter_tap::display_open_headers</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#abcfa63d8c5ca8acd458383102b7e99e9">micro_os_plus::micro_test_plus::detail::reporter_human::display_open_names</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a2d5ddae3195ab52a957927a1b455f7b8">micro_os_plus::micro_test_plus::detail::reporter_tap::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#ad15f7dbbf6a683441df40c502125adc3">micro_os_plus::micro_test_plus::detail::reporter_tap::end_test_case</a>, <a href="#aedfa17028026f6eaa871214da441e90c">operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af28ab5a9448645fb8976c0b139bf302b">micro_os_plus::micro_test_plus::detail::reporter_human::skip_test_case</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a31ccd7af941d06241ce16df9274abc38">micro_os_plus::micro_test_plus::detail::reporter_tap::skip_test_case</a>.</p>

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


<p>Large enough for the longest text produced by <span class="doxyComputerOutput"><a href="#a6bf3aac88a5e66e2f93eb32c54dbdd14">format_session_totals()</a></span>, which is longer than the texts of the suites and of the test cases: 53 characters, four counts, two fragments of up to 20 characters and a count each (the longest fragment is <span class="doxyComputerOutput">", N test cases failed"</span>), and the terminator, with the counts of the largest <span class="doxyComputerOutput">size_t</span> value (10 digits on 32-bit targets, 20 on 64-bit ones). The fragments are counted at their maximum length, as the compiler does when it checks for truncation.</p>


<p>The array is a local variable of the functions that end the test cases, which run at the deepest point of the stack, so it is not larger than needed on the 32-bit embedded targets.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l01005">1005</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">1006</span><span class="doxyLineContent"><span class="doxyHighlight">          = 94 + 6 * (std::numeric_limits&lt;size_t&gt;::digits10 + 1);</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ace9c2dfffc49a97516b96dacaf87b943">micro_os_plus::micro_test_plus::detail::reporter_human::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a7033819609bfad2db2ecc7a024e91b2c">micro_os_plus::micro_test_plus::detail::reporter_tap::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a2d5ddae3195ab52a957927a1b455f7b8">micro_os_plus::micro_test_plus::detail::reporter_tap::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#ad15f7dbbf6a683441df40c502125adc3">micro_os_plus::micro_test_plus::detail::reporter_tap::end_test_case</a>, <a href="#a6bf3aac88a5e66e2f93eb32c54dbdd14">format_session_totals</a>, <a href="#a570030599ccc9f4133ed6a9eda2c2a1c">format_suite_totals</a> and <a href="#a60b8564f54a6a1230e6d4ce110de93f5">format_test_case_totals</a>.</p>

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

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
