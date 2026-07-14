---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/classes/micro-os-plus/micro-test-plus/detail/timestamp
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
class micro_os_plus::micro_test_plus::detail::timestamp { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include &lt;<a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>&gt;
</div>

## Public Constructors Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a3021a3477870bda369e22bdf085bf7a7">timestamp</a> () noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Default constructor. Zero-initialises the internal <span class="doxyComputerOutput">timespec</span>. <a href="#a3021a3477870bda369e22bdf085bf7a7">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a5877a6dda459f5dc695f0e4569175a82">timestamp</a> (const timespec &amp;ts) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructs a timestamp from an existing <span class="doxyComputerOutput">timespec</span> value. <a href="#a5877a6dda459f5dc695f0e4569175a82">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a25cc87189f5ec1dbdef3302de6408d62">timestamp</a> (const timestamp &amp;)=default</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Defaulted copy constructor. <a href="#a25cc87189f5ec1dbdef3302de6408d62">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a78ec32dd29a858de635f6be2a4fd3f8f">timestamp</a> (timestamp &amp;&amp;)=default</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Defaulted move constructor. <a href="#a78ec32dd29a858de635f6be2a4fd3f8f">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a1edc35b9931f3fdb714daf9cae3da73e">~timestamp</a> ()=default</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Defaulted destructor. <a href="#a1edc35b9931f3fdb714daf9cae3da73e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Operators Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a3021a3477870bda369e22bdf085bf7a7">timestamp</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a91c4b65a10407ab3c2a65343b924902b">operator=</a> (const timestamp &amp;)=default</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Defaulted copy assignment operator. <a href="#a91c4b65a10407ab3c2a65343b924902b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a3021a3477870bda369e22bdf085bf7a7">timestamp</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a790a0f4322a690f7ab6591ada80222a0">operator=</a> (timestamp &amp;&amp;)=default</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Defaulted move assignment operator. <a href="#a790a0f4322a690f7ab6591ada80222a0">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ae5494fb57bcc3b577c914a0cc95ff667">has_clock</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns true if a monotonic clock is available on this target. <a href="#ae5494fb57bcc3b577c914a0cc95ff667">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const timespec &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a557741d17d1edd54c30a9fb689d27275">value</a> () const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns a const reference to the underlying <span class="doxyComputerOutput">timespec</span> value. <a href="#a557741d17d1edd54c30a9fb689d27275">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">timespec &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a3d67310c280413bdd857d975daa84eac">value</a> () noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns a mutable reference to the underlying <span class="doxyComputerOutput">timespec</span> value. <a href="#a3d67310c280413bdd857d975daa84eac">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a62c9539975cee7a03be62eb0a903bbf3">value_</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The underlying <span class="doxyComputerOutput">timespec</span> value. <a href="#a62c9539975cee7a03be62eb0a903bbf3">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>A single point-in-time measurement, wrapping a <span class="doxyComputerOutput">timespec</span> value.</p>


<p><span class="doxyComputerOutput"><a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp">timestamp</a></span> stores one <span class="doxyComputerOutput">timespec</span> sample obtained from the system clock. It is default-constructible (zero-initialises the <span class="doxyComputerOutput">timespec</span>), copy-constructible, and move-constructible, so that it can be used efficiently in <span class="doxyComputerOutput">std::optional&lt;<a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp">timestamp</a>&gt;</span> containers.</p>


<p>The <span class="doxyComputerOutput"><a href="#ae5494fb57bcc3b577c914a0cc95ff667">has_clock()</a></span> predicate allows callers to determine whether a real-time clock is available on the target platform before relying on the stored value.</p>


<p>Definition at line 93 of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>.</p>


<div class="doxySectionDef">

## Public Constructors

### timestamp() {#a3021a3477870bda369e22bdf085bf7a7}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::timestamp::timestamp ()</td>
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


<p>On Windows, the current time is captured via <span class="doxyComputerOutput">timespec_get()</span> with <span class="doxyComputerOutput">TIME_UTC</span>. On POSIX platforms with <span class="doxyComputerOutput">CLOCK_MONOTONIC</span> defined, <span class="doxyComputerOutput">clock_gettime(CLOCK_MONOTONIC)</span> is used to obtain a monotonic timestamp. On platforms where neither macro is defined, <span class="doxyComputerOutput"><a href="#a62c9539975cee7a03be62eb0a903bbf3">value_</a></span> remains zero-initialised.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00099">99</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>, definition at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/src/timings-cpp/#l00079">79</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/src/timings-cpp">timings.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a3021a3477870bda369e22bdf085bf7a7">79</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a3021a3477870bda369e22bdf085bf7a7">timestamp::timestamp</a> () noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">80</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">81</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(_WIN32)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">82</span><span class="doxyLineContent"><span class="doxyHighlight">    timespec_get (&amp;<a href="#a62c9539975cee7a03be62eb0a903bbf3">value_</a>, TIME_UTC);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">83</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#elif defined(CLOCK_MONOTONIC)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">84</span><span class="doxyLineContent"><span class="doxyHighlight">    clock_gettime (CLOCK_MONOTONIC, &amp;<a href="#a62c9539975cee7a03be62eb0a903bbf3">value_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">85</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">86</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a62c9539975cee7a03be62eb0a903bbf3">value_</a>.</p>


<p>Referenced by <a href="#a25cc87189f5ec1dbdef3302de6408d62">timestamp</a>, <a href="#a78ec32dd29a858de635f6be2a4fd3f8f">timestamp</a>, <a href="#a91c4b65a10407ab3c2a65343b924902b">operator=</a> and <a href="#a790a0f4322a690f7ab6591ada80222a0">operator=</a>.</p>

</div>
</div>

### timestamp() {#a5877a6dda459f5dc695f0e4569175a82}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::timestamp::timestamp (const timespec &amp; ts)</td>
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

<p>Stores the supplied <span class="doxyComputerOutput">timespec</span> value in the <span class="doxyComputerOutput"><a href="#a62c9539975cee7a03be62eb0a903bbf3">value_</a></span> member.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00106">106</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>, definition at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/timings-inlines-h/#l00057">57</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/timings-inlines-h">timings-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a5877a6dda459f5dc695f0e4569175a82">57</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">inline</span><span class="doxyHighlight"> <a href="#a3021a3477870bda369e22bdf085bf7a7">timestamp::timestamp</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> timespec&amp; ts) noexcept : <a href="#a62c9539975cee7a03be62eb0a903bbf3">value_</a>{ ts }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">58</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">59</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a62c9539975cee7a03be62eb0a903bbf3">value_</a>.</p>

</div>
</div>

### timestamp() {#a25cc87189f5ec1dbdef3302de6408d62}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::timestamp::timestamp (const timestamp &amp;)</td>
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

<p>Definition at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00115">115</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>.</p>


<p>Reference <a href="#a3021a3477870bda369e22bdf085bf7a7">timestamp</a>.</p>

</div>
</div>

### timestamp() {#a78ec32dd29a858de635f6be2a4fd3f8f}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::timestamp::timestamp (timestamp &amp;&amp;)</td>
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

<p>Definition at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00120">120</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>.</p>


<p>Reference <a href="#a3021a3477870bda369e22bdf085bf7a7">timestamp</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Destructor

### \~timestamp() {#a1edc35b9931f3fdb714daf9cae3da73e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::timestamp::~timestamp ()</td>
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

<p>Definition at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00139">139</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>.</p>


<p>Reference <a href="#a3d67310c280413bdd857d975daa84eac">value</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Operators

### operator=() {#a91c4b65a10407ab3c2a65343b924902b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">timestamp &amp; micro_os_plus::micro_test_plus::detail::timestamp::operator= (const <a href="#a3021a3477870bda369e22bdf085bf7a7">timestamp</a> &amp;)</td>
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

<p>Definition at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00126">126</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>.</p>


<p>Reference <a href="#a3021a3477870bda369e22bdf085bf7a7">timestamp</a>.</p>

</div>
</div>

### operator=() {#a790a0f4322a690f7ab6591ada80222a0}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">timestamp &amp; micro_os_plus::micro_test_plus::detail::timestamp::operator= (<a href="#a3021a3477870bda369e22bdf085bf7a7">timestamp</a> &amp;&amp;)</td>
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

<p>Definition at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00133">133</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>.</p>


<p>Reference <a href="#a3021a3477870bda369e22bdf085bf7a7">timestamp</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Member Functions

### has\_clock() {#ae5494fb57bcc3b577c914a0cc95ff667}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::detail::timestamp::has_clock (void)</td>
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


<p>Declaration at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00150">150</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>, definition at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/src/timings-cpp/#l00095">95</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/src/timings-cpp">timings.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ae5494fb57bcc3b577c914a0cc95ff667">95</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ae5494fb57bcc3b577c914a0cc95ff667">timestamp::has_clock</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">96</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">97</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a62c9539975cee7a03be62eb0a903bbf3">value_</a>.tv_sec != 0 || <a href="#a62c9539975cee7a03be62eb0a903bbf3">value_</a>.tv_nsec != 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">98</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a62c9539975cee7a03be62eb0a903bbf3">value_</a>.</p>

</div>
</div>

### value() {#a557741d17d1edd54c30a9fb689d27275}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const timespec &amp; micro_os_plus::micro_test_plus::detail::timestamp::value ()</td>
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


<p>Returns a const reference to the <span class="doxyComputerOutput"><a href="#a62c9539975cee7a03be62eb0a903bbf3">value_</a></span> member.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00170">170</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>, definition at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/timings-inlines-h/#l00076">76</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/timings-inlines-h">timings-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a557741d17d1edd54c30a9fb689d27275">76</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a3d67310c280413bdd857d975daa84eac">timestamp::value</a> () const noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">77</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">78</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a62c9539975cee7a03be62eb0a903bbf3">value_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">79</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a62c9539975cee7a03be62eb0a903bbf3">value_</a>.</p>

</div>
</div>

### value() {#a3d67310c280413bdd857d975daa84eac}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">timespec &amp; micro_os_plus::micro_test_plus::detail::timestamp::value ()</td>
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


<p>Returns a mutable reference to the <span class="doxyComputerOutput"><a href="#a62c9539975cee7a03be62eb0a903bbf3">value_</a></span> member.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00160">160</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>, definition at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/timings-inlines-h/#l00066">66</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/timings-inlines-h">timings-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a3d67310c280413bdd857d975daa84eac">66</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a3d67310c280413bdd857d975daa84eac">timestamp::value</a> () noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">67</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">68</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a62c9539975cee7a03be62eb0a903bbf3">value_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">69</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a62c9539975cee7a03be62eb0a903bbf3">value_</a>.</p>


<p>Referenced by <a href="#a1edc35b9931f3fdb714daf9cae3da73e">~timestamp</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Protected Member Attributes

### value\_ {#a62c9539975cee7a03be62eb0a903bbf3}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">timespec micro_os_plus::micro_test_plus::detail::timestamp::value_ {}</td>
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

<p>Definition at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h/#l00176">176</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a62c9539975cee7a03be62eb0a903bbf3">176</a></span><span class="doxyLineContent"><span class="doxyHighlight">      timespec <a href="#a62c9539975cee7a03be62eb0a903bbf3">value_</a>{};</span></span></div>

</div>


<p>Referenced by <a href="#a3021a3477870bda369e22bdf085bf7a7">timestamp</a>, <a href="#a5877a6dda459f5dc695f0e4569175a82">timestamp</a>, <a href="#ae5494fb57bcc3b577c914a0cc95ff667">has_clock</a>, <a href="#a557741d17d1edd54c30a9fb689d27275">value</a> and <a href="#a3d67310c280413bdd857d975daa84eac">value</a>.</p>

</div>
</div>

</div>

<hr/>

The documentation for this class was generated from the following files:

<ul>
<li><a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/timings-inlines-h">timings-inlines.h</a></li>
<li><a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/timings-h">timings.h</a></li>
<li><a href="/micro-test-plus-xpack-webpreview/docs/api/files/src/timings-cpp">timings.cpp</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.1 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
