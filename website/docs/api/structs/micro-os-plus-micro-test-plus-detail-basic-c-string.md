---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/structs/micro-os-plus/micro-test-plus/detail/basic-c-string
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - struct

---

<div class="doxyPage">

# `basic_c_string` Struct Template

<p>A C string operand of a comparator. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
template &lt;character Char_T&gt;<br/>
struct micro_os_plus::micro_test_plus::detail::basic_c_string&lt;Char_T&gt; { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>"
</div>

## Public Constructors Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;character Char_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a6ab5a592f0a20330b2a68480d719bd6a">basic_c_string</a> (const Char_T *str) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructs the operand from a pointer to a null-terminated string. <a href="#a6ab5a592f0a20330b2a68480d719bd6a">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;character Char_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#acdfd43d6d3d328ef3c40ea9a11340625">basic_c_string</a> (const Char_T *str, std::size_t capacity) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructs the operand from an array of characters. <a href="#acdfd43d6d3d328ef3c40ea9a11340625">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Member Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;character Char_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr bool</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a02a4a3d852b5606cbac121e9bab8d69d">is_null</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns whether the operand is a null pointer. <a href="#a02a4a3d852b5606cbac121e9bab8d69d">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;character Char_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto </td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a0851477f1a58ad82284847d1ebaf5201">view</a> (void) const noexcept -&gt; std::basic_string_view&lt; Char_T &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns the characters, as a string view. <a href="#a0851477f1a58ad82284847d1ebaf5201">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Private Member Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;character Char_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">std::size_t</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#af727574c085a72e7309c4e65f9fde693">size_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The number of characters, without the terminator. <a href="#af727574c085a72e7309c4e65f9fde693">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;character Char_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">const Char_T *</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#aaaeff461f662bc9fb7e54c666e4ee101">str_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The first character, or <span class="doxyComputerOutput">nullptr</span>. <a href="#aaaeff461f662bc9fb7e54c666e4ee101">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>A C string operand of a comparator.</p>


<p>The comparators convert the arrays (including the string literals) and the pointers of the character types to this type (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a51e86043001b197561806d5c6297041b">as_operand()</a></span>), so that they are compared by content, as a reader of a test expects, and not by address. A null pointer is equal only to another null pointer (not to an empty string), and is less than any string.</p>


<p>The characters are not copied; the operand must outlive the comparison, which is always the case within a check.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Char_T</td>
<td class="doxyParamItemDescription"><p>The character type; it satisfies <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/character">character</a></span>.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Definition at line 1673 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>.</p>


<div class="doxySectionDef">

## Public Constructors

### basic\_c\_string() {#a6ab5a592f0a20330b2a68480d719bd6a}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;character Char_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::basic_c_string&lt; Char_T &gt;::basic_c_string (const Char_T * str)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel explicit">explicit</span>
<span class="doxyMemberLabel constexpr">constexpr</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Constructs the operand from a pointer to a null-terminated string.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">str</td>
<td class="doxyParamItemDescription"><p>The string, or <span class="doxyComputerOutput">nullptr</span>.</p></td>
</tr>
</table>
</dd>
</dl>

<p>The length is computed with <span class="doxyComputerOutput">std::char_traits&lt;Char_T&gt;::length()</span>, which, unlike <span class="doxyComputerOutput">strlen()</span>, can be evaluated at compile time.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l01681">1681</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h/#l01498">1498</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h">detail-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a6ab5a592f0a20330b2a68480d719bd6a">1498</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">acter Char_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1499</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> <a href="#a6ab5a592f0a20330b2a68480d719bd6a">basic_c_string&lt;Char_T&gt;::basic_c_string</a> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1500</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Char_T* str) noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1501</span><span class="doxyLineContent"><span class="doxyHighlight">        : <a href="#aaaeff461f662bc9fb7e54c666e4ee101">str_</a>{ str },</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1502</span><span class="doxyLineContent"><span class="doxyHighlight">          size_{ str == </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight"> ? 0 : std::char_traits&lt;Char_T&gt;::length (str) }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1503</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>

</div>


<p>Reference <a href="#aaaeff461f662bc9fb7e54c666e4ee101">micro_os_plus::micro_test_plus::detail::basic_c_string&lt; Char_T &gt;::str_</a>.</p>

</div>
</div>

### basic\_c\_string() {#acdfd43d6d3d328ef3c40ea9a11340625}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;character Char_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::basic_c_string&lt; Char_T &gt;::basic_c_string (const Char_T * str, std::size_t capacity)</td>
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

<p>Constructs the operand from an array of characters.</p>


<p>The string ends at the first null character, or at the end of the array, so that an array without a terminator is not read beyond its end.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">str</td>
<td class="doxyParamItemDescription"><p>The first character of the array.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">capacity</td>
<td class="doxyParamItemDescription"><p>The number of elements of the array.</p></td>
</tr>
</table>
</dd>
</dl>

<p>The characters are counted up to the first null character, or up to <span class="doxyComputerOutput">capacity</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l01694">1694</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h/#l01511">1511</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h">detail-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#acdfd43d6d3d328ef3c40ea9a11340625">1511</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">acter Char_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1512</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> <a href="#a6ab5a592f0a20330b2a68480d719bd6a">basic_c_string&lt;Char_T&gt;::basic_c_string</a> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1513</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Char_T* str, std::size_t capacity) noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1514</span><span class="doxyLineContent"><span class="doxyHighlight">        : <a href="#aaaeff461f662bc9fb7e54c666e4ee101">str_</a>{ str }, size_{ capacity }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1515</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1516</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// Search within the array only; the view avoids indexing the raw</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1517</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// pointer.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1518</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::size_t terminator</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1519</span><span class="doxyLineContent"><span class="doxyHighlight">          = std::basic_string_view&lt;Char_T&gt;{ str, capacity }.find (Char_T{});</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1520</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (terminator != std::basic_string_view&lt;Char_T&gt;::npos)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1521</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1522</span><span class="doxyLineContent"><span class="doxyHighlight">          size_ = terminator;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1523</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>

</div>


<p>Reference <a href="#aaaeff461f662bc9fb7e54c666e4ee101">micro_os_plus::micro_test_plus::detail::basic_c_string&lt; Char_T &gt;::str_</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Member Functions

### is\_null() {#a02a4a3d852b5606cbac121e9bab8d69d}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;character Char_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::detail::basic_c_string&lt; Char_T &gt;::is_null (void)</td>
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

<p>Returns whether the operand is a null pointer.</p>


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
<td class="doxyParamItemDescription"><p>The operand is a null pointer.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">false</td>
<td class="doxyParamItemDescription"><p>The operand is a string, possibly empty.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Returns whether the stored pointer is null.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l01717">1717</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h/#l01543">1543</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h">detail-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a02a4a3d852b5606cbac121e9bab8d69d">1543</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1544</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a02a4a3d852b5606cbac121e9bab8d69d">basic_c_string&lt;Char_T&gt;::is_null</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1545</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1546</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#aaaeff461f662bc9fb7e54c666e4ee101">str_</a> == </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">;</span></span></div>

</div>


<p>Reference <a href="#aaaeff461f662bc9fb7e54c666e4ee101">micro_os_plus::micro_test_plus::detail::basic_c_string&lt; Char_T &gt;::str_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#adc1852317cb922b2104918b8644a6714">micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt;</a>.</p>

</div>
</div>

### view() {#a0851477f1a58ad82284847d1ebaf5201}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;character Char_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::basic_string_view&lt; Char_T &gt; micro_os_plus::micro_test_plus::detail::basic_c_string&lt; Char_T &gt;::view (void)</td>
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

<p>Returns the characters, as a string view.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The characters, without the terminator; empty for a null pointer.</p></dd>
</dl>


<p>Returns an empty view for a null pointer.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l01706">1706</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h/#l01531">1531</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h">detail-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a0851477f1a58ad82284847d1ebaf5201">1531</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> std::basic_string_view&lt;Char_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1532</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a0851477f1a58ad82284847d1ebaf5201">basic_c_string&lt;Char_T&gt;::view</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1533</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1534</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#aaaeff461f662bc9fb7e54c666e4ee101">str_</a> == </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight"> ? std::basic_string_view&lt;Char_T&gt;{}</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1535</span><span class="doxyLineContent"><span class="doxyHighlight">                             : std::basic_string_view&lt;Char_T&gt;{ <a href="#aaaeff461f662bc9fb7e54c666e4ee101">str_</a>, <a href="#af727574c085a72e7309c4e65f9fde693">size_</a> };</span></span></div>

</div>


<p>References <a href="#af727574c085a72e7309c4e65f9fde693">micro_os_plus::micro_test_plus::detail::basic_c_string&lt; Char_T &gt;::size_</a> and <a href="#aaaeff461f662bc9fb7e54c666e4ee101">micro_os_plus::micro_test_plus::detail::basic_c_string&lt; Char_T &gt;::str_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#adc1852317cb922b2104918b8644a6714">micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt;</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Private Member Attributes

### size\_ {#af727574c085a72e7309c4e65f9fde693}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;character Char_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::size_t micro_os_plus::micro_test_plus::detail::basic_c_string&lt; Char_T &gt;::size_</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The number of characters, without the terminator.</p>


<p>Computed by the constructors; zero for a null pointer.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l01734">1734</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#af727574c085a72e7309c4e65f9fde693">1734</a></span><span class="doxyLineContent"><span class="doxyHighlight">      std::size_t <a href="#af727574c085a72e7309c4e65f9fde693">size_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#a0851477f1a58ad82284847d1ebaf5201">micro_os_plus::micro_test_plus::detail::basic_c_string&lt; Char_T &gt;::view</a>.</p>

</div>
</div>

### str\_ {#aaaeff461f662bc9fb7e54c666e4ee101}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;character Char_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const Char_T* micro_os_plus::micro_test_plus::detail::basic_c_string&lt; Char_T &gt;::str_</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The first character, or <span class="doxyComputerOutput">nullptr</span>.</p>


<p>Not owned; points into the operand passed to the comparator.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l01726">1726</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aaaeff461f662bc9fb7e54c666e4ee101">1726</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Char_T* <a href="#aaaeff461f662bc9fb7e54c666e4ee101">str_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#a6ab5a592f0a20330b2a68480d719bd6a">micro_os_plus::micro_test_plus::detail::basic_c_string&lt; Char_T &gt;::basic_c_string</a>, <a href="#acdfd43d6d3d328ef3c40ea9a11340625">micro_os_plus::micro_test_plus::detail::basic_c_string&lt; Char_T &gt;::basic_c_string</a>, <a href="#a02a4a3d852b5606cbac121e9bab8d69d">micro_os_plus::micro_test_plus::detail::basic_c_string&lt; Char_T &gt;::is_null</a> and <a href="#a0851477f1a58ad82284847d1ebaf5201">micro_os_plus::micro_test_plus::detail::basic_c_string&lt; Char_T &gt;::view</a>.</p>

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

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.8 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
