---

# DO NOT EDIT!
# Automatically generated via docusaurus-plugin-doxygen by Doxygen.

slug: /api/namespaces/micro-os-plus/micro-test-plus/math
custom_edit_url: null
toc_max_heading_level: 4
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
<dt>Returns</dt>
<dd><p>The absolute value of the input.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h/#l00096">96</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h">math-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a1dd33529640b959c531ca18c2e494c80">96</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1dd33529640b959c531ca18c2e494c80">abs</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T t) -&gt; T</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">97</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">98</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> t &lt; T{} ? -t : t;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">99</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>

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
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The parsed decimal part as an integral value of type <span class="doxyComputerOutput">T</span>.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h/#l00200">200</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h">math-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a1006429dba18038662409138f5754952">200</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1006429dba18038662409138f5754952">den</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) -&gt; T</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">201</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">202</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::array cs{ Cs... };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">203</span><span class="doxyLineContent"><span class="doxyHighlight">      T result{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">204</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> i = 0u;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">205</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">while</span><span class="doxyHighlight"> (cs[i++] != </span><span class="doxyHighlightCharLiteral">'.'</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">206</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">207</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">208</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">209</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> j = i; j &lt; </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight">...(Cs); ++j)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">210</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">211</span><span class="doxyLineContent"><span class="doxyHighlight">          result += <a href="#a5c22d85f0df63cc0504cbf4988173cd7">pow</a> (T (10), </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight">...(Cs) - j) * T (cs[j] - </span><span class="doxyHighlightCharLiteral">'0'</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">212</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">213</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> result;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">214</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="#a5c22d85f0df63cc0504cbf4988173cd7">pow</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9d9b0d77e96cc46e7c9fabbb6cf671da">micro_os_plus::micro_test_plus::literals::operator""_d</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gab9d0b5fe567e9ea4b2cf4e7edd6ec2ef">micro_os_plus::micro_test_plus::literals::operator""_f</a> and <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaecd8c981d99602a0d0a44ebf6d1d4f75">micro_os_plus::micro_test_plus::literals::operator""_ld</a>.</p>

</div>
</div>

### den\_size() {#a3e243d7f77b8435e1433ccad9c603f98}

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
<dt>Returns</dt>
<dd><p>The number of decimal places, as a value of type <span class="doxyComputerOutput">T</span>, up to a maximum of seven.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h/#l00269">269</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h">math-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a3e243d7f77b8435e1433ccad9c603f98">269</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a74757af775d3afa203b808e3f6642467">den_size</a> (Value_T value) -&gt; T</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">270</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">271</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> precision = Value_T (1e-7);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">272</span><span class="doxyLineContent"><span class="doxyHighlight">      T result{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">273</span><span class="doxyLineContent"><span class="doxyHighlight">      Value_T tmp{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">274</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">do</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">275</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">276</span><span class="doxyLineContent"><span class="doxyHighlight">          value *= 10;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">277</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">278</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">279</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if !defined(__clang__) </span><span class="doxyHighlightComment">// GCC only</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">280</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Warith-conversion"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">281</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">282</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">283</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wimplicit-int-float-conversion"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">284</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">285</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">286</span><span class="doxyLineContent"><span class="doxyHighlight">          tmp = value - T (value);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">287</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">288</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">289</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">290</span><span class="doxyLineContent"><span class="doxyHighlight">          ++result;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">291</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">292</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">while</span><span class="doxyHighlight"> (tmp &gt; precision);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">293</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">294</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> result;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">295</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>

</div>
</div>

### den\_size() {#a74757af775d3afa203b808e3f6642467}

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
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The number of decimal places as a value of type <span class="doxyComputerOutput">T</span>.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h/#l00233">233</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h">math-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a74757af775d3afa203b808e3f6642467">233</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a74757af775d3afa203b808e3f6642467">den_size</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) -&gt; T</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">234</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">235</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::array cs{ Cs... };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">236</span><span class="doxyLineContent"><span class="doxyHighlight">      T i{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">237</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">238</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">239</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Wconversion"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">240</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">241</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">while</span><span class="doxyHighlight"> (cs[i++] != </span><span class="doxyHighlightCharLiteral">'.'</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">242</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">243</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">244</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">245</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">246</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">247</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">248</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> T (</span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight">...(Cs)) - i + T (1);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">249</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9d9b0d77e96cc46e7c9fabbb6cf671da">micro_os_plus::micro_test_plus::literals::operator""_d</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gab9d0b5fe567e9ea4b2cf4e7edd6ec2ef">micro_os_plus::micro_test_plus::literals::operator""_f</a> and <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaecd8c981d99602a0d0a44ebf6d1d4f75">micro_os_plus::micro_test_plus::literals::operator""_ld</a>.</p>

</div>
</div>

### min\_value() {#ae53dd62f6d82b8ccaa048d90a7002826}

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
<dt>Returns</dt>
<dd><p>A reference to the minimum of the two input values.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h/#l00117">117</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h">math-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ae53dd62f6d82b8ccaa048d90a7002826">117</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#ae53dd62f6d82b8ccaa048d90a7002826">min_value</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; lhs, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; rhs) -&gt; </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">118</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">119</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> (rhs &lt; lhs) ? rhs : lhs;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">120</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>

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
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The parsed integral value of type <span class="doxyComputerOutput">T</span>.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h/#l00160">160</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h">math-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a98cbcae8bfc4a2d2f27487d1b2e641b7">160</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a98cbcae8bfc4a2d2f27487d1b2e641b7">num</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) -&gt; T</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">161</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">162</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// Assume all are digits or dot or apostrophe.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">163</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">static_assert</span><span class="doxyHighlight"> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">164</span><span class="doxyLineContent"><span class="doxyHighlight">          ((Cs == </span><span class="doxyHighlightCharLiteral">'.'</span><span class="doxyHighlight"> or Cs == </span><span class="doxyHighlightCharLiteral">'\''</span><span class="doxyHighlight"> or (Cs &gt;= </span><span class="doxyHighlightCharLiteral">'0'</span><span class="doxyHighlight"> and Cs &lt;= </span><span class="doxyHighlightCharLiteral">'9'</span><span class="doxyHighlight">)) and ...));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">165</span><span class="doxyLineContent"><span class="doxyHighlight">      T result{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">166</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> c : { Cs... })</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">167</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">168</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (c == </span><span class="doxyHighlightCharLiteral">'.'</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">169</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">170</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">171</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">172</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (c &gt;= </span><span class="doxyHighlightCharLiteral">'0'</span><span class="doxyHighlight"> and c &lt;= </span><span class="doxyHighlightCharLiteral">'9'</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">173</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">174</span><span class="doxyLineContent"><span class="doxyHighlight">              result = </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">T</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (result * </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">T</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (10)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">175</span><span class="doxyLineContent"><span class="doxyHighlight">                                       + </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">T</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (c - </span><span class="doxyHighlightCharLiteral">'0'</span><span class="doxyHighlight">));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">176</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">177</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">178</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> result;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">179</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gae521cebfd48332f44d01e4f880b4aafa">micro_os_plus::micro_test_plus::literals::operator""_c</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9d9b0d77e96cc46e7c9fabbb6cf671da">micro_os_plus::micro_test_plus::literals::operator""_d</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gab9d0b5fe567e9ea4b2cf4e7edd6ec2ef">micro_os_plus::micro_test_plus::literals::operator""_f</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga366a0d47aec3241e659816067c94fcdf">micro_os_plus::micro_test_plus::literals::operator""_i</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gabce6e838737bf25be6e7527f69e75590">micro_os_plus::micro_test_plus::literals::operator""_i16</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6a192d3dfff5a4a98aa7532d36d1b1bd">micro_os_plus::micro_test_plus::literals::operator""_i32</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gab0bb5d1e37cbe8de6477c11ecd60956d">micro_os_plus::micro_test_plus::literals::operator""_i64</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9ca6fecc72b6da90acee52977eb077d7">micro_os_plus::micro_test_plus::literals::operator""_i8</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga96e891b439024e116cb845bc65bc9c4f">micro_os_plus::micro_test_plus::literals::operator""_l</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaecd8c981d99602a0d0a44ebf6d1d4f75">micro_os_plus::micro_test_plus::literals::operator""_ld</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaf5ab66b00c9486ade5d49f34a83783f5">micro_os_plus::micro_test_plus::literals::operator""_ll</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga812816a2e9b23de1f8d8b2d86553d96d">micro_os_plus::micro_test_plus::literals::operator""_s</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga57d27f1a76de2d2b2a067134cbe61457">micro_os_plus::micro_test_plus::literals::operator""_sc</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaf45bf641153a462a1ba7c12b908e667f">micro_os_plus::micro_test_plus::literals::operator""_u</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga96d12d563093f297a73a8b984ae7a3a5">micro_os_plus::micro_test_plus::literals::operator""_u16</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga3171e605b5c2e1d9a0e55ae34e904674">micro_os_plus::micro_test_plus::literals::operator""_u32</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga622b4808b7ebfc26ddf9db9128533f28">micro_os_plus::micro_test_plus::literals::operator""_u64</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga80f43260f6a1afd8260355136858df48">micro_os_plus::micro_test_plus::literals::operator""_u8</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6c1b46d4b967bdbc573e3192c2d9f98a">micro_os_plus::micro_test_plus::literals::operator""_uc</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaef96b19b140b5007ec33a944c3b72cae">micro_os_plus::micro_test_plus::literals::operator""_ul</a>, <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga01adcd3866da43c393b7fba8a5e72bb2">micro_os_plus::micro_test_plus::literals::operator""_ull</a> and <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9017debdc1eafd64e3c53c80157ad6f5">micro_os_plus::micro_test_plus::literals::operator""_us</a>.</p>

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
<dt>Returns</dt>
<dd><p>The result of raising <span class="doxyComputerOutput">base</span> to the power of <span class="doxyComputerOutput">exp</span>.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h/#l00138">138</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h">math-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a5c22d85f0df63cc0504cbf4988173cd7">138</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a5c22d85f0df63cc0504cbf4988173cd7">pow</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T base, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Exp_T exp) -&gt; T</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">139</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">140</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// If the exponent is 0, return 1, otherwise recurse.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">141</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> exp ? T (base * <a href="#a5c22d85f0df63cc0504cbf4988173cd7">pow</a> (base, exp - Exp_T (1))) : T (1);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">142</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="#a5c22d85f0df63cc0504cbf4988173cd7">pow</a>.</p>


<p>Referenced by <a href="#a1006429dba18038662409138f5754952">den</a> and <a href="#a5c22d85f0df63cc0504cbf4988173cd7">pow</a>.</p>

</div>
</div>

</div>

<hr/>

The documentation for this namespace was generated from the following file:

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/math-inlines-h">math-inlines.h</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://github.com/xpack/docusaurus-plugin-doxygen">docusaurus-plugin-doxygen</a> by <a href="https://www.doxygen.nl">Doxygen</a> 1.14.0.</p>

</div>
