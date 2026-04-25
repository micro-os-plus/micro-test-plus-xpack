---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/classes/micro-os-plus/micro-test-plus/timestamp
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - class

---

<div class="doxyPage">

# `timestamp` Class

<p>A single point-in-time measurement, wrapping a <span class="doxyComputerOutput">timespec</span> value. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
class micro_os_plus::micro_test_plus::timestamp { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include &lt;<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>&gt;
</div>

## Public Constructors Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ace868d5dfb29fd79cfaabbfad218a31d">timestamp</a> () noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Default constructor. Zero-initialises the internal <span class="doxyComputerOutput">timespec</span>. <a href="#ace868d5dfb29fd79cfaabbfad218a31d">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#adaeff7b2b11bc05ac92cb0f71818c1b0">timestamp</a> (const timespec &amp;ts) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructs a timestamp from an existing <span class="doxyComputerOutput">timespec</span> value. <a href="#adaeff7b2b11bc05ac92cb0f71818c1b0">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a60c9fb27c9025cfefa8b2bf5810c16f1">timestamp</a> (const timestamp &amp;)=default</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Defaulted copy constructor. <a href="#a60c9fb27c9025cfefa8b2bf5810c16f1">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a2d27592ce712dc206b0cd78b354e68b3">timestamp</a> (timestamp &amp;&amp;)=default</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Defaulted move constructor. <a href="#a2d27592ce712dc206b0cd78b354e68b3">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#acc5b87e2f3661ac56577b385b98f81fa">~timestamp</a> ()=default</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Defaulted destructor. <a href="#acc5b87e2f3661ac56577b385b98f81fa">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Operators Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/timestamp">timestamp</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a7db661420c0b2333aa80ca9081d505ae">operator=</a> (const timestamp &amp;)=default</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Defaulted copy assignment operator. <a href="#a7db661420c0b2333aa80ca9081d505ae">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/timestamp">timestamp</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#af28dcaf117fa2ed16c226d23f910ddc2">operator=</a> (timestamp &amp;&amp;)=default</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Defaulted move assignment operator. <a href="#af28dcaf117fa2ed16c226d23f910ddc2">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Member Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a9d1c21ae80e89e78e6123e49dc3aeaf2">has_clock</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns true if a monotonic clock is available on this target. <a href="#a9d1c21ae80e89e78e6123e49dc3aeaf2">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const timespec &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a9554e837ad48b787aae15108566d089a">value</a> () const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns a const reference to the underlying <span class="doxyComputerOutput">timespec</span> value. <a href="#a9554e837ad48b787aae15108566d089a">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">timespec &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a8e85da440408240b9b082a3a36de28f4">value</a> () noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns a mutable reference to the underlying <span class="doxyComputerOutput">timespec</span> value. <a href="#a8e85da440408240b9b082a3a36de28f4">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Protected Member Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">timespec</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aa45da56b409a7cf625ce373b7f6a621b">value_</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The underlying <span class="doxyComputerOutput">timespec</span> value. <a href="#aa45da56b409a7cf625ce373b7f6a621b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>A single point-in-time measurement, wrapping a <span class="doxyComputerOutput">timespec</span> value.</p>


<p><span class="doxyComputerOutput">timestamp</span> stores one <span class="doxyComputerOutput">timespec</span> sample obtained from the system clock. It is default-constructible (zero-initialises the <span class="doxyComputerOutput">timespec</span>), copy-constructible, and move-constructible, so that it can be used efficiently in <span class="doxyComputerOutput">std::optional&lt;timestamp&gt;</span> containers.</p>


<p>The <span class="doxyComputerOutput"><a href="#a9d1c21ae80e89e78e6123e49dc3aeaf2">has_clock()</a></span> predicate allows callers to determine whether a real-time clock is available on the target platform before relying on the stored value.</p>


<p>Definition at line 90 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>.</p>


<div class="doxySectionDef">

## Public Constructors

### timestamp() {#ace868d5dfb29fd79cfaabbfad218a31d}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::timestamp::timestamp ()</td>
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

<p>Default constructor. Zero-initialises the internal <span class="doxyComputerOutput">timespec</span>.</p>


<p>On Windows, the current time is captured via <span class="doxyComputerOutput">timespec_get()</span> with <span class="doxyComputerOutput">TIME_UTC</span>. On POSIX platforms with <span class="doxyComputerOutput">CLOCK_MONOTONIC</span> defined, <span class="doxyComputerOutput">clock_gettime(CLOCK_MONOTONIC)</span> is used to obtain a monotonic timestamp. On platforms where neither macro is defined, <span class="doxyComputerOutput">value_</span> remains zero-initialised.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00096">96</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/timings-cpp/#l00071">71</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/timings-cpp">timings.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ace868d5dfb29fd79cfaabbfad218a31d">71</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ace868d5dfb29fd79cfaabbfad218a31d">timestamp::timestamp</a> () noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">72</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">73</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(_WIN32)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">74</span><span class="doxyLineContent"><span class="doxyHighlight">    timespec_get (&amp;<a href="#aa45da56b409a7cf625ce373b7f6a621b">value_</a>, TIME_UTC);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">75</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#elif defined(CLOCK_MONOTONIC)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">76</span><span class="doxyLineContent"><span class="doxyHighlight">    clock_gettime (CLOCK_MONOTONIC, &amp;<a href="#aa45da56b409a7cf625ce373b7f6a621b">value_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">77</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">78</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#aa45da56b409a7cf625ce373b7f6a621b">value_</a>.</p>


<p>Referenced by <a href="#a60c9fb27c9025cfefa8b2bf5810c16f1">timestamp</a>, <a href="#a2d27592ce712dc206b0cd78b354e68b3">timestamp</a>, <a href="#a7db661420c0b2333aa80ca9081d505ae">operator=</a> and <a href="#af28dcaf117fa2ed16c226d23f910ddc2">operator=</a>.</p>

</div>
</div>

### timestamp() {#adaeff7b2b11bc05ac92cb0f71818c1b0}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::timestamp::timestamp (const timespec &amp; ts)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Constructs a timestamp from an existing <span class="doxyComputerOutput">timespec</span> value.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">ts</td>
<td class="doxyParamItemDescription"><p>The <span class="doxyComputerOutput">timespec</span> value to store.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00103">103</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#adaeff7b2b11bc05ac92cb0f71818c1b0">103</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#adaeff7b2b11bc05ac92cb0f71818c1b0">timestamp</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> timespec&amp; ts) noexcept : <a href="#aa45da56b409a7cf625ce373b7f6a621b">value_</a>{ ts }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">104</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">105</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="#aa45da56b409a7cf625ce373b7f6a621b">value_</a>.</p>

</div>
</div>

### timestamp() {#a60c9fb27c9025cfefa8b2bf5810c16f1}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::timestamp::timestamp (const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/timestamp">timestamp</a> &amp;)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel default">default</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Defaulted copy constructor.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00113">113</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>.</p>


<p>Reference <a href="#ace868d5dfb29fd79cfaabbfad218a31d">timestamp</a>.</p>

</div>
</div>

### timestamp() {#a2d27592ce712dc206b0cd78b354e68b3}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::timestamp::timestamp (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/timestamp">timestamp</a> &amp;&amp;)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel default">default</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Defaulted move constructor.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00118">118</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>.</p>


<p>Reference <a href="#ace868d5dfb29fd79cfaabbfad218a31d">timestamp</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Destructor

### \~timestamp() {#acc5b87e2f3661ac56577b385b98f81fa}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::timestamp::~timestamp ()</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel default">default</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Defaulted destructor.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00135">135</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Operators

### operator=() {#a7db661420c0b2333aa80ca9081d505ae}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">timestamp &amp; micro_os_plus::micro_test_plus::timestamp::operator= (const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/timestamp">timestamp</a> &amp;)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel default">default</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Defaulted copy assignment operator.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00124">124</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>.</p>


<p>Reference <a href="#ace868d5dfb29fd79cfaabbfad218a31d">timestamp</a>.</p>

</div>
</div>

### operator=() {#af28dcaf117fa2ed16c226d23f910ddc2}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">timestamp &amp; micro_os_plus::micro_test_plus::timestamp::operator= (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/timestamp">timestamp</a> &amp;&amp;)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel default">default</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Defaulted move assignment operator.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00130">130</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>.</p>


<p>Reference <a href="#ace868d5dfb29fd79cfaabbfad218a31d">timestamp</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Member Functions

### has\_clock() {#a9d1c21ae80e89e78e6123e49dc3aeaf2}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::timestamp::has_clock (void)</td>
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

<p>Returns true if a monotonic clock is available on this target.</p>


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
<td class="doxyParamItemDescription"><p>A real-time clock is available and timestamps are valid.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">false</td>
<td class="doxyParamItemDescription"><p>No clock is available; timing data should be ignored.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Returns <span class="doxyComputerOutput">true</span> if at least one of the <span class="doxyComputerOutput">tv_sec</span> or <span class="doxyComputerOutput">tv_nsec</span> fields of the underlying <span class="doxyComputerOutput">timespec</span> is non-zero, indicating that a valid clock reading was successfully captured.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00146">146</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/timings-cpp/#l00087">87</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/timings-cpp">timings.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a9d1c21ae80e89e78e6123e49dc3aeaf2">87</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a9d1c21ae80e89e78e6123e49dc3aeaf2">timestamp::has_clock</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">88</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">89</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#aa45da56b409a7cf625ce373b7f6a621b">value_</a>.tv_sec != 0 || <a href="#aa45da56b409a7cf625ce373b7f6a621b">value_</a>.tv_nsec != 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">90</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#aa45da56b409a7cf625ce373b7f6a621b">value_</a>.</p>

</div>
</div>

### value() {#a9554e837ad48b787aae15108566d089a}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const timespec &amp; micro_os_plus::micro_test_plus::timestamp::value ()</td>
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

<p>Returns a const reference to the underlying <span class="doxyComputerOutput">timespec</span> value.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A const reference to the stored <span class="doxyComputerOutput">timespec</span>.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00169">169</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a9554e837ad48b787aae15108566d089a">169</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a9554e837ad48b787aae15108566d089a">value</a> () const noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">170</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">171</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#aa45da56b409a7cf625ce373b7f6a621b">value_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">172</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="#aa45da56b409a7cf625ce373b7f6a621b">value_</a>.</p>

</div>
</div>

### value() {#a8e85da440408240b9b082a3a36de28f4}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">timespec &amp; micro_os_plus::micro_test_plus::timestamp::value ()</td>
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

<p>Returns a mutable reference to the underlying <span class="doxyComputerOutput">timespec</span> value.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A reference to the stored <span class="doxyComputerOutput">timespec</span>.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00156">156</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a8e85da440408240b9b082a3a36de28f4">156</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a8e85da440408240b9b082a3a36de28f4">value</a> () noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">157</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">158</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#aa45da56b409a7cf625ce373b7f6a621b">value_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">159</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="#aa45da56b409a7cf625ce373b7f6a621b">value_</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Protected Member Attributes

### value\_ {#aa45da56b409a7cf625ce373b7f6a621b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">timespec micro_os_plus::micro_test_plus::timestamp::value_ {}</td>
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

<p>The underlying <span class="doxyComputerOutput">timespec</span> value.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00178">178</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aa45da56b409a7cf625ce373b7f6a621b">178</a></span><span class="doxyLineContent"><span class="doxyHighlight">    timespec <a href="#aa45da56b409a7cf625ce373b7f6a621b">value_</a>{};</span></span></div>

</div>


<p>Referenced by <a href="#ace868d5dfb29fd79cfaabbfad218a31d">timestamp</a>, <a href="#adaeff7b2b11bc05ac92cb0f71818c1b0">timestamp</a>, <a href="#a9d1c21ae80e89e78e6123e49dc3aeaf2">has_clock</a>, <a href="#a9554e837ad48b787aae15108566d089a">value</a> and <a href="#a8e85da440408240b9b082a3a36de28f4">value</a>.</p>

</div>
</div>

</div>

<hr/>

The documentation for this class was generated from the following files:

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/src/timings-cpp">timings.cpp</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.1.0-pre by <a href="https://www.doxygen.nl">Doxygen</a> 1.14.0.</p>

</div>
