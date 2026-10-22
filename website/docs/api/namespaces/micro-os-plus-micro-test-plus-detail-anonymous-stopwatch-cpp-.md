---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-stopwatch-cpp-
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - namespace

---

<div class="doxyPage">

# `anonymous{stopwatch.cpp}` Namespace

<p>Local helpers of the stopwatch. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
namespace micro_os_plus::micro_test_plus::detail::anonymous{stopwatch.cpp} { ... }
</div>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a34225dca0ef5b70eb98c8eeaa3a05b06">read_clock</a> (timespec &amp;ts) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Reads the system clock. <a href="#a34225dca0ef5b70eb98c8eeaa3a05b06">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Local helpers of the stopwatch.</p>


<p>The unnamed namespace gives the helpers internal linkage, so that they are visible only in this translation unit, and cannot conflict with the names of the application or of the other source files of the framework. They are not declared in any header.</p>


<p>It contains <span class="doxyComputerOutput"><a href="#a34225dca0ef5b70eb98c8eeaa3a05b06">read_clock()</a></span>, which isolates the platform-specific access to the system clock.</p>


<div class="doxySectionDef">

## Functions

### read\_clock() {#a34225dca0ef5b70eb98c8eeaa3a05b06}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::anonymous{stopwatch.cpp}::read_clock (timespec &amp; ts)</td>
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

<p>Reads the system clock.</p>


<p>On Windows, the current time is captured via <span class="doxyComputerOutput">timespec_get()</span> with <span class="doxyComputerOutput">TIME_UTC</span>. On POSIX platforms with <span class="doxyComputerOutput">CLOCK_MONOTONIC</span> defined, <span class="doxyComputerOutput">clock_gettime(CLOCK_MONOTONIC)</span> is used to obtain a monotonic reading. On platforms where neither macro is defined, <span class="doxyComputerOutput">ts</span> is left unchanged.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">[out] ts</td>
<td class="doxyParamItemDescription"><p>The <span class="doxyComputerOutput">timespec</span> where the reading is stored.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/stopwatch-cpp/#l00085">85</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/stopwatch-cpp">stopwatch.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a34225dca0ef5b70eb98c8eeaa3a05b06">85</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a34225dca0ef5b70eb98c8eeaa3a05b06">read_clock</a> (timespec&amp; ts) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">86</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">87</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(_WIN32)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">88</span><span class="doxyLineContent"><span class="doxyHighlight">      timespec_get (&amp;ts, TIME_UTC);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">89</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#elif defined(CLOCK_MONOTONIC)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">90</span><span class="doxyLineContent"><span class="doxyHighlight">      clock_gettime (CLOCK_MONOTONIC, &amp;ts);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">91</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">92</span><span class="doxyLineContent"><span class="doxyHighlight">      (void)ts;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">93</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(_WIN32) || defined(CLOCK_MONOTONIC)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">94</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="#a34225dca0ef5b70eb98c8eeaa3a05b06">read_clock</a>.</p>


<p>Referenced by <a href="#a34225dca0ef5b70eb98c8eeaa3a05b06">read_clock</a>.</p>

</div>
</div>

</div>

<hr/>

The documentation for this namespace was generated from the following file:

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/src/stopwatch-cpp">stopwatch.cpp</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.4 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
