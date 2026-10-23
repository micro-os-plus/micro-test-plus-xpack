---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/classes/micro-os-plus/micro-test-plus/runner
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - class

---

<div class="doxyPage">

# `runner` Class

<p>The test runner for the µTest++ framework. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
class micro_os_plus::micro_test_plus::runner { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>"
</div>

## Public Member Typedefs Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ab5b0711c5f1ab3063c410c1b9a76707b">abort_handler_t</a> = void(*)(const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> &amp;sl)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The type of the function called when test execution is aborted. <a href="#ab5b0711c5f1ab3063c410c1b9a76707b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Enumerations Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">enum class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top">session_state { <a href="#a081c4bd4495097c8c7f913ef837899ba">...</a> }</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The states of a test session. <a href="#a081c4bd4495097c8c7f913ef837899ba">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a099a369b6d1f67c296baf9d22be40ba2">detail::reporter_human</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The human reporter, which displays the session. <a href="#a099a369b6d1f67c296baf9d22be40ba2">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a6cd3b3f893312fe43fa2d7b5018646e9">detail::reporter_tap</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The TAP reporter, which displays the session. <a href="#a6cd3b3f893312fe43fa2d7b5018646e9">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a484008ed66130a2bf334948841099943">detail::runnable_base</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The base of the nodes, which shares the state of the session. <a href="#a484008ed66130a2bf334948841099943">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a10788baa079e19676a8cdbaa253285dc">runner</a> (const char *top_suite_name)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deprecated constructor for the runner class. <a href="#a10788baa079e19676a8cdbaa253285dc">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#adbe02fed3c414adf001d856ab390e000">runner</a> (const runner &amp;)=delete</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deleted copy constructor to prevent copying. <a href="#adbe02fed3c414adf001d856ab390e000">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a09acf1e03953d8017e56c8b5e38b879a">runner</a> (runner &amp;&amp;)=delete</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deleted move constructor to prevent moving. <a href="#a09acf1e03953d8017e56c8b5e38b879a">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a5e2001730fd3659e9045fcc5cc668f07">runner</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructor for the runner class. <a href="#a5e2001730fd3659e9045fcc5cc668f07">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aea1a1eff9cac943c1cd84e48b9add92f">~runner</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Destructor for the runner class. <a href="#aea1a1eff9cac943c1cd84e48b9add92f">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Operators Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a5e2001730fd3659e9045fcc5cc668f07">runner</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a549524d15dc1eb5e6b4eb4bdd2af7b6b">operator=</a> (const runner &amp;)=delete</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deleted copy assignment operator to prevent copying. <a href="#a549524d15dc1eb5e6b4eb4bdd2af7b6b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a5e2001730fd3659e9045fcc5cc668f07">runner</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aa34a0418d54c633630a089eb2b5a61ee">operator=</a> (runner &amp;&amp;)=delete</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deleted move assignment operator to prevent moving. <a href="#aa34a0418d54c633630a089eb2b5a61ee">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a7bc806540e65c21095ef1ea1ef970db2">abort</a> (const reflection::source_location &amp;sl=reflection::source_location::current())</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Aborts test execution immediately. <a href="#a7bc806540e65c21095ef1ea1ef970db2">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite</a> (std::string_view name, Callable_T &amp;&amp;callable, Args_T &amp;&amp;... arguments)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Adds a test suite to the runner, to be run by <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span>. <a href="#a4069fe957bbc7a9217ca2dd4d2034a97">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">size_t</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a9484b22aa909151712144cd39130187a">added_suites_count</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns the count of the test suites added with <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span>. <a href="#a9484b22aa909151712144cd39130187a">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a7f8403f1ccc6a0e8171ef077bcd9cbd4">exit_code</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deprecated name of <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span>. <a href="#a7f8403f1ccc6a0e8171ef077bcd9cbd4">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ac40f554936c71d7c748c1241ffd3f2ac">initialise</a> (const runner_options &amp;options, const char *top_suite_name="")</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Initialises the test runner with the given options. <a href="#ac40f554936c71d7c748c1241ffd3f2ac">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise</a> (int argc, char *argv[], const char *top_suite_name="")</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Initialises the test runner with command-line arguments. <a href="#acfabd0e10d233ad305b6f4fc125a97f2">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ae5df469f7aaccc8e24bfadff4c209688">is_listing</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Checks whether the test cases are listed instead of run. <a href="#ae5df469f7aaccc8e24bfadff4c209688">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">detail::reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a65250ff363fbb3b5869bbe4de9578e86">reporter</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deprecated access to the reporter of the test session. <a href="#a65250ff363fbb3b5869bbe4de9578e86">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Runs the registered suites, ends the session, and returns the exit code. <a href="#a97f725cb167a2b464fac0eb88a0c8a46">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#ab5b0711c5f1ab3063c410c1b9a76707b">abort_handler_t</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a711756a8c6958c4036527a290c481f86">set_abort_handler</a> (abort_handler_t handler) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Sets the function called when test execution is aborted. <a href="#a711756a8c6958c4036527a290c481f86">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">size_t</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a2c2a6d7cb45b714026d124d0ca432360">skipped_suites_count</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns the count of the test suites skipped by the filter. <a href="#a2c2a6d7cb45b714026d124d0ca432360">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">size_t</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a67d3cf710cccd419c127e63c2c30e9fe">static_suites_count</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns the count of static test suites. <a href="#a67d3cf710cccd419c127e63c2c30e9fe">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a> (std::string_view name, Callable_T &amp;&amp;callable, Args_T &amp;&amp;... arguments)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deprecated name of <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span>. <a href="#a2636252ac7f80b7425cf2e5eced77834">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">size_t</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a6ed3a02ced62ed475c75678cd9e91be1">suites_count</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deprecated count of the test suites added with <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span>, plus the top suite. <a href="#a6ed3a02ced62ed475c75678cd9e91be1">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch">detail::stopwatch</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#af314280f14d61d37da276567685ec2a8">timings</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deprecated access to the timings of the test session. <a href="#af314280f14d61d37da276567685ec2a8">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch">detail::stopwatch</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a7d3ccfaf760cb2f4ace586c222b22244">timings</a> (void) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deprecated access to the timings of the test session, as a non-<span class="doxyComputerOutput">const</span> reference. <a href="#a7d3ccfaf760cb2f4ace586c222b22244">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">size_t</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ac29e4b993bb3fe795eb8900231cbf5c4">total_suites_count</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns the count of all the test suites. <a href="#ac29e4b993bb3fe795eb8900231cbf5c4">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters">counters</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a2c8a999cc273356ea10ed34fb12dcf5a">totals</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Gets the totals of the test session. <a href="#a2c8a999cc273356ea10ed34fb12dcf5a">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914b">micro_test_plus::verbosity</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a94a9df0418776ebce476cd9a2e4f591f">verbosity</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deprecated name of <span class="doxyComputerOutput"><a href="#a1dd0221dca8e7382f0b625ff6316ed92">verbosity_level()</a></span>. <a href="#a94a9df0418776ebce476cd9a2e4f591f">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914b">micro_test_plus::verbosity</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a1dd0221dca8e7382f0b625ff6316ed92">verbosity_level</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns the verbosity level of the console output. <a href="#a1dd0221dca8e7382f0b625ff6316ed92">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#af0682165f5d07b13fd21e3f6f8da546c">abort</a> (const reflection::source_location &amp;sl, bool is_requirement)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Aborts test execution, telling the reporter why. <a href="#af0682165f5d07b13fd21e3f6f8da546c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a2b0adeef059676a455d9506ba8a06d26">is_selected</a> (const char *name, size_t level) const</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Checks whether a suite or a test case is selected by the filter pattern of its nesting level. <a href="#a2b0adeef059676a455d9506ba8a06d26">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a0e478c394741ff78f65a7e2c0822ba50">list_test_case</a> (const class suite &amp;suite, const class test_case &amp;test_case)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Lists a test case, instead of running it. <a href="#a0e478c394741ff78f65a7e2c0822ba50">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options">runner_options</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a2319eb34fc8b601ca5e6a8ec538ba138">parse_options</a> (int argc, char *argv[])</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Parses the command-line options of the test session. <a href="#a2319eb34fc8b601ca5e6a8ec538ba138">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a1dcc8f8d7f80044c67c492a1aebe3043">register_suite</a> (std::unique_ptr&lt; class suite &gt; suite)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Registers a test suite with the runner. <a href="#a1dcc8f8d7f80044c67c492a1aebe3043">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a7c4dbf695c086ca4d3f0ce33e6d561f7">run_suites</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Runs all registered test suites. <a href="#a7c4dbf695c086ca4d3f0ce33e6d561f7">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Private Member Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#ab5b0711c5f1ab3063c410c1b9a76707b">abort_handler_t</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a1138505536cf6afe69dea5ae044eeb5a">abort_handler_</a> = nullptr</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The function called by <span class="doxyComputerOutput"><a href="#a7bc806540e65c21095ef1ea1ef970db2">abort()</a></span>, if not null. <a href="#a1138505536cf6afe69dea5ae044eeb5a">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ad107cec6e32daac2da4cd665c7444e51">aborted_</a> = false</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Whether the test execution was aborted. <a href="#ad107cec6e32daac2da4cd665c7444e51">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">std::vector&lt; std::unique_ptr&lt; class <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a> &gt; &gt;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Owning collection of dynamically registered child suites. <a href="#abacf53ab658e289ae89051531c0cddad">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">exit_code_</a> = 1</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The exit code computed by <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span>. <a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">std::vector&lt; std::string &gt;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a12b7d597d11b0ff284cdb84a7c4ea927">filter_patterns_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The patterns that select the suites and the test cases to run, one per nesting level. <a href="#a12b7d597d11b0ff284cdb84a7c4ea927">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a8e9e6782d6cde59ac82fb6fb459888cb">has_option_errors_</a> = false</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Whether <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span> reported an option error. <a href="#a8e9e6782d6cde59ac82fb6fb459888cb">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a999d64ffbd12dcacb59c34fbea4452ba">has_rejected_suites_</a> = false</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Whether a suite was added after <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span> had started. <a href="#a999d64ffbd12dcacb59c34fbea4452ba">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a2cbcc12d72c192f6053cd342af1b5a77">list_tests_</a> = false</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Whether the test cases are listed instead of run. <a href="#a2cbcc12d72c192f6053cd342af1b5a77">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const class <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a> *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#af8ce5a496dba305f6fbd45005d580321">listed_suite_</a> = nullptr</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The suite whose name was listed last, if any. <a href="#af8ce5a496dba305f6fbd45005d580321">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">size_t</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#acb06cb7ebf949b8af5c5d57645c56e4a">listed_suites_count_</a> = 0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The number of suites with listed test cases. <a href="#acb06cb7ebf949b8af5c5d57645c56e4a">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">size_t</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a90900e7d0a4571407b3727e031e46685">listed_test_cases_count_</a> = 0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The number of listed test cases. <a href="#a90900e7d0a4571407b3727e031e46685">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">std::unique_ptr&lt; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">detail::reporter</a> &gt;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Owning pointer to the test reporter used for outputting test results. <a href="#a67205181c73d11d12964bb324f1dc902">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a> *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#acf5727abb4e4b23e1a2d7d3320f5dec9">running_test_case_</a> = nullptr</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The innermost test case being run, if any. <a href="#acf5727abb4e4b23e1a2d7d3320f5dec9">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a081c4bd4495097c8c7f913ef837899ba">session_state</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> = <a href="#a081c4bd4495097c8c7f913ef837899baae2fa538867c3830a859a5b17ab24644b">session_state::created</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The current state of the test session. <a href="#a70dad6c927a59d5459c2edfdb40fdece">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">size_t</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ae815c0c97245032223f4c1523e1d35fe">skipped_suites_count_</a> = 0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The number of suites skipped by the filter. <a href="#ae815c0c97245032223f4c1523e1d35fe">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch">detail::stopwatch</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a13b3cf196a1b12cb90a12c4b84223d15">stopwatch_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Stopwatch of this runner. <a href="#a13b3cf196a1b12cb90a12c4b84223d15">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class { ... }</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The implicit top-level suite; always present and executed first. <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">std::string</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a401e4e098f0ceba7f21a3a5bf1ea89e3">top_suite_name_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Owned storage for the implicit top-suite name. <a href="#a401e4e098f0ceba7f21a3a5bf1ea89e3">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters">counters</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a04b52f3243abe3a9b08b44efd03e4b57">totals_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Totals of the test session. <a href="#a04b52f3243abe3a9b08b44efd03e4b57">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914b">micro_test_plus::verbosity</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a1d4b6b07a507c00a5ac262e098b12ad3">verbosity_</a> = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">verbosity::normal</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The verbosity level of the console output. <a href="#a1d4b6b07a507c00a5ac262e098b12ad3">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>The test runner for the µTest++ framework.</p>


<p>The <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">runner</a></span> class is responsible for managing the registration and execution of test suites within the µTest++ framework. It owns the implicit top suite, whose test cases are added after <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span>, and a collection of test suites added with <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span>, which are run later, by <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span>. These suites and the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite">static_suite</a></span> objects that refer to the runner are kept in a single list, sorted by name, independent of the runner object, so the static suites may be constructed before it. <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span> runs the suites added with <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span> and the static suites together, in a single order, sorted by name; for equal names, in the order of their creation, so the static suites constructed before <span class="doxyComputerOutput">main()</span> run first. The names are compared byte by byte, as by <span class="doxyComputerOutput">std::strcmp()</span>, not in the order of addition: the comparison is case-sensitive (<span class="doxyComputerOutput">"Zeta"</span> before <span class="doxyComputerOutput">"alpha"</span>) and does not compare numbers by value (<span class="doxyComputerOutput">"Suite 10"</span> before <span class="doxyComputerOutput">"Suite 2"</span>); zero-padded numeric prefixes (<span class="doxyComputerOutput">"01 - Init"</span>) give an explicit order.</p>


<p>The test runner provides member functions for initialising the test environment (including the creation of the reporter selected on the command line, or by the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options">runner_options</a></span> passed to <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span>), registering test suites, and determining the overall test result via an exit code. It also offers an abort mechanism for terminating test execution in exceptional circumstances.</p>


<p>The runner is not a node of the test tree: it has no name of its own (the name shown in the reports belongs to the top suite), and it owns the session totals, which accumulate the totals of all the suites.</p>


<p>All members are defined within the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a></span> namespace, ensuring clear separation from user code and minimising the risk of naming conflicts.</p>


<p>Definition at line 165 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxySectionDef">

## Public Member Typedefs

### abort\_handler\_t {#ab5b0711c5f1ab3063c410c1b9a76707b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">using micro_os_plus::micro_test_plus::runner::abort_handler_t = void (*) (const reflection::source_location&amp; sl)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The type of the function called when test execution is aborted.</p>


<p>The handler receives the source location from which the abort was triggered. It is not expected to return; it may, for example, reset an embedded target, or signal the test result to a debugger. If it returns, the process is terminated with <span class="doxyComputerOutput">::abort()</span>.</p>


<p>When exceptions are enabled, it may also throw an exception, to return control to the application without terminating the process. The test cases and the suites do not catch it, so it leaves the <span class="doxyComputerOutput">test()</span> call that started a test case of the top suite, or <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span>, and reaches the application; their remaining code is not run. The report is complete, but the runner cannot be used afterwards (see <span class="doxyComputerOutput"><a href="#a7bc806540e65c21095ef1ea1ef970db2">abort()</a></span>).</p>


<dl class="doxySectionUser">
<dt>Since</dt>
<dd><p>5.1.0</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00453">453</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ab5b0711c5f1ab3063c410c1b9a76707b">453</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="#ab5b0711c5f1ab3063c410c1b9a76707b">abort_handler_t</a> = void (*) (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; sl);</span></span></div>

</div>

</div>
</div>

</div>

<div class="doxySectionDef">

## Enumerations

### session\_state {#a081c4bd4495097c8c7f913ef837899ba}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">enum class micro_os_plus::micro_test_plus::runner::session_state </td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel strong">strong</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The states of a test session.</p>

<dl class="doxyEnumList">
<dt class="doxyEnumTableTitle">Enumeration values</dt>
<dd>
<table class="doxyEnumTable">

<tr class="doxyEnumItem">
<td class="doxyEnumItemName">created<a id="a081c4bd4495097c8c7f913ef837899baae2fa538867c3830a859a5b17ab24644b"></a></td>
<td class="doxyEnumItemDescription"></td>
</tr>

<tr class="doxyEnumItem">
<td class="doxyEnumItemName">initialised<a id="a081c4bd4495097c8c7f913ef837899baadb1687e1890c33928fe61b7cb4ac2f0e"></a></td>
<td class="doxyEnumItemDescription"></td>
</tr>

<tr class="doxyEnumItem">
<td class="doxyEnumItemName">running<a id="a081c4bd4495097c8c7f913ef837899baa75101dcdfc88455bcafc9e53e0b06689"></a></td>
<td class="doxyEnumItemDescription"></td>
</tr>

<tr class="doxyEnumItem">
<td class="doxyEnumItemName">finished<a id="a081c4bd4495097c8c7f913ef837899baaa5d7ceb2c59b8cee46c2953fec9abc19"></a></td>
<td class="doxyEnumItemDescription"></td>
</tr>

</table>
</dd>
</dl>


<p>The session moves only forwards, from <span class="doxyComputerOutput">created</span> to <span class="doxyComputerOutput">initialised</span> (by <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span>), to <span class="doxyComputerOutput">running</span>, and to <span class="doxyComputerOutput">finished</span> (both by <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span>); the calls made in another state are reported or ignored.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00938">938</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">939</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a081c4bd4495097c8c7f913ef837899baae2fa538867c3830a859a5b17ab24644b">940</a></span><span class="doxyLineContent"><span class="doxyHighlight">      created, </span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a081c4bd4495097c8c7f913ef837899baadb1687e1890c33928fe61b7cb4ac2f0e">941</a></span><span class="doxyLineContent"><span class="doxyHighlight">      initialised, </span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a081c4bd4495097c8c7f913ef837899baa75101dcdfc88455bcafc9e53e0b06689">942</a></span><span class="doxyLineContent"><span class="doxyHighlight">      running, </span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a081c4bd4495097c8c7f913ef837899baaa5d7ceb2c59b8cee46c2953fec9abc19">943</a></span><span class="doxyLineContent"><span class="doxyHighlight">      finished </span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">944</span><span class="doxyLineContent"><span class="doxyHighlight">    };</span></span></div>

</div>

</div>
</div>

</div>

<div class="doxySectionDef">

## Friends

### detail::reporter\_human {#a099a369b6d1f67c296baf9d22be40ba2}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">friend class <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human">detail::reporter_human</a></td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The human reporter, which displays the session.</p>


<p>It reads the stopwatch, to display the duration of the session.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00173">173</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a099a369b6d1f67c296baf9d22be40ba2">173</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human">detail::reporter_human</a>;</span></span></div>

</div>

</div>
</div>

### detail::reporter\_tap {#a6cd3b3f893312fe43fa2d7b5018646e9}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">friend class <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap">detail::reporter_tap</a></td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The TAP reporter, which displays the session.</p>


<p>It reads the stopwatch, to display the duration of the session.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00181">181</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a6cd3b3f893312fe43fa2d7b5018646e9">181</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap">detail::reporter_tap</a>;</span></span></div>

</div>

</div>
</div>

### detail::runnable\_base {#a484008ed66130a2bf334948841099943}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">friend class <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base">detail::runnable_base</a></td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The base of the nodes, which shares the state of the session.</p>


<p>It passes the reporter to the suites and the test cases, applies the filter, lists the test cases, keeps the running test case, and aborts for a failed requirement.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00192">192</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a484008ed66130a2bf334948841099943">192</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base">detail::runnable_base</a>;</span></span></div>

</div>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Constructors

### runner() {#a10788baa079e19676a8cdbaa253285dc}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::runner::runner (const char * top_suite_name)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Deprecated constructor for the runner class.</p>


<p>Use the anonymous constructor, and pass the name to <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span>, which can also override the name given here.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">top_suite_name</td>
<td class="doxyParamItemDescription"><p>The name given to the implicit top suite.</p></td>
</tr>
</table>
</dd>
</dl>

<div class="doxyXrefSect">
<dl class="doxyXrefSectList">
<dt class="doxyXrefSectTitle"><a href=/micro-test-plus-xpack/docs/api/pages/deprecated/#_deprecated000052>Deprecated</a></dt>
<dd class="doxyXrefSectDescription">
<p>use <a href="#a5e2001730fd3659e9045fcc5cc668f07">runner()</a> and <a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a> (since 4.1.0)</p>
</dd>
</dl>
</div>

<p>The constructor initialises a new <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">runner</a></span> instance together with its top suite (<span class="doxyComputerOutput"><a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a></span>). If tracing is enabled, it outputs the function signature for diagnostic purposes.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00216">216</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00093">93</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a10788baa079e19676a8cdbaa253285dc">93</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a5e2001730fd3659e9045fcc5cc668f07">runner::runner</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* top_suite_name)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">94</span><span class="doxyLineContent"><span class="doxyHighlight">      : <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>{ top_suite_name, *this }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">95</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">96</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">97</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s '%s'\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__, <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">98</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">99</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">micro_os_plus::micro_test_plus::detail::runnable_base::name</a> and <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>.</p>

</div>
</div>

### runner() {#adbe02fed3c414adf001d856ab390e000}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::runner::runner (const runner &amp;)</td>
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


<p>The runner owns the suites, the reporter, and the session totals, which must not be duplicated.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00225">225</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<p>Reference <a href="#a5e2001730fd3659e9045fcc5cc668f07">runner</a>.</p>

</div>
</div>

### runner() {#a09acf1e03953d8017e56c8b5e38b879a}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::runner::runner (runner &amp;&amp;)</td>
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


<p>The suites keep a reference to the runner, so it must not be relocated.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00234">234</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<p>Reference <a href="#a5e2001730fd3659e9045fcc5cc668f07">runner</a>.</p>

</div>
</div>

### runner() {#a5e2001730fd3659e9045fcc5cc668f07}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::runner::runner (void)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Constructor for the runner class.</p>


<p>The top suite name is set later, by <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span>.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<p>The constructor initialises a new <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">runner</a></span> instance together with its top suite (<span class="doxyComputerOutput"><a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a></span>). If tracing is enabled, it outputs the function signature for diagnostic purposes.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00204">204</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00079">79</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a5e2001730fd3659e9045fcc5cc668f07">79</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a5e2001730fd3659e9045fcc5cc668f07">runner::runner</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) : <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>{ </span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight">, *this }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">80</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">81</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">82</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s '%s'\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__, <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">83</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">84</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">micro_os_plus::micro_test_plus::detail::runnable_base::name</a> and <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>.</p>


<p>Referenced by <a href="#adbe02fed3c414adf001d856ab390e000">runner</a>, <a href="#a09acf1e03953d8017e56c8b5e38b879a">runner</a>, <a href="#a549524d15dc1eb5e6b4eb4bdd2af7b6b">operator=</a> and <a href="#aa34a0418d54c633630a089eb2b5a61ee">operator=</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Destructor

### \~runner() {#aea1a1eff9cac943c1cd84e48b9add92f}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::runner::~runner ()</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Destructor for the runner class.</p>


<p>Destroys the registered suites and the reporter, which closes the output file, if any. The static suites are not owned by the runner.</p>


<p>The <span class="doxyComputerOutput"><a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a></span> unique pointer is released automatically. If tracing is enabled, the function signature is output for diagnostic purposes.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00265">265</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00106">106</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aea1a1eff9cac943c1cd84e48b9add92f">106</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#aea1a1eff9cac943c1cd84e48b9add92f">runner::~runner</a> ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">107</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">108</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">109</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">110</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">111</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">112</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// reporter_ is a unique_ptr; destroyed automatically.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">113</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Operators

### operator=() {#a549524d15dc1eb5e6b4eb4bdd2af7b6b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">runner &amp; micro_os_plus::micro_test_plus::runner::operator= (const <a href="#a5e2001730fd3659e9045fcc5cc668f07">runner</a> &amp;)</td>
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


<p>The runner owns the suites, the reporter, and the session totals, which must not be duplicated.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00244">244</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<p>Reference <a href="#a5e2001730fd3659e9045fcc5cc668f07">runner</a>.</p>

</div>
</div>

### operator=() {#aa34a0418d54c633630a089eb2b5a61ee}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">runner &amp; micro_os_plus::micro_test_plus::runner::operator= (<a href="#a5e2001730fd3659e9045fcc5cc668f07">runner</a> &amp;&amp;)</td>
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


<p>The suites keep a reference to the runner, so it must not be relocated.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00255">255</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<p>References <a href="#a5e2001730fd3659e9045fcc5cc668f07">runner</a>, <a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite</a>, <a href="#a7f8403f1ccc6a0e8171ef077bcd9cbd4">exit_code</a>, <a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise</a>, <a href="#a97f725cb167a2b464fac0eb88a0c8a46">run</a> and <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Member Functions

### abort() {#a7bc806540e65c21095ef1ea1ef970db2}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::runner::abort (const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> &amp; sl=<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a>())</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Aborts test execution immediately.</p>


<p>Between <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span> and the end of <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span>, the reporter completes the report, on the console and in the output file: it writes the results of the running test case, if any, followed by a line with the source location (a <span class="doxyComputerOutput">Bail out!</span> line with the TAP reporter), in place of the totals. Before <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span> or after <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span>, when there is no report to complete, the source location is written to <span class="doxyComputerOutput">stderr</span>.</p>


<p>The handler set by <span class="doxyComputerOutput"><a href="#a711756a8c6958c4036527a290c481f86">set_abort_handler()</a></span> is then called, if any. If there is no handler, or if it returns, the process is terminated with <span class="doxyComputerOutput">::abort()</span>.</p>


<p>The abort is final, also when the handler throws an exception: no test case runs afterwards, <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span> and <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span> report an error on <span class="doxyComputerOutput">stderr</span> (<span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span> returns 1), and a later abort is not reported again.</p>


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


<p>Delegates to <span class="doxyComputerOutput"><a href="#a7bc806540e65c21095ef1ea1ef970db2">abort()</a></span>, as an explicit abort, not caused by a failed requirement.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00501">501</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00773">773</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a7bc806540e65c21095ef1ea1ef970db2">773</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a7bc806540e65c21095ef1ea1ef970db2">runner::abort</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; sl)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">774</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">775</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a7bc806540e65c21095ef1ea1ef970db2">abort</a> (sl, </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">776</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a7bc806540e65c21095ef1ea1ef970db2">abort</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a5fec64d9b300277d56e02193bb7d0a46">micro_os_plus::micro_test_plus::detail::runnable_base::abort</a>, <a href="#af0682165f5d07b13fd21e3f6f8da546c">abort</a> and <a href="#a7bc806540e65c21095ef1ea1ef970db2">abort</a>.</p>

</div>
</div>

### add\_suite() {#a4069fe957bbc7a9217ca2dd4d2034a97}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;typename Callable_T, typename... Args_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::runner::add_suite (std::string_view name, Callable_T &amp;&amp; callable, Args_T &amp;&amp;... arguments)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Adds a test suite to the runner, to be run by <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span>.</p>


<p>Unlike the test cases added to the top suite, which run immediately, the suite is only stored; <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span> runs it later, together with the static suites that refer to this runner, sorted by name.</p>


<p>The suites must be added before <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span> is called. A suite added while <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span> runs (for example from the body of another suite), or after it returned, would never run; it is rejected, the error is reported on <span class="doxyComputerOutput">stderr</span>, and the exit code is not 0, so that the omission cannot pass unnoticed.</p>


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
<td class="doxyParamItemDescription"><p>The test suite name or description, used in reports; a string literal, a <span class="doxyComputerOutput">const char*</span>, a <span class="doxyComputerOutput">std::string</span>, or a <span class="doxyComputerOutput">std::string_view</span>. It is copied, so the string need not outlive the call, nor be null-terminated.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">callable</td>
<td class="doxyParamItemDescription"><p>A generic callable object, usually a lambda, invoked to perform the test suite.</p></td>
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


<dl class="doxySectionUser">
<dt>Since</dt>
<dd><p>5.1.0</p></dd>
</dl>


<p>Constructs a <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a></span> object on the heap, binding the callable and any additional arguments, then transfers ownership to the runner via <span class="doxyComputerOutput"><a href="#a1dcc8f8d7f80044c67c492a1aebe3043">register_suite()</a></span>. The suite is not run here; all registered suites are run later by <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span>, together with the static suites, sorted by name. A suite added once <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span> has started is rejected by <span class="doxyComputerOutput"><a href="#a1dcc8f8d7f80044c67c492a1aebe3043">register_suite()</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00402">402</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h/#l00161">161</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h">runner-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">161</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a4069fe957bbc7a9217ca2dd4d2034a97">runner::add_suite</a> (std::string_view name, Callable_T&amp;&amp; callable,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">162</span><span class="doxyLineContent"><span class="doxyHighlight">                     Args_T&amp;&amp;... arguments)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">163</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">164</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">165</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s '%.*s'\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">166</span><span class="doxyLineContent"><span class="doxyHighlight">                   </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (name.size ()), name.data ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">167</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">168</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">169</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Not std::make_unique(), which cannot access the protected constructor.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">170</span><span class="doxyLineContent"><span class="doxyHighlight">    std::unique_ptr&lt;class suite&gt; child_suite{ </span><span class="doxyHighlightKeyword">new</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">171</span><span class="doxyLineContent"><span class="doxyHighlight">        name, *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">, std::forward&lt;Callable_T&gt; (callable),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">172</span><span class="doxyLineContent"><span class="doxyHighlight">        std::forward&lt;Args_T&gt; (arguments)...) };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">173</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">174</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1dcc8f8d7f80044c67c492a1aebe3043">register_suite</a> (std::move (child_suite));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">175</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a1dcc8f8d7f80044c67c492a1aebe3043">register_suite</a> and <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>.</p>


<p>Referenced by <a href="#aa34a0418d54c633630a089eb2b5a61ee">operator=</a> and <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>.</p>

</div>
</div>

### added\_suites\_count() {#a9484b22aa909151712144cd39130187a}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">size_t micro_os_plus::micro_test_plus::runner::added_suites_count (void)</td>
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

<p>Returns the count of the test suites added with <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span>.</p>


<p>The count includes neither the top suite nor the static suites, which are counted by <span class="doxyComputerOutput"><a href="#a67d3cf710cccd419c127e63c2c30e9fe">static_suites_count()</a></span>; add one for the top suite when needed, or use <span class="doxyComputerOutput"><a href="#ac29e4b993bb3fe795eb8900231cbf5c4">total_suites_count()</a></span>, which counts all of them. The suites that <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span> rejects, once <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span> has started, are not counted.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The number of test suites added with <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span>.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Since</dt>
<dd><p>5.1.0</p></dd>
</dl>


<p>Returns the number of suites stored by <span class="doxyComputerOutput"><a href="#a1dcc8f8d7f80044c67c492a1aebe3043">register_suite()</a></span>; the top suite and the static suites are not in <span class="doxyComputerOutput"><a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00596">596</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00842">842</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a9484b22aa909151712144cd39130187a">842</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a9484b22aa909151712144cd39130187a">runner::added_suites_count</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">843</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">844</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a>.size ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">845</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a>.</p>


<p>Referenced by <a href="#a6ed3a02ced62ed475c75678cd9e91be1">suites_count</a> and <a href="#ac29e4b993bb3fe795eb8900231cbf5c4">total_suites_count</a>.</p>

</div>
</div>

### exit\_code() {#a7f8403f1ccc6a0e8171ef077bcd9cbd4}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">int micro_os_plus::micro_test_plus::runner::exit_code (void)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Deprecated name of <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span>.</p>


<p>Calls <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span>; once the session has ended, it only returns the exit code.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The value returned by <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span>.</p></dd>
</dl>


<div class="doxyXrefSect">
<dl class="doxyXrefSectList">
<dt class="doxyXrefSectTitle"><a href=/micro-test-plus-xpack/docs/api/pages/deprecated/#_deprecated000053>Deprecated</a></dt>
<dd class="doxyXrefSectDescription">
<p>use <a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a> (since 5.1.0)</p>
</dd>
</dl>
</div>

<p>Kept for compatibility; it calls <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span>, so the first call runs the session and the later ones return the stored exit code.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00367">367</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00749">749</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a7f8403f1ccc6a0e8171ef077bcd9cbd4">749</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a7f8403f1ccc6a0e8171ef077bcd9cbd4">runner::exit_code</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">750</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">751</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a97f725cb167a2b464fac0eb88a0c8a46">run</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">752</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a97f725cb167a2b464fac0eb88a0c8a46">run</a>.</p>


<p>Referenced by <a href="#aa34a0418d54c633630a089eb2b5a61ee">operator=</a>.</p>

</div>
</div>

### initialise() {#ac40f554936c71d7c748c1241ffd3f2ac}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">suite &amp; micro_os_plus::micro_test_plus::runner::initialise (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options">runner_options</a> &amp; options, const char * top_suite_name="")</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Initialises the test runner with the given options.</p>


<p>Creates the selected reporter, starts the session, and returns the top suite, without parsing a command line; intended for the applications that do not have one, such as the embedded ones without semihosting arguments.</p>


<p>If no name is given, here or by the deprecated constructor, the top suite is named after <span class="doxyComputerOutput">options.arguments[0]</span>, when available, or "default suite".</p>


<p>If the output file cannot be opened, the error is reported on <span class="doxyComputerOutput">stderr</span> and the report is written only to the console; the tests are still run, but <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span> returns 2.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">options</td>
<td class="doxyParamItemDescription"><p>The session options; the strings they refer to must remain valid until the call returns.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">top_suite_name</td>
<td class="doxyParamItemDescription"><p>The name given to the implicit top suite. Defaults to an empty string.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to the top-level test suite.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Since</dt>
<dd><p>5.1.0</p></dd>
</dl>


<p>Keeps a copy of the verbosity, creates the reporter selected by the options, keeps a copy of the filter patterns, starts the session timing, and emits the initial reporter notifications for the session and the top suite. While the test cases are listed, only the header of the list is written; the session and the top suite are not reported.</p>


<p>If the top suite name is not provided, here or by the deprecated constructor, it is derived from the file name of <span class="doxyComputerOutput">options.arguments[0]</span> (usually <span class="doxyComputerOutput">argv[0]</span>), without the extension, or defaults to "default suite".</p>


<p>If the output file cannot be opened, the reporter writes only to the console, and <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span> will return 2.</p>


<p>The runner is initialised only once; a later call, or a call after the test execution was aborted, reports an error on <span class="doxyComputerOutput">stderr</span> and returns the top suite, without other effects.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00317">317</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00193">193</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ac40f554936c71d7c748c1241ffd3f2ac">193</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#acfabd0e10d233ad305b6f4fc125a97f2">runner::initialise</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options">runner_options</a>&amp; options,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">194</span><span class="doxyLineContent"><span class="doxyHighlight">                      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* top_suite_name)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">195</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">196</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">197</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">198</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">199</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">200</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#ad107cec6e32daac2da4cd665c7444e51">aborted_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">201</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">202</span><span class="doxyLineContent"><span class="doxyHighlight">        fprintf (stderr, </span><span class="doxyHighlightStringLiteral">"error: test execution aborted\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">203</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">204</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">205</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">206</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> != <a href="#a081c4bd4495097c8c7f913ef837899baae2fa538867c3830a859a5b17ab24644b">session_state::created</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">207</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">208</span><span class="doxyLineContent"><span class="doxyHighlight">        fprintf (stderr, </span><span class="doxyHighlightStringLiteral">"error: test runner already initialised\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">209</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">210</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">211</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">212</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (top_suite_name != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight"> &amp;&amp; strlen (top_suite_name) &gt; 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">213</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">214</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// If provided by this call, use it, possibly override the</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">215</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// deprecated constructor.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">216</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a401e4e098f0ceba7f21a3a5bf1ea89e3">top_suite_name_</a> = top_suite_name;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">217</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aad830bd92e4f6e4239d2bb5b75d5bf50">name_</a> = <a href="#a401e4e098f0ceba7f21a3a5bf1ea89e3">top_suite_name_</a>.c_str ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">218</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">219</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (strlen (<a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> ()) == 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">220</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">221</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// If not provided by the constructor or by this call, try to extract a</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">222</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// name from argv[0], which is commonly the executable name. If that</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">223</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// fails, use a default name.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">224</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (!options.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#a7c2cca740efdbdc4927cac43aa456611">arguments</a>.empty () &amp;&amp; options.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#a7c2cca740efdbdc4927cac43aa456611">arguments</a>[0] != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">225</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">226</span><span class="doxyLineContent"><span class="doxyHighlight">            std::string_view top_suite_name_view{ <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-utility-functions/#ga791f22f0c85b6436c9016821907b0653">utility::extract_file_name</a> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">227</span><span class="doxyLineContent"><span class="doxyHighlight">                options.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#a7c2cca740efdbdc4927cac43aa456611">arguments</a>[0]) };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">228</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">229</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> dot_pos = top_suite_name_view.rfind (</span><span class="doxyHighlightCharLiteral">'.'</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">230</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (dot_pos != std::string_view::npos)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">231</span><span class="doxyLineContent"><span class="doxyHighlight">              {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">232</span><span class="doxyLineContent"><span class="doxyHighlight">                top_suite_name_view = top_suite_name_view.substr (0, dot_pos);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">233</span><span class="doxyLineContent"><span class="doxyHighlight">              }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">234</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">235</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="#a401e4e098f0ceba7f21a3a5bf1ea89e3">top_suite_name_</a> = top_suite_name_view;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">236</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">237</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">238</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">239</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="#a401e4e098f0ceba7f21a3a5bf1ea89e3">top_suite_name_</a> = </span><span class="doxyHighlightStringLiteral">"default suite"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">240</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">241</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aad830bd92e4f6e4239d2bb5b75d5bf50">name_</a> = <a href="#a401e4e098f0ceba7f21a3a5bf1ea89e3">top_suite_name_</a>.c_str ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">242</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">243</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">244</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1d4b6b07a507c00a5ac262e098b12ad3">verbosity_</a> = options.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#aff30f0303a958a549a2f4b6e67db00d5">verbosity_level</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">245</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">246</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Initialise and configure the reporter; it keeps its own copy of the</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">247</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// verbosity, taken from the same options.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">248</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (options.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#ad22d04df014c5b0658b6e7bd239f15b0">selected_reporter</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a913c4161963e9439b20857358486e8b2a99e9bae675b12967251c175696f00a70">reporter_kind::human</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">249</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">250</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a> = std::make_unique&lt;detail::reporter_human&gt; (options);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">251</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">252</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">253</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">254</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a> = std::make_unique&lt;detail::reporter_tap&gt; (options);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">255</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">256</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">257</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>-&gt;has_output_file_error ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">258</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">259</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a8e9e6782d6cde59ac82fb6fb459888cb">has_option_errors_</a> = </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">260</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">261</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">262</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Copy the strings, not only the views, since the patterns are used</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">263</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// by run(), after the caller's strings may have been destroyed. Copy</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">264</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// them one by one, since the vector assignment uses std::copy, which</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">265</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// triggers -Waggregate-return in the standard library headers on some</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">266</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// targets.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">267</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a12b7d597d11b0ff284cdb84a7c4ea927">filter_patterns_</a>.reserve (options.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#a8dc9c5a5b6c89c12acd27d67d57618dd">filter_patterns</a>.size ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">268</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string_view pattern : options.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#a8dc9c5a5b6c89c12acd27d67d57618dd">filter_patterns</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">269</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">270</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a12b7d597d11b0ff284cdb84a7c4ea927">filter_patterns_</a>.emplace_back (pattern);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">271</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">272</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">273</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">274</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">275</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// When listing, the session is not reported; only the header of the</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">276</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// list is written, and the test cases are listed as they are created.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">277</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a2cbcc12d72c192f6053cd342af1b5a77">list_tests_</a> = options.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#ac4f95336439b329d0f3731a5dcafb6f9">list_tests</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">278</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a2cbcc12d72c192f6053cd342af1b5a77">list_tests_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">279</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">280</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>-&gt;write_line (<a href="#a1d4b6b07a507c00a5ac262e098b12ad3">verbosity_</a> != <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">verbosity::silent</a>, </span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">281</span><span class="doxyLineContent"><span class="doxyHighlight">                               <a href="#a12b7d597d11b0ff284cdb84a7c4ea927">filter_patterns_</a>.empty ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">282</span><span class="doxyLineContent"><span class="doxyHighlight">                                   ? </span><span class="doxyHighlightStringLiteral">"All available test cases:"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">283</span><span class="doxyLineContent"><span class="doxyHighlight">                                   : </span><span class="doxyHighlightStringLiteral">"Matching test cases:"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">284</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> = <a href="#a081c4bd4495097c8c7f913ef837899baadb1687e1890c33928fe61b7cb4ac2f0e">session_state::initialised</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">285</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">286</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">287</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">288</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a13b3cf196a1b12cb90a12c4b84223d15">stopwatch_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch/#af5ebb1e454867633db12fef45db9788d">start</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">289</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>-&gt;begin_session (*</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">290</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">291</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a95145ab410f5c0b6e514ac366aff8d84">stopwatch_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch/#af5ebb1e454867633db12fef45db9788d">start</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">292</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>-&gt;begin_suite (<a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">293</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">294</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> = <a href="#a081c4bd4495097c8c7f913ef837899baadb1687e1890c33928fe61b7cb4ac2f0e">session_state::initialised</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">295</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">296</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">297</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#ad107cec6e32daac2da4cd665c7444e51">aborted_</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#a7c2cca740efdbdc4927cac43aa456611">micro_os_plus::micro_test_plus::runner_options::arguments</a>, <a href="#a081c4bd4495097c8c7f913ef837899baae2fa538867c3830a859a5b17ab24644b">created</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-utility-functions/#ga791f22f0c85b6436c9016821907b0653">micro_os_plus::micro_test_plus::utility::extract_file_name</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#a8dc9c5a5b6c89c12acd27d67d57618dd">micro_os_plus::micro_test_plus::runner_options::filter_patterns</a>, <a href="#a12b7d597d11b0ff284cdb84a7c4ea927">filter_patterns_</a>, <a href="#a8e9e6782d6cde59ac82fb6fb459888cb">has_option_errors_</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a913c4161963e9439b20857358486e8b2a99e9bae675b12967251c175696f00a70">micro_os_plus::micro_test_plus::human</a>, <a href="#a081c4bd4495097c8c7f913ef837899baadb1687e1890c33928fe61b7cb4ac2f0e">initialised</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#ac4f95336439b329d0f3731a5dcafb6f9">micro_os_plus::micro_test_plus::runner_options::list_tests</a>, <a href="#a2cbcc12d72c192f6053cd342af1b5a77">list_tests_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">micro_os_plus::micro_test_plus::detail::runnable_base::name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aad830bd92e4f6e4239d2bb5b75d5bf50">micro_os_plus::micro_test_plus::detail::runnable_base::name_</a>, <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#ad22d04df014c5b0658b6e7bd239f15b0">micro_os_plus::micro_test_plus::runner_options::selected_reporter</a>, <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">micro_os_plus::micro_test_plus::silent</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch/#af5ebb1e454867633db12fef45db9788d">micro_os_plus::micro_test_plus::detail::stopwatch::start</a>, <a href="#a13b3cf196a1b12cb90a12c4b84223d15">stopwatch_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a95145ab410f5c0b6e514ac366aff8d84">micro_os_plus::micro_test_plus::suite::stopwatch_</a>, <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>, <a href="#a401e4e098f0ceba7f21a3a5bf1ea89e3">top_suite_name_</a>, <a href="#a1d4b6b07a507c00a5ac262e098b12ad3">verbosity_</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#aff30f0303a958a549a2f4b6e67db00d5">micro_os_plus::micro_test_plus::runner_options::verbosity_level</a>.</p>

</div>
</div>

### initialise() {#acfabd0e10d233ad305b6f4fc125a97f2}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">suite &amp; micro_os_plus::micro_test_plus::runner::initialise (int argc, char * argv=[], const char * top_suite_name="")</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Initialises the test runner with command-line arguments.</p>


<p>Parses the µTest++ options from the command line (<span class="doxyComputerOutput">--<a href="#a65250ff363fbb3b5869bbe4de9578e86">reporter</a></span>, <span class="doxyComputerOutput">--silent</span>, <span class="doxyComputerOutput">--quiet</span>, <span class="doxyComputerOutput">--verbose</span>, <span class="doxyComputerOutput">--output-file</span>, <span class="doxyComputerOutput">--color</span>, <span class="doxyComputerOutput">--use-colour</span>, <span class="doxyComputerOutput">--filter</span>, and <span class="doxyComputerOutput">--list-tests</span>) into a <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options">runner_options</a></span> structure, and continues as the overload taking the options. The other arguments are ignored, since the applications may define their own.</p>


<p>A missing option argument, an unknown reporter name, or an unknown colour mode, is reported on <span class="doxyComputerOutput">stderr</span> and the option is ignored; the tests are still run, but <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span> returns 2.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">argc</td>
<td class="doxyParamItemDescription"><p>The argument count from main().</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">argv</td>
<td class="doxyParamItemDescription"><p>The argument vector from main().</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">top_suite_name</td>
<td class="doxyParamItemDescription"><p>The name given to the implicit top suite. Defaults to an empty string.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to the top-level test suite.</p></dd>
</dl>


<p>Parses the command-line options with <span class="doxyComputerOutput"><a href="#a2319eb34fc8b601ca5e6a8ec538ba138">parse_options()</a></span>, and passes them to the overload taking the options, which creates the selected reporter (<span class="doxyComputerOutput">--<a href="#a65250ff363fbb3b5869bbe4de9578e86">reporter</a>=human</span> or <span class="doxyComputerOutput">--<a href="#a65250ff363fbb3b5869bbe4de9578e86">reporter</a>=tap</span>, the default) and starts the session. An option error is reported on <span class="doxyComputerOutput">stderr</span>, the option is ignored, and <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span> will return 2.</p>


<p>The options are not parsed if the runner is already initialised; the error is then reported by the other overload.</p>


<p>If tracing is enabled, the command-line arguments are also logged for diagnostic purposes.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00289">289</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00138">138</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">138</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#acfabd0e10d233ad305b6f4fc125a97f2">runner::initialise</a> (</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> argc, </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* argv[], </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* top_suite_name)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">139</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">140</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">141</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">142</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">143</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if !(defined(MICRO_OS_PLUS_STARTUP_ENABLED) \</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">144</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">      &amp;&amp; defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">145</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_DEBUG_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">146</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"argv["</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">147</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> i = 0; i &lt; argc; ++i)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">148</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">149</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (i &gt; 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">150</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">151</span><span class="doxyLineContent"><span class="doxyHighlight">            trace::printf (</span><span class="doxyHighlightStringLiteral">", "</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">152</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">153</span><span class="doxyLineContent"><span class="doxyHighlight">        trace::printf (</span><span class="doxyHighlightStringLiteral">"'%s'"</span><span class="doxyHighlight">, argv[i]);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">154</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">155</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::puts (</span><span class="doxyHighlightStringLiteral">"]"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">156</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(MICRO_OS_PLUS_DEBUG_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">157</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// !defined(MICRO_OS_PLUS_STARTUP_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">158</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">159</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">160</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> != <a href="#a081c4bd4495097c8c7f913ef837899baae2fa538867c3830a859a5b17ab24644b">session_state::created</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">161</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">162</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// Do not parse the options, since an option error would change</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">163</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// the exit code of the running session; the other overload</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">164</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// reports the error.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">165</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options">runner_options</a>{}, top_suite_name);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">166</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">167</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">168</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise</a> (<a href="#a2319eb34fc8b601ca5e6a8ec538ba138">parse_options</a> (argc, argv), top_suite_name);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">169</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a081c4bd4495097c8c7f913ef837899baae2fa538867c3830a859a5b17ab24644b">created</a>, <a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise</a>, <a href="#a2319eb34fc8b601ca5e6a8ec538ba138">parse_options</a> and <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a>.</p>


<p>Referenced by <a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise</a> and <a href="#aa34a0418d54c633630a089eb2b5a61ee">operator=</a>.</p>

</div>
</div>

### is\_listing() {#ae5df469f7aaccc8e24bfadff4c209688}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::runner::is_listing (void)</td>
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

<p>Checks whether the test cases are listed instead of run.</p>


<p>Set by the <span class="doxyComputerOutput">--list-tests</span> (or <span class="doxyComputerOutput">--list</span>) command-line option, or by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#ac4f95336439b329d0f3731a5dcafb6f9">runner_options::list_tests</a></span>. While the test cases are listed, their bodies do not run, so the code in <span class="doxyComputerOutput">main()</span> or in the suite bodies that depends on their results (their totals, or the exit code of <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span>) can use it to skip those parts, and the tests can use it to keep their own messages out of the list. Before <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span> is called, it is <span class="doxyComputerOutput">false</span>.</p>


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
<td class="doxyParamItemDescription"><p>The test cases are listed.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">false</td>
<td class="doxyParamItemDescription"><p>The test cases are run.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Since</dt>
<dd><p>5.1.0</p></dd>
</dl>


<p>Returns the flag copied by <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span> from <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#ac4f95336439b329d0f3731a5dcafb6f9">runner_options::list_tests</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00562">562</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h/#l00088">88</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h">runner-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ae5df469f7aaccc8e24bfadff4c209688">88</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ae5df469f7aaccc8e24bfadff4c209688">runner::is_listing</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">89</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">90</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a2cbcc12d72c192f6053cd342af1b5a77">list_tests_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">91</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a2cbcc12d72c192f6053cd342af1b5a77">list_tests_</a>.</p>

</div>
</div>

### reporter() {#a65250ff363fbb3b5869bbe4de9578e86}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">detail::reporter &amp; micro_os_plus::micro_test_plus::runner::reporter (void)</td>
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

<p>Deprecated access to the reporter of the test session.</p>


<p>Returns the internal reporter, created by <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span>, as selected by the session options; the call is valid only after <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span>. In v5.0.1, the returned class was the top namespace <span class="doxyComputerOutput"><a href="#a65250ff363fbb3b5869bbe4de9578e86">reporter</a></span>, now <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">detail::reporter</a></span>; of its members, the applications used only <span class="doxyComputerOutput"><a href="#a94a9df0418776ebce476cd9a2e4f591f">verbosity()</a></span>, kept, deprecated, on <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">detail::reporter</a></span>.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A reference to the reporter of the session.</p></dd>
</dl>


<div class="doxyXrefSect">
<dl class="doxyXrefSectList">
<dt class="doxyXrefSectTitle"><a href=/micro-test-plus-xpack/docs/api/pages/deprecated/#_deprecated000059>Deprecated</a></dt>
<dd class="doxyXrefSectDescription">
<p>use <a href="#a1dd0221dca8e7382f0b625ff6316ed92">verbosity_level()</a> (since 5.1.0)</p>
</dd>
</dl>
</div>

<p>Returns a reference to the reporter owned by the <span class="doxyComputerOutput"><a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a></span> unique pointer, which is empty before <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00724">724</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h/#l00143">143</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h">runner-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a65250ff363fbb3b5869bbe4de9578e86">143</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a65250ff363fbb3b5869bbe4de9578e86">runner::reporter</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">144</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">145</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *<a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">146</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>.</p>

</div>
</div>

### run() {#a97f725cb167a2b464fac0eb88a0c8a46}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">int micro_os_plus::micro_test_plus::runner::run (void)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Runs the registered suites, ends the session, and returns the exit code.</p>


<p>Completes the top suite, runs the suites registered with <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span> and the static suites that refer to this runner, together, sorted by name, and ends the session. When filter patterns are given, the suites whose names do not match the first pattern are reported as skipped, without being run.</p>


<p>While the test cases are listed (see <span class="doxyComputerOutput"><a href="#ae5df469f7aaccc8e24bfadff4c209688">is_listing()</a></span>), the suites run only to create their test cases, which are listed, and the number of listed test cases is written; the result of the checks does not affect the exit code, since no check is evaluated.</p>


<p>The session runs only once; later calls return the same exit code without running anything again. A call made while the session runs, for example from a suite body, or after the test execution was aborted (see <span class="doxyComputerOutput"><a href="#a7bc806540e65c21095ef1ea1ef970db2">abort()</a></span>), is reported on <span class="doxyComputerOutput">stderr</span> and returns 1, without other effects.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>0 if all checks passed, or if the test cases were listed; 1 if a check failed, if a suite was rejected by <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span>, if the runner was not initialised or is running, or if the test execution was aborted; 2 if <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span> reported an option error, regardless of the checks.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Since</dt>
<dd><p>5.1.0</p></dd>
</dl>


<p>Finalises the top suite by stopping its stopwatch and notifying the reporter, then accumulates its totals into the runner totals. Subsequently invokes <span class="doxyComputerOutput"><a href="#a7c4dbf695c086ca4d3f0ce33e6d561f7">run_suites()</a></span> to execute, sorted by name, and accumulate the registered and the static child suites. Finally, stops the session stopwatch, notifies the reporter, and returns <span class="doxyComputerOutput">0</span> if all checks passed or <span class="doxyComputerOutput">1</span> otherwise, or if a suite was rejected by <span class="doxyComputerOutput"><a href="#a1dcc8f8d7f80044c67c492a1aebe3043">register_suite()</a></span>; if <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span> reported an option error, <span class="doxyComputerOutput">2</span> is returned, regardless of the checks.</p>


<p>While the suites run, the session is in the <span class="doxyComputerOutput">running</span> state, so that the suites added by them are rejected.</p>


<p>While the test cases are listed, the top suite is not reported, the suites run only to create their test cases, the numbers of listed test cases and suites end the list, and the exit code is <span class="doxyComputerOutput">0</span>, or <span class="doxyComputerOutput">2</span> after an option error.</p>


<p>The result is stored, and the later calls return it without running anything again. If the runner was not initialised, if it is already running (a call from a suite or a test case), or if the test execution was aborted, an error is reported on <span class="doxyComputerOutput">stderr</span> and <span class="doxyComputerOutput">1</span> is returned.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00353">353</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00665">665</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">665</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a97f725cb167a2b464fac0eb88a0c8a46">runner::run</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">666</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">667</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">668</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">669</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">670</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">671</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#ad107cec6e32daac2da4cd665c7444e51">aborted_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">672</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">673</span><span class="doxyLineContent"><span class="doxyHighlight">        fprintf (stderr, </span><span class="doxyHighlightStringLiteral">"error: test execution aborted\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">674</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> 1;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">675</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">676</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">677</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> == <a href="#a081c4bd4495097c8c7f913ef837899baaa5d7ceb2c59b8cee46c2953fec9abc19">session_state::finished</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">678</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">679</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// The session has ended; do not run the suites again.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">680</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">exit_code_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">681</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">682</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">683</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> == <a href="#a081c4bd4495097c8c7f913ef837899baa75101dcdfc88455bcafc9e53e0b06689">session_state::running</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">684</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">685</span><span class="doxyLineContent"><span class="doxyHighlight">        fprintf (stderr, </span><span class="doxyHighlightStringLiteral">"error: test runner already running\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">686</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> 1;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">687</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">688</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">689</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> != <a href="#a081c4bd4495097c8c7f913ef837899baadb1687e1890c33928fe61b7cb4ac2f0e">session_state::initialised</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">690</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">691</span><span class="doxyLineContent"><span class="doxyHighlight">        fprintf (stderr, </span><span class="doxyHighlightStringLiteral">"error: test runner not initialised\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">692</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> 1;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">693</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">694</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">695</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> = <a href="#a081c4bd4495097c8c7f913ef837899baa75101dcdfc88455bcafc9e53e0b06689">session_state::running</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">696</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">697</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// When listing, the suites run only to create their test cases, which</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">698</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// are listed, and the number of listed test cases ends the list.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">699</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a2cbcc12d72c192f6053cd342af1b5a77">list_tests_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">700</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">701</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a7c4dbf695c086ca4d3f0ce33e6d561f7">run_suites</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">702</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">703</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> test_cases = <a href="#a90900e7d0a4571407b3727e031e46685">listed_test_cases_count_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">704</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> suites = <a href="#acb06cb7ebf949b8af5c5d57645c56e4a">listed_suites_count_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">705</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>-&gt;write_line (<a href="#a1d4b6b07a507c00a5ac262e098b12ad3">verbosity_</a> != <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">verbosity::silent</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">706</span><span class="doxyLineContent"><span class="doxyHighlight">                               </span><span class="doxyHighlightStringLiteral">"%lu test case%s in %lu test suite%s\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">707</span><span class="doxyLineContent"><span class="doxyHighlight">                               test_cases, (test_cases == 1) ? </span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"> : </span><span class="doxyHighlightStringLiteral">"s"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">708</span><span class="doxyLineContent"><span class="doxyHighlight">                               suites, (suites == 1) ? </span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"> : </span><span class="doxyHighlightStringLiteral">"s"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">709</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>-&gt;flush_streams ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">710</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">711</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">exit_code_</a> = <a href="#a8e9e6782d6cde59ac82fb6fb459888cb">has_option_errors_</a> ? 2 : 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">712</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> = <a href="#a081c4bd4495097c8c7f913ef837899baaa5d7ceb2c59b8cee46c2953fec9abc19">session_state::finished</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">713</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">exit_code_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">714</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">715</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">716</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a95145ab410f5c0b6e514ac366aff8d84">stopwatch_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch/#a83ab4e25e25a4a81ed1d3277ac09390d">stop</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">717</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>-&gt;end_suite (<a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">718</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a04b52f3243abe3a9b08b44efd03e4b57">totals_</a> += <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">totals</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">719</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">720</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a7c4dbf695c086ca4d3f0ce33e6d561f7">run_suites</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">721</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">722</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a13b3cf196a1b12cb90a12c4b84223d15">stopwatch_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch/#a83ab4e25e25a4a81ed1d3277ac09390d">stop</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">723</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>-&gt;end_session (*</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">724</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">725</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a8e9e6782d6cde59ac82fb6fb459888cb">has_option_errors_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">726</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">727</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">exit_code_</a> = 2;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">728</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">729</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">730</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">731</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">exit_code_</a> = (<a href="#a04b52f3243abe3a9b08b44efd03e4b57">totals_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a14690f9880df505f9dd90a9f2c3dfc96">passed</a> () &amp;&amp; !<a href="#a999d64ffbd12dcacb59c34fbea4452ba">has_rejected_suites_</a>) ? 0 : 1;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">732</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">733</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> = <a href="#a081c4bd4495097c8c7f913ef837899baaa5d7ceb2c59b8cee46c2953fec9abc19">session_state::finished</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">734</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">735</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">736</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s -&gt; %d\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__, <a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">exit_code_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">737</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">738</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">739</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">exit_code_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">740</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#ad107cec6e32daac2da4cd665c7444e51">aborted_</a>, <a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">exit_code_</a>, <a href="#a081c4bd4495097c8c7f913ef837899baaa5d7ceb2c59b8cee46c2953fec9abc19">finished</a>, <a href="#a8e9e6782d6cde59ac82fb6fb459888cb">has_option_errors_</a>, <a href="#a999d64ffbd12dcacb59c34fbea4452ba">has_rejected_suites_</a>, <a href="#a081c4bd4495097c8c7f913ef837899baadb1687e1890c33928fe61b7cb4ac2f0e">initialised</a>, <a href="#a2cbcc12d72c192f6053cd342af1b5a77">list_tests_</a>, <a href="#acb06cb7ebf949b8af5c5d57645c56e4a">listed_suites_count_</a>, <a href="#a90900e7d0a4571407b3727e031e46685">listed_test_cases_count_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a14690f9880df505f9dd90a9f2c3dfc96">micro_os_plus::micro_test_plus::counters::passed</a>, <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>, <a href="#a7c4dbf695c086ca4d3f0ce33e6d561f7">run_suites</a>, <a href="#a081c4bd4495097c8c7f913ef837899baa75101dcdfc88455bcafc9e53e0b06689">running</a>, <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">micro_os_plus::micro_test_plus::silent</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch/#a83ab4e25e25a4a81ed1d3277ac09390d">micro_os_plus::micro_test_plus::detail::stopwatch::stop</a>, <a href="#a13b3cf196a1b12cb90a12c4b84223d15">stopwatch_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a95145ab410f5c0b6e514ac366aff8d84">micro_os_plus::micro_test_plus::suite::stopwatch_</a>, <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">micro_os_plus::micro_test_plus::detail::runnable_base::totals</a>, <a href="#a04b52f3243abe3a9b08b44efd03e4b57">totals_</a> and <a href="#a1d4b6b07a507c00a5ac262e098b12ad3">verbosity_</a>.</p>


<p>Referenced by <a href="#a7f8403f1ccc6a0e8171ef077bcd9cbd4">exit_code</a> and <a href="#aa34a0418d54c633630a089eb2b5a61ee">operator=</a>.</p>

</div>
</div>

### set\_abort\_handler() {#a711756a8c6958c4036527a290c481f86}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">runner::abort_handler_t micro_os_plus::micro_test_plus::runner::set_abort_handler (<a href="#ab5b0711c5f1ab3063c410c1b9a76707b">abort_handler_t</a> handler)</td>
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

<p>Sets the function called when test execution is aborted.</p>


<p>Test execution is aborted by a failed <span class="doxyComputerOutput">require()</span>, when exceptions are not enabled (otherwise only the test case is stopped), or by an explicit call of <span class="doxyComputerOutput"><a href="#a7bc806540e65c21095ef1ea1ef970db2">abort()</a></span>. The abort is reported before the handler is called (see <span class="doxyComputerOutput"><a href="#a7bc806540e65c21095ef1ea1ef970db2">abort()</a></span>).</p>


<p>The handler can be set at any time, before or after <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">handler</td>
<td class="doxyParamItemDescription"><p>The new handler, or <span class="doxyComputerOutput">nullptr</span> to restore the default behaviour, which terminates the process with <span class="doxyComputerOutput">::abort()</span>.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The previous handler, or <span class="doxyComputerOutput">nullptr</span> if none was set.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Since</dt>
<dd><p>5.1.0</p></dd>
</dl>


<p>Stores the new handler and returns the previous one; a null handler restores the default behaviour.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00473">473</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00760">760</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a711756a8c6958c4036527a290c481f86">760</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a711756a8c6958c4036527a290c481f86">runner::set_abort_handler</a> (<a href="#ab5b0711c5f1ab3063c410c1b9a76707b">abort_handler_t</a> handler) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">761</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">762</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#ab5b0711c5f1ab3063c410c1b9a76707b">abort_handler_t</a> previous = <a href="#a1138505536cf6afe69dea5ae044eeb5a">abort_handler_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">763</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1138505536cf6afe69dea5ae044eeb5a">abort_handler_</a> = handler;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">764</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> previous;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">765</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a1138505536cf6afe69dea5ae044eeb5a">abort_handler_</a>.</p>

</div>
</div>

### skipped\_suites\_count() {#a2c2a6d7cb45b714026d124d0ca432360}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">size_t micro_os_plus::micro_test_plus::runner::skipped_suites_count (void)</td>
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

<p>Returns the count of the test suites skipped by the filter.</p>


<p>Counts the suites, registered or static, whose names do not match the first filter pattern (<span class="doxyComputerOutput">--filter</span> or <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#a8dc9c5a5b6c89c12acd27d67d57618dd">runner_options::filter_patterns</a></span>); it is complete only after <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span> has returned, and is zero when there are no patterns. The skipped suites are included in <span class="doxyComputerOutput"><a href="#a9484b22aa909151712144cd39130187a">added_suites_count()</a></span> and <span class="doxyComputerOutput"><a href="#a67d3cf710cccd419c127e63c2c30e9fe">static_suites_count()</a></span>; the skipped test cases are counted by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a2e5ea7bbb9bd5a05213dee741f08599d">counters::skipped_test_cases()</a></span>.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The number of test suites that were not run.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Since</dt>
<dd><p>5.1.0</p></dd>
</dl>


<p>Returns the counter incremented by <span class="doxyComputerOutput"><a href="#a7c4dbf695c086ca4d3f0ce33e6d561f7">run_suites()</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00651">651</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00896">896</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a2c2a6d7cb45b714026d124d0ca432360">896</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a2c2a6d7cb45b714026d124d0ca432360">runner::skipped_suites_count</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">897</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">898</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#ae815c0c97245032223f4c1523e1d35fe">skipped_suites_count_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">899</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#ae815c0c97245032223f4c1523e1d35fe">skipped_suites_count_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a6bf3aac88a5e66e2f93eb32c54dbdd14">micro_os_plus::micro_test_plus::detail::reporter::format_session_totals</a>.</p>

</div>
</div>

### static\_suites\_count() {#a67d3cf710cccd419c127e63c2c30e9fe}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">size_t micro_os_plus::micro_test_plus::runner::static_suites_count (void)</td>
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

<p>Returns the count of static test suites.</p>


<p>Counts the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite">static_suite</a></span> objects that refer to this runner; it is complete only after the static initialisation.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The number of static test suites run by this runner.</p></dd>
</dl>


<p>Walks the list of suites, counts those that refer to this runner, and subtracts the suites registered with <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span>, which are all in the list.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00630">630</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00866">866</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a67d3cf710cccd419c127e63c2c30e9fe">866</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a67d3cf710cccd419c127e63c2c30e9fe">runner::static_suites_count</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">867</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">868</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> count = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">869</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>* suite_ptr = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a612f5529e08321a2e44c714d60c2ba1e">suite::first_</a>; suite_ptr != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">870</span><span class="doxyLineContent"><span class="doxyHighlight">         suite_ptr = suite_ptr-&gt;next_)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">871</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">872</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (&amp;suite_ptr-&gt;test_runner () == </span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">873</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">874</span><span class="doxyLineContent"><span class="doxyHighlight">            ++count;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">875</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">876</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">877</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> count - <a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a>.size ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">878</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a612f5529e08321a2e44c714d60c2ba1e">micro_os_plus::micro_test_plus::suite::first_</a> and <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>.</p>


<p>Referenced by <a href="#ac29e4b993bb3fe795eb8900231cbf5c4">total_suites_count</a>.</p>

</div>
</div>

### suite() {#a2636252ac7f80b7425cf2e5eced77834}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;typename Callable_T, typename... Args_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::runner::suite (std::string_view name, Callable_T &amp;&amp; callable, Args_T &amp;&amp;... arguments)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Deprecated name of <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span>.</p>


<p>Calls <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span>. The old name did not show that the suite is only stored, to be run later by <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span>, unlike the test cases, which run immediately; it also hid the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a></span> class inside the runner.</p>


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
<td class="doxyParamItemDescription"><p>The test suite name or description, as for <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span>.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">callable</td>
<td class="doxyParamItemDescription"><p>A generic callable object, usually a lambda, invoked to perform the test suite.</p></td>
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


<div class="doxyXrefSect">
<dl class="doxyXrefSectList">
<dt class="doxyXrefSectTitle"><a href=/micro-test-plus-xpack/docs/api/pages/deprecated/#_deprecated000054>Deprecated</a></dt>
<dd class="doxyXrefSectDescription">
<p>use <a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a> (since 5.1.0)</p>
</dd>
</dl>
</div>

<p>Forwards the name, the callable, and the arguments to <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00428">428</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h/#l00184">184</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h">runner-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a2636252ac7f80b7425cf2e5eced77834">184</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a2636252ac7f80b7425cf2e5eced77834">runner::suite</a> (std::string_view name, Callable_T&amp;&amp; callable,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">185</span><span class="doxyLineContent"><span class="doxyHighlight">                 Args_T&amp;&amp;... arguments)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">186</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">187</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite</a> (name, std::forward&lt;Callable_T&gt; (callable),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">188</span><span class="doxyLineContent"><span class="doxyHighlight">               std::forward&lt;Args_T&gt; (arguments)...);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">189</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite</a>.</p>


<p>Referenced by <a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite</a>, <a href="#a0e478c394741ff78f65a7e2c0822ba50">list_test_case</a>, <a href="#aa34a0418d54c633630a089eb2b5a61ee">operator=</a>, <a href="#a1dcc8f8d7f80044c67c492a1aebe3043">register_suite</a>, <a href="#a7c4dbf695c086ca4d3f0ce33e6d561f7">run_suites</a> and <a href="#a67d3cf710cccd419c127e63c2c30e9fe">static_suites_count</a>.</p>

</div>
</div>

### suites\_count() {#a6ed3a02ced62ed475c75678cd9e91be1}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">size_t micro_os_plus::micro_test_plus::runner::suites_count (void)</td>
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

<p>Deprecated count of the test suites added with <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span>, plus the top suite.</p>


<p>Returns <span class="doxyComputerOutput"><a href="#a9484b22aa909151712144cd39130187a">added_suites_count()</a></span> plus one, for the top suite. The name suggested that all the suites are counted, while the static suites are not. Use <span class="doxyComputerOutput"><a href="#a9484b22aa909151712144cd39130187a">added_suites_count()</a></span>, plus one for the top suite, or <span class="doxyComputerOutput"><a href="#ac29e4b993bb3fe795eb8900231cbf5c4">total_suites_count()</a></span>.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The number of test suites added with <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span>, plus one.</p></dd>
</dl>


<div class="doxyXrefSect">
<dl class="doxyXrefSectList">
<dt class="doxyXrefSectTitle"><a href=/micro-test-plus-xpack/docs/api/pages/deprecated/#_deprecated000056>Deprecated</a></dt>
<dd class="doxyXrefSectDescription">
<p>use <a href="#a9484b22aa909151712144cd39130187a">added_suites_count()</a> or <a href="#ac29e4b993bb3fe795eb8900231cbf5c4">total_suites_count()</a> (since 5.1.0)</p>
</dd>
</dl>
</div>

<p>Returns <span class="doxyComputerOutput"><a href="#a9484b22aa909151712144cd39130187a">added_suites_count()</a></span> plus one, for the top suite, as before the rename.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00616">616</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00854">854</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a6ed3a02ced62ed475c75678cd9e91be1">854</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a6ed3a02ced62ed475c75678cd9e91be1">runner::suites_count</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">855</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">856</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a9484b22aa909151712144cd39130187a">added_suites_count</a> () + 1;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">857</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a9484b22aa909151712144cd39130187a">added_suites_count</a>.</p>

</div>
</div>

### timings() {#af314280f14d61d37da276567685ec2a8}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const detail::stopwatch &amp; micro_os_plus::micro_test_plus::runner::timings (void)</td>
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

<p>Deprecated access to the timings of the test session.</p>


<p>Returns the internal stopwatch of the session, started by <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span> and stopped at the end of <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span>; the elapsed time is complete only after <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span> has returned. In v5.0.1, the returned class was <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a53a6bc7f86b15378c8296b3647e7013f">detail::timestamps</a></span>, now a deprecated alias; only its read-only members are kept. The timings are internal; the elapsed times are shown by the reporters.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A const reference to the stopwatch of the session.</p></dd>
</dl>


<div class="doxyXrefSect">
<dl class="doxyXrefSectList">
<dt class="doxyXrefSectTitle"><a href=/micro-test-plus-xpack/docs/api/pages/deprecated/#_deprecated000057>Deprecated</a></dt>
<dd class="doxyXrefSectDescription">
<p>the timings are internal (since 5.1.0)</p>
</dd>
</dl>
</div>

<p>Returns a const reference to the <span class="doxyComputerOutput">stopwatch</span> member.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00687">687</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h/#l00120">120</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h">runner-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#af314280f14d61d37da276567685ec2a8">120</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#af314280f14d61d37da276567685ec2a8">runner::timings</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">121</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">122</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a13b3cf196a1b12cb90a12c4b84223d15">stopwatch_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">123</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a13b3cf196a1b12cb90a12c4b84223d15">stopwatch_</a>.</p>

</div>
</div>

### timings() {#a7d3ccfaf760cb2f4ace586c222b22244}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">detail::stopwatch &amp; micro_os_plus::micro_test_plus::runner::timings (void)</td>
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

<p>Deprecated access to the timings of the test session, as a non-<span class="doxyComputerOutput">const</span> reference.</p>


<p>Kept for the v5.0.1 code that binds a non-<span class="doxyComputerOutput">const</span> reference (<span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a53a6bc7f86b15378c8296b3647e7013f">detail::timestamps</a>&amp; t = tr.timings ();</span>). The test code must not start or stop the stopwatch through it, since the reporters show its elapsed time.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A reference to the stopwatch of the session.</p></dd>
</dl>


<div class="doxyXrefSect">
<dl class="doxyXrefSectList">
<dt class="doxyXrefSectTitle"><a href=/micro-test-plus-xpack/docs/api/pages/deprecated/#_deprecated000058>Deprecated</a></dt>
<dd class="doxyXrefSectDescription">
<p>the timings are internal (since 5.1.0)</p>
</dd>
</dl>
</div>

<p>Returns a reference to the <span class="doxyComputerOutput">stopwatch</span> member.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00705">705</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h/#l00131">131</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h">runner-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a7d3ccfaf760cb2f4ace586c222b22244">131</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#af314280f14d61d37da276567685ec2a8">runner::timings</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">132</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">133</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a13b3cf196a1b12cb90a12c4b84223d15">stopwatch_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">134</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a13b3cf196a1b12cb90a12c4b84223d15">stopwatch_</a>.</p>

</div>
</div>

### total\_suites\_count() {#ac29e4b993bb3fe795eb8900231cbf5c4}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">size_t micro_os_plus::micro_test_plus::runner::total_suites_count (void)</td>
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

<p>Returns the count of all the test suites.</p>


<p>One, for the top suite, plus <span class="doxyComputerOutput"><a href="#a9484b22aa909151712144cd39130187a">added_suites_count()</a></span> plus <span class="doxyComputerOutput"><a href="#a67d3cf710cccd419c127e63c2c30e9fe">static_suites_count()</a></span>; this is the number of suites printed by the reporters.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The total number of test suites managed by this runner, including the top suite and the static suites.</p></dd>
</dl>


<p>Returns one, for the top suite, plus the count of the suites added with <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span>, plus the count of the static suites.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00521">521</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00886">886</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ac29e4b993bb3fe795eb8900231cbf5c4">886</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ac29e4b993bb3fe795eb8900231cbf5c4">runner::total_suites_count</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">887</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">888</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> 1 + <a href="#a9484b22aa909151712144cd39130187a">added_suites_count</a> () + <a href="#a67d3cf710cccd419c127e63c2c30e9fe">static_suites_count</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">889</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9484b22aa909151712144cd39130187a">added_suites_count</a> and <a href="#a67d3cf710cccd419c127e63c2c30e9fe">static_suites_count</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a7033819609bfad2db2ecc7a024e91b2c">micro_os_plus::micro_test_plus::detail::reporter_tap::end_session</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a6bf3aac88a5e66e2f93eb32c54dbdd14">micro_os_plus::micro_test_plus::detail::reporter::format_session_totals</a>.</p>

</div>
</div>

### totals() {#a2c8a999cc273356ea10ed34fb12dcf5a}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const counters &amp; micro_os_plus::micro_test_plus::runner::totals (void)</td>
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

<p>Gets the totals of the test session.</p>


<p>The counters include the checks and the test cases of all the suites that were run, including the top suite; they are complete only after <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span> has returned. The totals are read-only; there is no non-const overload, so that the counters cannot be modified from the test code.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A const reference to the session totals.</p></dd>
</dl>


<p>Returns a const reference to the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters">counters</a></span> member.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00668">668</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h/#l00109">109</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h">runner-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a2c8a999cc273356ea10ed34fb12dcf5a">109</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a2c8a999cc273356ea10ed34fb12dcf5a">runner::totals</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">110</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">111</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a04b52f3243abe3a9b08b44efd03e4b57">totals_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">112</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a04b52f3243abe3a9b08b44efd03e4b57">totals_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ace9c2dfffc49a97516b96dacaf87b943">micro_os_plus::micro_test_plus::detail::reporter_human::end_session</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a6bf3aac88a5e66e2f93eb32c54dbdd14">micro_os_plus::micro_test_plus::detail::reporter::format_session_totals</a>.</p>

</div>
</div>

### verbosity() {#a94a9df0418776ebce476cd9a2e4f591f}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_test_plus::verbosity micro_os_plus::micro_test_plus::runner::verbosity (void)</td>
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

<p>Deprecated name of <span class="doxyComputerOutput"><a href="#a1dd0221dca8e7382f0b625ff6316ed92">verbosity_level()</a></span>.</p>


<p>Calls <span class="doxyComputerOutput"><a href="#a1dd0221dca8e7382f0b625ff6316ed92">verbosity_level()</a></span>. The old name hid the <span class="doxyComputerOutput"><a href="#a94a9df0418776ebce476cd9a2e4f591f">verbosity</a></span> enumeration inside the runner.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The value returned by <span class="doxyComputerOutput"><a href="#a1dd0221dca8e7382f0b625ff6316ed92">verbosity_level()</a></span>.</p></dd>
</dl>


<div class="doxyXrefSect">
<dl class="doxyXrefSectList">
<dt class="doxyXrefSectTitle"><a href=/micro-test-plus-xpack/docs/api/pages/deprecated/#_deprecated000055>Deprecated</a></dt>
<dd class="doxyXrefSectDescription">
<p>use <a href="#a1dd0221dca8e7382f0b625ff6316ed92">verbosity_level()</a> (since 5.1.0)</p>
</dd>
</dl>
</div>

<p>Forwards to <span class="doxyComputerOutput"><a href="#a1dd0221dca8e7382f0b625ff6316ed92">verbosity_level()</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00576">576</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h/#l00099">99</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h">runner-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a94a9df0418776ebce476cd9a2e4f591f">99</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a94a9df0418776ebce476cd9a2e4f591f">runner::verbosity</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight"> -&gt; <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914b">micro_test_plus::verbosity</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">100</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">101</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a1dd0221dca8e7382f0b625ff6316ed92">verbosity_level</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">102</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a1dd0221dca8e7382f0b625ff6316ed92">verbosity_level</a>.</p>

</div>
</div>

### verbosity\_level() {#a1dd0221dca8e7382f0b625ff6316ed92}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_test_plus::verbosity micro_os_plus::micro_test_plus::runner::verbosity_level (void)</td>
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

<p>Returns the verbosity level of the console output.</p>


<p>The level is selected with the <span class="doxyComputerOutput">--silent</span>, <span class="doxyComputerOutput">--quiet</span>, and <span class="doxyComputerOutput">--verbose</span> command-line options, or with <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#aff30f0303a958a549a2f4b6e67db00d5">runner_options::verbosity_level</a></span>; the tests can use it to decide whether to display their own messages. Before <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span> is called, it is <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">verbosity::normal</a></span>.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The active <span class="doxyComputerOutput"><a href="#a94a9df0418776ebce476cd9a2e4f591f">verbosity</a></span> value.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Since</dt>
<dd><p>5.1.0</p></dd>
</dl>


<p>Returns the level stored in <span class="doxyComputerOutput"><a href="#a1d4b6b07a507c00a5ac262e098b12ad3">verbosity_</a></span>, which does not depend on the reporter, so the call is safe before <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00540">540</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h/#l00077">77</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h">runner-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a1dd0221dca8e7382f0b625ff6316ed92">77</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a1dd0221dca8e7382f0b625ff6316ed92">runner::verbosity_level</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight"> -&gt; <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914b">micro_test_plus::verbosity</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">78</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">79</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a1d4b6b07a507c00a5ac262e098b12ad3">verbosity_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">80</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a1d4b6b07a507c00a5ac262e098b12ad3">verbosity_</a>.</p>


<p>Referenced by <a href="#a94a9df0418776ebce476cd9a2e4f591f">verbosity</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Private Member Functions

### abort() {#af0682165f5d07b13fd21e3f6f8da546c}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::runner::abort (const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> &amp; sl, bool is_requirement)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Aborts test execution, telling the reporter why.</p>


<p>Implements <span class="doxyComputerOutput"><a href="#a7bc806540e65c21095ef1ea1ef970db2">abort()</a></span>, which calls it for an explicit abort; also called by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base">detail::runnable_base</a></span>, a friend, for a failed requirement without exceptions, so that the reporter names the cause.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">sl</td>
<td class="doxyParamItemDescription"><p>The source location from which the abort is triggered.</p></td>
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
<dd><p>Does not return.</p></dd>
</dl>


<p>While the report is open, from <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span>, which begins it (the test cases of the top suite run from then on), to the end of <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span>, the reporter writes the buffered results and the location of the abort, with <span class="doxyComputerOutput">abort_session()</span>, to the console and to the output file, since the totals are never reached. Otherwise, there is no report to complete, and the location is written to <span class="doxyComputerOutput">stderr</span>. The standard streams are then flushed, and the handler set by <span class="doxyComputerOutput"><a href="#a711756a8c6958c4036527a290c481f86">set_abort_handler()</a></span> is called, if any. If there is no handler, or if it returns, the process is terminated via <span class="doxyComputerOutput">::abort()</span>.</p>


<p>The <span class="doxyComputerOutput"><a href="#ad107cec6e32daac2da4cd665c7444e51">aborted_</a></span> flag is set first, and never cleared, so that, if the handler throws an exception, the test cases and the suites pass it on (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#adb4333ecb107fee477156b661f0b1512">test_case::run()</a></span>), and the runner refuses to run again. An abort after another one, for example from the code that caught the exception, is not reported again, since the report is already complete; the handler is still called.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00835">835</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00798">798</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#af0682165f5d07b13fd21e3f6f8da546c">798</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a7bc806540e65c21095ef1ea1ef970db2">runner::abort</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; sl, </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> is_requirement)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">799</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">800</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">801</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">802</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">803</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">804</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (!<a href="#ad107cec6e32daac2da4cd665c7444e51">aborted_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">805</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">806</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#ad107cec6e32daac2da4cd665c7444e51">aborted_</a> = </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">807</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">808</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> == <a href="#a081c4bd4495097c8c7f913ef837899baadb1687e1890c33928fe61b7cb4ac2f0e">session_state::initialised</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">809</span><span class="doxyLineContent"><span class="doxyHighlight">            || <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> == <a href="#a081c4bd4495097c8c7f913ef837899baa75101dcdfc88455bcafc9e53e0b06689">session_state::running</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">810</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">811</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>-&gt;abort_session (sl, is_requirement);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">812</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">813</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">814</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">815</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightComment">// The type of `line()` depends on the toolchain</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">816</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightComment">// (`uint_least32_t` for `std::source_location`); widen it</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">817</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightComment">// implicitly, without a cast that would be useless on some</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">818</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightComment">// platforms.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">819</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> line = sl.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#aab9d006004611ac0526852a09f675c66">line</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">820</span><span class="doxyLineContent"><span class="doxyHighlight">            fprintf (stderr, </span><span class="doxyHighlightStringLiteral">"error: test execution aborted at %s:%lu\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">821</span><span class="doxyLineContent"><span class="doxyHighlight">                     <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-utility-functions/#ga791f22f0c85b6436c9016821907b0653">utility::extract_file_name</a> (sl.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#a3df499675aacb7ab9192cfb9a5371874">file_name</a> ()), line);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">822</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">823</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">824</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">825</span><span class="doxyLineContent"><span class="doxyHighlight">    fflush (stdout);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">826</span><span class="doxyLineContent"><span class="doxyHighlight">    fflush (stderr);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">827</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">828</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a1138505536cf6afe69dea5ae044eeb5a">abort_handler_</a> != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">829</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">830</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a1138505536cf6afe69dea5ae044eeb5a">abort_handler_</a> (sl);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">831</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">832</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">833</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a7bc806540e65c21095ef1ea1ef970db2">::abort</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">834</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a7bc806540e65c21095ef1ea1ef970db2">abort</a>, <a href="#a1138505536cf6afe69dea5ae044eeb5a">abort_handler_</a>, <a href="#ad107cec6e32daac2da4cd665c7444e51">aborted_</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-utility-functions/#ga791f22f0c85b6436c9016821907b0653">micro_os_plus::micro_test_plus::utility::extract_file_name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#a3df499675aacb7ab9192cfb9a5371874">micro_os_plus::micro_test_plus::reflection::source_location::file_name</a>, <a href="#a081c4bd4495097c8c7f913ef837899baadb1687e1890c33928fe61b7cb4ac2f0e">initialised</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#aab9d006004611ac0526852a09f675c66">micro_os_plus::micro_test_plus::reflection::source_location::line</a>, <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>, <a href="#a081c4bd4495097c8c7f913ef837899baa75101dcdfc88455bcafc9e53e0b06689">running</a> and <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a>.</p>

</div>
</div>

### is\_selected() {#a2b0adeef059676a455d9506ba8a06d26}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::runner::is_selected (const char * name, size_t level)</td>
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

<p>Checks whether a suite or a test case is selected by the filter pattern of its nesting level.</p>


<p>Level 0 refers to the suites, level 1 to their test cases, and each further level to the test cases nested one level deeper. A name is selected when there is no pattern for its level, or when it matches one of the alternatives of the pattern, separated by <span class="doxyComputerOutput">|</span>, as defined by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-utility-functions/#gaa2f0f4cff320a783ad2347c9ff3fc731">utility::is_match()</a></span>.</p>


<p>Also called by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base">detail::runnable_base</a></span>, a friend, before running a test case.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">name</td>
<td class="doxyParamItemDescription"><p>The name of the suite or of the test case.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">level</td>
<td class="doxyParamItemDescription"><p>The nesting level; 0 for suites.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p><span class="doxyComputerOutput">true</span> if it must run, <span class="doxyComputerOutput">false</span> if it must be skipped.</p></dd>
</dl>


<p>The levels beyond the last pattern are not filtered. Otherwise, the alternatives of the pattern, separated by <span class="doxyComputerOutput">|</span>, are tried in order, until one matches the whole name.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00796">796</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00486">486</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a2b0adeef059676a455d9506ba8a06d26">486</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a2b0adeef059676a455d9506ba8a06d26">runner::is_selected</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* name, </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> level)</span><span class="doxyHighlightKeyword"> const</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">487</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">  </span><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">488</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (level &gt;= <a href="#a12b7d597d11b0ff284cdb84a7c4ea927">filter_patterns_</a>.size ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">489</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">490</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">491</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">492</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">493</span><span class="doxyLineContent"><span class="doxyHighlight">    std::string_view alternatives{ <a href="#a12b7d597d11b0ff284cdb84a7c4ea927">filter_patterns_</a>[level] };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">494</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">while</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">495</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">496</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> separator = alternatives.find (</span><span class="doxyHighlightCharLiteral">'|'</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">497</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-utility-functions/#gaa2f0f4cff320a783ad2347c9ff3fc731">utility::is_match</a> (name, alternatives.substr (0, separator)))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">498</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">499</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">500</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">501</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (separator == std::string_view::npos)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">502</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">503</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">504</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">505</span><span class="doxyLineContent"><span class="doxyHighlight">        alternatives.remove_prefix (separator + 1);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">506</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">507</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a12b7d597d11b0ff284cdb84a7c4ea927">filter_patterns_</a> and <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-utility-functions/#gaa2f0f4cff320a783ad2347c9ff3fc731">micro_os_plus::micro_test_plus::utility::is_match</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a38cf903fb0ba5b76b1eb2350b6385962">micro_os_plus::micro_test_plus::detail::runnable_base::after_test_case_create</a> and <a href="#a7c4dbf695c086ca4d3f0ce33e6d561f7">run_suites</a>.</p>

</div>
</div>

### list\_test\_case() {#a0e478c394741ff78f65a7e2c0822ba50}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::runner::list_test_case (const class <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a> &amp; suite, const class <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a> &amp; test_case)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Lists a test case, instead of running it.</p>


<p>Called by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base">detail::runnable_base</a></span>, a friend, for each selected test case created while the test cases are listed (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#ac4f95336439b329d0f3731a5dcafb6f9">runner_options::list_tests</a></span>). The name of the suite is written before its first listed test case, indented by two spaces, and the name of the test case after it, indented by four spaces, through the reporter, to the console, unless the verbosity is <span class="doxyComputerOutput">silent</span>, and to the output file, if any.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">suite</td>
<td class="doxyParamItemDescription"><p>The suite of the test case.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">test_case</td>
<td class="doxyParamItemDescription"><p>The test case to list.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>The suites are listed in the order in which their first test cases are created: the top suite first, during <span class="doxyComputerOutput">main()</span>, then the other suites, in the order of <span class="doxyComputerOutput"><a href="#a7c4dbf695c086ca4d3f0ce33e6d561f7">run_suites()</a></span>; so the name of a suite is written when it differs from the previous one.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00816">816</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00519">519</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a0e478c394741ff78f65a7e2c0822ba50">519</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a0e478c394741ff78f65a7e2c0822ba50">runner::list_test_case</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>&amp; <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">520</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">521</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (&amp;<a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a> != <a href="#af8ce5a496dba305f6fbd45005d580321">listed_suite_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">522</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">523</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#af8ce5a496dba305f6fbd45005d580321">listed_suite_</a> = &amp;<a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">524</span><span class="doxyLineContent"><span class="doxyHighlight">        ++<a href="#acb06cb7ebf949b8af5c5d57645c56e4a">listed_suites_count_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">525</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>-&gt;write_line (<a href="#a1d4b6b07a507c00a5ac262e098b12ad3">verbosity_</a> != <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">verbosity::silent</a>, </span><span class="doxyHighlightStringLiteral">"  %s\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">526</span><span class="doxyLineContent"><span class="doxyHighlight">                               <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">527</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">528</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">529</span><span class="doxyLineContent"><span class="doxyHighlight">    ++<a href="#a90900e7d0a4571407b3727e031e46685">listed_test_cases_count_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">530</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>-&gt;write_line (<a href="#a1d4b6b07a507c00a5ac262e098b12ad3">verbosity_</a> != <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">verbosity::silent</a>, </span><span class="doxyHighlightStringLiteral">"    %s\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">531</span><span class="doxyLineContent"><span class="doxyHighlight">                           <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">532</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#af8ce5a496dba305f6fbd45005d580321">listed_suite_</a>, <a href="#acb06cb7ebf949b8af5c5d57645c56e4a">listed_suites_count_</a>, <a href="#a90900e7d0a4571407b3727e031e46685">listed_test_cases_count_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">micro_os_plus::micro_test_plus::detail::runnable_base::name</a>, <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">micro_os_plus::micro_test_plus::silent</a>, <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a> and <a href="#a1d4b6b07a507c00a5ac262e098b12ad3">verbosity_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a38cf903fb0ba5b76b1eb2350b6385962">micro_os_plus::micro_test_plus::detail::runnable_base::after_test_case_create</a>.</p>

</div>
</div>

### parse\_options() {#a2319eb34fc8b601ca5e6a8ec538ba138}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">runner_options micro_os_plus::micro_test_plus::runner::parse_options (int argc, char * argv=[])</td>
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

<p>Parses the command-line options of the test session.</p>


<p>All the options are parsed here, once, and passed to the reporter; the arguments not recognised as options are ignored, since the applications may define their own. A missing option argument, an unknown reporter name, or an unknown colour mode, is reported on <span class="doxyComputerOutput">stderr</span>, the option is ignored, and <span class="doxyComputerOutput"><a href="#a8e9e6782d6cde59ac82fb6fb459888cb">has_option_errors_</a></span> is set.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">argc</td>
<td class="doxyParamItemDescription"><p>The argument count from main().</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">argv</td>
<td class="doxyParamItemDescription"><p>The argument vector from main().</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The parsed options.</p></dd>
</dl>


<p>Scans the arguments after <span class="doxyComputerOutput">argv[0]</span>, in order, for:</p>


<ul class="doxyList ">
<li><span class="doxyComputerOutput">--<a href="#a65250ff363fbb3b5869bbe4de9578e86">reporter</a>=&lt;name&gt;</span> or <span class="doxyComputerOutput">--<a href="#a65250ff363fbb3b5869bbe4de9578e86">reporter</a> &lt;name&gt;</span>, with <span class="doxyComputerOutput">tap</span> (the default) or <span class="doxyComputerOutput">human</span>;</li>
<li><span class="doxyComputerOutput">--verbose</span>, <span class="doxyComputerOutput">--quiet</span>, and <span class="doxyComputerOutput">--silent</span>;</li>
<li><span class="doxyComputerOutput">--output-file=&lt;path&gt;</span> or <span class="doxyComputerOutput">--output-file &lt;path&gt;</span>;</li>
<li><span class="doxyComputerOutput">--color[=&lt;when&gt;]</span>, as in the GNU tools, with <span class="doxyComputerOutput">always</span>, <span class="doxyComputerOutput">never</span>, or <span class="doxyComputerOutput">auto</span> (the default), and their GNU synonyms (<span class="doxyComputerOutput">yes</span> and <span class="doxyComputerOutput">force</span>, <span class="doxyComputerOutput">no</span> and <span class="doxyComputerOutput">none</span>, <span class="doxyComputerOutput">tty</span> and <span class="doxyComputerOutput">if-tty</span>); <span class="doxyComputerOutput">--color</span> alone means <span class="doxyComputerOutput">always</span>;</li>
<li><span class="doxyComputerOutput">--use-colour=&lt;mode&gt;</span> or <span class="doxyComputerOutput">--use-colour &lt;mode&gt;</span>, the Catch2 and Boost UT alternative to <span class="doxyComputerOutput">--color</span>, with <span class="doxyComputerOutput">yes</span>, <span class="doxyComputerOutput">no</span>, or <span class="doxyComputerOutput">auto</span>, or any of the <span class="doxyComputerOutput">--color</span> values;</li>
<li><span class="doxyComputerOutput">--filter=&lt;pattern&gt;</span> or <span class="doxyComputerOutput">--filter &lt;pattern&gt;</span>;</li>
<li><span class="doxyComputerOutput">--list-tests</span>, or its short form <span class="doxyComputerOutput">--list</span>, as in Catch2 and Boost UT, to list the test cases instead of running them.</li>
</ul>

<p>When an option is repeated, the last one takes effect, except <span class="doxyComputerOutput">--filter</span>, whose patterns are all kept, in order, one per nesting level; <span class="doxyComputerOutput">--color</span> and <span class="doxyComputerOutput">--use-colour</span> set the same option. An option argument given separately is the next argument, whatever its content; <span class="doxyComputerOutput">--color</span> accepts its value only after <span class="doxyComputerOutput">=</span>. The other arguments are ignored. The whole command line is kept in the options, to be listed by the reporter.</p>


<p>A missing option argument, an unknown reporter name, or an unknown colour mode, is reported on <span class="doxyComputerOutput">stderr</span>, the option is ignored, and <span class="doxyComputerOutput"><a href="#a8e9e6782d6cde59ac82fb6fb459888cb">has_option_errors_</a></span> is set, so that <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span> returns 2; the parsing continues with the next argument.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00775">775</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00332">332</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a2319eb34fc8b601ca5e6a8ec538ba138">332</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a2319eb34fc8b601ca5e6a8ec538ba138">runner::parse_options</a> (</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> argc, </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* argv[])</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">333</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">334</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options">runner_options</a> opts{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">335</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">336</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (argc &lt;= 0 || argv == </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">337</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">338</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> opts;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">339</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">340</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">341</span><span class="doxyLineContent"><span class="doxyHighlight">    opts.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#a7c2cca740efdbdc4927cac43aa456611">arguments</a> = { argv, </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (argc) };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">342</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">343</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> std::string_view reporter_option{ </span><span class="doxyHighlightStringLiteral">"--reporter"</span><span class="doxyHighlight"> };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">344</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> std::string_view output_file_option{ </span><span class="doxyHighlightStringLiteral">"--output-file"</span><span class="doxyHighlight"> };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">345</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> std::string_view color_option{ </span><span class="doxyHighlightStringLiteral">"--color"</span><span class="doxyHighlight"> };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">346</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> std::string_view use_colour_option{ </span><span class="doxyHighlightStringLiteral">"--use-colour"</span><span class="doxyHighlight"> };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">347</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> std::string_view filter_option{ </span><span class="doxyHighlightStringLiteral">"--filter"</span><span class="doxyHighlight"> };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">348</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">349</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Get the value of an option given as `--option=&lt;value&gt;` or as</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">350</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// `--option &lt;value&gt;`; the latter advances the index past the value.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">351</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Return false if the argument is not this option, or if its value is</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">352</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// missing, which is reported as an error.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">353</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> get_value = [&amp;] (std::string_view option, </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight">&amp; i,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">354</span><span class="doxyLineContent"><span class="doxyHighlight">                          std::string_view&amp; value) -&gt; </span><span class="doxyHighlightKeywordType">bool</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">355</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">356</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string_view argument{ opts.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#a7c2cca740efdbdc4927cac43aa456611">arguments</a>[i] };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">357</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (argument == option)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">358</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">359</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (i + 1 &gt;= opts.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#a7c2cca740efdbdc4927cac43aa456611">arguments</a>.size ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">360</span><span class="doxyLineContent"><span class="doxyHighlight">              {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">361</span><span class="doxyLineContent"><span class="doxyHighlight">                fprintf (stderr, </span><span class="doxyHighlightStringLiteral">"error: %.*s option requires an argument\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">362</span><span class="doxyLineContent"><span class="doxyHighlight">                         </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (option.size ()), option.data ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">363</span><span class="doxyLineContent"><span class="doxyHighlight">                <a href="#a8e9e6782d6cde59ac82fb6fb459888cb">has_option_errors_</a> = </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">364</span><span class="doxyLineContent"><span class="doxyHighlight">                </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">365</span><span class="doxyLineContent"><span class="doxyHighlight">              }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">366</span><span class="doxyLineContent"><span class="doxyHighlight">            value = opts.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#a7c2cca740efdbdc4927cac43aa456611">arguments</a>[++i];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">367</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">368</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">369</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (argument.starts_with (option)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">370</span><span class="doxyLineContent"><span class="doxyHighlight">            &amp;&amp; argument.substr (option.size ()).starts_with (</span><span class="doxyHighlightCharLiteral">'='</span><span class="doxyHighlight">))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">371</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">372</span><span class="doxyLineContent"><span class="doxyHighlight">            value = argument.substr (option.size () + 1);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">373</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">374</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">375</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">376</span><span class="doxyLineContent"><span class="doxyHighlight">      };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">377</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">378</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Set the colour mode from the value of `--color` or of</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">379</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// `--use-colour`; both accept the values and the synonyms of the GNU</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">380</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// tools, which include those of Catch2 and Boost UT (`yes`, `no`, and</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">381</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// `auto`). An unknown mode is reported as an error.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">382</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> set_colour_mode = [&amp;] (std::string_view value)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">383</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">384</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (value == </span><span class="doxyHighlightStringLiteral">"always"</span><span class="doxyHighlight"> || value == </span><span class="doxyHighlightStringLiteral">"yes"</span><span class="doxyHighlight"> || value == </span><span class="doxyHighlightStringLiteral">"force"</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">385</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">386</span><span class="doxyLineContent"><span class="doxyHighlight">            opts.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#a48ed4dd71eff02911c2d6943ba616850">colour</a> = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a603af2d1c9643caa351305180b2e905baf9f90eeaf400d228facde6bc48da5cfb">colour_mode::always</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">387</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">388</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (value == </span><span class="doxyHighlightStringLiteral">"never"</span><span class="doxyHighlight"> || value == </span><span class="doxyHighlightStringLiteral">"no"</span><span class="doxyHighlight"> || value == </span><span class="doxyHighlightStringLiteral">"none"</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">389</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">390</span><span class="doxyLineContent"><span class="doxyHighlight">            opts.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#a48ed4dd71eff02911c2d6943ba616850">colour</a> = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a603af2d1c9643caa351305180b2e905bac7561db7a418dd39b2201dfe110ab4a4">colour_mode::never</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">391</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">392</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (value == </span><span class="doxyHighlightStringLiteral">"auto"</span><span class="doxyHighlight"> || value == </span><span class="doxyHighlightStringLiteral">"tty"</span><span class="doxyHighlight"> || value == </span><span class="doxyHighlightStringLiteral">"if-tty"</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">393</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">394</span><span class="doxyLineContent"><span class="doxyHighlight">            opts.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#a48ed4dd71eff02911c2d6943ba616850">colour</a> = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a603af2d1c9643caa351305180b2e905ba2bd9c0ed00116be1258e0cc66617d7c8">colour_mode::automatic</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">395</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">396</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">397</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">398</span><span class="doxyLineContent"><span class="doxyHighlight">            fprintf (stderr, </span><span class="doxyHighlightStringLiteral">"error: unknown colour mode '%.*s'\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">399</span><span class="doxyLineContent"><span class="doxyHighlight">                     </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (value.size ()), value.data ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">400</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="#a8e9e6782d6cde59ac82fb6fb459888cb">has_option_errors_</a> = </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">401</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">402</span><span class="doxyLineContent"><span class="doxyHighlight">      };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">403</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">404</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> i = 1; i &lt; opts.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#a7c2cca740efdbdc4927cac43aa456611">arguments</a>.size (); ++i)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">405</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">406</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string_view argument{ opts.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#a7c2cca740efdbdc4927cac43aa456611">arguments</a>[i] };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">407</span><span class="doxyLineContent"><span class="doxyHighlight">        std::string_view value{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">408</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">409</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (argument == </span><span class="doxyHighlightStringLiteral">"--verbose"</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">410</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">411</span><span class="doxyLineContent"><span class="doxyHighlight">            opts.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#aff30f0303a958a549a2f4b6e67db00d5">verbosity_level</a> = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">verbosity::verbose</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">412</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">413</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (argument == </span><span class="doxyHighlightStringLiteral">"--quiet"</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">414</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">415</span><span class="doxyLineContent"><span class="doxyHighlight">            opts.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#aff30f0303a958a549a2f4b6e67db00d5">verbosity_level</a> = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba556966c7830465dc4623d62e32cec31d">verbosity::quiet</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">416</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">417</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (argument == </span><span class="doxyHighlightStringLiteral">"--silent"</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">418</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">419</span><span class="doxyLineContent"><span class="doxyHighlight">            opts.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#aff30f0303a958a549a2f4b6e67db00d5">verbosity_level</a> = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">verbosity::silent</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">420</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">421</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (argument == </span><span class="doxyHighlightStringLiteral">"--list-tests"</span><span class="doxyHighlight"> || argument == </span><span class="doxyHighlightStringLiteral">"--list"</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">422</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">423</span><span class="doxyLineContent"><span class="doxyHighlight">            opts.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#ac4f95336439b329d0f3731a5dcafb6f9">list_tests</a> = </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">424</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">425</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (get_value (reporter_option, i, value))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">426</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">427</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (value == </span><span class="doxyHighlightStringLiteral">"human"</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">428</span><span class="doxyLineContent"><span class="doxyHighlight">              {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">429</span><span class="doxyLineContent"><span class="doxyHighlight">                opts.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#ad22d04df014c5b0658b6e7bd239f15b0">selected_reporter</a> = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a913c4161963e9439b20857358486e8b2a99e9bae675b12967251c175696f00a70">reporter_kind::human</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">430</span><span class="doxyLineContent"><span class="doxyHighlight">              }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">431</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (value == </span><span class="doxyHighlightStringLiteral">"tap"</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">432</span><span class="doxyLineContent"><span class="doxyHighlight">              {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">433</span><span class="doxyLineContent"><span class="doxyHighlight">                opts.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#ad22d04df014c5b0658b6e7bd239f15b0">selected_reporter</a> = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a913c4161963e9439b20857358486e8b2a8f98645041aa7d5f53913329c6946a6b">reporter_kind::tap</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">434</span><span class="doxyLineContent"><span class="doxyHighlight">              }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">435</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">436</span><span class="doxyLineContent"><span class="doxyHighlight">              {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">437</span><span class="doxyLineContent"><span class="doxyHighlight">                fprintf (stderr, </span><span class="doxyHighlightStringLiteral">"error: unknown reporter '%.*s'\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">438</span><span class="doxyLineContent"><span class="doxyHighlight">                         </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (value.size ()), value.data ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">439</span><span class="doxyLineContent"><span class="doxyHighlight">                <a href="#a8e9e6782d6cde59ac82fb6fb459888cb">has_option_errors_</a> = </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">440</span><span class="doxyLineContent"><span class="doxyHighlight">              }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">441</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">442</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (get_value (output_file_option, i, value))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">443</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">444</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightComment">// The value is a suffix of a null-terminated argv[] string,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">445</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightComment">// so it is null-terminated too. An empty path disables the</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">446</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightComment">// output file.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">447</span><span class="doxyLineContent"><span class="doxyHighlight">            opts.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#aacf79acd1554b6e8899524bc02ee6257">output_file_path</a> = value.empty () ? nullptr : value.data ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">448</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">449</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (get_value (use_colour_option, i, value))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">450</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">451</span><span class="doxyLineContent"><span class="doxyHighlight">            set_colour_mode (value);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">452</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">453</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (argument == color_option)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">454</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">455</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightComment">// As in the GNU tools, the option alone means `always`, and</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">456</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightComment">// the next argument is never taken as its value.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">457</span><span class="doxyLineContent"><span class="doxyHighlight">            opts.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#a48ed4dd71eff02911c2d6943ba616850">colour</a> = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a603af2d1c9643caa351305180b2e905baf9f90eeaf400d228facde6bc48da5cfb">colour_mode::always</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">458</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">459</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (argument.starts_with (color_option)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">460</span><span class="doxyLineContent"><span class="doxyHighlight">                 &amp;&amp; argument.substr (color_option.size ()).starts_with (</span><span class="doxyHighlightCharLiteral">'='</span><span class="doxyHighlight">))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">461</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">462</span><span class="doxyLineContent"><span class="doxyHighlight">            set_colour_mode (argument.substr (color_option.size () + 1));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">463</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">464</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (get_value (filter_option, i, value))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">465</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">466</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightComment">// The view refers to the argv[] string, which remains valid</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">467</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightComment">// until the program ends.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">468</span><span class="doxyLineContent"><span class="doxyHighlight">            opts.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#a8dc9c5a5b6c89c12acd27d67d57618dd">filter_patterns</a>.push_back (value);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">469</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">470</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">471</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">472</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> opts;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">473</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a603af2d1c9643caa351305180b2e905baf9f90eeaf400d228facde6bc48da5cfb">micro_os_plus::micro_test_plus::always</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#a7c2cca740efdbdc4927cac43aa456611">micro_os_plus::micro_test_plus::runner_options::arguments</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a603af2d1c9643caa351305180b2e905ba2bd9c0ed00116be1258e0cc66617d7c8">micro_os_plus::micro_test_plus::automatic</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#a48ed4dd71eff02911c2d6943ba616850">micro_os_plus::micro_test_plus::runner_options::colour</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#a8dc9c5a5b6c89c12acd27d67d57618dd">micro_os_plus::micro_test_plus::runner_options::filter_patterns</a>, <a href="#a8e9e6782d6cde59ac82fb6fb459888cb">has_option_errors_</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a913c4161963e9439b20857358486e8b2a99e9bae675b12967251c175696f00a70">micro_os_plus::micro_test_plus::human</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#ac4f95336439b329d0f3731a5dcafb6f9">micro_os_plus::micro_test_plus::runner_options::list_tests</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a603af2d1c9643caa351305180b2e905bac7561db7a418dd39b2201dfe110ab4a4">micro_os_plus::micro_test_plus::never</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#aacf79acd1554b6e8899524bc02ee6257">micro_os_plus::micro_test_plus::runner_options::output_file_path</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba556966c7830465dc4623d62e32cec31d">micro_os_plus::micro_test_plus::quiet</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#ad22d04df014c5b0658b6e7bd239f15b0">micro_os_plus::micro_test_plus::runner_options::selected_reporter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">micro_os_plus::micro_test_plus::silent</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a913c4161963e9439b20857358486e8b2a8f98645041aa7d5f53913329c6946a6b">micro_os_plus::micro_test_plus::tap</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">micro_os_plus::micro_test_plus::verbose</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#aff30f0303a958a549a2f4b6e67db00d5">micro_os_plus::micro_test_plus::runner_options::verbosity_level</a>.</p>


<p>Referenced by <a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise</a>.</p>

</div>
</div>

### register\_suite() {#a1dcc8f8d7f80044c67c492a1aebe3043}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::runner::register_suite (std::unique_ptr&lt; class <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a> &gt; suite)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Registers a test suite with the runner.</p>


<p>Called by <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span>. Once <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span> has started, the suite is rejected: it is destroyed, the error is reported on <span class="doxyComputerOutput">stderr</span>, and <span class="doxyComputerOutput"><a href="#a999d64ffbd12dcacb59c34fbea4452ba">has_rejected_suites_</a></span> is set.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">suite</td>
<td class="doxyParamItemDescription"><p>Owning pointer to the test suite to register.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Takes ownership of the supplied <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a></span> unique pointer and appends it to the internal <span class="doxyComputerOutput"><a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a></span> vector, then inserts the suite into the list of suites, sorted by name, deferring execution until <span class="doxyComputerOutput"><a href="#a7c4dbf695c086ca4d3f0ce33e6d561f7">run_suites()</a></span> is called. The suite is inserted after it is stored, so that a failed allocation of the vector leaves it out of the list. If tracing is enabled, the suite name is logged for diagnostic purposes.</p>


<p>Once <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span> has started, the suite is rejected, since it would never run: <span class="doxyComputerOutput"><a href="#a7c4dbf695c086ca4d3f0ce33e6d561f7">run_suites()</a></span> takes the number of suites only once, before running them, and after the session has ended nothing runs. The error is reported on <span class="doxyComputerOutput">stderr</span>, the suite is destroyed when the pointer goes out of scope, and <span class="doxyComputerOutput"><a href="#a999d64ffbd12dcacb59c34fbea4452ba">has_rejected_suites_</a></span> is set, so that the exit code is not 0; if the session has already ended, the stored exit code is updated, for the later calls of <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00758">758</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00555">555</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a1dcc8f8d7f80044c67c492a1aebe3043">555</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a1dcc8f8d7f80044c67c492a1aebe3043">runner::register_suite</a> (std::unique_ptr&lt;class suite&gt; <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">556</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">557</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">558</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s '%s'\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__, <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>-&gt;name ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">559</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">560</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">561</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> == <a href="#a081c4bd4495097c8c7f913ef837899baa75101dcdfc88455bcafc9e53e0b06689">session_state::running</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">562</span><span class="doxyLineContent"><span class="doxyHighlight">        || <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> == <a href="#a081c4bd4495097c8c7f913ef837899baaa5d7ceb2c59b8cee46c2953fec9abc19">session_state::finished</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">563</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">564</span><span class="doxyLineContent"><span class="doxyHighlight">        fprintf (stderr,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">565</span><span class="doxyLineContent"><span class="doxyHighlight">                 </span><span class="doxyHighlightStringLiteral">"error: suite '%s' added after run() started, rejected\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">566</span><span class="doxyLineContent"><span class="doxyHighlight">                 <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>-&gt;name ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">567</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a999d64ffbd12dcacb59c34fbea4452ba">has_rejected_suites_</a> = </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">568</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> == <a href="#a081c4bd4495097c8c7f913ef837899baaa5d7ceb2c59b8cee46c2953fec9abc19">session_state::finished</a> &amp;&amp; <a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">exit_code_</a> == 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">569</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">570</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">exit_code_</a> = 1;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">571</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">572</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">573</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">574</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">575</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a>.push_back (std::move (<a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">576</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a>.back ()-&gt;link ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">577</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a>, <a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">exit_code_</a>, <a href="#a081c4bd4495097c8c7f913ef837899baaa5d7ceb2c59b8cee46c2953fec9abc19">finished</a>, <a href="#a999d64ffbd12dcacb59c34fbea4452ba">has_rejected_suites_</a>, <a href="#a081c4bd4495097c8c7f913ef837899baa75101dcdfc88455bcafc9e53e0b06689">running</a>, <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> and <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>.</p>


<p>Referenced by <a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite</a>.</p>

</div>
</div>

### run\_suites() {#a7c4dbf695c086ca4d3f0ce33e6d561f7}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::runner::run_suites (void)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Runs all registered test suites.</p>


<p>Runs the suites registered with <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span> and the static suites that refer to this runner in a single order, sorted by name; for equal names, in the order of their insertion into the list, so the static suites constructed before <span class="doxyComputerOutput">main()</span> run first. The suites not selected by the first filter pattern are reported as skipped.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Runs the suites registered with <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span> and the static suites that refer to this runner in a single order, sorted by name.</p>


<p>Both kinds of suites are in the list of suites, which <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a532459c0a6362991282548f4f845cb97">suite::link()</a></span> keeps sorted by name, so no sorting is needed here; the suites of other runners are skipped. The names are compared with <span class="doxyComputerOutput">std::strcmp()</span>, so in byte order, case-sensitively, and without comparing the numbers by value; the suites with the same name run in the order of their insertion into the list.</p>


<p>Each suite is assigned a 1-based index, following the top suite, in the order of execution. If the first filter pattern selects it, it is executed via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a432deda5a8721472e8775cbc98451722">suite::run()</a></span>, and its totals are accumulated into the runner totals; otherwise, it is reported as skipped and counted in <span class="doxyComputerOutput"><a href="#ae815c0c97245032223f4c1523e1d35fe">skipped_suites_count_</a></span>, keeping its index, so that the TAP plan remains complete; while the test cases are listed, the skipped suites are not reported. The executed test cases counter is not incremented; suites are not counted as test cases.</p>


<p>The next suite is read after the current one has run, since the suites of the local runners created by the current suite are inserted into the list, and removed again, while it runs.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00743">743</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00605">605</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a7c4dbf695c086ca4d3f0ce33e6d561f7">605</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a7c4dbf695c086ca4d3f0ce33e6d561f7">runner::run_suites</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">606</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">607</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// The top suite has index 1</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">608</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> own_index = 1;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">609</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>* suite_ptr = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a612f5529e08321a2e44c714d60c2ba1e">suite::first_</a>; suite_ptr != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">610</span><span class="doxyLineContent"><span class="doxyHighlight">         suite_ptr = suite_ptr-&gt;next_)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">611</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">612</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// Skip the suites run by other runners.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">613</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (&amp;suite_ptr-&gt;test_runner () != </span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">614</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">615</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">continue</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">616</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">617</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">618</span><span class="doxyLineContent"><span class="doxyHighlight">        suite_ptr-&gt;own_index_ = ++own_index;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">619</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">620</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (!<a href="#a2b0adeef059676a455d9506ba8a06d26">is_selected</a> (suite_ptr-&gt;name (), 0))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">621</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">622</span><span class="doxyLineContent"><span class="doxyHighlight">            ++<a href="#ae815c0c97245032223f4c1523e1d35fe">skipped_suites_count_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">623</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (!<a href="#a2cbcc12d72c192f6053cd342af1b5a77">list_tests_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">624</span><span class="doxyLineContent"><span class="doxyHighlight">              {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">625</span><span class="doxyLineContent"><span class="doxyHighlight">                <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>-&gt;skip_suite (*suite_ptr);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">626</span><span class="doxyLineContent"><span class="doxyHighlight">              }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">627</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">continue</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">628</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">629</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">630</span><span class="doxyLineContent"><span class="doxyHighlight">        suite_ptr-&gt;run ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">631</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">632</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// Accumulate the totals from the child suite into the runner</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">633</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// totals.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">634</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// DO NOT increment executed_test_cases here.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">635</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a04b52f3243abe3a9b08b44efd03e4b57">totals_</a> += suite_ptr-&gt;totals ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">636</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">637</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a612f5529e08321a2e44c714d60c2ba1e">micro_os_plus::micro_test_plus::suite::first_</a>, <a href="#a2b0adeef059676a455d9506ba8a06d26">is_selected</a>, <a href="#a2cbcc12d72c192f6053cd342af1b5a77">list_tests_</a>, <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>, <a href="#ae815c0c97245032223f4c1523e1d35fe">skipped_suites_count_</a>, <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a> and <a href="#a04b52f3243abe3a9b08b44efd03e4b57">totals_</a>.</p>


<p>Referenced by <a href="#a97f725cb167a2b464fac0eb88a0c8a46">run</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Private Member Attributes

### abort\_handler\_ {#a1138505536cf6afe69dea5ae044eeb5a}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">abort_handler_t micro_os_plus::micro_test_plus::runner::abort_handler_ = nullptr</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The function called by <span class="doxyComputerOutput"><a href="#a7bc806540e65c21095ef1ea1ef970db2">abort()</a></span>, if not null.</p>


<p>Set by <span class="doxyComputerOutput"><a href="#a711756a8c6958c4036527a290c481f86">set_abort_handler()</a></span>.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00989">989</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a1138505536cf6afe69dea5ae044eeb5a">989</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#ab5b0711c5f1ab3063c410c1b9a76707b">abort_handler_t</a> <a href="#a1138505536cf6afe69dea5ae044eeb5a">abort_handler_</a> = </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">;</span></span></div>

</div>


<p>Referenced by <a href="#af0682165f5d07b13fd21e3f6f8da546c">abort</a> and <a href="#a711756a8c6958c4036527a290c481f86">set_abort_handler</a>.</p>

</div>
</div>

### aborted\_ {#ad107cec6e32daac2da4cd665c7444e51}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::runner::aborted_ = false</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Whether the test execution was aborted.</p>


<p>Set by <span class="doxyComputerOutput"><a href="#a7bc806540e65c21095ef1ea1ef970db2">abort()</a></span>, before the abort is reported, and never cleared. Read by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base">detail::runnable_base</a></span>, a friend, so that, when the abort handler throws an exception, the test cases and the suites pass it on instead of reporting it, and no test case runs afterwards; read by <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span> and <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span>, which then refuse to start, and by <span class="doxyComputerOutput"><a href="#a7bc806540e65c21095ef1ea1ef970db2">abort()</a></span>, so that a later abort is not reported again.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01002">1002</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ad107cec6e32daac2da4cd665c7444e51">1002</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="#ad107cec6e32daac2da4cd665c7444e51">aborted_</a> = </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>

</div>


<p>Referenced by <a href="#af0682165f5d07b13fd21e3f6f8da546c">abort</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a38cf903fb0ba5b76b1eb2350b6385962">micro_os_plus::micro_test_plus::detail::runnable_base::after_test_case_create</a>, <a href="#ac40f554936c71d7c748c1241ffd3f2ac">initialise</a> and <a href="#a97f725cb167a2b464fac0eb88a0c8a46">run</a>.</p>

</div>
</div>

### children\_suites\_ {#abacf53ab658e289ae89051531c0cddad}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::vector&lt;std::unique_ptr&lt;class suite&gt; &gt; micro_os_plus::micro_test_plus::runner::children_suites_</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Owning collection of dynamically registered child suites.</p>


<p>Each call to <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span> appends a new <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a></span> to this vector, and inserts it into the list of suites, sorted by name; the suites are run later, by <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span>, in the order of the list. The vector retains ownership of all suites for the lifetime of the runner.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00857">857</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#abacf53ab658e289ae89051531c0cddad">857</a></span><span class="doxyLineContent"><span class="doxyHighlight">    std::vector&lt;std::unique_ptr&lt;class suite&gt;&gt; <a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#a9484b22aa909151712144cd39130187a">added_suites_count</a>, <a href="#a1dcc8f8d7f80044c67c492a1aebe3043">register_suite</a> and <a href="#a67d3cf710cccd419c127e63c2c30e9fe">static_suites_count</a>.</p>

</div>
</div>

### exit\_code\_ {#a1aa6f3fec517a49f9cdc70ec79b9d1e5}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">int micro_os_plus::micro_test_plus::runner::exit_code_ = 1</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The exit code computed by <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span>.</p>


<p>Returned again by the calls of <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span> made after the session ended.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00962">962</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">962</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> <a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">exit_code_</a> = 1;</span></span></div>

</div>


<p>Referenced by <a href="#a1dcc8f8d7f80044c67c492a1aebe3043">register_suite</a> and <a href="#a97f725cb167a2b464fac0eb88a0c8a46">run</a>.</p>

</div>
</div>

### filter\_patterns\_ {#a12b7d597d11b0ff284cdb84a7c4ea927}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::vector&lt;std::string&gt; micro_os_plus::micro_test_plus::runner::filter_patterns_</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The patterns that select the suites and the test cases to run, one per nesting level.</p>


<p>Copied by <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span> from <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#a8dc9c5a5b6c89c12acd27d67d57618dd">runner_options::filter_patterns</a></span>, including the characters, so the caller's strings need not outlive the call, and read by <span class="doxyComputerOutput"><a href="#a2b0adeef059676a455d9506ba8a06d26">is_selected()</a></span>. Empty when everything must run.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00919">919</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a12b7d597d11b0ff284cdb84a7c4ea927">919</a></span><span class="doxyLineContent"><span class="doxyHighlight">    std::vector&lt;std::string&gt; <a href="#a12b7d597d11b0ff284cdb84a7c4ea927">filter_patterns_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#ac40f554936c71d7c748c1241ffd3f2ac">initialise</a> and <a href="#a2b0adeef059676a455d9506ba8a06d26">is_selected</a>.</p>

</div>
</div>

### has\_option\_errors\_ {#a8e9e6782d6cde59ac82fb6fb459888cb}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::runner::has_option_errors_ = false</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Whether <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span> reported an option error.</p>


<p>Set for a missing option argument, an unknown reporter name, an unknown colour mode, or an output file that cannot be opened; <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span> then returns 2.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00972">972</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a8e9e6782d6cde59ac82fb6fb459888cb">972</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="#a8e9e6782d6cde59ac82fb6fb459888cb">has_option_errors_</a> = </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>

</div>


<p>Referenced by <a href="#ac40f554936c71d7c748c1241ffd3f2ac">initialise</a>, <a href="#a2319eb34fc8b601ca5e6a8ec538ba138">parse_options</a> and <a href="#a97f725cb167a2b464fac0eb88a0c8a46">run</a>.</p>

</div>
</div>

### has\_rejected\_suites\_ {#a999d64ffbd12dcacb59c34fbea4452ba}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::runner::has_rejected_suites_ = false</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Whether a suite was added after <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span> had started.</p>


<p>Set by <span class="doxyComputerOutput"><a href="#a1dcc8f8d7f80044c67c492a1aebe3043">register_suite()</a></span>, which rejects such a suite; <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span> then returns 1, unless an option error requires 2.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00981">981</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a999d64ffbd12dcacb59c34fbea4452ba">981</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="#a999d64ffbd12dcacb59c34fbea4452ba">has_rejected_suites_</a> = </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>

</div>


<p>Referenced by <a href="#a1dcc8f8d7f80044c67c492a1aebe3043">register_suite</a> and <a href="#a97f725cb167a2b464fac0eb88a0c8a46">run</a>.</p>

</div>
</div>

### list\_tests\_ {#a2cbcc12d72c192f6053cd342af1b5a77}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::runner::list_tests_ = false</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Whether the test cases are listed instead of run.</p>


<p>Copied by <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span> from <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#ac4f95336439b329d0f3731a5dcafb6f9">runner_options::list_tests</a></span>. When set, the suite bodies run, to create their test cases, but the test case bodies do not; the selected test cases are listed by <span class="doxyComputerOutput"><a href="#a0e478c394741ff78f65a7e2c0822ba50">list_test_case()</a></span>, and <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span> writes their number.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01024">1024</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a2cbcc12d72c192f6053cd342af1b5a77">1024</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="#a2cbcc12d72c192f6053cd342af1b5a77">list_tests_</a> = </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a38cf903fb0ba5b76b1eb2350b6385962">micro_os_plus::micro_test_plus::detail::runnable_base::after_test_case_create</a>, <a href="#ac40f554936c71d7c748c1241ffd3f2ac">initialise</a>, <a href="#ae5df469f7aaccc8e24bfadff4c209688">is_listing</a>, <a href="#a97f725cb167a2b464fac0eb88a0c8a46">run</a> and <a href="#a7c4dbf695c086ca4d3f0ce33e6d561f7">run_suites</a>.</p>

</div>
</div>

### listed\_suite\_ {#af8ce5a496dba305f6fbd45005d580321}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const class suite* micro_os_plus::micro_test_plus::runner::listed_suite_ = nullptr</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The suite whose name was listed last, if any.</p>


<p>Used by <span class="doxyComputerOutput"><a href="#a0e478c394741ff78f65a7e2c0822ba50">list_test_case()</a></span> to write the name of a suite only once, before its first listed test case.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01033">1033</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#af8ce5a496dba305f6fbd45005d580321">1033</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>* <a href="#af8ce5a496dba305f6fbd45005d580321">listed_suite_</a> = </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">;</span></span></div>

</div>


<p>Referenced by <a href="#a0e478c394741ff78f65a7e2c0822ba50">list_test_case</a>.</p>

</div>
</div>

### listed\_suites\_count\_ {#acb06cb7ebf949b8af5c5d57645c56e4a}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">size_t micro_os_plus::micro_test_plus::runner::listed_suites_count_ = 0</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The number of suites with listed test cases.</p>


<p>Incremented by <span class="doxyComputerOutput"><a href="#a0e478c394741ff78f65a7e2c0822ba50">list_test_case()</a></span> when it writes the name of a suite; written by <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span> at the end of the list.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01051">1051</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#acb06cb7ebf949b8af5c5d57645c56e4a">1051</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="#acb06cb7ebf949b8af5c5d57645c56e4a">listed_suites_count_</a> = 0;</span></span></div>

</div>


<p>Referenced by <a href="#a0e478c394741ff78f65a7e2c0822ba50">list_test_case</a> and <a href="#a97f725cb167a2b464fac0eb88a0c8a46">run</a>.</p>

</div>
</div>

### listed\_test\_cases\_count\_ {#a90900e7d0a4571407b3727e031e46685}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">size_t micro_os_plus::micro_test_plus::runner::listed_test_cases_count_ = 0</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The number of listed test cases.</p>


<p>Incremented by <span class="doxyComputerOutput"><a href="#a0e478c394741ff78f65a7e2c0822ba50">list_test_case()</a></span>; written by <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span> at the end of the list.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01042">1042</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a90900e7d0a4571407b3727e031e46685">1042</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="#a90900e7d0a4571407b3727e031e46685">listed_test_cases_count_</a> = 0;</span></span></div>

</div>


<p>Referenced by <a href="#a0e478c394741ff78f65a7e2c0822ba50">list_test_case</a> and <a href="#a97f725cb167a2b464fac0eb88a0c8a46">run</a>.</p>

</div>
</div>

### reporter\_ {#a67205181c73d11d12964bb324f1dc902}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::unique_ptr&lt;detail::reporter&gt; micro_os_plus::micro_test_plus::runner::reporter_</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Owning pointer to the test reporter used for outputting test results.</p>


<p>Created by <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span>, as selected by the session options, either given by the caller or parsed from the command line by <span class="doxyComputerOutput"><a href="#a2319eb34fc8b601ca5e6a8ec538ba138">parse_options()</a></span>. Used by the suites and the test cases, through <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base">detail::runnable_base</a></span>, which is a friend.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00869">869</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a67205181c73d11d12964bb324f1dc902">869</a></span><span class="doxyLineContent"><span class="doxyHighlight">    std::unique_ptr&lt;detail::reporter&gt; <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#af0682165f5d07b13fd21e3f6f8da546c">abort</a>, <a href="#ac40f554936c71d7c748c1241ffd3f2ac">initialise</a>, <a href="#a0e478c394741ff78f65a7e2c0822ba50">list_test_case</a>, <a href="#a65250ff363fbb3b5869bbe4de9578e86">reporter</a>, <a href="#a97f725cb167a2b464fac0eb88a0c8a46">run</a> and <a href="#a7c4dbf695c086ca4d3f0ce33e6d561f7">run_suites</a>.</p>

</div>
</div>

### running\_test\_case\_ {#acf5727abb4e4b23e1a2d7d3320f5dec9}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_case* micro_os_plus::micro_test_plus::runner::running_test_case_ = nullptr</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The innermost test case being run, if any.</p>


<p>Set by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base">detail::runnable_base</a></span>, a friend, while a test case runs, and restored when it ends, so that <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a402696dc4d4978ff3c050427890cfe01">suite::test()</a></span>, when called from the body of a test case (for example via a captured suite reference), runs the new test case nested in it.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01013">1013</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#acf5727abb4e4b23e1a2d7d3320f5dec9">1013</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>* <a href="#acf5727abb4e4b23e1a2d7d3320f5dec9">running_test_case_</a> = </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">;</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a38cf903fb0ba5b76b1eb2350b6385962">micro_os_plus::micro_test_plus::detail::runnable_base::after_test_case_create</a>.</p>

</div>
</div>

### session\_state\_ {#a70dad6c927a59d5459c2edfdb40fdece}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">session_state micro_os_plus::micro_test_plus::runner::session_state_ = <a href="#a081c4bd4495097c8c7f913ef837899baae2fa538867c3830a859a5b17ab24644b">session_state::created</a></td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The current state of the test session.</p>


<p>Set by <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span> and <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span>; read by <span class="doxyComputerOutput"><a href="#a1dcc8f8d7f80044c67c492a1aebe3043">register_suite()</a></span>, to reject the suites added too late.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00953">953</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a70dad6c927a59d5459c2edfdb40fdece">953</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a081c4bd4495097c8c7f913ef837899ba">session_state</a> <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> = <a href="#a081c4bd4495097c8c7f913ef837899baae2fa538867c3830a859a5b17ab24644b">session_state::created</a>;</span></span></div>

</div>


<p>Referenced by <a href="#af0682165f5d07b13fd21e3f6f8da546c">abort</a>, <a href="#ac40f554936c71d7c748c1241ffd3f2ac">initialise</a>, <a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise</a>, <a href="#a1dcc8f8d7f80044c67c492a1aebe3043">register_suite</a> and <a href="#a97f725cb167a2b464fac0eb88a0c8a46">run</a>.</p>

</div>
</div>

### skipped\_suites\_count\_ {#ae815c0c97245032223f4c1523e1d35fe}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">size_t micro_os_plus::micro_test_plus::runner::skipped_suites_count_ = 0</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The number of suites skipped by the filter.</p>


<p>Incremented by <span class="doxyComputerOutput"><a href="#a7c4dbf695c086ca4d3f0ce33e6d561f7">run_suites()</a></span>; returned by <span class="doxyComputerOutput"><a href="#a2c2a6d7cb45b714026d124d0ca432360">skipped_suites_count()</a></span>.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00928">928</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ae815c0c97245032223f4c1523e1d35fe">928</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="#ae815c0c97245032223f4c1523e1d35fe">skipped_suites_count_</a> = 0;</span></span></div>

</div>


<p>Referenced by <a href="#a7c4dbf695c086ca4d3f0ce33e6d561f7">run_suites</a> and <a href="#a2c2a6d7cb45b714026d124d0ca432360">skipped_suites_count</a>.</p>

</div>
</div>

### stopwatch\_ {#a13b3cf196a1b12cb90a12c4b84223d15}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">detail::stopwatch micro_os_plus::micro_test_plus::runner::stopwatch_</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Stopwatch of this runner.</p>


<p>Measures the duration of the entire test session; started by <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span>, stopped by <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span>, and read by the reporters, which are friends.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00879">879</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a13b3cf196a1b12cb90a12c4b84223d15">879</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch">detail::stopwatch</a> <a href="#a13b3cf196a1b12cb90a12c4b84223d15">stopwatch_</a>;</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ace9c2dfffc49a97516b96dacaf87b943">micro_os_plus::micro_test_plus::detail::reporter_human::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a7033819609bfad2db2ecc7a024e91b2c">micro_os_plus::micro_test_plus::detail::reporter_tap::end_session</a>, <a href="#ac40f554936c71d7c748c1241ffd3f2ac">initialise</a>, <a href="#a97f725cb167a2b464fac0eb88a0c8a46">run</a>, <a href="#af314280f14d61d37da276567685ec2a8">timings</a> and <a href="#a7d3ccfaf760cb2f4ace586c222b22244">timings</a>.</p>

</div>
</div>

### top\_suite\_ {#a93a3afb222db1fcaa87cd1ba7fa15bc0}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">class top_suite micro_os_plus::micro_test_plus::runner::top_suite_</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The implicit top-level suite; always present and executed first.</p>


<p>Its test cases are added directly, between <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span> and <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span>.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00846">846</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">846</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite">top_suite</a> <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#a10788baa079e19676a8cdbaa253285dc">runner</a>, <a href="#a5e2001730fd3659e9045fcc5cc668f07">runner</a>, <a href="#ac40f554936c71d7c748c1241ffd3f2ac">initialise</a> and <a href="#a97f725cb167a2b464fac0eb88a0c8a46">run</a>.</p>

</div>
</div>

### top\_suite\_name\_ {#a401e4e098f0ceba7f21a3a5bf1ea89e3}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::string micro_os_plus::micro_test_plus::runner::top_suite_name_</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Owned storage for the implicit top-suite name.</p>


<p>Set by <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span>, either from its argument or derived from <span class="doxyComputerOutput">argv[0]</span>, as kept in the session options.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00897">897</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a401e4e098f0ceba7f21a3a5bf1ea89e3">897</a></span><span class="doxyLineContent"><span class="doxyHighlight">    std::string <a href="#a401e4e098f0ceba7f21a3a5bf1ea89e3">top_suite_name_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#ac40f554936c71d7c748c1241ffd3f2ac">initialise</a>.</p>

</div>
</div>

### totals\_ {#a04b52f3243abe3a9b08b44efd03e4b57}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">counters micro_os_plus::micro_test_plus::runner::totals_</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Totals of the test session.</p>


<p>The totals of each suite are added by <span class="doxyComputerOutput"><a href="#a97f725cb167a2b464fac0eb88a0c8a46">run()</a></span> and <span class="doxyComputerOutput"><a href="#a7c4dbf695c086ca4d3f0ce33e6d561f7">run_suites()</a></span>, after the suite was run.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00888">888</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a04b52f3243abe3a9b08b44efd03e4b57">888</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters">counters</a> <a href="#a04b52f3243abe3a9b08b44efd03e4b57">totals_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#a97f725cb167a2b464fac0eb88a0c8a46">run</a>, <a href="#a7c4dbf695c086ca4d3f0ce33e6d561f7">run_suites</a> and <a href="#a2c8a999cc273356ea10ed34fb12dcf5a">totals</a>.</p>

</div>
</div>

### verbosity\_ {#a1d4b6b07a507c00a5ac262e098b12ad3}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_test_plus::verbosity micro_os_plus::micro_test_plus::runner::verbosity_ = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">verbosity::normal</a></td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The verbosity level of the console output.</p>


<p>Copied by <span class="doxyComputerOutput"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise()</a></span> from <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options/#aff30f0303a958a549a2f4b6e67db00d5">runner_options::verbosity_level</a></span>, before the reporter is created, which keeps its own constant copy; returned by <span class="doxyComputerOutput"><a href="#a1dd0221dca8e7382f0b625ff6316ed92">verbosity_level()</a></span>. <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">verbosity::normal</a></span> until then.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00907">907</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a1d4b6b07a507c00a5ac262e098b12ad3">907</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914b">micro_test_plus::verbosity</a> <a href="#a1d4b6b07a507c00a5ac262e098b12ad3">verbosity_</a> = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">verbosity::normal</a>;</span></span></div>

</div>


<p>Referenced by <a href="#ac40f554936c71d7c748c1241ffd3f2ac">initialise</a>, <a href="#a0e478c394741ff78f65a7e2c0822ba50">list_test_case</a>, <a href="#a97f725cb167a2b464fac0eb88a0c8a46">run</a> and <a href="#a1dd0221dca8e7382f0b625ff6316ed92">verbosity_level</a>.</p>

</div>
</div>

</div>

<hr/>

The documentation for this class was generated from the following files:

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h">runner-inlines.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
