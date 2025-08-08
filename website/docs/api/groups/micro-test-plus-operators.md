---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-test-plus-operators
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
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt; ... &gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ga6f792d4a05a9b4e2e5b15c21905639f4">operator and</a> (const Lhs_T &amp;lhs, const Rhs_T &amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Logical <span class="doxyComputerOutput">&amp;&amp;</span> (and) operator. Matches only if at least one operand is of local type (derived from local <span class="doxyComputerOutput">op</span>). <a href="#ga6f792d4a05a9b4e2e5b15c21905639f4">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ga76287e126ef9eaf3039d970d70f3a436">operator not</a> (const T &amp;t)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Logical <span class="doxyComputerOutput">!</span> (not) operator. Matches only if the operand is of local type (derived from local <span class="doxyComputerOutput">op</span>). <a href="#ga76287e126ef9eaf3039d970d70f3a436">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#gaaad46363338988f9080425b0d327b779">operator or</a> (const Lhs_T &amp;lhs, const Rhs_T &amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Logical <span class="doxyComputerOutput">||</span> (or) operator. Matches only if at least one operand is of local type (derived from local <span class="doxyComputerOutput">op</span>). <a href="#gaaad46363338988f9080425b0d327b779">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#gae2090b8535bb7860e6104347b2d9f4e6">operator!=</a> (const Lhs_T &amp;lhs, const Rhs_T &amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Non-equality operator for custom types. Matches only if at least one operand is of local type. <a href="#gae2090b8535bb7860e6104347b2d9f4e6">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#gad934faf2be89b200f4d286c26c043a29">operator&lt;</a> (const Lhs_T &amp;lhs, const Rhs_T &amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Less than operator. Matches only if at least one operand is of local type (derived from local <span class="doxyComputerOutput">op</span>). <a href="#gad934faf2be89b200f4d286c26c043a29">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ga7862426cbe47cb764473e8bc9f49c0a9">operator&lt;=</a> (const Lhs_T &amp;lhs, const Rhs_T &amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Less than or equal operator. Matches only if at least one operand is of local type (derived from local <span class="doxyComputerOutput">op</span>). <a href="#ga7862426cbe47cb764473e8bc9f49c0a9">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ga26bc1232c48df9b79463025f66da5f1f">operator==</a> (const Lhs_T &amp;lhs, const Rhs_T &amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Equality operator for custom types. Matches only if at least one operand is of local type. <a href="#ga26bc1232c48df9b79463025f66da5f1f">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#gabd2a0c082adee2dbdd69043ba8d34dcd">operator&gt;</a> (const Lhs_T &amp;lhs, const Rhs_T &amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Greater than operator. Matches only if at least one operand is of local type (derived from local <span class="doxyComputerOutput">op</span>). <a href="#gabd2a0c082adee2dbdd69043ba8d34dcd">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ga676092b57233f1137778ee9c38e24a46">operator&gt;=</a> (const Lhs_T &amp;lhs, const Rhs_T &amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Greater than or equal operator. Matches only if at least one operand is of local type (derived from local <span class="doxyComputerOutput">op</span>). <a href="#ga676092b57233f1137778ee9c38e24a46">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Overloaded operators for expressive test comparisons.</p>


<p>The µTest++ framework provides overloaded comparison and logical operators to enable expressive and type-safe test assertions. These operators—such as <span class="doxyComputerOutput">==</span>, <span class="doxyComputerOutput">!=</span>, <span class="doxyComputerOutput">&lt;</span>, <span class="doxyComputerOutput">&gt;</span>, <span class="doxyComputerOutput">&lt;=</span>, and <span class="doxyComputerOutput">&gt;=</span>—are defined within the dedicated <span class="doxyComputerOutput">micro_test_plus::operators</span> namespace to avoid conflicts with application-defined operators.</p>


<p>For standard values, the default operators are used, ensuring correct comparisons. However, when using the specialised µTest++ operators with typed operands, failed checks will display both the actual and expected values, greatly improving the clarity of test reports.</p>


<p>These operators are restricted to operands derived from the local <span class="doxyComputerOutput">detail::op</span> type. For constant values, this is achieved using provided literals (e.g., <span class="doxyComputerOutput">1_i</span>), while dynamic values can be wrapped using casts such as <span class="doxyComputerOutput">mt::to_i{expression}</span>.</p>


<p>Logical operators (<span class="doxyComputerOutput">&amp;&amp;</span>, <span class="doxyComputerOutput">||</span>, <span class="doxyComputerOutput">!</span>) are also supported and provide enhanced functionality when used with typed operands, allowing for the composition of complex test conditions in a natural and readable manner.</p>


<dl class="doxySectionUser">
<dt>Examples</dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">mt::test_case (</span><span class="doxyHighlightStringLiteral">"Operators"</span><span class="doxyHighlight">, [] {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using namespace </span><span class="doxyHighlight">micro_test_plus::operators;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using namespace </span><span class="doxyHighlight">micro_test_plus::literals;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  mt::expect (compute_answer () == 42_i) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"answer is 42 (with literal)"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  mt::expect (mt::to_i {compute_answer ()} == 42) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"answer is 42 (with cast)"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  mt::expect (compute_answer () != 43_i) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"answer is not 43"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  mt::expect (compute_answer () &lt; 43_i) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"answer is &lt; 43"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  mt::expect (compute_answer () &lt;= 43_i) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"answer is &lt;= 42"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  mt::expect (compute_answer () &gt; 41_i) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"answer is &gt; 43"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  mt::expect (compute_answer () &gt;= 42_i) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"answer is &gt;= 42"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">});</span></span></div>

</div>



### Logical operators {#autotoc_md1}


<p>Logical operators may be used in the same way as standard operators, with enhanced reporting available when used with typed operands.</p>


<dl class="doxySectionUser">
<dt>Example</dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">mt::expect (compute_answer () == 42_i &amp;&amp; compute_float () == 42.0_f);</span></span></div>

</div>


<div class="doxySectionDef">

## Operators

### operator and() {#ga6f792d4a05a9b4e2e5b15c21905639f4}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T, type_traits::requires_t&lt; type_traits::is_op_v&lt; Lhs_T &gt; or type_traits::is_op_v&lt; Rhs_T &gt; &gt; = 0&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::operators::operator and (const Lhs_T &amp; lhs, const Rhs_T &amp; rhs)</td>
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

<p>Logical <span class="doxyComputerOutput">&amp;&amp;</span> (and) operator. Matches only if at least one operand is of local type (derived from local <span class="doxyComputerOutput">op</span>).</p>


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
<td class="doxyParamItemName">[in] lhs</td>
<td class="doxyParamItemDescription"><p>Left hand side operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] rhs</td>
<td class="doxyParamItemDescription"><p>Right hand side operand.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A logical conjunction object that evaluates to true if both operands are true.</p></dd>
</dl>


<p>This overload of the logical <span class="doxyComputerOutput">&amp;&amp;</span> (and) operator enables conjunction between two operands, where at least one is a local type derived from the local <span class="doxyComputerOutput">op</span> base. It constructs a logical conjunction object that can be used within the µTest++ framework to assert that both operands evaluate to true. This operator is intended for use with the framework's strongly-typed constants, wrappers, or other custom types, ensuring type-safe and expressive test assertions.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/operators-h/#l00431">431</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/operators-h">operators.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga6f792d4a05a9b4e2e5b15c21905639f4">431</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlight"> and (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Lhs_T&amp; lhs, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Rhs_T&amp; rhs)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">432</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">433</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/and-">detail::and_</a>{ lhs, rhs };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">434</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>

</div>
</div>

### operator not() {#ga76287e126ef9eaf3039d970d70f3a436}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T, type_traits::requires_t&lt; type_traits::is_op_v&lt; T &gt; &gt; = 0&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::operators::operator not (const T &amp; t)</td>
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

<p>Logical <span class="doxyComputerOutput">!</span> (not) operator. Matches only if the operand is of local type (derived from local <span class="doxyComputerOutput">op</span>).</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>Type of the operand, constrained to types derived from the local <span class="doxyComputerOutput">op</span> base.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] t</td>
<td class="doxyParamItemDescription"><p>Operand to be logically negated.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A logical negator object that evaluates to true if the operand is false.</p></dd>
</dl>


<p>This overload of the logical <span class="doxyComputerOutput">!</span> (not) operator enables logical negation of an operand, provided it is a local type derived from the local <span class="doxyComputerOutput">op</span> base. It constructs a logical negator object that can be used within the µTest++ framework to assert that a given condition is false. This operator is intended for use with the framework's strongly-typed constants, wrappers, or other custom types, ensuring type-safe and expressive test assertions.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/operators-h/#l00491">491</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/operators-h">operators.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga76287e126ef9eaf3039d970d70f3a436">491</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlight"> not(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; t)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">492</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">493</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/not-">detail::not_</a>{ t };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">494</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>

</div>
</div>

### operator or() {#gaaad46363338988f9080425b0d327b779}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T, type_traits::requires_t&lt; type_traits::is_op_v&lt; Lhs_T &gt; or type_traits::is_op_v&lt; Rhs_T &gt; &gt; = 0&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::operators::operator or (const Lhs_T &amp; lhs, const Rhs_T &amp; rhs)</td>
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

<p>Logical <span class="doxyComputerOutput">||</span> (or) operator. Matches only if at least one operand is of local type (derived from local <span class="doxyComputerOutput">op</span>).</p>


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
<td class="doxyParamItemName">[in] lhs</td>
<td class="doxyParamItemDescription"><p>Left hand side operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] rhs</td>
<td class="doxyParamItemDescription"><p>Right hand side operand.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A logical disjunction object that evaluates to true if at least one operand is true.</p></dd>
</dl>


<p>This overload of the logical <span class="doxyComputerOutput">||</span> (or) operator enables disjunction between two operands, where at least one is a local type derived from the local <span class="doxyComputerOutput">op</span> base. It constructs a logical disjunction object that can be used within the µTest++ framework to assert that at least one operand evaluates to true. This operator is intended for use with the framework's strongly-typed constants, wrappers, or other custom types, ensuring type-safe and expressive test assertions.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/operators-h/#l00463">463</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/operators-h">operators.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gaaad46363338988f9080425b0d327b779">463</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlight"> or (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Lhs_T&amp; lhs, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Rhs_T&amp; rhs)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">464</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">465</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/or-">detail::or_</a>{ lhs, rhs };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">466</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>

</div>
</div>

### operator!=() {#gae2090b8535bb7860e6104347b2d9f4e6}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T, type_traits::requires_t&lt; type_traits::is_op_v&lt; Lhs_T &gt; or type_traits::is_op_v&lt; Rhs_T &gt; &gt; = 0&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::operators::operator!= (const Lhs_T &amp; lhs, const Rhs_T &amp; rhs)</td>
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

<p>Non-equality operator for custom types. Matches only if at least one operand is of local type.</p>


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
<td class="doxyParamItemName">[in] lhs</td>
<td class="doxyParamItemDescription"><p>Left hand side operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] rhs</td>
<td class="doxyParamItemDescription"><p>Right hand side operand.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A comparator object that evaluates to true if the operands are not equal.</p></dd>
</dl>


<p>This overload of the non-equality operator enables comparison between two operands, where at least one is a local type derived from the local <span class="doxyComputerOutput">op</span> base. It constructs a comparator object that can be used within the µTest++ framework to assert that the operands are not equal. This operator is intended for use with the framework's strongly-typed constants, wrappers, or other custom types, ensuring type-safe and expressive test assertions.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/operators-h/#l00269">269</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/operators-h">operators.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gae2090b8535bb7860e6104347b2d9f4e6">269</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-string-operators/#ga179e971d5e37795c036ad66aa35f1654">operator!=</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Lhs_T&amp; lhs, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Rhs_T&amp; rhs)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">270</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">271</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/ne-">detail::ne_</a>{ lhs, rhs };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">272</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>

</div>
</div>

### operator&lt;() {#gad934faf2be89b200f4d286c26c043a29}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T, type_traits::requires_t&lt; type_traits::is_op_v&lt; Lhs_T &gt; or type_traits::is_op_v&lt; Rhs_T &gt; &gt; = 0&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::operators::operator&lt; (const Lhs_T &amp; lhs, const Rhs_T &amp; rhs)</td>
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

<p>Less than operator. Matches only if at least one operand is of local type (derived from local <span class="doxyComputerOutput">op</span>).</p>


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
<td class="doxyParamItemName">[in] lhs</td>
<td class="doxyParamItemDescription"><p>Left hand side operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] rhs</td>
<td class="doxyParamItemDescription"><p>Right hand side operand.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A comparator object that evaluates to true if the left hand side operand is less than the right hand side operand.</p></dd>
</dl>


<p>This overload of the less than operator enables comparison between two operands, where at least one is a local type derived from the local <span class="doxyComputerOutput">op</span> base. It constructs a comparator object that can be used within the µTest++ framework to assert that the left hand side operand is less than the right hand side operand. This operator is intended for use with the framework's strongly-typed constants, wrappers, or other custom types, ensuring type-safe and expressive test assertions.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/operators-h/#l00365">365</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/operators-h">operators.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">366</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#gad934faf2be89b200f4d286c26c043a29">operator&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Lhs_T&amp; lhs, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Rhs_T&amp; rhs)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">367</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">368</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/lt-">detail::lt_</a>{ lhs, rhs };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">369</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>

</div>
</div>

### operator&lt;=() {#ga7862426cbe47cb764473e8bc9f49c0a9}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T, type_traits::requires_t&lt; type_traits::is_op_v&lt; Lhs_T &gt; or type_traits::is_op_v&lt; Rhs_T &gt; &gt; = 0&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::operators::operator&lt;= (const Lhs_T &amp; lhs, const Rhs_T &amp; rhs)</td>
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

<p>Less than or equal operator. Matches only if at least one operand is of local type (derived from local <span class="doxyComputerOutput">op</span>).</p>


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
<td class="doxyParamItemName">[in] lhs</td>
<td class="doxyParamItemDescription"><p>Left hand side operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] rhs</td>
<td class="doxyParamItemDescription"><p>Right hand side operand.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A comparator object that evaluates to true if the left hand side operand is less than or equal to the right hand side operand.</p></dd>
</dl>


<p>This overload of the less than or equal operator enables comparison between two operands, where at least one is a local type derived from the local <span class="doxyComputerOutput">op</span> base. It constructs a comparator object that can be used within the µTest++ framework to assert that the left hand side operand is less than or equal to the right hand side operand. This operator is intended for use with the framework's strongly-typed constants, wrappers, or other custom types, ensuring type-safe and expressive test assertions.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/operators-h/#l00398">398</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/operators-h">operators.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">399</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#ga7862426cbe47cb764473e8bc9f49c0a9">operator&lt;=</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Lhs_T&amp; lhs, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Rhs_T&amp; rhs)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">400</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">401</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/le-">detail::le_</a>{ lhs, rhs };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">402</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>

</div>
</div>

### operator==() {#ga26bc1232c48df9b79463025f66da5f1f}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T, type_traits::requires_t&lt; type_traits::is_op_v&lt; Lhs_T &gt; or type_traits::is_op_v&lt; Rhs_T &gt; &gt; = 0&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::operators::operator== (const Lhs_T &amp; lhs, const Rhs_T &amp; rhs)</td>
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

<p>Equality operator for custom types. Matches only if at least one operand is of local type.</p>


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
<td class="doxyParamItemName">[in] lhs</td>
<td class="doxyParamItemDescription"><p>Left hand side operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] rhs</td>
<td class="doxyParamItemDescription"><p>Right hand side operand.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A comparator object that evaluates to true if the operands are equal.</p></dd>
</dl>


<p>This overload of the equality operator enables comparison between two operands, where at least one is a local type derived from the local <span class="doxyComputerOutput">op</span> base. It constructs a comparator object that can be used within the µTest++ framework to assert that the operands are equal. This operator is intended for use with the framework's strongly-typed constants, wrappers, or other custom types, ensuring type-safe and expressive test assertions.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/operators-h/#l00237">237</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/operators-h">operators.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga26bc1232c48df9b79463025f66da5f1f">237</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-string-operators/#gaabe34a842bf38ea2913a4164d2b0a9cb">operator==</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Lhs_T&amp; lhs, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Rhs_T&amp; rhs)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">238</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">239</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/eq-">detail::eq_</a>{ lhs, rhs };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">240</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>

</div>
</div>

### operator&gt;() {#gabd2a0c082adee2dbdd69043ba8d34dcd}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T, type_traits::requires_t&lt; type_traits::is_op_v&lt; Lhs_T &gt; or type_traits::is_op_v&lt; Rhs_T &gt; &gt; = 0&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::operators::operator&gt; (const Lhs_T &amp; lhs, const Rhs_T &amp; rhs)</td>
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

<p>Greater than operator. Matches only if at least one operand is of local type (derived from local <span class="doxyComputerOutput">op</span>).</p>


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
<td class="doxyParamItemName">[in] lhs</td>
<td class="doxyParamItemDescription"><p>Left hand side operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] rhs</td>
<td class="doxyParamItemDescription"><p>Right hand side operand.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A comparator object that evaluates to true if the left hand side operand is greater than the right hand side operand.</p></dd>
</dl>


<p>This overload of the greater than operator enables comparison between two operands, where at least one is a local type derived from the local <span class="doxyComputerOutput">op</span> base. It constructs a comparator object that can be used within the µTest++ framework to assert that the left hand side operand is greater than the right hand side operand. This operator is intended for use with the framework's strongly-typed constants, wrappers, or other custom types, ensuring type-safe and expressive test assertions.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/operators-h/#l00301">301</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/operators-h">operators.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gabd2a0c082adee2dbdd69043ba8d34dcd">301</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#gabd2a0c082adee2dbdd69043ba8d34dcd">operator&gt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Lhs_T&amp; lhs, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Rhs_T&amp; rhs)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">302</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">303</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/gt-">detail::gt_</a>{ lhs, rhs };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">304</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>

</div>
</div>

### operator&gt;=() {#ga676092b57233f1137778ee9c38e24a46}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T, type_traits::requires_t&lt; type_traits::is_op_v&lt; Lhs_T &gt; or type_traits::is_op_v&lt; Rhs_T &gt; &gt; = 0&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::operators::operator&gt;= (const Lhs_T &amp; lhs, const Rhs_T &amp; rhs)</td>
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

<p>Greater than or equal operator. Matches only if at least one operand is of local type (derived from local <span class="doxyComputerOutput">op</span>).</p>


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
<td class="doxyParamItemName">[in] lhs</td>
<td class="doxyParamItemDescription"><p>Left hand side operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] rhs</td>
<td class="doxyParamItemDescription"><p>Right hand side operand.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A comparator object that evaluates to true if the left hand side operand is greater than or equal to the right hand side operand.</p></dd>
</dl>


<p>This overload of the greater than or equal operator enables comparison between two operands, where at least one is a local type derived from the local <span class="doxyComputerOutput">op</span> base. It constructs a comparator object that can be used within the µTest++ framework to assert that the left hand side operand is greater than or equal to the right hand side operand. This operator is intended for use with the framework's strongly-typed constants, wrappers, or other custom types, ensuring type-safe and expressive test assertions.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/operators-h/#l00334">334</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/operators-h">operators.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga676092b57233f1137778ee9c38e24a46">334</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#ga676092b57233f1137778ee9c38e24a46">operator&gt;=</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Lhs_T&amp; lhs, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Rhs_T&amp; rhs)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">335</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">336</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/ge-">detail::ge_</a>{ lhs, rhs };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">337</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>

</div>
</div>

</div>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 1.1.0 by <a href="https://www.doxygen.nl">Doxygen</a> 1.14.0.</p>

</div>
