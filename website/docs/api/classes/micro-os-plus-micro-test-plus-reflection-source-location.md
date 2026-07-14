---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/classes/micro-os-plus/micro-test-plus/reflection/source-location
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - class

---

<div class="doxyPage">

# `source_location` Class

<p>Local implementation of source location information for diagnostics. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
class micro_os_plus::micro_test_plus::reflection::source_location { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include &lt;<a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>&gt;
</div>

## Public Member Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a3df499675aacb7ab9192cfb9a5371874">file_name</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Retrieve the file name associated with this source location. <a href="#a3df499675aacb7ab9192cfb9a5371874">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aab9d006004611ac0526852a09f675c66">line</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Retrieve the line number associated with this source location. <a href="#aab9d006004611ac0526852a09f675c66">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Private Member Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const char *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ae648fa43322766fbeb3f9103b43bcc4b">file_</a> { "unknown" }</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The file name where the source location was captured. <a href="#ae648fa43322766fbeb3f9103b43bcc4b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">unsigned int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a0e805c2ed2234f2c004fd7196b844fc5">line_</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The line number where the source location was captured. <a href="#a0e805c2ed2234f2c004fd7196b844fc5">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Static Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">static constexpr <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">source_location</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#af2ee3ac5db96f13680291736d58fe327">current</a> (const char *file="unknown", unsigned int line={}) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Obtain the current source location. <a href="#af2ee3ac5db96f13680291736d58fe327">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Local implementation of source location information for diagnostics.</p>


<p>This class provides a lightweight, constexpr-compatible alternative to <span class="doxyComputerOutput">std::source_location</span> for environments lacking C++20 standard support.</p>


<p>It enables retrieval of the file name and line number at the point of invocation, supporting enhanced diagnostics and reporting within the µTest++ framework.</p>


<p>The static <span class="doxyComputerOutput"><a href="#af2ee3ac5db96f13680291736d58fe327">current()</a></span> method captures the current source location, using compiler built-ins where available, or defaulting to <span class="doxyComputerOutput">"unknown"</span> and zero otherwise.</p>


<dl class="doxySectionUser">
<dt>Since</dt>
<dd><p>3.0.0</p></dd>
</dl>


<p>Definition at line 137 of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/reflection-h">reflection.h</a>.</p>


<div class="doxySectionDef">

## Public Member Functions

### file\_name() {#a3df499675aacb7ab9192cfb9a5371874}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::reflection::source_location::file_name (void)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel constexpr">constexpr</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Retrieve the file name associated with this source location.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The file name as a constant character pointer.</p></dd>
</dl>


<p>Returns the file name captured at the time this <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">source_location</a></span> instance was created.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/reflection-h/#l00165">165</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/reflection-h">reflection.h</a>, definition at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reflection-inlines-h/#l00105">105</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reflection-inlines-h">reflection-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a3df499675aacb7ab9192cfb9a5371874">105</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a3df499675aacb7ab9192cfb9a5371874">source_location::file_name</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">106</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">107</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#ae648fa43322766fbeb3f9103b43bcc4b">file_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">108</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="#ae648fa43322766fbeb3f9103b43bcc4b">file_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a7bc806540e65c21095ef1ea1ef970db2">micro_os_plus::micro_test_plus::runner::abort</a>, <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a20077cabbb38559ff5b0f75140fc7eae">micro_os_plus::micro_test_plus::reporter_human::output_fail_prefix_</a> and <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a951a2aa4cb5300a7706709a2336651a8">micro_os_plus::micro_test_plus::reporter_tap::output_fail_suffix_</a>.</p>

</div>
</div>

### line() {#aab9d006004611ac0526852a09f675c66}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::reflection::source_location::line (void)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel constexpr">constexpr</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Retrieve the line number associated with this source location.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The line number as an unsigned integer.</p></dd>
</dl>


<p>Returns the line number captured at the time this <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">source_location</a></span> instance was created.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/reflection-h/#l00175">175</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/reflection-h">reflection.h</a>, definition at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reflection-inlines-h/#l00116">116</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reflection-inlines-h">reflection-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aab9d006004611ac0526852a09f675c66">116</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#aab9d006004611ac0526852a09f675c66">source_location::line</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">117</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">118</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a0e805c2ed2234f2c004fd7196b844fc5">line_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">119</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="#a0e805c2ed2234f2c004fd7196b844fc5">line_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a7bc806540e65c21095ef1ea1ef970db2">micro_os_plus::micro_test_plus::runner::abort</a>, <a href="#af2ee3ac5db96f13680291736d58fe327">current</a>, <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a20077cabbb38559ff5b0f75140fc7eae">micro_os_plus::micro_test_plus::reporter_human::output_fail_prefix_</a> and <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a951a2aa4cb5300a7706709a2336651a8">micro_os_plus::micro_test_plus::reporter_tap::output_fail_suffix_</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Private Member Attributes

### file\_ {#ae648fa43322766fbeb3f9103b43bcc4b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const char* micro_os_plus::micro_test_plus::reflection::source_location::file_ { "unknown" }</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The file name where the source location was captured.</p>

<p>Definition at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/reflection-h/#l00181">181</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/reflection-h">reflection.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ae648fa43322766fbeb3f9103b43bcc4b">181</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* <a href="#ae648fa43322766fbeb3f9103b43bcc4b">file_</a>{ </span><span class="doxyHighlightStringLiteral">"unknown"</span><span class="doxyHighlight"> };</span></span></div>

</div>


<p>Referenced by <a href="#af2ee3ac5db96f13680291736d58fe327">current</a> and <a href="#a3df499675aacb7ab9192cfb9a5371874">file_name</a>.</p>

</div>
</div>

### line\_ {#a0e805c2ed2234f2c004fd7196b844fc5}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">unsigned int micro_os_plus::micro_test_plus::reflection::source_location::line_ {}</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The line number where the source location was captured.</p>

<p>Definition at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/reflection-h/#l00186">186</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/reflection-h">reflection.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a0e805c2ed2234f2c004fd7196b844fc5">186</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> <a href="#a0e805c2ed2234f2c004fd7196b844fc5">line_</a>{};</span></span></div>

</div>


<p>Referenced by <a href="#af2ee3ac5db96f13680291736d58fe327">current</a> and <a href="#aab9d006004611ac0526852a09f675c66">line</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Static Functions

### current() {#af2ee3ac5db96f13680291736d58fe327}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">source_location micro_os_plus::micro_test_plus::reflection::source_location::current (const char * file="unknown", unsigned int line={})</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel constexpr">constexpr</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
<span class="doxyMemberLabel static">static</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Obtain the current source location.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">file</td>
<td class="doxyParamItemDescription"><p>The file name (automatically provided by the compiler).</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">line</td>
<td class="doxyParamItemDescription"><p>The line number (automatically provided by the compiler).</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">source_location</a></span> instance with the captured information.</p></dd>
</dl>


<p>Returns a <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">source_location</a></span> instance representing the file name and line number at the point of invocation.</p>


<p>If supported by the compiler, uses built-in macros to capture this information; otherwise, defaults to <span class="doxyComputerOutput">"unknown"</span> and zero.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/reflection-h/#l00148">148</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/reflection-h">reflection.h</a>, definition at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reflection-inlines-h/#l00091">91</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reflection-inlines-h">reflection-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#af2ee3ac5db96f13680291736d58fe327">91</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#af2ee3ac5db96f13680291736d58fe327">source_location::current</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* file, </span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> <a href="#aab9d006004611ac0526852a09f675c66">line</a>) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">92</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">93</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">source_location</a> sl{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">94</span><span class="doxyLineContent"><span class="doxyHighlight">      sl.<a href="#ae648fa43322766fbeb3f9103b43bcc4b">file_</a> = file;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">95</span><span class="doxyLineContent"><span class="doxyHighlight">      sl.<a href="#a0e805c2ed2234f2c004fd7196b844fc5">line_</a> = <a href="#aab9d006004611ac0526852a09f675c66">line</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">96</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> sl;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">97</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="#ae648fa43322766fbeb3f9103b43bcc4b">file_</a>, <a href="#aab9d006004611ac0526852a09f675c66">line</a> and <a href="#a0e805c2ed2234f2c004fd7196b844fc5">line_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/runner/#aa34a0418d54c633630a089eb2b5a61ee">micro_os_plus::micro_test_plus::runner::operator=</a> and <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/subtest/#ad3eb4bb11f1c6fc4631bae8a7215a95e">micro_os_plus::micro_test_plus::subtest::operator=</a>.</p>

</div>
</div>

</div>

<hr/>

The documentation for this class was generated from the following files:

<ul>
<li><a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reflection-inlines-h">reflection-inlines.h</a></li>
<li><a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/reflection-h">reflection.h</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.1 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
