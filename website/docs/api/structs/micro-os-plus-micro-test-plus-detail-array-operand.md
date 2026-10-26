---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/structs/micro-os-plus/micro-test-plus/detail/array-operand
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - struct

---

<div class="doxyPage">

# `array_operand` Struct Template

<p>An array operand of a comparator, other than a <span class="doxyComputerOutput">char</span> array. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
template &lt;class T&gt;<br/>
struct micro_os_plus::micro_test_plus::detail::array_operand&lt;T&gt; { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>"
</div>

## Public Constructors Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a9c2ee9c42136a485b41aebd85c3597c1">array_operand</a> (const T *first, std::size_t count) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructs the operand from the first element and the size of an array. <a href="#a9c2ee9c42136a485b41aebd85c3597c1">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Member Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr const T *</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a8f44a4be9bb4c412b551818b378395c4">begin</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns an iterator to the first element. <a href="#a8f44a4be9bb4c412b551818b378395c4">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr const T *</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#afe9138ceb8877c6f13281c240008a762">end</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns an iterator past the last element. <a href="#afe9138ceb8877c6f13281c240008a762">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Private Member Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">std::size_t</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a07aad5c8d860e3c487df8a0f6948d0a2">count_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The number of elements. <a href="#a07aad5c8d860e3c487df8a0f6948d0a2">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">const T *</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a81af19b59f044e9adfee2dc5edabbc6f">first_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The first element. <a href="#a81af19b59f044e9adfee2dc5edabbc6f">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>An array operand of a comparator, other than a <span class="doxyComputerOutput">char</span> array.</p>


<p>The comparators convert the arrays of any element type except <span class="doxyComputerOutput">char</span> (the byte buffers, the arrays of numbers, and the arrays of the wide character types) to this type (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a51e86043001b197561806d5c6297041b">as_operand()</a></span>), so that they are compared element by element, and written as ranges, instead of being compared and written as the addresses they decay to. Two arrays of different sizes are never equal.</p>


<p>The elements are not copied; the operand must outlive the comparison, which is always the case within a check.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The element type, possibly <span class="doxyComputerOutput">const</span>.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Definition at line 1505 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>.</p>


<div class="doxySectionDef">

## Public Constructors

### array\_operand() {#a9c2ee9c42136a485b41aebd85c3597c1}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::array_operand&lt; T &gt;::array_operand (const T * first, std::size_t count)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel constexpr">constexpr</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Constructs the operand from the first element and the size of an array.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">first</td>
<td class="doxyParamItemDescription"><p>The first element of the array.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">count</td>
<td class="doxyParamItemDescription"><p>The number of elements of the array.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Stores the pointer and the count; nothing is copied.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l01514">1514</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h/#l00982">982</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h">detail-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a9c2ee9c42136a485b41aebd85c3597c1">982</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> <a href="#a9c2ee9c42136a485b41aebd85c3597c1">array_operand&lt;T&gt;::array_operand</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T* first,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">983</span><span class="doxyLineContent"><span class="doxyHighlight">                                               std::size_t count) noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">984</span><span class="doxyLineContent"><span class="doxyHighlight">        : <a href="#a81af19b59f044e9adfee2dc5edabbc6f">first_</a>{ first }, count_{ count }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">985</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">986</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="#a81af19b59f044e9adfee2dc5edabbc6f">micro_os_plus::micro_test_plus::detail::array_operand&lt; T &gt;::first_</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Member Functions

### begin() {#a8f44a4be9bb4c412b551818b378395c4}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const T * micro_os_plus::micro_test_plus::detail::array_operand&lt; T &gt;::begin (void)</td>
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

<p>Returns an iterator to the first element.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A pointer to the first element.</p></dd>
</dl>


<p>Returns the stored pointer.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l01524">1524</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h/#l00994">994</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h">detail-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a8f44a4be9bb4c412b551818b378395c4">994</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a8f44a4be9bb4c412b551818b378395c4">array_operand&lt;T&gt;::begin</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">995</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">996</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a81af19b59f044e9adfee2dc5edabbc6f">first_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">997</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="#a81af19b59f044e9adfee2dc5edabbc6f">micro_os_plus::micro_test_plus::detail::array_operand&lt; T &gt;::first_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ade4fe4b187a8ded1bb42910536d86235">micro_os_plus::micro_test_plus::detail::operator&lt;=&gt;</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ad7b514fb92021548630dbeb2cd8189bc">micro_os_plus::micro_test_plus::detail::operator==</a>.</p>

</div>
</div>

### end() {#afe9138ceb8877c6f13281c240008a762}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const T * micro_os_plus::micro_test_plus::detail::array_operand&lt; T &gt;::end (void)</td>
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

<p>Returns an iterator past the last element.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A pointer past the last element.</p></dd>
</dl>


<p>Returns the pointer past the last element.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l01534">1534</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h/#l01013">1013</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h">detail-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#afe9138ceb8877c6f13281c240008a762">1013</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#afe9138ceb8877c6f13281c240008a762">array_operand&lt;T&gt;::end</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1014</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1015</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a81af19b59f044e9adfee2dc5edabbc6f">first_</a> + <a href="#a07aad5c8d860e3c487df8a0f6948d0a2">count_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1016</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="#a07aad5c8d860e3c487df8a0f6948d0a2">micro_os_plus::micro_test_plus::detail::array_operand&lt; T &gt;::count_</a> and <a href="#a81af19b59f044e9adfee2dc5edabbc6f">micro_os_plus::micro_test_plus::detail::array_operand&lt; T &gt;::first_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ade4fe4b187a8ded1bb42910536d86235">micro_os_plus::micro_test_plus::detail::operator&lt;=&gt;</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ad7b514fb92021548630dbeb2cd8189bc">micro_os_plus::micro_test_plus::detail::operator==</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Private Member Attributes

### count\_ {#a07aad5c8d860e3c487df8a0f6948d0a2}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::size_t micro_os_plus::micro_test_plus::detail::array_operand&lt; T &gt;::count_</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The number of elements.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l01548">1548</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a07aad5c8d860e3c487df8a0f6948d0a2">1548</a></span><span class="doxyLineContent"><span class="doxyHighlight">      std::size_t <a href="#a07aad5c8d860e3c487df8a0f6948d0a2">count_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#afe9138ceb8877c6f13281c240008a762">micro_os_plus::micro_test_plus::detail::array_operand&lt; T &gt;::end</a>.</p>

</div>
</div>

### first\_ {#a81af19b59f044e9adfee2dc5edabbc6f}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const T* micro_os_plus::micro_test_plus::detail::array_operand&lt; T &gt;::first_</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The first element.</p>


<p>Not owned; points into the array passed to the comparator.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l01543">1543</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a81af19b59f044e9adfee2dc5edabbc6f">1543</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T* <a href="#a81af19b59f044e9adfee2dc5edabbc6f">first_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#a9c2ee9c42136a485b41aebd85c3597c1">micro_os_plus::micro_test_plus::detail::array_operand&lt; T &gt;::array_operand</a>, <a href="#a8f44a4be9bb4c412b551818b378395c4">micro_os_plus::micro_test_plus::detail::array_operand&lt; T &gt;::begin</a> and <a href="#afe9138ceb8877c6f13281c240008a762">micro_os_plus::micro_test_plus::detail::array_operand&lt; T &gt;::end</a>.</p>

</div>
</div>

</div>

<hr/>

The documentation for this struct was generated from the following files:

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h">detail-inlines.h</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
