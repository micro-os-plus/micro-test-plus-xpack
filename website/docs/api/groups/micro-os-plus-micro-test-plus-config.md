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

<p>The macros that enable and configure the framework. <a href="#details">More...</a></p>

## Macro Definitions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">#define</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ga67c701de5426ac340584ed038494a873">MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Enables the deprecated definitions of the µTest++ Testing Framework. <a href="#ga67c701de5426ac340584ed038494a873">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

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

<p>The macros that enable and configure the framework.</p>


<p>The framework is configured with preprocessor macros. They have no value; only their definition matters:</p>


<ul class="doxyList ">
<li><span class="doxyComputerOutput"><a href="#ga3dd1e70998580fe7d7f410e5cd83879b">MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED</a></span> is required; without it, the headers declare nothing and the library sources compile to nothing;</li>
<li><span class="doxyComputerOutput"><a href="#ga67c701de5426ac340584ed038494a873">MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED</a></span> makes the deprecated definitions available;</li>
<li><span class="doxyComputerOutput"><a href="#ga039219e6edfdcaa8a5e07badd7f4830d">MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</a></span> and <span class="doxyComputerOutput"><a href="#ga27bb1b9066b162d868e0b1c557b91e0d">MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED</a></span> enable the trace messages.</li>
</ul>

<dl class="doxySectionUser">
<dt>Where to define them</dt>
<dd><p>The application defines the macros; neither the library nor its CMake, meson, and xPack build files define them (the <span class="doxyComputerOutput">defaultDefine</span> entries in <span class="doxyComputerOutput">xcdl-package.jsonc</span> are informative only).</p></dd>
</dl>


<p>The application and the library sources must be compiled with the same <span class="doxyComputerOutput"><a href="#ga3dd1e70998580fe7d7f410e5cd83879b">MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED</a></span> macro, otherwise the link fails; the same holds for <span class="doxyComputerOutput"><a href="#ga67c701de5426ac340584ed038494a873">MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED</a></span>, for the applications that use the non-inline deprecated members (see the pages of the macros below). The trace macros only add trace calls to the function bodies, and need the <span class="doxyComputerOutput">micro-os-plus/diag/trace.h</span> header (see the pages of the macros). The simplest way is a header named <span class="doxyComputerOutput">micro-os-plus/micro-test-plus-defines.h</span> (or <span class="doxyComputerOutput">micro-os-plus/project-config.h</span>) in the include path of the build: every µTest++ header includes it, if present, before its own definitions.</p>


<p>Guard each definition, so that the macro can also be given on the compiler command line:</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if !defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#define MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// !defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)</span></span></div>

</div>


<p>A macro given only on the compiler command line (for example <span class="doxyComputerOutput">-DMICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED</span>) must be given for the whole build, for both the application and the library sources.</p>


<p>The definitions shown on the pages of the macros, with a line number in <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-test-plus.h</a></span>, exist only for this documentation; the header does not define these macros, and neither does the library.</p>


<div class="doxySectionDef">

## Macro Definitions

### MICRO\_OS\_PLUS\_MICRO\_TEST\_PLUS\_DEPRECATED\_ENABLED {#ga67c701de5426ac340584ed038494a873}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">#define MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Enables the deprecated definitions of the µTest++ Testing Framework.</p>


<p>This option has no value, only its definition matters.</p>


<p>Without it, the deprecated definitions (the old names of the functions, the classes, and the members, the overloaded operators, the user-defined literals, the value wrappers, and the deprecated overloads and constructors) are neither declared nor defined, so the applications that still use them fail to compile.</p>


<p>With it, they are available, but marked <span class="doxyComputerOutput">[[deprecated]]</span>, so the compiler reports their use; the applications that build with <span class="doxyComputerOutput">-Werror</span> fail until the deprecated definitions are replaced.</p>


<p>The macro must be defined for the library sources too, otherwise the link of an application that uses the non-inline deprecated members fails with undefined references.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h/#l00075">75</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-test-plus.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga67c701de5426ac340584ed038494a873">75</a></span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#define MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED</span></span></div>

</div>

</div>
</div>

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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h/#l00072">72</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-test-plus.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga3dd1e70998580fe7d7f410e5cd83879b">72</a></span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#define MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED</span></span></div>

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


<p>The code compiled with this macro includes <span class="doxyComputerOutput">micro-os-plus/diag/trace.h</span>, of the µOS++ <span class="doxyComputerOutput">diag-trace</span> package, which must be in the include path of the build; without it, the compilation fails.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h/#l00074">74</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-test-plus.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga27bb1b9066b162d868e0b1c557b91e0d">74</a></span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#define MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED</span></span></div>

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


<p>The code compiled with this macro includes <span class="doxyComputerOutput">micro-os-plus/diag/trace.h</span>, of the µOS++ <span class="doxyComputerOutput">diag-trace</span> package, which must be in the include path of the build; without it, the compilation fails.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h/#l00073">73</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-test-plus.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga039219e6edfdcaa8a5e07badd7f4830d">73</a></span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#define MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED</span></span></div>

</div>

</div>
</div>

</div>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.8 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
