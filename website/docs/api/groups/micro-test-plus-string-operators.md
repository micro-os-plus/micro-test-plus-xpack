---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-test-plus-string-operators
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# String Operators

<p>Overloaded operators for string comparison. <a href="#details">More...</a></p>

## Operators Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ga179e971d5e37795c036ad66aa35f1654">operator!=</a> (std::string_view lhs, std::string_view rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Non-equality operator for <span class="doxyComputerOutput">string_view</span> objects. <a href="#ga179e971d5e37795c036ad66aa35f1654">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#gaabe34a842bf38ea2913a4164d2b0a9cb">operator==</a> (std::string_view lhs, std::string_view rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Equality operator for <span class="doxyComputerOutput">string_view</span> objects. <a href="#gaabe34a842bf38ea2913a4164d2b0a9cb">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Overloaded operators for string comparison.</p>


<p>Operators are provided specifically for comparing string types, such as <span class="doxyComputerOutput">std::string_view</span>. These operators enable clear, expressive assertions when verifying string values in test cases, supporting both equality and inequality checks.</p>


<p>Using these dedicated operators ensures concise, readable tests that accurately reflect intended logic. The framework ensures correct string comparisons and reports failed checks with both actual and expected values for clear diagnostics.</p>


<dl class="doxySectionUser">
<dt>Examples</dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;string_view&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">using namespace </span><span class="doxyHighlight">std::literals; </span><span class="doxyHighlightComment">// For the "sv" literal.</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight">mt = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ...</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ts.test (</span><span class="doxyHighlightStringLiteral">"Check strings with operators"</span><span class="doxyHighlight">, [] (</span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; t) {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using namespace </span><span class="doxyHighlight">mt::operators;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  t.expect (std::string_view{ compute_ultimate_answer () } == </span><span class="doxyHighlightStringLiteral">"forty-two"</span><span class="doxyHighlight">sv)</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">      &lt;&lt; </span><span class="doxyHighlightStringLiteral">"ultimate answer == 'forty-two'"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">});</span></span></div>

</div>


<div class="doxySectionDef">

## Operators

### operator!=() {#ga179e971d5e37795c036ad66aa35f1654}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::operators::operator!= (std::string_view lhs, std::string_view rhs)</td>
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

<p>Non-equality operator for <span class="doxyComputerOutput">string_view</span> objects.</p>


<p>Constructs an <span class="doxyComputerOutput">ne_</span> comparator object from the two <span class="doxyComputerOutput">string_view</span> operands and returns it. The comparator evaluates to <span class="doxyComputerOutput">true</span> if the string views are not equal.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] lhs</td>
<td class="doxyParamItemDescription"><p>The left hand side <span class="doxyComputerOutput">std::string_view</span> operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] rhs</td>
<td class="doxyParamItemDescription"><p>The right hand side <span class="doxyComputerOutput">std::string_view</span> operand.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A comparator object that evaluates to true if the string views are not equal.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/operators-inlines-h/#l00088">88</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/operators-inlines-h">operators-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga179e971d5e37795c036ad66aa35f1654">88</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#ga179e971d5e37795c036ad66aa35f1654">operator!=</a>(std::string_view lhs, std::string_view rhs)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">89</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">90</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/ne-">detail::ne_</a>{ lhs, rhs };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">91</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>

</div>
</div>

### operator==() {#gaabe34a842bf38ea2913a4164d2b0a9cb}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::operators::operator== (std::string_view lhs, std::string_view rhs)</td>
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

<p>Equality operator for <span class="doxyComputerOutput">string_view</span> objects.</p>


<p>Constructs an <span class="doxyComputerOutput">eq_</span> comparator object from the two <span class="doxyComputerOutput">string_view</span> operands and returns it. The comparator evaluates to <span class="doxyComputerOutput">true</span> if the string views are equal.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] lhs</td>
<td class="doxyParamItemDescription"><p>The left hand side <span class="doxyComputerOutput">std::string_view</span> operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] rhs</td>
<td class="doxyParamItemDescription"><p>The right hand side <span class="doxyComputerOutput">std::string_view</span> operand.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A comparator object that evaluates to true if the string views are equal.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/operators-inlines-h/#l00076">76</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/operators-inlines-h">operators-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gaabe34a842bf38ea2913a4164d2b0a9cb">76</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#gaabe34a842bf38ea2913a4164d2b0a9cb">operator==</a>(std::string_view lhs, std::string_view rhs)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">77</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">78</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/eq-">detail::eq_</a>{ lhs, rhs };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">79</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>

</div>
</div>

</div>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.0 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
