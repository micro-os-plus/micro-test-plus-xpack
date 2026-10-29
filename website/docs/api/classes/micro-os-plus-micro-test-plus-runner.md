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

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#af153e90c6ef7fad5fe7f059fced9f423">static_suite</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The static suites link themselves through the runner. <a href="#af153e90c6ef7fad5fe7f059fced9f423">More...</a></p>
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
<p>Adds a test suite to the runner, to be run by <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>. <a href="#a4069fe957bbc7a9217ca2dd4d2034a97">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite</a> (std::string_view top_suite_name={})</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Adds the top suite and returns it. <a href="#aac24d1193ac0579dd6ac3c523a32015f">More...</a></p>
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
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aba1f6140138ba802f91f8f025258b63d">initialise</a> (int argc, char *argv[])</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Initialises the test runner with the command-line arguments. <a href="#aba1f6140138ba802f91f8f025258b63d">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ae87c4a8f0e08e069b6d1a393f88e040e">initialise</a> (runner_options options)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Initialises the test runner with the given options. <a href="#ae87c4a8f0e08e069b6d1a393f88e040e">More...</a></p>
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
<td class="doxyMemberIndexItemType" align="left" valign="top">int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Runs the registered suites, ends the session, and returns the exit code. <a href="#a700e3ef1f955492cd84235bd388dcdf2">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a11cfc0285b39ae765ccf3082c1eadebe">has_option_errors</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Checks whether an option error was found by <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise()</a></span>. <a href="#a11cfc0285b39ae765ccf3082c1eadebe">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a964febc11fcd08a4437e11d16544ca7b">reject_suite</a> (const char *name)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Reject a suite constructed after <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> has started. <a href="#a964febc11fcd08a4437e11d16544ca7b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a061939d61f7f2d4a4523c427b0dc98f2">run_child_suites</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Runs all registered test suites. <a href="#a061939d61f7f2d4a4523c427b0dc98f2">More...</a></p>
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
<p>The exit code computed by <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>. <a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">More...</a></p>
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
<p>Whether a suite was added after <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> had started. <a href="#a999d64ffbd12dcacb59c34fbea4452ba">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a4a43729c815ce9b3e3f15a650f011f66">has_top_suite_</a> = false</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Whether the top suite was added to the session. <a href="#a4a43729c815ce9b3e3f15a650f011f66">More...</a></p>
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
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options">runner_options</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The options of the test session. <a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">More...</a></p>
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
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a5e2001730fd3659e9045fcc5cc668f07">runner</a> *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a291ce3303f40804df4fd99f0f7d40d6c">started_next_</a> = nullptr</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The next runner in the list of the started runners. <a href="#a291ce3303f40804df4fd99f0f7d40d6c">More...</a></p>
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
<p>The top suite, whose body is the code of <span class="doxyComputerOutput">main()</span>. <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">More...</a></p>
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
<p>Owned storage for the top suite name. <a href="#a401e4e098f0ceba7f21a3a5bf1ea89e3">More...</a></p>
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

</table>

## Private Static Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">static void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a19160679a4fe484fc9f8f76ed3408762">link_static_suite</a> (runner &amp;test_runner, class suite &amp;suite) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Insert a static suite into the list of suites, or reject it. <a href="#a19160679a4fe484fc9f8f76ed3408762">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Private Static Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">static <a href="#a5e2001730fd3659e9045fcc5cc668f07">runner</a> *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a5fd4803c937d65c578a4ae30d407c40e">started_first_</a> = nullptr</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The head of the list of the runners that have started. <a href="#a5fd4803c937d65c578a4ae30d407c40e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Deprecated Functions Index

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
<td class="doxyMemberIndexItemType" align="left" valign="top">class <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise</a> (int argc, char *argv[], const char *top_suite_name)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deprecated initialisation with the command-line arguments, which also adds the top suite. <a href="#a39ee9ec53f8df687cd84092de5118592">More...</a></p>
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
<p>Deprecated name of <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>. <a href="#a7f8403f1ccc6a0e8171ef077bcd9cbd4">More...</a></p>
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
<td class="doxyMemberIndexItemType" align="left" valign="top">const char *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a5f1698a93a8b09c39b87c23452335646">name</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deprecated name of the runner. <a href="#a5f1698a93a8b09c39b87c23452335646">More...</a></p>
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

</table>

## Description {#details}

<p>The test runner for the µTest++ framework.</p>


<p>The <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">runner</a></span> class is responsible for managing the registration and execution of test suites within the µTest++ framework. It owns the optional top suite, returned by <span class="doxyComputerOutput"><a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite()</a></span>, whose test cases run immediately, in <span class="doxyComputerOutput">main()</span>, and a collection of test suites added with <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span>, which are run later, by <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>. These suites and the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite">static_suite</a></span> objects that refer to the runner are kept in a single list, sorted by name, independent of the runner object, so the static suites may be constructed before it. <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> runs the suites added with <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span> and the static suites together, in a single order, sorted by name; for equal names, in the order of their creation, so the static suites constructed before <span class="doxyComputerOutput">main()</span> run first. The names are compared byte by byte, as by <span class="doxyComputerOutput">std::strcmp()</span>, not in the order of addition: the comparison is case-sensitive (<span class="doxyComputerOutput">"Zeta"</span> before <span class="doxyComputerOutput">"alpha"</span>) and does not compare numbers by value (<span class="doxyComputerOutput">"Suite 10"</span> before <span class="doxyComputerOutput">"Suite 2"</span>); zero-padded numeric prefixes (<span class="doxyComputerOutput">"01 - Init"</span>) give an explicit order.</p>


<p>Several runners may coexist, global or local, each with its own static suites and suites added with <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span>. The list of suites is shared by all the runners; each suite refers to its runner, and <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> runs only the suites that refer to this runner, skipping those of the other runners, so the runners do not interfere. The list is not protected by a lock: the runners must not run, and the suites must not be created or destroyed, concurrently from different threads.</p>


<p>The test runner provides member functions for initialising the test environment (including the creation of the reporter selected by the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options">runner_options</a></span> passed to <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise()</a></span>), registering test suites, and determining the overall test result via an exit code. It also offers an abort mechanism for terminating test execution in exceptional circumstances.</p>


<p>Both <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise()</a></span> and <span class="doxyComputerOutput"><a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite()</a></span> are optional:</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">mt::runner tr;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeywordType">int</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">main (</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> argc, </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* argv[])</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  tr.initialise (argc, argv);</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; ts = tr.add_top_suite (</span><span class="doxyHighlightStringLiteral">"Main"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  ts.test (</span><span class="doxyHighlightStringLiteral">"Check something"</span><span class="doxyHighlight">, [] (</span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; t) { t.expect (</span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">); });</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> tr.run_suites ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">}</span></span></div>

</div>


<p>Without <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise()</a></span>, the default options are used; without <span class="doxyComputerOutput"><a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite()</a></span>, there is no top suite, and <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> runs only the suites added with <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span> and the static suites.</p>


<p>The runner is not a node of the test tree: it has no name of its own (the names shown in the reports belong to the suites), and it owns the session totals, which accumulate the totals of all the suites.</p>


<p>All members are defined within the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a></span> namespace, ensuring clear separation from user code and minimising the risk of naming conflicts.</p>


<p>Definition at line 194 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


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


<p>When exceptions are enabled, it may also throw an exception, to return control to the application without terminating the process. The test cases and the suites do not catch it, so it leaves the <span class="doxyComputerOutput">test()</span> call that started a test case of the top suite, or <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>, and reaches the application; their remaining code is not run. The report is complete, but the runner cannot be used afterwards (see <span class="doxyComputerOutput"><a href="#a7bc806540e65c21095ef1ea1ef970db2">abort()</a></span>).</p>


<dl class="doxySectionUser">
<dt>Since</dt>
<dd><p>6.0.0</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00612">612</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ab5b0711c5f1ab3063c410c1b9a76707b">612</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="#ab5b0711c5f1ab3063c410c1b9a76707b">abort_handler_t</a> = void (*) (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; sl);</span></span></div>

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


<p>The session moves only forwards, from <span class="doxyComputerOutput">created</span> to <span class="doxyComputerOutput">initialised</span> (by <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise()</a></span>), to <span class="doxyComputerOutput">running</span>, and to <span class="doxyComputerOutput">finished</span> (both by <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>); the calls made in another state are reported or ignored.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01202">1202</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">1203</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a081c4bd4495097c8c7f913ef837899baae2fa538867c3830a859a5b17ab24644b">1204</a></span><span class="doxyLineContent"><span class="doxyHighlight">      created, </span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a081c4bd4495097c8c7f913ef837899baadb1687e1890c33928fe61b7cb4ac2f0e">1205</a></span><span class="doxyLineContent"><span class="doxyHighlight">      initialised, </span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a081c4bd4495097c8c7f913ef837899baa75101dcdfc88455bcafc9e53e0b06689">1206</a></span><span class="doxyLineContent"><span class="doxyHighlight">      running, </span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a081c4bd4495097c8c7f913ef837899baaa5d7ceb2c59b8cee46c2953fec9abc19">1207</a></span><span class="doxyLineContent"><span class="doxyHighlight">      finished </span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1208</span><span class="doxyLineContent"><span class="doxyHighlight">    };</span></span></div>

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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00202">202</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a099a369b6d1f67c296baf9d22be40ba2">202</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human">detail::reporter_human</a>;</span></span></div>

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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00210">210</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a6cd3b3f893312fe43fa2d7b5018646e9">210</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap">detail::reporter_tap</a>;</span></span></div>

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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00221">221</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a484008ed66130a2bf334948841099943">221</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base">detail::runnable_base</a>;</span></span></div>

</div>

</div>
</div>

### static\_suite {#af153e90c6ef7fad5fe7f059fced9f423}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">friend class static_suite</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The static suites link themselves through the runner.</p>


<p>The <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite">static_suite</a></span> constructors call <span class="doxyComputerOutput"><a href="#a19160679a4fe484fc9f8f76ed3408762">link_static_suite()</a></span>, which rejects the suites constructed after <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> has started.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00230">230</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#af153e90c6ef7fad5fe7f059fced9f423">230</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="#af153e90c6ef7fad5fe7f059fced9f423">static_suite</a>;</span></span></div>

</div>


<p>Reference <a href="#af153e90c6ef7fad5fe7f059fced9f423">static_suite</a>.</p>


<p>Referenced by <a href="#af153e90c6ef7fad5fe7f059fced9f423">static_suite</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Constructors

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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00275">275</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00284">284</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


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


<p>The session is configured later, by <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise()</a></span>, and the top suite, if any, is added by <span class="doxyComputerOutput"><a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite()</a></span>.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<p>The constructor initialises a new <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">runner</a></span> instance together with its top suite (<span class="doxyComputerOutput"><a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a></span>). If tracing is enabled, it outputs the function signature for diagnostic purposes.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00243">243</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00081">81</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a5e2001730fd3659e9045fcc5cc668f07">81</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a5e2001730fd3659e9045fcc5cc668f07">runner::runner</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) : <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>{ </span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight">, *this }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">82</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">83</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">84</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s '%s'\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__, <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">85</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">86</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">micro_os_plus::micro_test_plus::detail::runnable_base::name</a> and <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>.</p>


<p>Referenced by <a href="#adbe02fed3c414adf001d856ab390e000">runner</a>, <a href="#a09acf1e03953d8017e56c8b5e38b879a">runner</a>, <a href="#aea1a1eff9cac943c1cd84e48b9add92f">~runner</a>, <a href="#a19160679a4fe484fc9f8f76ed3408762">link_static_suite</a>, <a href="#a549524d15dc1eb5e6b4eb4bdd2af7b6b">operator=</a> and <a href="#aa34a0418d54c633630a089eb2b5a61ee">operator=</a>.</p>

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


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00315">315</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00110">110</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aea1a1eff9cac943c1cd84e48b9add92f">110</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#aea1a1eff9cac943c1cd84e48b9add92f">runner::~runner</a> ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">111</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">112</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">113</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">114</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">115</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">116</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (<a href="#a5e2001730fd3659e9045fcc5cc668f07">runner</a>** slot = &amp;<a href="#a5fd4803c937d65c578a4ae30d407c40e">started_first_</a>; *slot != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">117</span><span class="doxyLineContent"><span class="doxyHighlight">         slot = &amp;(*slot)-&gt;<a href="#a291ce3303f40804df4fd99f0f7d40d6c">started_next_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">118</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">119</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (*slot == </span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">120</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">121</span><span class="doxyLineContent"><span class="doxyHighlight">            *slot = <a href="#a291ce3303f40804df4fd99f0f7d40d6c">started_next_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">122</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">123</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">124</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">125</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">126</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// reporter_ is a unique_ptr; destroyed automatically.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">127</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a5e2001730fd3659e9045fcc5cc668f07">runner</a>, <a href="#a5fd4803c937d65c578a4ae30d407c40e">started_first_</a> and <a href="#a291ce3303f40804df4fd99f0f7d40d6c">started_next_</a>.</p>

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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00294">294</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00305">305</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<p>References <a href="#a5e2001730fd3659e9045fcc5cc668f07">runner</a>, <a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite</a>, <a href="#a39ee9ec53f8df687cd84092de5118592">initialise</a> and <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>.</p>

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


<p>Between <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise()</a></span> and the end of <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>, the reporter completes the report, on the console and in the output file: it writes the results of the running test case, if any, followed by a line with the source location (a <span class="doxyComputerOutput">Bail out!</span> line with the TAP reporter), in place of the totals. Before <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise()</a></span> or after <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>, when there is no report to complete, the source location is written to <span class="doxyComputerOutput">stderr</span>.</p>


<p>The handler set by <span class="doxyComputerOutput"><a href="#a711756a8c6958c4036527a290c481f86">set_abort_handler()</a></span> is then called, if any. If there is no handler, or if it returns, the process is terminated with <span class="doxyComputerOutput">::abort()</span>.</p>


<p>The abort is final, also when the handler throws an exception: no test case runs afterwards, <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise()</a></span> and <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> report an error on <span class="doxyComputerOutput">stderr</span> (<span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> returns 1), and a later abort is not reported again.</p>


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


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00660">660</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00772">772</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a7bc806540e65c21095ef1ea1ef970db2">772</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a7bc806540e65c21095ef1ea1ef970db2">runner::abort</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; sl)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">773</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">774</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a7bc806540e65c21095ef1ea1ef970db2">abort</a> (sl, </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">775</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

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

<p>Adds a test suite to the runner, to be run by <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>.</p>


<p>Unlike the test cases added to the top suite (see <span class="doxyComputerOutput"><a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite()</a></span>), which run immediately, the suite is only stored; <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> runs it later, together with the static suites that refer to this runner, sorted by name.</p>


<p>The suites must be added before <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> is called. A suite added while <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> runs (for example from the body of another suite), or after it returned, would never run; it is rejected, the error is reported on <span class="doxyComputerOutput">stderr</span>, and the exit code is not 0, so that the omission cannot pass unnoticed.</p>


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
<dd><p>6.0.0</p></dd>
</dl>


<p>Constructs a <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a></span> object on the heap, binding the callable and any additional arguments, then transfers ownership to the runner via <span class="doxyComputerOutput"><a href="#a1dcc8f8d7f80044c67c492a1aebe3043">register_suite()</a></span>. The suite is not run here; all registered suites are run later by <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>, together with the static suites, sorted by name. A suite added once <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> has started is rejected by <span class="doxyComputerOutput"><a href="#a1dcc8f8d7f80044c67c492a1aebe3043">register_suite()</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00550">550</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h/#l00175">175</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h">runner-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">175</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a4069fe957bbc7a9217ca2dd4d2034a97">runner::add_suite</a> (std::string_view <a href="#a5f1698a93a8b09c39b87c23452335646">name</a>, Callable_T&amp;&amp; callable,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">176</span><span class="doxyLineContent"><span class="doxyHighlight">                     Args_T&amp;&amp;... arguments)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">177</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">178</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">179</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s '%.*s'\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">180</span><span class="doxyLineContent"><span class="doxyHighlight">                   </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (<a href="#a5f1698a93a8b09c39b87c23452335646">name</a>.size ()), <a href="#a5f1698a93a8b09c39b87c23452335646">name</a>.data ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">181</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">182</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">183</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Not std::make_unique(), which cannot access the protected constructor.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">184</span><span class="doxyLineContent"><span class="doxyHighlight">    std::unique_ptr&lt;class suite&gt; child_suite{ </span><span class="doxyHighlightKeyword">new</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">185</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a5f1698a93a8b09c39b87c23452335646">name</a>, *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">, std::forward&lt;Callable_T&gt; (callable),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">186</span><span class="doxyLineContent"><span class="doxyHighlight">        std::forward&lt;Args_T&gt; (arguments)...) };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">187</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">188</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1dcc8f8d7f80044c67c492a1aebe3043">register_suite</a> (std::move (child_suite));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">189</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a5f1698a93a8b09c39b87c23452335646">name</a>, <a href="#a1dcc8f8d7f80044c67c492a1aebe3043">register_suite</a> and <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>.</p>


<p>Referenced by <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>.</p>

</div>
</div>

### add\_top\_suite() {#aac24d1193ac0579dd6ac3c523a32015f}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">suite &amp; micro_os_plus::micro_test_plus::runner::add_top_suite (std::string_view top_suite_name={})</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Adds the top suite and returns it.</p>


<p>The top suite is the suite whose body is the code of <span class="doxyComputerOutput">main()</span>: its test cases run immediately, when <span class="doxyComputerOutput">test()</span> is called, before the suites added with <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span> and the static suites, which run later, by <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>. It is always the first suite in the report.</p>


<p>The call is optional; without it, there is no top suite, and only the other suites are run and reported. If the runner is not yet initialised, it is initialised with the default options.</p>


<p>If no name is given, here or by the deprecated constructor, the top suite is named after the file name of <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#ae26cb575ce2e252eef06b7b124a6400a">runner_options::arguments</a>[0]</span>, without the extension, when available, or "default suite".</p>


<p>The top suite can be added only once, and before <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>; a second call, or a call made once <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> has started, is reported on <span class="doxyComputerOutput">stderr</span>, and the existing top suite is returned. With an unknown reporter name, the top suite is returned, but nothing is reported.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">top_suite_name</td>
<td class="doxyParamItemDescription"><p>The name of the top suite, used in reports; a string literal, a <span class="doxyComputerOutput">const char*</span>, a <span class="doxyComputerOutput">std::string</span>, or a <span class="doxyComputerOutput">std::string_view</span>. It is copied, so the string need not outlive the call, nor be null-terminated. Defaults to an empty string.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to the top suite.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Since</dt>
<dd><p>6.0.0</p></dd>
</dl>


<p>Initialises the runner with the default options, if not yet done, names the top suite, marks it as part of the session, starts its timing, and emits the reporter notification for its beginning; while the test cases are listed, the top suite is not reported.</p>


<p>If the name is empty, the name given to the deprecated constructor is kept; if there is none, the name is derived from the file name of <span class="doxyComputerOutput">arguments[0]</span> (usually <span class="doxyComputerOutput">argv[0]</span>), without the extension, or defaults to "default suite".</p>


<p>After the test execution was aborted, the error is reported on <span class="doxyComputerOutput">stderr</span>. With an unknown reporter, the session has already finished, and the top suite is returned without other effects. A second call, or a call once <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> has started, is reported on <span class="doxyComputerOutput">stderr</span>; the latter also sets <span class="doxyComputerOutput"><a href="#a999d64ffbd12dcacb59c34fbea4452ba">has_rejected_suites_</a></span>, so that the exit code is not 0.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00448">448</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00318">318</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aac24d1193ac0579dd6ac3c523a32015f">318</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#aac24d1193ac0579dd6ac3c523a32015f">runner::add_top_suite</a> (std::string_view top_suite_name)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">319</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">320</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">321</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">322</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">323</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">324</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#ad107cec6e32daac2da4cd665c7444e51">aborted_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">325</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">326</span><span class="doxyLineContent"><span class="doxyHighlight">        fprintf (stderr, </span><span class="doxyHighlightStringLiteral">"error: test execution aborted\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">327</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">328</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">329</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">330</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> == <a href="#a081c4bd4495097c8c7f913ef837899baae2fa538867c3830a859a5b17ab24644b">session_state::created</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">331</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">332</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a39ee9ec53f8df687cd84092de5118592">initialise</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options">runner_options</a>{});</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">333</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">334</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">335</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#acd0e6a20ac7d916592945346f29654ad">has_invalid_reporter</a> ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">336</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">337</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">338</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">339</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">340</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a4a43729c815ce9b3e3f15a650f011f66">has_top_suite_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">341</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">342</span><span class="doxyLineContent"><span class="doxyHighlight">        fprintf (stderr, </span><span class="doxyHighlightStringLiteral">"error: top suite already added\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">343</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">344</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">345</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">346</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (!top_suite_name.empty ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">347</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">348</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// If provided by this call, use it, possibly override the</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">349</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// deprecated constructor.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">350</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a401e4e098f0ceba7f21a3a5bf1ea89e3">top_suite_name_</a> = top_suite_name;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">351</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aad830bd92e4f6e4239d2bb5b75d5bf50">name_</a> = <a href="#a401e4e098f0ceba7f21a3a5bf1ea89e3">top_suite_name_</a>.c_str ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">352</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">353</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (strlen (<a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> ()) == 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">354</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">355</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// If not provided by the constructor or by this call, try to extract a</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">356</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// name from argv[0], which is commonly the executable name. If that</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">357</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// fails, use a default name.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">358</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (!<a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#ae26cb575ce2e252eef06b7b124a6400a">arguments</a>.empty ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">359</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">360</span><span class="doxyLineContent"><span class="doxyHighlight">            std::string_view top_suite_name_view{ <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-utility-functions/#ga791f22f0c85b6436c9016821907b0653">utility::extract_file_name</a> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">361</span><span class="doxyLineContent"><span class="doxyHighlight">                <a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#ae26cb575ce2e252eef06b7b124a6400a">arguments</a>[0].c_str ()) };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">362</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">363</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> dot_pos = top_suite_name_view.rfind (</span><span class="doxyHighlightCharLiteral">'.'</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">364</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (dot_pos != std::string_view::npos)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">365</span><span class="doxyLineContent"><span class="doxyHighlight">              {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">366</span><span class="doxyLineContent"><span class="doxyHighlight">                top_suite_name_view = top_suite_name_view.substr (0, dot_pos);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">367</span><span class="doxyLineContent"><span class="doxyHighlight">              }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">368</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">369</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="#a401e4e098f0ceba7f21a3a5bf1ea89e3">top_suite_name_</a> = top_suite_name_view;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">370</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">371</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">372</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">373</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="#a401e4e098f0ceba7f21a3a5bf1ea89e3">top_suite_name_</a> = </span><span class="doxyHighlightStringLiteral">"default suite"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">374</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">375</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aad830bd92e4f6e4239d2bb5b75d5bf50">name_</a> = <a href="#a401e4e098f0ceba7f21a3a5bf1ea89e3">top_suite_name_</a>.c_str ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">376</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">377</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">378</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Named first, so that the rejection names it.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">379</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> != <a href="#a081c4bd4495097c8c7f913ef837899baadb1687e1890c33928fe61b7cb4ac2f0e">session_state::initialised</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">380</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">381</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a964febc11fcd08a4437e11d16544ca7b">reject_suite</a> (<a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">382</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">383</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">384</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">385</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a4a43729c815ce9b3e3f15a650f011f66">has_top_suite_</a> = </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">386</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">387</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// When listing, the top suite is not reported; its test cases are</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">388</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// listed as they are created.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">389</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (!<a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#ac4f95336439b329d0f3731a5dcafb6f9">list_tests</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">390</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">391</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a95145ab410f5c0b6e514ac366aff8d84">stopwatch_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch/#af5ebb1e454867633db12fef45db9788d">start</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">392</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>-&gt;begin_suite (<a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">393</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">394</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">395</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">396</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#ad107cec6e32daac2da4cd665c7444e51">aborted_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#ae26cb575ce2e252eef06b7b124a6400a">micro_os_plus::micro_test_plus::runner_options::arguments</a>, <a href="#a081c4bd4495097c8c7f913ef837899baae2fa538867c3830a859a5b17ab24644b">created</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-utility-functions/#ga791f22f0c85b6436c9016821907b0653">micro_os_plus::micro_test_plus::utility::extract_file_name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#acd0e6a20ac7d916592945346f29654ad">micro_os_plus::micro_test_plus::runner_options::has_invalid_reporter</a>, <a href="#a4a43729c815ce9b3e3f15a650f011f66">has_top_suite_</a>, <a href="#a39ee9ec53f8df687cd84092de5118592">initialise</a>, <a href="#a081c4bd4495097c8c7f913ef837899baadb1687e1890c33928fe61b7cb4ac2f0e">initialised</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#ac4f95336439b329d0f3731a5dcafb6f9">micro_os_plus::micro_test_plus::runner_options::list_tests</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">micro_os_plus::micro_test_plus::detail::runnable_base::name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aad830bd92e4f6e4239d2bb5b75d5bf50">micro_os_plus::micro_test_plus::detail::runnable_base::name_</a>, <a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>, <a href="#a964febc11fcd08a4437e11d16544ca7b">reject_suite</a>, <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>, <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch/#af5ebb1e454867633db12fef45db9788d">micro_os_plus::micro_test_plus::detail::stopwatch::start</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a95145ab410f5c0b6e514ac366aff8d84">micro_os_plus::micro_test_plus::suite::stopwatch_</a>, <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a> and <a href="#a401e4e098f0ceba7f21a3a5bf1ea89e3">top_suite_name_</a>.</p>


<p>Referenced by <a href="#a39ee9ec53f8df687cd84092de5118592">initialise</a> and <a href="#aa34a0418d54c633630a089eb2b5a61ee">operator=</a>.</p>

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


<p>The count includes neither the top suite nor the static suites, which are counted by <span class="doxyComputerOutput"><a href="#a67d3cf710cccd419c127e63c2c30e9fe">static_suites_count()</a></span>; add one for the top suite, if added, or use <span class="doxyComputerOutput"><a href="#ac29e4b993bb3fe795eb8900231cbf5c4">total_suites_count()</a></span>, which counts all of them. The suites that <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span> rejects, once <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> has started, are not counted.</p>


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
<dd><p>6.0.0</p></dd>
</dl>


<p>Returns the number of suites stored by <span class="doxyComputerOutput"><a href="#a1dcc8f8d7f80044c67c492a1aebe3043">register_suite()</a></span>; the top suite and the static suites are not in <span class="doxyComputerOutput"><a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00766">766</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00841">841</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a9484b22aa909151712144cd39130187a">841</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a9484b22aa909151712144cd39130187a">runner::added_suites_count</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">842</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">843</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a>.size ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">844</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a>.</p>


<p>Referenced by <a href="#a6ed3a02ced62ed475c75678cd9e91be1">suites_count</a> and <a href="#ac29e4b993bb3fe795eb8900231cbf5c4">total_suites_count</a>.</p>

</div>
</div>

### initialise() {#aba1f6140138ba802f91f8f025258b63d}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::runner::initialise (int argc, char * argv=[])</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Initialises the test runner with the command-line arguments.</p>


<p>Parses the command-line options and initialises the runner with them; equivalent to <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options">runner_options</a>{ argc, argv })</span>.</p>


<p>The call is optional; without it, the runner is initialised with the default options by the first call of <span class="doxyComputerOutput"><a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite()</a></span> or <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>. If used, it must therefore precede them; a later call, or a call after the test execution was aborted, reports an error on <span class="doxyComputerOutput">stderr</span>, without other effects; the options are then not parsed, so their errors do not change the exit code.</p>


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
<dd><p>Nothing.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Since</dt>
<dd><p>6.0.0</p></dd>
</dl>


<p>Parses the command-line options with the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options">runner_options</a></span> constructor, and initialises the runner with them.</p>


<p>The options are not parsed if the runner is already initialised, or the test execution was aborted, since an option error would change the exit code of the session; the error is reported by the overload taking the options.</p>


<p>If tracing is enabled, the command-line arguments are also logged for diagnostic purposes.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00377">377</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00178">178</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aba1f6140138ba802f91f8f025258b63d">178</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a39ee9ec53f8df687cd84092de5118592">runner::initialise</a> (</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> argc, </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* argv[])</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">179</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">180</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">181</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">182</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">183</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if !(defined(MICRO_OS_PLUS_STARTUP_ENABLED) \</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">184</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">      &amp;&amp; defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">185</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_DEBUG_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">186</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"argv["</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">187</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> i = 0; i &lt; argc; ++i)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">188</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">189</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (i &gt; 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">190</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">191</span><span class="doxyLineContent"><span class="doxyHighlight">            trace::printf (</span><span class="doxyHighlightStringLiteral">", "</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">192</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">193</span><span class="doxyLineContent"><span class="doxyHighlight">        trace::printf (</span><span class="doxyHighlightStringLiteral">"'%s'"</span><span class="doxyHighlight">, argv[i]);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">194</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">195</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::puts (</span><span class="doxyHighlightStringLiteral">"]"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">196</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(MICRO_OS_PLUS_DEBUG_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">197</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// !defined(MICRO_OS_PLUS_STARTUP_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">198</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">199</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">200</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#ad107cec6e32daac2da4cd665c7444e51">aborted_</a> || <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> != <a href="#a081c4bd4495097c8c7f913ef837899baae2fa538867c3830a859a5b17ab24644b">session_state::created</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">201</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">202</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a39ee9ec53f8df687cd84092de5118592">initialise</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options">runner_options</a>{});</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">203</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">204</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">205</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">206</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a39ee9ec53f8df687cd84092de5118592">initialise</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options">runner_options</a>{ argc, argv });</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">207</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#ad107cec6e32daac2da4cd665c7444e51">aborted_</a>, <a href="#a081c4bd4495097c8c7f913ef837899baae2fa538867c3830a859a5b17ab24644b">created</a>, <a href="#a39ee9ec53f8df687cd84092de5118592">initialise</a> and <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a>.</p>

</div>
</div>

### initialise() {#ae87c4a8f0e08e069b6d1a393f88e040e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::runner::initialise (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options">runner_options</a> options)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Initialises the test runner with the given options.</p>


<p>Creates the reporter selected by the options and starts the session. The options may be parsed from the command line, adjusted, and passed here:</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">mt::runner_options options{ argc, argv };</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">options.selected_reporter = mt::reporter_kind::tap;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">tr.initialise (std::move (options));</span></span></div>

</div>


<p>The call is optional; without it, the runner is initialised with the default options by the first call of <span class="doxyComputerOutput"><a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite()</a></span> or <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>. If used, it must therefore precede them; a later call, or a call after the test execution was aborted, reports an error on <span class="doxyComputerOutput">stderr</span>, without other effects.</p>


<p>If the output file cannot be opened, the error is reported on <span class="doxyComputerOutput">stderr</span> and the report is written only to the console; the tests are still run, but <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> returns 2. With an unknown reporter name, nothing is reported, no test is run, and <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> returns 2.</p>


<p>The options are taken by value and moved into the runner, which keeps them for the whole session; pass a temporary, or use <span class="doxyComputerOutput">std::move()</span>, to avoid a copy.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">options</td>
<td class="doxyParamItemDescription"><p>The session options.</p></td>
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
<dd><p>6.0.0</p></dd>
</dl>


<p>Moves the options into the runner, which keeps them for the whole session, creates the reporter selected by them, starts the session timing, and emits the initial reporter notification for the session. While the test cases are listed, only the header of the list is written; the session is not reported.</p>


<p>If the output file cannot be opened, the reporter writes only to the console, and <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> will return 2.</p>


<p>If the reporter name is not recognised, nothing else is done: no output file is created, nothing is reported, the session is marked as finished, so that no test is run, and <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> returns 2.</p>


<p>The runner is initialised only once; a later call, or a call after the test execution was aborted, reports an error on <span class="doxyComputerOutput">stderr</span>, without other effects.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00415">415</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00229">229</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ae87c4a8f0e08e069b6d1a393f88e040e">229</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a39ee9ec53f8df687cd84092de5118592">runner::initialise</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options">runner_options</a> options)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">230</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">231</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">232</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">233</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">234</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">235</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#ad107cec6e32daac2da4cd665c7444e51">aborted_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">236</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">237</span><span class="doxyLineContent"><span class="doxyHighlight">        fprintf (stderr, </span><span class="doxyHighlightStringLiteral">"error: test execution aborted\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">238</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">239</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">240</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">241</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> != <a href="#a081c4bd4495097c8c7f913ef837899baae2fa538867c3830a859a5b17ab24644b">session_state::created</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">242</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">243</span><span class="doxyLineContent"><span class="doxyHighlight">        fprintf (stderr, </span><span class="doxyHighlightStringLiteral">"error: test runner already initialised\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">244</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">245</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">246</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">247</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Move the vectors, since their copy assignment uses std::copy, which</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">248</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// triggers -Waggregate-return in the standard library headers on some</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">249</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// targets.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">250</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a> = std::move (options);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">251</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">252</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// With an unknown reporter, do not proceed: no output file is created,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">253</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// nothing is reported, no test is run, and `run_suites()` returns 2 A</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">254</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// silent reporter without output file is still created, since the suites and</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">255</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// the test cases refer to it.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">256</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#acd0e6a20ac7d916592945346f29654ad">has_invalid_reporter</a> ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">257</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">258</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options">runner_options</a> silent_options{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">259</span><span class="doxyLineContent"><span class="doxyHighlight">        silent_options.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#aff30f0303a958a549a2f4b6e67db00d5">verbosity_level</a> = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">verbosity::silent</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">260</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#aff30f0303a958a549a2f4b6e67db00d5">verbosity_level</a> = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">verbosity::silent</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">261</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a> = std::make_unique&lt;detail::reporter_tap&gt; (silent_options);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">262</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">exit_code_</a> = 2;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">263</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> = <a href="#a081c4bd4495097c8c7f913ef837899baaa5d7ceb2c59b8cee46c2953fec9abc19">session_state::finished</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">264</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">265</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">266</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">267</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Initialise and configure the reporter; it keeps its own copy of the</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">268</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// verbosity, taken from the same options.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">269</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#ad22d04df014c5b0658b6e7bd239f15b0">selected_reporter</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a913c4161963e9439b20857358486e8b2a99e9bae675b12967251c175696f00a70">reporter_kind::human</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">270</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">271</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a> = std::make_unique&lt;detail::reporter_human&gt; (<a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">272</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">273</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">274</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">275</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a> = std::make_unique&lt;detail::reporter_tap&gt; (<a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">276</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">277</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">278</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">279</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">280</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// When listing, the session is not reported; only the header of the</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">281</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// list is written, and the test cases are listed as they are created.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">282</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#ac4f95336439b329d0f3731a5dcafb6f9">list_tests</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">283</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">284</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>-&gt;write_line (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">285</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#aff30f0303a958a549a2f4b6e67db00d5">verbosity_level</a> != <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">verbosity::silent</a>, </span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">286</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#a62b0a05ad2be4f3a5131aaf8bb523910">filter_patterns</a>.empty () ? </span><span class="doxyHighlightStringLiteral">"All available test cases:"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">287</span><span class="doxyLineContent"><span class="doxyHighlight">                                              : </span><span class="doxyHighlightStringLiteral">"Matching test cases:"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">288</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> = <a href="#a081c4bd4495097c8c7f913ef837899baadb1687e1890c33928fe61b7cb4ac2f0e">session_state::initialised</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">289</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">290</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">291</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">292</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a13b3cf196a1b12cb90a12c4b84223d15">stopwatch_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch/#af5ebb1e454867633db12fef45db9788d">start</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">293</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>-&gt;begin_session (*</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">294</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">295</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> = <a href="#a081c4bd4495097c8c7f913ef837899baadb1687e1890c33928fe61b7cb4ac2f0e">session_state::initialised</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">296</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#ad107cec6e32daac2da4cd665c7444e51">aborted_</a>, <a href="#a081c4bd4495097c8c7f913ef837899baae2fa538867c3830a859a5b17ab24644b">created</a>, <a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">exit_code_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#a62b0a05ad2be4f3a5131aaf8bb523910">micro_os_plus::micro_test_plus::runner_options::filter_patterns</a>, <a href="#a081c4bd4495097c8c7f913ef837899baaa5d7ceb2c59b8cee46c2953fec9abc19">finished</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#acd0e6a20ac7d916592945346f29654ad">micro_os_plus::micro_test_plus::runner_options::has_invalid_reporter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a913c4161963e9439b20857358486e8b2a99e9bae675b12967251c175696f00a70">micro_os_plus::micro_test_plus::human</a>, <a href="#a081c4bd4495097c8c7f913ef837899baadb1687e1890c33928fe61b7cb4ac2f0e">initialised</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#ac4f95336439b329d0f3731a5dcafb6f9">micro_os_plus::micro_test_plus::runner_options::list_tests</a>, <a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>, <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#ad22d04df014c5b0658b6e7bd239f15b0">micro_os_plus::micro_test_plus::runner_options::selected_reporter</a>, <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">micro_os_plus::micro_test_plus::silent</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch/#af5ebb1e454867633db12fef45db9788d">micro_os_plus::micro_test_plus::detail::stopwatch::start</a>, <a href="#a13b3cf196a1b12cb90a12c4b84223d15">stopwatch_</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#aff30f0303a958a549a2f4b6e67db00d5">micro_os_plus::micro_test_plus::runner_options::verbosity_level</a>.</p>

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


<p>Set by the <span class="doxyComputerOutput">--list-tests</span> (or <span class="doxyComputerOutput">--list</span>) command-line option, or by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#ac4f95336439b329d0f3731a5dcafb6f9">runner_options::list_tests</a></span>. While the test cases are listed, their bodies do not run, so the code in <span class="doxyComputerOutput">main()</span> or in the suite bodies that depends on their results (their totals, or the exit code of <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>) can use it to skip those parts, and the tests can use it to keep their own messages out of the list. Before <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise()</a></span> is called, it is <span class="doxyComputerOutput">false</span>.</p>


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
<dd><p>6.0.0</p></dd>
</dl>


<p>Returns <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#ac4f95336439b329d0f3731a5dcafb6f9">runner_options::list_tests</a></span> of the session options.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00721">721</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h/#l00087">87</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h">runner-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ae5df469f7aaccc8e24bfadff4c209688">87</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ae5df469f7aaccc8e24bfadff4c209688">runner::is_listing</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">88</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">89</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>.list_tests;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">90</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>.</p>

</div>
</div>

### run\_suites() {#a700e3ef1f955492cd84235bd388dcdf2}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">int micro_os_plus::micro_test_plus::runner::run_suites (void)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Runs the registered suites, ends the session, and returns the exit code.</p>


<p>Completes the top suite, if any, runs the suites registered with <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span> and the static suites that refer to this runner, together, sorted by name, and ends the session. If the runner is not yet initialised, it is initialised with the default options. When filter patterns are given, the suites whose names do not match the first pattern are reported as skipped, without being run.</p>


<p>While the test cases are listed (see <span class="doxyComputerOutput"><a href="#ae5df469f7aaccc8e24bfadff4c209688">is_listing()</a></span>), the suites run only to create their test cases, which are listed, and the number of listed test cases is written; the result of the checks does not affect the exit code, since no check is evaluated.</p>


<p>A session without any suite (no top suite, no suite added with <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span>, and no static suite) is reported as an error, since a test program that runs nothing must not pass unnoticed.</p>


<p>The session runs only once; later calls return the same exit code without running anything again. A call made while the session runs, for example from a suite body, or after the test execution was aborted (see <span class="doxyComputerOutput"><a href="#a7bc806540e65c21095ef1ea1ef970db2">abort()</a></span>), is reported on <span class="doxyComputerOutput">stderr</span> and returns 1, without other effects.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>0 if all checks passed, or if the test cases were listed; 1 if a check failed, if a suite was rejected by <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span> or <span class="doxyComputerOutput"><a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite()</a></span>, if there was no suite, if the runner is running, or if the test execution was aborted; 2 if <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise()</a></span> reported an option error, or if the filters selected no test case, regardless of the checks.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Since</dt>
<dd><p>6.0.0</p></dd>
</dl>


<p>Initialises the runner with the default options, if not yet done. Finalises the top suite, if added, by stopping its stopwatch and notifying the reporter, then accumulates its totals into the runner totals. Subsequently invokes <span class="doxyComputerOutput"><a href="#a061939d61f7f2d4a4523c427b0dc98f2">run_child_suites()</a></span> to execute, sorted by name, and accumulate the registered and the static child suites. Finally, stops the session stopwatch, notifies the reporter, and returns <span class="doxyComputerOutput">0</span> if all checks passed or <span class="doxyComputerOutput">1</span> otherwise, or if a suite was rejected by <span class="doxyComputerOutput"><a href="#a1dcc8f8d7f80044c67c492a1aebe3043">register_suite()</a></span> or <span class="doxyComputerOutput"><a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite()</a></span>, or if there was no suite at all; if <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise()</a></span> reported an option error, or if the filters selected no test case, <span class="doxyComputerOutput">2</span> is returned, regardless of the checks.</p>


<p>While the suites run, the session is in the <span class="doxyComputerOutput">running</span> state, so that the suites added by them are rejected.</p>


<p>While the test cases are listed, the top suite is not reported, the suites run only to create their test cases, the numbers of listed test cases and suites end the list, and the exit code is <span class="doxyComputerOutput">0</span>, or <span class="doxyComputerOutput">2</span> after an option error.</p>


<p>The result is stored, and the later calls return it without running anything again. If the runner is already running (a call from a suite or a test case), or if the test execution was aborted, an error is reported on <span class="doxyComputerOutput">stderr</span> and <span class="doxyComputerOutput">1</span> is returned.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00489">489</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00633">633</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a700e3ef1f955492cd84235bd388dcdf2">633</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a700e3ef1f955492cd84235bd388dcdf2">runner::run_suites</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">634</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">635</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">636</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">637</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">638</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">639</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#ad107cec6e32daac2da4cd665c7444e51">aborted_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">640</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">641</span><span class="doxyLineContent"><span class="doxyHighlight">        fprintf (stderr, </span><span class="doxyHighlightStringLiteral">"error: test execution aborted\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">642</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> 1;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">643</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">644</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">645</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> == <a href="#a081c4bd4495097c8c7f913ef837899baaa5d7ceb2c59b8cee46c2953fec9abc19">session_state::finished</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">646</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">647</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// The session has ended; do not run the suites again.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">648</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">exit_code_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">649</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">650</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">651</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> == <a href="#a081c4bd4495097c8c7f913ef837899baa75101dcdfc88455bcafc9e53e0b06689">session_state::running</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">652</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">653</span><span class="doxyLineContent"><span class="doxyHighlight">        fprintf (stderr, </span><span class="doxyHighlightStringLiteral">"error: test runner already running\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">654</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> 1;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">655</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">656</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">657</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> == <a href="#a081c4bd4495097c8c7f913ef837899baae2fa538867c3830a859a5b17ab24644b">session_state::created</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">658</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">659</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a39ee9ec53f8df687cd84092de5118592">initialise</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options">runner_options</a>{});</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">660</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">661</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">662</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> = <a href="#a081c4bd4495097c8c7f913ef837899baa75101dcdfc88455bcafc9e53e0b06689">session_state::running</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">663</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a291ce3303f40804df4fd99f0f7d40d6c">started_next_</a> = <a href="#a5fd4803c937d65c578a4ae30d407c40e">started_first_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">664</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a5fd4803c937d65c578a4ae30d407c40e">started_first_</a> = </span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">665</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">666</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// When listing, the suites run only to create their test cases, which</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">667</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// are listed, and the number of listed test cases ends the list.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">668</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#ac4f95336439b329d0f3731a5dcafb6f9">list_tests</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">669</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">670</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a061939d61f7f2d4a4523c427b0dc98f2">run_child_suites</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">671</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">672</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> test_cases = <a href="#a90900e7d0a4571407b3727e031e46685">listed_test_cases_count_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">673</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> suites = <a href="#acb06cb7ebf949b8af5c5d57645c56e4a">listed_suites_count_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">674</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>-&gt;write_line (<a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#aff30f0303a958a549a2f4b6e67db00d5">verbosity_level</a> != <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">verbosity::silent</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">675</span><span class="doxyLineContent"><span class="doxyHighlight">                               </span><span class="doxyHighlightStringLiteral">"%lu test case%s in %lu test suite%s\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">676</span><span class="doxyLineContent"><span class="doxyHighlight">                               test_cases, (test_cases == 1) ? </span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"> : </span><span class="doxyHighlightStringLiteral">"s"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">677</span><span class="doxyLineContent"><span class="doxyHighlight">                               suites, (suites == 1) ? </span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"> : </span><span class="doxyHighlightStringLiteral">"s"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">678</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>-&gt;flush_streams ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">679</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">680</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">exit_code_</a> = <a href="#a11cfc0285b39ae765ccf3082c1eadebe">has_option_errors</a> () ? 2 : 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">681</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> = <a href="#a081c4bd4495097c8c7f913ef837899baaa5d7ceb2c59b8cee46c2953fec9abc19">session_state::finished</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">682</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">exit_code_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">683</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">684</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">685</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a4a43729c815ce9b3e3f15a650f011f66">has_top_suite_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">686</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">687</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a95145ab410f5c0b6e514ac366aff8d84">stopwatch_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch/#a83ab4e25e25a4a81ed1d3277ac09390d">stop</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">688</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>-&gt;end_suite (<a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">689</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a04b52f3243abe3a9b08b44efd03e4b57">totals_</a> += <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">totals</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">690</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">691</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">692</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a061939d61f7f2d4a4523c427b0dc98f2">run_child_suites</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">693</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">694</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// A session without suites runs nothing; report it.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">695</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> has_no_suites = (<a href="#ac29e4b993bb3fe795eb8900231cbf5c4">total_suites_count</a> () == 0);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">696</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (has_no_suites)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">697</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">698</span><span class="doxyLineContent"><span class="doxyHighlight">        fprintf (stderr, </span><span class="doxyHighlightStringLiteral">"error: no test suites\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">699</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>-&gt;write_line (<a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#aff30f0303a958a549a2f4b6e67db00d5">verbosity_level</a> != <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">verbosity::silent</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">700</span><span class="doxyLineContent"><span class="doxyHighlight">                               </span><span class="doxyHighlightStringLiteral">"%serror: no test suites\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">701</span><span class="doxyLineContent"><span class="doxyHighlight">                               <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>-&gt;comment_prefix ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">702</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">703</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">704</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// A filter that selects no test case disables the tests; report it.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">705</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> selected_nothing = !has_no_suites</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">706</span><span class="doxyLineContent"><span class="doxyHighlight">                                  &amp;&amp; !<a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#a62b0a05ad2be4f3a5131aaf8bb523910">filter_patterns</a>.empty ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">707</span><span class="doxyLineContent"><span class="doxyHighlight">                                  &amp;&amp; <a href="#a04b52f3243abe3a9b08b44efd03e4b57">totals_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">executed_test_cases</a> () == 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">708</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (selected_nothing)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">709</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">710</span><span class="doxyLineContent"><span class="doxyHighlight">        fprintf (stderr, </span><span class="doxyHighlightStringLiteral">"error: the filters selected no test case\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">711</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>-&gt;write_line (<a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#aff30f0303a958a549a2f4b6e67db00d5">verbosity_level</a> != <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">verbosity::silent</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">712</span><span class="doxyLineContent"><span class="doxyHighlight">                               </span><span class="doxyHighlightStringLiteral">"%serror: the filters selected no test case\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">713</span><span class="doxyLineContent"><span class="doxyHighlight">                               <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>-&gt;comment_prefix ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">714</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">715</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">716</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a13b3cf196a1b12cb90a12c4b84223d15">stopwatch_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch/#a83ab4e25e25a4a81ed1d3277ac09390d">stop</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">717</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>-&gt;end_session (*</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">718</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">719</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (selected_nothing || <a href="#a11cfc0285b39ae765ccf3082c1eadebe">has_option_errors</a> ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">720</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">721</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">exit_code_</a> = 2;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">722</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">723</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">724</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">725</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">exit_code_</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">726</span><span class="doxyLineContent"><span class="doxyHighlight">            = (<a href="#a04b52f3243abe3a9b08b44efd03e4b57">totals_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a14690f9880df505f9dd90a9f2c3dfc96">passed</a> () &amp;&amp; !<a href="#a999d64ffbd12dcacb59c34fbea4452ba">has_rejected_suites_</a> &amp;&amp; !has_no_suites)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">727</span><span class="doxyLineContent"><span class="doxyHighlight">                  ? 0</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">728</span><span class="doxyLineContent"><span class="doxyHighlight">                  : 1;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">729</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">730</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> = <a href="#a081c4bd4495097c8c7f913ef837899baaa5d7ceb2c59b8cee46c2953fec9abc19">session_state::finished</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">731</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">732</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">733</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s -&gt; %d\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__, <a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">exit_code_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">734</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">735</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">736</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">exit_code_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">737</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#ad107cec6e32daac2da4cd665c7444e51">aborted_</a>, <a href="#a081c4bd4495097c8c7f913ef837899baae2fa538867c3830a859a5b17ab24644b">created</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">micro_os_plus::micro_test_plus::counters::executed_test_cases</a>, <a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">exit_code_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#a62b0a05ad2be4f3a5131aaf8bb523910">micro_os_plus::micro_test_plus::runner_options::filter_patterns</a>, <a href="#a081c4bd4495097c8c7f913ef837899baaa5d7ceb2c59b8cee46c2953fec9abc19">finished</a>, <a href="#a11cfc0285b39ae765ccf3082c1eadebe">has_option_errors</a>, <a href="#a999d64ffbd12dcacb59c34fbea4452ba">has_rejected_suites_</a>, <a href="#a4a43729c815ce9b3e3f15a650f011f66">has_top_suite_</a>, <a href="#a39ee9ec53f8df687cd84092de5118592">initialise</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#ac4f95336439b329d0f3731a5dcafb6f9">micro_os_plus::micro_test_plus::runner_options::list_tests</a>, <a href="#acb06cb7ebf949b8af5c5d57645c56e4a">listed_suites_count_</a>, <a href="#a90900e7d0a4571407b3727e031e46685">listed_test_cases_count_</a>, <a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a14690f9880df505f9dd90a9f2c3dfc96">micro_os_plus::micro_test_plus::counters::passed</a>, <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>, <a href="#a061939d61f7f2d4a4523c427b0dc98f2">run_child_suites</a>, <a href="#a081c4bd4495097c8c7f913ef837899baa75101dcdfc88455bcafc9e53e0b06689">running</a>, <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">micro_os_plus::micro_test_plus::silent</a>, <a href="#a5fd4803c937d65c578a4ae30d407c40e">started_first_</a>, <a href="#a291ce3303f40804df4fd99f0f7d40d6c">started_next_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch/#a83ab4e25e25a4a81ed1d3277ac09390d">micro_os_plus::micro_test_plus::detail::stopwatch::stop</a>, <a href="#a13b3cf196a1b12cb90a12c4b84223d15">stopwatch_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a95145ab410f5c0b6e514ac366aff8d84">micro_os_plus::micro_test_plus::suite::stopwatch_</a>, <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>, <a href="#ac29e4b993bb3fe795eb8900231cbf5c4">total_suites_count</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">micro_os_plus::micro_test_plus::detail::runnable_base::totals</a>, <a href="#a04b52f3243abe3a9b08b44efd03e4b57">totals_</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#aff30f0303a958a549a2f4b6e67db00d5">micro_os_plus::micro_test_plus::runner_options::verbosity_level</a>.</p>


<p>Referenced by <a href="#a7f8403f1ccc6a0e8171ef077bcd9cbd4">exit_code</a>.</p>

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


<p>The handler can be set at any time, before or after <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise()</a></span>.</p>


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
<dd><p>6.0.0</p></dd>
</dl>


<p>Stores the new handler and returns the previous one; a null handler restores the default behaviour.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00632">632</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00759">759</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a711756a8c6958c4036527a290c481f86">759</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a711756a8c6958c4036527a290c481f86">runner::set_abort_handler</a> (<a href="#ab5b0711c5f1ab3063c410c1b9a76707b">abort_handler_t</a> handler) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">760</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">761</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#ab5b0711c5f1ab3063c410c1b9a76707b">abort_handler_t</a> previous = <a href="#a1138505536cf6afe69dea5ae044eeb5a">abort_handler_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">762</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1138505536cf6afe69dea5ae044eeb5a">abort_handler_</a> = handler;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">763</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> previous;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">764</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

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


<p>Counts the suites, registered or static, whose names do not match the first filter pattern (<span class="doxyComputerOutput">--filter</span> or <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#a62b0a05ad2be4f3a5131aaf8bb523910">runner_options::filter_patterns</a></span>); it is complete only after <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> has returned, and is zero when there are no patterns. The skipped suites are included in <span class="doxyComputerOutput"><a href="#a9484b22aa909151712144cd39130187a">added_suites_count()</a></span> and <span class="doxyComputerOutput"><a href="#a67d3cf710cccd419c127e63c2c30e9fe">static_suites_count()</a></span>; the skipped test cases are counted by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a2e5ea7bbb9bd5a05213dee741f08599d">counters::skipped_test_cases()</a></span>.</p>


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
<dd><p>6.0.0</p></dd>
</dl>


<p>Returns the counter incremented by <span class="doxyComputerOutput"><a href="#a061939d61f7f2d4a4523c427b0dc98f2">run_child_suites()</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00850">850</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00910">910</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a2c2a6d7cb45b714026d124d0ca432360">910</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a2c2a6d7cb45b714026d124d0ca432360">runner::skipped_suites_count</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">911</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">912</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#ae815c0c97245032223f4c1523e1d35fe">skipped_suites_count_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">913</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

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


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00829">829</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00879">879</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a67d3cf710cccd419c127e63c2c30e9fe">879</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a67d3cf710cccd419c127e63c2c30e9fe">runner::static_suites_count</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">880</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">881</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> count = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">882</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">micro_test_plus::suite</a>* suite_ptr = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a612f5529e08321a2e44c714d60c2ba1e">suite::first_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">883</span><span class="doxyLineContent"><span class="doxyHighlight">         suite_ptr != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">; suite_ptr = suite_ptr-&gt;<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a65d1fed18566774295fcbc7df44c216e">next_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">884</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">885</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (&amp;suite_ptr-&gt;test_runner () == </span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">886</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">887</span><span class="doxyLineContent"><span class="doxyHighlight">            ++count;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">888</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">889</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">890</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> count - <a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a>.size ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">891</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a612f5529e08321a2e44c714d60c2ba1e">micro_os_plus::micro_test_plus::suite::first_</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a65d1fed18566774295fcbc7df44c216e">micro_os_plus::micro_test_plus::suite::next_</a>.</p>


<p>Referenced by <a href="#ac29e4b993bb3fe795eb8900231cbf5c4">total_suites_count</a>.</p>

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


<p>One, if the top suite was added by <span class="doxyComputerOutput"><a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite()</a></span>, plus <span class="doxyComputerOutput"><a href="#a9484b22aa909151712144cd39130187a">added_suites_count()</a></span> plus <span class="doxyComputerOutput"><a href="#a67d3cf710cccd419c127e63c2c30e9fe">static_suites_count()</a></span>; this is the number of suites printed by the reporters.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The total number of test suites managed by this runner, including the top suite, if any, and the static suites.</p></dd>
</dl>


<p>Returns one, if the top suite was added, plus the count of the suites added with <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span>, plus the count of the static suites.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00680">680</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00899">899</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ac29e4b993bb3fe795eb8900231cbf5c4">899</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ac29e4b993bb3fe795eb8900231cbf5c4">runner::total_suites_count</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">900</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">901</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> (<a href="#a4a43729c815ce9b3e3f15a650f011f66">has_top_suite_</a> ? 1u : 0u) + <a href="#a9484b22aa909151712144cd39130187a">added_suites_count</a> ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">902</span><span class="doxyLineContent"><span class="doxyHighlight">           + <a href="#a67d3cf710cccd419c127e63c2c30e9fe">static_suites_count</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">903</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9484b22aa909151712144cd39130187a">added_suites_count</a>, <a href="#a4a43729c815ce9b3e3f15a650f011f66">has_top_suite_</a> and <a href="#a67d3cf710cccd419c127e63c2c30e9fe">static_suites_count</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a7033819609bfad2db2ecc7a024e91b2c">micro_os_plus::micro_test_plus::detail::reporter_tap::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a6bf3aac88a5e66e2f93eb32c54dbdd14">micro_os_plus::micro_test_plus::detail::reporter::format_session_totals</a> and <a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites</a>.</p>

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


<p>The counters include the checks and the test cases of all the suites that were run, including the top suite, if any; they are complete only after <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> has returned. The totals are read-only; there is no non-const overload, so that the counters cannot be modified from the test code.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A const reference to the session totals.</p></dd>
</dl>


<p>Returns a const reference to the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters">counters</a></span> member.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00867">867</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h/#l00121">121</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h">runner-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a2c8a999cc273356ea10ed34fb12dcf5a">121</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a2c8a999cc273356ea10ed34fb12dcf5a">runner::totals</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">122</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">123</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a04b52f3243abe3a9b08b44efd03e4b57">totals_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">124</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a04b52f3243abe3a9b08b44efd03e4b57">totals_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ace9c2dfffc49a97516b96dacaf87b943">micro_os_plus::micro_test_plus::detail::reporter_human::end_session</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a6bf3aac88a5e66e2f93eb32c54dbdd14">micro_os_plus::micro_test_plus::detail::reporter::format_session_totals</a>.</p>

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


<p>The level is selected with the <span class="doxyComputerOutput">--silent</span>, <span class="doxyComputerOutput">--quiet</span>, and <span class="doxyComputerOutput">--verbose</span> command-line options, or with <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#aff30f0303a958a549a2f4b6e67db00d5">runner_options::verbosity_level</a></span>; the tests can use it to decide whether to display their own messages. Before <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise()</a></span> is called, it is <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">verbosity::normal</a></span>.</p>


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
<dd><p>6.0.0</p></dd>
</dl>


<p>Returns the level kept in <span class="doxyComputerOutput"><a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a></span>, which does not depend on the reporter, so the call is safe before <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise()</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00699">699</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h/#l00077">77</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h">runner-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a1dd0221dca8e7382f0b625ff6316ed92">77</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a1dd0221dca8e7382f0b625ff6316ed92">runner::verbosity_level</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight"> -&gt; <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914b">micro_test_plus::verbosity</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">78</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">79</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>.verbosity_level;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">80</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>.</p>


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


<p>While the report is open, from <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise()</a></span>, which begins it (the test cases of the top suite run from then on), to the end of <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>, the reporter writes the buffered results and the location of the abort, with <span class="doxyComputerOutput">abort_session()</span>, to the console and to the output file, since the totals are never reached. Otherwise, there is no report to complete, and the location is written to <span class="doxyComputerOutput">stderr</span>. The standard streams are then flushed, and the handler set by <span class="doxyComputerOutput"><a href="#a711756a8c6958c4036527a290c481f86">set_abort_handler()</a></span> is called, if any. If there is no handler, or if it returns, the process is terminated via <span class="doxyComputerOutput">::abort()</span>.</p>


<p>The <span class="doxyComputerOutput"><a href="#ad107cec6e32daac2da4cd665c7444e51">aborted_</a></span> flag is set first, and never cleared, so that, if the handler throws an exception, the test cases and the suites pass it on (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#adb4333ecb107fee477156b661f0b1512">test_case::run()</a></span>), and the runner refuses to run again. An abort after another one, for example from the code that caught the exception, is not reported again, since the report is already complete; the handler is still called.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01099">1099</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00797">797</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#af0682165f5d07b13fd21e3f6f8da546c">797</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a7bc806540e65c21095ef1ea1ef970db2">runner::abort</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; sl, </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> is_requirement)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">798</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">799</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">800</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">801</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">802</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">803</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (!<a href="#ad107cec6e32daac2da4cd665c7444e51">aborted_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">804</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">805</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#ad107cec6e32daac2da4cd665c7444e51">aborted_</a> = </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">806</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">807</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> == <a href="#a081c4bd4495097c8c7f913ef837899baadb1687e1890c33928fe61b7cb4ac2f0e">session_state::initialised</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">808</span><span class="doxyLineContent"><span class="doxyHighlight">            || <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> == <a href="#a081c4bd4495097c8c7f913ef837899baa75101dcdfc88455bcafc9e53e0b06689">session_state::running</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">809</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">810</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>-&gt;abort_session (sl, is_requirement);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">811</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">812</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">813</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">814</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightComment">// The type of `line()` depends on the toolchain</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">815</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightComment">// (`uint_least32_t` for `std::source_location`); widen it</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">816</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightComment">// implicitly, without a cast that would be useless on some</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">817</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightComment">// platforms.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">818</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> line = sl.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#aab9d006004611ac0526852a09f675c66">line</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">819</span><span class="doxyLineContent"><span class="doxyHighlight">            fprintf (stderr, </span><span class="doxyHighlightStringLiteral">"error: test execution aborted at %s:%lu\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">820</span><span class="doxyLineContent"><span class="doxyHighlight">                     <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-utility-functions/#ga791f22f0c85b6436c9016821907b0653">utility::extract_file_name</a> (sl.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#a3df499675aacb7ab9192cfb9a5371874">file_name</a> ()), line);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">821</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">822</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">823</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">824</span><span class="doxyLineContent"><span class="doxyHighlight">    fflush (stdout);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">825</span><span class="doxyLineContent"><span class="doxyHighlight">    fflush (stderr);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">826</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">827</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a1138505536cf6afe69dea5ae044eeb5a">abort_handler_</a> != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">828</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">829</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a1138505536cf6afe69dea5ae044eeb5a">abort_handler_</a> (sl);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">830</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">831</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">832</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a7bc806540e65c21095ef1ea1ef970db2">::abort</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">833</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a7bc806540e65c21095ef1ea1ef970db2">abort</a>, <a href="#a1138505536cf6afe69dea5ae044eeb5a">abort_handler_</a>, <a href="#ad107cec6e32daac2da4cd665c7444e51">aborted_</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-utility-functions/#ga791f22f0c85b6436c9016821907b0653">micro_os_plus::micro_test_plus::utility::extract_file_name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#a3df499675aacb7ab9192cfb9a5371874">micro_os_plus::micro_test_plus::reflection::source_location::file_name</a>, <a href="#a081c4bd4495097c8c7f913ef837899baadb1687e1890c33928fe61b7cb4ac2f0e">initialised</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#aab9d006004611ac0526852a09f675c66">micro_os_plus::micro_test_plus::reflection::source_location::line</a>, <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>, <a href="#a081c4bd4495097c8c7f913ef837899baa75101dcdfc88455bcafc9e53e0b06689">running</a> and <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a>.</p>

</div>
</div>

### has\_option\_errors() {#a11cfc0285b39ae765ccf3082c1eadebe}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::runner::has_option_errors (void)</td>
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

<p>Checks whether an option error was found by <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise()</a></span>.</p>


<p>Called by <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>, which then returns 2. The errors are those found while parsing the options (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#a4ed347422b26dded0244c3926ef384a8">runner_options::has_errors()</a></span>), and the output file that cannot be opened. The filters that select no test case are checked by <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> itself.</p>


<p>Valid only after <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise()</a></span> created the reporter.</p>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p><span class="doxyComputerOutput">true</span> if an option error was found.</p></dd>
</dl>


<p>Combines the results kept by the options and by the reporter, so that the runner needs no flag of its own.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01060">1060</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h/#l00098">98</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h">runner-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a11cfc0285b39ae765ccf3082c1eadebe">98</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a11cfc0285b39ae765ccf3082c1eadebe">runner::has_option_errors</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">99</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">100</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>.has_errors () || <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>-&gt;has_output_file_error ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">101</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a> and <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>.</p>


<p>Referenced by <a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites</a>.</p>

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


<p>Level 0 refers to the suites, level 1 to their test cases, and each further level to the test cases nested one level deeper. A name is selected when there is no pattern for its level, or when it matches one of the alternatives of the pattern, separated by <span class="doxyComputerOutput">|</span>, as defined by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-utility-functions/#gaa2f0f4cff320a783ad2347c9ff3fc731">utility::is_match()</a></span>.</p>


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


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01044">1044</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00409">409</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a2b0adeef059676a455d9506ba8a06d26">409</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a2b0adeef059676a455d9506ba8a06d26">runner::is_selected</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* <a href="#a5f1698a93a8b09c39b87c23452335646">name</a>, </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> level)</span><span class="doxyHighlightKeyword"> const</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">410</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">  </span><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">411</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (level &gt;= <a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#a62b0a05ad2be4f3a5131aaf8bb523910">filter_patterns</a>.size ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">412</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">413</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">414</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">415</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">416</span><span class="doxyLineContent"><span class="doxyHighlight">    std::string_view alternatives{ <a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#a62b0a05ad2be4f3a5131aaf8bb523910">filter_patterns</a>[level] };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">417</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">while</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">418</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">419</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> separator = alternatives.find (</span><span class="doxyHighlightCharLiteral">'|'</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">420</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-utility-functions/#gaa2f0f4cff320a783ad2347c9ff3fc731">utility::is_match</a> (<a href="#a5f1698a93a8b09c39b87c23452335646">name</a>, alternatives.substr (0, separator)))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">421</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">422</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">423</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">424</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (separator == std::string_view::npos)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">425</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">426</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">427</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">428</span><span class="doxyLineContent"><span class="doxyHighlight">        alternatives.remove_prefix (separator + 1);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">429</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">430</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#a62b0a05ad2be4f3a5131aaf8bb523910">micro_os_plus::micro_test_plus::runner_options::filter_patterns</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-utility-functions/#gaa2f0f4cff320a783ad2347c9ff3fc731">micro_os_plus::micro_test_plus::utility::is_match</a>, <a href="#a5f1698a93a8b09c39b87c23452335646">name</a> and <a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a38cf903fb0ba5b76b1eb2350b6385962">micro_os_plus::micro_test_plus::detail::runnable_base::after_test_case_create</a> and <a href="#a061939d61f7f2d4a4523c427b0dc98f2">run_child_suites</a>.</p>

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


<p>Called by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base">detail::runnable_base</a></span>, a friend, for each selected test case created while the test cases are listed (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#ac4f95336439b329d0f3731a5dcafb6f9">runner_options::list_tests</a></span>). The name of the suite is written before its first listed test case, indented by two spaces, and the name of the test case after it, indented by four spaces, through the reporter, to the console, unless the verbosity is <span class="doxyComputerOutput">silent</span>, and to the output file, if any.</p>


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


<p>The suites are listed in the order in which their first test cases are created: the top suite first, during <span class="doxyComputerOutput">main()</span>, then the other suites, in the order of <span class="doxyComputerOutput"><a href="#a061939d61f7f2d4a4523c427b0dc98f2">run_child_suites()</a></span>; so the name of a suite is written when it differs from the previous one.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01080">1080</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00442">442</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a0e478c394741ff78f65a7e2c0822ba50">442</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a0e478c394741ff78f65a7e2c0822ba50">runner::list_test_case</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">micro_test_plus::suite</a>&amp; <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">443</span><span class="doxyLineContent"><span class="doxyHighlight">                          </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">444</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">445</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (&amp;<a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a> != <a href="#af8ce5a496dba305f6fbd45005d580321">listed_suite_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">446</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">447</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#af8ce5a496dba305f6fbd45005d580321">listed_suite_</a> = &amp;<a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">448</span><span class="doxyLineContent"><span class="doxyHighlight">        ++<a href="#acb06cb7ebf949b8af5c5d57645c56e4a">listed_suites_count_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">449</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>-&gt;write_line (<a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#aff30f0303a958a549a2f4b6e67db00d5">verbosity_level</a> != <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">verbosity::silent</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">450</span><span class="doxyLineContent"><span class="doxyHighlight">                               </span><span class="doxyHighlightStringLiteral">"  %s\n"</span><span class="doxyHighlight">, <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">451</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">452</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">453</span><span class="doxyLineContent"><span class="doxyHighlight">    ++<a href="#a90900e7d0a4571407b3727e031e46685">listed_test_cases_count_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">454</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>-&gt;write_line (<a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#aff30f0303a958a549a2f4b6e67db00d5">verbosity_level</a> != <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">verbosity::silent</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">455</span><span class="doxyLineContent"><span class="doxyHighlight">                           </span><span class="doxyHighlightStringLiteral">"    %s\n"</span><span class="doxyHighlight">, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">456</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#af8ce5a496dba305f6fbd45005d580321">listed_suite_</a>, <a href="#acb06cb7ebf949b8af5c5d57645c56e4a">listed_suites_count_</a>, <a href="#a90900e7d0a4571407b3727e031e46685">listed_test_cases_count_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">micro_os_plus::micro_test_plus::detail::runnable_base::name</a>, <a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>, <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">micro_os_plus::micro_test_plus::silent</a>, <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#aff30f0303a958a549a2f4b6e67db00d5">micro_os_plus::micro_test_plus::runner_options::verbosity_level</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a38cf903fb0ba5b76b1eb2350b6385962">micro_os_plus::micro_test_plus::detail::runnable_base::after_test_case_create</a>.</p>

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


<p>Called by <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span>. Once <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> has started, the suite is rejected: it is destroyed, the error is reported on <span class="doxyComputerOutput">stderr</span>, and <span class="doxyComputerOutput"><a href="#a999d64ffbd12dcacb59c34fbea4452ba">has_rejected_suites_</a></span> is set.</p>


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


<p>Takes ownership of the supplied <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a></span> unique pointer and appends it to the internal <span class="doxyComputerOutput"><a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a></span> vector, then inserts the suite into the list of suites, sorted by name, deferring execution until <span class="doxyComputerOutput"><a href="#a061939d61f7f2d4a4523c427b0dc98f2">run_child_suites()</a></span> is called. The suite is inserted after it is stored, so that a failed allocation of the vector leaves it out of the list. If tracing is enabled, the suite name is logged for diagnostic purposes.</p>


<p>Once <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> has started, the suite is rejected, since it would never run: <span class="doxyComputerOutput"><a href="#a061939d61f7f2d4a4523c427b0dc98f2">run_child_suites()</a></span> takes the number of suites only once, before running them, and after the session has ended nothing runs. The error is reported on <span class="doxyComputerOutput">stderr</span>, the suite is destroyed when the pointer goes out of scope, and <span class="doxyComputerOutput"><a href="#a999d64ffbd12dcacb59c34fbea4452ba">has_rejected_suites_</a></span> is set, so that the exit code is not 0; if the session has already ended, the stored exit code is updated, for the later calls of <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00968">968</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00479">479</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a1dcc8f8d7f80044c67c492a1aebe3043">479</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a1dcc8f8d7f80044c67c492a1aebe3043">runner::register_suite</a> (std::unique_ptr&lt;micro_test_plus::suite&gt; <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">480</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">481</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">482</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s '%s'\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__, <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>-&gt;name ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">483</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">484</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">485</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> == <a href="#a081c4bd4495097c8c7f913ef837899baa75101dcdfc88455bcafc9e53e0b06689">session_state::running</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">486</span><span class="doxyLineContent"><span class="doxyHighlight">        || <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> == <a href="#a081c4bd4495097c8c7f913ef837899baaa5d7ceb2c59b8cee46c2953fec9abc19">session_state::finished</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">487</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">488</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a964febc11fcd08a4437e11d16544ca7b">reject_suite</a> (<a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>-&gt;name ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">489</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">490</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">491</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">492</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a>.push_back (std::move (<a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">493</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a>.back ()-&gt;link ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">494</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a>, <a href="#a081c4bd4495097c8c7f913ef837899baaa5d7ceb2c59b8cee46c2953fec9abc19">finished</a>, <a href="#a964febc11fcd08a4437e11d16544ca7b">reject_suite</a>, <a href="#a081c4bd4495097c8c7f913ef837899baa75101dcdfc88455bcafc9e53e0b06689">running</a>, <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> and <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>.</p>


<p>Referenced by <a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite</a>.</p>

</div>
</div>

### reject\_suite() {#a964febc11fcd08a4437e11d16544ca7b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::runner::reject_suite (const char * name)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Reject a suite constructed after <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> has started.</p>


<p>Reports the error on <span class="doxyComputerOutput">stderr</span>, sets <span class="doxyComputerOutput"><a href="#a999d64ffbd12dcacb59c34fbea4452ba">has_rejected_suites_</a></span>, and, if the session has already ended, updates the stored exit code, for the later calls of <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>. Used by <span class="doxyComputerOutput"><a href="#a1dcc8f8d7f80044c67c492a1aebe3043">register_suite()</a></span> and by <span class="doxyComputerOutput"><a href="#a19160679a4fe484fc9f8f76ed3408762">link_static_suite()</a></span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] name</td>
<td class="doxyParamItemDescription"><p>The name of the rejected suite.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>The message is written on <span class="doxyComputerOutput">stderr</span>, since the reporter may have ended. The suite itself is destroyed by the caller.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00985">985</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00502">502</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a964febc11fcd08a4437e11d16544ca7b">502</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a964febc11fcd08a4437e11d16544ca7b">runner::reject_suite</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* <a href="#a5f1698a93a8b09c39b87c23452335646">name</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">503</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">504</span><span class="doxyLineContent"><span class="doxyHighlight">    fprintf (stderr,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">505</span><span class="doxyLineContent"><span class="doxyHighlight">             </span><span class="doxyHighlightStringLiteral">"error: suite '%s' added after run_suites() started, rejected\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">506</span><span class="doxyLineContent"><span class="doxyHighlight">             <a href="#a5f1698a93a8b09c39b87c23452335646">name</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">507</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a999d64ffbd12dcacb59c34fbea4452ba">has_rejected_suites_</a> = </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">508</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> == <a href="#a081c4bd4495097c8c7f913ef837899baaa5d7ceb2c59b8cee46c2953fec9abc19">session_state::finished</a> &amp;&amp; <a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">exit_code_</a> == 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">509</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">510</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">exit_code_</a> = 1;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">511</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">512</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">exit_code_</a>, <a href="#a081c4bd4495097c8c7f913ef837899baaa5d7ceb2c59b8cee46c2953fec9abc19">finished</a>, <a href="#a999d64ffbd12dcacb59c34fbea4452ba">has_rejected_suites_</a>, <a href="#a5f1698a93a8b09c39b87c23452335646">name</a> and <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a>.</p>


<p>Referenced by <a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite</a> and <a href="#a1dcc8f8d7f80044c67c492a1aebe3043">register_suite</a>.</p>

</div>
</div>

### run\_child\_suites() {#a061939d61f7f2d4a4523c427b0dc98f2}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::runner::run_child_suites (void)</td>
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


<p>Each suite is assigned a 1-based index, following the top suite, if added, in the order of execution. If the first filter pattern selects it, it is executed via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a432deda5a8721472e8775cbc98451722">suite::run()</a></span>, and its totals are accumulated into the runner totals; otherwise, it is reported as skipped and counted in <span class="doxyComputerOutput"><a href="#ae815c0c97245032223f4c1523e1d35fe">skipped_suites_count_</a></span>, keeping its index, so that the TAP plan remains complete; while the test cases are listed, the skipped suites are not reported. The executed test cases counter is not incremented; suites are not counted as test cases.</p>


<p>The next suite is read after the current one has run, since the suites of the local runners created by the current suite are inserted into the list, and removed again, while it runs.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00953">953</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00571">571</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a061939d61f7f2d4a4523c427b0dc98f2">571</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a061939d61f7f2d4a4523c427b0dc98f2">runner::run_child_suites</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">572</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">573</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// The top suite, if added, has index 1</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">574</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> own_index = <a href="#a4a43729c815ce9b3e3f15a650f011f66">has_top_suite_</a> ? 1 : 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">575</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">micro_test_plus::suite</a>* suite_ptr = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a612f5529e08321a2e44c714d60c2ba1e">suite::first_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">576</span><span class="doxyLineContent"><span class="doxyHighlight">         suite_ptr != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">; suite_ptr = suite_ptr-&gt;<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a65d1fed18566774295fcbc7df44c216e">next_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">577</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">578</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// Skip the suites run by other runners.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">579</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (&amp;suite_ptr-&gt;test_runner () != </span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">580</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">581</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">continue</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">582</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">583</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">584</span><span class="doxyLineContent"><span class="doxyHighlight">        suite_ptr-&gt;own_index_ = ++own_index;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">585</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">586</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (!<a href="#a2b0adeef059676a455d9506ba8a06d26">is_selected</a> (suite_ptr-&gt;name (), 0))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">587</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">588</span><span class="doxyLineContent"><span class="doxyHighlight">            ++<a href="#ae815c0c97245032223f4c1523e1d35fe">skipped_suites_count_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">589</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (!<a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#ac4f95336439b329d0f3731a5dcafb6f9">list_tests</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">590</span><span class="doxyLineContent"><span class="doxyHighlight">              {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">591</span><span class="doxyLineContent"><span class="doxyHighlight">                <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>-&gt;skip_suite (*suite_ptr);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">592</span><span class="doxyLineContent"><span class="doxyHighlight">              }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">593</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">continue</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">594</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">595</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">596</span><span class="doxyLineContent"><span class="doxyHighlight">        suite_ptr-&gt;run ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">597</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">598</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// Accumulate the totals from the child suite into the runner</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">599</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// totals.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">600</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// DO NOT increment executed_test_cases here.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">601</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a04b52f3243abe3a9b08b44efd03e4b57">totals_</a> += suite_ptr-&gt;totals ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">602</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">603</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a612f5529e08321a2e44c714d60c2ba1e">micro_os_plus::micro_test_plus::suite::first_</a>, <a href="#a4a43729c815ce9b3e3f15a650f011f66">has_top_suite_</a>, <a href="#a2b0adeef059676a455d9506ba8a06d26">is_selected</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#ac4f95336439b329d0f3731a5dcafb6f9">micro_os_plus::micro_test_plus::runner_options::list_tests</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a65d1fed18566774295fcbc7df44c216e">micro_os_plus::micro_test_plus::suite::next_</a>, <a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>, <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>, <a href="#ae815c0c97245032223f4c1523e1d35fe">skipped_suites_count_</a> and <a href="#a04b52f3243abe3a9b08b44efd03e4b57">totals_</a>.</p>


<p>Referenced by <a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites</a>.</p>

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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01243">1243</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a1138505536cf6afe69dea5ae044eeb5a">1243</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#ab5b0711c5f1ab3063c410c1b9a76707b">abort_handler_t</a> <a href="#a1138505536cf6afe69dea5ae044eeb5a">abort_handler_</a> = </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">;</span></span></div>

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


<p>Set by <span class="doxyComputerOutput"><a href="#a7bc806540e65c21095ef1ea1ef970db2">abort()</a></span>, before the abort is reported, and never cleared. Read by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base">detail::runnable_base</a></span>, a friend, so that, when the abort handler throws an exception, the test cases and the suites pass it on instead of reporting it, and no test case runs afterwards; read by <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise()</a></span> and <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>, which then refuse to start, and by <span class="doxyComputerOutput"><a href="#a7bc806540e65c21095ef1ea1ef970db2">abort()</a></span>, so that a later abort is not reported again.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01256">1256</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ad107cec6e32daac2da4cd665c7444e51">1256</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="#ad107cec6e32daac2da4cd665c7444e51">aborted_</a> = </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>

</div>


<p>Referenced by <a href="#af0682165f5d07b13fd21e3f6f8da546c">abort</a>, <a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a38cf903fb0ba5b76b1eb2350b6385962">micro_os_plus::micro_test_plus::detail::runnable_base::after_test_case_create</a>, <a href="#aba1f6140138ba802f91f8f025258b63d">initialise</a>, <a href="#a39ee9ec53f8df687cd84092de5118592">initialise</a>, <a href="#ae87c4a8f0e08e069b6d1a393f88e040e">initialise</a> and <a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites</a>.</p>

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


<p>Each call to <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span> appends a new <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a></span> to this vector, and inserts it into the list of suites, sorted by name; the suites are run later, by <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>, in the order of the list. The vector retains ownership of all suites for the lifetime of the runner.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01131">1131</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#abacf53ab658e289ae89051531c0cddad">1131</a></span><span class="doxyLineContent"><span class="doxyHighlight">    std::vector&lt;std::unique_ptr&lt;class suite&gt;&gt; <a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a>;</span></span></div>

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

<p>The exit code computed by <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>.</p>


<p>Returned again by the calls of <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> made after the session ended.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01226">1226</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">1226</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> <a href="#a1aa6f3fec517a49f9cdc70ec79b9d1e5">exit_code_</a> = 1;</span></span></div>

</div>


<p>Referenced by <a href="#ae87c4a8f0e08e069b6d1a393f88e040e">initialise</a>, <a href="#a964febc11fcd08a4437e11d16544ca7b">reject_suite</a> and <a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites</a>.</p>

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

<p>Whether a suite was added after <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> had started.</p>


<p>Set by <span class="doxyComputerOutput"><a href="#a1dcc8f8d7f80044c67c492a1aebe3043">register_suite()</a></span>, which rejects such a suite; <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> then returns 1, unless an option error requires 2.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01235">1235</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a999d64ffbd12dcacb59c34fbea4452ba">1235</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="#a999d64ffbd12dcacb59c34fbea4452ba">has_rejected_suites_</a> = </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>

</div>


<p>Referenced by <a href="#a964febc11fcd08a4437e11d16544ca7b">reject_suite</a> and <a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites</a>.</p>

</div>
</div>

### has\_top\_suite\_ {#a4a43729c815ce9b3e3f15a650f011f66}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::runner::has_top_suite_ = false</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Whether the top suite was added to the session.</p>


<p>Set by <span class="doxyComputerOutput"><a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite()</a></span>. When not set, the top suite is neither run, nor reported, nor counted.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01120">1120</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a4a43729c815ce9b3e3f15a650f011f66">1120</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="#a4a43729c815ce9b3e3f15a650f011f66">has_top_suite_</a> = </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>

</div>


<p>Referenced by <a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite</a>, <a href="#a061939d61f7f2d4a4523c427b0dc98f2">run_child_suites</a>, <a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites</a> and <a href="#ac29e4b993bb3fe795eb8900231cbf5c4">total_suites_count</a>.</p>

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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01276">1276</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#af8ce5a496dba305f6fbd45005d580321">1276</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>* <a href="#af8ce5a496dba305f6fbd45005d580321">listed_suite_</a> = </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">;</span></span></div>

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


<p>Incremented by <span class="doxyComputerOutput"><a href="#a0e478c394741ff78f65a7e2c0822ba50">list_test_case()</a></span> when it writes the name of a suite; written by <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> at the end of the list.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01294">1294</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#acb06cb7ebf949b8af5c5d57645c56e4a">1294</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="#acb06cb7ebf949b8af5c5d57645c56e4a">listed_suites_count_</a> = 0;</span></span></div>

</div>


<p>Referenced by <a href="#a0e478c394741ff78f65a7e2c0822ba50">list_test_case</a> and <a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites</a>.</p>

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


<p>Incremented by <span class="doxyComputerOutput"><a href="#a0e478c394741ff78f65a7e2c0822ba50">list_test_case()</a></span>; written by <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> at the end of the list.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01285">1285</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a90900e7d0a4571407b3727e031e46685">1285</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="#a90900e7d0a4571407b3727e031e46685">listed_test_cases_count_</a> = 0;</span></span></div>

</div>


<p>Referenced by <a href="#a0e478c394741ff78f65a7e2c0822ba50">list_test_case</a> and <a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites</a>.</p>

</div>
</div>

### options\_ {#acea30e98ccf65d97e8c0e0d0ff8edda0}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">runner_options micro_os_plus::micro_test_plus::runner::options_ {}</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The options of the test session.</p>


<p>Moved in by <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise()</a></span>, and kept for the whole session: the verbosity is returned by <span class="doxyComputerOutput"><a href="#a1dd0221dca8e7382f0b625ff6316ed92">verbosity_level()</a></span>, the filter patterns are read by <span class="doxyComputerOutput"><a href="#a2b0adeef059676a455d9506ba8a06d26">is_selected()</a></span>, the listing of the test cases by <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> and <span class="doxyComputerOutput"><a href="#ae5df469f7aaccc8e24bfadff4c209688">is_listing()</a></span>, and the command line by the reporters, which are friends. The defaults until then.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01183">1183</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">1183</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options">runner_options</a> <a href="#acea30e98ccf65d97e8c0e0d0ff8edda0">options_</a>{};</span></span></div>

</div>


<p>Referenced by <a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a38cf903fb0ba5b76b1eb2350b6385962">micro_os_plus::micro_test_plus::detail::runnable_base::after_test_case_create</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#aa3cefeb72e745b2424b48ed4a31102e7">micro_os_plus::micro_test_plus::detail::reporter_human::begin_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#acaae91eea2deed1fe3f43b6453e7e656">micro_os_plus::micro_test_plus::detail::reporter_tap::begin_session</a>, <a href="#a11cfc0285b39ae765ccf3082c1eadebe">has_option_errors</a>, <a href="#ae87c4a8f0e08e069b6d1a393f88e040e">initialise</a>, <a href="#ae5df469f7aaccc8e24bfadff4c209688">is_listing</a>, <a href="#a2b0adeef059676a455d9506ba8a06d26">is_selected</a>, <a href="#a0e478c394741ff78f65a7e2c0822ba50">list_test_case</a>, <a href="#a061939d61f7f2d4a4523c427b0dc98f2">run_child_suites</a>, <a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites</a> and <a href="#a1dd0221dca8e7382f0b625ff6316ed92">verbosity_level</a>.</p>

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


<p>Created by <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise()</a></span>, as selected by the session options, either given by the caller or parsed from the command line by the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options">runner_options</a></span> constructor. Used by the suites and the test cases, through <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base">detail::runnable_base</a></span>, which is a friend.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01143">1143</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a67205181c73d11d12964bb324f1dc902">1143</a></span><span class="doxyLineContent"><span class="doxyHighlight">    std::unique_ptr&lt;detail::reporter&gt; <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#af0682165f5d07b13fd21e3f6f8da546c">abort</a>, <a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite</a>, <a href="#a11cfc0285b39ae765ccf3082c1eadebe">has_option_errors</a>, <a href="#ae87c4a8f0e08e069b6d1a393f88e040e">initialise</a>, <a href="#a0e478c394741ff78f65a7e2c0822ba50">list_test_case</a>, <a href="#a65250ff363fbb3b5869bbe4de9578e86">reporter</a>, <a href="#a061939d61f7f2d4a4523c427b0dc98f2">run_child_suites</a> and <a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites</a>.</p>

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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01267">1267</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#acf5727abb4e4b23e1a2d7d3320f5dec9">1267</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>* <a href="#acf5727abb4e4b23e1a2d7d3320f5dec9">running_test_case_</a> = </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">;</span></span></div>

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


<p>Set by <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise()</a></span> and <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>; read by <span class="doxyComputerOutput"><a href="#a1dcc8f8d7f80044c67c492a1aebe3043">register_suite()</a></span>, to reject the suites added too late.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01217">1217</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a70dad6c927a59d5459c2edfdb40fdece">1217</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a081c4bd4495097c8c7f913ef837899ba">session_state</a> <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> = <a href="#a081c4bd4495097c8c7f913ef837899baae2fa538867c3830a859a5b17ab24644b">session_state::created</a>;</span></span></div>

</div>


<p>Referenced by <a href="#af0682165f5d07b13fd21e3f6f8da546c">abort</a>, <a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite</a>, <a href="#aba1f6140138ba802f91f8f025258b63d">initialise</a>, <a href="#a39ee9ec53f8df687cd84092de5118592">initialise</a>, <a href="#ae87c4a8f0e08e069b6d1a393f88e040e">initialise</a>, <a href="#a1dcc8f8d7f80044c67c492a1aebe3043">register_suite</a>, <a href="#a964febc11fcd08a4437e11d16544ca7b">reject_suite</a> and <a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites</a>.</p>

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


<p>Incremented by <span class="doxyComputerOutput"><a href="#a061939d61f7f2d4a4523c427b0dc98f2">run_child_suites()</a></span>; returned by <span class="doxyComputerOutput"><a href="#a2c2a6d7cb45b714026d124d0ca432360">skipped_suites_count()</a></span>.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01192">1192</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ae815c0c97245032223f4c1523e1d35fe">1192</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="#ae815c0c97245032223f4c1523e1d35fe">skipped_suites_count_</a> = 0;</span></span></div>

</div>


<p>Referenced by <a href="#a061939d61f7f2d4a4523c427b0dc98f2">run_child_suites</a> and <a href="#a2c2a6d7cb45b714026d124d0ca432360">skipped_suites_count</a>.</p>

</div>
</div>

### started\_next\_ {#a291ce3303f40804df4fd99f0f7d40d6c}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">runner* micro_os_plus::micro_test_plus::runner::started_next_ = nullptr</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The next runner in the list of the started runners.</p>


<p>Null if this runner has not started, or is the last one.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01023">1023</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a291ce3303f40804df4fd99f0f7d40d6c">1023</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a5e2001730fd3659e9045fcc5cc668f07">runner</a>* <a href="#a291ce3303f40804df4fd99f0f7d40d6c">started_next_</a> = </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">;</span></span></div>

</div>


<p>Referenced by <a href="#aea1a1eff9cac943c1cd84e48b9add92f">~runner</a> and <a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites</a>.</p>

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


<p>Measures the duration of the entire test session; started by <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise()</a></span>, stopped by <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>, and read by the reporters, which are friends.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01153">1153</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a13b3cf196a1b12cb90a12c4b84223d15">1153</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch">detail::stopwatch</a> <a href="#a13b3cf196a1b12cb90a12c4b84223d15">stopwatch_</a>;</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ace9c2dfffc49a97516b96dacaf87b943">micro_os_plus::micro_test_plus::detail::reporter_human::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a7033819609bfad2db2ecc7a024e91b2c">micro_os_plus::micro_test_plus::detail::reporter_tap::end_session</a>, <a href="#ae87c4a8f0e08e069b6d1a393f88e040e">initialise</a>, <a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites</a>, <a href="#af314280f14d61d37da276567685ec2a8">timings</a> and <a href="#a7d3ccfaf760cb2f4ace586c222b22244">timings</a>.</p>

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

<p>The top suite, whose body is the code of <span class="doxyComputerOutput">main()</span>.</p>


<p>Always constructed with the runner, but part of the session only after <span class="doxyComputerOutput"><a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite()</a></span> (see <span class="doxyComputerOutput"><a href="#a4a43729c815ce9b3e3f15a650f011f66">has_top_suite_</a></span>); its test cases are added directly, between <span class="doxyComputerOutput"><a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite()</a></span> and <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01111">1111</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">1111</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite">top_suite</a> <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#a10788baa079e19676a8cdbaa253285dc">runner</a>, <a href="#a5e2001730fd3659e9045fcc5cc668f07">runner</a>, <a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite</a>, <a href="#a39ee9ec53f8df687cd84092de5118592">initialise</a> and <a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites</a>.</p>

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

<p>Owned storage for the top suite name.</p>


<p>Set by <span class="doxyComputerOutput"><a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite()</a></span>, either from its argument or derived from <span class="doxyComputerOutput">arguments[0]</span> of the session options.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01171">1171</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a401e4e098f0ceba7f21a3a5bf1ea89e3">1171</a></span><span class="doxyLineContent"><span class="doxyHighlight">    std::string <a href="#a401e4e098f0ceba7f21a3a5bf1ea89e3">top_suite_name_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite</a>.</p>

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


<p>The totals of each suite are added by <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> and <span class="doxyComputerOutput"><a href="#a061939d61f7f2d4a4523c427b0dc98f2">run_child_suites()</a></span>, after the suite was run.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01162">1162</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a04b52f3243abe3a9b08b44efd03e4b57">1162</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters">counters</a> <a href="#a04b52f3243abe3a9b08b44efd03e4b57">totals_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#a061939d61f7f2d4a4523c427b0dc98f2">run_child_suites</a>, <a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites</a> and <a href="#a2c8a999cc273356ea10ed34fb12dcf5a">totals</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Private Static Functions

### link\_static\_suite() {#a19160679a4fe484fc9f8f76ed3408762}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::runner::link_static_suite (<a href="#a5e2001730fd3659e9045fcc5cc668f07">runner</a> &amp; test_runner, class <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a> &amp; suite)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel noexcept">noexcept</span>
<span class="doxyMemberLabel static">static</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Insert a static suite into the list of suites, or reject it.</p>


<p>Called by the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite">static_suite</a></span> constructors. A static suite may be constructed before its runner, which must not be accessed then; therefore the runners that have started are kept in a constant-initialised list, which is searched by address. If the runner is in the list, <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> has started and the suite would never run, so it is rejected, as by <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span>; otherwise, it is linked.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] test_runner</td>
<td class="doxyParamItemDescription"><p>The runner of the suite.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] suite</td>
<td class="doxyParamItemDescription"><p>The suite being constructed.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Searches the list of the started runners for <span class="doxyComputerOutput">test_runner</span>, without accessing it, since it may not be constructed yet. If found, the runner reports the rejection; otherwise, the suite is linked. No memory is allocated.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01006">1006</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00522">522</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a19160679a4fe484fc9f8f76ed3408762">522</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a19160679a4fe484fc9f8f76ed3408762">runner::link_static_suite</a> (<a href="#a5e2001730fd3659e9045fcc5cc668f07">runner</a>&amp; test_runner,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">523</span><span class="doxyLineContent"><span class="doxyHighlight">                             <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">micro_test_plus::suite</a>&amp; <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">524</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">525</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="#a5e2001730fd3659e9045fcc5cc668f07">runner</a>* started = <a href="#a5fd4803c937d65c578a4ae30d407c40e">started_first_</a>; started != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">526</span><span class="doxyLineContent"><span class="doxyHighlight">         started = started-&gt;started_next_)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">527</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">528</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (started == &amp;test_runner)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">529</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">530</span><span class="doxyLineContent"><span class="doxyHighlight">            test_runner.reject_suite (<a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>.name ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">531</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">532</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">533</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">534</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">535</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>.link ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">536</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a5e2001730fd3659e9045fcc5cc668f07">runner</a>, <a href="#a5fd4803c937d65c578a4ae30d407c40e">started_first_</a> and <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#a7ac8520c7d0761e54e7482ca5d7e26f2">micro_os_plus::micro_test_plus::static_suite::link_or_reject</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Private Static Attributes

### started\_first\_ {#a5fd4803c937d65c578a4ae30d407c40e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">runner * micro_os_plus::micro_test_plus::runner::started_first_ = nullptr</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel static">static</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The head of the list of the runners that have started.</p>


<p>Constant-initialised, so it is valid before any constructor runs. A runner is inserted by <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> and removed by the destructor.</p>


<p>Constant-initialised, so it is null before any static constructor runs.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l01015">1015</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a5fd4803c937d65c578a4ae30d407c40e">1015</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> <a href="#a5e2001730fd3659e9045fcc5cc668f07">runner</a>* <a href="#a5fd4803c937d65c578a4ae30d407c40e">started_first_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#aea1a1eff9cac943c1cd84e48b9add92f">~runner</a>, <a href="#a19160679a4fe484fc9f8f76ed3408762">link_static_suite</a> and <a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Deprecated Functions

### exit\_code {#a7f8403f1ccc6a0e8171ef077bcd9cbd4}

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

<p>Deprecated name of <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>.</p>


<p>Calls <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>; once the session has ended, it only returns the exit code.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The value returned by <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>.</p></dd>
</dl>


<div class="doxyXrefSect">
<dl class="doxyXrefSectList">
<dt class="doxyXrefSectTitle"><a href=/micro-test-plus-xpack/docs/api/pages/deprecated/#_deprecated000114>Deprecated</a></dt>
<dd class="doxyXrefSectDescription">
<p>use <a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a> (since 6.0.0)</p>
</dd>
</dl>
</div>

<p>Kept for compatibility; it calls <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>, so the first call runs the session and the later ones return the stored exit code.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00509">509</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00747">747</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a7f8403f1ccc6a0e8171ef077bcd9cbd4">747</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a7f8403f1ccc6a0e8171ef077bcd9cbd4">runner::exit_code</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">748</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">749</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">750</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites</a>.</p>

</div>
</div>

### initialise {#a39ee9ec53f8df687cd84092de5118592}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">suite &amp; micro_os_plus::micro_test_plus::runner::initialise (int argc, char * argv=[], const char * top_suite_name)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Deprecated initialisation with the command-line arguments, which also adds the top suite.</p>


<p>Equivalent to <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise</a> (argc, argv)</span> followed by <span class="doxyComputerOutput"><a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite</a> (top_suite_name)</span>. Use the two calls; the top suite is now optional, and <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise()</a></span> no longer returns it.</p>


<p>The name no longer has a default value, so that the call with two arguments selects the current <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise</a> (argc, argv)</span>, which returns nothing and does not add the top suite.</p>


<p>If the runner is already initialised, or the test execution was aborted, the error is reported on <span class="doxyComputerOutput">stderr</span>, as by <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise()</a></span>, and the top suite is returned without other effects.</p>


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
<td class="doxyParamItemDescription"><p>The name given to the top suite; if empty, the name is chosen as by <span class="doxyComputerOutput"><a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite()</a></span>.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to the top suite.</p></dd>
</dl>


<div class="doxyXrefSect">
<dl class="doxyXrefSectList">
<dt class="doxyXrefSectTitle"><a href=/micro-test-plus-xpack/docs/api/pages/deprecated/#_deprecated000113>Deprecated</a></dt>
<dd class="doxyXrefSectDescription">

</dd>
</dl>
</div>

<p>Initialises the runner with the command-line options, as <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise</a> (argc, argv)</span> does, and adds the top suite.</p>


<p>If the runner is already initialised, or the test execution was aborted, the error is reported by <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise()</a></span>, and the top suite is returned without being added.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00348">348</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00150">150</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a39ee9ec53f8df687cd84092de5118592">150</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a39ee9ec53f8df687cd84092de5118592">runner::initialise</a> (</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> argc, </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* argv[], </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* top_suite_name)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">151</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">152</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> is_first = !<a href="#ad107cec6e32daac2da4cd665c7444e51">aborted_</a> &amp;&amp; <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> == <a href="#a081c4bd4495097c8c7f913ef837899baae2fa538867c3830a859a5b17ab24644b">session_state::created</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">153</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">154</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a39ee9ec53f8df687cd84092de5118592">initialise</a> (argc, argv);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">155</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (!is_first)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">156</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">157</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">158</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">159</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">160</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite</a> (top_suite_name != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight"> ? top_suite_name : </span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">161</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#ad107cec6e32daac2da4cd665c7444e51">aborted_</a>, <a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite</a>, <a href="#a081c4bd4495097c8c7f913ef837899baae2fa538867c3830a859a5b17ab24644b">created</a>, <a href="#a39ee9ec53f8df687cd84092de5118592">initialise</a>, <a href="#a70dad6c927a59d5459c2edfdb40fdece">session_state_</a> and <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>.</p>


<p>Referenced by <a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite</a>, <a href="#aba1f6140138ba802f91f8f025258b63d">initialise</a>, <a href="#a39ee9ec53f8df687cd84092de5118592">initialise</a>, <a href="#aa34a0418d54c633630a089eb2b5a61ee">operator=</a> and <a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites</a>.</p>

</div>
</div>

### name {#a5f1698a93a8b09c39b87c23452335646}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const char * micro_os_plus::micro_test_plus::runner::name (void)</td>
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

<p>Deprecated name of the runner.</p>


<p>In v5.0.1, the runner was a test node, and always returned <span class="doxyComputerOutput">"<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">runner</a>"</span>. The runner is no longer a node; the name shown at the beginning of the reports is that of the top suite, returned by <span class="doxyComputerOutput"><a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite()</a></span>.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The constant string <span class="doxyComputerOutput">"<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">runner</a>"</span>.</p></dd>
</dl>


<div class="doxyXrefSect">
<dl class="doxyXrefSectList">
<dt class="doxyXrefSectTitle"><a href=/micro-test-plus-xpack/docs/api/pages/deprecated/#_deprecated000117>Deprecated</a></dt>
<dd class="doxyXrefSectDescription">

</dd>
</dl>
</div>

<p>Returns the constant string <span class="doxyComputerOutput">"<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">runner</a>"</span>, as before the runner stopped being a test node.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00790">790</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00854">854</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a5f1698a93a8b09c39b87c23452335646">854</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a5f1698a93a8b09c39b87c23452335646">runner::name</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">855</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">856</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> </span><span class="doxyHighlightStringLiteral">"runner"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">857</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Referenced by <a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite</a>, <a href="#a2b0adeef059676a455d9506ba8a06d26">is_selected</a>, <a href="#a964febc11fcd08a4437e11d16544ca7b">reject_suite</a> and <a href="#a2636252ac7f80b7425cf2e5eced77834">suite</a>.</p>

</div>
</div>

### reporter {#a65250ff363fbb3b5869bbe4de9578e86}

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


<p>Returns the internal reporter, created by <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise()</a></span>, as selected by the session options; the call is valid only after <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise()</a></span>. In v5.0.1, the returned class was the top namespace <span class="doxyComputerOutput"><a href="#a65250ff363fbb3b5869bbe4de9578e86">reporter</a></span>, now <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">detail::reporter</a></span>; of its members, the applications used only <span class="doxyComputerOutput"><a href="#a94a9df0418776ebce476cd9a2e4f591f">verbosity()</a></span>, kept, deprecated, on <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">detail::reporter</a></span>.</p>


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
<dt class="doxyXrefSectTitle"><a href=/micro-test-plus-xpack/docs/api/pages/deprecated/#_deprecated000121>Deprecated</a></dt>
<dd class="doxyXrefSectDescription">
<p>use <a href="#a1dd0221dca8e7382f0b625ff6316ed92">verbosity_level()</a> (since 6.0.0)</p>
</dd>
</dl>
</div>

<p>Returns a reference to the reporter owned by the <span class="doxyComputerOutput"><a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a></span> unique pointer, which is empty before <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise()</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00929">929</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h/#l00156">156</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h">runner-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a65250ff363fbb3b5869bbe4de9578e86">156</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a65250ff363fbb3b5869bbe4de9578e86">runner::reporter</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">157</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">158</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *<a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">159</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a67205181c73d11d12964bb324f1dc902">reporter_</a>.</p>

</div>
</div>

### runner {#a10788baa079e19676a8cdbaa253285dc}

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


<p>Use the anonymous constructor, and pass the name to <span class="doxyComputerOutput"><a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite()</a></span>, which can also override the name given here.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">top_suite_name</td>
<td class="doxyParamItemDescription"><p>The name given to the top suite.</p></td>
</tr>
</table>
</dd>
</dl>

<div class="doxyXrefSect">
<dl class="doxyXrefSectList">
<dt class="doxyXrefSectTitle"><a href=/micro-test-plus-xpack/docs/api/pages/deprecated/#_deprecated000112>Deprecated</a></dt>
<dd class="doxyXrefSectDescription">
<p>use <a href="#a5e2001730fd3659e9045fcc5cc668f07">runner()</a> and <a href="#aac24d1193ac0579dd6ac3c523a32015f">add_top_suite()</a> (since 4.1.0)</p>
</dd>
</dl>
</div>

<p>The constructor initialises a new <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">runner</a></span> instance together with its top suite (<span class="doxyComputerOutput"><a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a></span>). If tracing is enabled, it outputs the function signature for diagnostic purposes.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00261">261</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00096">96</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a10788baa079e19676a8cdbaa253285dc">96</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a5e2001730fd3659e9045fcc5cc668f07">runner::runner</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* top_suite_name)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">97</span><span class="doxyLineContent"><span class="doxyHighlight">      : <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>{ top_suite_name, *this }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">98</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">99</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">100</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s '%s'\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__, <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">101</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">102</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">micro_os_plus::micro_test_plus::detail::runnable_base::name</a> and <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>.</p>

</div>
</div>

### suite {#a2636252ac7f80b7425cf2e5eced77834}

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


<p>Calls <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span>. The old name did not show that the suite is only stored, to be run later by <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>, unlike the test cases, which run immediately; it also hid the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a></span> class inside the runner.</p>


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
<dt class="doxyXrefSectTitle"><a href=/micro-test-plus-xpack/docs/api/pages/deprecated/#_deprecated000115>Deprecated</a></dt>
<dd class="doxyXrefSectDescription">
<p>use <a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a> (since 6.0.0)</p>
</dd>
</dl>
</div>

<p>Forwards the name, the callable, and the arguments to <span class="doxyComputerOutput"><a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite()</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00582">582</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h/#l00199">199</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h">runner-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a2636252ac7f80b7425cf2e5eced77834">199</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a2636252ac7f80b7425cf2e5eced77834">runner::suite</a> (std::string_view <a href="#a5f1698a93a8b09c39b87c23452335646">name</a>, Callable_T&amp;&amp; callable,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">200</span><span class="doxyLineContent"><span class="doxyHighlight">                 Args_T&amp;&amp;... arguments)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">201</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">202</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite</a> (<a href="#a5f1698a93a8b09c39b87c23452335646">name</a>, std::forward&lt;Callable_T&gt; (callable),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">203</span><span class="doxyLineContent"><span class="doxyHighlight">               std::forward&lt;Args_T&gt; (arguments)...);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">204</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite</a> and <a href="#a5f1698a93a8b09c39b87c23452335646">name</a>.</p>


<p>Referenced by <a href="#a4069fe957bbc7a9217ca2dd4d2034a97">add_suite</a>, <a href="#a19160679a4fe484fc9f8f76ed3408762">link_static_suite</a>, <a href="#a0e478c394741ff78f65a7e2c0822ba50">list_test_case</a>, <a href="#aa34a0418d54c633630a089eb2b5a61ee">operator=</a> and <a href="#a1dcc8f8d7f80044c67c492a1aebe3043">register_suite</a>.</p>

</div>
</div>

### suites\_count {#a6ed3a02ced62ed475c75678cd9e91be1}

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
<dt class="doxyXrefSectTitle"><a href=/micro-test-plus-xpack/docs/api/pages/deprecated/#_deprecated000118>Deprecated</a></dt>
<dd class="doxyXrefSectDescription">
<p>use <a href="#a9484b22aa909151712144cd39130187a">added_suites_count()</a> or <a href="#ac29e4b993bb3fe795eb8900231cbf5c4">total_suites_count()</a> (since 6.0.0)</p>
</dd>
</dl>
</div>

<p>Returns <span class="doxyComputerOutput"><a href="#a9484b22aa909151712144cd39130187a">added_suites_count()</a></span> plus one, for the top suite, as before the rename.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00810">810</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00866">866</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a6ed3a02ced62ed475c75678cd9e91be1">866</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a6ed3a02ced62ed475c75678cd9e91be1">runner::suites_count</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">867</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">868</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a9484b22aa909151712144cd39130187a">added_suites_count</a> () + 1;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">869</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a9484b22aa909151712144cd39130187a">added_suites_count</a>.</p>

</div>
</div>

### timings {#af314280f14d61d37da276567685ec2a8}

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


<p>Returns the internal stopwatch of the session, started by <span class="doxyComputerOutput"><a href="#a39ee9ec53f8df687cd84092de5118592">initialise()</a></span> and stopped at the end of <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span>; the elapsed time is complete only after <span class="doxyComputerOutput"><a href="#a700e3ef1f955492cd84235bd388dcdf2">run_suites()</a></span> has returned. In v5.0.1, the returned class was <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-deprecated/#ga53a6bc7f86b15378c8296b3647e7013f">detail::timestamps</a></span>, now a deprecated alias; only its read-only members are kept. The timings are internal; the elapsed times are shown by the reporters.</p>


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
<dt class="doxyXrefSectTitle"><a href=/micro-test-plus-xpack/docs/api/pages/deprecated/#_deprecated000119>Deprecated</a></dt>
<dd class="doxyXrefSectDescription">
<p>the timings are internal (since 6.0.0)</p>
</dd>
</dl>
</div>

<p>Returns a const reference to the <span class="doxyComputerOutput">stopwatch</span> member.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00892">892</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h/#l00133">133</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h">runner-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#af314280f14d61d37da276567685ec2a8">133</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#af314280f14d61d37da276567685ec2a8">runner::timings</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">134</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">135</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a13b3cf196a1b12cb90a12c4b84223d15">stopwatch_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">136</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a13b3cf196a1b12cb90a12c4b84223d15">stopwatch_</a>.</p>

</div>
</div>

### timings {#a7d3ccfaf760cb2f4ace586c222b22244}

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


<p>Kept for the v5.0.1 code that binds a non-<span class="doxyComputerOutput">const</span> reference (<span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-deprecated/#ga53a6bc7f86b15378c8296b3647e7013f">detail::timestamps</a>&amp; t = tr.timings ();</span>). The test code must not start or stop the stopwatch through it, since the reporters show its elapsed time.</p>


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
<dt class="doxyXrefSectTitle"><a href=/micro-test-plus-xpack/docs/api/pages/deprecated/#_deprecated000120>Deprecated</a></dt>
<dd class="doxyXrefSectDescription">
<p>the timings are internal (since 6.0.0)</p>
</dd>
</dl>
</div>

<p>Returns a reference to the <span class="doxyComputerOutput">stopwatch</span> member.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00910">910</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h/#l00144">144</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h">runner-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a7d3ccfaf760cb2f4ace586c222b22244">144</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#af314280f14d61d37da276567685ec2a8">runner::timings</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">145</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">146</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a13b3cf196a1b12cb90a12c4b84223d15">stopwatch_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">147</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a13b3cf196a1b12cb90a12c4b84223d15">stopwatch_</a>.</p>

</div>
</div>

### verbosity {#a94a9df0418776ebce476cd9a2e4f591f}

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
<dt class="doxyXrefSectTitle"><a href=/micro-test-plus-xpack/docs/api/pages/deprecated/#_deprecated000116>Deprecated</a></dt>
<dd class="doxyXrefSectDescription">
<p>use <a href="#a1dd0221dca8e7382f0b625ff6316ed92">verbosity_level()</a> (since 6.0.0)</p>
</dd>
</dl>
</div>

<p>Forwards to <span class="doxyComputerOutput"><a href="#a1dd0221dca8e7382f0b625ff6316ed92">verbosity_level()</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00741">741</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h/#l00110">110</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h">runner-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a94a9df0418776ebce476cd9a2e4f591f">110</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a94a9df0418776ebce476cd9a2e4f591f">runner::verbosity</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight"> -&gt; <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914b">micro_test_plus::verbosity</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">111</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">112</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a1dd0221dca8e7382f0b625ff6316ed92">verbosity_level</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">113</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a1dd0221dca8e7382f0b625ff6316ed92">verbosity_level</a>.</p>

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
