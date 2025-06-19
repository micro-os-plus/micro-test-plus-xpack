---

# DO NOT EDIT!
# Automatically generated via docusaurus-plugin-doxygen by Doxygen.

slug: /api/groups/micro-test-plus-string-operators
custom_edit_url: null
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# The String Operators Reference

<p>Overloaded operators for string comparison. <a href="#details">More...</a></p>

## Operators Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">constexpr auto</td>
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
<td class="doxyMemberIndexItemType" align="right" valign="top">constexpr auto</td>
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


<p>The µTest++ framework provides overloaded operators specifically for comparing string types, such as <span class="doxyComputerOutput">std::string_view</span>. These operators enable clear and expressive assertions when verifying string values within test cases, supporting both equality and inequality checks.</p>

<p>By using these dedicated string operators, developers can write concise and readable tests that accurately reflect the intended logic. The framework ensures that string comparisons are performed correctly and that any failed checks are reported with both the actual and expected values for straightforward diagnostics.</p>

<dl class="doxySectionUser">
<dt><b>Examples</b></dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;string_view&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">using namespace </span><span class="doxyHighlight">std::literals; </span><span class="doxyHighlightComment">// For the "sv" literal.</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight">mt = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ...</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">mt::test_case (</span><span class="doxyHighlightStringLiteral">"Operators"</span><span class="doxyHighlight">, [] {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using namespace </span><span class="doxyHighlight">micro_test_plus::operators;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  mt::expect (std::string_view{ compute_ultimate_answer () } == </span><span class="doxyHighlightStringLiteral">"forty-two"</span><span class="doxyHighlight">sv)</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">          &lt;&lt; </span><span class="doxyHighlightStringLiteral">"ultimate answer == 'forty-two'"</span><span class="doxyHighlight">;</span></span></div>
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
<dt><b>Returns</b></dt>
<dd>
<p>A comparator object that evaluates to true if the string views are not equal.</p>
</dd>
</dl>


<p>This overload of the non-equality operator enables direct comparison of two <span class="doxyComputerOutput">std::string_view</span> objects within the µTest++ framework. It constructs a comparator object that can be used in test expectations and assertions to verify that two string views are not equal.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/operators-h/#l00149">149</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/operators-h">operators.h</a>.</p>
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
<dt><b>Returns</b></dt>
<dd>
<p>A comparator object that evaluates to true if the string views are equal.</p>
</dd>
</dl>


<p>This overload of the equality operator enables direct comparison of two <span class="doxyComputerOutput">std::string_view</span> objects within the µTest++ framework. It constructs a comparator object that can be used in test expectations and assertions to verify that two string views are equal.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/operators-h/#l00128">128</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/operators-h">operators.h</a>.</p>
</div>
</div>

</div>

<p class="doxyGeneratedBy">Generated via <a href="https://github.com/xpack/docusaurus-plugin-doxygen">docusaurus-plugin-doxygen</a> by <a href="https://www.doxygen.nl">Doxygen</a> 1.14.0.</p>

</div>
