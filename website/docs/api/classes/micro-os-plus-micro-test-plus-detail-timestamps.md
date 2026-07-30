---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/classes/micro-os-plus/micro-test-plus/detail/timestamps
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - class

---

<div class="doxyPage">

# `timestamps` Class

<p>A begin/end timestamp pair used to measure elapsed time. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
class micro_os_plus::micro_test_plus::detail::timestamps { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>"
</div>

## Public Constructors Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a28411e9d980b53accf2a8c5221a1861f">timestamps</a> ()=default</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Default constructor. Both timestamps are uninitialised. <a href="#a28411e9d980b53accf2a8c5221a1861f">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ad9bb8bdb44def63c7ace6e25efa6150e">timestamps</a> (const timestamps &amp;)=delete</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deleted copy constructor to prevent copying. <a href="#ad9bb8bdb44def63c7ace6e25efa6150e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aed7caa5ea1c202dd12403ae9a5b38167">timestamps</a> (timestamps &amp;&amp;)=delete</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deleted move constructor to prevent moving. <a href="#aed7caa5ea1c202dd12403ae9a5b38167">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a29791422e99ae1b77c0d0cefa97bbd88">~timestamps</a> ()=default</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Defaulted destructor. <a href="#a29791422e99ae1b77c0d0cefa97bbd88">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Operators Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a28411e9d980b53accf2a8c5221a1861f">timestamps</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aa003cc61308004bc8e22ce2097e4564b">operator=</a> (const timestamps &amp;)=delete</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deleted copy assignment operator to prevent copying. <a href="#aa003cc61308004bc8e22ce2097e4564b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a28411e9d980b53accf2a8c5221a1861f">timestamps</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#afe37704a6659bbaeb5a21372b5b53b60">operator=</a> (timestamps &amp;&amp;)=delete</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deleted move assignment operator to prevent moving. <a href="#afe37704a6659bbaeb5a21372b5b53b60">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a7e7ade6bb02af23d65e5ceaa958052dd">compute_elapsed_time</a> (uint32_t &amp;milliseconds, uint32_t &amp;microseconds) const</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Computes the elapsed time between begin and end timestamps. <a href="#a7e7ade6bb02af23d65e5ceaa958052dd">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aa0947e2e891064a6b0c36e55dcfc900b">has_begin</a> () const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns true if the begin timestamp has been recorded. <a href="#aa0947e2e891064a6b0c36e55dcfc900b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a66eaffb91df2a7b6b70b8c8005791954">has_end</a> () const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns true if the end timestamp has been recorded. <a href="#a66eaffb91df2a7b6b70b8c8005791954">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a125c87d852257c18749074be3b698ed1">has_timestamps</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns true if both begin and end timestamps are available. <a href="#a125c87d852257c18749074be3b698ed1">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a44ccea73af94c2c106be7aa04c85841b">timestamp_begin</a> (const timespec &amp;ts) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Records the begin timestamp from a caller-supplied value. <a href="#a44ccea73af94c2c106be7aa04c85841b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a1b2077718469ade9fda2e257a0d06293">timestamp_begin</a> (void) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Records the begin timestamp using the current system clock. <a href="#a1b2077718469ade9fda2e257a0d06293">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a465347769933c044abe2448a428d7281">timestamp_end</a> (const timespec &amp;ts) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Records the end timestamp from a caller-supplied value. <a href="#a465347769933c044abe2448a428d7281">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aeb4873587b5be066c69c0ef26d64640b">timestamp_end</a> (void) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Records the end timestamp using the current system clock. <a href="#aeb4873587b5be066c69c0ef26d64640b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Protected Member Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">std::optional&lt; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp">timestamp</a> &gt;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ac621973713cc6e574f7aa70566a4e960">begin_time_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The timestamp recorded at the beginning of the test suite. <a href="#ac621973713cc6e574f7aa70566a4e960">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">std::optional&lt; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp">timestamp</a> &gt;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a85749791b2161ff48e9a1de82c532017">end_time_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The timestamp recorded at the end of the test suite. <a href="#a85749791b2161ff48e9a1de82c532017">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>A begin/end timestamp pair used to measure elapsed time.</p>


<p><span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps">timestamps</a></span> stores an optional begin <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp">timestamp</a></span> and an optional end <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp">timestamp</a></span>. When both are available, <span class="doxyComputerOutput"><a href="#a7e7ade6bb02af23d65e5ceaa958052dd">compute_elapsed_time()</a></span> derives the elapsed interval in milliseconds and microseconds.</p>


<p>Typical usage in the framework:</p>


<ol class="doxyList" type="1">
<li>Call <span class="doxyComputerOutput"><a href="#a1b2077718469ade9fda2e257a0d06293">timestamp_begin()</a></span> just before the test suite or session body executes.</li>
<li>Call <span class="doxyComputerOutput"><a href="#aeb4873587b5be066c69c0ef26d64640b">timestamp_end()</a></span> immediately after it completes.</li>
<li>Pass the elapsed values to the reporter.</li>
</ol>

<p>If the platform does not provide a monotonic clock, the <span class="doxyComputerOutput">std::optional</span> members remain empty and <span class="doxyComputerOutput"><a href="#a125c87d852257c18749074be3b698ed1">has_timestamps()</a></span> returns <span class="doxyComputerOutput">false</span>, so that the reporter can skip timing output.</p>


<p>The class is non-copyable and non-movable to prevent accidental sharing of live timing state.</p>


<p>Definition at line 212 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>.</p>


<div class="doxySectionDef">

## Public Constructors

### timestamps() {#a28411e9d980b53accf2a8c5221a1861f}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::timestamps::timestamps ()</td>
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

<p>Default constructor. Both timestamps are uninitialised.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00218">218</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>.</p>


<p>Referenced by <a href="#ad9bb8bdb44def63c7ace6e25efa6150e">timestamps</a>, <a href="#aed7caa5ea1c202dd12403ae9a5b38167">timestamps</a>, <a href="#aa003cc61308004bc8e22ce2097e4564b">operator=</a> and <a href="#afe37704a6659bbaeb5a21372b5b53b60">operator=</a>.</p>

</div>
</div>

### timestamps() {#ad9bb8bdb44def63c7ace6e25efa6150e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::timestamps::timestamps (const timestamps &amp;)</td>
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

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00223">223</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>.</p>


<p>Reference <a href="#a28411e9d980b53accf2a8c5221a1861f">timestamps</a>.</p>

</div>
</div>

### timestamps() {#aed7caa5ea1c202dd12403ae9a5b38167}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::timestamps::timestamps (timestamps &amp;&amp;)</td>
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

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00228">228</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>.</p>


<p>Reference <a href="#a28411e9d980b53accf2a8c5221a1861f">timestamps</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Destructor

### \~timestamps() {#a29791422e99ae1b77c0d0cefa97bbd88}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::timestamps::~timestamps ()</td>
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

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00247">247</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>.</p>


<p>References <a href="#a7e7ade6bb02af23d65e5ceaa958052dd">compute_elapsed_time</a>, <a href="#a66eaffb91df2a7b6b70b8c8005791954">has_end</a> and <a href="#a125c87d852257c18749074be3b698ed1">has_timestamps</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Operators

### operator=() {#aa003cc61308004bc8e22ce2097e4564b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">timestamps &amp; micro_os_plus::micro_test_plus::detail::timestamps::operator= (const <a href="#a28411e9d980b53accf2a8c5221a1861f">timestamps</a> &amp;)</td>
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

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00234">234</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>.</p>


<p>Reference <a href="#a28411e9d980b53accf2a8c5221a1861f">timestamps</a>.</p>

</div>
</div>

### operator=() {#afe37704a6659bbaeb5a21372b5b53b60}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">timestamps &amp; micro_os_plus::micro_test_plus::detail::timestamps::operator= (<a href="#a28411e9d980b53accf2a8c5221a1861f">timestamps</a> &amp;&amp;)</td>
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

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00241">241</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>.</p>


<p>Reference <a href="#a28411e9d980b53accf2a8c5221a1861f">timestamps</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Member Functions

### compute\_elapsed\_time() {#a7e7ade6bb02af23d65e5ceaa958052dd}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::timestamps::compute_elapsed_time (uint32_t &amp; milliseconds, uint32_t &amp; microseconds)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Computes the elapsed time between begin and end timestamps.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">[out] milliseconds</td>
<td class="doxyParamItemDescription"><p>The elapsed time in whole milliseconds.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">[out] microseconds</td>
<td class="doxyParamItemDescription"><p>The sub-millisecond remainder in microseconds.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Subtracts the begin timestamp from the end timestamp in nanoseconds. If the nanosecond difference is negative, one second is borrowed from the seconds delta to normalise the result. The total elapsed duration in microseconds is then split into whole milliseconds (written to <span class="doxyComputerOutput">milliseconds</span>) and the remainder microseconds (written to <span class="doxyComputerOutput">microseconds</span>). Requires <span class="doxyComputerOutput"><a href="#a125c87d852257c18749074be3b698ed1">has_timestamps()</a></span> to be <span class="doxyComputerOutput">true</span>; behaviour is undefined otherwise.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00334">334</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/timings-cpp/#l00184">184</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/timings-cpp">timings.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a7e7ade6bb02af23d65e5ceaa958052dd">184</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a7e7ade6bb02af23d65e5ceaa958052dd">timestamps::compute_elapsed_time</a> (uint32_t&amp; milliseconds,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">185</span><span class="doxyLineContent"><span class="doxyHighlight">                                    uint32_t&amp; microseconds)</span><span class="doxyHighlightKeyword"> const</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">186</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">  </span><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">187</span><span class="doxyLineContent"><span class="doxyHighlight">    assert (<a href="#a125c87d852257c18749074be3b698ed1">has_timestamps</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">188</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">189</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Precondition: has_timestamps() must be true before calling this method.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">190</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Invoking it with disengaged optionals is undefined behaviour.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">191</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> delta_ns</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">192</span><span class="doxyLineContent"><span class="doxyHighlight">        = <a href="#a85749791b2161ff48e9a1de82c532017">end_time_</a>-&gt;value ().tv_nsec - <a href="#ac621973713cc6e574f7aa70566a4e960">begin_time_</a>-&gt;value ().tv_nsec;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">193</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> delta_s</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">194</span><span class="doxyLineContent"><span class="doxyHighlight">        = <a href="#a85749791b2161ff48e9a1de82c532017">end_time_</a>-&gt;value ().tv_sec - <a href="#ac621973713cc6e574f7aa70566a4e960">begin_time_</a>-&gt;value ().tv_sec;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">195</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (delta_ns &lt; 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">196</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">197</span><span class="doxyLineContent"><span class="doxyHighlight">        delta_ns += 1000000000LL;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">198</span><span class="doxyLineContent"><span class="doxyHighlight">        --delta_s;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">199</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">200</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">201</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Split into milliseconds and microseconds.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">202</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> total_us = delta_s * 1000000LL + delta_ns / 1000LL;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">203</span><span class="doxyLineContent"><span class="doxyHighlight">    milliseconds = </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">uint32_t</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (total_us / 1000LL);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">204</span><span class="doxyLineContent"><span class="doxyHighlight">    microseconds = </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">uint32_t</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (total_us % 1000LL);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">205</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#ac621973713cc6e574f7aa70566a4e960">begin_time_</a>, <a href="#a85749791b2161ff48e9a1de82c532017">end_time_</a> and <a href="#a125c87d852257c18749074be3b698ed1">has_timestamps</a>.</p>


<p>Referenced by <a href="#a29791422e99ae1b77c0d0cefa97bbd88">~timestamps</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a3118ff89506858505f18e8fd368baffc">micro_os_plus::micro_test_plus::reporter_human::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a9a224d34b068e1698c00633ae2341e7f">micro_os_plus::micro_test_plus::reporter_tap::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#ac0a6d2bda91a9afa71346eef59c7f35e">micro_os_plus::micro_test_plus::reporter_human::end_suite</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a8649b62ba8f7ff88501450c5f939ab6d">micro_os_plus::micro_test_plus::reporter_tap::end_suite</a>.</p>

</div>
</div>

### has\_begin() {#aa0947e2e891064a6b0c36e55dcfc900b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::detail::timestamps::has_begin ()</td>
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

<p>Returns true if the begin timestamp has been recorded.</p>


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
<td class="doxyParamItemDescription"><p><span class="doxyComputerOutput"><a href="#a1b2077718469ade9fda2e257a0d06293">timestamp_begin()</a></span> has been called.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">false</td>
<td class="doxyParamItemDescription"><p><span class="doxyComputerOutput"><a href="#a1b2077718469ade9fda2e257a0d06293">timestamp_begin()</a></span> has not been called.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Returns <span class="doxyComputerOutput">true</span> when <span class="doxyComputerOutput"><a href="#ac621973713cc6e574f7aa70566a4e960">begin_time_</a></span> holds a value, i.e. when <span class="doxyComputerOutput"><a href="#a1b2077718469ade9fda2e257a0d06293">timestamp_begin()</a></span> has previously been called.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00300">300</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/timings-inlines-h/#l00089">89</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/timings-inlines-h">timings-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aa0947e2e891064a6b0c36e55dcfc900b">89</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#aa0947e2e891064a6b0c36e55dcfc900b">timestamps::has_begin</a> () const noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">90</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">91</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#ac621973713cc6e574f7aa70566a4e960">begin_time_</a>.has_value ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">92</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#ac621973713cc6e574f7aa70566a4e960">begin_time_</a>.</p>

</div>
</div>

### has\_end() {#a66eaffb91df2a7b6b70b8c8005791954}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::detail::timestamps::has_end ()</td>
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

<p>Returns true if the end timestamp has been recorded.</p>


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
<td class="doxyParamItemDescription"><p><span class="doxyComputerOutput"><a href="#aeb4873587b5be066c69c0ef26d64640b">timestamp_end()</a></span> has been called.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">false</td>
<td class="doxyParamItemDescription"><p><span class="doxyComputerOutput"><a href="#aeb4873587b5be066c69c0ef26d64640b">timestamp_end()</a></span> has not been called.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Returns <span class="doxyComputerOutput">true</span> when <span class="doxyComputerOutput"><a href="#a85749791b2161ff48e9a1de82c532017">end_time_</a></span> holds a value, i.e. when <span class="doxyComputerOutput"><a href="#aeb4873587b5be066c69c0ef26d64640b">timestamp_end()</a></span> has previously been called.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00311">311</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/timings-inlines-h/#l00100">100</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/timings-inlines-h">timings-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a66eaffb91df2a7b6b70b8c8005791954">100</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a66eaffb91df2a7b6b70b8c8005791954">timestamps::has_end</a> () const noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">101</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">102</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a85749791b2161ff48e9a1de82c532017">end_time_</a>.has_value ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">103</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a85749791b2161ff48e9a1de82c532017">end_time_</a>.</p>


<p>Referenced by <a href="#a29791422e99ae1b77c0d0cefa97bbd88">~timestamps</a>.</p>

</div>
</div>

### has\_timestamps() {#a125c87d852257c18749074be3b698ed1}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::detail::timestamps::has_timestamps (void)</td>
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

<p>Returns true if both begin and end timestamps are available.</p>


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
<td class="doxyParamItemDescription"><p>Both timestamps are present and elapsed time can be computed.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">false</td>
<td class="doxyParamItemDescription"><p>At least one timestamp is absent; elapsed time is not available.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Returns <span class="doxyComputerOutput">true</span> only when both the begin and end optional timestamps are engaged and each contains a valid (non-zero) clock reading, as determined by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp/#ae5494fb57bcc3b577c914a0cc95ff667">timestamp::has_clock()</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00324">324</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/timings-cpp/#l00167">167</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/timings-cpp">timings.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a125c87d852257c18749074be3b698ed1">167</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a125c87d852257c18749074be3b698ed1">timestamps::has_timestamps</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">168</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">169</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#ac621973713cc6e574f7aa70566a4e960">begin_time_</a>.has_value () &amp;&amp; <a href="#ac621973713cc6e574f7aa70566a4e960">begin_time_</a>-&gt;has_clock ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">170</span><span class="doxyLineContent"><span class="doxyHighlight">           &amp;&amp; <a href="#a85749791b2161ff48e9a1de82c532017">end_time_</a>.has_value () &amp;&amp; <a href="#a85749791b2161ff48e9a1de82c532017">end_time_</a>-&gt;has_clock ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">171</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#ac621973713cc6e574f7aa70566a4e960">begin_time_</a> and <a href="#a85749791b2161ff48e9a1de82c532017">end_time_</a>.</p>


<p>Referenced by <a href="#a29791422e99ae1b77c0d0cefa97bbd88">~timestamps</a>, <a href="#a7e7ade6bb02af23d65e5ceaa958052dd">compute_elapsed_time</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a3118ff89506858505f18e8fd368baffc">micro_os_plus::micro_test_plus::reporter_human::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a9a224d34b068e1698c00633ae2341e7f">micro_os_plus::micro_test_plus::reporter_tap::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#ac0a6d2bda91a9afa71346eef59c7f35e">micro_os_plus::micro_test_plus::reporter_human::end_suite</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a8649b62ba8f7ff88501450c5f939ab6d">micro_os_plus::micro_test_plus::reporter_tap::end_suite</a>.</p>

</div>
</div>

### timestamp\_begin() {#a44ccea73af94c2c106be7aa04c85841b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::timestamps::timestamp_begin (const timespec &amp; ts)</td>
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

<p>Records the begin timestamp from a caller-supplied value.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">ts</td>
<td class="doxyParamItemDescription"><p>The <span class="doxyComputerOutput">timespec</span> value to use as the begin timestamp.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>If the begin timestamp has not yet been set, a <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp">timestamp</a></span> is constructed in-place from the supplied <span class="doxyComputerOutput">timespec</span> value. Subsequent calls are silently ignored, ensuring idempotent behaviour.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00268">268</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/timings-cpp/#l00118">118</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/timings-cpp">timings.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a44ccea73af94c2c106be7aa04c85841b">118</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a1b2077718469ade9fda2e257a0d06293">timestamps::timestamp_begin</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> timespec&amp; ts) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">119</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">120</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Ensure it is timestamped only once.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">121</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (!<a href="#ac621973713cc6e574f7aa70566a4e960">begin_time_</a>.has_value ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">122</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">123</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#ac621973713cc6e574f7aa70566a4e960">begin_time_</a>.emplace (ts);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">124</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">125</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#ac621973713cc6e574f7aa70566a4e960">begin_time_</a>.</p>

</div>
</div>

### timestamp\_begin() {#a1b2077718469ade9fda2e257a0d06293}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::timestamps::timestamp_begin (void)</td>
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

<p>Records the begin timestamp using the current system clock.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>If the begin timestamp has not yet been set, a <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp">timestamp</a></span> is constructed in-place using the default constructor, which captures the current monotonic time. Subsequent calls are silently ignored, ensuring idempotent behaviour.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00258">258</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/timings-cpp/#l00102">102</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/timings-cpp">timings.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a1b2077718469ade9fda2e257a0d06293">102</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a1b2077718469ade9fda2e257a0d06293">timestamps::timestamp_begin</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">103</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">104</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Ensure it is timestamped only once.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">105</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (!<a href="#ac621973713cc6e574f7aa70566a4e960">begin_time_</a>.has_value ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">106</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">107</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#ac621973713cc6e574f7aa70566a4e960">begin_time_</a>.emplace ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">108</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">109</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#ac621973713cc6e574f7aa70566a4e960">begin_time_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#a4ab3277887dfc4cd8ae84bb4101eae60">micro_os_plus::micro_test_plus::static_suite::run</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a432deda5a8721472e8775cbc98451722">micro_os_plus::micro_test_plus::suite::run</a>.</p>

</div>
</div>

### timestamp\_end() {#a465347769933c044abe2448a428d7281}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::timestamps::timestamp_end (const timespec &amp; ts)</td>
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

<p>Records the end timestamp from a caller-supplied value.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">ts</td>
<td class="doxyParamItemDescription"><p>The <span class="doxyComputerOutput">timespec</span> value to use as the end timestamp.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>If the end timestamp has not yet been set, a <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp">timestamp</a></span> is constructed in-place from the supplied <span class="doxyComputerOutput">timespec</span> value. Subsequent calls are silently ignored, ensuring idempotent behaviour.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00289">289</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/timings-cpp/#l00151">151</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/timings-cpp">timings.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a465347769933c044abe2448a428d7281">151</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#aeb4873587b5be066c69c0ef26d64640b">timestamps::timestamp_end</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> timespec&amp; ts) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">152</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">153</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Ensure it is timestamped only once.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">154</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (!<a href="#a85749791b2161ff48e9a1de82c532017">end_time_</a>.has_value ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">155</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">156</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a85749791b2161ff48e9a1de82c532017">end_time_</a>.emplace (ts);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">157</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">158</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a85749791b2161ff48e9a1de82c532017">end_time_</a>.</p>

</div>
</div>

### timestamp\_end() {#aeb4873587b5be066c69c0ef26d64640b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::timestamps::timestamp_end (void)</td>
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

<p>Records the end timestamp using the current system clock.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>If the end timestamp has not yet been set, a <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp">timestamp</a></span> is constructed in-place using the default constructor, which captures the current monotonic time. Subsequent calls are silently ignored, ensuring idempotent behaviour.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00279">279</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/timings-cpp/#l00135">135</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/timings-cpp">timings.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aeb4873587b5be066c69c0ef26d64640b">135</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#aeb4873587b5be066c69c0ef26d64640b">timestamps::timestamp_end</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">136</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">137</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Ensure it is timestamped only once.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">138</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (!<a href="#a85749791b2161ff48e9a1de82c532017">end_time_</a>.has_value ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">139</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">140</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a85749791b2161ff48e9a1de82c532017">end_time_</a>.emplace ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">141</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">142</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a85749791b2161ff48e9a1de82c532017">end_time_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#a4ab3277887dfc4cd8ae84bb4101eae60">micro_os_plus::micro_test_plus::static_suite::run</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a432deda5a8721472e8775cbc98451722">micro_os_plus::micro_test_plus::suite::run</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Protected Member Attributes

### begin\_time\_ {#ac621973713cc6e574f7aa70566a4e960}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::optional&lt;timestamp&gt; micro_os_plus::micro_test_plus::detail::timestamps::begin_time_</td>
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

<p>The timestamp recorded at the beginning of the test suite.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00341">341</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ac621973713cc6e574f7aa70566a4e960">341</a></span><span class="doxyLineContent"><span class="doxyHighlight">      std::optional&lt;<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp">timestamp</a>&gt; <a href="#ac621973713cc6e574f7aa70566a4e960">begin_time_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#a7e7ade6bb02af23d65e5ceaa958052dd">compute_elapsed_time</a>, <a href="#aa0947e2e891064a6b0c36e55dcfc900b">has_begin</a>, <a href="#a125c87d852257c18749074be3b698ed1">has_timestamps</a>, <a href="#a44ccea73af94c2c106be7aa04c85841b">timestamp_begin</a> and <a href="#a1b2077718469ade9fda2e257a0d06293">timestamp_begin</a>.</p>

</div>
</div>

### end\_time\_ {#a85749791b2161ff48e9a1de82c532017}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::optional&lt;timestamp&gt; micro_os_plus::micro_test_plus::detail::timestamps::end_time_</td>
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

<p>The timestamp recorded at the end of the test suite.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00346">346</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a85749791b2161ff48e9a1de82c532017">346</a></span><span class="doxyLineContent"><span class="doxyHighlight">      std::optional&lt;<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp">timestamp</a>&gt; <a href="#a85749791b2161ff48e9a1de82c532017">end_time_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#a7e7ade6bb02af23d65e5ceaa958052dd">compute_elapsed_time</a>, <a href="#a66eaffb91df2a7b6b70b8c8005791954">has_end</a>, <a href="#a125c87d852257c18749074be3b698ed1">has_timestamps</a>, <a href="#a465347769933c044abe2448a428d7281">timestamp_end</a> and <a href="#aeb4873587b5be066c69c0ef26d64640b">timestamp_end</a>.</p>

</div>
</div>

</div>

<hr/>

The documentation for this class was generated from the following files:

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/timings-inlines-h">timings-inlines.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/src/timings-cpp">timings.cpp</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.2 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
