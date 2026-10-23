---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-os-plus-micro-test-plus-config
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# Configuration

<p>Configuration macros. <a href="#details">More...</a></p>

## Macro Definitions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">#define</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ga3dd1e70998580fe7d7f410e5cd83879b">MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Enables the µTest++ Testing Framework. <a href="#ga3dd1e70998580fe7d7f410e5cd83879b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">#define</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ga27bb1b9066b162d868e0b1c557b91e0d">MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Enables the trace messages of the µTest++ constructors and destructors. <a href="#ga27bb1b9066b162d868e0b1c557b91e0d">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">#define</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ga039219e6edfdcaa8a5e07badd7f4830d">MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Enables the trace messages of the µTest++ member functions. <a href="#ga039219e6edfdcaa8a5e07badd7f4830d">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Configuration macros.</p>


<p>The µTest++ Testing Framework library uses several preprocessor macros to enable it and to configure various options.</p>


<p>These macros must be defined by the application; neither the library nor its CMake, meson, and xPack build files define them (the <span class="doxyComputerOutput">defaultDefine</span> entries in <span class="doxyComputerOutput">xcdl-package.jsonc</span> are informative only).</p>


<p>The preferred place is <span class="doxyComputerOutput">micro-os-plus/micro-test-plus-defines.h</span>, or <span class="doxyComputerOutput">micro-os-plus/project-config.h</span>, which each µTest++ header includes, if present, before its own definitions, so that the application and the library sources are compiled with the same configuration. The macros have no value, only their definition matters; guard them, so that they can also be defined on the compiler command line:</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if !defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#define MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// !defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)</span></span></div>

</div>


<p>A macro defined only on the compiler command line (for example <span class="doxyComputerOutput">‑DMICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED</span>) must be defined for the entire build (both the application and the library sources).</p>


<div class="doxySectionDef">

## Macro Definitions

### MICRO\_OS\_PLUS\_MICRO\_TEST\_PLUS\_ENABLED {#ga3dd1e70998580fe7d7f410e5cd83879b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">#define MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Enables the µTest++ Testing Framework.</p>


<p>This is the main configuration option of this library; it has no value, only its definition matters.</p>


<p>Without it, <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a></span> declares nothing and the library sources compile to nothing. If it is defined on the compiler command line for the application, but not for the library sources, the link fails with undefined references.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h/#l00076">76</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-test-plus.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga3dd1e70998580fe7d7f410e5cd83879b">76</a></span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#define MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED</span></span></div>

</div>

</div>
</div>

### MICRO\_OS\_PLUS\_MICRO\_TEST\_PLUS\_TRACE\_CONSTRUCTORS\_ENABLED {#ga27bb1b9066b162d868e0b1c557b91e0d}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">#define MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Enables the trace messages of the µTest++ constructors and destructors.</p>


<p>Displays trace messages in the constructors and destructors of the µTest++ Testing Framework, through <span class="doxyComputerOutput">trace::printf()</span>, which writes them only when <span class="doxyComputerOutput">MICRO_OS_PLUS_DIAG_TRACE_ENABLED</span> is also defined.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h/#l00078">78</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-test-plus.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga27bb1b9066b162d868e0b1c557b91e0d">78</a></span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#define MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED</span></span></div>

</div>

</div>
</div>

### MICRO\_OS\_PLUS\_MICRO\_TEST\_PLUS\_TRACE\_ENABLED {#ga039219e6edfdcaa8a5e07badd7f4830d}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">#define MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Enables the trace messages of the µTest++ member functions.</p>


<p>Displays trace messages in the member functions of the µTest++ Testing Framework, through <span class="doxyComputerOutput">trace::printf()</span>, which writes them only when <span class="doxyComputerOutput">MICRO_OS_PLUS_DIAG_TRACE_ENABLED</span> is also defined.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h/#l00077">77</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-test-plus.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga039219e6edfdcaa8a5e07badd7f4830d">77</a></span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#define MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>

</div>

</div>
</div>

</div>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
