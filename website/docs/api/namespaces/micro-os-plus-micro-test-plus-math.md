---

# DO NOT EDIT!
# Automatically generated via docusaurus-plugin-doxygen by Doxygen.

slug: /api/namespaces/micro-os-plus/micro-test-plus/math
custom_edit_url: null
keywords:
  - doxygen
  - reference
  - namespace

---

<div class="doxyPage">

# The `math` Namespace Reference

<p>Mathematical utilities for the µTest++ testing framework. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
namespace micro_os_plus::micro_test_plus::math { ... }
</div>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr T</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a1dd33529640b959c531ca18c2e494c80">abs</a> (const T t)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Computes the absolute value of a given comparable value. <a href="#a1dd33529640b959c531ca18c2e494c80">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T, char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr T</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a1006429dba18038662409138f5754952">den</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Computes the decimal part of a number represented as an array of characters. <a href="#a1006429dba18038662409138f5754952">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T, class Value_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr T</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a3e243d7f77b8435e1433ccad9c603f98">den_size</a> (Value_T value)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Computes the number of decimal places of a value, up to 7 digits. <a href="#a3e243d7f77b8435e1433ccad9c603f98">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T, char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr T</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a74757af775d3afa203b808e3f6642467">den_size</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Computes the number of decimal places in a number represented as an array of characters. <a href="#a74757af775d3afa203b808e3f6642467">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr const T &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ae53dd62f6d82b8ccaa048d90a7002826">min_value</a> (const T &amp;lhs, const T &amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Computes the minimum of two comparable values. <a href="#ae53dd62f6d82b8ccaa048d90a7002826">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T, char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr T</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a98cbcae8bfc4a2d2f27487d1b2e641b7">num</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Computes the integral value of a number represented as an array of characters. <a href="#a98cbcae8bfc4a2d2f27487d1b2e641b7">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T, class Exp_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr T</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a5c22d85f0df63cc0504cbf4988173cd7">pow</a> (const T base, const Exp_T exp)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Generic exponentiation function to compute the power of a base raised to an exponent. <a href="#a5c22d85f0df63cc0504cbf4988173cd7">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Mathematical utilities for the µTest++ testing framework.</p>


<p>The <span class="doxyComputerOutput">math</span> namespace offers a suite of constexpr mathematical function templates and utilities for use within the µTest++ framework.</p>

<p>These functions include generic implementations for absolute value, minimum value, exponentiation, and compile-time parsing of numeric values from character arrays. The utilities are designed to be lightweight and suitable for embedded environments, where standard library alternatives may be unavailable, less efficient, or not constexpr.</p>

<p>All definitions within this namespace are intended to facilitate mathematical operations in a type-safe and efficient manner, and are implemented in the <span class="doxyComputerOutput">include/micro-os-plus</span> folder to maintain a structured and modular codebase.</p>

<div class="doxySectionDef">

## Functions

### abs() {#a1dd33529640b959c531ca18c2e494c80}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">T micro_os_plus::micro_test_plus::math::abs (const T t)</td>
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
<p>Computes the absolute value of a given comparable value.</p>


<p>This function template provides a generic, constexpr implementation for obtaining the absolute value of any type that supports comparison and unary negation.</p>

<p>The function returns the non-negative value of the input. If the input is less than the default-constructed value of its type (typically zero), the negated value is returned; otherwise, the original value is returned.</p>

<p>This utility is designed to be lightweight and suitable for embedded environments, where standard library alternatives may be unavailable, less efficient, or not constexpr.</p>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The type of the input value. Must support comparison and unary negation.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">t</td>
<td class="doxyParamItemDescription"><p>The value for which the absolute value is to be computed.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>The absolute value of the input.</p>
</dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h/#l00096">96</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h">math-inlines.h</a>.</p>
</div>
</div>

### den() {#a1006429dba18038662409138f5754952}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T, char... Cs&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">T micro_os_plus::micro_test_plus::math::den (void)</td>
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
<p>Computes the decimal part of a number represented as an array of characters.</p>


<p>This function template performs compile-time extraction of the decimal (fractional) part from a sequence of characters, typically provided as a template parameter pack.</p>

<p>The function expects the character sequence to represent a numeric value, where all characters are either digits, a dot (<span class="doxyComputerOutput">.</span>), or an apostrophe (‘``). Parsing begins after the first dot, accumulating the decimal digits as an integer value, each weighted by its decimal position.</p>

<p>This utility is particularly useful for user-defined literals and other compile-time constant expressions, enabling efficient and type-safe conversion from character sequences to the decimal part of numeric values.</p>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The target integral type for the result.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Cs</td>
<td class="doxyParamItemDescription"><p>The character pack representing the numeric value.</p></td>
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
<p>The parsed decimal part as an integral value of type <span class="doxyComputerOutput">T</span>.</p>
</dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h/#l00200">200</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h">math-inlines.h</a>.</p>
</div>
</div>

### den_size() {#a3e243d7f77b8435e1433ccad9c603f98}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T, class Value_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">T micro_os_plus::micro_test_plus::math::den_size (Value_T value)</td>
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
<p>Computes the number of decimal places of a value, up to 7 digits.</p>


<p>This function template determines, at compile time, the number of decimal (fractional) digits present in a floating-point value, up to a maximum of seven digits of precision.</p>

<p>The function repeatedly multiplies the input value by ten, incrementing a counter until the fractional part is less than a defined precision threshold (1e-7). This approach provides a robust means of estimating decimal precision for values where exact representation is not possible due to floating-point limitations.</p>

<p>This utility is particularly useful for user-defined literals and compile-time constant expressions, enabling efficient and type-safe determination of decimal precision from floating-point values.</p>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The integral type for the result.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Value_T</td>
<td class="doxyParamItemDescription"><p>The type of the input value, typically a floating-point type.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">value</td>
<td class="doxyParamItemDescription"><p>The value whose decimal precision is to be determined.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>The number of decimal places, as a value of type <span class="doxyComputerOutput">T</span>, up to a maximum of seven.</p>
</dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h/#l00269">269</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h">math-inlines.h</a>.</p>
</div>
</div>

### den_size() {#a74757af775d3afa203b808e3f6642467}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T, char... Cs&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">T micro_os_plus::micro_test_plus::math::den_size (void)</td>
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
<p>Computes the number of decimal places in a number represented as an array of characters.</p>


<p>This function template determines, at compile time, the number of decimal (fractional) digits present in a numeric value represented by a character sequence, typically provided as a template parameter pack.</p>

<p>The function expects the character sequence to represent a numeric value, where all characters are either digits, a dot (<span class="doxyComputerOutput">.</span>), or an apostrophe (‘``). It locates the first dot and counts the number of digits that follow, returning the count as the number of decimal places.</p>

<p>This utility is particularly useful for user-defined literals and other compile-time constant expressions, enabling efficient and type-safe determination of decimal precision from character sequences.</p>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The integral type for the result.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Cs</td>
<td class="doxyParamItemDescription"><p>The character pack representing the numeric value.</p></td>
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
<p>The number of decimal places as a value of type <span class="doxyComputerOutput">T</span>.</p>
</dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h/#l00233">233</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h">math-inlines.h</a>.</p>
</div>
</div>

### min_value() {#ae53dd62f6d82b8ccaa048d90a7002826}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const T &amp; micro_os_plus::micro_test_plus::math::min_value (const T &amp; lhs, const T &amp; rhs)</td>
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
<p>Computes the minimum of two comparable values.</p>


<p>This function template provides a generic, constexpr implementation for determining the minimum of two values of any type that supports comparison.</p>

<p>The function returns a reference to the lesser of the two input values, as determined by the <span class="doxyComputerOutput">&lt;</span> operator. If the second argument is less than the first, it is returned; otherwise, the first argument is returned.</p>

<p>This utility is designed to be lightweight and suitable for embedded environments, where standard library alternatives may be unavailable, less efficient, or not constexpr.</p>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The type of the input values. Must support comparison via the <span class="doxyComputerOutput">&lt;</span> operator.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">lhs</td>
<td class="doxyParamItemDescription"><p>The first value to compare.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">rhs</td>
<td class="doxyParamItemDescription"><p>The second value to compare.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>A reference to the minimum of the two input values.</p>
</dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h/#l00117">117</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h">math-inlines.h</a>.</p>
</div>
</div>

### num() {#a98cbcae8bfc4a2d2f27487d1b2e641b7}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T, char... Cs&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">T micro_os_plus::micro_test_plus::math::num (void)</td>
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
<p>Computes the integral value of a number represented as an array of characters.</p>


<p>This function template performs compile-time parsing of a numeric value from a sequence of characters, typically provided as a template parameter pack.</p>

<p>The function assumes that all characters are either digits, a dot (<span class="doxyComputerOutput">.</span>), or an apostrophe (‘``). Parsing stops at the first dot, allowing the function to extract only the integral part of the number.</p>

<p>This utility is particularly useful for user-defined literals and other compile-time constant expressions, enabling efficient and type-safe conversion from character sequences to integral values.</p>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The target integral type for the result.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Cs</td>
<td class="doxyParamItemDescription"><p>The character pack representing the numeric value.</p></td>
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
<p>The parsed integral value of type <span class="doxyComputerOutput">T</span>.</p>
</dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h/#l00160">160</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h">math-inlines.h</a>.</p>
</div>
</div>

### pow() {#a5c22d85f0df63cc0504cbf4988173cd7}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T, class Exp_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">T micro_os_plus::micro_test_plus::math::pow (const T base, const Exp_T exp)</td>
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
<p>Generic exponentiation function to compute the power of a base raised to an exponent.</p>


<p>This function template provides a constexpr implementation for raising a base value to a given exponent, supporting any types that allow multiplication and subtraction.</p>

<p>The function recursively multiplies the base by itself exponent times. If the exponent is zero, the function returns one (the multiplicative identity for the type).</p>

<p>This utility is designed to be lightweight and suitable for embedded environments, where standard library alternatives may be unavailable, less efficient, or not constexpr.</p>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The type of the base value. Must support multiplication and construction from an integer.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Exp_T</td>
<td class="doxyParamItemDescription"><p>The type of the exponent. Must support subtraction and comparison to zero.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">base</td>
<td class="doxyParamItemDescription"><p>The base value to be raised to the power of <span class="doxyComputerOutput">exp</span>.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">exp</td>
<td class="doxyParamItemDescription"><p>The exponent value.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>The result of raising <span class="doxyComputerOutput">base</span> to the power of <span class="doxyComputerOutput">exp</span>.</p>
</dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h/#l00138">138</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h">math-inlines.h</a>.</p>
</div>
</div>

</div>

<hr/>

<p>The documentation for this namespace was generated from the following file:</p>

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h">math-inlines.h</a></li>
</ul>

<p class="doxyGeneratedBy">Generated via <a href="https://github.com/xpack/docusaurus-plugin-doxygen">docusaurus-plugin-doxygen</a> by <a href="https://www.doxygen.nl">Doxygen</a> 1.14.0.</p>

</div>
