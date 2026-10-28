---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/classes/micro-os-plus/micro-test-plus/detail/runnable-base
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - class

---

<div class="doxyPage">

# `runnable_base` Class

<p>Non-template base for all runnable objects (suites and test cases). <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
class micro_os_plus::micro_test_plus::detail::runnable_base { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>"
</div>

## Derived Classes

<table class="doxyMembersIndex">

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

## Friends Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aec75a9652b7e98188d506c462aa73e19">check_result</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The check result, which numbers and counts the checks. <a href="#aec75a9652b7e98188d506c462aa73e19">More...</a></p>
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
<p>The runner, which numbers and runs the suites. <a href="#a68a030feff1f481126e9a6d170331420">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ac1362875db31c5b5b875520025597a65">reporter_human</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The human reporter, which displays the nodes. <a href="#ac1362875db31c5b5b875520025597a65">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ac6f88fbc9f895d8d7495393d1a9a7d6a">reporter_tap</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The TAP reporter, which displays the nodes. <a href="#ac6f88fbc9f895d8d7495393d1a9a7d6a">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a> (const char *name, runner &amp;test_runner, size_t own_index)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructs a <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base">runnable_base</a></span> with a name, runner, and index. <a href="#a90b850cc983e007829a3aaf929aa8b4d">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a0252f278ae59dddef03282d7aa84a51c">runnable_base</a> (const runnable_base &amp;)=delete</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deleted copy constructor to prevent copying. <a href="#a0252f278ae59dddef03282d7aa84a51c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a6086e33edab5d5b8b837cab432f087c9">runnable_base</a> (runnable_base &amp;&amp;)=delete</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deleted move constructor to prevent moving. <a href="#a6086e33edab5d5b8b837cab432f087c9">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a129a5382922b2be662f4f491d03750ef">~runnable_base</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Virtual destructor. <a href="#a129a5382922b2be662f4f491d03750ef">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Operators Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a41f7fada4e78a1869653f67f9acedb42">operator=</a> (const runnable_base &amp;)=delete</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deleted copy assignment operator to prevent copying. <a href="#a41f7fada4e78a1869653f67f9acedb42">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a18b82d51daccd8a75f87e043d2660006">operator=</a> (runnable_base &amp;&amp;)=delete</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deleted move assignment operator to prevent moving. <a href="#a18b82d51daccd8a75f87e043d2660006">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Member Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const char *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Gets the node name. <a href="#a6c652cd5dc8194269c1cc5f0dc1945e0">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters">counters</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aa83553cf6bf351153328304ebc71e545">totals</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Gets the totals of the node. <a href="#aa83553cf6bf351153328304ebc71e545">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a38cf903fb0ba5b76b1eb2350b6385962">after_test_case_create</a> (class test_case &amp;test_case, suite &amp;suite)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Counts a newly constructed child test case and executes it immediately. <a href="#a38cf903fb0ba5b76b1eb2350b6385962">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;typename Callable_T, typename... Args_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ad4ac49522cfd6e1608d9ac64ab7a8b91">create_test_case</a> (const test_case_name &amp;name, suite &amp;parent_suite, size_t nesting_depth, Callable_T &amp;&amp;callable, Args_T &amp;&amp;... arguments)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Creates a child test case, and runs it. <a href="#ad4ac49522cfd6e1608d9ac64ab7a8b91">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aaec8b378e1d1639a5fa0e6dec20d6a46">is_aborted</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Checks whether the test execution was aborted by the owning runner. <a href="#aaec8b378e1d1639a5fa0e6dec20d6a46">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a58c3051635ce2389a8afc2222cd6b30d">is_listing</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Checks whether the owning runner lists the test cases instead of running them. <a href="#a58c3051635ce2389a8afc2222cd6b30d">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">size_t</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a0d131770fe8aed387ca6da982f1ff60e">next_test_point_number</a> (void) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Advances to the next child test point, and returns its number. <a href="#a0d131770fe8aed387ca6da982f1ff60e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a> *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a3fd5730af8bd449cc56e29d5d14509e9">running_test_case</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Gets the innermost test case being run by the owning runner, if any. <a href="#a3fd5730af8bd449cc56e29d5d14509e9">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a7e4a578732a0464480e211f6591fa69f">test_reporter</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Gets the test reporter associated with this test runnable. <a href="#a7e4a578732a0464480e211f6591fa69f">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a68a030feff1f481126e9a6d170331420">runner</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a0224080b4433f538798354eca0f4c8c5">test_runner</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Gets the test runner that owns this test runnable. <a href="#a0224080b4433f538798354eca0f4c8c5">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a5fec64d9b300277d56e02193bb7d0a46">abort</a> (const reflection::source_location &amp;sl=reflection::source_location::current()) const</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Aborts test execution via the owning runner, for a failed requirement. <a href="#a5fec64d9b300277d56e02193bb7d0a46">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a1bffa5c8f05ffb464857521badd6ecef">run</a> (void)=0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Runs the body of the test case or suite. <a href="#a1bffa5c8f05ffb464857521badd6ecef">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Protected Member Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">size_t</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aff1a81aff41ab5dc80e2fac1c5a78a31">child_test_cases_count_</a> = 0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The number of direct child test cases. <a href="#aff1a81aff41ab5dc80e2fac1c5a78a31">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const char *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aad830bd92e4f6e4239d2bb5b75d5bf50">name_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The node name. <a href="#aad830bd92e4f6e4239d2bb5b75d5bf50">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">size_t</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a69687627342981d42471b17f1d83311f">own_index_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The test index, counting from 1. <a href="#a69687627342981d42471b17f1d83311f">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a68a030feff1f481126e9a6d170331420">runner</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ab7513249cc0aac30e3edd7008d08d355">runner_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Reference to the test runner that owns this object. <a href="#ab7513249cc0aac30e3edd7008d08d355">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">size_t</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#abc92cbb8ab8d04e7c75bf18aa7189d98">test_point_number_</a> = 0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The number of the most recent child test point. <a href="#abc92cbb8ab8d04e7c75bf18aa7189d98">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters">counters</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a87091ad4653e9db854ba9d5a64b30738">totals_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Totals for the node. <a href="#a87091ad4653e9db854ba9d5a64b30738">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Non-template base for all runnable objects (suites and test cases).</p>


<p><span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base">runnable_base</a></span> is the single base of the nodes of the test tree, and holds the state that is shared by every runnable object:</p>


<ul class="doxyList ">
<li>the node name,</li>
<li>the counters of the passed and failed checks, and of the test cases,</li>
<li>a reference to the owning <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">runner</a></span>,</li>
<li>the object's own index within its parent,</li>
<li>the number of the most recent test point (check or nested test case), used in the TAP output, and</li>
<li>the number of the direct child test cases, used in the TAP plan; the child test cases themselves are not kept.</li>
</ul>

<p>The concrete runnable classes (<span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a></span>, <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a></span>) derive from <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base">runnable_base</a></span>; each refers to its body, which receives a reference to its own class, and implements <span class="doxyComputerOutput"><a href="#a1bffa5c8f05ffb464857521badd6ecef">run()</a></span>, which invokes the body between the reporter notifications. A suite, which runs later, stores its body in a <span class="doxyComputerOutput">std::function</span>; a test case, which runs immediately, refers to a body kept by its creator.</p>


<p>The user code can read only the name and the totals; the rest of the state, and the functions that run and abort the nodes, are the protocol between the nodes, the runner, the check result, and the reporters, which are friends. The runner numbers and runs the suites, the check result numbers and counts the checks, and the reporters read the indices and the test point numbers.</p>


<p>The class is non-copyable and non-movable to preserve unique ownership and consistent state throughout the test session.</p>


<p>Definition at line 272 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


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

<p>The check result, which numbers and counts the checks.</p>


<p>It advances the test point number, updates the totals, and reports the check through the reporter of the node.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00290">290</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aec75a9652b7e98188d506c462aa73e19">290</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="#aec75a9652b7e98188d506c462aa73e19">check_result</a>;</span></span></div>

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

<p>The runner, which numbers and runs the suites.</p>


<p>It sets the indices of the suites before running them, and selects the suites that refer to it.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00281">281</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a68a030feff1f481126e9a6d170331420">281</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">micro_test_plus::runner</a>;</span></span></div>

</div>


<p>Referenced by <a href="#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a0ffeed47bd9ecd07bda3a2f33f062b71">micro_os_plus::micro_test_plus::test_case::test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a484008ed66130a2bf334948841099943">micro_os_plus::micro_test_plus::test_case::detail::runnable_base</a>, <a href="#ac6f88fbc9f895d8d7495393d1a9a7d6a">reporter_tap</a> and <a href="#a1bffa5c8f05ffb464857521badd6ecef">run</a>.</p>

</div>
</div>

### reporter\_human {#ac1362875db31c5b5b875520025597a65}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">friend class reporter_human</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The human reporter, which displays the nodes.</p>


<p>It currently uses only the public members of the nodes; the declaration is kept for symmetry with the TAP reporter.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00299">299</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ac1362875db31c5b5b875520025597a65">299</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="#ac1362875db31c5b5b875520025597a65">reporter_human</a>;</span></span></div>

</div>


<p>Reference <a href="#ac1362875db31c5b5b875520025597a65">reporter_human</a>.</p>


<p>Referenced by <a href="#ac1362875db31c5b5b875520025597a65">reporter_human</a>.</p>

</div>
</div>

### reporter\_tap {#ac6f88fbc9f895d8d7495393d1a9a7d6a}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">friend class reporter_tap</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The TAP reporter, which displays the nodes.</p>


<p>It reads the indices and the test point numbers, for the TAP lines and plans, and, when tracing, the numbers of the child test cases.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00309">309</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ac6f88fbc9f895d8d7495393d1a9a7d6a">309</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="#ac6f88fbc9f895d8d7495393d1a9a7d6a">reporter_tap</a>;</span></span></div>

</div>


<p>References <a href="#a68a030feff1f481126e9a6d170331420">micro_test_plus::runner</a>, <a href="#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, <a href="#ac6f88fbc9f895d8d7495393d1a9a7d6a">reporter_tap</a> and <a href="#a0224080b4433f538798354eca0f4c8c5">test_runner</a>.</p>


<p>Referenced by <a href="#ac6f88fbc9f895d8d7495393d1a9a7d6a">reporter_tap</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Constructors

### runnable\_base() {#a90b850cc983e007829a3aaf929aa8b4d}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::runnable_base::runnable_base (const char * name, <a href="#a68a030feff1f481126e9a6d170331420">runner</a> &amp; test_runner, size_t own_index)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Constructs a <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base">runnable_base</a></span> with a name, runner, and index.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">name</td>
<td class="doxyParamItemDescription"><p>The name used in reports.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">test_runner</td>
<td class="doxyParamItemDescription"><p>The test runner managing this object.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">own_index</td>
<td class="doxyParamItemDescription"><p>The positional index of this object within its parent.</p></td>
</tr>
</table>
</dd>
</dl>

<p>The constructor initialises a new instance of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base">runnable_base</a></span> class with the specified name, runner reference, and own index; the name pointer is stored, and is expected to point to a string with a lifetime exceeding that of this instance. The totals, the child test point index, and the child test cases count start at zero. If tracing is enabled, the function signature is output for diagnostic purposes.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00320">320</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-cpp/#l00086">86</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-cpp">test.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a90b850cc983e007829a3aaf929aa8b4d">86</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a90b850cc983e007829a3aaf929aa8b4d">runnable_base::runnable_base</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* <a href="#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, <a href="#a68a030feff1f481126e9a6d170331420">runner</a>&amp; <a href="#a0224080b4433f538798354eca0f4c8c5">test_runner</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">87</span><span class="doxyLineContent"><span class="doxyHighlight">                                  </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> own_index)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">88</span><span class="doxyLineContent"><span class="doxyHighlight">        : <a href="#aad830bd92e4f6e4239d2bb5b75d5bf50">name_</a>{ <a href="#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> }, <a href="#ab7513249cc0aac30e3edd7008d08d355">runner_</a>{ <a href="#a0224080b4433f538798354eca0f4c8c5">test_runner</a> }, <a href="#a69687627342981d42471b17f1d83311f">own_index_</a>{ own_index }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">89</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">90</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">91</span><span class="doxyLineContent"><span class="doxyHighlight">      trace::printf (</span><span class="doxyHighlightStringLiteral">"%s '%s' %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a> </span><span class="doxyHighlightStringLiteral">"\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">92</span><span class="doxyLineContent"><span class="doxyHighlight">                     __PRETTY_FUNCTION__, <a href="#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, <a href="#a69687627342981d42471b17f1d83311f">own_index_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">93</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">94</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a>, <a href="#a68a030feff1f481126e9a6d170331420">micro_test_plus::runner</a>, <a href="#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, <a href="#aad830bd92e4f6e4239d2bb5b75d5bf50">name_</a>, <a href="#a69687627342981d42471b17f1d83311f">own_index_</a>, <a href="#ab7513249cc0aac30e3edd7008d08d355">runner_</a> and <a href="#a0224080b4433f538798354eca0f4c8c5">test_runner</a>.</p>


<p>Referenced by <a href="#a0252f278ae59dddef03282d7aa84a51c">runnable_base</a>, <a href="#a6086e33edab5d5b8b837cab432f087c9">runnable_base</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a0232c48687da2eb3a2171d8647ffb0a6">micro_os_plus::micro_test_plus::suite::suite</a>, <a href="#a41f7fada4e78a1869653f67f9acedb42">operator=</a> and <a href="#a18b82d51daccd8a75f87e043d2660006">operator=</a>.</p>

</div>
</div>

### runnable\_base() {#a0252f278ae59dddef03282d7aa84a51c}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::runnable_base::runnable_base (const runnable_base &amp;)</td>
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


<p>A copy would duplicate the counters.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00328">328</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<p>Reference <a href="#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a>.</p>

</div>
</div>

### runnable\_base() {#a6086e33edab5d5b8b837cab432f087c9}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::runnable_base::runnable_base (runnable_base &amp;&amp;)</td>
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


<p>Nodes are referred to by address (e.g. by their children and by the runner), so they must not be relocated.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00337">337</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<p>Reference <a href="#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Destructor

### \~runnable\_base() {#a129a5382922b2be662f4f491d03750ef}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::runnable_base::~runnable_base ()</td>
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

<p>Virtual destructor.</p>


<p>Virtual, so that the derived nodes are destroyed correctly.</p>


<p>Nothing is owned; the child test cases were destroyed when the <span class="doxyComputerOutput">test()</span> calls that created them returned. If tracing is enabled, the name is output for diagnostic purposes.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00366">366</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-cpp/#l00102">102</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-cpp">test.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a129a5382922b2be662f4f491d03750ef">102</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a129a5382922b2be662f4f491d03750ef">runnable_base::~runnable_base</a> ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">103</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">104</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">105</span><span class="doxyLineContent"><span class="doxyHighlight">      trace::printf (</span><span class="doxyHighlightStringLiteral">"%s '%s'\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__, <a href="#aad830bd92e4f6e4239d2bb5b75d5bf50">name_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">106</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">107</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="#aad830bd92e4f6e4239d2bb5b75d5bf50">name_</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Operators

### operator=() {#a41f7fada4e78a1869653f67f9acedb42}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">runnable_base &amp; micro_os_plus::micro_test_plus::detail::runnable_base::operator= (const <a href="#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a> &amp;)</td>
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


<p>A copy would duplicate the counters.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00346">346</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<p>Reference <a href="#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a>.</p>

</div>
</div>

### operator=() {#a18b82d51daccd8a75f87e043d2660006}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">runnable_base &amp; micro_os_plus::micro_test_plus::detail::runnable_base::operator= (<a href="#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a> &amp;&amp;)</td>
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


<p>Nodes are referred to by address (e.g. by their children and by the runner), so they must not be relocated.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00357">357</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<p>References <a href="#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a>, <a href="#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> and <a href="#aa83553cf6bf351153328304ebc71e545">totals</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Member Functions

### name() {#a6c652cd5dc8194269c1cc5f0dc1945e0}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const char * micro_os_plus::micro_test_plus::detail::runnable_base::name (void)</td>
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

<p>Gets the node name.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A pointer to the null-terminated node name.</p></dd>
</dl>


<p>Returns a pointer to the null-terminated name stored in <span class="doxyComputerOutput"><a href="#aad830bd92e4f6e4239d2bb5b75d5bf50">name_</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00378">378</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00152">152</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a6c652cd5dc8194269c1cc5f0dc1945e0">152</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a6c652cd5dc8194269c1cc5f0dc1945e0">runnable_base::name</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">153</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">154</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#aad830bd92e4f6e4239d2bb5b75d5bf50">name_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">155</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="#aad830bd92e4f6e4239d2bb5b75d5bf50">name_</a>.</p>


<p>Referenced by <a href="#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a10788baa079e19676a8cdbaa253285dc">micro_os_plus::micro_test_plus::runner::runner</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a5e2001730fd3659e9045fcc5cc668f07">micro_os_plus::micro_test_plus::runner::runner</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#aee03f72ebd3b2ff8e670b00e07d7f729">micro_os_plus::micro_test_plus::static_suite::static_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a0232c48687da2eb3a2171d8647ffb0a6">micro_os_plus::micro_test_plus::suite::suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a0ffeed47bd9ecd07bda3a2f33f062b71">micro_os_plus::micro_test_plus::test_case::test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#ac10e4f707de47389f43c38d420ce13e9">micro_os_plus::micro_test_plus::top_suite::top_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#aac24d1193ac0579dd6ac3c523a32015f">micro_os_plus::micro_test_plus::runner::add_top_suite</a>, <a href="#a38cf903fb0ba5b76b1eb2350b6385962">after_test_case_create</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a58c85919422801369d1d4d9a8efe77d0">micro_os_plus::micro_test_plus::detail::reporter_human::begin_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a2c05a737bfe80c955a998dc801e964b5">micro_os_plus::micro_test_plus::detail::reporter_tap::begin_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a04cef97a62731931038355a1b5f23556">micro_os_plus::micro_test_plus::detail::reporter_human::begin_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a0302f9f5b977b05139d73df3bbc18d69">micro_os_plus::micro_test_plus::detail::reporter_tap::begin_test_case</a>, <a href="#ad4ac49522cfd6e1608d9ac64ab7a8b91">create_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a6cd3b3f893312fe43fa2d7b5018646e9">micro_os_plus::micro_test_plus::suite::detail::reporter_tap</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a484008ed66130a2bf334948841099943">micro_os_plus::micro_test_plus::test_case::detail::runnable_base</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#aec7a63f892ff631e659c28607bf31242">micro_os_plus::micro_test_plus::detail::reporter_tap::display_open_headers</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#abcfa63d8c5ca8acd458383102b7e99e9">micro_os_plus::micro_test_plus::detail::reporter_human::display_open_names</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a2d5ddae3195ab52a957927a1b455f7b8">micro_os_plus::micro_test_plus::detail::reporter_tap::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#ad15f7dbbf6a683441df40c502125adc3">micro_os_plus::micro_test_plus::detail::reporter_tap::end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#afd98d9a322823d67448d4ba301846392">micro_os_plus::micro_test_plus::detail::reporter_human::fail_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a314df80e98fe6fa5de008d6708a14925">micro_os_plus::micro_test_plus::detail::reporter_tap::fail_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a0e478c394741ff78f65a7e2c0822ba50">micro_os_plus::micro_test_plus::runner::list_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#a68a030feff1f481126e9a6d170331420">micro_os_plus::micro_test_plus::top_suite::micro_test_plus::runner</a>, <a href="#a18b82d51daccd8a75f87e043d2660006">operator=</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#aaaa545978a454f1ae63fc06ac5169efe">micro_os_plus::micro_test_plus::suite::operator=</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#ac2e310ec902a0c3e786d4c415269c23e">micro_os_plus::micro_test_plus::test_case::operator=</a>, <a href="#ac6f88fbc9f895d8d7495393d1a9a7d6a">reporter_tap</a>, <a href="#a1bffa5c8f05ffb464857521badd6ecef">run</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#aca37d52611ed87d102dce89c3c6cc99d">micro_os_plus::micro_test_plus::detail::reporter_human::skip_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a319f35d4af8c72af8b14a89b421c1c74">micro_os_plus::micro_test_plus::detail::reporter_tap::skip_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af28ab5a9448645fb8976c0b139bf302b">micro_os_plus::micro_test_plus::detail::reporter_human::skip_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a31ccd7af941d06241ce16df9274abc38">micro_os_plus::micro_test_plus::detail::reporter_tap::skip_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a402696dc4d4978ff3c050427890cfe01">micro_os_plus::micro_test_plus::suite::test</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#aac23ee148d8e5946cd87e0de036e9fb8">micro_os_plus::micro_test_plus::test_case::test</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a86d654e9059b1acecbf49f2725419320">micro_os_plus::micro_test_plus::suite::test_each</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a08e3a26d6e032a580f095f8dcf8b2b41">micro_os_plus::micro_test_plus::suite::test_each</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a018224e675db634b3b9898c72d1c8655">micro_os_plus::micro_test_plus::test_case::test_each</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#afe716dc1b9245d7761b1fd6e6e854c5c">micro_os_plus::micro_test_plus::test_case::test_each</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a637a7a94e8ba373203339489a160b322">micro_os_plus::micro_test_plus::detail::reporter_tap::write_quiet_failures</a>.</p>

</div>
</div>

### totals() {#aa83553cf6bf351153328304ebc71e545}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const counters &amp; micro_os_plus::micro_test_plus::detail::runnable_base::totals (void)</td>
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

<p>Gets the totals of the node.</p>


<p>The reference is read-only, for the <span class="doxyComputerOutput">const</span> and the non-<span class="doxyComputerOutput">const</span> nodes alike, so that a test case or a suite cannot modify its own counters, which decide the exit code. The counters are updated only by the framework, which accesses the protected member directly.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A const reference to the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters">counters</a></span> instance.</p></dd>
</dl>


<p>Returns a const reference to the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters">counters</a></span> member.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00395">395</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00162">162</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aa83553cf6bf351153328304ebc71e545">162</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#aa83553cf6bf351153328304ebc71e545">runnable_base::totals</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">163</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">164</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a87091ad4653e9db854ba9d5a64b30738">totals_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">165</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="#a87091ad4653e9db854ba9d5a64b30738">totals_</a>.</p>


<p>Referenced by <a href="#a38cf903fb0ba5b76b1eb2350b6385962">after_test_case_create</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a2d5ddae3195ab52a957927a1b455f7b8">micro_os_plus::micro_test_plus::detail::reporter_tap::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#ad15f7dbbf6a683441df40c502125adc3">micro_os_plus::micro_test_plus::detail::reporter_tap::end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a570030599ccc9f4133ed6a9eda2c2a1c">micro_os_plus::micro_test_plus::detail::reporter::format_suite_totals</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a60b8564f54a6a1230e6d4ce110de93f5">micro_os_plus::micro_test_plus::detail::reporter::format_test_case_totals</a>, <a href="#a18b82d51daccd8a75f87e043d2660006">operator=</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a97f725cb167a2b464fac0eb88a0c8a46">micro_os_plus::micro_test_plus::runner::run</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Protected Member Functions

### after\_test\_case\_create() {#a38cf903fb0ba5b76b1eb2350b6385962}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::runnable_base::after_test_case_create (class <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a> &amp; test_case, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a> &amp; suite)</td>
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

<p>Counts a newly constructed child test case and executes it immediately.</p>


<p>The child test case is a local object of <span class="doxyComputerOutput"><a href="#ad4ac49522cfd6e1608d9ac64ab7a8b91">create_test_case()</a></span>, and is destroyed when that function returns.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">test_case</td>
<td class="doxyParamItemDescription"><p>The newly created <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a></span>.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">suite</td>
<td class="doxyParamItemDescription"><p>The parent <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a></span> to which execution results are reported.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Counts <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a></span>, which is a local object of the calling <span class="doxyComputerOutput"><a href="#ad4ac49522cfd6e1608d9ac64ab7a8b91">create_test_case()</a></span>, and immediately invokes <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#adb4333ecb107fee477156b661f0b1512">test_case::run()</a></span> on it. The test case is not kept; only <span class="doxyComputerOutput"><a href="#aff1a81aff41ab5dc80e2fac1c5a78a31">child_test_cases_count_</a></span> is needed later, for the TAP plan.</p>


<p>If the filter patterns do not select the test case (its own name at its nesting level, or the name of <span class="doxyComputerOutput">suite</span> at level 0, which matters only for the top suite, since the other suites run only when selected), its body is not called: the reporter is notified with <span class="doxyComputerOutput">skip_test_case()</span> and the parent's skipped test cases counter is incremented. The test case keeps its index and its place among the children, so the TAP plan of the parent remains complete.</p>


<p>Otherwise, while the test case runs, the runner keeps it as its innermost running test case (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a402696dc4d4978ff3c050427890cfe01">suite::test()</a></span>). The parent's executed test cases counter is incremented after the run, and, if the child failed (a failed check, or a failed nested test case), its failed test cases counter too, so that the parent fails as well, as in node-tap. The child's check counters are intentionally not merged into the parent totals; each test case reports only its own counters. The child's totals are, however, accumulated into <span class="doxyComputerOutput">suite</span> so that the suite summary reflects all checks performed by its test cases.</p>


<p>While the test cases are listed (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#ac4f95336439b329d0f3731a5dcafb6f9">runner_options::list_tests</a></span>), the selected test case is listed by the runner, and neither run nor counted, except in <span class="doxyComputerOutput"><a href="#aff1a81aff41ab5dc80e2fac1c5a78a31">child_test_cases_count_</a></span>.</p>


<p>After the test execution was aborted (possible only when the abort handler threw an exception, which the application caught), the report is complete, so the test case is neither run nor reported.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00553">553</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-cpp/#l00201">201</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-cpp">test.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a38cf903fb0ba5b76b1eb2350b6385962">201</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a38cf903fb0ba5b76b1eb2350b6385962">runnable_base::after_test_case_create</a> (</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">202</span><span class="doxyLineContent"><span class="doxyHighlight">                                           <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">203</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">204</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#ab7513249cc0aac30e3edd7008d08d355">runner_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#ad107cec6e32daac2da4cd665c7444e51">aborted_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">205</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">206</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">207</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">208</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">209</span><span class="doxyLineContent"><span class="doxyHighlight">      ++<a href="#aff1a81aff41ab5dc80e2fac1c5a78a31">child_test_cases_count_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">210</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">211</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// While the test cases are listed, the selected ones are listed and</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">212</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// the others ignored; none is run.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">213</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#ab7513249cc0aac30e3edd7008d08d355">runner_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#ac4f95336439b329d0f3731a5dcafb6f9">list_tests</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">214</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">215</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#ab7513249cc0aac30e3edd7008d08d355">runner_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a2b0adeef059676a455d9506ba8a06d26">is_selected</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>.<a href="#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> (), 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">216</span><span class="doxyLineContent"><span class="doxyHighlight">              &amp;&amp; <a href="#ab7513249cc0aac30e3edd7008d08d355">runner_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a2b0adeef059676a455d9506ba8a06d26">is_selected</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>.<a href="#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">217</span><span class="doxyLineContent"><span class="doxyHighlight">                                      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#af2b6792d06fa335f2b617e4d39bbba3c">nesting_depth</a> ()))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">218</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">219</span><span class="doxyLineContent"><span class="doxyHighlight">              <a href="#ab7513249cc0aac30e3edd7008d08d355">runner_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a0e478c394741ff78f65a7e2c0822ba50">list_test_case</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">220</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">221</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">222</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">223</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">224</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// Skip the test cases not selected by the filter; the outer test</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">225</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// cases, if any, were selected, otherwise this one was not created.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">226</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (!<a href="#ab7513249cc0aac30e3edd7008d08d355">runner_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a2b0adeef059676a455d9506ba8a06d26">is_selected</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>.<a href="#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> (), 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">227</span><span class="doxyLineContent"><span class="doxyHighlight">          || !<a href="#ab7513249cc0aac30e3edd7008d08d355">runner_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a2b0adeef059676a455d9506ba8a06d26">is_selected</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>.<a href="#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">228</span><span class="doxyLineContent"><span class="doxyHighlight">                                   <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#af2b6792d06fa335f2b617e4d39bbba3c">nesting_depth</a> ()))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">229</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">230</span><span class="doxyLineContent"><span class="doxyHighlight">          <a href="#a7e4a578732a0464480e211f6591fa69f">test_reporter</a> ().<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a1986653001ad23e18de13822bbcd022f">skip_test_case</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">231</span><span class="doxyLineContent"><span class="doxyHighlight">          <a href="#a87091ad4653e9db854ba9d5a64b30738">totals_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a0fdafd0ee8aa838ecc833365d2b0eebb">increment_skipped_test_cases</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">232</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">233</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">234</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">235</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// Run the child test case immediately, as the innermost running test</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">236</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// case of the runner. The outer one is restored by the guard, also</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">237</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// when an exception leaves run() (for example thrown by an abort</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">238</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// handler), so that the runner never keeps a destroyed test case.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">239</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">240</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">struct </span><span class="doxyHighlight">running_guard</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">241</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">242</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>*&amp; running;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">243</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>* outer;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">244</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">245</span><span class="doxyLineContent"><span class="doxyHighlight">          ~running_guard ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">246</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">247</span><span class="doxyLineContent"><span class="doxyHighlight">            running = outer;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">248</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">249</span><span class="doxyLineContent"><span class="doxyHighlight">        } guard{ <a href="#ab7513249cc0aac30e3edd7008d08d355">runner_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#acf5727abb4e4b23e1a2d7d3320f5dec9">running_test_case_</a>, <a href="#ab7513249cc0aac30e3edd7008d08d355">runner_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#acf5727abb4e4b23e1a2d7d3320f5dec9">running_test_case_</a> };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">250</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">251</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#ab7513249cc0aac30e3edd7008d08d355">runner_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#acf5727abb4e4b23e1a2d7d3320f5dec9">running_test_case_</a> = &amp;<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">252</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// A non-virtual call, so that run() is inlined here; each nested</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">253</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// test case adds this call chain to the stack.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">254</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>.test_case::run ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">255</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">256</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">257</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// This test executed one more test case.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">258</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">259</span><span class="doxyLineContent"><span class="doxyHighlight">      trace::printf (</span><span class="doxyHighlightStringLiteral">"%s test case '%s' executed one more test case\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">260</span><span class="doxyLineContent"><span class="doxyHighlight">                     __PRETTY_FUNCTION__, <a href="#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">261</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">262</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="#a87091ad4653e9db854ba9d5a64b30738">totals_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a21c6250b78a96ae1448a7fa93608d2d3">increment_executed_test_cases</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">263</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">264</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// Do not accumulate the totals from the child test into the current test</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">265</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// totals, each test case shows only its counters. But a failed child</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">266</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// fails this test too, as in node-tap; the failure reaches all outer</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">267</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// tests, one level at a time, when they end.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">268</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (!<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>.<a href="#aa83553cf6bf351153328304ebc71e545">totals</a> ().<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a14690f9880df505f9dd90a9f2c3dfc96">passed</a> ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">269</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">270</span><span class="doxyLineContent"><span class="doxyHighlight">          <a href="#a87091ad4653e9db854ba9d5a64b30738">totals_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a80c4365daa5804dc8ea52c7a5531e4cd">increment_failed_test_cases</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">271</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">272</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">273</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">274</span><span class="doxyLineContent"><span class="doxyHighlight">      trace::printf (</span><span class="doxyHighlightStringLiteral">"%s suite '%s' totals\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">275</span><span class="doxyLineContent"><span class="doxyHighlight">                     <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>.<a href="#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">276</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">277</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">278</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// Accumulate the totals from the child test into the suite totals.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">279</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>.<a href="#a87091ad4653e9db854ba9d5a64b30738">totals_</a> += <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>.<a href="#aa83553cf6bf351153328304ebc71e545">totals</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">280</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#ad107cec6e32daac2da4cd665c7444e51">micro_os_plus::micro_test_plus::runner::aborted_</a>, <a href="#aff1a81aff41ab5dc80e2fac1c5a78a31">child_test_cases_count_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a21c6250b78a96ae1448a7fa93608d2d3">micro_os_plus::micro_test_plus::counters::increment_executed_test_cases</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a80c4365daa5804dc8ea52c7a5531e4cd">micro_os_plus::micro_test_plus::counters::increment_failed_test_cases</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a0fdafd0ee8aa838ecc833365d2b0eebb">micro_os_plus::micro_test_plus::counters::increment_skipped_test_cases</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a2b0adeef059676a455d9506ba8a06d26">micro_os_plus::micro_test_plus::runner::is_selected</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a0e478c394741ff78f65a7e2c0822ba50">micro_os_plus::micro_test_plus::runner::list_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#ac4f95336439b329d0f3731a5dcafb6f9">micro_os_plus::micro_test_plus::runner_options::list_tests</a>, <a href="#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#af2b6792d06fa335f2b617e4d39bbba3c">micro_os_plus::micro_test_plus::test_case::nesting_depth</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#acea30e98ccf65d97e8c0e0d0ff8edda0">micro_os_plus::micro_test_plus::runner::options_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a14690f9880df505f9dd90a9f2c3dfc96">micro_os_plus::micro_test_plus::counters::passed</a>, <a href="#ab7513249cc0aac30e3edd7008d08d355">runner_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#acf5727abb4e4b23e1a2d7d3320f5dec9">micro_os_plus::micro_test_plus::runner::running_test_case_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a1986653001ad23e18de13822bbcd022f">micro_os_plus::micro_test_plus::detail::reporter::skip_test_case</a>, <a href="#a7e4a578732a0464480e211f6591fa69f">test_reporter</a>, <a href="#aa83553cf6bf351153328304ebc71e545">totals</a> and <a href="#a87091ad4653e9db854ba9d5a64b30738">totals_</a>.</p>


<p>Referenced by <a href="#ad4ac49522cfd6e1608d9ac64ab7a8b91">create_test_case</a> and <a href="#a1bffa5c8f05ffb464857521badd6ecef">run</a>.</p>

</div>
</div>

### create\_test\_case() {#ad4ac49522cfd6e1608d9ac64ab7a8b91}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;typename Callable_T, typename... Args_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::runnable_base::create_test_case (const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name">test_case_name</a> &amp; name, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a> &amp; parent_suite, size_t nesting_depth, Callable_T &amp;&amp; callable, Args_T &amp;&amp;... arguments)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
<span class="doxyMemberLabel protected">protected</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Creates a child test case, and runs it.</p>


<p>The common body of <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a402696dc4d4978ff3c050427890cfe01">suite::test()</a></span> and <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#aac23ee148d8e5946cd87e0de036e9fb8">test_case::test()</a></span>, which differ only in the parent suite and the nesting depth of the test cases they create.</p>


<p>Always inlined into them, even without optimisations, since each nested test case adds one call chain to the stack, and a separate frame for this function would make it longer.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Callable_T</td>
<td class="doxyParamItemDescription"><p>The type of a callable object.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Args_T</td>
<td class="doxyParamItemDescription"><p>The types of the callable arguments.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">name</td>
<td class="doxyParamItemDescription"><p>The test case name or description, used in reports, and the location of the call to <span class="doxyComputerOutput">test()</span>.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">parent_suite</td>
<td class="doxyParamItemDescription"><p>The suite to which the test case belongs.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">nesting_depth</td>
<td class="doxyParamItemDescription"><p>The depth of nesting of the test case; 1 for the direct children of a suite.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">callable</td>
<td class="doxyParamItemDescription"><p>A generic callable object, usually a lambda, invoked to perform the test.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">arguments</td>
<td class="doxyParamItemDescription"><p>A possibly empty list of arguments to be passed to the callable.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Binds the callable and its arguments into a local body, constructs the child <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a></span> as a local object that refers to the body, with the next test point number of this node as its index, then passes it to <span class="doxyComputerOutput"><a href="#a38cf903fb0ba5b76b1eb2350b6385962">after_test_case_create()</a></span>, which counts and runs it.</p>


<p>The child test case and its body, with the copies of the arguments, are destroyed when this function returns, so the memory used by a test session does not grow with the number of test cases; the stack holds one test case and one body for each level of nesting being run. Since the body is not stored in a <span class="doxyComputerOutput">std::function</span>, it is never allocated, whatever the size of the lambda captures and of the arguments.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00584">584</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00207">207</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ad4ac49522cfd6e1608d9ac64ab7a8b91">207</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#ad4ac49522cfd6e1608d9ac64ab7a8b91">runnable_base::create_test_case</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name">test_case_name</a>&amp; <a href="#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">208</span><span class="doxyLineContent"><span class="doxyHighlight">                                     <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp; parent_suite, </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> nesting_depth,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">209</span><span class="doxyLineContent"><span class="doxyHighlight">                                     Callable_T&amp;&amp; callable,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">210</span><span class="doxyLineContent"><span class="doxyHighlight">                                     Args_T&amp;&amp;... arguments)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">211</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">212</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> own_index = <a href="#a0d131770fe8aed387ca6da982f1ff60e">next_test_point_number</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">213</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> body = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a6abb44ef8226b1f80aad8010b5ef1a5c">bind_callable&lt;class test_case&gt;</a> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">214</span><span class="doxyLineContent"><span class="doxyHighlight">          std::forward&lt;Callable_T&gt; (callable),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">215</span><span class="doxyLineContent"><span class="doxyHighlight">          std::forward&lt;Args_T&gt; (arguments)...);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">216</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a> child_test_case{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">217</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>,      <a href="#ab7513249cc0aac30e3edd7008d08d355">runner_</a>,       parent_suite,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">218</span><span class="doxyLineContent"><span class="doxyHighlight">        own_index, nesting_depth, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref">callable_ref&lt;class test_case&gt;</a>{ body }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">219</span><span class="doxyLineContent"><span class="doxyHighlight">      };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">220</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">221</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="#a38cf903fb0ba5b76b1eb2350b6385962">after_test_case_create</a> (child_test_case, parent_suite);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">222</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="#a38cf903fb0ba5b76b1eb2350b6385962">after_test_case_create</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a6abb44ef8226b1f80aad8010b5ef1a5c">micro_os_plus::micro_test_plus::detail::bind_callable</a>, <a href="#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, <a href="#a0d131770fe8aed387ca6da982f1ff60e">next_test_point_number</a> and <a href="#ab7513249cc0aac30e3edd7008d08d355">runner_</a>.</p>


<p>Referenced by <a href="#a1bffa5c8f05ffb464857521badd6ecef">run</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a402696dc4d4978ff3c050427890cfe01">micro_os_plus::micro_test_plus::suite::test</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#aac23ee148d8e5946cd87e0de036e9fb8">micro_os_plus::micro_test_plus::test_case::test</a>.</p>

</div>
</div>

### is\_aborted() {#aaec8b378e1d1639a5fa0e6dec20d6a46}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::detail::runnable_base::is_aborted (void)</td>
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

<p>Checks whether the test execution was aborted by the owning runner.</p>


<p>Protected, since it is used only by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#adb4333ecb107fee477156b661f0b1512">test_case::run()</a></span> and <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a432deda5a8721472e8775cbc98451722">suite::run()</a></span>, to pass on an exception thrown by the abort handler, instead of reporting it as unexpected.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p><span class="doxyComputerOutput">true</span> once <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a7bc806540e65c21095ef1ea1ef970db2">runner::abort()</a></span> was called.</p></dd>
</dl>


<p>Returns the flag kept by the owning runner, set by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a7bc806540e65c21095ef1ea1ef970db2">runner::abort()</a></span> and never cleared.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00505">505</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-cpp/#l00137">137</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-cpp">test.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aaec8b378e1d1639a5fa0e6dec20d6a46">137</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#aaec8b378e1d1639a5fa0e6dec20d6a46">runnable_base::is_aborted</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">138</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">139</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#ab7513249cc0aac30e3edd7008d08d355">runner_</a>.aborted_;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">140</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="#ab7513249cc0aac30e3edd7008d08d355">runner_</a>.</p>


<p>Referenced by <a href="#a1bffa5c8f05ffb464857521badd6ecef">run</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a432deda5a8721472e8775cbc98451722">micro_os_plus::micro_test_plus::suite::run</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#adb4333ecb107fee477156b661f0b1512">micro_os_plus::micro_test_plus::test_case::run</a>.</p>

</div>
</div>

### is\_listing() {#a58c3051635ce2389a8afc2222cd6b30d}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::detail::runnable_base::is_listing (void)</td>
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

<p>Checks whether the owning runner lists the test cases instead of running them.</p>


<p>Protected, since it is used only by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a432deda5a8721472e8775cbc98451722">suite::run()</a></span>, which then calls the suite body without reporting the suite, so that its test cases are created, and listed instead of run.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p><span class="doxyComputerOutput">true</span> if <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#ac4f95336439b329d0f3731a5dcafb6f9">runner_options::list_tests</a></span> was set.</p></dd>
</dl>


<p>Returns <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#ac4f95336439b329d0f3731a5dcafb6f9">runner_options::list_tests</a></span> of the session options kept by the owning runner.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00521">521</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-cpp/#l00148">148</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-cpp">test.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a58c3051635ce2389a8afc2222cd6b30d">148</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a58c3051635ce2389a8afc2222cd6b30d">runnable_base::is_listing</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">149</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">150</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#ab7513249cc0aac30e3edd7008d08d355">runner_</a>.options_.list_tests;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">151</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="#ab7513249cc0aac30e3edd7008d08d355">runner_</a>.</p>


<p>Referenced by <a href="#a1bffa5c8f05ffb464857521badd6ecef">run</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a432deda5a8721472e8775cbc98451722">micro_os_plus::micro_test_plus::suite::run</a>.</p>

</div>
</div>

### next\_test\_point\_number() {#a0d131770fe8aed387ca6da982f1ff60e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">size_t micro_os_plus::micro_test_plus::detail::runnable_base::next_test_point_number (void)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
<span class="doxyMemberLabel protected">protected</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Advances to the next child test point, and returns its number.</p>


<p>Called for each check (by the check result, when the check is reported) and for each nested test case created.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The one-based number of the new test point.</p></dd>
</dl>


<p>Each call to <span class="doxyComputerOutput">test()</span> invokes this member function before constructing the new <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a></span>, and each check invokes it from the check result destructor, when the check is reported, so the numbers form a strictly increasing, one-based sequence of TAP test points, in output order.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00536">536</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00175">175</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a0d131770fe8aed387ca6da982f1ff60e">175</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a0d131770fe8aed387ca6da982f1ff60e">runnable_base::next_test_point_number</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">176</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">177</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> ++<a href="#abc92cbb8ab8d04e7c75bf18aa7189d98">test_point_number_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">178</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="#abc92cbb8ab8d04e7c75bf18aa7189d98">test_point_number_</a>.</p>


<p>Referenced by <a href="#ad4ac49522cfd6e1608d9ac64ab7a8b91">create_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a1d15dd97c94c3dabccb9e5a7444af0ec">micro_os_plus::micro_test_plus::suite::fail_unexpected_exception</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a1980019eed5ac5b1eef65302eb9cc9cd">micro_os_plus::micro_test_plus::test_case::fail_unexpected_exception</a> and <a href="#a1bffa5c8f05ffb464857521badd6ecef">run</a>.</p>

</div>
</div>

### running\_test\_case() {#a3fd5730af8bd449cc56e29d5d14509e9}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_case * micro_os_plus::micro_test_plus::detail::runnable_base::running_test_case (void)</td>
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

<p>Gets the innermost test case being run by the owning runner, if any.</p>


<p>Protected, since it is used only by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a402696dc4d4978ff3c050427890cfe01">suite::test()</a></span>, to run a test case started on the suite from inside a running test case as a nested test case of it.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A pointer to the running test case, or <span class="doxyComputerOutput">nullptr</span> when no test case is running.</p></dd>
</dl>


<p>Returns the pointer kept by the owning runner, set by <span class="doxyComputerOutput"><a href="#a38cf903fb0ba5b76b1eb2350b6385962">after_test_case_create()</a></span> while a test case runs.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00489">489</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-cpp/#l00126">126</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-cpp">test.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a3fd5730af8bd449cc56e29d5d14509e9">126</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a3fd5730af8bd449cc56e29d5d14509e9">runnable_base::running_test_case</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">127</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">128</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#ab7513249cc0aac30e3edd7008d08d355">runner_</a>.running_test_case_;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">129</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="#ab7513249cc0aac30e3edd7008d08d355">runner_</a>.</p>


<p>Referenced by <a href="#a1bffa5c8f05ffb464857521badd6ecef">run</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a402696dc4d4978ff3c050427890cfe01">micro_os_plus::micro_test_plus::suite::test</a>.</p>

</div>
</div>

### test\_reporter() {#a7e4a578732a0464480e211f6591fa69f}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">reporter &amp; micro_os_plus::micro_test_plus::detail::runnable_base::test_reporter (void)</td>
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

<p>Gets the test reporter associated with this test runnable.</p>


<p>Protected, since the reporter is internal to the framework; it is used by the suites and the test cases, which derive from this class, and by the check result, which is a friend.</p>


<p>Not named <span class="doxyComputerOutput">reporter()</span>, which would hide the class <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">detail::reporter</a></span> in the derived classes.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A reference to the test reporter.</p></dd>
</dl>


<p>Returns the reporter owned by the runner, through its <span class="doxyComputerOutput">reporter_</span> pointer, which is valid after <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a39ee9ec53f8df687cd84092de5118592">runner::initialise()</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00472">472</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-cpp/#l00115">115</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-cpp">test.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a7e4a578732a0464480e211f6591fa69f">115</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a7e4a578732a0464480e211f6591fa69f">runnable_base::test_reporter</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">116</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">117</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *<a href="#ab7513249cc0aac30e3edd7008d08d355">runner_</a>.reporter_;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">118</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="#ab7513249cc0aac30e3edd7008d08d355">runner_</a>.</p>


<p>Referenced by <a href="#a38cf903fb0ba5b76b1eb2350b6385962">after_test_case_create</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#af4f5f9632b5a290c1894984661a41a86">micro_os_plus::micro_test_plus::test_case::expect</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a1d15dd97c94c3dabccb9e5a7444af0ec">micro_os_plus::micro_test_plus::suite::fail_unexpected_exception</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a1980019eed5ac5b1eef65302eb9cc9cd">micro_os_plus::micro_test_plus::test_case::fail_unexpected_exception</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#ace68a1bd4dd258082f4b1fc01fcd008a">micro_os_plus::micro_test_plus::test_case::require</a>, <a href="#a1bffa5c8f05ffb464857521badd6ecef">run</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a432deda5a8721472e8775cbc98451722">micro_os_plus::micro_test_plus::suite::run</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#adb4333ecb107fee477156b661f0b1512">micro_os_plus::micro_test_plus::test_case::run</a>.</p>

</div>
</div>

### test\_runner() {#a0224080b4433f538798354eca0f4c8c5}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">runner &amp; micro_os_plus::micro_test_plus::detail::runnable_base::test_runner (void)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
<span class="doxyMemberLabel protected">protected</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Gets the test runner that owns this test runnable.</p>


<p>Protected, since the runner is internal to the framework; it is used by the suites and the test cases, which derive from this class and pass it to their nested test cases, and by the runner, which is a friend and selects the static suites it runs.</p>


<p>Not named <span class="doxyComputerOutput"><a href="#a68a030feff1f481126e9a6d170331420">runner()</a></span>, which would hide the class <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">runner</a></span> in the derived classes.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A reference to the test runner.</p></dd>
</dl>


<p>Returns a reference to the owning test runner.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00454">454</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00185">185</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a0224080b4433f538798354eca0f4c8c5">185</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a0224080b4433f538798354eca0f4c8c5">runnable_base::test_runner</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">186</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">187</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#ab7513249cc0aac30e3edd7008d08d355">runner_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">188</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="#ab7513249cc0aac30e3edd7008d08d355">runner_</a>.</p>


<p>Referenced by <a href="#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#aee03f72ebd3b2ff8e670b00e07d7f729">micro_os_plus::micro_test_plus::static_suite::static_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a0232c48687da2eb3a2171d8647ffb0a6">micro_os_plus::micro_test_plus::suite::suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a0ffeed47bd9ecd07bda3a2f33f062b71">micro_os_plus::micro_test_plus::test_case::test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#ac10e4f707de47389f43c38d420ce13e9">micro_os_plus::micro_test_plus::top_suite::top_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a6cd3b3f893312fe43fa2d7b5018646e9">micro_os_plus::micro_test_plus::suite::detail::reporter_tap</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a484008ed66130a2bf334948841099943">micro_os_plus::micro_test_plus::test_case::detail::runnable_base</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#a7ac8520c7d0761e54e7482ca5d7e26f2">micro_os_plus::micro_test_plus::static_suite::link_or_reject</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#a68a030feff1f481126e9a6d170331420">micro_os_plus::micro_test_plus::top_suite::micro_test_plus::runner</a>, <a href="#ac6f88fbc9f895d8d7495393d1a9a7d6a">reporter_tap</a> and <a href="#a1bffa5c8f05ffb464857521badd6ecef">run</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Private Member Functions

### abort() {#a5fec64d9b300277d56e02193bb7d0a46}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::runnable_base::abort (const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> &amp; sl=<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a>())</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Aborts test execution via the owning runner, for a failed requirement.</p>


<p>Private, since it is used only by the check result, a friend, for a failed requirement without exceptions; the user code calls <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a7bc806540e65c21095ef1ea1ef970db2">runner::abort()</a></span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">sl</td>
<td class="doxyParamItemDescription"><p>The source location from which the abort is triggered.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Does not return.</p></dd>
</dl>


<p>Delegates to the private <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a7bc806540e65c21095ef1ea1ef970db2">runner::abort()</a></span>, as caused by a failed requirement, passing the supplied source location, so that the report identifies it. The runner then calls the abort handler, if any, and terminates the process via <span class="doxyComputerOutput">::abort()</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00433">433</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-cpp/#l00161">161</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-cpp">test.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a5fec64d9b300277d56e02193bb7d0a46">161</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a5fec64d9b300277d56e02193bb7d0a46">runnable_base::abort</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; sl)</span><span class="doxyHighlightKeyword"> const</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">162</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">    </span><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">163</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="#ab7513249cc0aac30e3edd7008d08d355">runner_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a7bc806540e65c21095ef1ea1ef970db2">abort</a> (sl, </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">164</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a7bc806540e65c21095ef1ea1ef970db2">micro_os_plus::micro_test_plus::runner::abort</a> and <a href="#ab7513249cc0aac30e3edd7008d08d355">runner_</a>.</p>


<p>Referenced by <a href="#a1bffa5c8f05ffb464857521badd6ecef">run</a>.</p>

</div>
</div>

### run() {#a1bffa5c8f05ffb464857521badd6ecef}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">virtual void micro_os_plus::micro_test_plus::detail::runnable_base::run (void)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Runs the body of the test case or suite.</p>


<p>Implemented by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a></span> and <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a></span>, which invoke the stored callable surrounded by the reporter notifications.</p>


<p>Private, since the nodes are run only by the framework: the test cases by <span class="doxyComputerOutput"><a href="#a38cf903fb0ba5b76b1eb2350b6385962">after_test_case_create()</a></span>, when they are created, and the suites by the runner, which is a friend; a second run would report the node twice.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00416">416</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<p>References <a href="#a5fec64d9b300277d56e02193bb7d0a46">abort</a>, <a href="#a38cf903fb0ba5b76b1eb2350b6385962">after_test_case_create</a>, <a href="#ad4ac49522cfd6e1608d9ac64ab7a8b91">create_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">micro_os_plus::micro_test_plus::reflection::source_location::current</a>, <a href="#aaec8b378e1d1639a5fa0e6dec20d6a46">is_aborted</a>, <a href="#a58c3051635ce2389a8afc2222cd6b30d">is_listing</a>, <a href="#a68a030feff1f481126e9a6d170331420">micro_test_plus::runner</a>, <a href="#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, <a href="#a0d131770fe8aed387ca6da982f1ff60e">next_test_point_number</a>, <a href="#a3fd5730af8bd449cc56e29d5d14509e9">running_test_case</a>, <a href="#a7e4a578732a0464480e211f6591fa69f">test_reporter</a> and <a href="#a0224080b4433f538798354eca0f4c8c5">test_runner</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Protected Member Attributes

### child\_test\_cases\_count\_ {#aff1a81aff41ab5dc80e2fac1c5a78a31}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">size_t micro_os_plus::micro_test_plus::detail::runnable_base::child_test_cases_count_ = 0</td>
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

<p>The number of direct child test cases.</p>


<p>Incremented for each call to <span class="doxyComputerOutput">test()</span>, which creates a child <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a></span> and runs it immediately. The child test cases are not kept after they run, so that the memory does not grow with the number of test cases; only their number is needed later, for the TAP plan.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00657">657</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aff1a81aff41ab5dc80e2fac1c5a78a31">657</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="#aff1a81aff41ab5dc80e2fac1c5a78a31">child_test_cases_count_</a> = 0;</span></span></div>

</div>


<p>Referenced by <a href="#a38cf903fb0ba5b76b1eb2350b6385962">after_test_case_create</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a2d5ddae3195ab52a957927a1b455f7b8">micro_os_plus::micro_test_plus::detail::reporter_tap::end_suite</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#ad15f7dbbf6a683441df40c502125adc3">micro_os_plus::micro_test_plus::detail::reporter_tap::end_test_case</a>.</p>

</div>
</div>

### name\_ {#aad830bd92e4f6e4239d2bb5b75d5bf50}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const char* micro_os_plus::micro_test_plus::detail::runnable_base::name_</td>
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

<p>The node name.</p>


<p>Not owned; it points to a string whose lifetime exceeds that of the node. Derived classes may access this member directly, in addition to the public <span class="doxyComputerOutput"><a href="#a6c652cd5dc8194269c1cc5f0dc1945e0">name()</a></span> getter.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00597">597</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aad830bd92e4f6e4239d2bb5b75d5bf50">597</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* <a href="#aad830bd92e4f6e4239d2bb5b75d5bf50">name_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a0232c48687da2eb3a2171d8647ffb0a6">micro_os_plus::micro_test_plus::suite::suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a0ffeed47bd9ecd07bda3a2f33f062b71">micro_os_plus::micro_test_plus::test_case::test_case</a>, <a href="#a129a5382922b2be662f4f491d03750ef">~runnable_base</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#a88ca9975daf7b7b1e509114944151675">micro_os_plus::micro_test_plus::static_suite::~static_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#aa25d7d2a11b7c893d9260d562beb96fb">micro_os_plus::micro_test_plus::suite::~suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a26a1b913fdcece44668b56200298218a">micro_os_plus::micro_test_plus::test_case::~test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#aae4ef52e5ceaa29d20cf7e3be848c528">micro_os_plus::micro_test_plus::top_suite::~top_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#aac24d1193ac0579dd6ac3c523a32015f">micro_os_plus::micro_test_plus::runner::add_top_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a532459c0a6362991282548f4f845cb97">micro_os_plus::micro_test_plus::suite::link</a>, <a href="#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a432deda5a8721472e8775cbc98451722">micro_os_plus::micro_test_plus::suite::run</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#adb4333ecb107fee477156b661f0b1512">micro_os_plus::micro_test_plus::test_case::run</a>.</p>

</div>
</div>

### own\_index\_ {#a69687627342981d42471b17f1d83311f}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">size_t micro_os_plus::micro_test_plus::detail::runnable_base::own_index_</td>
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

<p>The test index, counting from 1.</p>


<p>The position of this object within its parent, displayed by the TAP reporter in the <span class="doxyComputerOutput">ok</span>/<span class="doxyComputerOutput">not ok</span> lines. Set directly by the runner, which numbers the suites when it runs them, and by the top suite, which, when added, is always the first one.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00633">633</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a69687627342981d42471b17f1d83311f">633</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="#a69687627342981d42471b17f1d83311f">own_index_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a0232c48687da2eb3a2171d8647ffb0a6">micro_os_plus::micro_test_plus::suite::suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a0ffeed47bd9ecd07bda3a2f33f062b71">micro_os_plus::micro_test_plus::test_case::test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#ac10e4f707de47389f43c38d420ce13e9">micro_os_plus::micro_test_plus::top_suite::top_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a2d5ddae3195ab52a957927a1b455f7b8">micro_os_plus::micro_test_plus::detail::reporter_tap::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#ad15f7dbbf6a683441df40c502125adc3">micro_os_plus::micro_test_plus::detail::reporter_tap::end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a319f35d4af8c72af8b14a89b421c1c74">micro_os_plus::micro_test_plus::detail::reporter_tap::skip_suite</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a31ccd7af941d06241ce16df9274abc38">micro_os_plus::micro_test_plus::detail::reporter_tap::skip_test_case</a>.</p>

</div>
</div>

### runner\_ {#ab7513249cc0aac30e3edd7008d08d355}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">runner&amp; micro_os_plus::micro_test_plus::detail::runnable_base::runner_</td>
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

<p>Reference to the test runner that owns this object.</p>


<p>Provides access to the reporter, to the filter, and to the state of the session (the running test case, and the abort and listing flags), and is used when aborting.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00622">622</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ab7513249cc0aac30e3edd7008d08d355">622</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="#a68a030feff1f481126e9a6d170331420">runner</a>&amp; <a href="#ab7513249cc0aac30e3edd7008d08d355">runner_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a>, <a href="#a5fec64d9b300277d56e02193bb7d0a46">abort</a>, <a href="#a38cf903fb0ba5b76b1eb2350b6385962">after_test_case_create</a>, <a href="#ad4ac49522cfd6e1608d9ac64ab7a8b91">create_test_case</a>, <a href="#aaec8b378e1d1639a5fa0e6dec20d6a46">is_aborted</a>, <a href="#a58c3051635ce2389a8afc2222cd6b30d">is_listing</a>, <a href="#a3fd5730af8bd449cc56e29d5d14509e9">running_test_case</a>, <a href="#a7e4a578732a0464480e211f6591fa69f">test_reporter</a> and <a href="#a0224080b4433f538798354eca0f4c8c5">test_runner</a>.</p>

</div>
</div>

### test\_point\_number\_ {#abc92cbb8ab8d04e7c75bf18aa7189d98}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">size_t micro_os_plus::micro_test_plus::detail::runnable_base::test_point_number_ = 0</td>
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

<p>The number of the most recent child test point.</p>


<p>Test points are numbered from 1; the value is 0 before the first one. This number counts the checks and the nested test cases of this object, in execution order, as required by the TAP <span class="doxyComputerOutput">ok</span>/<span class="doxyComputerOutput">not ok</span> lines. It is incremented for each check (by the check result) and for each nested test case created.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00645">645</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#abc92cbb8ab8d04e7c75bf18aa7189d98">645</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="#abc92cbb8ab8d04e7c75bf18aa7189d98">test_point_number_</a> = 0;</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a2d5ddae3195ab52a957927a1b455f7b8">micro_os_plus::micro_test_plus::detail::reporter_tap::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a314df80e98fe6fa5de008d6708a14925">micro_os_plus::micro_test_plus::detail::reporter_tap::fail_suite</a>, <a href="#a0d131770fe8aed387ca6da982f1ff60e">next_test_point_number</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a3bd1c7d455abc782062d0e23a3ef1015">micro_os_plus::micro_test_plus::detail::reporter_tap::output_fail_prefix</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#ac6c05f92e47ad71f72b44f9beb0b98f1">micro_os_plus::micro_test_plus::detail::reporter_tap::output_pass_prefix</a>.</p>

</div>
</div>

### totals\_ {#a87091ad4653e9db854ba9d5a64b30738}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">counters micro_os_plus::micro_test_plus::detail::runnable_base::totals_</td>
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

<p>Totals for the node.</p>


<p>For the suites, the totals include the checks of all their test cases; for a test case, they include only its own checks, plus the counts of its direct nested test cases.</p>


<p>The check counters are updated by the check result, which is a friend; the test case counters by <span class="doxyComputerOutput"><a href="#a38cf903fb0ba5b76b1eb2350b6385962">after_test_case_create()</a></span>, when a nested test case ends. For a suite, the totals of each of its test cases are also added, by the same function.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00612">612</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a87091ad4653e9db854ba9d5a64b30738">612</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters">counters</a> <a href="#a87091ad4653e9db854ba9d5a64b30738">totals_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#a38cf903fb0ba5b76b1eb2350b6385962">after_test_case_create</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a1d15dd97c94c3dabccb9e5a7444af0ec">micro_os_plus::micro_test_plus::suite::fail_unexpected_exception</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a1980019eed5ac5b1eef65302eb9cc9cd">micro_os_plus::micro_test_plus::test_case::fail_unexpected_exception</a> and <a href="#aa83553cf6bf351153328304ebc71e545">totals</a>.</p>

</div>
</div>

</div>

<hr/>

The documentation for this class was generated from the following files:

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/src/test-cpp">test.cpp</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
