---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-os-plus-micro-test-plus-cpp-api-logical-functions
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# Logical Functions

<p>Functions used to compose logical expressions in tests. <a href="#details">More...</a></p>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class First_T, class Second_T, class... Rest_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#gab9b9c26860ceafc1288ecb415f52aaaf">all_of</a> (First_T &amp;&amp;first, Second_T &amp;&amp;second, Rest_T &amp;&amp;... rest)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Generic logical <b>and</b> operation, for two or more operands. <a href="#gab9b9c26860ceafc1288ecb415f52aaaf">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class First_T, class Second_T, class... Rest_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#gae6395736f05626ba6dcf79ecc523486c">any_of</a> (First_T &amp;&amp;first, Second_T &amp;&amp;second, Rest_T &amp;&amp;... rest)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Generic logical (inclusive) <b>or</b> operation, for two or more operands. <a href="#gae6395736f05626ba6dcf79ecc523486c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Expr_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ga6a0bb2654eb89c1b0a35134e8738eeb1">negate</a> (Expr_T &amp;&amp;expr)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Generic logical <b>not</b> operation. <a href="#ga6a0bb2654eb89c1b0a35134e8738eeb1">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Functions used to compose logical expressions in tests.</p>


<p>The functions <span class="doxyComputerOutput">mt::all_of()</span>, <span class="doxyComputerOutput">mt::any_of()</span>, and <span class="doxyComputerOutput">mt::negate()</span> combine multiple conditions, allowing expressive and concise test logic. <span class="doxyComputerOutput">mt::all_of()</span> and <span class="doxyComputerOutput">mt::any_of()</span> take two or more operands, and <span class="doxyComputerOutput">mt::any_of()</span> is an inclusive or: it is true also when all the conditions are true. A chain of the same operation is reported as a single group, for example <span class="doxyComputerOutput">(a and b and c)</span>.</p>


<p>All the operands are evaluated before the check, so the functions do not stop at the first operand that decides the result, like the standard algorithms of the same names. After a <span class="doxyComputerOutput">using namespace std</span>, an unqualified call with three or more operands of the same type selects the standard algorithm; call the functions as <span class="doxyComputerOutput">mt::all_of()</span> and <span class="doxyComputerOutput">mt::any_of()</span>.</p>


<p>The functions have descriptive names, since <span class="doxyComputerOutput">and</span>, <span class="doxyComputerOutput">or</span>, and <span class="doxyComputerOutput">not</span> are alternative tokens and cannot be used as identifiers. Using these logical functions allows developers to express compound conditions clearly and improve readability.</p>


<dl class="doxySectionUser">
<dt>Example</dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ts.test (</span><span class="doxyHighlightStringLiteral">"Check compound conditions"</span><span class="doxyHighlight">, [] (</span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; t) {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  t.expect (mt::all_of (mt::eq (compute_answer (), 42),</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                        mt::eq (compute_float (), 42.0),</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                        mt::lt (compute_answer (), 43)));</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">});</span></span></div>

</div>


<p>The overloaded logical operators of the <span class="doxyComputerOutput">micro_test_plus::operators</span> namespace are deprecated since 6.0.0, in favour of these functions.</p>


<div class="doxySectionDef">

## Functions

### all\_of() {#gab9b9c26860ceafc1288ecb415f52aaaf}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class First_T, class Second_T, class... Rest_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::all_of (First_T &amp;&amp; first, Second_T &amp;&amp; second, Rest_T &amp;&amp;... rest)</td>
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

<p>Generic logical <b>and</b> operation, for two or more operands.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">First_T</td>
<td class="doxyParamItemDescription"><p>Type of the first operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Second_T</td>
<td class="doxyParamItemDescription"><p>Type of the second operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rest_T</td>
<td class="doxyParamItemDescription"><p>Types of the other operands, if any.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">first</td>
<td class="doxyParamItemDescription"><p>First operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">second</td>
<td class="doxyParamItemDescription"><p>Second operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">rest</td>
<td class="doxyParamItemDescription"><p>The other operands, if any.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>An object that evaluates to true if all the operand expressions are true.</p></dd>
</dl>


<p>The <span class="doxyComputerOutput"><a href="#gab9b9c26860ceafc1288ecb415f52aaaf">all_of</a></span> function template provides a generic logical conjunction for any expression types. It constructs a <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/and-op">detail::and_op</a></span> logical conjunction object, which evaluates to <span class="doxyComputerOutput">true</span> if all the operands are true. For more than two operands, the objects are nested from the left, <span class="doxyComputerOutput">(a and b) and c</span>, and the expression formatter writes them as a single chain, <span class="doxyComputerOutput">(a and b and c)</span>.</p>


<p>All the operands are evaluated before the check, so, unlike the standard algorithm of the same name, the function does not stop at the first operand that is false.</p>


<p>The name is the same as that of <span class="doxyComputerOutput">std::all_of</span>: after a <span class="doxyComputerOutput">using namespace std</span>, an unqualified call with three or more operands of the same type selects the standard algorithm, so the function must be called as <span class="doxyComputerOutput">mt::all_of()</span>.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/function-comparators-inlines-h/#l00246">246</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/function-comparators-inlines-h">function-comparators-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gab9b9c26860ceafc1288ecb415f52aaaf">246</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#gab9b9c26860ceafc1288ecb415f52aaaf">all_of</a> (First_T&amp;&amp; first, Second_T&amp;&amp; second, Rest_T&amp;&amp;... rest)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">247</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">248</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight">...(Rest_T) == 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">249</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">250</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/and-op">detail::and_op</a>{ std::forward&lt;First_T&gt; (first),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">251</span><span class="doxyLineContent"><span class="doxyHighlight">                               std::forward&lt;Second_T&gt; (second) };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">252</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">253</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">254</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">255</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#gab9b9c26860ceafc1288ecb415f52aaaf">micro_test_plus::all_of</a> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">256</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/and-op">detail::and_op</a>{ std::forward&lt;First_T&gt; (first),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">257</span><span class="doxyLineContent"><span class="doxyHighlight">                            std::forward&lt;Second_T&gt; (second) },</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">258</span><span class="doxyLineContent"><span class="doxyHighlight">            std::forward&lt;Rest_T&gt; (rest)...);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">259</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">260</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#gab9b9c26860ceafc1288ecb415f52aaaf">micro_os_plus::micro_test_plus::all_of</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-deprecated-logical-functions/#ga9998cd63972fac8b24a2f0138322e7c1">micro_os_plus::micro_test_plus::_and</a> and <a href="#gab9b9c26860ceafc1288ecb415f52aaaf">micro_os_plus::micro_test_plus::all_of</a>.</p>

</div>
</div>

### any\_of() {#gae6395736f05626ba6dcf79ecc523486c}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class First_T, class Second_T, class... Rest_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::any_of (First_T &amp;&amp; first, Second_T &amp;&amp; second, Rest_T &amp;&amp;... rest)</td>
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

<p>Generic logical (inclusive) <b>or</b> operation, for two or more operands.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">First_T</td>
<td class="doxyParamItemDescription"><p>Type of the first operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Second_T</td>
<td class="doxyParamItemDescription"><p>Type of the second operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rest_T</td>
<td class="doxyParamItemDescription"><p>Types of the other operands, if any.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">first</td>
<td class="doxyParamItemDescription"><p>First operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">second</td>
<td class="doxyParamItemDescription"><p>Second operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">rest</td>
<td class="doxyParamItemDescription"><p>The other operands, if any.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>An object that evaluates to true if at least one of the operand expressions is true, including when all are.</p></dd>
</dl>


<p>The <span class="doxyComputerOutput"><a href="#gae6395736f05626ba6dcf79ecc523486c">any_of</a></span> function template provides a generic logical disjunction for any expression types. It constructs a <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/or-op">detail::or_op</a></span> logical disjunction object, which evaluates to <span class="doxyComputerOutput">true</span> if at least one of the operands is true; the disjunction is inclusive, so the result is also true when all the conditions are true. For more than two operands, the objects are nested from the left, and the expression formatter writes them as a single chain, <span class="doxyComputerOutput">(a or b or c)</span>.</p>


<p>All the operands are evaluated before the check, so the function does not stop at the first operand that is true; and, as for <span class="doxyComputerOutput"><a href="#gab9b9c26860ceafc1288ecb415f52aaaf">all_of()</a></span>, it must be called as <span class="doxyComputerOutput">mt::any_of()</span> after a <span class="doxyComputerOutput">using namespace std</span>.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/function-comparators-inlines-h/#l00278">278</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/function-comparators-inlines-h">function-comparators-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gae6395736f05626ba6dcf79ecc523486c">278</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#gae6395736f05626ba6dcf79ecc523486c">any_of</a> (First_T&amp;&amp; first, Second_T&amp;&amp; second, Rest_T&amp;&amp;... rest)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">279</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">280</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight">...(Rest_T) == 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">281</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">282</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/or-op">detail::or_op</a>{ std::forward&lt;First_T&gt; (first),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">283</span><span class="doxyLineContent"><span class="doxyHighlight">                              std::forward&lt;Second_T&gt; (second) };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">284</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">285</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">286</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">287</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#gae6395736f05626ba6dcf79ecc523486c">micro_test_plus::any_of</a> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">288</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/or-op">detail::or_op</a>{ std::forward&lt;First_T&gt; (first),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">289</span><span class="doxyLineContent"><span class="doxyHighlight">                           std::forward&lt;Second_T&gt; (second) },</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">290</span><span class="doxyLineContent"><span class="doxyHighlight">            std::forward&lt;Rest_T&gt; (rest)...);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">291</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">292</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#gae6395736f05626ba6dcf79ecc523486c">micro_os_plus::micro_test_plus::any_of</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-deprecated-logical-functions/#ga1c7ddbf53764ab67240f1cf0e0fb4b8d">micro_os_plus::micro_test_plus::_or</a> and <a href="#gae6395736f05626ba6dcf79ecc523486c">micro_os_plus::micro_test_plus::any_of</a>.</p>

</div>
</div>

### negate() {#ga6a0bb2654eb89c1b0a35134e8738eeb1}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Expr_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::negate (Expr_T &amp;&amp; expr)</td>
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

<p>Generic logical <b>not</b> operation.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Expr_T</td>
<td class="doxyParamItemDescription"><p>Type of the operand.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">expr</td>
<td class="doxyParamItemDescription"><p>Logical expression to be negated.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>An object that evaluates to true if the operand is false.</p></dd>
</dl>


<p>The <span class="doxyComputerOutput"><a href="#ga6a0bb2654eb89c1b0a35134e8738eeb1">negate</a></span> function template provides a generic logical negation for any expression type. It constructs a <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/not-op">detail::not_op</a></span> logical negator object, which evaluates to <span class="doxyComputerOutput">true</span> if the operand is false; the template argument is named, since the class template argument deduction would copy an operand that is itself a <span class="doxyComputerOutput">not_op</span>, instead of negating it.</p>


<p>It is the function form of the <span class="doxyComputerOutput">!</span> operator from the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/operators">micro_test_plus::operators</a></span> namespace.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/function-comparators-inlines-h/#l00219">219</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/function-comparators-inlines-h">function-comparators-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga6a0bb2654eb89c1b0a35134e8738eeb1">219</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ga6a0bb2654eb89c1b0a35134e8738eeb1">negate</a> (Expr_T&amp;&amp; expr)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">220</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">221</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/not-op">detail::not_op&lt;detail::stored_operand_t&lt;Expr_T&gt;</a>&gt;{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">222</span><span class="doxyLineContent"><span class="doxyHighlight">      std::forward&lt;Expr_T&gt; (expr)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">223</span><span class="doxyLineContent"><span class="doxyHighlight">    };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">224</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#ga6a0bb2654eb89c1b0a35134e8738eeb1">micro_os_plus::micro_test_plus::negate</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-deprecated-logical-functions/#gaa465723bc4fe309f15d30a4e7207d40f">micro_os_plus::micro_test_plus::_not</a> and <a href="#ga6a0bb2654eb89c1b0a35134e8738eeb1">micro_os_plus::micro_test_plus::negate</a>.</p>

</div>
</div>

</div>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
