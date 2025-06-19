---

# DO NOT EDIT!
# Automatically generated via docusaurus-plugin-doxygen by Doxygen.

slug: /api/namespaces/micro-os-plus/micro-test-plus/reflection
custom_edit_url: null
keywords:
  - doxygen
  - reference
  - namespace

---

<div class="doxyPage">

# The `reflection` Namespace Reference

<p>Reflection utilities for the µTest++ testing framework. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
namespace micro_os_plus::micro_test_plus::reflection { ... }
</div>

## Classes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">source_location</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Local implementation of source location information for diagnostics. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">const char *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ab4fa1159ebe60ce5fe073eefbe9a2446">short_name</a> (const char *name)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Extract a short type or function name from a fully qualified name. <a href="#ab4fa1159ebe60ce5fe073eefbe9a2446">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr std::string_view</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a6580ad54ad22a1d3ab43a1d9d49d1f26">type_name</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Extract the type name from the <span class="doxyComputerOutput">__PRETTY_FUNCTION__</span> macro. <a href="#a6580ad54ad22a1d3ab43a1d9d49d1f26">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Reflection utilities for the µTest++ testing framework.</p>


<p>The <span class="doxyComputerOutput">reflection</span> namespace provides facilities for obtaining source location information and type names at compile time, thereby supporting advanced reporting and diagnostics within the µTest++ framework.</p>

<p>It includes a local implementation of <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">source_location</a></span> for environments lacking C++20 standard support, as well as utilities for extracting concise type names from compiler-specific macros such as <span class="doxyComputerOutput">__PRETTY_FUNCTION__</span>.</p>

<p>All definitions within this namespace are intended to facilitate advanced reflection and reporting capabilities.</p>

<div class="doxySectionDef">

## Functions

### short_name() {#ab4fa1159ebe60ce5fe073eefbe9a2446}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const char * micro_os_plus::micro_test_plus::reflection::short_name (const char * name)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Extract a short type or function name from a fully qualified name.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">name</td>
<td class="doxyParamItemDescription"><p>The fully qualified name as a C-string.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>A pointer to the short name within the input string.</p>
</dd>
</dl>


<p>This function extracts the short name from a given file path by locating the final folder separator ('/'). If a separator is found, it returns a pointer to the character immediately following it, effectively providing the file or folder name. If no separator is present, the original input string is returned. This utility is useful for reporting concise file or folder names in test output.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/micro-test-plus-cpp/#l00128">128</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/micro-test-plus-cpp">micro-test-plus.cpp</a>.</p>
</div>
</div>

### type_name() {#a6580ad54ad22a1d3ab43a1d9d49d1f26}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::string_view micro_os_plus::micro_test_plus::reflection::type_name (void)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel constexpr">constexpr</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Extract the type name from the <span class="doxyComputerOutput">__PRETTY_FUNCTION__</span> macro.</p>


<p>This function template parses the compiler-specific <span class="doxyComputerOutput">__PRETTY_FUNCTION__</span> macro to extract a concise type name for the template parameter <span class="doxyComputerOutput">T</span>.</p>

<p>The implementation is compiler-dependent and may require adjustment for different toolchains. It is primarily intended for internal use within the µTest++ framework to support improved diagnostics and reporting.</p>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The type whose name is to be extracted.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Parameters</b></dt>
<dd>
<p>None.</p>
</dd>
</dl>


<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>A <span class="doxyComputerOutput">std::string_view</span> containing the extracted type name.</p>
</dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reflection-inlines-h/#l00133">133</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reflection-inlines-h">reflection-inlines.h</a>.</p>
</div>
</div>

</div>

<hr/>

<p>The documentation for this namespace was generated from the following files:</p>

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reflection-inlines-h">reflection-inlines.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/src/micro-test-plus-cpp">micro-test-plus.cpp</a></li>
</ul>

<p class="doxyGeneratedBy">Generated via <a href="https://github.com/xpack/docusaurus-plugin-doxygen">docusaurus-plugin-doxygen</a> by <a href="https://www.doxygen.nl">Doxygen</a> 1.14.0.</p>

</div>
