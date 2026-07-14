---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/structs/micro-os-plus/micro-test-plus/-t
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - struct

---

<div class="doxyPage">

# `_t` Struct Template

<p>Deprecated generic strongly-typed wrapper for explicit type conversion. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
template &lt;class T&gt;<br/>
struct micro_os_plus::micro_test_plus::_t&lt;T&gt; { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include &lt;<a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>&gt;
</div>

## Base struct

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">struct</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-f7399366cd6336ecbea702c3289d9432">value&lt;T&gt;</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Struct template representing a floating point value with precision control. <a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-f7399366cd6336ecbea702c3289d9432/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Member Typedefs Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-base-/#a4a819c9151d37da6e8a76f4629c7cc4d">value_type</a> = T</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The type of the stored value. <a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-base-/#a4a819c9151d37da6e8a76f4629c7cc4d">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Constructors Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">constexpr</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack-webpreview/docs/api/groups/micro-test-plus-literals/#ga6195961d9ece2c2c91e8946d47d84a79">_t</a> (const T &amp;t)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructor for the deprecated strongly-typed wrapper. <a href="/micro-test-plus-xpack-webpreview/docs/api/groups/micro-test-plus-literals/#ga6195961d9ece2c2c91e8946d47d84a79">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Operators Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-base-/#ab7f7f241b55abd7ac9e25234bbe64406">operator T</a> () const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Explicit conversion operator to the underlying value type. <a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-base-/#ab7f7f241b55abd7ac9e25234bbe64406">More...</a></p>
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
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr T</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-base-/#aedc41334c71b7711435aee0cb8f44fb3">get</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Getter for the stored value. <a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-base-/#aedc41334c71b7711435aee0cb8f44fb3">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Member Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">T</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-f7399366cd6336ecbea702c3289d9432/#a434b222ff19bdb4970ad56fce11d5176">epsilon</a> = T{}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The epsilon value used for floating-point comparisons. <a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-f7399366cd6336ecbea702c3289d9432/#a434b222ff19bdb4970ad56fce11d5176">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">T</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-base-/#a8f1747b0fb288001d51754dfb8c53b0e">value_</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The stored value. <a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-base-/#a8f1747b0fb288001d51754dfb8c53b0e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Deprecated generic strongly-typed wrapper for explicit type conversion.</p>


<p>The <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/-t">_t</a></span> template provides a public, strongly-typed wrapper for any type <span class="doxyComputerOutput">T</span>, enabling explicit conversion of dynamic values and expressions to a type recognised by the µTest++ comparators and reporting mechanisms.</p>


<p>This wrapper inherits from <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value</a>&lt;T&gt;</span>, ensuring that the encapsulated value is treated as the specified type within the framework.</p>


<div class="doxyXrefSect">
<dl class="doxyXrefSectList">
<dt class="doxyXrefSectTitle"><a href=/micro-test-plus-xpack-webpreview/docs/api/pages/deprecated/#_deprecated000024>Deprecated</a></dt>
<dd class="doxyXrefSectDescription">
<p>Use <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/to-t">to_t</a></span> (since 3.2.0).</p>
</dd>
</dl>
</div>

<p>Definition at line 641 of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/literals-h">literals.h</a>.</p>


<div class="doxySectionDef">

## Public Member Typedefs

### value\_type {#a4a819c9151d37da6e8a76f4629c7cc4d}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">using micro_os_plus::micro_test_plus::type_traits::value_base_&lt; T &gt;::value_type = T</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The type of the stored value.</p>

<p>Definition at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/type-traits-h/#l00514">514</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/type-traits-h">type-traits.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-base-/#a4a819c9151d37da6e8a76f4629c7cc4d">514</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-base-/#a4a819c9151d37da6e8a76f4629c7cc4d">value_type</a> = T;</span></span></div>

</div>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Operators

### operator T() {#ab7f7f241b55abd7ac9e25234bbe64406}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::type_traits::value_base_&lt; T &gt;::operator T ()</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel explicit">explicit</span>
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel constexpr">constexpr</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Explicit conversion operator to the underlying value type.</p>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The stored value as type <span class="doxyComputerOutput">T</span>.</p></dd>
</dl>


<p>Allows explicit conversion to the encapsulated value.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/type-traits-h/#l00529">529</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/type-traits-h">type-traits.h</a>, definition at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/type-traits-inlines-h/#l00083">83</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/type-traits-inlines-h">type-traits-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">83</span><span class="doxyLineContent"><span class="doxyHighlight">    operator T () const noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">84</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">85</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-base-/#a8f1747b0fb288001d51754dfb8c53b0e">value_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">86</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-base-/#ab9b0e45988e4291e63d6b016c55231f7">micro_os_plus::micro_test_plus::type_traits::value_base_&lt; T &gt;::value_base_</a> and <a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-base-/#a8f1747b0fb288001d51754dfb8c53b0e">micro_os_plus::micro_test_plus::type_traits::value_base_&lt; T &gt;::value_</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Member Functions

### get() {#aedc41334c71b7711435aee0cb8f44fb3}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">T micro_os_plus::micro_test_plus::type_traits::value_base_&lt; T &gt;::get (void)</td>
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

<p>Getter for the stored value.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The stored value.</p></dd>
</dl>


<p>Returns the stored value by value.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/type-traits-h/#l00539">539</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/type-traits-h">type-traits.h</a>, definition at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/type-traits-inlines-h/#l00094">94</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/type-traits-inlines-h">type-traits-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-base-/#aedc41334c71b7711435aee0cb8f44fb3">94</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-base-/#aedc41334c71b7711435aee0cb8f44fb3">value_base_&lt;T&gt;::get</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">95</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">96</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-base-/#a8f1747b0fb288001d51754dfb8c53b0e">value_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">97</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-base-/#a8f1747b0fb288001d51754dfb8c53b0e">micro_os_plus::micro_test_plus::type_traits::value_base_&lt; T &gt;::value_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a35c3c186dea0017fd5afe8a2adac98a3">micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt;</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Member Attributes

### epsilon {#a434b222ff19bdb4970ad56fce11d5176}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">T micro_os_plus::micro_test_plus::type_traits::value&lt; T &gt;::epsilon = T{}</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The epsilon value used for floating-point comparisons.</p>


<p>This instance member defines the precision for comparisons. It is set via the constructor, either explicitly or computed as a default based on the number of decimal digits in the value. Each instance carries its own epsilon, so two <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">value</a>&lt;T&gt;</span> objects with different precisions do not interfere with each other.</p>


<p>Definition at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/type-traits-h/#l00756">756</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/type-traits-h">type-traits.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-f7399366cd6336ecbea702c3289d9432/#a434b222ff19bdb4970ad56fce11d5176">756</a></span><span class="doxyLineContent"><span class="doxyHighlight">      T <a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-f7399366cd6336ecbea702c3289d9432/#a434b222ff19bdb4970ad56fce11d5176">epsilon</a> = T{};</span></span></div>

</div>

</div>
</div>

### value\_ {#a8f1747b0fb288001d51754dfb8c53b0e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">T micro_os_plus::micro_test_plus::type_traits::value_base_&lt; T &gt;::value_ {}</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The stored value.</p>

<p>Definition at line <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/type-traits-h/#l00544">544</a> of file <a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/type-traits-h">type-traits.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-base-/#a8f1747b0fb288001d51754dfb8c53b0e">544</a></span><span class="doxyLineContent"><span class="doxyHighlight">      T <a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-base-/#a8f1747b0fb288001d51754dfb8c53b0e">value_</a>{};</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-base-/#ab9b0e45988e4291e63d6b016c55231f7">micro_os_plus::micro_test_plus::type_traits::value_base_&lt; T &gt;::value_base_</a>, <a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-base-/#aedc41334c71b7711435aee0cb8f44fb3">micro_os_plus::micro_test_plus::type_traits::value_base_&lt; T &gt;::get</a> and <a href="/micro-test-plus-xpack-webpreview/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-base-/#ab7f7f241b55abd7ac9e25234bbe64406">micro_os_plus::micro_test_plus::type_traits::value_base_&lt; T &gt;::operator T</a>.</p>

</div>
</div>

</div>

<hr/>

The documentation for this struct was generated from the following files:

<ul>
<li><a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/type-traits-inlines-h">type-traits-inlines.h</a></li>
<li><a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/type-traits-h">type-traits.h</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.1 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
