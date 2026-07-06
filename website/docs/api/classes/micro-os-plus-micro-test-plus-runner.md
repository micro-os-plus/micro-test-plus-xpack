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

<div class="doxyIncludesList">#include &lt;<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>&gt;
</div>

## Base class

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node">test_node</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Base class for runners and runable tests. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Derived Classes

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-runner">static_runner</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>A <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">runner</a></span> variant that also manages statically-registered test suites. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-runner/#details">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a47a11b38ecca99760dd8078b5175041f">~runner</a> () override</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Destructor for the runner class. <a href="#a47a11b38ecca99760dd8078b5175041f">More...</a></p>
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

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a7f8403f1ccc6a0e8171ef077bcd9cbd4">exit_code</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns 0 if all tests were successful, 1 otherwise. <a href="#a7f8403f1ccc6a0e8171ef077bcd9cbd4">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class <a href="#a330a6a2c24a6759e4cce1269942b9c88">suite</a> &amp;</td>
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
<td class="doxyMemberIndexItemType" align="left" valign="top">const char *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1565ede2ab1141b2e3db2ea5513002a1">name</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Gets the node name. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1565ede2ab1141b2e3db2ea5513002a1">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class reporter &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a28e8cf878d98f6cba575a58189c39a56">reporter</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns a reference to the test reporter. <a href="#a28e8cf878d98f6cba575a58189c39a56">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a330a6a2c24a6759e4cce1269942b9c88">suite</a> (const char *name, Callable_T &amp;&amp;callable, Args_T &amp;&amp;... arguments)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Adds a test suite to the runner. <a href="#a330a6a2c24a6759e4cce1269942b9c88">More...</a></p>
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
<p>Returns the count of test suites. <a href="#a6ed3a02ced62ed475c75678cd9e91be1">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps">detail::timestamps</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a9c98d2b38f64305b6042e81a3e468540">timings</a> () const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Gets the timings for this runner (const overload). <a href="#a9c98d2b38f64305b6042e81a3e468540">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps">detail::timestamps</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a256d5fafb7231399ca0128ec68deff75">timings</a> () noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Gets the timings for this runner. <a href="#a256d5fafb7231399ca0128ec68deff75">More...</a></p>
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
<p>Returns the total count of registered test suites. <a href="#ac29e4b993bb3fe795eb8900231cbf5c4">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const runner_totals &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a722406c83eaec234b23b1b9a97a97010">totals</a> () const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Gets the totals for the test (const overload). <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a722406c83eaec234b23b1b9a97a97010">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">runner_totals &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1e053f72527192d324e4d0130b7017d3">totals</a> () noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Gets the totals for the test. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1e053f72527192d324e4d0130b7017d3">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#abc9182d5e12609158d936f312a83f53c">register_suite_</a> (std::unique_ptr&lt; class suite &gt; suite)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Registers a test suite with the runner. <a href="#abc9182d5e12609158d936f312a83f53c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ad02a7dd243b31ec630484b6397eb506d">run_suites_</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Runs all registered test suites. <a href="#ad02a7dd243b31ec630484b6397eb506d">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Protected Member Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">std::vector&lt; std::unique_ptr&lt; class <a href="#a330a6a2c24a6759e4cce1269942b9c88">suite</a> &gt; &gt;</td>
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
<td class="doxyMemberIndexItemType" align="left" valign="top">const char *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a61ac0275108c9f9b2348c1c5fc8af104">name_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The test node name. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a61ac0275108c9f9b2348c1c5fc8af104">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">std::unique_ptr&lt; class <a href="#a28e8cf878d98f6cba575a58189c39a56">reporter</a> &gt;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ace4da8161152a82e4ffa9c6d50917088">reporter_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Pointer to the test reporter used for outputting test results. <a href="#ace4da8161152a82e4ffa9c6d50917088">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps">detail::timestamps</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a7cdc57b32f1d1989fde8a119905a0bc7">timings_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Timings for this runner. <a href="#a7cdc57b32f1d1989fde8a119905a0bc7">More...</a></p>
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
<td class="doxyMemberIndexItemType" align="left" valign="top">runner_totals</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1af301da2bcb0659c40a472589edc194">totals_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Totals for the test node, including nested cases. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1af301da2bcb0659c40a472589edc194">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>The test runner for the µTest++ framework.</p>


<p>The <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">runner</a></span> class is responsible for managing the registration and execution of test suites within the µTest++ framework. It maintains a collection of test suites, each of which registers itself automatically upon construction, enabling seamless integration and execution of tests across different components and folders of a project.</p>


<p>The test runner provides methods for initialising the test environment, registering test suites, retrieving the runner's name, and determining the overall test result via an exit code. It also offers an abort mechanism for terminating test execution in exceptional circumstances.</p>


<p>All members and methods are defined within the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a></span> namespace, ensuring clear separation from user code and minimising the risk of naming conflicts.</p>


<p>Definition at line 110 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


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


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] top_suite_name</td>
<td class="doxyParamItemDescription"><p>The name given to the implicit top suite. Defaults to an empty string.</p></td>
</tr>
</table>
</dd>
</dl>

<div class="doxyXrefSect">
<dl class="doxyXrefSectList">
<dt class="doxyXrefSectTitle"><a href=/micro-test-plus-xpack/docs/api/pages/deprecated/#_deprecated000025>Deprecated</a></dt>
<dd class="doxyXrefSectDescription">
<p>Use the anonymous constructor.</p>
</dd>
</dl>
</div>

<p>The constructor initialises a new <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">runner</a></span> instance together with its top suite (<span class="doxyComputerOutput"><a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a></span>). If tracing is enabled, it outputs the function signature for diagnostic purposes.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00129">129</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00139">139</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a10788baa079e19676a8cdbaa253285dc">139</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a5e2001730fd3659e9045fcc5cc668f07">runner::runner</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* top_suite_name)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">140</span><span class="doxyLineContent"><span class="doxyHighlight">      : <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1f293a9e44f60ee340c18d9e7efa0390">test_node</a>{ </span><span class="doxyHighlightStringLiteral">"runner"</span><span class="doxyHighlight"> }, <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>{ top_suite_name, *this }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">141</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">142</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_TRACE) \</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">143</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">    &amp;&amp; defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">144</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">145</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">146</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">147</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">148</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">149</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">150</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s '%s'\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1565ede2ab1141b2e3db2ea5513002a1">name</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">151</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">152</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">153</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">154</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">155</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1f293a9e44f60ee340c18d9e7efa0390">micro_os_plus::micro_test_plus::detail::test_node::test_node</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1565ede2ab1141b2e3db2ea5513002a1">micro_os_plus::micro_test_plus::detail::test_node::name</a> and <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>.</p>

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

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00134">134</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


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

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00139">139</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


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


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<p>The constructor initialises a new <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">runner</a></span> instance together with its top suite (<span class="doxyComputerOutput"><a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a></span>). If tracing is enabled, it outputs the function signature for diagnostic purposes.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00119">119</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00116">116</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a5e2001730fd3659e9045fcc5cc668f07">116</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a5e2001730fd3659e9045fcc5cc668f07">runner::runner</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) : <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1f293a9e44f60ee340c18d9e7efa0390">test_node</a>{ </span><span class="doxyHighlightStringLiteral">"runner"</span><span class="doxyHighlight"> }, <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>{ </span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight">, *this }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">117</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">118</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_TRACE) \</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">119</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">    &amp;&amp; defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">120</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">121</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">122</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">123</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">124</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">125</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">126</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s '%s'\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1565ede2ab1141b2e3db2ea5513002a1">name</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">127</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">128</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">129</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">130</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">131</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1f293a9e44f60ee340c18d9e7efa0390">micro_os_plus::micro_test_plus::detail::test_node::test_node</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1565ede2ab1141b2e3db2ea5513002a1">micro_os_plus::micro_test_plus::detail::test_node::name</a> and <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>.</p>


<p>Referenced by <a href="#adbe02fed3c414adf001d856ab390e000">runner</a>, <a href="#a09acf1e03953d8017e56c8b5e38b879a">runner</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-runner/#a1e3c2cbe731c469a93fcad9e574e717a">micro_os_plus::micro_test_plus::static_runner::static_runner</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-runner/#a83055372bf85fcb9ff002418a43ea8d0">micro_os_plus::micro_test_plus::static_runner::static_runner</a>, <a href="#a549524d15dc1eb5e6b4eb4bdd2af7b6b">operator=</a>, <a href="#aa34a0418d54c633630a089eb2b5a61ee">operator=</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-runner/#af3dfbf384a9736f9e150c25e661bcb38">micro_os_plus::micro_test_plus::static_runner::operator=</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-runner/#a6984a307a2f487cea3eeeb36c1422020">micro_os_plus::micro_test_plus::static_runner::register_static_suite</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Destructor

### \~runner() {#a47a11b38ecca99760dd8078b5175041f}

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
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel virtual">virtual</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Destructor for the runner class.</p>


<p>The <span class="doxyComputerOutput"><a href="#ace4da8161152a82e4ffa9c6d50917088">reporter_</a></span> unique pointer is released automatically. If tracing is enabled, the function signature is output for diagnostic purposes.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00158">158</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00162">162</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a47a11b38ecca99760dd8078b5175041f">162</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a47a11b38ecca99760dd8078b5175041f">runner::~runner</a> ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">163</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">164</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_TRACE) \</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">165</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">    &amp;&amp; defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">166</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">167</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">168</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">169</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// reporter_ is a unique_ptr; destroyed automatically.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">170</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

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

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00145">145</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


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

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00152">152</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<p>References <a href="#a5e2001730fd3659e9045fcc5cc668f07">runner</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">micro_os_plus::micro_test_plus::reflection::source_location::current</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1565ede2ab1141b2e3db2ea5513002a1">micro_os_plus::micro_test_plus::detail::test_node::name</a>, <a href="#abc9182d5e12609158d936f312a83f53c">register_suite_</a>, <a href="#a28e8cf878d98f6cba575a58189c39a56">reporter</a>, <a href="#ad02a7dd243b31ec630484b6397eb506d">run_suites_</a>, <a href="#a330a6a2c24a6759e4cce1269942b9c88">suite</a>, <a href="#a6ed3a02ced62ed475c75678cd9e91be1">suites_count</a> and <a href="#a256d5fafb7231399ca0128ec68deff75">timings</a>.</p>

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
<dd><p>Nothing.</p></dd>
</dl>


<p>Prints the source location of the fatal error to <span class="doxyComputerOutput">stderr</span> and then terminates the process via <span class="doxyComputerOutput">::abort()</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00210">210</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00440">440</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a7bc806540e65c21095ef1ea1ef970db2">440</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a7bc806540e65c21095ef1ea1ef970db2">runner::abort</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; sl)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">441</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">442</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_TRACE) \</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">443</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">    &amp;&amp; defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">444</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">445</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">446</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">447</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">448</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">449</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">450</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">451</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">452</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">453</span><span class="doxyLineContent"><span class="doxyHighlight">    fprintf (stderr, </span><span class="doxyHighlightStringLiteral">"\nerror: test execution aborted at %s:%u\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">454</span><span class="doxyLineContent"><span class="doxyHighlight">             <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/reflection/#afc93799846770e521c4721d0de0a81cc">reflection::short_name</a> (sl.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#a3df499675aacb7ab9192cfb9a5371874">file_name</a> ()), sl.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#aab9d006004611ac0526852a09f675c66">line</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">455</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">456</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">457</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">458</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">459</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a7bc806540e65c21095ef1ea1ef970db2">::abort</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">460</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a7bc806540e65c21095ef1ea1ef970db2">abort</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#a3df499675aacb7ab9192cfb9a5371874">micro_os_plus::micro_test_plus::reflection::source_location::file_name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#aab9d006004611ac0526852a09f675c66">micro_os_plus::micro_test_plus::reflection::source_location::line</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/reflection/#afc93799846770e521c4721d0de0a81cc">micro_os_plus::micro_test_plus::reflection::short_name</a>.</p>


<p>Referenced by <a href="#a7bc806540e65c21095ef1ea1ef970db2">abort</a>.</p>

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

<p>Returns 0 if all tests were successful, 1 otherwise.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Integer exit code representing the overall test result.</p></dd>
</dl>


<p>Finalises the top suite by recording its end timestamp and notifying the reporter, then accumulates its totals into the runner totals. Subsequently invokes <span class="doxyComputerOutput"><a href="#ad02a7dd243b31ec630484b6397eb506d">run_suites_()</a></span> to sort, execute, and accumulate all registered child suites. Finally, records the session end timestamp, notifies the reporter, and returns <span class="doxyComputerOutput">0</span> if all checks passed or <span class="doxyComputerOutput">1</span> otherwise.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00180">180</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00393">393</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a7f8403f1ccc6a0e8171ef077bcd9cbd4">393</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a7f8403f1ccc6a0e8171ef077bcd9cbd4">runner::exit_code</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">394</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">395</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_TRACE) \</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">396</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">    &amp;&amp; defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">397</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">398</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">399</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">400</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#ace4da8161152a82e4ffa9c6d50917088">reporter_</a> == </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">401</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">402</span><span class="doxyLineContent"><span class="doxyHighlight">        fprintf (stderr, </span><span class="doxyHighlightStringLiteral">"error: test runner not initialised\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">403</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> 1;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">404</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">405</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">406</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>.timings ().timestamp_end ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">407</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#ace4da8161152a82e4ffa9c6d50917088">reporter_</a>-&gt;end_suite (<a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">408</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1af301da2bcb0659c40a472589edc194">totals_</a> += <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>.totals ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">409</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">410</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#ad02a7dd243b31ec630484b6397eb506d">run_suites_</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">411</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">412</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a7cdc57b32f1d1989fde8a119905a0bc7">timings_</a>.timestamp_end ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">413</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#ace4da8161152a82e4ffa9c6d50917088">reporter_</a>-&gt;end_session (*</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">414</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">415</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> result = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1af301da2bcb0659c40a472589edc194">totals_</a>.was_successful () ? 0 : 1;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">416</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">417</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_TRACE) \</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">418</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">    &amp;&amp; defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">419</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">420</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">421</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">422</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">423</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">424</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">425</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s -&gt; %d\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__, result);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">426</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">427</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">428</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">429</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">430</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">431</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> result;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">432</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#ace4da8161152a82e4ffa9c6d50917088">reporter_</a>, <a href="#ad02a7dd243b31ec630484b6397eb506d">run_suites_</a>, <a href="#a7cdc57b32f1d1989fde8a119905a0bc7">timings_</a>, <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1af301da2bcb0659c40a472589edc194">micro_os_plus::micro_test_plus::detail::test_node::totals_</a>.</p>

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


<p>Captures command-line arguments, selects the reporter implementation (<span class="doxyComputerOutput">human</span> or <span class="doxyComputerOutput">tap</span>), starts session timing, and emits the initial reporter notifications for the session and top suite.</p>


<p>If the top suite name is not provided, it attempts to derive a name from <span class="doxyComputerOutput">argv[0]</span> or defaults to "default suite".</p>


<p>If tracing is enabled, the command-line arguments are also logged for diagnostic purposes.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00170">170</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00191">191</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#acfabd0e10d233ad305b6f4fc125a97f2">191</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#acfabd0e10d233ad305b6f4fc125a97f2">runner::initialise</a> (</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> argc, </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* argv[], </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* top_suite_name)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">192</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">193</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_TRACE) \</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">194</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">    &amp;&amp; defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">195</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">196</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">197</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">198</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if !(defined(MICRO_OS_PLUS_INCLUDE_STARTUP) &amp;&amp; defined(MICRO_OS_PLUS_TRACE))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">199</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_DEBUG)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">200</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"argv["</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">201</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> i = 0; i &lt; argc; ++i)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">202</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">203</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (i &gt; 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">204</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">205</span><span class="doxyLineContent"><span class="doxyHighlight">            trace::printf (</span><span class="doxyHighlightStringLiteral">", "</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">206</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">207</span><span class="doxyLineContent"><span class="doxyHighlight">        trace::printf (</span><span class="doxyHighlightStringLiteral">"'%s'"</span><span class="doxyHighlight">, argv[i]);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">208</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">209</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::puts (</span><span class="doxyHighlightStringLiteral">"]"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">210</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(MICRO_OS_PLUS_DEBUG)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">211</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// !defined(MICRO_OS_PLUS_INCLUDE_STARTUP)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">212</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">213</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (strlen (top_suite_name) &gt; 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">214</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">215</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// If provided by this call, use it, possibly override the</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">216</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// deprecated constructor.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">217</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a401e4e098f0ceba7f21a3a5bf1ea89e3">top_suite_name_</a> = top_suite_name;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">218</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>.name (<a href="#a401e4e098f0ceba7f21a3a5bf1ea89e3">top_suite_name_</a>.c_str ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">219</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">220</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (strlen (<a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>.name ()) == 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">221</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">222</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// If not provided by the constructor or by this call, try to extract a</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">223</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// name from argv[0], which is commonly the executable name. If that</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">224</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// fails, use a default name.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">225</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (argc &gt; 0 &amp;&amp; argv != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight"> &amp;&amp; argv[0] != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">226</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">227</span><span class="doxyLineContent"><span class="doxyHighlight">            std::string_view top_suite_name_view{ <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-utility-functions/#ga791f22f0c85b6436c9016821907b0653">utility::extract_file_name</a> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">228</span><span class="doxyLineContent"><span class="doxyHighlight">                argv[0]) };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">229</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">230</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> dot_pos = top_suite_name_view.rfind (</span><span class="doxyHighlightCharLiteral">'.'</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">231</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (dot_pos != std::string_view::npos)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">232</span><span class="doxyLineContent"><span class="doxyHighlight">              {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">233</span><span class="doxyLineContent"><span class="doxyHighlight">                top_suite_name_view = top_suite_name_view.substr (0, dot_pos);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">234</span><span class="doxyLineContent"><span class="doxyHighlight">              }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">235</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">236</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="#a401e4e098f0ceba7f21a3a5bf1ea89e3">top_suite_name_</a> = top_suite_name_view;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">237</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">238</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">239</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">240</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="#a401e4e098f0ceba7f21a3a5bf1ea89e3">top_suite_name_</a> = </span><span class="doxyHighlightStringLiteral">"default suite"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">241</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">242</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>.name (<a href="#a401e4e098f0ceba7f21a3a5bf1ea89e3">top_suite_name_</a>.c_str ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">243</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">244</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">245</span><span class="doxyLineContent"><span class="doxyHighlight">    std::vector&lt;std::string_view&gt; argvs (argv, argv + argc);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">246</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">247</span><span class="doxyLineContent"><span class="doxyHighlight">    std::string_view reporter_name{ </span><span class="doxyHighlightStringLiteral">"tap"</span><span class="doxyHighlight"> };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">248</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> std::string_view reporter_prefix{ </span><span class="doxyHighlightStringLiteral">"--reporter="</span><span class="doxyHighlight"> };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">249</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> i = 0; i &lt; argvs.size (); ++i)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">250</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">251</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (argvs[i].starts_with (reporter_prefix))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">252</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">253</span><span class="doxyLineContent"><span class="doxyHighlight">            reporter_name = argvs[i].substr (reporter_prefix.size ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">254</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">255</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (argvs[i]</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">256</span><span class="doxyLineContent"><span class="doxyHighlight">                 == reporter_prefix.substr (0, reporter_prefix.size () - 1))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">257</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">258</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (i + 1 &lt; argvs.size ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">259</span><span class="doxyLineContent"><span class="doxyHighlight">              {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">260</span><span class="doxyLineContent"><span class="doxyHighlight">                reporter_name = argvs[++i];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">261</span><span class="doxyLineContent"><span class="doxyHighlight">              }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">262</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">263</span><span class="doxyLineContent"><span class="doxyHighlight">              {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">264</span><span class="doxyLineContent"><span class="doxyHighlight">                fprintf (stderr, </span><span class="doxyHighlightStringLiteral">"error: --reporter option requires a "</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">265</span><span class="doxyLineContent"><span class="doxyHighlight">                                 </span><span class="doxyHighlightStringLiteral">"reporter name argument\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">266</span><span class="doxyLineContent"><span class="doxyHighlight">                exit (1);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">267</span><span class="doxyLineContent"><span class="doxyHighlight">              }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">268</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">269</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">270</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">271</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Initialise and configure the reporter.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">272</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (reporter_name == </span><span class="doxyHighlightStringLiteral">"human"</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">273</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">274</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#ace4da8161152a82e4ffa9c6d50917088">reporter_</a> = std::make_unique&lt;reporter_human&gt; (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">275</span><span class="doxyLineContent"><span class="doxyHighlight">            std::make_unique&lt;std::vector&lt;std::string_view&gt;&gt; (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">276</span><span class="doxyLineContent"><span class="doxyHighlight">                std::move (argvs)));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">277</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">278</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (reporter_name == </span><span class="doxyHighlightStringLiteral">"tap"</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">279</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">280</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#ace4da8161152a82e4ffa9c6d50917088">reporter_</a> = std::make_unique&lt;reporter_tap&gt; (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">281</span><span class="doxyLineContent"><span class="doxyHighlight">            std::make_unique&lt;std::vector&lt;std::string_view&gt;&gt; (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">282</span><span class="doxyLineContent"><span class="doxyHighlight">                std::move (argvs)));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">283</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">284</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">285</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">286</span><span class="doxyLineContent"><span class="doxyHighlight">        fprintf (stderr, </span><span class="doxyHighlightStringLiteral">"error: unknown reporter '%.*s'\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">287</span><span class="doxyLineContent"><span class="doxyHighlight">                 </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (reporter_name.size ()),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">288</span><span class="doxyLineContent"><span class="doxyHighlight">                 reporter_name.data ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">289</span><span class="doxyLineContent"><span class="doxyHighlight">        exit (1);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">290</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">291</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">292</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">293</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">294</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a7cdc57b32f1d1989fde8a119905a0bc7">timings_</a>.timestamp_begin ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">295</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#ace4da8161152a82e4ffa9c6d50917088">reporter_</a>-&gt;begin_session (*</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">296</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">297</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>.timings ().timestamp_begin ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">298</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#ace4da8161152a82e4ffa9c6d50917088">reporter_</a>-&gt;begin_suite (<a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">299</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">300</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">301</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-utility-functions/#ga791f22f0c85b6436c9016821907b0653">micro_os_plus::micro_test_plus::utility::extract_file_name</a>, <a href="#ace4da8161152a82e4ffa9c6d50917088">reporter_</a>, <a href="#a7cdc57b32f1d1989fde8a119905a0bc7">timings_</a>, <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a> and <a href="#a401e4e098f0ceba7f21a3a5bf1ea89e3">top_suite_name_</a>.</p>

</div>
</div>

### name() {#a1565ede2ab1141b2e3db2ea5513002a1}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const char * micro_os_plus::micro_test_plus::detail::test_node::name (void)</td>
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
<dd><p>A pointer to the null-terminated test node name.</p></dd>
</dl>


<p>Returns a pointer to the null-terminated name stored in <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a61ac0275108c9f9b2348c1c5fc8af104">name_</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00194">194</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00092">92</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1565ede2ab1141b2e3db2ea5513002a1">92</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1565ede2ab1141b2e3db2ea5513002a1">test_node::name</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">93</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">94</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a61ac0275108c9f9b2348c1c5fc8af104">name_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">95</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a61ac0275108c9f9b2348c1c5fc8af104">micro_os_plus::micro_test_plus::detail::test_node::name_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable/#a1e123b99ea9036b71ceeadc05606284b">micro_os_plus::micro_test_plus::detail::runnable&lt; Self_T &gt;::runnable</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a16fe4a8c3110e27cfd89e8c57bcfd6ea">micro_os_plus::micro_test_plus::detail::runnable_base::runnable_base</a>, <a href="#a10788baa079e19676a8cdbaa253285dc">runner</a>, <a href="#a5e2001730fd3659e9045fcc5cc668f07">runner</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-runner/#a1e3c2cbe731c469a93fcad9e574e717a">micro_os_plus::micro_test_plus::static_runner::static_runner</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-runner/#a83055372bf85fcb9ff002418a43ea8d0">micro_os_plus::micro_test_plus::static_runner::static_runner</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1f293a9e44f60ee340c18d9e7efa0390">micro_os_plus::micro_test_plus::detail::test_node::test_node</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a60ea42dbf8ecbe8b4c5fcfedb52e857c">micro_os_plus::micro_test_plus::detail::runnable_base::after_subtest_create_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a59da3337bb7a2d1bc89406f548131d00">micro_os_plus::micro_test_plus::reporter_human::begin_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a27a5c6eca6a4beb82466448bfe5c44e9">micro_os_plus::micro_test_plus::reporter_tap::begin_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a172a7a10a5aa2bd47dc6e7dde903cbbd">micro_os_plus::micro_test_plus::reporter_human::begin_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#ae118be849ab3ff75ab88ff4f54f54be0">micro_os_plus::micro_test_plus::reporter_tap::begin_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a052138e5f517b578df99204c8d88213e">micro_os_plus::micro_test_plus::reporter_human::end_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a79c7928d44d70b8fe5bf993775517e63">micro_os_plus::micro_test_plus::reporter_tap::end_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#ac0a6d2bda91a9afa71346eef59c7f35e">micro_os_plus::micro_test_plus::reporter_human::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a8649b62ba8f7ff88501450c5f939ab6d">micro_os_plus::micro_test_plus::reporter_tap::end_suite</a>, <a href="#aa34a0418d54c633630a089eb2b5a61ee">operator=</a> and <a href="#a330a6a2c24a6759e4cce1269942b9c88">suite</a>.</p>

</div>
</div>

### reporter() {#a28e8cf878d98f6cba575a58189c39a56}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">class reporter &amp; micro_os_plus::micro_test_plus::runner::reporter (void)</td>
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

<p>Returns a reference to the test reporter.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to the test reporter.</p></dd>
</dl>


<p>Returns a reference to the reporter object stored in the unique pointer.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00234">234</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h/#l00077">77</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h">runner-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a28e8cf878d98f6cba575a58189c39a56">77</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a28e8cf878d98f6cba575a58189c39a56">runner::reporter</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">78</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">79</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *<a href="#ace4da8161152a82e4ffa9c6d50917088">reporter_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">80</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#ace4da8161152a82e4ffa9c6d50917088">reporter_</a>.</p>


<p>Referenced by <a href="#aa34a0418d54c633630a089eb2b5a61ee">operator=</a>.</p>

</div>
</div>

### suite() {#a330a6a2c24a6759e4cce1269942b9c88}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;typename Callable_T, typename... Args_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::runner::suite (const char * name, Callable_T &amp;&amp; callable, Args_T &amp;&amp;... arguments)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Adds a test suite to the runner.</p>


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
<td class="doxyParamItemName">[in] name</td>
<td class="doxyParamItemDescription"><p>The test suite name or description, used in reports.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] callable</td>
<td class="doxyParamItemDescription"><p>A generic callable object, usually a lambda, invoked to perform the test suite.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] arguments</td>
<td class="doxyParamItemDescription"><p>A possibly empty list of arguments to be passed to the callable.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Constructs a <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a></span> object on the heap, binding the callable and any additional arguments, then transfers ownership to the runner via <span class="doxyComputerOutput"><a href="#abc9182d5e12609158d936f312a83f53c">register_suite_()</a></span>. The suite runs immediately as part of the registration process.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00198">198</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h/#l00113">113</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h">runner-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a330a6a2c24a6759e4cce1269942b9c88">113</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a330a6a2c24a6759e4cce1269942b9c88">runner::suite</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1565ede2ab1141b2e3db2ea5513002a1">name</a>, Callable_T&amp;&amp; callable,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">114</span><span class="doxyLineContent"><span class="doxyHighlight">                 Args_T&amp;&amp;... arguments)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">115</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">116</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_TRACE) \</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">117</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">    &amp;&amp; defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">118</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">119</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">120</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">121</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">122</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">123</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">124</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s '%s'\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1565ede2ab1141b2e3db2ea5513002a1">name</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">125</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">126</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">127</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">128</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">129</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">130</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> child_suite = std::make_unique&lt;class suite&gt; (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">131</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1565ede2ab1141b2e3db2ea5513002a1">name</a>, *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">, std::forward&lt;Callable_T&gt; (callable),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">132</span><span class="doxyLineContent"><span class="doxyHighlight">        std::forward&lt;Args_T&gt; (arguments)...);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">133</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">134</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#abc9182d5e12609158d936f312a83f53c">register_suite_</a> (std::move (child_suite));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">135</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1565ede2ab1141b2e3db2ea5513002a1">micro_os_plus::micro_test_plus::detail::test_node::name</a> and <a href="#abc9182d5e12609158d936f312a83f53c">register_suite_</a>.</p>


<p>Referenced by <a href="#aa34a0418d54c633630a089eb2b5a61ee">operator=</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-runner/#af3dfbf384a9736f9e150c25e661bcb38">micro_os_plus::micro_test_plus::static_runner::operator=</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-runner/#a6984a307a2f487cea3eeeb36c1422020">micro_os_plus::micro_test_plus::static_runner::register_static_suite</a> and <a href="#abc9182d5e12609158d936f312a83f53c">register_suite_</a>.</p>

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

<p>Returns the count of test suites.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The number of test suites, including the top one.</p></dd>
</dl>


<p>Returns the number of registered child suites plus one, accounting for the top suite.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00264">264</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00468">468</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a6ed3a02ced62ed475c75678cd9e91be1">468</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a6ed3a02ced62ed475c75678cd9e91be1">runner::suites_count</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">469</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">470</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a>.size () + 1;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">471</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a>.</p>


<p>Referenced by <a href="#aa34a0418d54c633630a089eb2b5a61ee">operator=</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-runner/#ac17e3110a8cd7f71a39b932cc74cbcad">micro_os_plus::micro_test_plus::static_runner::run_suites_</a>, <a href="#ac29e4b993bb3fe795eb8900231cbf5c4">total_suites_count</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-runner/#aada4bf589cf8316e3987084de0d8fbca">micro_os_plus::micro_test_plus::static_runner::total_suites_count</a>.</p>

</div>
</div>

### timings() {#a9c98d2b38f64305b6042e81a3e468540}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const detail::timestamps &amp; micro_os_plus::micro_test_plus::runner::timings ()</td>
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

<p>Gets the timings for this runner (const overload).</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A const reference to the timestamps instance.</p></dd>
</dl>


<p>Returns a const reference to the <span class="doxyComputerOutput">timestamps</span> member.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00254">254</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h/#l00097">97</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h">runner-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a9c98d2b38f64305b6042e81a3e468540">97</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a256d5fafb7231399ca0128ec68deff75">runner::timings</a> () const noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">98</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">99</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a7cdc57b32f1d1989fde8a119905a0bc7">timings_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">100</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a7cdc57b32f1d1989fde8a119905a0bc7">timings_</a>.</p>

</div>
</div>

### timings() {#a256d5fafb7231399ca0128ec68deff75}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">detail::timestamps &amp; micro_os_plus::micro_test_plus::runner::timings ()</td>
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

<p>Gets the timings for this runner.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A reference to the timestamps instance.</p></dd>
</dl>


<p>Returns a reference to the <span class="doxyComputerOutput">timestamps</span> member.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00244">244</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h/#l00087">87</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h">runner-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a256d5fafb7231399ca0128ec68deff75">87</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a256d5fafb7231399ca0128ec68deff75">runner::timings</a> () noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">88</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">89</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a7cdc57b32f1d1989fde8a119905a0bc7">timings_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">90</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a7cdc57b32f1d1989fde8a119905a0bc7">timings_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a3118ff89506858505f18e8fd368baffc">micro_os_plus::micro_test_plus::reporter_human::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a9a224d34b068e1698c00633ae2341e7f">micro_os_plus::micro_test_plus::reporter_tap::end_session</a> and <a href="#aa34a0418d54c633630a089eb2b5a61ee">operator=</a>.</p>

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
<span class="doxyMemberLabel virtual">virtual</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Returns the total count of registered test suites.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The total number of test suites managed by this runner.</p></dd>
</dl>


<p>For the base <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">runner</a></span>, the total suite count equals <span class="doxyComputerOutput"><a href="#a6ed3a02ced62ed475c75678cd9e91be1">suites_count()</a></span>, as there are no additional static suites.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00224">224</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00479">479</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ac29e4b993bb3fe795eb8900231cbf5c4">479</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ac29e4b993bb3fe795eb8900231cbf5c4">runner::total_suites_count</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">480</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">481</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a6ed3a02ced62ed475c75678cd9e91be1">suites_count</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">482</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a6ed3a02ced62ed475c75678cd9e91be1">suites_count</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a3118ff89506858505f18e8fd368baffc">micro_os_plus::micro_test_plus::reporter_human::end_session</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a9a224d34b068e1698c00633ae2341e7f">micro_os_plus::micro_test_plus::reporter_tap::end_session</a>.</p>

</div>
</div>

### totals() {#a722406c83eaec234b23b1b9a97a97010}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const runner_totals &amp; micro_os_plus::micro_test_plus::detail::test_node::totals ()</td>
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

<p>Gets the totals for the test (const overload).</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A const reference to the <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runner-totals">runner_totals</a> instance.</p></dd>
</dl>


<p>Returns a const reference to the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runner-totals">runner_totals</a></span> member.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00215">215</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00112">112</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a722406c83eaec234b23b1b9a97a97010">112</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1e053f72527192d324e4d0130b7017d3">test_node::totals</a> () const noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">113</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">114</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1af301da2bcb0659c40a472589edc194">totals_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">115</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1af301da2bcb0659c40a472589edc194">micro_os_plus::micro_test_plus::detail::test_node::totals_</a>.</p>

</div>
</div>

### totals() {#a1e053f72527192d324e4d0130b7017d3}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">runner_totals &amp; micro_os_plus::micro_test_plus::detail::test_node::totals ()</td>
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

<p>Gets the totals for the test.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A reference to the <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runner-totals">runner_totals</a> instance.</p></dd>
</dl>


<p>Returns a reference to the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runner-totals">runner_totals</a></span> member.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00205">205</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00102">102</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1e053f72527192d324e4d0130b7017d3">102</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1e053f72527192d324e4d0130b7017d3">test_node::totals</a> () noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">103</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">104</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1af301da2bcb0659c40a472589edc194">totals_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">105</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1af301da2bcb0659c40a472589edc194">micro_os_plus::micro_test_plus::detail::test_node::totals_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a60ea42dbf8ecbe8b4c5fcfedb52e857c">micro_os_plus::micro_test_plus::detail::runnable_base::after_subtest_create_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a3118ff89506858505f18e8fd368baffc">micro_os_plus::micro_test_plus::reporter_human::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a9a224d34b068e1698c00633ae2341e7f">micro_os_plus::micro_test_plus::reporter_tap::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a052138e5f517b578df99204c8d88213e">micro_os_plus::micro_test_plus::reporter_human::end_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a79c7928d44d70b8fe5bf993775517e63">micro_os_plus::micro_test_plus::reporter_tap::end_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#ac0a6d2bda91a9afa71346eef59c7f35e">micro_os_plus::micro_test_plus::reporter_human::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a8649b62ba8f7ff88501450c5f939ab6d">micro_os_plus::micro_test_plus::reporter_tap::end_suite</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#aa4f1beeb7b4b88ffc5e15eb705a2644e">micro_os_plus::micro_test_plus::detail::test_node::operator=</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Protected Member Functions

### register\_suite\_() {#abc9182d5e12609158d936f312a83f53c}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::runner::register_suite_ (std::unique_ptr&lt; class <a href="#a330a6a2c24a6759e4cce1269942b9c88">suite</a> &gt; suite)</td>
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

<p>Registers a test suite with the runner.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] suite</td>
<td class="doxyParamItemDescription"><p>Owning pointer to the test suite to register.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Takes ownership of the supplied <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a></span> unique pointer and appends it to the internal <span class="doxyComputerOutput"><a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a></span> vector, deferring execution until <span class="doxyComputerOutput"><a href="#ad02a7dd243b31ec630484b6397eb506d">run_suites_()</a></span> is called. If tracing is enabled, the suite name is logged for diagnostic purposes.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00284">284</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00316">316</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#abc9182d5e12609158d936f312a83f53c">316</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#abc9182d5e12609158d936f312a83f53c">runner::register_suite_</a> (std::unique_ptr&lt;class suite&gt; <a href="#a330a6a2c24a6759e4cce1269942b9c88">suite</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">317</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">318</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_TRACE) \</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">319</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">    &amp;&amp; defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">320</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">321</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">322</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">323</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">324</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">325</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">326</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s '%s'\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__, <a href="#a330a6a2c24a6759e4cce1269942b9c88">suite</a>-&gt;name ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">327</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">328</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">329</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">330</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">331</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">332</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a>.push_back (std::move (<a href="#a330a6a2c24a6759e4cce1269942b9c88">suite</a>));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">333</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a> and <a href="#a330a6a2c24a6759e4cce1269942b9c88">suite</a>.</p>


<p>Referenced by <a href="#aa34a0418d54c633630a089eb2b5a61ee">operator=</a> and <a href="#a330a6a2c24a6759e4cce1269942b9c88">suite</a>.</p>

</div>
</div>

### run\_suites\_() {#ad02a7dd243b31ec630484b6397eb506d}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::runner::run_suites_ (void)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel protected">protected</span>
<span class="doxyMemberLabel virtual">virtual</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Runs all registered test suites.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<p>Sorts <span class="doxyComputerOutput"><a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a></span> alphabetically by suite name using a selection sort on <span class="doxyComputerOutput">unique_ptr::swap</span>, avoiding the <span class="doxyComputerOutput">-Waggregate-return</span> diagnostic that <span class="doxyComputerOutput">std::sort</span> would trigger on unique-pointer iterators. Each suite is assigned a 1-based index offset by the top-suite index, executed via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a432deda5a8721472e8775cbc98451722">suite::run()</a></span>, and its totals are accumulated into the runner totals. The executed-subtest counter is not incremented; suites are not counted as subtests.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00274">274</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp/#l00346">346</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ad02a7dd243b31ec630484b6397eb506d">346</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ad02a7dd243b31ec630484b6397eb506d">runner::run_suites_</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">347</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">348</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Use selection sort with unique_ptr::swap (returns void) to avoid</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">349</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// std::sort triggering -Waggregate-return via std::move_backward,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">350</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// which returns a class-type iterator when operating on unique_ptr</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">351</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// elements.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">352</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> n = <a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a>.size ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">353</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> i = 0; i &lt; n; ++i)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">354</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">355</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> min_idx = i;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">356</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> j = i + 1; j &lt; n; ++j)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">357</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">358</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (std::string_view{ <a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a>[j]-&gt;name () }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">359</span><span class="doxyLineContent"><span class="doxyHighlight">                &lt; std::string_view{ <a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a>[min_idx]-&gt;name () })</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">360</span><span class="doxyLineContent"><span class="doxyHighlight">              min_idx = j;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">361</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">362</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (min_idx != i)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">363</span><span class="doxyLineContent"><span class="doxyHighlight">          <a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a>[i].swap (<a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a>[min_idx]);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">364</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">365</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">366</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> i = 0; i &lt; n; ++i)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">367</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">368</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">* suite_ptr = <a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a>[i].get ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">369</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">370</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// 1 for 1-based index, 1 for top suite</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">371</span><span class="doxyLineContent"><span class="doxyHighlight">        suite_ptr-&gt;own_index (i + 1 + 1);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">372</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">373</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// Run the child suite immediately.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">374</span><span class="doxyLineContent"><span class="doxyHighlight">        suite_ptr-&gt;run ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">375</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">376</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// Accumulate the totals from the child suite into the runner</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">377</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// totals.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">378</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// DO NOT increment executed_subtests here.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">379</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1af301da2bcb0659c40a472589edc194">totals_</a> += suite_ptr-&gt;totals ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">380</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">381</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1af301da2bcb0659c40a472589edc194">micro_os_plus::micro_test_plus::detail::test_node::totals_</a>.</p>


<p>Referenced by <a href="#a7f8403f1ccc6a0e8171ef077bcd9cbd4">exit_code</a>, <a href="#aa34a0418d54c633630a089eb2b5a61ee">operator=</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-runner/#ac17e3110a8cd7f71a39b932cc74cbcad">micro_os_plus::micro_test_plus::static_runner::run_suites_</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Protected Member Attributes

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
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel protected">protected</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Owning collection of dynamically registered child suites.</p>


<p>Each call to <span class="doxyComputerOutput"><a href="#a330a6a2c24a6759e4cce1269942b9c88">runner::suite()</a></span> appends a new <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a></span> to this vector and runs it immediately. The vector retains ownership of all suites for the lifetime of the runner.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00301">301</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#abacf53ab658e289ae89051531c0cddad">301</a></span><span class="doxyLineContent"><span class="doxyHighlight">    std::vector&lt;std::unique_ptr&lt;class <a href="#a330a6a2c24a6759e4cce1269942b9c88">suite</a>&gt;&gt; <a href="#abacf53ab658e289ae89051531c0cddad">children_suites_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#abc9182d5e12609158d936f312a83f53c">register_suite_</a>, <a href="#ad02a7dd243b31ec630484b6397eb506d">run_suites_</a> and <a href="#a6ed3a02ced62ed475c75678cd9e91be1">suites_count</a>.</p>

</div>
</div>

### name\_ {#a61ac0275108c9f9b2348c1c5fc8af104}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const char* micro_os_plus::micro_test_plus::detail::test_node::name_</td>
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

<p>The test node name.</p>



:::info
<p>Derived classes may access this member directly in addition to the public <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1565ede2ab1141b2e3db2ea5513002a1">name()</a></span> getter.</p>
:::


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00224">224</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a61ac0275108c9f9b2348c1c5fc8af104">224</a></span><span class="doxyLineContent"><span class="doxyHighlight">      const </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a61ac0275108c9f9b2348c1c5fc8af104">name_</a>;</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1f293a9e44f60ee340c18d9e7efa0390">micro_os_plus::micro_test_plus::detail::test_node::test_node</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable/#a3a3b33c3ac1c6bf54c72f17a2bfc467e">micro_os_plus::micro_test_plus::detail::runnable&lt; Self_T &gt;::~runnable</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aceb40214c40edbd44ffcde673624e389">micro_os_plus::micro_test_plus::detail::runnable_base::~runnable_base</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1a2ee48056523ceead142c95209cd57d">micro_os_plus::micro_test_plus::detail::test_node::~test_node</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1565ede2ab1141b2e3db2ea5513002a1">micro_os_plus::micro_test_plus::detail::test_node::name</a>.</p>

</div>
</div>

### reporter\_ {#ace4da8161152a82e4ffa9c6d50917088}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::unique_ptr&lt;class reporter&gt; micro_os_plus::micro_test_plus::runner::reporter_</td>
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

<p>Pointer to the test reporter used for outputting test results.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00306">306</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ace4da8161152a82e4ffa9c6d50917088">306</a></span><span class="doxyLineContent"><span class="doxyHighlight">    std::unique_ptr&lt;class <a href="#a28e8cf878d98f6cba575a58189c39a56">reporter</a>&gt; <a href="#ace4da8161152a82e4ffa9c6d50917088">reporter_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#a7f8403f1ccc6a0e8171ef077bcd9cbd4">exit_code</a>, <a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise</a> and <a href="#a28e8cf878d98f6cba575a58189c39a56">reporter</a>.</p>

</div>
</div>

### timings\_ {#a7cdc57b32f1d1989fde8a119905a0bc7}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">detail::timestamps micro_os_plus::micro_test_plus::runner::timings_</td>
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

<p>Timings for this runner.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00311">311</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a7cdc57b32f1d1989fde8a119905a0bc7">311</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail">detail</a>::timestamps <a href="#a7cdc57b32f1d1989fde8a119905a0bc7">timings_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#a7f8403f1ccc6a0e8171ef077bcd9cbd4">exit_code</a>, <a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise</a>, <a href="#a9c98d2b38f64305b6042e81a3e468540">timings</a> and <a href="#a256d5fafb7231399ca0128ec68deff75">timings</a>.</p>

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
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel protected">protected</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The implicit top-level suite; always present and executed first.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00291">291</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">291</a></span><span class="doxyLineContent"><span class="doxyHighlight">    class <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite">top_suite</a> <a href="#a93a3afb222db1fcaa87cd1ba7fa15bc0">top_suite_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#a10788baa079e19676a8cdbaa253285dc">runner</a>, <a href="#a5e2001730fd3659e9045fcc5cc668f07">runner</a>, <a href="#a7f8403f1ccc6a0e8171ef077bcd9cbd4">exit_code</a> and <a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise</a>.</p>

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
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel protected">protected</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Owned storage for the implicit top-suite name.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h/#l00316">316</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a401e4e098f0ceba7f21a3a5bf1ea89e3">316</a></span><span class="doxyLineContent"><span class="doxyHighlight">    std::</span><span class="doxyHighlightKeywordType">string</span><span class="doxyHighlight"> <a href="#a401e4e098f0ceba7f21a3a5bf1ea89e3">top_suite_name_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#acfabd0e10d233ad305b6f4fc125a97f2">initialise</a>.</p>

</div>
</div>

### totals\_ {#a1af301da2bcb0659c40a472589edc194}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">runner_totals micro_os_plus::micro_test_plus::detail::test_node::totals_</td>
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

<p>Totals for the test node, including nested cases.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00229">229</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1af301da2bcb0659c40a472589edc194">229</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runner-totals">runner_totals</a> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1af301da2bcb0659c40a472589edc194">totals_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#a7f8403f1ccc6a0e8171ef077bcd9cbd4">exit_code</a>, <a href="#ad02a7dd243b31ec630484b6397eb506d">run_suites_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-runner/#ac17e3110a8cd7f71a39b932cc74cbcad">micro_os_plus::micro_test_plus::static_runner::run_suites_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a722406c83eaec234b23b1b9a97a97010">micro_os_plus::micro_test_plus::detail::test_node::totals</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/test-node/#a1e053f72527192d324e4d0130b7017d3">micro_os_plus::micro_test_plus::detail::test_node::totals</a>.</p>

</div>
</div>

</div>

<hr/>

The documentation for this class was generated from the following files:

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/runner-inlines-h">runner-inlines.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">runner.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/src/runner-cpp">runner.cpp</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.0 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
