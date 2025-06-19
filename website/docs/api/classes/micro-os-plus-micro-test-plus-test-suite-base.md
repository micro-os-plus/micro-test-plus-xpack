---

# DO NOT EDIT!
# Automatically generated via docusaurus-plugin-doxygen by Doxygen.

slug: /api/classes/micro-os-plus/micro-test-plus/test-suite-base
custom_edit_url: null
keywords:
  - doxygen
  - reference
  - class
toc_max_heading_level: 3

---

<div class="doxyPage">

# The `test_suite_base` Class Reference

<p>Base class for all test suites. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
class micro_os_plus::micro_test_plus::test_suite_base
</div>

## Included Headers

<div class="doxyIncludesList">
#include &lt;<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>&gt;
<br/>
</div>

## Derived Classes

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">class</td>
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

## Public Constructors Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a1aea53994faf3a7f7a610a6c47a8ef4a">test_suite_base</a> (const char *name)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructs a test suite. <a href="#a1aea53994faf3a7f7a610a6c47a8ef4a">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ac3d6caf07f5c38f8dc8d75d8ae7bb20c">test_suite_base</a> (const test_suite_base &amp;)=delete</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deleted copy constructor to prevent copying. <a href="#ac3d6caf07f5c38f8dc8d75d8ae7bb20c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ac66248be55f033bef1a32fb1204ce03b">test_suite_base</a> (test_suite_base &amp;&amp;)=delete</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deleted move constructor to prevent moving. <a href="#ac66248be55f033bef1a32fb1204ce03b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Destructor Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a8684c3b31ab07eaef800280bc172d6de">~test_suite_base</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Virtual destructor for the <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-suite-base">test_suite_base</a> class. <a href="#a8684c3b31ab07eaef800280bc172d6de">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Operators Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-suite-base">test_suite_base</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aba2b1e9fde84789ac9e1a78ae0a088f7">operator=</a> (const test_suite_base &amp;)=delete</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deleted copy assignment operator to prevent copying. <a href="#aba2b1e9fde84789ac9e1a78ae0a088f7">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-suite-base">test_suite_base</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ab80bbf61a4ff0a02f7a50ec2d305fee0">operator=</a> (test_suite_base &amp;&amp;)=delete</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deleted move assignment operator to prevent moving. <a href="#ab80bbf61a4ff0a02f7a50ec2d305fee0">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Member Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a6bd8aa956f30c344c9ef79cf21c69cdc">begin_test_case</a> (const char *name)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Marks the beginning of a named test case. <a href="#a6bd8aa956f30c344c9ef79cf21c69cdc">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#adfc3afd1432b2d093eef73a18ca9a242">begin_test_suite</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Begins the execution of the test suite. <a href="#adfc3afd1432b2d093eef73a18ca9a242">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ab2e1a6eadc56c54b45f9d21e450b0cbc">end_test_case</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Marks the end of a test case. <a href="#ab2e1a6eadc56c54b45f9d21e450b0cbc">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aa53f99054051136b3484a1664b5ee59f">end_test_suite</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Marks the end of the test suite. <a href="#aa53f99054051136b3484a1664b5ee59f">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">constexpr int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a4cd96949ef52b98b6c5e08bbd7900979">failed_checks</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Gets the number of test conditions that failed. <a href="#a4cd96949ef52b98b6c5e08bbd7900979">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a20051842d981b530746b4fb4dee00d01">increment_failed</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Increments the count of failed test conditions. <a href="#a20051842d981b530746b4fb4dee00d01">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a81006378d0bebeadcd59266f57b4ef4b">increment_successful</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Increments the count of passed test conditions. <a href="#a81006378d0bebeadcd59266f57b4ef4b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">constexpr const char *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a3625fee07d796bf5c3d6b4c69a94182c">name</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Gets the suite name. <a href="#a3625fee07d796bf5c3d6b4c69a94182c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a134b2f92347ac243ccb310d5d0324c25">run</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Runs the sequence of test cases in the suite. <a href="#a134b2f92347ac243ccb310d5d0324c25">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">constexpr int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#acf56ac77830e630b5485248409c3b3f1">successful_checks</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Gets the number of conditions that passed. <a href="#acf56ac77830e630b5485248409c3b3f1">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">constexpr int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ae755b186f32e229e8d0bd5e02027b515">test_cases</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Gets the number of test cases. <a href="#ae755b186f32e229e8d0bd5e02027b515">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">constexpr bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a20de3062a437e86955dd2917d7976cb3">unused</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Checks if the test suite was not used. <a href="#a20de3062a437e86955dd2917d7976cb3">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">constexpr bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ae60536040204e7481b50dfde7b0a6600">was_successful</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Gets the test suite result. <a href="#ae60536040204e7481b50dfde7b0a6600">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Member Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">struct { ... }</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ac534b9501e09bf4f1f6ef1d118a5bcbe">current_test_case</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Structure holding the current test case's check counters. <a href="#ac534b9501e09bf4f1f6ef1d118a5bcbe">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a40cadb0a79f55c796b7e7aca4a847cfd">failed_checks</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Number of failed checks in the current test case. <a href="#a40cadb0a79f55c796b7e7aca4a847cfd">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ac442c68973cd937aeaef7aa7fbc27d30">process_deferred_begin</a> = true</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Indicates whether to process deferred begin for test cases. <a href="#ac442c68973cd937aeaef7aa7fbc27d30">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a4851a70fd4a0c71b787e445b9766bacc">successful_checks</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Number of successful checks in the current test case. <a href="#a4851a70fd4a0c71b787e445b9766bacc">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Protected Member Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a01c523aaf94e26eb4cd6727c5d74ab02">failed_checks_</a> = 0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Count of test conditions that failed. <a href="#a01c523aaf94e26eb4cd6727c5d74ab02">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">const char *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a76f1c1c39f8b2c8cc70688a47bf6eafd">name_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The test suite name. <a href="#a76f1c1c39f8b2c8cc70688a47bf6eafd">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ad2736cdadc2ab917099cd0ad82d3fc18">successful_checks_</a> = 0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Count of test conditions that passed. <a href="#ad2736cdadc2ab917099cd0ad82d3fc18">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">const char *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ae369ec539219642f84aeb93b78269df0">test_case_name_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The current test case name. <a href="#ae369ec539219642f84aeb93b78269df0">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a1e9205117a2373caf7346064e86afa03">test_cases_</a> = 0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Count of test cases in the test suite. <a href="#a1e9205117a2373caf7346064e86afa03">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Base class for all test suites.</p>


<p>The <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-suite-base">test_suite_base</a></span> class provides the foundational interface for managing test suites within the µTest++ framework. It maintains counters for successful and failed checks, tracks test cases, and offers methods for marking the commencement and completion of test cases and suites.</p>

<p>This class ensures consistent state management and reporting for all derived test suites. It also provides utility methods for querying the suite's name, the number of successful and failed checks, the number of test cases, and the overall result of the suite.</p>

<p>All members and methods are defined within the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a></span> namespace, ensuring clear separation from user code and minimising the risk of naming conflicts.</p>

<p>Definition at line 97 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h">test-suite.h</a>.</p>

<div class="doxySectionDef">

## Public Constructors

### test_suite_base() {#a1aea53994faf3a7f7a610a6c47a8ef4a}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::test_suite_base::test_suite_base (const char * name)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Constructs a test suite.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] name</td>
<td class="doxyParamItemDescription"><p>The test suite name.</p></td>
</tr>
</table>
</dd>
</dl>

<p>The rule of five is enforced to prevent accidental copying or moving.</p>

<p>The constructor initialises a new instance of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-suite-base">test_suite_base</a></span> class with the specified name. It sets up the internal state required for managing test cases within the suite. If tracing is enabled, the function signature is output for diagnostic purposes. The default test suite does not require explicit registration, ensuring seamless integration within the µTest++ framework and supporting organised test management across all files and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h/#l00108">108</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h">test-suite.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-suite-cpp/#l00075">75</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-suite-cpp">test-suite.cpp</a>.</p>
</div>
</div>

### test_suite_base() {#ac3d6caf07f5c38f8dc8d75d8ae7bb20c}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::test_suite_base::test_suite_base (const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-suite-base">test_suite_base</a> &amp;)</td>
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

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h/#l00113">113</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h">test-suite.h</a>.</p>
</div>
</div>

### test_suite_base() {#ac66248be55f033bef1a32fb1204ce03b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::test_suite_base::test_suite_base (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-suite-base">test_suite_base</a> &amp;&amp;)</td>
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

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h/#l00118">118</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h">test-suite.h</a>.</p>
</div>
</div>

</div>

<div class="doxySectionDef">

## Public Destructor

### ~test_suite_base() {#a8684c3b31ab07eaef800280bc172d6de}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::test_suite_base::~test_suite_base ()</td>
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
<p>Virtual destructor for the <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-suite-base">test_suite_base</a> class.</p>


<p>The destructor releases any resources associated with the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-suite-base">test_suite_base</a></span> instance. It ensures that the test suite is properly cleaned up after execution, supporting robust and reliable test management across all files and folders within the µTest++ framework.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h/#l00137">137</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h">test-suite.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-suite-cpp/#l00092">92</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-suite-cpp">test-suite.cpp</a>.</p>
</div>
</div>

</div>

<div class="doxySectionDef">

## Public Operators

### operator=() {#aba2b1e9fde84789ac9e1a78ae0a088f7}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_suite_base &amp; micro_os_plus::micro_test_plus::test_suite_base::operator= (const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-suite-base">test_suite_base</a> &amp;)</td>
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

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h/#l00124">124</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h">test-suite.h</a>.</p>
</div>
</div>

### operator=() {#ab80bbf61a4ff0a02f7a50ec2d305fee0}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_suite_base &amp; micro_os_plus::micro_test_plus::test_suite_base::operator= (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-suite-base">test_suite_base</a> &amp;&amp;)</td>
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

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h/#l00131">131</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h">test-suite.h</a>.</p>
</div>
</div>

</div>

<div class="doxySectionDef">

## Public Member Functions

### begin_test_case() {#a6bd8aa956f30c344c9ef79cf21c69cdc}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::test_suite_base::begin_test_case (const char * name)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Marks the beginning of a named test case.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] name</td>
<td class="doxyParamItemDescription"><p>The test case name.</p></td>
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


<p>This method marks the beginning of a test case within the suite. If the start of the suite was deferred, it ensures the suite is properly begun before proceeding. The method sets the current test case name, increments the total number of test cases, resets the current test case statistics, and notifies the test reporter to begin the test case. This approach guarantees that each test case is clearly identified, accurately tracked, and properly reported across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h/#l00158">158</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h">test-suite.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-suite-cpp/#l00159">159</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-suite-cpp">test-suite.cpp</a>.</p>
</div>
</div>

### begin_test_suite() {#adfc3afd1432b2d093eef73a18ca9a242}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::test_suite_base::begin_test_suite (void)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Begins the execution of the test suite.</p>


<dl class="doxySectionUser">
<dt><b>Parameters</b></dt>
<dd>
<p>None.</p>
</dd>
</dl>


<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Nothing.</p>
</dd>
</dl>


<p>This method marks the beginning of a test suite's execution. It resets the deferred begin flag and notifies the test reporter to start the suite, passing the suite's name. This ensures that test suite output is clearly delineated and properly initialised, supporting organised and readable reporting across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h/#l00253">253</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h">test-suite.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-suite-cpp/#l00122">122</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-suite-cpp">test-suite.cpp</a>.</p>
</div>
</div>

### end_test_case() {#ab2e1a6eadc56c54b45f9d21e450b0cbc}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::test_suite_base::end_test_case (void)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Marks the end of a test case.</p>


<dl class="doxySectionUser">
<dt><b>Parameters</b></dt>
<dd>
<p>None.</p>
</dd>
</dl>


<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Nothing.</p>
</dd>
</dl>


<p>This method marks the end of a test case within the suite. It notifies the test reporter to conclude the test case, passing the current test case name. This ensures that the results of the test case are accurately finalised and clearly reported, supporting organised and reliable test management across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h/#l00168">168</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h">test-suite.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-suite-cpp/#l00183">183</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-suite-cpp">test-suite.cpp</a>.</p>
</div>
</div>

### end_test_suite() {#aa53f99054051136b3484a1664b5ee59f}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::test_suite_base::end_test_suite (void)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Marks the end of the test suite.</p>


<dl class="doxySectionUser">
<dt><b>Parameters</b></dt>
<dd>
<p>None.</p>
</dd>
</dl>


<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Nothing.</p>
</dd>
</dl>


<p>This method marks the end of a test suite's execution. If the suite's start was deferred, it ensures the suite is properly begun before finalising. The method then notifies the test reporter to conclude the suite, passing a reference to the suite instance. This guarantees that all results are accurately summarised and reported, supporting clear and organised test management across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h/#l00264">264</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h">test-suite.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-suite-cpp/#l00139">139</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-suite-cpp">test-suite.cpp</a>.</p>
</div>
</div>

### failed_checks() {#a4cd96949ef52b98b6c5e08bbd7900979}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">int micro_os_plus::micro_test_plus::test_suite_base::failed_checks (void)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel constexpr">constexpr</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Gets the number of test conditions that failed.</p>


<dl class="doxySectionUser">
<dt><b>Parameters</b></dt>
<dd>
<p>None.</p>
</dd>
</dl>


<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>An integer with the number of checks that failed.</p>
</dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h/#l00226">226</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h">test-suite.h</a>.</p>
</div>
</div>

### increment_failed() {#a20051842d981b530746b4fb4dee00d01}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::test_suite_base::increment_failed (void)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Increments the count of failed test conditions.</p>


<dl class="doxySectionUser">
<dt><b>Parameters</b></dt>
<dd>
<p>None.</p>
</dd>
</dl>


<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Nothing.</p>
</dd>
</dl>


<p>This method increments the count of failed checks for the test suite and the current test case. It ensures that each failing assertion is accurately recorded, supporting precise tracking and reporting of test outcomes across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h/#l00203">203</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h">test-suite.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-suite-cpp/#l00210">210</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-suite-cpp">test-suite.cpp</a>.</p>
</div>
</div>

### increment_successful() {#a81006378d0bebeadcd59266f57b4ef4b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::test_suite_base::increment_successful (void)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Increments the count of passed test conditions.</p>


<dl class="doxySectionUser">
<dt><b>Parameters</b></dt>
<dd>
<p>None.</p>
</dd>
</dl>


<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Nothing.</p>
</dd>
</dl>


<p>This method increments the count of successful checks for the test suite and the current test case. It ensures that each passing assertion is accurately recorded, supporting precise tracking and reporting of test outcomes across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h/#l00192">192</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h">test-suite.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-suite-cpp/#l00196">196</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-suite-cpp">test-suite.cpp</a>.</p>
</div>
</div>

### name() {#a3625fee07d796bf5c3d6b4c69a94182c}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const char * micro_os_plus::micro_test_plus::test_suite_base::name (void)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel constexpr">constexpr</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Gets the suite name.</p>


<dl class="doxySectionUser">
<dt><b>Parameters</b></dt>
<dd>
<p>None.</p>
</dd>
</dl>


<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>A pointer to the null-terminated test suite name.</p>
</dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h/#l00178">178</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h">test-suite.h</a>.</p>
</div>
</div>

### run() {#a134b2f92347ac243ccb310d5d0324c25}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::test_suite_base::run (void)</td>
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
<p>Runs the sequence of test cases in the suite.</p>


<dl class="doxySectionUser">
<dt><b>Parameters</b></dt>
<dd>
<p>None.</p>
</dd>
</dl>


<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Nothing.</p>
</dd>
</dl>


<p>This method executes the test suite by invoking its associated callable object. If tracing is enabled, the function signature is output for diagnostic purposes. The method ensures that all test cases grouped within the suite are executed in an organised manner, supporting comprehensive and structured testing across all files and folders within the µTest++ framework.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h/#l00148">148</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h">test-suite.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-suite-cpp/#l00106">106</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-suite-cpp">test-suite.cpp</a>.</p>
</div>
</div>

### successful_checks() {#acf56ac77830e630b5485248409c3b3f1}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">int micro_os_plus::micro_test_plus::test_suite_base::successful_checks (void)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel constexpr">constexpr</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Gets the number of conditions that passed.</p>


<dl class="doxySectionUser">
<dt><b>Parameters</b></dt>
<dd>
<p>None.</p>
</dd>
</dl>


<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>An integer with the number of checks that passed.</p>
</dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h/#l00213">213</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h">test-suite.h</a>.</p>
</div>
</div>

### test_cases() {#ae755b186f32e229e8d0bd5e02027b515}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">int micro_os_plus::micro_test_plus::test_suite_base::test_cases (void)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel constexpr">constexpr</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Gets the number of test cases.</p>


<dl class="doxySectionUser">
<dt><b>Parameters</b></dt>
<dd>
<p>None.</p>
</dd>
</dl>


<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>An integer with the number of test cases.</p>
</dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h/#l00239">239</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h">test-suite.h</a>.</p>
</div>
</div>

### unused() {#a20de3062a437e86955dd2917d7976cb3}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::test_suite_base::unused (void)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel constexpr">constexpr</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Checks if the test suite was not used.</p>


<dl class="doxySectionUser">
<dt><b>Parameters</b></dt>
<dd>
<p>None.</p>
</dd>
</dl>


<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>True if the test suite is not used.</p>
</dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h/#l00288">288</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h">test-suite.h</a>.</p>
</div>
</div>

### was_successful() {#ae60536040204e7481b50dfde7b0a6600}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::test_suite_base::was_successful (void)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel constexpr">constexpr</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Gets the test suite result.</p>


<dl class="doxySectionUser">
<dt><b>Parameters</b></dt>
<dd>
<p>None.</p>
</dd>
</dl>


<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>True if the test suite was successful.</p>
</dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h/#l00274">274</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h">test-suite.h</a>.</p>
</div>
</div>

</div>

<div class="doxySectionDef">

## Public Member Attributes

### current_test_case {#ac534b9501e09bf4f1f6ef1d118a5bcbe}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">struct micro_os_plus::micro_test_plus::test_suite_base micro_os_plus::micro_test_plus::test_suite_base::current_test_case</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Structure holding the current test case's check counters.</p>


<p>Tracks the number of successful and failed checks for the currently running test case.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h/#l00344">344</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h">test-suite.h</a>.</p>
</div>
</div>

### failed_checks {#a40cadb0a79f55c796b7e7aca4a847cfd}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">int micro_os_plus::micro_test_plus::test_suite_base::failed_checks</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Number of failed checks in the current test case.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h/#l00343">343</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h">test-suite.h</a>.</p>
</div>
</div>

### process_deferred_begin {#ac442c68973cd937aeaef7aa7fbc27d30}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::test_suite_base::process_deferred_begin = true</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Indicates whether to process deferred begin for test cases.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h/#l00324">324</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h">test-suite.h</a>.</p>
</div>
</div>

### successful_checks {#a4851a70fd4a0c71b787e445b9766bacc}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">int micro_os_plus::micro_test_plus::test_suite_base::successful_checks</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Number of successful checks in the current test case.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h/#l00338">338</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h">test-suite.h</a>.</p>
</div>
</div>

</div>

<div class="doxySectionDef">

## Protected Member Attributes

### failed_checks_ {#a01c523aaf94e26eb4cd6727c5d74ab02}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">int micro_os_plus::micro_test_plus::test_suite_base::failed_checks_ = 0</td>
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
<p>Count of test conditions that failed.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h/#l00313">313</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h">test-suite.h</a>.</p>
</div>
</div>

### name_ {#a76f1c1c39f8b2c8cc70688a47bf6eafd}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const char* micro_os_plus::micro_test_plus::test_suite_base::name_</td>
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
<p>The test suite name.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h/#l00298">298</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h">test-suite.h</a>.</p>
</div>
</div>

### successful_checks_ {#ad2736cdadc2ab917099cd0ad82d3fc18}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">int micro_os_plus::micro_test_plus::test_suite_base::successful_checks_ = 0</td>
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
<p>Count of test conditions that passed.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h/#l00308">308</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h">test-suite.h</a>.</p>
</div>
</div>

### test_case_name_ {#ae369ec539219642f84aeb93b78269df0}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const char* micro_os_plus::micro_test_plus::test_suite_base::test_case_name_</td>
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
<p>The current test case name.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h/#l00303">303</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h">test-suite.h</a>.</p>
</div>
</div>

### test_cases_ {#a1e9205117a2373caf7346064e86afa03}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">int micro_os_plus::micro_test_plus::test_suite_base::test_cases_ = 0</td>
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
<p>Count of test cases in the test suite.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h/#l00318">318</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h">test-suite.h</a>.</p>
</div>
</div>

</div>

<hr/>

<p>The documentation for this class was generated from the following files:</p>

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-suite-h">test-suite.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/src/test-suite-cpp">test-suite.cpp</a></li>
</ul>

<p class="doxyGeneratedBy">Generated via <a href="https://github.com/xpack/docusaurus-plugin-doxygen">docusaurus-plugin-doxygen</a> by <a href="https://www.doxygen.nl">Doxygen</a> 1.14.0.</p>

</div>
