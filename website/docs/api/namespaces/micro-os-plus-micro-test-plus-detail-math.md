---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/namespaces/micro-os-plus/micro-test-plus/detail/math
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - namespace

---

<div class="doxyPage">

# `math` Namespace

<p>Internal mathematical utilities for the µTest++ testing framework. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
namespace micro_os_plus::micro_test_plus::detail::math { ... }
</div>

## Classes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">struct</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/math/integer-literal">integer_literal</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The result of parsing the characters of an integer literal. <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/math/integer-literal/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr T</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a515f68bbb31d64d07810f45f3b1118f6">abs</a> (const T t) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Computes the absolute value of a given comparable value. <a href="#a515f68bbb31d64d07810f45f3b1118f6">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#accba38bf51d261f330b594ca121e6f75">count_decimals</a> (Value_T value)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Computes the number of decimal places of a value, with a precision of about seven digits. <a href="#accba38bf51d261f330b594ca121e6f75">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;bool Fraction, char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">std::size_t</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#af295fc92026927f8a453248655e7862e">count_literal_digits</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Counts the decimal digits of a floating-point literal, before or after the decimal point. <a href="#af295fc92026927f8a453248655e7862e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Value_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr Value_T</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ae474285acf7f49d66bb721b8ab5f8fa8">decimal_epsilon</a> (Value_T value)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Computes the default comparison tolerance of a floating-point value, one unit of its last decimal. <a href="#ae474285acf7f49d66bb721b8ab5f8fa8">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T, char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">T</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a154910632d01b827ab1b67f309064211">den</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Computes the decimal part of a number represented as an array of characters. <a href="#a154910632d01b827ab1b67f309064211">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T, char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">T</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a3557a9ea7ea89e94be133fb78edcd01f">den_size</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Counts the decimal places of a number represented as an array of characters. <a href="#a3557a9ea7ea89e94be133fb78edcd01f">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T, char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">unsigned long long</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a4f5af9be6a23a49f942e72de92adc91e">integer_magnitude</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Computes the value of an integer literal of type <span class="doxyComputerOutput">T</span>, before any negation. <a href="#a4f5af9be6a23a49f942e72de92adc91e">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a67e71e2dce0120ad4839635830e80de8">min_value</a> (const T &amp;lhs, const T &amp;rhs) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Computes the minimum of two comparable values. <a href="#a67e71e2dce0120ad4839635830e80de8">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T, char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">T</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a6b03b257bb18615448fe9b4fca4a8402">num</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Computes the integral part of a decimal floating-point number represented as an array of characters. <a href="#a6b03b257bb18615448fe9b4fca4a8402">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/math/integer-literal">integer_literal</a></td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a9292deab69ef8584bc2604e76316ecfd">parse_integer_literal</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Parses the characters of an integer literal. <a href="#a9292deab69ef8584bc2604e76316ecfd">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a121fbc662b8263c3b9ce605456fbc7d5">pow</a> (const T base, const Exp_T exp) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Generic exponentiation function to compute the power of a base raised to an exponent. <a href="#a121fbc662b8263c3b9ce605456fbc7d5">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Internal mathematical utilities for the µTest++ testing framework.</p>


<p>The <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/math">detail::math</a></span> namespace offers a suite of constexpr mathematical function templates and utilities, used by the literals and by the floating-point comparisons of the µTest++ framework.</p>


<p>These functions include generic implementations for absolute value, minimum value, exponentiation, and compile-time parsing of numeric values from character arrays. The utilities are designed to be lightweight and suitable for embedded environments, where standard library alternatives may be unavailable, less efficient, or not constexpr.</p>


<p>The names of these functions suggest general mathematical functions, but their scope is limited to the needs of the framework (for example, <span class="doxyComputerOutput"><a href="#a121fbc662b8263c3b9ce605456fbc7d5">pow()</a></span> accepts only integral exponents); like everything in <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail">detail</a></span>, they are not part of the public API and may be modified without prior notice.</p>


<div class="doxySectionDef">

## Functions

### abs() {#a515f68bbb31d64d07810f45f3b1118f6}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">T micro_os_plus::micro_test_plus::detail::math::abs (const T t)</td>
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

<p>Computes the absolute value of a given comparable value.</p>


<p>This function template provides a generic, constexpr implementation for obtaining the absolute value of any type that supports comparison and unary negation.</p>


<p>The function returns the non-negative value of the input. If the input is less than the default-constructed value of its type (typically zero), the negated value is returned; otherwise, the original value is returned.</p>


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
<dt>Returns</dt>
<dd><p>The absolute value of the input.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h/#l00092">92</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h">math-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a515f68bbb31d64d07810f45f3b1118f6">92</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a515f68bbb31d64d07810f45f3b1118f6">abs</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T t) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight"> -&gt; T</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">93</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">94</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> t &lt; T{} ? -t : t;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">95</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="#a515f68bbb31d64d07810f45f3b1118f6">abs</a>.</p>


<p>Referenced by <a href="#a515f68bbb31d64d07810f45f3b1118f6">abs</a>, <a href="#accba38bf51d261f330b594ca121e6f75">count_decimals</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a7ce90ae12eac430cf58becac530b92b2">micro_os_plus::micro_test_plus::detail::differ_by_less_than</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a6c5237ff6944278e8c5e3294cf99a3b9">micro_os_plus::micro_test_plus::detail::within_tolerance</a>.</p>

</div>
</div>

### count\_decimals() {#accba38bf51d261f330b594ca121e6f75}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T, class Value_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">T micro_os_plus::micro_test_plus::detail::math::count_decimals (Value_T value)</td>
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

<p>Computes the number of decimal places of a value, with a precision of about seven digits.</p>


<p>This function template determines the number of decimal (fractional) digits present in a floating-point value, with a precision of about seven digits. Being <span class="doxyComputerOutput">constexpr</span>, it can also be evaluated at compile time.</p>


<p>The function repeatedly multiplies the absolute value by ten, incrementing a counter until the distance to the nearest integer is at most a defined precision threshold (1e-7). Using the distance to the nearest integer, not the fractional part, prevents the rounding noise of a value just below an integer (e.g. 2674.9999999999995) from being taken as more decimals.</p>


<p>The nearest integer is never zero: while the scaled value is below one, its distance to one is used, so that the leading zeros of a small value are counted as decimals, as in its notation (12 for <span class="doxyComputerOutput">1e-12</span>), instead of the count stopping as soon as the scaled value is below the threshold. A zero value has no significant digit, and the result is zero.</p>


<p>The loop also stops when the value reaches the magnitude from which the type can represent only integers (2^23 for <span class="doxyComputerOutput">float</span>, 2^52 for <span class="doxyComputerOutput">double</span>), limited to 2^63 so that the conversion to <span class="doxyComputerOutput">unsigned long long</span> is always defined. This bounds the number of steps for large values, infinities, and NaNs, for which the result is one; for small values, the number of steps is bounded by the decimal exponent of the smallest value of the type.</p>


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
<td class="doxyParamItemDescription"><p>The type of the input value, a floating-point type.</p></td>
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
<td class="doxyParamItemDescription"><p>The value whose decimal precision is to be determined; it may be negative, infinite, or a NaN.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The number of decimal places, as a value of type <span class="doxyComputerOutput">T</span>, at least one, or zero for a zero value; the leading zeros of a value below one are counted; it is limited by the magnitude from which <span class="doxyComputerOutput">Value_T</span> represents only integers.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h/#l00299">299</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h">math-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#accba38bf51d261f330b594ca121e6f75">299</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#accba38bf51d261f330b594ca121e6f75">count_decimals</a> (Value_T <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">value</a>) -&gt; T</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">300</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">301</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> precision = Value_T (1e-7);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">302</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// From this magnitude upwards all values are integers.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">303</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> integral_limit</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">304</span><span class="doxyLineContent"><span class="doxyHighlight">          = <a href="#a67e71e2dce0120ad4839635830e80de8">min_value</a> (Value_T (1) / std::numeric_limits&lt;Value_T&gt;::epsilon (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">305</span><span class="doxyLineContent"><span class="doxyHighlight">                       Value_T (1ULL &lt;&lt; 63));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">306</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">307</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">value</a> = <a href="#a515f68bbb31d64d07810f45f3b1118f6">abs</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">value</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">308</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">309</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">310</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">311</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Wfloat-equal"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">312</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">313</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">value</a> == Value_T (0))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">314</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">315</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightComment">// A zero has no decimals.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">316</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> T{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">317</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">318</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">319</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">320</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">321</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">322</span><span class="doxyLineContent"><span class="doxyHighlight">      T result{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">323</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (;;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">324</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">325</span><span class="doxyLineContent"><span class="doxyHighlight">          <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">value</a> *= 10;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">326</span><span class="doxyLineContent"><span class="doxyHighlight">          ++result;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">327</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">328</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightComment">// Also true for infinities and NaNs.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">329</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (not(<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">value</a> &lt; integral_limit))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">330</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">331</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">332</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">333</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">334</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> fraction = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">value</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">335</span><span class="doxyLineContent"><span class="doxyHighlight">                                - </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">Value_T</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">336</span><span class="doxyLineContent"><span class="doxyHighlight">                                    </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">value</a>));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">337</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightComment">// Below one, the distance is to one, not to zero, so that the</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">338</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightComment">// leading zeros of a small value are counted.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">339</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> distance</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">340</span><span class="doxyLineContent"><span class="doxyHighlight">              = (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">value</a> &lt; Value_T (1))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">341</span><span class="doxyLineContent"><span class="doxyHighlight">                    ? Value_T (1) - fraction</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">342</span><span class="doxyLineContent"><span class="doxyHighlight">                    : <a href="#a67e71e2dce0120ad4839635830e80de8">min_value</a> (fraction, Value_T (1) - fraction);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">343</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (distance &lt;= precision)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">344</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">345</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">346</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">347</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">348</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">349</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> result;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">350</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="#a515f68bbb31d64d07810f45f3b1118f6">abs</a>, <a href="#accba38bf51d261f330b594ca121e6f75">count_decimals</a> and <a href="#a67e71e2dce0120ad4839635830e80de8">min_value</a>.</p>


<p>Referenced by <a href="#accba38bf51d261f330b594ca121e6f75">count_decimals</a> and <a href="#ae474285acf7f49d66bb721b8ab5f8fa8">decimal_epsilon</a>.</p>

</div>
</div>

### count\_literal\_digits() {#af295fc92026927f8a453248655e7862e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;bool Fraction, char... Cs&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::size_t micro_os_plus::micro_test_plus::detail::math::count_literal_digits (void)</td>
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

<p>Counts the decimal digits of a floating-point literal, before or after the decimal point.</p>


<p>Walks the characters once, counting the decimal digits before the first decimal point (<span class="doxyComputerOutput">Fraction</span> false) or after it (<span class="doxyComputerOutput">Fraction</span> true); the digit separators are skipped.</p>


<p>The digit separators (<span class="doxyComputerOutput">'</span>) are not counted.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Fraction</td>
<td class="doxyParamItemDescription"><p><span class="doxyComputerOutput">true</span> to count the digits after the decimal point, <span class="doxyComputerOutput">false</span> to count those before it.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Cs</td>
<td class="doxyParamItemDescription"><p>The characters of the literal.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The number of digits.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h/#l00142">142</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h">math-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#af295fc92026927f8a453248655e7862e">142</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#af295fc92026927f8a453248655e7862e">count_literal_digits</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) -&gt; std::size_t</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">143</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">144</span><span class="doxyLineContent"><span class="doxyHighlight">      std::size_t count = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">145</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> is_fraction = </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">146</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> c : { Cs... })</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">147</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">148</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (c == </span><span class="doxyHighlightCharLiteral">'.'</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">149</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">150</span><span class="doxyLineContent"><span class="doxyHighlight">              is_fraction = </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">151</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">152</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (c &gt;= </span><span class="doxyHighlightCharLiteral">'0'</span><span class="doxyHighlight"> and c &lt;= </span><span class="doxyHighlightCharLiteral">'9'</span><span class="doxyHighlight"> and is_fraction == Fraction)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">153</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">154</span><span class="doxyLineContent"><span class="doxyHighlight">              ++count;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">155</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">156</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">157</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> count;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">158</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="#af295fc92026927f8a453248655e7862e">count_literal_digits</a>.</p>


<p>Referenced by <a href="#af295fc92026927f8a453248655e7862e">count_literal_digits</a>, <a href="#a154910632d01b827ab1b67f309064211">den</a>, <a href="#a3557a9ea7ea89e94be133fb78edcd01f">den_size</a> and <a href="#a6b03b257bb18615448fe9b4fca4a8402">num</a>.</p>

</div>
</div>

### decimal\_epsilon() {#ae474285acf7f49d66bb721b8ab5f8fa8}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Value_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">Value_T micro_os_plus::micro_test_plus::detail::math::decimal_epsilon (Value_T value)</td>
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

<p>Computes the default comparison tolerance of a floating-point value, one unit of its last decimal.</p>


<p>The number of decimal places is computed by <span class="doxyComputerOutput"><a href="#accba38bf51d261f330b594ca121e6f75">count_decimals()</a></span>, and the tolerance is one divided by ten raised to that number, as for the floating-point literals, which use the decimals written.</p>


<p>A zero value has no decimals, and gets a zero tolerance, so that it is compared exactly; a tolerance of one unit of an arbitrary decimal would make the zero equal to unrelated small values. A zero tolerance is also returned when ten raised to the number of decimals would exceed the range of <span class="doxyComputerOutput">Value_T</span> (values below about <span class="doxyComputerOutput">1e-308</span> for <span class="doxyComputerOutput">double</span>), instead of computing an infinite power.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Value_T</td>
<td class="doxyParamItemDescription"><p>The type of the value, a floating-point type.</p></td>
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
<td class="doxyParamItemDescription"><p>The value whose tolerance is to be determined; it may be negative, infinite, or a NaN.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Ten raised to minus the number of decimal places returned by <span class="doxyComputerOutput"><a href="#accba38bf51d261f330b594ca121e6f75">count_decimals()</a></span> (0.01 for <span class="doxyComputerOutput">1.25</span>, 1e-12 for <span class="doxyComputerOutput">1e-12</span>), or zero, which means an exact comparison, for a zero value and for a value whose tolerance would be below the range of <span class="doxyComputerOutput">Value_T</span>.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h/#l00367">367</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h">math-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ae474285acf7f49d66bb721b8ab5f8fa8">367</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#ae474285acf7f49d66bb721b8ab5f8fa8">decimal_epsilon</a> (Value_T <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">value</a>) -&gt; Value_T</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">368</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">369</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> decimals = <a href="#accba38bf51d261f330b594ca121e6f75">count_decimals&lt;unsigned long long&gt;</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">value</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">370</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (decimals == 0</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">371</span><span class="doxyLineContent"><span class="doxyHighlight">          or decimals &gt; </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">372</span><span class="doxyLineContent"><span class="doxyHighlight">                 std::numeric_limits&lt;Value_T&gt;::max_exponent10))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">373</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">374</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> Value_T{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">375</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">376</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> Value_T (1) / <a href="#a121fbc662b8263c3b9ce605456fbc7d5">pow</a> (Value_T (10), decimals);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">377</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="#accba38bf51d261f330b594ca121e6f75">count_decimals</a>, <a href="#ae474285acf7f49d66bb721b8ab5f8fa8">decimal_epsilon</a> and <a href="#a121fbc662b8263c3b9ce605456fbc7d5">pow</a>.</p>


<p>Referenced by <a href="#ae474285acf7f49d66bb721b8ab5f8fa8">decimal_epsilon</a>.</p>

</div>
</div>

### den() {#a154910632d01b827ab1b67f309064211}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T, char... Cs&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">T micro_os_plus::micro_test_plus::detail::math::den (void)</td>
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

<p>Computes the decimal part of a number represented as an array of characters.</p>


<p>This function template performs compile-time extraction of the decimal (fractional) part from a sequence of characters, typically provided as a template parameter pack.</p>


<p>The function expects the character sequence to represent a numeric value, where all characters are either digits, a dot (<span class="doxyComputerOutput">.</span>), or an apostrophe (<span class="doxyComputerOutput">'</span>). Parsing begins after the first dot, accumulating the decimal digits as an integer value and skipping the digit separators (e.g. <span class="doxyComputerOutput">1.25</span> yields 25), so that <span class="doxyComputerOutput"><a href="#a154910632d01b827ab1b67f309064211">den()</a> / 10^den_size()</span> gives the fraction. If the result could exceed <span class="doxyComputerOutput">T</span>, the compilation fails with an explicit message.</p>


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
<td class="doxyParamItemDescription"><p>The character pack representing the numeric value; it must contain a decimal point.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The digits after the decimal point, as an integral value of type <span class="doxyComputerOutput">T</span> (e.g. 25 for <span class="doxyComputerOutput">1.25</span>), to be divided by ten raised to the power returned by <span class="doxyComputerOutput"><a href="#a3557a9ea7ea89e94be133fb78edcd01f">den_size()</a></span>.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h/#l00218">218</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h">math-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a154910632d01b827ab1b67f309064211">218</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a154910632d01b827ab1b67f309064211">den</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) -&gt; T</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">219</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">220</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">static_assert</span><span class="doxyHighlight"> ((... || (Cs == </span><span class="doxyHighlightCharLiteral">'.'</span><span class="doxyHighlight">)),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">221</span><span class="doxyLineContent"><span class="doxyHighlight">                     </span><span class="doxyHighlightStringLiteral">"den(): no decimal point in literal"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">222</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// The result has as many digits as the decimals, and it must fit in</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">223</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// `T`.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">224</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">static_assert</span><span class="doxyHighlight"> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">225</span><span class="doxyLineContent"><span class="doxyHighlight">          <a href="#af295fc92026927f8a453248655e7862e">count_literal_digits</a>&lt;</span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">, Cs...&gt; ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">226</span><span class="doxyLineContent"><span class="doxyHighlight">              &lt;= </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">std::size_t</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (std::numeric_limits&lt;T&gt;::digits10),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">227</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightStringLiteral">"µTest++: the floating-point literal has too many "</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">228</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightStringLiteral">"decimals"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">229</span><span class="doxyLineContent"><span class="doxyHighlight">      T result{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">230</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> is_fraction = </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">231</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> c : { Cs... })</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">232</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">233</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (c == </span><span class="doxyHighlightCharLiteral">'.'</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">234</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">235</span><span class="doxyLineContent"><span class="doxyHighlight">              is_fraction = </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">236</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">237</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (is_fraction and c &gt;= </span><span class="doxyHighlightCharLiteral">'0'</span><span class="doxyHighlight"> and c &lt;= </span><span class="doxyHighlightCharLiteral">'9'</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">238</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">239</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightComment">// The digit separators are skipped.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">240</span><span class="doxyLineContent"><span class="doxyHighlight">              result = </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">T</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (result * </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">T</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (10)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">241</span><span class="doxyLineContent"><span class="doxyHighlight">                                       + </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">T</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (c - </span><span class="doxyHighlightCharLiteral">'0'</span><span class="doxyHighlight">));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">242</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">243</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">244</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> result;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">245</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="#af295fc92026927f8a453248655e7862e">count_literal_digits</a> and <a href="#a154910632d01b827ab1b67f309064211">den</a>.</p>


<p>Referenced by <a href="#a154910632d01b827ab1b67f309064211">den</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-deprecated-literals/#ga9d9b0d77e96cc46e7c9fabbb6cf671da">micro_os_plus::micro_test_plus::literals::operator""_d</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-deprecated-literals/#gab9d0b5fe567e9ea4b2cf4e7edd6ec2ef">micro_os_plus::micro_test_plus::literals::operator""_f</a> and <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-deprecated-literals/#gaecd8c981d99602a0d0a44ebf6d1d4f75">micro_os_plus::micro_test_plus::literals::operator""_ld</a>.</p>

</div>
</div>

### den\_size() {#a3557a9ea7ea89e94be133fb78edcd01f}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T, char... Cs&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">T micro_os_plus::micro_test_plus::detail::math::den_size (void)</td>
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

<p>Counts the decimal places of a number represented as an array of characters.</p>


<p>This function template determines, at compile time, the number of decimal (fractional) digits present in a numeric value represented by a character sequence, typically provided as a template parameter pack.</p>


<p>The function expects the character sequence to represent a numeric value, where all characters are either digits, a dot (<span class="doxyComputerOutput">.</span>), or an apostrophe (<span class="doxyComputerOutput">'</span>). It returns the number of digits that follow the first dot (the digit separators are not counted; e.g. 2 for <span class="doxyComputerOutput">1.25</span>), which is the scale of the value returned by <span class="doxyComputerOutput"><a href="#a154910632d01b827ab1b67f309064211">den()</a></span>.</p>


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
<td class="doxyParamItemDescription"><p>The character pack representing the numeric value; it must contain a decimal point.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The number of decimal places (e.g. 2 for <span class="doxyComputerOutput">1.25</span>), as a value of type <span class="doxyComputerOutput">T</span>; it is the scale of the value returned by <span class="doxyComputerOutput"><a href="#a154910632d01b827ab1b67f309064211">den()</a></span>.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h/#l00261">261</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h">math-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a3557a9ea7ea89e94be133fb78edcd01f">261</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a3557a9ea7ea89e94be133fb78edcd01f">den_size</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) -&gt; T</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">262</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">263</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">static_assert</span><span class="doxyHighlight"> ((... || (Cs == </span><span class="doxyHighlightCharLiteral">'.'</span><span class="doxyHighlight">)),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">264</span><span class="doxyLineContent"><span class="doxyHighlight">                     </span><span class="doxyHighlightStringLiteral">"den_size(): no decimal point in literal"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">265</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">T</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (<a href="#af295fc92026927f8a453248655e7862e">count_literal_digits</a>&lt;</span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">, Cs...&gt; ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">266</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="#af295fc92026927f8a453248655e7862e">count_literal_digits</a> and <a href="#a3557a9ea7ea89e94be133fb78edcd01f">den_size</a>.</p>


<p>Referenced by <a href="#a3557a9ea7ea89e94be133fb78edcd01f">den_size</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-deprecated-literals/#ga9d9b0d77e96cc46e7c9fabbb6cf671da">micro_os_plus::micro_test_plus::literals::operator""_d</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-deprecated-literals/#gab9d0b5fe567e9ea4b2cf4e7edd6ec2ef">micro_os_plus::micro_test_plus::literals::operator""_f</a> and <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-deprecated-literals/#gaecd8c981d99602a0d0a44ebf6d1d4f75">micro_os_plus::micro_test_plus::literals::operator""_ld</a>.</p>

</div>
</div>

### integer\_magnitude() {#a4f5af9be6a23a49f942e72de92adc91e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T, char... Cs&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">unsigned long long micro_os_plus::micro_test_plus::detail::math::integer_magnitude (void)</td>
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

<p>Computes the value of an integer literal of type <span class="doxyComputerOutput">T</span>, before any negation.</p>


<p>The literal must be an integer literal, in any of the C++ forms (decimal, hexadecimal, binary, or octal, with digit separators), and its value must fit in <span class="doxyComputerOutput">T</span>; otherwise the compilation fails with an explicit message.</p>


<p>Negative values are obtained with the unary minus, so the literal itself is never negative. For the signed types, the limit is the absolute value of the minimum, <span class="doxyComputerOutput">max () + 1</span>, so that the minimum can be written (e.g. <span class="doxyComputerOutput">-128<a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-deprecated-literals/#ga265f8609ef3d6ead78c7a66825553e24">_i8</a></span>); the caller allows this magnitude only when it is negated.</p>


<p>When a check fails, zero is returned, so that the callers report no further errors.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The integral type of the literal.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Cs</td>
<td class="doxyParamItemDescription"><p>The characters of the literal, as received by a literal operator template.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The value of the literal, up to <span class="doxyComputerOutput">max ()</span> of <span class="doxyComputerOutput">T</span>, or, for the signed types, up to <span class="doxyComputerOutput">max () + 1</span>, the absolute value of the minimum.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h/#l00489">489</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h">math-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a4f5af9be6a23a49f942e72de92adc91e">489</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a4f5af9be6a23a49f942e72de92adc91e">integer_magnitude</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) -&gt; </span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">490</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">491</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/math/integer-literal">integer_literal</a> literal = <a href="#a9292deab69ef8584bc2604e76316ecfd">parse_integer_literal</a>&lt;Cs...&gt; ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">492</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> max_magnitude</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">493</span><span class="doxyLineContent"><span class="doxyHighlight">          = </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (std::numeric_limits&lt;T&gt;::max ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">494</span><span class="doxyLineContent"><span class="doxyHighlight">            + (std::numeric_limits&lt;T&gt;::is_signed ? 1u : 0u);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">495</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> fits = literal.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/math/integer-literal/#ac09f666f846defca3cb8bd6e1b33c60e">is_integer</a> &amp;&amp; !literal.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/math/integer-literal/#a94438561fe06662519cf9687cc734fdb">is_too_large</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">496</span><span class="doxyLineContent"><span class="doxyHighlight">                            &amp;&amp; literal.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/math/integer-literal/#a79fda0403a1ee1c8fafecbab9e80c815">value</a> &lt;= max_magnitude;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">497</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">498</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">static_assert</span><span class="doxyHighlight"> (literal.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/math/integer-literal/#ac09f666f846defca3cb8bd6e1b33c60e">is_integer</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">499</span><span class="doxyLineContent"><span class="doxyHighlight">                     </span><span class="doxyHighlightStringLiteral">"µTest++: an integer literal must not have a decimal "</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">500</span><span class="doxyLineContent"><span class="doxyHighlight">                     </span><span class="doxyHighlightStringLiteral">"point or an exponent"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">501</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">static_assert</span><span class="doxyHighlight"> (!literal.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/math/integer-literal/#ac09f666f846defca3cb8bd6e1b33c60e">is_integer</a> || !literal.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/math/integer-literal/#a94438561fe06662519cf9687cc734fdb">is_too_large</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">502</span><span class="doxyLineContent"><span class="doxyHighlight">                     </span><span class="doxyHighlightStringLiteral">"µTest++: the integer literal is too large"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">503</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">static_assert</span><span class="doxyHighlight"> (!literal.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/math/integer-literal/#ac09f666f846defca3cb8bd6e1b33c60e">is_integer</a> || literal.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/math/integer-literal/#a94438561fe06662519cf9687cc734fdb">is_too_large</a> || fits,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">504</span><span class="doxyLineContent"><span class="doxyHighlight">                     </span><span class="doxyHighlightStringLiteral">"µTest++: the integer literal value does not fit in the "</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">505</span><span class="doxyLineContent"><span class="doxyHighlight">                     </span><span class="doxyHighlightStringLiteral">"type of the literal"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">506</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">507</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> fits ? literal.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/math/integer-literal/#a79fda0403a1ee1c8fafecbab9e80c815">value</a> : 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">508</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="#a4f5af9be6a23a49f942e72de92adc91e">integer_magnitude</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/math/integer-literal/#ac09f666f846defca3cb8bd6e1b33c60e">micro_os_plus::micro_test_plus::detail::math::integer_literal::is_integer</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/math/integer-literal/#a94438561fe06662519cf9687cc734fdb">micro_os_plus::micro_test_plus::detail::math::integer_literal::is_too_large</a>, <a href="#a9292deab69ef8584bc2604e76316ecfd">parse_integer_literal</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/math/integer-literal/#a79fda0403a1ee1c8fafecbab9e80c815">micro_os_plus::micro_test_plus::detail::math::integer_literal::value</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value-base/#ad2d04a9ef0d53c48107b13005ec0877d">micro_os_plus::micro_test_plus::detail::value_base&lt; decltype(N)&gt;::value_base</a> and <a href="#a4f5af9be6a23a49f942e72de92adc91e">integer_magnitude</a>.</p>

</div>
</div>

### min\_value() {#a67e71e2dce0120ad4839635830e80de8}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const T &amp; micro_os_plus::micro_test_plus::detail::math::min_value (const T &amp; lhs, const T &amp; rhs)</td>
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

<p>Computes the minimum of two comparable values.</p>


<p>This function template provides a generic, constexpr implementation for determining the minimum of two values of any type that supports comparison.</p>


<p>The function returns a reference to the lesser of the two input values, as determined by the <span class="doxyComputerOutput">&lt;</span> operator. If the second argument is less than the first, it is returned; otherwise, the first argument is returned.</p>


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
<dt>Returns</dt>
<dd><p>A reference to the minimum of the two input values.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h/#l00109">109</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h">math-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a67e71e2dce0120ad4839635830e80de8">109</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a67e71e2dce0120ad4839635830e80de8">min_value</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; lhs, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; rhs) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight"> -&gt; </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">110</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">111</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> (rhs &lt; lhs) ? rhs : lhs;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">112</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="#a67e71e2dce0120ad4839635830e80de8">min_value</a>.</p>


<p>Referenced by <a href="#accba38bf51d261f330b594ca121e6f75">count_decimals</a>, <a href="#a67e71e2dce0120ad4839635830e80de8">min_value</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a6c5237ff6944278e8c5e3294cf99a3b9">micro_os_plus::micro_test_plus::detail::within_tolerance</a>.</p>

</div>
</div>

### num() {#a6b03b257bb18615448fe9b4fca4a8402}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T, char... Cs&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">T micro_os_plus::micro_test_plus::detail::math::num (void)</td>
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

<p>Computes the integral part of a decimal floating-point number represented as an array of characters.</p>


<p>This function template performs compile-time parsing of a numeric value from a sequence of characters, typically provided as a template parameter pack.</p>


<p>The characters must be decimal digits, a dot (<span class="doxyComputerOutput">.</span>), or digit separators (<span class="doxyComputerOutput">'</span>), which are skipped; otherwise (e.g. an exponent) the compilation fails with an explicit message, as it does if the integral part has more digits than <span class="doxyComputerOutput">T</span> can always hold. Parsing stops at the first dot, allowing the function to extract only the integral part of the number.</p>


<p>Used by the floating-point literal operators; the integer literals use <span class="doxyComputerOutput"><a href="#a4f5af9be6a23a49f942e72de92adc91e">integer_magnitude()</a></span>, which also accepts the C++ prefixes and checks the range.</p>


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
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The parsed integral value of type <span class="doxyComputerOutput">T</span>.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h/#l00175">175</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h">math-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a6b03b257bb18615448fe9b4fca4a8402">175</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a6b03b257bb18615448fe9b4fca4a8402">num</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) -&gt; T</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">176</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">177</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">static_assert</span><span class="doxyHighlight"> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">178</span><span class="doxyLineContent"><span class="doxyHighlight">          ((Cs == </span><span class="doxyHighlightCharLiteral">'.'</span><span class="doxyHighlight"> or Cs == </span><span class="doxyHighlightCharLiteral">'\''</span><span class="doxyHighlight"> or (Cs &gt;= </span><span class="doxyHighlightCharLiteral">'0'</span><span class="doxyHighlight"> and Cs &lt;= </span><span class="doxyHighlightCharLiteral">'9'</span><span class="doxyHighlight">)) and ...),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">179</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightStringLiteral">"µTest++: a floating-point literal must be written with decimal "</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">180</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightStringLiteral">"digits and a decimal point, without an exponent"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">181</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">static_assert</span><span class="doxyHighlight"> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">182</span><span class="doxyLineContent"><span class="doxyHighlight">          <a href="#af295fc92026927f8a453248655e7862e">count_literal_digits</a>&lt;</span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">, Cs...&gt; ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">183</span><span class="doxyLineContent"><span class="doxyHighlight">              &lt;= </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">std::size_t</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (std::numeric_limits&lt;T&gt;::digits10),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">184</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightStringLiteral">"µTest++: the floating-point literal has too many "</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">185</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightStringLiteral">"digits before the decimal point"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">186</span><span class="doxyLineContent"><span class="doxyHighlight">      T result{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">187</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> c : { Cs... })</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">188</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">189</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (c == </span><span class="doxyHighlightCharLiteral">'.'</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">190</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">191</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">192</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">193</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (c &gt;= </span><span class="doxyHighlightCharLiteral">'0'</span><span class="doxyHighlight"> and c &lt;= </span><span class="doxyHighlightCharLiteral">'9'</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">194</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">195</span><span class="doxyLineContent"><span class="doxyHighlight">              result = </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">T</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (result * </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">T</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (10)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">196</span><span class="doxyLineContent"><span class="doxyHighlight">                                       + </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">T</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (c - </span><span class="doxyHighlightCharLiteral">'0'</span><span class="doxyHighlight">));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">197</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">198</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">199</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> result;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">200</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="#af295fc92026927f8a453248655e7862e">count_literal_digits</a> and <a href="#a6b03b257bb18615448fe9b4fca4a8402">num</a>.</p>


<p>Referenced by <a href="#a6b03b257bb18615448fe9b4fca4a8402">num</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-deprecated-literals/#ga9d9b0d77e96cc46e7c9fabbb6cf671da">micro_os_plus::micro_test_plus::literals::operator""_d</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-deprecated-literals/#gab9d0b5fe567e9ea4b2cf4e7edd6ec2ef">micro_os_plus::micro_test_plus::literals::operator""_f</a> and <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-deprecated-literals/#gaecd8c981d99602a0d0a44ebf6d1d4f75">micro_os_plus::micro_test_plus::literals::operator""_ld</a>.</p>

</div>
</div>

### parse\_integer\_literal() {#a9292deab69ef8584bc2604e76316ecfd}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;char... Cs&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">integer_literal micro_os_plus::micro_test_plus::detail::math::parse_integer_literal (void)</td>
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

<p>Parses the characters of an integer literal.</p>


<p>The characters are those of a valid C++ literal, already checked by the compiler (digits valid for the base, digit separators in valid positions). The base is given by the prefix: <span class="doxyComputerOutput">0x</span> or <span class="doxyComputerOutput">0X</span> for hexadecimal, <span class="doxyComputerOutput">0b</span> or <span class="doxyComputerOutput">0B</span> for binary, a leading <span class="doxyComputerOutput">0</span> for octal, and none for decimal. The digit separators (<span class="doxyComputerOutput">'</span>) are skipped.</p>


<p>Any other character (a decimal point, an exponent, or a digit not valid for the base, as in the floating-point literal <span class="doxyComputerOutput">9.5</span>) marks the literal as not an integer. The value is accumulated in <span class="doxyComputerOutput">unsigned long long</span>, and the accumulation stops if it would overflow.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Cs</td>
<td class="doxyParamItemDescription"><p>The characters of the literal, as received by a literal operator template.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The value, and whether the characters form an integer literal and whether its value fits in <span class="doxyComputerOutput">unsigned long long</span>.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h/#l00395">395</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h">math-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a9292deab69ef8584bc2604e76316ecfd">395</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a9292deab69ef8584bc2604e76316ecfd">parse_integer_literal</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) -&gt; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/math/integer-literal">integer_literal</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">396</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">397</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> std::array&lt;char, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight">...(Cs)&gt; cs{ Cs... };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">398</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> max_value</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">399</span><span class="doxyLineContent"><span class="doxyHighlight">          = std::numeric_limits&lt;unsigned long long&gt;::max ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">400</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">401</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/math/integer-literal">integer_literal</a> result{ 0, </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">, </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight"> };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">402</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">403</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> base = 10;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">404</span><span class="doxyLineContent"><span class="doxyHighlight">      std::size_t i = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">405</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (cs.size () &gt; 1 &amp;&amp; cs[0] == </span><span class="doxyHighlightCharLiteral">'0'</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">406</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">407</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (cs[1] == </span><span class="doxyHighlightCharLiteral">'x'</span><span class="doxyHighlight"> || cs[1] == </span><span class="doxyHighlightCharLiteral">'X'</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">408</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">409</span><span class="doxyLineContent"><span class="doxyHighlight">              base = 16;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">410</span><span class="doxyLineContent"><span class="doxyHighlight">              i = 2;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">411</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">412</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (cs[1] == </span><span class="doxyHighlightCharLiteral">'b'</span><span class="doxyHighlight"> || cs[1] == </span><span class="doxyHighlightCharLiteral">'B'</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">413</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">414</span><span class="doxyLineContent"><span class="doxyHighlight">              base = 2;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">415</span><span class="doxyLineContent"><span class="doxyHighlight">              i = 2;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">416</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">417</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">418</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">419</span><span class="doxyLineContent"><span class="doxyHighlight">              base = 8;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">420</span><span class="doxyLineContent"><span class="doxyHighlight">              i = 1;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">421</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">422</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">423</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">424</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (; i &lt; cs.size (); ++i)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">425</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">426</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> c = cs[i];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">427</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (c == </span><span class="doxyHighlightCharLiteral">'\''</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">428</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">429</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">continue</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">430</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">431</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">432</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> digit = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">433</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (c &gt;= </span><span class="doxyHighlightCharLiteral">'0'</span><span class="doxyHighlight"> &amp;&amp; c &lt;= </span><span class="doxyHighlightCharLiteral">'9'</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">434</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">435</span><span class="doxyLineContent"><span class="doxyHighlight">              digit = </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (c - </span><span class="doxyHighlightCharLiteral">'0'</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">436</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">437</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (base == 16 &amp;&amp; c &gt;= </span><span class="doxyHighlightCharLiteral">'a'</span><span class="doxyHighlight"> &amp;&amp; c &lt;= </span><span class="doxyHighlightCharLiteral">'f'</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">438</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">439</span><span class="doxyLineContent"><span class="doxyHighlight">              digit = </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (c - </span><span class="doxyHighlightCharLiteral">'a'</span><span class="doxyHighlight"> + 10);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">440</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">441</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (base == 16 &amp;&amp; c &gt;= </span><span class="doxyHighlightCharLiteral">'A'</span><span class="doxyHighlight"> &amp;&amp; c &lt;= </span><span class="doxyHighlightCharLiteral">'F'</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">442</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">443</span><span class="doxyLineContent"><span class="doxyHighlight">              digit = </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (c - </span><span class="doxyHighlightCharLiteral">'A'</span><span class="doxyHighlight"> + 10);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">444</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">445</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">446</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">447</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightComment">// A decimal point, an exponent, or a suffix character.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">448</span><span class="doxyLineContent"><span class="doxyHighlight">              result.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/math/integer-literal/#ac09f666f846defca3cb8bd6e1b33c60e">is_integer</a> = </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">449</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> result;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">450</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">451</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">452</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (digit &gt;= base)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">453</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">454</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightComment">// Possible only in a floating-point literal, like `09.5`.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">455</span><span class="doxyLineContent"><span class="doxyHighlight">              result.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/math/integer-literal/#ac09f666f846defca3cb8bd6e1b33c60e">is_integer</a> = </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">456</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> result;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">457</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">458</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">459</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (result.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/math/integer-literal/#a79fda0403a1ee1c8fafecbab9e80c815">value</a> &gt; (max_value - digit) / base)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">460</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">461</span><span class="doxyLineContent"><span class="doxyHighlight">              result.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/math/integer-literal/#a94438561fe06662519cf9687cc734fdb">is_too_large</a> = </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">462</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> result;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">463</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">464</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">465</span><span class="doxyLineContent"><span class="doxyHighlight">          result.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/math/integer-literal/#a79fda0403a1ee1c8fafecbab9e80c815">value</a> = result.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/math/integer-literal/#a79fda0403a1ee1c8fafecbab9e80c815">value</a> * base + digit;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">466</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">467</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">468</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> result;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">469</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/math/integer-literal/#ac09f666f846defca3cb8bd6e1b33c60e">micro_os_plus::micro_test_plus::detail::math::integer_literal::is_integer</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/math/integer-literal/#a94438561fe06662519cf9687cc734fdb">micro_os_plus::micro_test_plus::detail::math::integer_literal::is_too_large</a>, <a href="#a9292deab69ef8584bc2604e76316ecfd">parse_integer_literal</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/math/integer-literal/#a79fda0403a1ee1c8fafecbab9e80c815">micro_os_plus::micro_test_plus::detail::math::integer_literal::value</a>.</p>


<p>Referenced by <a href="#a4f5af9be6a23a49f942e72de92adc91e">integer_magnitude</a> and <a href="#a9292deab69ef8584bc2604e76316ecfd">parse_integer_literal</a>.</p>

</div>
</div>

### pow() {#a121fbc662b8263c3b9ce605456fbc7d5}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T, class Exp_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">T micro_os_plus::micro_test_plus::detail::math::pow (const T base, const Exp_T exp)</td>
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

<p>Generic exponentiation function to compute the power of a base raised to an exponent.</p>


<p>This function template provides a constexpr implementation for raising a base value to a given exponent, supporting any types that allow multiplication.</p>


<p>The function starts from one and multiplies the result by the base <span class="doxyComputerOutput">exp</span> times. If the exponent is zero (or negative), the function returns one (the multiplicative identity for the type).</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The type of the base value. Must support multiplication assignment and construction from an integer.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Exp_T</td>
<td class="doxyParamItemDescription"><p>The type of the exponent. Must be default-constructible (to zero), and support the <span class="doxyComputerOutput">&lt;</span> and prefix <span class="doxyComputerOutput">++</span> operators.</p></td>
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
<dt>Returns</dt>
<dd><p>The result of raising <span class="doxyComputerOutput">base</span> to the power of <span class="doxyComputerOutput">exp</span>.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h/#l00126">126</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h">math-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a121fbc662b8263c3b9ce605456fbc7d5">126</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a121fbc662b8263c3b9ce605456fbc7d5">pow</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T base, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Exp_T exp) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight"> -&gt; T</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">127</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">128</span><span class="doxyLineContent"><span class="doxyHighlight">      T result{ 1 };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">129</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (Exp_T i{}; i &lt; exp; ++i)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">130</span><span class="doxyLineContent"><span class="doxyHighlight">        result *= base;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">131</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> result;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">132</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="#a121fbc662b8263c3b9ce605456fbc7d5">pow</a>.</p>


<p>Referenced by <a href="#ae474285acf7f49d66bb721b8ab5f8fa8">decimal_epsilon</a> and <a href="#a121fbc662b8263c3b9ce605456fbc7d5">pow</a>.</p>

</div>
</div>

</div>

<hr/>

The documentation for this namespace was generated from the following file:

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h">math-inlines.h</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
