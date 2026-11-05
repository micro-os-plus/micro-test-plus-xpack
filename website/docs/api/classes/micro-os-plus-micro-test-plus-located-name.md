---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/classes/micro-os-plus/micro-test-plus/located-name
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - class

---

<div class="doxyPage">

# `located_name` Class

<p>A name of a suite or of a test case, with the location where it was given. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
class micro_os_plus::micro_test_plus::located_name { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>"
</div>

## Public Constructors Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;std::size_t N&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemNoTypeNameTemplate" colspan="2" align="left" valign="top"><a href="#a6559d4b0648a5552702a2f5d40ba4db4">located_name</a> (const char(&amp;name)[N], const reflection::source_location &amp;location=reflection::source_location::current())</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructs the name from an array of characters, capturing the location of the caller. <a href="#a6559d4b0648a5552702a2f5d40ba4db4">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a49ca2791ea42fc17bd4f9de133c8adbb">located_name</a> (const std::string &amp;name, const reflection::source_location &amp;location=reflection::source_location::current())</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructs the name from a standard string, capturing the location of the caller. <a href="#a49ca2791ea42fc17bd4f9de133c8adbb">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;typename Pointer_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemNoTypeNameTemplate" colspan="2" align="left" valign="top"><a href="#ab66a15ccc3f4b66fb2f8f897b2cb91ec">located_name</a> (Pointer_T name, const reflection::source_location &amp;location=reflection::source_location::current())</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructs the name from a C string, capturing the location of the caller. <a href="#ab66a15ccc3f4b66fb2f8f897b2cb91ec">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a2be70223f532513d9f1ce311b436b72f">located_name</a> (std::string &amp;&amp;name, const reflection::source_location &amp;location=reflection::source_location::current())</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructs the name from a temporary standard string, capturing the location of the caller. <a href="#a2be70223f532513d9f1ce311b436b72f">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a030144fd43957ba5e2c9a660d2dd33be">located_name</a> (std::string_view name, const reflection::source_location &amp;location=reflection::source_location::current())</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructs the name from a string view, capturing the location of the caller. <a href="#a030144fd43957ba5e2c9a660d2dd33be">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Member Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ade35aacdde746abad6be66a9fcab251b">location</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Gets the location where the name was given. <a href="#ade35aacdde746abad6be66a9fcab251b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const char *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aa2ec3a20974c59b2f5a64a50b41db444">name</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Gets the name. <a href="#aa2ec3a20974c59b2f5a64a50b41db444">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Private Member Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a199094a3c03b40d8621279a30a152784">location_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The location where the name was given. <a href="#a199094a3c03b40d8621279a30a152784">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">std::string</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a73d82df6b0bafcf4dfef0f15433185ca">name_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The copy of the name. <a href="#a73d82df6b0bafcf4dfef0f15433185ca">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>A name of a suite or of a test case, with the location where it was given.</p>


<p>The name parameter of <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a0cfa76ba0ba0c308d246b2b5d506ab19">suite::test()</a></span>, <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a9b497f0911a0abe12a341a560ba79e1d">test_case::test()</a></span>, <span class="doxyComputerOutput">test_each()</span>, <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#abdb31c03509a40a041b8f0ea8e12ebd1">runner::add_suite()</a></span>, <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a9ec7d561fe8eab9df03da792f62518ae">runner::add_top_suite()</a></span>, and the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite">static_suite</a></span> constructors. The constructors are not explicit, so a string literal, a <span class="doxyComputerOutput">const char*</span>, a <span class="doxyComputerOutput">std::string</span>, or a <span class="doxyComputerOutput">std::string_view</span> passed as the name converts implicitly; the default argument of the constructors is evaluated at the place of the conversion, which is the call in the user code, so the location is captured without an additional argument (which could not follow the variadic arguments of these functions).</p>


<p>The name is copied, so the argument need not outlive the call, and a <span class="doxyComputerOutput">std::string_view</span> need not be null-terminated; a temporary <span class="doxyComputerOutput">std::string</span> is moved. The copy of a test case name lives until the end of the call to <span class="doxyComputerOutput">test()</span>, within which the test case runs, so the memory used does not grow with the number of test cases; the suites, which run later, keep their name, moved, until they are destroyed.</p>


<p>The location of a test case is used to report a failure that is not associated with a check, such as an exception escaping the test case body; the suites keep their location, but do not report it.</p>


<p>Since a conversion sequence may include only one user-defined conversion, an argument that converts to <span class="doxyComputerOutput">const char*</span>, to <span class="doxyComputerOutput">std::string</span>, or to <span class="doxyComputerOutput">std::string_view</span> via a user-defined conversion operator must be converted explicitly.</p>


<p>A helper function that adds test cases on behalf of its caller can take a <span class="doxyComputerOutput">const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name">located_name</a>&amp;</span> parameter and pass it to <span class="doxyComputerOutput">test()</span>, so that the reported location is that of the call to the helper, not that of the call to <span class="doxyComputerOutput">test()</span> inside the helper.</p>


<dl class="doxySectionUser">
<dt>Example</dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight">mt = micro_os_plus::micro_test_plus;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">check_answer (mt::suite&amp; ts, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> mt::located_name&amp; <a href="#aa2ec3a20974c59b2f5a64a50b41db444">name</a>, </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  ts.test (<a href="#aa2ec3a20974c59b2f5a64a50b41db444">name</a>, [v] (</span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; t) { t.expect (mt::eq (v, 42)); });</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">}</span></span></div>

</div>


<dl class="doxySectionUser">
<dt>Since</dt>
<dd><p>6.0.0</p></dd>
</dl>


<p>Definition at line 176 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<div class="doxySectionDef">

## Public Constructors

### located\_name() {#a6559d4b0648a5552702a2f5d40ba4db4}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;std::size_t N&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::located_name::located_name (const char(&amp;) name=[N], const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> &amp; location=<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a>())</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Constructs the name from an array of characters, capturing the location of the caller.</p>


<p>Selected for the arrays, including the string literals. The name ends at the first null character or at the end of the array, whichever comes first, so that an array that is full, without a terminator, such as a fixed-size name field, is not read beyond its end.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">N</td>
<td class="doxyParamItemDescription"><p>The number of elements of the array.</p></td>
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
<td class="doxyParamItemDescription"><p>The name or description, used in reports; copied.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">location</td>
<td class="doxyParamItemDescription"><p>The location of the conversion, defaulting to the call in the user code.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Copies the characters up to the first null character, or all the elements of the array if there is none, and stores the location; when called implicitly, the location is the place of the conversion, in the user code.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00219">219</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00116">116</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a6559d4b0648a5552702a2f5d40ba4db4">116</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ab66a15ccc3f4b66fb2f8f897b2cb91ec">located_name::located_name</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> (&amp;<a href="#aa2ec3a20974c59b2f5a64a50b41db444">name</a>)[N],</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">117</span><span class="doxyLineContent"><span class="doxyHighlight">                              </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; <a href="#ade35aacdde746abad6be66a9fcab251b">location</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">118</span><span class="doxyLineContent"><span class="doxyHighlight">      : <a href="#a73d82df6b0bafcf4dfef0f15433185ca">name_</a>{ std::string_view{ <a href="#aa2ec3a20974c59b2f5a64a50b41db444">name</a>, N }.substr (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">119</span><span class="doxyLineContent"><span class="doxyHighlight">            0, std::string_view{ <a href="#aa2ec3a20974c59b2f5a64a50b41db444">name</a>, N }.find (</span><span class="doxyHighlightStringLiteral">'\0'</span><span class="doxyHighlight">)) },</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">120</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a199094a3c03b40d8621279a30a152784">location_</a>{ <a href="#ade35aacdde746abad6be66a9fcab251b">location</a> }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">121</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">122</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#afe0adb93e576b2c11ba933ec65245d91">detail::escape_control_characters</a> (<a href="#a73d82df6b0bafcf4dfef0f15433185ca">name_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">123</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#afe0adb93e576b2c11ba933ec65245d91">micro_os_plus::micro_test_plus::detail::escape_control_characters</a>, <a href="#ade35aacdde746abad6be66a9fcab251b">location</a>, <a href="#a199094a3c03b40d8621279a30a152784">location_</a>, <a href="#aa2ec3a20974c59b2f5a64a50b41db444">name</a> and <a href="#a73d82df6b0bafcf4dfef0f15433185ca">name_</a>.</p>

</div>
</div>

### located\_name() {#a49ca2791ea42fc17bd4f9de133c8adbb}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::located_name::located_name (const std::string &amp; name, const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> &amp; location=<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a>())</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Constructs the name from a standard string, capturing the location of the caller.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">name</td>
<td class="doxyParamItemDescription"><p>The name or description, used in reports; copied.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">location</td>
<td class="doxyParamItemDescription"><p>The location of the conversion, defaulting to the call in the user code.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Copies the content of the string, and stores the location; when called implicitly, the location is the place of the conversion, in the user code.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00231">231</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00131">131</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a49ca2791ea42fc17bd4f9de133c8adbb">131</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">inline</span><span class="doxyHighlight"> <a href="#ab66a15ccc3f4b66fb2f8f897b2cb91ec">located_name::located_name</a> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">132</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string&amp; <a href="#aa2ec3a20974c59b2f5a64a50b41db444">name</a>, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; <a href="#ade35aacdde746abad6be66a9fcab251b">location</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">133</span><span class="doxyLineContent"><span class="doxyHighlight">      : <a href="#a73d82df6b0bafcf4dfef0f15433185ca">name_</a>{ <a href="#aa2ec3a20974c59b2f5a64a50b41db444">name</a> }, <a href="#a199094a3c03b40d8621279a30a152784">location_</a>{ <a href="#ade35aacdde746abad6be66a9fcab251b">location</a> }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">134</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">135</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#afe0adb93e576b2c11ba933ec65245d91">detail::escape_control_characters</a> (<a href="#a73d82df6b0bafcf4dfef0f15433185ca">name_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">136</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#afe0adb93e576b2c11ba933ec65245d91">micro_os_plus::micro_test_plus::detail::escape_control_characters</a>, <a href="#ade35aacdde746abad6be66a9fcab251b">location</a>, <a href="#a199094a3c03b40d8621279a30a152784">location_</a>, <a href="#aa2ec3a20974c59b2f5a64a50b41db444">name</a> and <a href="#a73d82df6b0bafcf4dfef0f15433185ca">name_</a>.</p>

</div>
</div>

### located\_name() {#ab66a15ccc3f4b66fb2f8f897b2cb91ec}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;typename Pointer_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::located_name::located_name (Pointer_T name, const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> &amp; location=<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a>())</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Constructs the name from a C string, capturing the location of the caller.</p>


<p>Selected for the <span class="doxyComputerOutput">char</span> pointers; the text must be null-terminated. The arrays, including the string literals, are taken by the constructor for arrays, which does not read beyond the array.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Pointer_T</td>
<td class="doxyParamItemDescription"><p>The pointer type: a pointer to <span class="doxyComputerOutput">char</span>, possibly <span class="doxyComputerOutput">const</span>, or <span class="doxyComputerOutput">std::nullptr_t</span>.</p></td>
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
<td class="doxyParamItemDescription"><p>The name or description, used in reports; copied. A null pointer is an empty name.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">location</td>
<td class="doxyParamItemDescription"><p>The location of the conversion, defaulting to the call in the user code.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Copies the name, or stores an empty name if the pointer is null, and the location; the control characters of the name are escaped. When called implicitly, the location is the place of the conversion, in the user code.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00199">199</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00101">101</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ab66a15ccc3f4b66fb2f8f897b2cb91ec">101</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ab66a15ccc3f4b66fb2f8f897b2cb91ec">located_name::located_name</a> (Pointer_T <a href="#aa2ec3a20974c59b2f5a64a50b41db444">name</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">102</span><span class="doxyLineContent"><span class="doxyHighlight">                              </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; <a href="#ade35aacdde746abad6be66a9fcab251b">location</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">103</span><span class="doxyLineContent"><span class="doxyHighlight">      : <a href="#a73d82df6b0bafcf4dfef0f15433185ca">name_</a>{ <a href="#aa2ec3a20974c59b2f5a64a50b41db444">name</a> != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight"> ? <a href="#aa2ec3a20974c59b2f5a64a50b41db444">name</a> : </span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"> }, location_{ location }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">104</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">105</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#afe0adb93e576b2c11ba933ec65245d91">detail::escape_control_characters</a> (name_);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">106</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#ab66a15ccc3f4b66fb2f8f897b2cb91ec">located_name</a>, <a href="#ade35aacdde746abad6be66a9fcab251b">location</a>, <a href="#aa2ec3a20974c59b2f5a64a50b41db444">name</a> and <a href="#a73d82df6b0bafcf4dfef0f15433185ca">name_</a>.</p>


<p>Referenced by <a href="#ab66a15ccc3f4b66fb2f8f897b2cb91ec">located_name</a>.</p>

</div>
</div>

### located\_name() {#a2be70223f532513d9f1ce311b436b72f}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::located_name::located_name (std::string &amp;&amp; name, const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> &amp; location=<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a>())</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Constructs the name from a temporary standard string, capturing the location of the caller.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">name</td>
<td class="doxyParamItemDescription"><p>The name or description, used in reports; moved.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">location</td>
<td class="doxyParamItemDescription"><p>The location of the conversion, defaulting to the call in the user code.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Takes over the content of the string, without copying it, and stores the location; when called implicitly, the location is the place of the conversion, in the user code.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00243">243</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00144">144</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a2be70223f532513d9f1ce311b436b72f">144</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">inline</span><span class="doxyHighlight"> <a href="#ab66a15ccc3f4b66fb2f8f897b2cb91ec">located_name::located_name</a> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">145</span><span class="doxyLineContent"><span class="doxyHighlight">      std::string&amp;&amp; <a href="#aa2ec3a20974c59b2f5a64a50b41db444">name</a>, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; <a href="#ade35aacdde746abad6be66a9fcab251b">location</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">146</span><span class="doxyLineContent"><span class="doxyHighlight">      : <a href="#a73d82df6b0bafcf4dfef0f15433185ca">name_</a>{ std::move (<a href="#aa2ec3a20974c59b2f5a64a50b41db444">name</a>) }, <a href="#a199094a3c03b40d8621279a30a152784">location_</a>{ <a href="#ade35aacdde746abad6be66a9fcab251b">location</a> }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">147</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">148</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#afe0adb93e576b2c11ba933ec65245d91">detail::escape_control_characters</a> (<a href="#a73d82df6b0bafcf4dfef0f15433185ca">name_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">149</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#afe0adb93e576b2c11ba933ec65245d91">micro_os_plus::micro_test_plus::detail::escape_control_characters</a>, <a href="#ade35aacdde746abad6be66a9fcab251b">location</a>, <a href="#a199094a3c03b40d8621279a30a152784">location_</a>, <a href="#aa2ec3a20974c59b2f5a64a50b41db444">name</a> and <a href="#a73d82df6b0bafcf4dfef0f15433185ca">name_</a>.</p>

</div>
</div>

### located\_name() {#a030144fd43957ba5e2c9a660d2dd33be}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::located_name::located_name (std::string_view name, const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> &amp; location=<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a>())</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Constructs the name from a string view, capturing the location of the caller.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">name</td>
<td class="doxyParamItemDescription"><p>The name or description, used in reports; copied, so the view need not be null-terminated.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">location</td>
<td class="doxyParamItemDescription"><p>The location of the conversion, defaulting to the call in the user code.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Copies the characters of the view, which need not be null-terminated, and stores the location; when called implicitly, the location is the place of the conversion, in the user code.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00256">256</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00157">157</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a030144fd43957ba5e2c9a660d2dd33be">157</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">inline</span><span class="doxyHighlight"> <a href="#ab66a15ccc3f4b66fb2f8f897b2cb91ec">located_name::located_name</a> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">158</span><span class="doxyLineContent"><span class="doxyHighlight">      std::string_view <a href="#aa2ec3a20974c59b2f5a64a50b41db444">name</a>, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; <a href="#ade35aacdde746abad6be66a9fcab251b">location</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">159</span><span class="doxyLineContent"><span class="doxyHighlight">      : <a href="#a73d82df6b0bafcf4dfef0f15433185ca">name_</a>{ <a href="#aa2ec3a20974c59b2f5a64a50b41db444">name</a> }, <a href="#a199094a3c03b40d8621279a30a152784">location_</a>{ <a href="#ade35aacdde746abad6be66a9fcab251b">location</a> }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">160</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">161</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#afe0adb93e576b2c11ba933ec65245d91">detail::escape_control_characters</a> (<a href="#a73d82df6b0bafcf4dfef0f15433185ca">name_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">162</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#afe0adb93e576b2c11ba933ec65245d91">micro_os_plus::micro_test_plus::detail::escape_control_characters</a>, <a href="#ade35aacdde746abad6be66a9fcab251b">location</a>, <a href="#a199094a3c03b40d8621279a30a152784">location_</a>, <a href="#aa2ec3a20974c59b2f5a64a50b41db444">name</a> and <a href="#a73d82df6b0bafcf4dfef0f15433185ca">name_</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Member Functions

### location() {#ade35aacdde746abad6be66a9fcab251b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const reflection::source_location &amp; micro_os_plus::micro_test_plus::located_name::location (void)</td>
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

<p>Gets the location where the name was given.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A reference to the stored source location.</p></dd>
</dl>


<p>Returns a reference to the location stored in <span class="doxyComputerOutput"><a href="#a199094a3c03b40d8621279a30a152784">location_</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00279">279</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00179">179</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ade35aacdde746abad6be66a9fcab251b">179</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ade35aacdde746abad6be66a9fcab251b">located_name::location</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">180</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">181</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a199094a3c03b40d8621279a30a152784">location_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">182</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a199094a3c03b40d8621279a30a152784">location_</a>.</p>


<p>Referenced by <a href="#a6559d4b0648a5552702a2f5d40ba4db4">located_name</a>, <a href="#a49ca2791ea42fc17bd4f9de133c8adbb">located_name</a>, <a href="#ab66a15ccc3f4b66fb2f8f897b2cb91ec">located_name</a>, <a href="#a2be70223f532513d9f1ce311b436b72f">located_name</a>, <a href="#a030144fd43957ba5e2c9a660d2dd33be">located_name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a5e5df8d6e176fd4aa0ba8ed2d5104780">micro_os_plus::micro_test_plus::detail::runnable_base::accepts_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a7170624ca4a3a92b17ced71472726529">micro_os_plus::micro_test_plus::runner::add_top_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a1980019eed5ac5b1eef65302eb9cc9cd">micro_os_plus::micro_test_plus::test_case::fail_unexpected_exception</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a6a5ba9415486617bc64b8d764fef6ba6">micro_os_plus::micro_test_plus::runner::reject_call</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#ac40bf24e28cce401256d3e90f0c9e8cd">micro_os_plus::micro_test_plus::test_case::report_misdirected_test</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3178150c77ae33d100e18e157436b04b">micro_os_plus::micro_test_plus::detail::test_each_value</a>.</p>

</div>
</div>

### name() {#aa2ec3a20974c59b2f5a64a50b41db444}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const char * micro_os_plus::micro_test_plus::located_name::name (void)</td>
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

<p>Gets the name.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A pointer to the null-terminated name, valid while this object exists and is not modified.</p></dd>
</dl>


<p>Returns <span class="doxyComputerOutput">name_.c_str()</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00269">269</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00169">169</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aa2ec3a20974c59b2f5a64a50b41db444">169</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#aa2ec3a20974c59b2f5a64a50b41db444">located_name::name</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">170</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">171</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a73d82df6b0bafcf4dfef0f15433185ca">name_</a>.c_str ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">172</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a73d82df6b0bafcf4dfef0f15433185ca">name_</a>.</p>


<p>Referenced by <a href="#a6559d4b0648a5552702a2f5d40ba4db4">located_name</a>, <a href="#a49ca2791ea42fc17bd4f9de133c8adbb">located_name</a>, <a href="#ab66a15ccc3f4b66fb2f8f897b2cb91ec">located_name</a>, <a href="#a2be70223f532513d9f1ce311b436b72f">located_name</a>, <a href="#a030144fd43957ba5e2c9a660d2dd33be">located_name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#ad7c1d86bb59a42c67848ec6d9482c42b">micro_os_plus::micro_test_plus::suite::suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a5e5df8d6e176fd4aa0ba8ed2d5104780">micro_os_plus::micro_test_plus::detail::runnable_base::accepts_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#abdb31c03509a40a041b8f0ea8e12ebd1">micro_os_plus::micro_test_plus::runner::add_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a7170624ca4a3a92b17ced71472726529">micro_os_plus::micro_test_plus::runner::add_top_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#ac40bf24e28cce401256d3e90f0c9e8cd">micro_os_plus::micro_test_plus::test_case::report_misdirected_test</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a0cfa76ba0ba0c308d246b2b5d506ab19">micro_os_plus::micro_test_plus::suite::test</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a9b497f0911a0abe12a341a560ba79e1d">micro_os_plus::micro_test_plus::test_case::test</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3178150c77ae33d100e18e157436b04b">micro_os_plus::micro_test_plus::detail::test_each_value</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Private Member Attributes

### location\_ {#a199094a3c03b40d8621279a30a152784}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">reflection::source_location micro_os_plus::micro_test_plus::located_name::location_</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The location where the name was given.</p>


<p>Captured by the default argument of the constructor, at the place of the conversion to <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name">located_name</a></span>.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00298">298</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a199094a3c03b40d8621279a30a152784">298</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> <a href="#a199094a3c03b40d8621279a30a152784">location_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#a6559d4b0648a5552702a2f5d40ba4db4">located_name</a>, <a href="#a49ca2791ea42fc17bd4f9de133c8adbb">located_name</a>, <a href="#a2be70223f532513d9f1ce311b436b72f">located_name</a>, <a href="#a030144fd43957ba5e2c9a660d2dd33be">located_name</a> and <a href="#ade35aacdde746abad6be66a9fcab251b">location</a>.</p>

</div>
</div>

### name\_ {#a73d82df6b0bafcf4dfef0f15433185ca}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::string micro_os_plus::micro_test_plus::located_name::name_</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The copy of the name.</p>


<p>Owned, so that the name does not depend on the lifetime of the argument; the name of the node points into it.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00289">289</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a73d82df6b0bafcf4dfef0f15433185ca">289</a></span><span class="doxyLineContent"><span class="doxyHighlight">    std::string <a href="#a73d82df6b0bafcf4dfef0f15433185ca">name_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#a6559d4b0648a5552702a2f5d40ba4db4">located_name</a>, <a href="#a49ca2791ea42fc17bd4f9de133c8adbb">located_name</a>, <a href="#ab66a15ccc3f4b66fb2f8f897b2cb91ec">located_name</a>, <a href="#a2be70223f532513d9f1ce311b436b72f">located_name</a>, <a href="#a030144fd43957ba5e2c9a660d2dd33be">located_name</a> and <a href="#aa2ec3a20974c59b2f5a64a50b41db444">name</a>.</p>

</div>
</div>

</div>

<hr/>

The documentation for this class was generated from the following files:

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.7 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
