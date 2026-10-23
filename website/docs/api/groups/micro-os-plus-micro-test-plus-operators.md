---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-os-plus-micro-test-plus-operators
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# Operators

<p>Overloaded operators for expressive test comparisons. <a href="#details">More...</a></p>

## Operators Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#gad47ea22957940a08ff56104d3c0c16f7">operator and</a> (Lhs_T &amp;&amp;lhs, Rhs_T &amp;&amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Logical <span class="doxyComputerOutput">&amp;&amp;</span> (and) operator. Matches only if at least one operand is a framework type (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a></span>). <a href="#gad47ea22957940a08ff56104d3c0c16f7">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ga1d79c807e0d12684f1a850d7269c077b">operator not</a> (T &amp;&amp;t)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Logical <span class="doxyComputerOutput">!</span> (not) operator. Matches only if the operand is a framework type (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a></span>). <a href="#ga1d79c807e0d12684f1a850d7269c077b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#gac008174d3b00512dc53b3e9e26ed45ec">operator or</a> (Lhs_T &amp;&amp;lhs, Rhs_T &amp;&amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Logical <span class="doxyComputerOutput">||</span> (or) operator. Matches only if at least one operand is a framework type (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a></span>). <a href="#gac008174d3b00512dc53b3e9e26ed45ec">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ga0cc55025bbf6cac2f1b64242784559cb">operator!=</a> (Lhs_T &amp;&amp;lhs, Rhs_T &amp;&amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Non-equality operator. Matches only if at least one operand is a framework type (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a></span>). <a href="#ga0cc55025bbf6cac2f1b64242784559cb">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ga1d1c66d2cce699e0e64d8307e3951090">operator&lt;</a> (Lhs_T &amp;&amp;lhs, Rhs_T &amp;&amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Less than operator. Matches only if at least one operand is a framework type (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a></span>). <a href="#ga1d1c66d2cce699e0e64d8307e3951090">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#gaa0bcc006277ab947cf9ff7f13ab9b8ed">operator&lt;=</a> (Lhs_T &amp;&amp;lhs, Rhs_T &amp;&amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Less than or equal operator. Matches only if at least one operand is a framework type (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a></span>). <a href="#gaa0bcc006277ab947cf9ff7f13ab9b8ed">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ga6f2d36e79581db77f3aa9f8d7a958c78">operator==</a> (Lhs_T &amp;&amp;lhs, Rhs_T &amp;&amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Equality operator. Matches only if at least one operand is a framework type (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a></span>). <a href="#ga6f2d36e79581db77f3aa9f8d7a958c78">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#gaa7e34201bb41a287742c3c08a88924d3">operator&gt;</a> (Lhs_T &amp;&amp;lhs, Rhs_T &amp;&amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Greater than operator. Matches only if at least one operand is a framework type (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a></span>). <a href="#gaa7e34201bb41a287742c3c08a88924d3">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ga9d9f5f30c7d8973ef7ccd6f52f0cbd21">operator&gt;=</a> (Lhs_T &amp;&amp;lhs, Rhs_T &amp;&amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Greater than or equal operator. Matches only if at least one operand is a framework type (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a></span>). <a href="#ga9d9f5f30c7d8973ef7ccd6f52f0cbd21">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Overloaded operators for expressive test comparisons.</p>


<p>These overloads enable expressive, type-safe test assertions. Operators such as <span class="doxyComputerOutput">==</span>, <span class="doxyComputerOutput">!=</span>, <span class="doxyComputerOutput">&lt;</span>, <span class="doxyComputerOutput">&gt;</span>, <span class="doxyComputerOutput">&lt;=</span>, and <span class="doxyComputerOutput">&gt;=</span> are defined in the dedicated <span class="doxyComputerOutput">micro_test_plus::operators</span> namespace to avoid conflicts with application-defined operators.</p>


<p>For standard values, the default operators are used, ensuring correct comparisons. However, when specialised µTest++ operators are used with typed operands, failed checks display both actual and expected values, greatly improving report clarity.</p>


<p>These operators are restricted to the framework types (see <span class="doxyComputerOutput">extension::is_op</span>). For constant values, this is achieved with provided literals (for example, <span class="doxyComputerOutput">1_i</span>), whilst dynamic values can be wrapped with converters such as <span class="doxyComputerOutput">mt::to_i{expression}</span>. When neither operand is of such a type, the standard operators are selected; they return a plain <span class="doxyComputerOutput">bool</span>, so a failed check cannot show the operands.</p>


<p>There are no operators for strings and containers: the standard operators would be selected for <span class="doxyComputerOutput">std::string</span> objects and for containers of the same type, and operators for <span class="doxyComputerOutput">std::string_view</span> objects would also replace the standard ones in the application code that follows the <span class="doxyComputerOutput">using namespace</span> directive. Use <span class="doxyComputerOutput">mt::eq()</span> and <span class="doxyComputerOutput">mt::ne()</span> to compare strings and containers.</p>


<p>Logical operators (<span class="doxyComputerOutput">&amp;&amp;</span>, <span class="doxyComputerOutput">||</span>, <span class="doxyComputerOutput">!</span>) are also supported and provide enhanced functionality when used with typed operands, allowing complex test conditions to be composed naturally and readably.</p>


<dl class="doxySectionUser">
<dt>Examples</dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight">mt = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ts.test (</span><span class="doxyHighlightStringLiteral">"Operators"</span><span class="doxyHighlight">, [] (</span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; t) {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using namespace </span><span class="doxyHighlight">mt::operators;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using namespace </span><span class="doxyHighlight">mt::literals;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  t.expect (compute_answer () == 42_i) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"answer is 42 (with literal)"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  t.expect (mt::to_i {compute_answer ()} == 42) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"answer is 42 (with cast)"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  t.expect (compute_answer () != 43_i) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"answer is not 43"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  t.expect (compute_answer () &lt; 43_i) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"answer is &lt; 43"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  t.expect (compute_answer () &lt;= 43_i) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"answer is &lt;= 43"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  t.expect (compute_answer () &gt; 41_i) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"answer is &gt; 41"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  t.expect (compute_answer () &gt;= 42_i) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"answer is &gt;= 42"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">});</span></span></div>

</div>


<dl class="doxySectionUser">
<dt>Logical Operators</dt>
<dd></dd>
</dl>


<p>Logical operators provide enhanced reporting when used with typed operands, allowing complex test conditions to be composed naturally and readably.</p>


<dl class="doxySectionUser">
<dt>Example</dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight">mt = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ts.test (</span><span class="doxyHighlightStringLiteral">"Logical operators"</span><span class="doxyHighlight">, [] (</span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; t) {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using namespace </span><span class="doxyHighlight">mt::operators;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using namespace </span><span class="doxyHighlight">mt::literals;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  t.expect (compute_answer () == 42_i &amp;&amp; compute_float () == 42.0_f);</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">});</span></span></div>

</div>


<div class="doxySectionDef">

## Operators

### operator and() {#gad47ea22957940a08ff56104d3c0c16f7}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::operators::operator and (Lhs_T &amp;&amp; lhs, Rhs_T &amp;&amp; rhs)</td>
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

<p>Logical <span class="doxyComputerOutput">&amp;&amp;</span> (and) operator. Matches only if at least one operand is a framework type (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a></span>).</p>


<p>Constructs an <span class="doxyComputerOutput">and_op</span> logical conjunction object from the two operands and returns it. The object evaluates to <span class="doxyComputerOutput">true</span> if both operands are true. At least one operand must be a framework type (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a></span>).</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>Type of the left hand side operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>Type of the right hand side operand.</p></td>
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
<td class="doxyParamItemDescription"><p>Left hand side operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">rhs</td>
<td class="doxyParamItemDescription"><p>Right hand side operand.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A logical conjunction object that evaluates to true if both operands are true.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/operators-inlines-h/#l00188">188</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/operators-inlines-h">operators-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gad47ea22957940a08ff56104d3c0c16f7">188</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlight"> and (Lhs_T&amp;&amp; lhs, Rhs_T&amp;&amp; rhs)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">189</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">190</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/and-op">detail::and_op</a>{ std::forward&lt;Lhs_T&gt; (lhs),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">191</span><span class="doxyLineContent"><span class="doxyHighlight">                             std::forward&lt;Rhs_T&gt; (rhs) };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">192</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>

</div>
</div>

### operator not() {#ga1d79c807e0d12684f1a850d7269c077b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::operators::operator not (T &amp;&amp; t)</td>
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

<p>Logical <span class="doxyComputerOutput">!</span> (not) operator. Matches only if the operand is a framework type (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a></span>).</p>


<p>Constructs a <span class="doxyComputerOutput">not_op</span> logical negator object from the operand and returns it. The object evaluates to <span class="doxyComputerOutput">true</span> if the operand is false. The operand must be a framework type (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a></span>).</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>Type of the operand, constrained to the framework types.</p></td>
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
<td class="doxyParamItemDescription"><p>Operand to be logically negated.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A logical negator object that evaluates to true if the operand is false.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/operators-inlines-h/#l00220">220</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/operators-inlines-h">operators-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga1d79c807e0d12684f1a850d7269c077b">220</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlight"> not(T&amp;&amp; t)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">221</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">222</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// Not `not_op{ t }`, which would copy an operand that is itself</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">223</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// a `not_op`, instead of negating it.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">224</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/not-op">detail::not_op&lt;detail::stored_operand_t&lt;T&gt;</a>&gt;{ std::forward&lt;T&gt; (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">225</span><span class="doxyLineContent"><span class="doxyHighlight">          t) };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">226</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>

</div>
</div>

### operator or() {#gac008174d3b00512dc53b3e9e26ed45ec}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::operators::operator or (Lhs_T &amp;&amp; lhs, Rhs_T &amp;&amp; rhs)</td>
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

<p>Logical <span class="doxyComputerOutput">||</span> (or) operator. Matches only if at least one operand is a framework type (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a></span>).</p>


<p>Constructs an <span class="doxyComputerOutput">or_op</span> logical disjunction object from the two operands and returns it. The object evaluates to <span class="doxyComputerOutput">true</span> if at least one operand is true. At least one operand must be a framework type (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a></span>).</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>Type of the left hand side operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>Type of the right hand side operand.</p></td>
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
<td class="doxyParamItemDescription"><p>Left hand side operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">rhs</td>
<td class="doxyParamItemDescription"><p>Right hand side operand.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A logical disjunction object that evaluates to true if at least one operand is true.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/operators-inlines-h/#l00205">205</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/operators-inlines-h">operators-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gac008174d3b00512dc53b3e9e26ed45ec">205</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlight"> or (Lhs_T&amp;&amp; lhs, Rhs_T&amp;&amp; rhs)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">206</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">207</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/or-op">detail::or_op</a>{ std::forward&lt;Lhs_T&gt; (lhs),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">208</span><span class="doxyLineContent"><span class="doxyHighlight">                            std::forward&lt;Rhs_T&gt; (rhs) };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">209</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>

</div>
</div>

### operator!=() {#ga0cc55025bbf6cac2f1b64242784559cb}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::operators::operator!= (Lhs_T &amp;&amp; lhs, Rhs_T &amp;&amp; rhs)</td>
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

<p>Non-equality operator. Matches only if at least one operand is a framework type (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a></span>).</p>


<p>Constructs a comparator object, with the <span class="doxyComputerOutput">not_equal_to</span> tag, from the two operands and returns it. The comparator evaluates to <span class="doxyComputerOutput">true</span> if the operands are not equal. At least one operand must be a framework type (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a></span>).</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>Type of the left hand side operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>Type of the right hand side operand.</p></td>
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
<td class="doxyParamItemDescription"><p>Left hand side operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">rhs</td>
<td class="doxyParamItemDescription"><p>Right hand side operand.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A comparator object that evaluates to true if the operands are not equal.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/operators-inlines-h/#l00099">99</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/operators-inlines-h">operators-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga0cc55025bbf6cac2f1b64242784559cb">99</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#ga0cc55025bbf6cac2f1b64242784559cb">operator!=</a>(Lhs_T&amp;&amp; lhs, Rhs_T&amp;&amp; rhs)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">100</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">101</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/compare-op">detail::compare_op</a>{ std::forward&lt;Lhs_T&gt; (lhs),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">102</span><span class="doxyLineContent"><span class="doxyHighlight">                                 std::forward&lt;Rhs_T&gt; (rhs),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">103</span><span class="doxyLineContent"><span class="doxyHighlight">                                 <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/not-equal-to">detail::not_equal_to</a>{} };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">104</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>

</div>
</div>

### operator&lt;() {#ga1d1c66d2cce699e0e64d8307e3951090}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::operators::operator&lt; (Lhs_T &amp;&amp; lhs, Rhs_T &amp;&amp; rhs)</td>
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

<p>Less than operator. Matches only if at least one operand is a framework type (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a></span>).</p>


<p>Constructs a comparator object, with the <span class="doxyComputerOutput">less</span> tag, from the two operands and returns it. The comparator evaluates to <span class="doxyComputerOutput">true</span> if <span class="doxyComputerOutput">lhs</span> is less than <span class="doxyComputerOutput">rhs</span>. At least one operand must be a framework type (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a></span>).</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>Type of the left hand side operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>Type of the right hand side operand.</p></td>
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
<td class="doxyParamItemDescription"><p>Left hand side operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">rhs</td>
<td class="doxyParamItemDescription"><p>Right hand side operand.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A comparator object that evaluates to true if the left hand side operand is less than the right hand side operand.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/operators-inlines-h/#l00152">152</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/operators-inlines-h">operators-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">153</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#ga1d1c66d2cce699e0e64d8307e3951090">operator&lt;</a>(Lhs_T&amp;&amp; lhs, Rhs_T&amp;&amp; rhs)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">154</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">155</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/compare-op">detail::compare_op</a>{ std::forward&lt;Lhs_T&gt; (lhs),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">156</span><span class="doxyLineContent"><span class="doxyHighlight">                                 std::forward&lt;Rhs_T&gt; (rhs), <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/less">detail::less</a>{} };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">157</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>

</div>
</div>

### operator&lt;=() {#gaa0bcc006277ab947cf9ff7f13ab9b8ed}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::operators::operator&lt;= (Lhs_T &amp;&amp; lhs, Rhs_T &amp;&amp; rhs)</td>
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

<p>Less than or equal operator. Matches only if at least one operand is a framework type (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a></span>).</p>


<p>Constructs a comparator object, with the <span class="doxyComputerOutput">less_equal</span> tag, from the two operands and returns it. The comparator evaluates to <span class="doxyComputerOutput">true</span> if <span class="doxyComputerOutput">lhs</span> is less than or equal to <span class="doxyComputerOutput">rhs</span>. At least one operand must be a framework type (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a></span>).</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>Type of the left hand side operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>Type of the right hand side operand.</p></td>
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
<td class="doxyParamItemDescription"><p>Left hand side operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">rhs</td>
<td class="doxyParamItemDescription"><p>Right hand side operand.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A comparator object that evaluates to true if the left hand side operand is less than or equal to the right hand side operand.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/operators-inlines-h/#l00169">169</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/operators-inlines-h">operators-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">170</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#gaa0bcc006277ab947cf9ff7f13ab9b8ed">operator&lt;=</a>(Lhs_T&amp;&amp; lhs, Rhs_T&amp;&amp; rhs)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">171</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">172</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/compare-op">detail::compare_op</a>{ std::forward&lt;Lhs_T&gt; (lhs),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">173</span><span class="doxyLineContent"><span class="doxyHighlight">                                 std::forward&lt;Rhs_T&gt; (rhs),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">174</span><span class="doxyLineContent"><span class="doxyHighlight">                                 <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/less-equal">detail::less_equal</a>{} };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">175</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>

</div>
</div>

### operator==() {#ga6f2d36e79581db77f3aa9f8d7a958c78}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::operators::operator== (Lhs_T &amp;&amp; lhs, Rhs_T &amp;&amp; rhs)</td>
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

<p>Equality operator. Matches only if at least one operand is a framework type (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a></span>).</p>


<p>Constructs a comparator object, with the <span class="doxyComputerOutput">equal_to</span> tag, from the two operands and returns it. The comparator evaluates to <span class="doxyComputerOutput">true</span> if the operands are equal. At least one operand must be a framework type (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a></span>).</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>Type of the left hand side operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>Type of the right hand side operand.</p></td>
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
<td class="doxyParamItemDescription"><p>Left hand side operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">rhs</td>
<td class="doxyParamItemDescription"><p>Right hand side operand.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A comparator object that evaluates to true if the operands are equal.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/operators-inlines-h/#l00081">81</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/operators-inlines-h">operators-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga6f2d36e79581db77f3aa9f8d7a958c78">81</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#ga6f2d36e79581db77f3aa9f8d7a958c78">operator==</a>(Lhs_T&amp;&amp; lhs, Rhs_T&amp;&amp; rhs)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">82</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">83</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/compare-op">detail::compare_op</a>{ std::forward&lt;Lhs_T&gt; (lhs),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">84</span><span class="doxyLineContent"><span class="doxyHighlight">                                 std::forward&lt;Rhs_T&gt; (rhs),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">85</span><span class="doxyLineContent"><span class="doxyHighlight">                                 <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/equal-to">detail::equal_to</a>{} };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">86</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>

</div>
</div>

### operator&gt;() {#gaa7e34201bb41a287742c3c08a88924d3}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::operators::operator&gt; (Lhs_T &amp;&amp; lhs, Rhs_T &amp;&amp; rhs)</td>
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

<p>Greater than operator. Matches only if at least one operand is a framework type (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a></span>).</p>


<p>Constructs a comparator object, with the <span class="doxyComputerOutput">greater</span> tag, from the two operands and returns it. The comparator evaluates to <span class="doxyComputerOutput">true</span> if <span class="doxyComputerOutput">lhs</span> is greater than <span class="doxyComputerOutput">rhs</span>. At least one operand must be a framework type (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a></span>).</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>Type of the left hand side operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>Type of the right hand side operand.</p></td>
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
<td class="doxyParamItemDescription"><p>Left hand side operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">rhs</td>
<td class="doxyParamItemDescription"><p>Right hand side operand.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A comparator object that evaluates to true if the left hand side operand is greater than the right hand side operand.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/operators-inlines-h/#l00117">117</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/operators-inlines-h">operators-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gaa7e34201bb41a287742c3c08a88924d3">117</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#gaa7e34201bb41a287742c3c08a88924d3">operator&gt;</a>(Lhs_T&amp;&amp; lhs, Rhs_T&amp;&amp; rhs)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">118</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">119</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/compare-op">detail::compare_op</a>{ std::forward&lt;Lhs_T&gt; (lhs),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">120</span><span class="doxyLineContent"><span class="doxyHighlight">                                 std::forward&lt;Rhs_T&gt; (rhs),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">121</span><span class="doxyLineContent"><span class="doxyHighlight">                                 <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/greater">detail::greater</a>{} };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">122</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>

</div>
</div>

### operator&gt;=() {#ga9d9f5f30c7d8973ef7ccd6f52f0cbd21}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::operators::operator&gt;= (Lhs_T &amp;&amp; lhs, Rhs_T &amp;&amp; rhs)</td>
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

<p>Greater than or equal operator. Matches only if at least one operand is a framework type (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a></span>).</p>


<p>Constructs a comparator object, with the <span class="doxyComputerOutput">greater_equal</span> tag, from the two operands and returns it. The comparator evaluates to <span class="doxyComputerOutput">true</span> if <span class="doxyComputerOutput">lhs</span> is greater than or equal to <span class="doxyComputerOutput">rhs</span>. At least one operand must be a framework type (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a></span>).</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>Type of the left hand side operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>Type of the right hand side operand.</p></td>
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
<td class="doxyParamItemDescription"><p>Left hand side operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">rhs</td>
<td class="doxyParamItemDescription"><p>Right hand side operand.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A comparator object that evaluates to true if the left hand side operand is greater than or equal to the right hand side operand.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/operators-inlines-h/#l00135">135</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/operators-inlines-h">operators-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga9d9f5f30c7d8973ef7ccd6f52f0cbd21">135</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#ga9d9f5f30c7d8973ef7ccd6f52f0cbd21">operator&gt;=</a>(Lhs_T&amp;&amp; lhs, Rhs_T&amp;&amp; rhs)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">136</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">137</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/compare-op">detail::compare_op</a>{ std::forward&lt;Lhs_T&gt; (lhs),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">138</span><span class="doxyLineContent"><span class="doxyHighlight">                                 std::forward&lt;Rhs_T&gt; (rhs),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">139</span><span class="doxyLineContent"><span class="doxyHighlight">                                 <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/greater-equal">detail::greater_equal</a>{} };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">140</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>

</div>
</div>

</div>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
