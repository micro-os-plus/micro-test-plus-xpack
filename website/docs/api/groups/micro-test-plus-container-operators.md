---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-test-plus-container-operators
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# Container Operators

<p>Overloaded operators for container comparison. <a href="#details">More...</a></p>

## Operators Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt; ... &gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#gac48b765b41388c3ebe1a996f9a05aaf8">operator!=</a> (T &amp;&amp;lhs, T &amp;&amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Non-equality operator for containers. <a href="#gac48b765b41388c3ebe1a996f9a05aaf8">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt; ... &gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#gaac06b4166dbd6e2b62a744878903eee8">operator==</a> (T &amp;&amp;lhs, T &amp;&amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Equality operator for containers. <a href="#gaac06b4166dbd6e2b62a744878903eee8">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Overloaded operators for container comparison.</p>


<p>The µTest++ framework provides overloaded operators to facilitate direct and expressive comparison of standard containers, such as vectors and strings, within test cases. These operators enable developers to write clear and concise assertions when verifying the equality or inequality of container contents.</p>


<p>In addition to the generic operators, specialised equality and inequality operators are provided for containers, ensuring accurate and efficient comparison semantics that align with modern C++ practices.</p>


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
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">mt::test_case (</span><span class="doxyHighlightStringLiteral">"Operators"</span><span class="doxyHighlight">, [] {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using namespace </span><span class="doxyHighlight">micro_test_plus::operators;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  mt::expect (std::vector&lt;int&gt;{ 1, 2 } == std::vector&lt;int&gt;{ 1, 2 })</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">          &lt;&lt; </span><span class="doxyHighlightStringLiteral">"vector{ 1, 2 } == vector{ 1, 2 }"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  mt::expect (std::vector&lt;int&gt;{ 1, 2, 3 } != std::vector&lt;int&gt;{ 1, 2, 4 })</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">          &lt;&lt; </span><span class="doxyHighlightStringLiteral">"vector{ 1, 2, 3 } != vector{ 1, 2, 4 }"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">});</span></span></div>

</div>


<div class="doxySectionDef">

## Operators

### operator!=() {#gac48b765b41388c3ebe1a996f9a05aaf8}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T, type_traits::requires_t&lt; type_traits::is_container_v&lt; T &gt; &gt; = 0&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::operators::operator!= (T &amp;&amp; lhs, T &amp;&amp; rhs)</td>
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

<p>Non-equality operator for containers.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The container type, constrained to recognised container types.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] lhs</td>
<td class="doxyParamItemDescription"><p>The left hand side container operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] rhs</td>
<td class="doxyParamItemDescription"><p>The right hand side container operand.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A comparator object that evaluates to true if the containers are not equal.</p></dd>
</dl>


<p>This overload of the non-equality operator enables direct comparison of two container objects within the µTest++ framework. It constructs a comparator object that can be used in test expectations and assertions to verify that two containers are not equal in content or order.</p>


<p>The operator is enabled only for types recognised as containers by the framework's type traits.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/operators-h/#l00205">205</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/operators-h">operators.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gac48b765b41388c3ebe1a996f9a05aaf8">205</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-string-operators/#ga179e971d5e37795c036ad66aa35f1654">operator!=</a>(T&amp;&amp; lhs, T&amp;&amp; rhs)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">206</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">207</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/ne-">detail::ne_</a>{ </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">T&amp;&amp;</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (lhs), </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">T&amp;&amp;</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (rhs) };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">208</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>

</div>
</div>

### operator==() {#gaac06b4166dbd6e2b62a744878903eee8}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T, type_traits::requires_t&lt; type_traits::is_container_v&lt; T &gt; &gt; = 0&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::operators::operator== (T &amp;&amp; lhs, T &amp;&amp; rhs)</td>
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

<p>Equality operator for containers.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The container type, constrained to recognised container types.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] lhs</td>
<td class="doxyParamItemDescription"><p>The left hand side container operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] rhs</td>
<td class="doxyParamItemDescription"><p>The right hand side container operand.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A comparator object that evaluates to true if the containers are equal.</p></dd>
</dl>


<p>This overload of the equality operator enables direct comparison of two container objects within the µTest++ framework. It constructs a comparator object that can be used in test expectations and assertions to verify that two containers are equal in content and order.</p>


<p>The operator is enabled only for types recognised as containers by the framework's type traits.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/operators-h/#l00177">177</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/operators-h">operators.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gaac06b4166dbd6e2b62a744878903eee8">177</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-string-operators/#gaabe34a842bf38ea2913a4164d2b0a9cb">operator==</a>(T&amp;&amp; lhs, T&amp;&amp; rhs)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">178</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">179</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/eq-">detail::eq_</a>{ </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">T&amp;&amp;</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (lhs), </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">T&amp;&amp;</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (rhs) };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">180</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>

</div>
</div>

</div>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 1.1.0 by <a href="https://www.doxygen.nl">Doxygen</a> 1.14.0.</p>

</div>
