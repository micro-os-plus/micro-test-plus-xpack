---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/files/src/reporter-cpp
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - file

---

<div class="doxyPage">

# `reporter.cpp` File

<p>C++ source file with implementations for the µTest++ test reporter member functions. <a href="#details">More...</a></p>

## Included Headers

<div class="doxyIncludesList">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/counters-h">micro-os-plus/micro-test-plus/counters.h</a>"
#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">micro-os-plus/micro-test-plus/reporter.h</a>"
#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">micro-os-plus/micro-test-plus/runner.h</a>"
#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/stopwatch-h">micro-os-plus/micro-test-plus/stopwatch.h</a>"
#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">micro-os-plus/micro-test-plus/test.h</a>"
#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/utility-h">micro-os-plus/micro-test-plus/utility.h</a>"
#include &lt;cstdarg&gt;
#include &lt;cinttypes&gt;
#include &lt;limits&gt;
</div>

## Namespaces Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">namespace</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus">micro_os_plus</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The primary namespace for the µOS++ framework. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">namespace</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_test_plus</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Primary namespace for the µTest++ testing framework. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">namespace</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail">detail</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Internal implementation details for the µTest++ framework. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">namespace</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-">anonymous{reporter.cpp}</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Local helpers of the reporter base class. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">reporter &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">endl</a> (reporter &amp;stream)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output stream manipulator for ending a line in test reports. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a0d696f5039163e76ec2e4005980ca285">format_skipped</a> (size_t count, char(&amp;message)[fragment_size])</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats the number of items skipped by the filter. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a0d696f5039163e76ec2e4005980ca285">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">constexpr const char *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a25afc917399bf6d116b401e47ca8a4d5">plural</a> (size_t count) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns the plural suffix for a count. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a25afc917399bf6d116b401e47ca8a4d5">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a78d7c9fe8e59d559bf67bc55e7c52040">write_without_colours</a> (FILE *file, std::string_view text)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Writes a text to a file, without the ANSI colour sequences. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a78d7c9fe8e59d559bf67bc55e7c52040">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Variables Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">constexpr size_t</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a1ffff9ae8f2024f3bff18ec45b2baaf9">fragment_size</a> = 21 + (std::numeric_limits&lt;size_t&gt;::digits10 + 1)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Size of the array that receives a fragment of the totals. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a1ffff9ae8f2024f3bff18ec45b2baaf9">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>C++ source file with implementations for the µTest++ test reporter member functions.</p>


<p>This source file contains the core implementations for the test reporting facilities of the µTest++ framework. It provides lifecycle and utility behaviour for reporters, including output-file handling, informational banner emission, buffering helpers, stream operators, the formatting of the totals and of the elapsed times, and pass/fail dispatch to reporter-specific prefix/suffix hooks. The command-line options are parsed by the runner.</p>


<p>Concrete formatting behaviour is implemented by derived reporters (<span class="doxyComputerOutput">reporter_human</span> and <span class="doxyComputerOutput">reporter_tap</span>).</p>


<p>All definitions reside within the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail">micro_os_plus::micro_test_plus::detail</a></span> namespace, since the reporters are internal to the framework.</p>


<p>This file must be included when building the µTest++ library.</p>


<div class="doxySectionDef">

## Functions

### endl() {#a18e81b3839468cd82ad9c394d88a0e02}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">reporter &amp; micro_os_plus::micro_test_plus::detail::endl (reporter &amp; stream)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Output stream manipulator for ending a line in test reports.</p>


<p>Calls <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a287bad0e5eccee7df4a2c8517959bd0e">reporter::end_line()</a></span>, which appends a line ending to the internal buffer. Unlike <span class="doxyComputerOutput">std::endl</span>, it does not flush; the buffer is written later, by the concrete reporters.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">stream</td>
<td class="doxyParamItemDescription"><p>Reference to the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a></span> instance.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to the same <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a></span> instance, enabling chaining of output operations.</p></dd>
</dl>


<p>The <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">endl</a></span> function calls <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a287bad0e5eccee7df4a2c8517959bd0e">reporter::end_line()</a></span>, which appends a newline character to the buffer of the specified <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a></span>.</p>


<p>Definition at line <a href="#l00218">218</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">218</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">endl</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a>&amp; stream)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">219</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">220</span><span class="doxyLineContent"><span class="doxyHighlight">    stream.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a287bad0e5eccee7df4a2c8517959bd0e">end_line</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">221</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> stream;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">222</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a287bad0e5eccee7df4a2c8517959bd0e">micro_os_plus::micro_test_plus::detail::reporter::end_line</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">micro_os_plus::micro_test_plus::detail::endl</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">micro_os_plus::micro_test_plus::detail::endl</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#afd98d9a322823d67448d4ba301846392">micro_os_plus::micro_test_plus::detail::reporter_human::fail_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a314df80e98fe6fa5de008d6708a14925">micro_os_plus::micro_test_plus::detail::reporter_tap::fail_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a3bd1c7d455abc782062d0e23a3ef1015">micro_os_plus::micro_test_plus::detail::reporter_tap::output_fail_prefix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ab9fdb57e1a5497af22de7cf4a252ce4b">micro_os_plus::micro_test_plus::detail::reporter_human::output_fail_suffix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#aaea110287f115fbaf80b0248f724c5b6">micro_os_plus::micro_test_plus::detail::reporter_tap::output_fail_suffix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#aeb5fb6ae953d2250360968c5582f73ab">micro_os_plus::micro_test_plus::detail::reporter_human::output_pass_suffix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a37c4235afdd9b704fd65d25d130bee86">micro_os_plus::micro_test_plus::detail::reporter_tap::output_pass_suffix</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a4ccc6d5273d6668fc3e91cc790328c5f">micro_os_plus::micro_test_plus::detail::reporter_tap::pass_without_text</a>.</p>

</div>
</div>

### format\_skipped() {#a0d696f5039163e76ec2e4005980ca285}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::anonymous{reporter.cpp}::format_skipped (size_t count, char(&amp;message)[fragment_size])</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Formats the number of items skipped by the filter.</p>


<p>The text is <span class="doxyComputerOutput">", &lt;count&gt; skipped"</span>, appended to the count of the items, or empty when no item was skipped, so that the totals lines of the runs without a filter are not longer.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">count</td>
<td class="doxyParamItemDescription"><p>The number of skipped items.</p></td>
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


<p>Definition at line <a href="#l00874">874</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a0d696f5039163e76ec2e4005980ca285">874</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a0d696f5039163e76ec2e4005980ca285">format_skipped</a> (</span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> count, </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> (&amp;message)[<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a1ffff9ae8f2024f3bff18ec45b2baaf9">fragment_size</a>])</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">875</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">876</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (count &gt; 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">877</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">878</span><span class="doxyLineContent"><span class="doxyHighlight">          snprintf (message, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (message),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">879</span><span class="doxyLineContent"><span class="doxyHighlight">                    </span><span class="doxyHighlightStringLiteral">", %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a> </span><span class="doxyHighlightStringLiteral">" skipped"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">880</span><span class="doxyLineContent"><span class="doxyHighlight">                    count);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">881</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">882</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">883</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">884</span><span class="doxyLineContent"><span class="doxyHighlight">          message[0] = </span><span class="doxyHighlightCharLiteral">'\0'</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">885</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">886</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a0d696f5039163e76ec2e4005980ca285">micro_os_plus::micro_test_plus::detail::anonymous{reporter.cpp}::format_skipped</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a1ffff9ae8f2024f3bff18ec45b2baaf9">micro_os_plus::micro_test_plus::detail::anonymous{reporter.cpp}::fragment_size</a> and <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a0d696f5039163e76ec2e4005980ca285">micro_os_plus::micro_test_plus::detail::anonymous{reporter.cpp}::format_skipped</a>.</p>

</div>
</div>

### plural() {#a25afc917399bf6d116b401e47ca8a4d5}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const char * micro_os_plus::micro_test_plus::detail::anonymous{reporter.cpp}::plural (size_t count)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel constexpr">constexpr</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Returns the plural suffix for a count.</p>


<p>The totals lines are in English, where only the count 1 takes the singular form.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">count</td>
<td class="doxyParamItemDescription"><p>The count that precedes the noun.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p><span class="doxyComputerOutput">""</span> for 1, and <span class="doxyComputerOutput">"s"</span> otherwise.</p></dd>
</dl>


<p>Definition at line <a href="#l00854">854</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a25afc917399bf6d116b401e47ca8a4d5">854</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a25afc917399bf6d116b401e47ca8a4d5">plural</a> (</span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> count) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">855</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">856</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> count == 1 ? </span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"> : </span><span class="doxyHighlightStringLiteral">"s"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">857</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a25afc917399bf6d116b401e47ca8a4d5">micro_os_plus::micro_test_plus::detail::anonymous{reporter.cpp}::plural</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a25afc917399bf6d116b401e47ca8a4d5">micro_os_plus::micro_test_plus::detail::anonymous{reporter.cpp}::plural</a>.</p>

</div>
</div>

### write\_without\_colours() {#a78d7c9fe8e59d559bf67bc55e7c52040}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::anonymous{reporter.cpp}::write_without_colours (FILE * file, std::string_view text)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Writes a text to a file, without the ANSI colour sequences.</p>


<p>The text may contain ANSI colour sequences, added when the console is a terminal, which must not reach the file. They are removed while writing: each <span class="doxyComputerOutput">ESC [</span>, followed by any digits and semicolons, and terminated by <span class="doxyComputerOutput">m</span>, is skipped, and the text between the sequences is written unchanged. Any other use of <span class="doxyComputerOutput">ESC</span> is written as is. No line ending is appended.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">file</td>
<td class="doxyParamItemDescription"><p>The file to write to; must not be null.</p></td>
</tr>
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


<p>Definition at line <a href="#l00113">113</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a78d7c9fe8e59d559bf67bc55e7c52040">113</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a78d7c9fe8e59d559bf67bc55e7c52040">write_without_colours</a> (FILE* file, std::string_view text)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">114</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">115</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> start = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">116</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> pos = text.find (</span><span class="doxyHighlightCharLiteral">'\033'</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">117</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">while</span><span class="doxyHighlight"> (pos != std::string_view::npos)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">118</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">119</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightComment">// Parse `ESC [ &lt;digits and semicolons&gt; m`.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">120</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> end = pos + 1;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">121</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (end &lt; text.size () &amp;&amp; text[end] == </span><span class="doxyHighlightCharLiteral">'['</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">122</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">123</span><span class="doxyLineContent"><span class="doxyHighlight">              ++end;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">124</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">while</span><span class="doxyHighlight"> (end &lt; text.size ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">125</span><span class="doxyLineContent"><span class="doxyHighlight">                     &amp;&amp; ((text[end] &gt;= </span><span class="doxyHighlightCharLiteral">'0'</span><span class="doxyHighlight"> &amp;&amp; text[end] &lt;= </span><span class="doxyHighlightCharLiteral">'9'</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">126</span><span class="doxyLineContent"><span class="doxyHighlight">                         || text[end] == </span><span class="doxyHighlightCharLiteral">';'</span><span class="doxyHighlight">))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">127</span><span class="doxyLineContent"><span class="doxyHighlight">                {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">128</span><span class="doxyLineContent"><span class="doxyHighlight">                  ++end;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">129</span><span class="doxyLineContent"><span class="doxyHighlight">                }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">130</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (end &lt; text.size () &amp;&amp; text[end] == </span><span class="doxyHighlightCharLiteral">'m'</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">131</span><span class="doxyLineContent"><span class="doxyHighlight">                {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">132</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightComment">// A colour sequence; write the preceding text and skip</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">133</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightComment">// it.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">134</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string_view chunk</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">135</span><span class="doxyLineContent"><span class="doxyHighlight">                      = text.substr (start, pos - start);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">136</span><span class="doxyLineContent"><span class="doxyHighlight">                  fwrite (chunk.data (), 1, chunk.size (), file);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">137</span><span class="doxyLineContent"><span class="doxyHighlight">                  start = end + 1;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">138</span><span class="doxyLineContent"><span class="doxyHighlight">                }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">139</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">140</span><span class="doxyLineContent"><span class="doxyHighlight">          pos = text.find (</span><span class="doxyHighlightCharLiteral">'\033'</span><span class="doxyHighlight">, pos + 1);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">141</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">142</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">143</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string_view chunk = text.substr (start);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">144</span><span class="doxyLineContent"><span class="doxyHighlight">      fwrite (chunk.data (), 1, chunk.size (), file);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">145</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a78d7c9fe8e59d559bf67bc55e7c52040">micro_os_plus::micro_test_plus::detail::anonymous{reporter.cpp}::write_without_colours</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a78d7c9fe8e59d559bf67bc55e7c52040">micro_os_plus::micro_test_plus::detail::anonymous{reporter.cpp}::write_without_colours</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Variables

### fragment\_size {#a1ffff9ae8f2024f3bff18ec45b2baaf9}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">size_t micro_os_plus::micro_test_plus::detail::anonymous{reporter.cpp}::fragment_size = 21 + (std::numeric_limits&lt;size_t&gt;::digits10 + 1)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel constexpr">constexpr</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Size of the array that receives a fragment of the totals.</p>


<p>Large enough for <span class="doxyComputerOutput">", N test cases failed"</span>, the longest fragment (20 characters and the count), and the terminator, with the count of the largest <span class="doxyComputerOutput">size_t</span> value (10 digits on 32-bit targets, 20 on 64-bit ones, as in <span class="doxyComputerOutput">", 18446744073709551615 test cases failed"</span>).</p>


<p>Definition at line <a href="#l00840">840</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">841</span><span class="doxyLineContent"><span class="doxyHighlight">        = 21 + (std::numeric_limits&lt;size_t&gt;::digits10 + 1);</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a0d696f5039163e76ec2e4005980ca285">micro_os_plus::micro_test_plus::detail::anonymous{reporter.cpp}::format_skipped</a>.</p>

</div>
</div>

</div>

## File Listing

The file content with the documentation metadata removed is:

<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00001"></a>1</span><span class="doxyLineContent"><span class="doxyHighlightComment">/*</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00002"></a>2</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * This file is part of the µOS++ project (https://micro-os-plus.github.io/).</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00003"></a>3</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * Copyright (c) 2021-2026 Liviu Ionescu. All rights reserved.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00004"></a>4</span><span class="doxyLineContent"><span class="doxyHighlightComment"> *</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00005"></a>5</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * Permission to use, copy, modify, and/or distribute this software for any</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00006"></a>6</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * purpose is hereby granted, under the terms of the MIT license.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00007"></a>7</span><span class="doxyLineContent"><span class="doxyHighlightComment"> *</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00008"></a>8</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * If a copy of the license was not distributed with this file, it can be</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00009"></a>9</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * obtained from https://opensource.org/licenses/mit.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00010"></a>10</span><span class="doxyLineContent"><span class="doxyHighlightComment"> */</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00011"></a>11</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00012"></a>12</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00013"></a>13</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00037"></a>37</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00038"></a>38</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00039"></a>39</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00040"></a>40</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/counters-h">micro-os-plus/micro-test-plus/counters.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00041"></a>41</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">micro-os-plus/micro-test-plus/reporter.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00042"></a>42</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-h">micro-os-plus/micro-test-plus/runner.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00043"></a>43</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/stopwatch-h">micro-os-plus/micro-test-plus/stopwatch.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00044"></a>44</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">micro-os-plus/micro-test-plus/test.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00045"></a>45</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/utility-h">micro-os-plus/micro-test-plus/utility.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00046"></a>46</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00047"></a>47</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if __has_include("micro-os-plus/diag/trace.h")</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00048"></a>48</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "micro-os-plus/diag/trace.h"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00049"></a>49</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// __has_include("micro-os-plus/diag/trace.h")</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00050"></a>50</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00051"></a>51</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;cstdarg&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00052"></a>52</span><span class="doxyLineContent"><span class="doxyHighlightComment">// For the PRIu32 macro used in snprintf() formatting of uint32_t values.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00053"></a>53</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;cinttypes&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00054"></a>54</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;limits&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00055"></a>55</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00056"></a>56</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00057"></a>57</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00058"></a>58</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00059"></a>59</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Waggregate-return"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00060"></a>60</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00061"></a>61</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wunknown-warning-option"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00062"></a>62</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wc++98-compat"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00063"></a>63</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00064"></a>64</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00065"></a>65</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00066"></a>66</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00067"></a>67</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00068"></a>68</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ============================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00069"></a>69</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00070"></a>70</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00071"></a>71</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00072"></a>72</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00073"></a>73</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00074"></a>74</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail">micro_os_plus::micro_test_plus::detail</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00075"></a>75</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00076"></a>76</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00077"></a>77</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00094"></a><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-">94</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">namespace</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00095"></a>95</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00112"></a>112</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00113"></a><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a78d7c9fe8e59d559bf67bc55e7c52040">113</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a78d7c9fe8e59d559bf67bc55e7c52040">write_without_colours</a> (FILE* file, std::string_view text)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00114"></a>114</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00115"></a>115</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> start = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00116"></a>116</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> pos = text.find (</span><span class="doxyHighlightCharLiteral">'\033'</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00117"></a>117</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">while</span><span class="doxyHighlight"> (pos != std::string_view::npos)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00118"></a>118</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00119"></a>119</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightComment">// Parse `ESC [ &lt;digits and semicolons&gt; m`.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00120"></a>120</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> end = pos + 1;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00121"></a>121</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (end &lt; text.size () &amp;&amp; text[end] == </span><span class="doxyHighlightCharLiteral">'['</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00122"></a>122</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00123"></a>123</span><span class="doxyLineContent"><span class="doxyHighlight">              ++end;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00124"></a>124</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">while</span><span class="doxyHighlight"> (end &lt; text.size ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00125"></a>125</span><span class="doxyLineContent"><span class="doxyHighlight">                     &amp;&amp; ((text[end] &gt;= </span><span class="doxyHighlightCharLiteral">'0'</span><span class="doxyHighlight"> &amp;&amp; text[end] &lt;= </span><span class="doxyHighlightCharLiteral">'9'</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00126"></a>126</span><span class="doxyLineContent"><span class="doxyHighlight">                         || text[end] == </span><span class="doxyHighlightCharLiteral">';'</span><span class="doxyHighlight">))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00127"></a>127</span><span class="doxyLineContent"><span class="doxyHighlight">                {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00128"></a>128</span><span class="doxyLineContent"><span class="doxyHighlight">                  ++end;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00129"></a>129</span><span class="doxyLineContent"><span class="doxyHighlight">                }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00130"></a>130</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (end &lt; text.size () &amp;&amp; text[end] == </span><span class="doxyHighlightCharLiteral">'m'</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00131"></a>131</span><span class="doxyLineContent"><span class="doxyHighlight">                {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00132"></a>132</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightComment">// A colour sequence; write the preceding text and skip</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00133"></a>133</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightComment">// it.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00134"></a>134</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string_view chunk</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00135"></a>135</span><span class="doxyLineContent"><span class="doxyHighlight">                      = text.substr (start, pos - start);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00136"></a>136</span><span class="doxyLineContent"><span class="doxyHighlight">                  fwrite (chunk.data (), 1, chunk.size (), file);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00137"></a>137</span><span class="doxyLineContent"><span class="doxyHighlight">                  start = end + 1;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00138"></a>138</span><span class="doxyLineContent"><span class="doxyHighlight">                }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00139"></a>139</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00140"></a>140</span><span class="doxyLineContent"><span class="doxyHighlight">          pos = text.find (</span><span class="doxyHighlightCharLiteral">'\033'</span><span class="doxyHighlight">, pos + 1);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00141"></a>141</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00142"></a>142</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00143"></a>143</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string_view chunk = text.substr (start);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00144"></a>144</span><span class="doxyLineContent"><span class="doxyHighlight">      fwrite (chunk.data (), 1, chunk.size (), file);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00145"></a>145</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00146"></a>146</span><span class="doxyLineContent"><span class="doxyHighlight">  } </span><span class="doxyHighlightComment">// namespace</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00147"></a>147</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00148"></a>148</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00149"></a>149</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00162"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">162</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter::reporter</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options">runner_options</a>&amp; opts)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00163"></a>163</span><span class="doxyLineContent"><span class="doxyHighlight">      : <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a>{ opts.verbosity_level }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00164"></a>164</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00165"></a>165</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00166"></a>166</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00167"></a>167</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00168"></a>168</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00169"></a>169</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (!opts.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#a86bc6ef13bb488a933f6001c98aa2c6e">output_file_path</a>.empty ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00170"></a>170</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00171"></a>171</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> = fopen (opts.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#a86bc6ef13bb488a933f6001c98aa2c6e">output_file_path</a>.c_str (), </span><span class="doxyHighlightStringLiteral">"w"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00172"></a>172</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> == </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00173"></a>173</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00174"></a>174</span><span class="doxyLineContent"><span class="doxyHighlight">            fprintf (stderr, </span><span class="doxyHighlightStringLiteral">"error: failed to open output file '%s'\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00175"></a>175</span><span class="doxyLineContent"><span class="doxyHighlight">                     opts.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#a86bc6ef13bb488a933f6001c98aa2c6e">output_file_path</a>.c_str ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00176"></a>176</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0d73674812cca717a754137b4b26ed89">has_output_file_error_</a> = </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00177"></a>177</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00178"></a>178</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00179"></a>179</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00180"></a>180</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac3878d2e85ed2cae4c71c793d7a8f52e">output_file_path_</a> = opts.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#a86bc6ef13bb488a933f6001c98aa2c6e">output_file_path</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00181"></a>181</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00182"></a>182</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00183"></a>183</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00184"></a>184</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Pre-allocate buffer to reduce dynamic allocations.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00185"></a>185</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>.reserve (128);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00186"></a>186</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00187"></a>187</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00194"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5b6052e6c28235b76d855b2b7bc176dd">194</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5b6052e6c28235b76d855b2b7bc176dd">reporter::~reporter</a> ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00195"></a>195</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00196"></a>196</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00197"></a>197</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00198"></a>198</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00199"></a>199</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00200"></a>200</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00201"></a>201</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00202"></a>202</span><span class="doxyLineContent"><span class="doxyHighlight">        fflush (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00203"></a>203</span><span class="doxyLineContent"><span class="doxyHighlight">        fclose (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00204"></a>204</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00205"></a>205</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> = </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00206"></a>206</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac3878d2e85ed2cae4c71c793d7a8f52e">output_file_path_</a>.clear ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00207"></a>207</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00208"></a>208</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00209"></a>209</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00210"></a>210</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00211"></a>211</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00217"></a>217</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00218"></a><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">218</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">endl</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a>&amp; stream)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00219"></a>219</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00220"></a>220</span><span class="doxyLineContent"><span class="doxyHighlight">    stream.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a287bad0e5eccee7df4a2c8517959bd0e">end_line</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00221"></a>221</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> stream;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00222"></a>222</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00223"></a>223</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00231"></a>231</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00232"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a287bad0e5eccee7df4a2c8517959bd0e">232</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a287bad0e5eccee7df4a2c8517959bd0e">reporter::end_line</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00233"></a>233</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00234"></a>234</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00235"></a>235</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00236"></a>236</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00243"></a>243</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00244"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a388b0308cfe82a025b8e1fa7e9a969a5">244</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a388b0308cfe82a025b8e1fa7e9a969a5">reporter::announce_output_file</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00245"></a>245</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00246"></a>246</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> == </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00247"></a>247</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00248"></a>248</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00249"></a>249</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00250"></a>250</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00251"></a>251</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a804b593aefa158d92a72da43de57d242">flush_streams</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00252"></a>252</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00253"></a>253</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> != <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-runners/#gga809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">verbosity::silent</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00254"></a>254</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00255"></a>255</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#abaee31ffca8e65c9af34f7f67227c5b3">write_console</a> (</span><span class="doxyHighlightStringLiteral">"%sTest output written to '%s'.\n"</span><span class="doxyHighlight">, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a324aa273975068c140ab6eecc7e722c9">comment_prefix</a> (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00256"></a>256</span><span class="doxyLineContent"><span class="doxyHighlight">                       <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac3878d2e85ed2cae4c71c793d7a8f52e">output_file_path_</a>.c_str ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00257"></a>257</span><span class="doxyLineContent"><span class="doxyHighlight">        fflush (stdout);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00258"></a>258</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00259"></a>259</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00260"></a>260</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00266"></a>266</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">*</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00267"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a9cf0f0b5601d19cb6e68c8b97f053c85">267</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a9cf0f0b5601d19cb6e68c8b97f053c85">reporter::error_prefix</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00268"></a>268</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00269"></a>269</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> </span><span class="doxyHighlightStringLiteral">"error: "</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00270"></a>270</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00271"></a>271</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00279"></a>279</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/output-route">output_route</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00280"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#af33f2f6498a97383cdb75020e32ccf23">280</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#af33f2f6498a97383cdb75020e32ccf23">reporter::route</a> (<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5">record_kind</a> kind) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00281"></a>281</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00282"></a>282</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> console;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00283"></a>283</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (kind == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5ae3a1f45168c36de6c9f4a81f84aaa640">record_kind::failed_check</a> || kind == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5afbb44b4487415b134bce9c790a27fe5e">record_kind::total</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00284"></a>284</span><span class="doxyLineContent"><span class="doxyHighlight">        || kind == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5a5bb94a1c12413a2e5d14deabab29f2aa">record_kind::abort</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00285"></a>285</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00286"></a>286</span><span class="doxyLineContent"><span class="doxyHighlight">        console = (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> != <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-runners/#gga809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">verbosity::silent</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00287"></a>287</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00288"></a>288</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (kind == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5a50bcbe154487d5fbab186979293ec8f1">record_kind::test_case_heading</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00289"></a>289</span><span class="doxyLineContent"><span class="doxyHighlight">             || kind == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5ad92bae248e3e6219914c8348b9b14a6e">record_kind::passed_check</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00290"></a>290</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00291"></a>291</span><span class="doxyLineContent"><span class="doxyHighlight">        console = (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-runners/#gga809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">verbosity::verbose</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00292"></a>292</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00293"></a>293</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_STARTUP_ENABLED) \</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00294"></a>294</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">    &amp;&amp; defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00295"></a>295</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (kind == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5acaf9b6b99962bf5c2264824231d7a40c">record_kind::info</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00296"></a>296</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00297"></a>297</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// The startup code already displays this information.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00298"></a>298</span><span class="doxyLineContent"><span class="doxyHighlight">        console = </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00299"></a>299</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00300"></a>300</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(MICRO_OS_PLUS_STARTUP_ENABLED) &amp;&amp; ...</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00301"></a>301</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00302"></a>302</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00303"></a>303</span><span class="doxyLineContent"><span class="doxyHighlight">        console = (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-runners/#gga809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">verbosity::normal</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00304"></a>304</span><span class="doxyLineContent"><span class="doxyHighlight">                   || <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-runners/#gga809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">verbosity::verbose</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00305"></a>305</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00306"></a>306</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00307"></a>307</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> { console, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight"> };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00308"></a>308</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00309"></a>309</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00319"></a>319</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">bool</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00320"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0e6f0a129d495a7e9d57ef71412cd88f">320</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0e6f0a129d495a7e9d57ef71412cd88f">reporter::writes_passed_checks</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00321"></a>321</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00322"></a>322</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight"> || <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-runners/#gga809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">verbosity::verbose</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00323"></a>323</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00324"></a>324</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00331"></a>331</span><span class="doxyLineContent"><span class="doxyHighlight">  std::string_view</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00332"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#adb473d2a466c856bfe8151c7558383c1">332</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#adb473d2a466c856bfe8151c7558383c1">reporter::console_lines</a> (</span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> failed) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00333"></a>333</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00334"></a>334</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-runners/#gga809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">verbosity::verbose</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00335"></a>335</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00336"></a>336</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00337"></a>337</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00338"></a>338</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-runners/#gga809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">verbosity::normal</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00339"></a>339</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00340"></a>340</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> failed ? std::string_view{ <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a> } : std::string_view{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00341"></a>341</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00342"></a>342</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-runners/#gga809871d76f29309ed9c6fbd96d5a914ba556966c7830465dc4623d62e32cec31d">verbosity::quiet</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00343"></a>343</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00344"></a>344</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ab8acd7e0c7bc5240a0912affd115305b">failures_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00345"></a>345</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00346"></a>346</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> {};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00347"></a>347</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00348"></a>348</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00354"></a>354</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00355"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a887f23131eb91fecf060982dcbd3b1ca">355</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a887f23131eb91fecf060982dcbd3b1ca">reporter::write_console_text</a> (std::string_view text)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00356"></a>356</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00357"></a>357</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Pass only the text, do not add an `\n` here.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00358"></a>358</span><span class="doxyLineContent"><span class="doxyHighlight">    fwrite (text.data (), 1, text.size (), stdout);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00359"></a>359</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00360"></a>360</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00366"></a>366</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00367"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2d5e5125b8c71fe0dedbe92d730647ec">367</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2d5e5125b8c71fe0dedbe92d730647ec">reporter::mark_failure</a> (</span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> begin)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00368"></a>368</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00369"></a>369</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-runners/#gga809871d76f29309ed9c6fbd96d5a914ba556966c7830465dc4623d62e32cec31d">verbosity::quiet</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00370"></a>370</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00371"></a>371</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ab8acd7e0c7bc5240a0912affd115305b">failures_</a>.append (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>, begin, std::string::npos);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00372"></a>372</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00373"></a>373</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a970a08a00e70f1574033085350656230">buffer_has_failures_</a> = </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00374"></a>374</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00375"></a>375</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00381"></a>381</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00382"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ae0a4d6478487a011e331e653d1a618b3">382</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ae0a4d6478487a011e331e653d1a618b3">reporter::display_open_test_cases</a> (</span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> include_last)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00383"></a>383</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00384"></a>384</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> count = include_last || <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ad7db34b25d785eacf98d4a50f1951d5b">open_test_cases_</a>.empty ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00385"></a>385</span><span class="doxyLineContent"><span class="doxyHighlight">                             ? <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ad7db34b25d785eacf98d4a50f1951d5b">open_test_cases_</a>.size ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00386"></a>386</span><span class="doxyLineContent"><span class="doxyHighlight">                             : <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ad7db34b25d785eacf98d4a50f1951d5b">open_test_cases_</a>.size () - 1;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00387"></a>387</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> is_first = </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00388"></a>388</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> i = 0; i &lt; count; ++i)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00389"></a>389</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00390"></a>390</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/reporter/open-test-case">open_test_case</a>&amp; open = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ad7db34b25d785eacf98d4a50f1951d5b">open_test_cases_</a>[i];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00391"></a>391</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (open.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/reporter/open-test-case/#a545589f22f45b2450bf06447aaee7ee5">name_displayed</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00392"></a>392</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00393"></a>393</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">continue</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00394"></a>394</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00395"></a>395</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00396"></a>396</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#af5fdc59140d1d58c4bdb903c9ec6d9a7">display_open_heading</a> (open, is_first);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00397"></a>397</span><span class="doxyLineContent"><span class="doxyHighlight">        is_first = </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00398"></a>398</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00399"></a>399</span><span class="doxyLineContent"><span class="doxyHighlight">        open.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/reporter/open-test-case/#a545589f22f45b2450bf06447aaee7ee5">name_displayed</a> = </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00400"></a>400</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00401"></a>401</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00402"></a>402</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00408"></a>408</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00409"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5ddd6ca6ce847ca89d7a3fcf9751f97d">409</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5ddd6ca6ce847ca89d7a3fcf9751f97d">reporter::enter_suite</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>, </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> displayed)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00410"></a>410</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00411"></a>411</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ad0a2ebe9aedaecf71fc76993122e661f">current_suite_</a> = &amp;<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00412"></a>412</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a6b07e60aa8baeb90821690d1ff9c65e6">suite_displayed_</a> = displayed;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00413"></a>413</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00414"></a>414</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00424"></a>424</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00425"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a37cba38a47d66a928a936ee081c6d88c">425</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a37cba38a47d66a928a936ee081c6d88c">reporter::write_buffer_to_file</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00426"></a>426</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00427"></a>427</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> == </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00428"></a>428</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00429"></a>429</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00430"></a>430</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00431"></a>431</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00432"></a>432</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Pass only the string, do not add an `\n` here.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00433"></a>433</span><span class="doxyLineContent"><span class="doxyHighlight">    write_without_colours (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00434"></a>434</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00435"></a>435</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00443"></a>443</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00444"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#abaee31ffca8e65c9af34f7f67227c5b3">444</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#abaee31ffca8e65c9af34f7f67227c5b3">reporter::write_console</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* format, ...)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00445"></a>445</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00446"></a>446</span><span class="doxyLineContent"><span class="doxyHighlight">    va_list args;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00447"></a>447</span><span class="doxyLineContent"><span class="doxyHighlight">    va_start (args, format);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00448"></a>448</span><span class="doxyLineContent"><span class="doxyHighlight">    vfprintf (stdout, format, args);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00449"></a>449</span><span class="doxyLineContent"><span class="doxyHighlight">    va_end (args);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00450"></a>450</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00451"></a>451</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00457"></a>457</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00458"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a90a541c6a9b1ddd3da9440358bfc704e">458</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a90a541c6a9b1ddd3da9440358bfc704e">reporter::write_file</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* format, ...)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00459"></a>459</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00460"></a>460</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> == </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00461"></a>461</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00462"></a>462</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00463"></a>463</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00464"></a>464</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00465"></a>465</span><span class="doxyLineContent"><span class="doxyHighlight">    va_list args;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00466"></a>466</span><span class="doxyLineContent"><span class="doxyHighlight">    va_start (args, format);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00467"></a>467</span><span class="doxyLineContent"><span class="doxyHighlight">    vfprintf (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a>, format, args);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00468"></a>468</span><span class="doxyLineContent"><span class="doxyHighlight">    va_end (args);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00469"></a>469</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00470"></a>470</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00484"></a>484</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00485"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">485</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">reporter::write_line</a> (</span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> to_console, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* format, ...)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00486"></a>486</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00487"></a>487</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> == </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight"> &amp;&amp; !to_console)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00488"></a>488</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00489"></a>489</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00490"></a>490</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00491"></a>491</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00492"></a>492</span><span class="doxyLineContent"><span class="doxyHighlight">    va_list args;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00493"></a>493</span><span class="doxyLineContent"><span class="doxyHighlight">    va_start (args, format);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00494"></a>494</span><span class="doxyLineContent"><span class="doxyHighlight">    va_list args_copy;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00495"></a>495</span><span class="doxyLineContent"><span class="doxyHighlight">    va_copy (args_copy, args);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00496"></a>496</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00497"></a>497</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> local_text[128];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00498"></a>498</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> length</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00499"></a>499</span><span class="doxyLineContent"><span class="doxyHighlight">        = vsnprintf (local_text, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (local_text), format, args);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00500"></a>500</span><span class="doxyLineContent"><span class="doxyHighlight">    va_end (args);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00501"></a>501</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00502"></a>502</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (length &lt; 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00503"></a>503</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00504"></a>504</span><span class="doxyLineContent"><span class="doxyHighlight">        va_end (args_copy);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00505"></a>505</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00506"></a>506</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00507"></a>507</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00508"></a>508</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> size = </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (length);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00509"></a>509</span><span class="doxyLineContent"><span class="doxyHighlight">    std::string long_text;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00510"></a>510</span><span class="doxyLineContent"><span class="doxyHighlight">    std::string_view text{ local_text, size };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00511"></a>511</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (size &gt;= </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (local_text))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00512"></a>512</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00513"></a>513</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// The terminating null character is written over the one kept by</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00514"></a>514</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// the string after its content.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00515"></a>515</span><span class="doxyLineContent"><span class="doxyHighlight">        long_text.resize (size);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00516"></a>516</span><span class="doxyLineContent"><span class="doxyHighlight">        vsnprintf (long_text.data (), size + 1, format, args_copy);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00517"></a>517</span><span class="doxyLineContent"><span class="doxyHighlight">        text = long_text;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00518"></a>518</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00519"></a>519</span><span class="doxyLineContent"><span class="doxyHighlight">    va_end (args_copy);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00520"></a>520</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00521"></a>521</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00522"></a>522</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00523"></a>523</span><span class="doxyLineContent"><span class="doxyHighlight">        write_without_colours (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a>, text);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00524"></a>524</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00525"></a>525</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00526"></a>526</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (to_console)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00527"></a>527</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00528"></a>528</span><span class="doxyLineContent"><span class="doxyHighlight">        fwrite (text.data (), 1, text.size (), stdout);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00529"></a>529</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00530"></a>530</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00531"></a>531</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00546"></a>546</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00547"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a6b48a4007c568c28fffbc2f2fe3f32e7">547</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a6b48a4007c568c28fffbc2f2fe3f32e7">reporter::write_info</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::vector&lt;std::string&gt;&amp; arguments)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00548"></a>548</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00549"></a>549</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> to_console = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#af33f2f6498a97383cdb75020e32ccf23">route</a> (<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5acaf9b6b99962bf5c2264824231d7a40c">record_kind::info</a>).<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/output-route/#a5ffc75b90c3290f21a2126bba91a759a">console</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00550"></a>550</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00551"></a>551</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (!arguments.empty ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00552"></a>552</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00553"></a>553</span><span class="doxyLineContent"><span class="doxyHighlight">        std::string line;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00554"></a>554</span><span class="doxyLineContent"><span class="doxyHighlight">        line.reserve (256);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00555"></a>555</span><span class="doxyLineContent"><span class="doxyHighlight">        line.append (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a324aa273975068c140ab6eecc7e722c9">comment_prefix</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00556"></a>556</span><span class="doxyLineContent"><span class="doxyHighlight">        line.append (</span><span class="doxyHighlightStringLiteral">"Running: "</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00557"></a>557</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00558"></a>558</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// Append only the file name part of argv[0].</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00559"></a>559</span><span class="doxyLineContent"><span class="doxyHighlight">        line.append (<a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-utility-functions/#ga791f22f0c85b6436c9016821907b0653">utility::extract_file_name</a> (arguments[0].c_str ()));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00560"></a>560</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00561"></a>561</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> i = 1; i &lt; arguments.size (); ++i)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00562"></a>562</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00563"></a>563</span><span class="doxyLineContent"><span class="doxyHighlight">            line.append (</span><span class="doxyHighlightStringLiteral">" "</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00564"></a>564</span><span class="doxyLineContent"><span class="doxyHighlight">            line.append (arguments[i]);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00565"></a>565</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00566"></a>566</span><span class="doxyLineContent"><span class="doxyHighlight">        line.append (</span><span class="doxyHighlightStringLiteral">"\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00567"></a>567</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00568"></a>568</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">write_line</a> (to_console, </span><span class="doxyHighlightStringLiteral">"%s"</span><span class="doxyHighlight">, line.c_str ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00569"></a>569</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00570"></a>570</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00571"></a>571</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00572"></a>572</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// Build the "Built with ..." line, including the compiler version</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00573"></a>573</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// (via __VERSION__); the same line goes to the file and to stdout.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00574"></a>574</span><span class="doxyLineContent"><span class="doxyHighlight">      std::string line;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00575"></a>575</span><span class="doxyLineContent"><span class="doxyHighlight">      line.reserve (256);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00576"></a>576</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a324aa273975068c140ab6eecc7e722c9">comment_prefix</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00577"></a>577</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">"Built with "</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00578"></a>578</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00579"></a>579</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">"clang "</span><span class="doxyHighlight"> __VERSION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00580"></a>580</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#elif defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00581"></a>581</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">"GCC "</span><span class="doxyHighlight"> __VERSION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00582"></a>582</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#elif defined(_MSC_VER)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00583"></a>583</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">"MSVC"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00584"></a>584</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> msvc_ver[16];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00585"></a>585</span><span class="doxyLineContent"><span class="doxyHighlight">      snprintf (msvc_ver, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (msvc_ver), </span><span class="doxyHighlightStringLiteral">" - %d"</span><span class="doxyHighlight">, _MSC_VER);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00586"></a>586</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (msvc_ver);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00587"></a>587</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00588"></a>588</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">"an unknown compiler"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00589"></a>589</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00590"></a>590</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if !(defined(__APPLE__) || defined(__linux__) || defined(__unix__) \</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00591"></a>591</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">      || defined(_WIN32))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00592"></a>592</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// This is relevant only on bare-metal.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00593"></a>593</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__ARM_PCS_VFP) || defined(__ARM_FP)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00594"></a>594</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">", with FP"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00595"></a>595</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00596"></a>596</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">", no FP"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00597"></a>597</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__ARM_PCS_VFP) || defined(__ARM_FP)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00598"></a>598</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// bare-metal only</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00599"></a>599</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__cpp_exceptions)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00600"></a>600</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">", with exceptions"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00601"></a>601</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00602"></a>602</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">", no exceptions"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00603"></a>603</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__cpp_exceptions)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00604"></a>604</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_DEBUG_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00605"></a>605</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">", with MICRO_OS_PLUS_DEBUG_ENABLED"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00606"></a>606</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(MICRO_OS_PLUS_DEBUG_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00607"></a>607</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00608"></a>608</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">", with MICRO_OS_PLUS_DIAG_TRACE_ENABLED"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00609"></a>609</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00610"></a>610</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00611"></a>611</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">write_line</a> (to_console, </span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, line.c_str ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00612"></a>612</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00613"></a>613</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00614"></a>614</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00621"></a>621</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00622"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a804b593aefa158d92a72da43de57d242">622</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a804b593aefa158d92a72da43de57d242">reporter::flush_streams</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00623"></a>623</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00624"></a>624</span><span class="doxyLineContent"><span class="doxyHighlight">    fflush (stdout);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00625"></a>625</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a> != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00626"></a>626</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00627"></a>627</span><span class="doxyLineContent"><span class="doxyHighlight">        fflush (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00628"></a>628</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00629"></a>629</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00630"></a>630</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00635"></a>635</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">bool</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00636"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a083ecdfa952d7f8c372a61fbea309357">636</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a083ecdfa952d7f8c372a61fbea309357">reporter::has_output_file_error</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00637"></a>637</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00638"></a>638</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0d73674812cca717a754137b4b26ed89">has_output_file_error_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00639"></a>639</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00640"></a>640</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00641"></a>641</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00642"></a>642</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00650"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#af4b5f0d3207f22b402bf4079a7547c1c">650</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00651"></a>651</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a54158cb2ca77354223506355247cab9a">reporter::operator&lt;&lt;</a>(<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a>&amp; (*func) (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a>&amp;))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00652"></a>652</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00653"></a>653</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Call the endl function.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00654"></a>654</span><span class="doxyLineContent"><span class="doxyHighlight">    (*func) (*this);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00655"></a>655</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00656"></a>656</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00657"></a>657</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00664"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aedfa17028026f6eaa871214da441e90c">664</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00665"></a>665</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a54158cb2ca77354223506355247cab9a">reporter::operator&lt;&lt;</a>(<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/indentation">indentation</a> m)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00666"></a>666</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00667"></a>667</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>.append (m.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/indentation/#a6b8b1c2610c1f1591bc87068deeefd5a">level</a> * <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7ee7d450c03e89bb0beb6cd97056aa4e">indent_size_</a>, </span><span class="doxyHighlightCharLiteral">' '</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00668"></a>668</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00669"></a>669</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00670"></a>670</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00676"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a54158cb2ca77354223506355247cab9a">676</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00677"></a>677</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a54158cb2ca77354223506355247cab9a">reporter::operator&lt;&lt;</a>(std::string_view sv)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00678"></a>678</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00679"></a>679</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>.append (sv);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00680"></a>680</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00681"></a>681</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00682"></a>682</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00688"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5d29d78c80c20d3fe96ac9d0f4a969b3">688</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00689"></a>689</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a54158cb2ca77354223506355247cab9a">reporter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> c)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00690"></a>690</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00691"></a>691</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>.append (1, c);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00692"></a>692</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00693"></a>693</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00694"></a>694</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00703"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ad84ba0969733f2120622d26951259f95">703</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00704"></a>704</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a54158cb2ca77354223506355247cab9a">reporter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* s)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00705"></a>705</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00706"></a>706</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (s == </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00707"></a>707</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00708"></a>708</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"nullptr"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00709"></a>709</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00710"></a>710</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00711"></a>711</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00712"></a>712</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>.append (s);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00713"></a>713</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00714"></a>714</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00715"></a>715</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00716"></a>716</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00725"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#acbdac50fb2a1302e4a97c8160e7fd7cb">725</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00726"></a>726</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a54158cb2ca77354223506355247cab9a">reporter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00727"></a>727</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00728"></a>728</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>.append (v ? </span><span class="doxyHighlightStringLiteral">"true"</span><span class="doxyHighlight"> : </span><span class="doxyHighlightStringLiteral">"false"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00729"></a>729</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00730"></a>730</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00731"></a>731</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00737"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac894cb9cbf11f2f57acb388310eede4c">737</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00738"></a>738</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a54158cb2ca77354223506355247cab9a">reporter::operator&lt;&lt;</a>(std::nullptr_t)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00739"></a>739</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00740"></a>740</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"nullptr"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00741"></a>741</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00742"></a>742</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00743"></a>743</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00750"></a>750</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00751"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ad9e6ccebc1904f723409ddb0caaddb3e">751</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ad9e6ccebc1904f723409ddb0caaddb3e">reporter::pass</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string&amp; message, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string&amp; expression,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00752"></a>752</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00753"></a>753</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00754"></a>754</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aede54e424adbe77bdb6b87d40f2d3517">output_pass_prefix</a> (message, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00755"></a>755</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00756"></a>756</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (message.empty ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00757"></a>757</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00758"></a>758</span><span class="doxyLineContent"><span class="doxyHighlight">        *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; expression;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00759"></a>759</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00760"></a>760</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00761"></a>761</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a82f4940bc3915b3fdcb58823f9bdb535">output_pass_suffix</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00762"></a>762</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00763"></a>763</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00770"></a>770</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00771"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a406cf77b7adcd5fe9417ce7bce4f3afb">771</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a406cf77b7adcd5fe9417ce7bce4f3afb">reporter::fail</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info">failure_info</a>&amp; failure, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string&amp; expression,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00772"></a>772</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00773"></a>773</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00774"></a>774</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> begin = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>.size ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00775"></a>775</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00776"></a>776</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a24888ee49f3e3abb1a849e309a099189">output_fail_prefix</a> (failure.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info/#ad7484cdab2c4142c2df255dc9aadfea6">message</a>, failure.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info/#a6d4c667be4b4a4709ea29505c9d23f12">has_expression</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00777"></a>777</span><span class="doxyLineContent"><span class="doxyHighlight">                        failure.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info/#a8c259595885388a6a550576d1d3fab35">location</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00778"></a>778</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00779"></a>779</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (failure.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info/#a6d4c667be4b4a4709ea29505c9d23f12">has_expression</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00780"></a>780</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00781"></a>781</span><span class="doxyLineContent"><span class="doxyHighlight">        *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; expression;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00782"></a>782</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00783"></a>783</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00784"></a>784</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#adce64d6a989f193c1d0c306039a3639c">output_fail_suffix</a> (failure.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info/#a8c259595885388a6a550576d1d3fab35">location</a>, failure.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info/#af7c2c1b52b97d5d2af89155e16bf8c41">kind</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00785"></a>785</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00786"></a>786</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2d5e5125b8c71fe0dedbe92d730647ec">mark_failure</a> (begin);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00787"></a>787</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00788"></a>788</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00794"></a>794</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00795"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5859ce31641330b243cfb5d1c6080859">795</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5859ce31641330b243cfb5d1c6080859">reporter::clear_buffer</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00796"></a>796</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00797"></a>797</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>.clear ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00798"></a>798</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ab8acd7e0c7bc5240a0912affd115305b">failures_</a>.clear ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00799"></a>799</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a970a08a00e70f1574033085350656230">buffer_has_failures_</a> = </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00800"></a>800</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00801"></a>801</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00809"></a>809</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00810"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac6dca3d3fa34870f3960fe5e226e45d8">810</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac6dca3d3fa34870f3960fe5e226e45d8">reporter::format_elapsed_time</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch">stopwatch</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch">stopwatch</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00811"></a>811</span><span class="doxyLineContent"><span class="doxyHighlight">                                 </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> (&amp;message)[<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2bf85bc5dd65df1816b52b7fd7c6c627">elapsed_time_size_</a>])</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00812"></a>812</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00813"></a>813</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> elapsed = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch">stopwatch</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch/#a3719382123c6741054a89e4f76b55d90">elapsed</a> ().count ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00814"></a>814</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (elapsed &gt; 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00815"></a>815</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00816"></a>816</span><span class="doxyLineContent"><span class="doxyHighlight">        snprintf (message, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (message),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00817"></a>817</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">", time: %"</span><span class="doxyHighlight"> PRIu32 </span><span class="doxyHighlightStringLiteral">".%03"</span><span class="doxyHighlight"> PRIu32 </span><span class="doxyHighlightStringLiteral">" ms"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00818"></a>818</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">uint32_t</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (elapsed / 1000),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00819"></a>819</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">uint32_t</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (elapsed % 1000));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00820"></a>820</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00821"></a>821</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00822"></a>822</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00823"></a>823</span><span class="doxyLineContent"><span class="doxyHighlight">        message[0] = </span><span class="doxyHighlightCharLiteral">'\0'</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00824"></a>824</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00825"></a>825</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00826"></a>826</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00827"></a>827</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00828"></a>828</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00829"></a>829</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">namespace</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00830"></a>830</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00840"></a><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a1ffff9ae8f2024f3bff18ec45b2baaf9">840</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a1ffff9ae8f2024f3bff18ec45b2baaf9">fragment_size</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00841"></a>841</span><span class="doxyLineContent"><span class="doxyHighlight">        = 21 + (std::numeric_limits&lt;size_t&gt;::digits10 + 1);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00842"></a>842</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00853"></a>853</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">*</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00854"></a><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a25afc917399bf6d116b401e47ca8a4d5">854</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a25afc917399bf6d116b401e47ca8a4d5">plural</a> (</span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> count) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00855"></a>855</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00856"></a>856</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> count == 1 ? </span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"> : </span><span class="doxyHighlightStringLiteral">"s"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00857"></a>857</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00858"></a>858</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00873"></a>873</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00874"></a><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a0d696f5039163e76ec2e4005980ca285">874</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a0d696f5039163e76ec2e4005980ca285">format_skipped</a> (</span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> count, </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> (&amp;message)[<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-cpp-/#a1ffff9ae8f2024f3bff18ec45b2baaf9">fragment_size</a>])</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00875"></a>875</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00876"></a>876</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (count &gt; 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00877"></a>877</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00878"></a>878</span><span class="doxyLineContent"><span class="doxyHighlight">          snprintf (message, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (message),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00879"></a>879</span><span class="doxyLineContent"><span class="doxyHighlight">                    </span><span class="doxyHighlightStringLiteral">", %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a> </span><span class="doxyHighlightStringLiteral">" skipped"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00880"></a>880</span><span class="doxyLineContent"><span class="doxyHighlight">                    count);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00881"></a>881</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00882"></a>882</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00883"></a>883</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00884"></a>884</span><span class="doxyLineContent"><span class="doxyHighlight">          message[0] = </span><span class="doxyHighlightCharLiteral">'\0'</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00885"></a>885</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00886"></a>886</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00887"></a>887</span><span class="doxyLineContent"><span class="doxyHighlight">  } </span><span class="doxyHighlightComment">// namespace</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00888"></a>888</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00895"></a>895</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00896"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a6bf3aac88a5e66e2f93eb32c54dbdd14">896</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a6bf3aac88a5e66e2f93eb32c54dbdd14">reporter::format_session_totals</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">runner</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">runner</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00897"></a>897</span><span class="doxyLineContent"><span class="doxyHighlight">                                   </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> (&amp;message)[<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aaa55b147a670878984952ca1112cecd8">totals_size_</a>])</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00898"></a>898</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00899"></a>899</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// The fixed text, four counts, two fragments, and the terminator.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00900"></a>900</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">static_assert</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aaa55b147a670878984952ca1112cecd8">totals_size_</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00901"></a>901</span><span class="doxyLineContent"><span class="doxyHighlight">                       &gt;= 54 + 4 * (std::numeric_limits&lt;size_t&gt;::digits10 + 1)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00902"></a>902</span><span class="doxyLineContent"><span class="doxyHighlight">                              + 2 * (fragment_size - 1),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00903"></a>903</span><span class="doxyLineContent"><span class="doxyHighlight">                   </span><span class="doxyHighlightStringLiteral">"totals_size_ too small for the session totals"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00904"></a>904</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00905"></a>905</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters">counters</a>&amp; totals = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">runner</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a2c8a999cc273356ea10ed34fb12dcf5a">totals</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00906"></a>906</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> suites_count = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">runner</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#ac29e4b993bb3fe795eb8900231cbf5c4">total_suites_count</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00907"></a>907</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00908"></a>908</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> message_skipped_test_cases[fragment_size];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00909"></a>909</span><span class="doxyLineContent"><span class="doxyHighlight">    format_skipped (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a2e5ea7bbb9bd5a05213dee741f08599d">skipped_test_cases</a> (), message_skipped_test_cases);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00910"></a>910</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00911"></a>911</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> message_skipped_suites[fragment_size];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00912"></a>912</span><span class="doxyLineContent"><span class="doxyHighlight">    format_skipped (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">runner</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a2c2a6d7cb45b714026d124d0ca432360">skipped_suites_count</a> (), message_skipped_suites);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00913"></a>913</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00914"></a>914</span><span class="doxyLineContent"><span class="doxyHighlight">    snprintf (message, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (message),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00915"></a>915</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightStringLiteral">"%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00916"></a>916</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightStringLiteral">" check%s passed, %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00917"></a>917</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightStringLiteral">" failed, in %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00918"></a>918</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightStringLiteral">" test case%s%s, %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a> </span><span class="doxyHighlightStringLiteral">" "</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00919"></a>919</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightStringLiteral">"test suite%s%s"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00920"></a>920</span><span class="doxyLineContent"><span class="doxyHighlight">              totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> (), plural (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> ()),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00921"></a>921</span><span class="doxyLineContent"><span class="doxyHighlight">              totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#ab1684c7c6101a4d534356d9d16807bee">failed_checks</a> (), totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">executed_test_cases</a> (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00922"></a>922</span><span class="doxyLineContent"><span class="doxyHighlight">              plural (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">executed_test_cases</a> ()),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00923"></a>923</span><span class="doxyLineContent"><span class="doxyHighlight">              message_skipped_test_cases, suites_count, plural (suites_count),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00924"></a>924</span><span class="doxyLineContent"><span class="doxyHighlight">              message_skipped_suites);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00925"></a>925</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00926"></a>926</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00932"></a>932</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00933"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a570030599ccc9f4133ed6a9eda2c2a1c">933</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a570030599ccc9f4133ed6a9eda2c2a1c">reporter::format_suite_totals</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00934"></a>934</span><span class="doxyLineContent"><span class="doxyHighlight">                                 </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> (&amp;message)[<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aaa55b147a670878984952ca1112cecd8">totals_size_</a>])</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00935"></a>935</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00936"></a>936</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters">counters</a>&amp; totals = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">totals</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00937"></a>937</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00938"></a>938</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> message_skipped[fragment_size];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00939"></a>939</span><span class="doxyLineContent"><span class="doxyHighlight">    format_skipped (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a2e5ea7bbb9bd5a05213dee741f08599d">skipped_test_cases</a> (), message_skipped);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00940"></a>940</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00941"></a>941</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a14690f9880df505f9dd90a9f2c3dfc96">passed</a> ()) [[likely]]</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00942"></a>942</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00943"></a>943</span><span class="doxyLineContent"><span class="doxyHighlight">        snprintf (message, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (message),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00944"></a>944</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">"%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00945"></a>945</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">" check%s in %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00946"></a>946</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">" test case%s%s"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00947"></a>947</span><span class="doxyLineContent"><span class="doxyHighlight">                  totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> (), plural (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> ()),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00948"></a>948</span><span class="doxyLineContent"><span class="doxyHighlight">                  totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">executed_test_cases</a> (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00949"></a>949</span><span class="doxyLineContent"><span class="doxyHighlight">                  plural (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">executed_test_cases</a> ()), message_skipped);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00950"></a>950</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00951"></a>951</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00952"></a>952</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00953"></a>953</span><span class="doxyLineContent"><span class="doxyHighlight">        snprintf (message, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (message),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00954"></a>954</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">"%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00955"></a>955</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">" check%s passed, %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00956"></a>956</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">" failed, in %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00957"></a>957</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">" test case%s%s"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00958"></a>958</span><span class="doxyLineContent"><span class="doxyHighlight">                  totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> (), plural (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> ()),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00959"></a>959</span><span class="doxyLineContent"><span class="doxyHighlight">                  totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#ab1684c7c6101a4d534356d9d16807bee">failed_checks</a> (), totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">executed_test_cases</a> (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00960"></a>960</span><span class="doxyLineContent"><span class="doxyHighlight">                  plural (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a3d33b96c8d1a299929ead1f830e91853">executed_test_cases</a> ()), message_skipped);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00961"></a>961</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00962"></a>962</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00963"></a>963</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00969"></a>969</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00970"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a60b8564f54a6a1230e6d4ce110de93f5">970</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a60b8564f54a6a1230e6d4ce110de93f5">reporter::format_test_case_totals</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00971"></a>971</span><span class="doxyLineContent"><span class="doxyHighlight">                                     </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> (&amp;message)[<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aaa55b147a670878984952ca1112cecd8">totals_size_</a>])</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00972"></a>972</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00973"></a>973</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters">counters</a>&amp; totals = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">totals</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00974"></a>974</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00975"></a>975</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a14690f9880df505f9dd90a9f2c3dfc96">passed</a> ()) [[likely]]</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00976"></a>976</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00977"></a>977</span><span class="doxyLineContent"><span class="doxyHighlight">        snprintf (message, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (message),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00978"></a>978</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">"%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a> </span><span class="doxyHighlightStringLiteral">" check%s"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00979"></a>979</span><span class="doxyLineContent"><span class="doxyHighlight">                  totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> (), plural (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> ()));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00980"></a>980</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00981"></a>981</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00982"></a>982</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00983"></a>983</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> message_test_cases[fragment_size] = </span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00984"></a>984</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a85981e2e55a820cb49ee04aa82bbde56">failed_test_cases</a> () &gt; 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00985"></a>985</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00986"></a>986</span><span class="doxyLineContent"><span class="doxyHighlight">            snprintf (message_test_cases, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (message_test_cases),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00987"></a>987</span><span class="doxyLineContent"><span class="doxyHighlight">                      </span><span class="doxyHighlightStringLiteral">", %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00988"></a>988</span><span class="doxyLineContent"><span class="doxyHighlight">                      </span><span class="doxyHighlightStringLiteral">" test case%s failed"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00989"></a>989</span><span class="doxyLineContent"><span class="doxyHighlight">                      totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a85981e2e55a820cb49ee04aa82bbde56">failed_test_cases</a> (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00990"></a>990</span><span class="doxyLineContent"><span class="doxyHighlight">                      plural (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a85981e2e55a820cb49ee04aa82bbde56">failed_test_cases</a> ()));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00991"></a>991</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00992"></a>992</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00993"></a>993</span><span class="doxyLineContent"><span class="doxyHighlight">        snprintf (message, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (message),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00994"></a>994</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">"%"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00995"></a>995</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">" check%s passed, %"</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#aaec16ed032c8fc52ba753a273b788381">MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00996"></a>996</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">" failed%s"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00997"></a>997</span><span class="doxyLineContent"><span class="doxyHighlight">                  totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> (), plural (totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#a6d478407d2416d3d19a4041fa1c12c9b">passed_checks</a> ()),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00998"></a>998</span><span class="doxyLineContent"><span class="doxyHighlight">                  totals.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#ab1684c7c6101a4d534356d9d16807bee">failed_checks</a> (), message_test_cases);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00999"></a>999</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01000"></a>1000</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01001"></a>1001</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01012"></a>1012</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01013"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5cf73aaf67484b50c25ef42363d49337">1013</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5cf73aaf67484b50c25ef42363d49337">reporter::commit_outer_results</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01014"></a>1014</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01015"></a>1015</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (!<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>.empty ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01016"></a>1016</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01017"></a>1017</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a844e80839c81133b52ee3beabf64d942">commit_buffer</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01018"></a>1018</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01019"></a>1019</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01020"></a>1020</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01021"></a>1021</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01022"></a>1022</span><span class="doxyLineContent"><span class="doxyHighlight">} </span><span class="doxyHighlightComment">// namespace micro_os_plus::micro_test_plus::detail</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01023"></a>1023</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01024"></a>1024</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01025"></a>1025</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01026"></a>1026</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01027"></a>1027</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01028"></a>1028</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.7 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
