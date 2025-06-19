---

# DO NOT EDIT!
# Automatically generated via docusaurus-plugin-doxygen by Doxygen.

slug: /api/groups/micro-test-plus-utility-functions
custom_edit_url: null
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# The Utility Functions Reference

<p>Utility functions for advanced string handling in tests. <a href="#details">More...</a></p>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#gaa2f0f4cff320a783ad2347c9ff3fc731">is_match</a> (std::string_view input, std::string_view pattern)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Check if a string matches a pattern. <a href="#gaa2f0f4cff320a783ad2347c9ff3fc731">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr T &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ga00ea8f3dfb7cb0ef39919065321cf62f">mut</a> (const T &amp;t) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Generic mutator to remove const qualification from any type. <a href="#ga00ea8f3dfb7cb0ef39919065321cf62f">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T, class Delim_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">auto </td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ga1b860aa64be17658d1664de447e6e125">split</a> (T input, Delim_T delim) -&gt; std::vector&lt; T &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Split a string into a vector of sub-strings. <a href="#ga1b860aa64be17658d1664de447e6e125">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Utility functions for advanced string handling in tests.</p>


<p>The µTest++ framework includes a collection of utility functions designed to simplify advanced string operations commonly required during test development. These functions support tasks such as partial string matching, splitting long strings for improved readability, and other manipulations that enhance the clarity and effectiveness of test code.</p>

<div class="doxySectionDef">

## Functions

### is_match() {#gaa2f0f4cff320a783ad2347c9ff3fc731}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::utility::is_match (std::string_view input, std::string_view pattern)</td>
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
<p>Check if a string matches a pattern.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] input</td>
<td class="doxyParamItemDescription"><p>The string view to be checked.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] pattern</td>
<td class="doxyParamItemDescription"><p>The string view containing the pattern to match.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p><span class="doxyComputerOutput">true</span> if the input string matches the pattern; otherwise, <span class="doxyComputerOutput">false</span>.</p>
</dd>
</dl>


<p>This function enables pattern-based string comparison for tests, supporting both exact matches and wildcard patterns. The pattern may include <span class="doxyComputerOutput">*</span> to match any sequence of characters and <span class="doxyComputerOutput">?</span> to match any single character. This allows for flexible validation of string content in test assertions, accommodating variable or partially known values.</p>

<dl class="doxySectionUser">
<dt><b>Examples</b></dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight">mt = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">mt::expect (mt::utility::is_match (</span><span class="doxyHighlightStringLiteral">"abc"</span><span class="doxyHighlight">, </span><span class="doxyHighlightStringLiteral">"a?c"</span><span class="doxyHighlight">)) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"abc matches a?c"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">mt::expect (mt::utility::is_match (</span><span class="doxyHighlightStringLiteral">"abc"</span><span class="doxyHighlight">, </span><span class="doxyHighlightStringLiteral">"a*c"</span><span class="doxyHighlight">)) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"abc matches a*c"</span><span class="doxyHighlight">;</span></span></div>

</div>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/micro-test-plus-cpp/#l00171">171</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/micro-test-plus-cpp">micro-test-plus.cpp</a>.</p>
</div>
</div>

### mut() {#ga00ea8f3dfb7cb0ef39919065321cf62f}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">T &amp; micro_os_plus::micro_test_plus::mut (const T &amp; t)</td>
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
<p>Generic mutator to remove const qualification from any type.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The type of the input object.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] t</td>
<td class="doxyParamItemDescription"><p>The object from which to remove const qualification.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>A non-const reference to the input object.</p>
</dd>
</dl>


<p>The <span class="doxyComputerOutput">mut</span> function template provides a safe and generic mechanism to remove the <span class="doxyComputerOutput">const</span> qualifier from any type. It returns a non-const reference to the input object, enabling modification of objects that were originally declared as <span class="doxyComputerOutput">const</span>. This utility is particularly useful in testing scenarios where controlled mutation of test data is required.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/function-comparators-inlines-h/#l00321">321</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/function-comparators-inlines-h">function-comparators-inlines.h</a>.</p>
</div>
</div>

### split() {#ga1b860aa64be17658d1664de447e6e125}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T, class Delim_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::vector&lt; T &gt; micro_os_plus::micro_test_plus::utility::split (T input, Delim_T delim)</td>
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
<p>Split a string into a vector of sub-strings.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>Type of the input string.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Delim_T</td>
<td class="doxyParamItemDescription"><p>Type of the delimiter.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] input</td>
<td class="doxyParamItemDescription"><p>Input string to split.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] delim</td>
<td class="doxyParamItemDescription"><p>Delimiter string.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>A vector containing the resulting sub-strings.</p>
</dd>
</dl>


<p>This function template facilitates string handling in tests by splitting a string into a vector of substrings, using the specified delimiter.</p>

<p>The function iterates through the input string, identifying delimiter positions and extracting substrings between them. Each resulting substring is added to the output vector. This approach supports flexible parsing of delimited data, which is particularly useful for validating string processing logic in test cases.</p>

<dl class="doxySectionUser">
<dt><b>Example</b></dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight">mt = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">mt::expect (std::vector&lt;std::string_view&gt;{ </span><span class="doxyHighlightStringLiteral">"a"</span><span class="doxyHighlight">, </span><span class="doxyHighlightStringLiteral">"b"</span><span class="doxyHighlight"> }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">            == mt::utility::split&lt;std::string_view&gt; (</span><span class="doxyHighlightStringLiteral">"a.b"</span><span class="doxyHighlight">, </span><span class="doxyHighlightStringLiteral">"."</span><span class="doxyHighlight">))</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">        &lt;&lt; </span><span class="doxyHighlightStringLiteral">"a.b splits into [a,b]"</span><span class="doxyHighlight">;</span></span></div>

</div>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/micro-test-plus-inlines-h/#l00275">275</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/micro-test-plus-inlines-h">micro-test-plus-inlines.h</a>.</p>
</div>
</div>

</div>

<p class="doxyGeneratedBy">Generated via <a href="https://github.com/xpack/docusaurus-plugin-doxygen">docusaurus-plugin-doxygen</a> by <a href="https://www.doxygen.nl">Doxygen</a> 1.14.0.</p>

</div>
