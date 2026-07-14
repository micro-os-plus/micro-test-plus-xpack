---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/structs/micro-os-plus/micro-test-plus/detail/gt-
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - struct

---

<div class="doxyPage">

# `gt_` Struct Template

<p>Greater than comparator struct template. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
template &lt;class Lhs_T, class Rhs_T&gt;<br/>
struct micro_os_plus::micro_test_plus::detail::gt_&lt;Lhs_T, Rhs_T&gt; { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include &lt;<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>&gt;
</div>

## Base struct

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">struct</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-">binary_op_&lt;Lhs_T, Rhs_T&gt;</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Common base struct template for binary comparators. <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Constructors Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a0d3eb79b0fd8cd986a18ac77abb98192">gt_</a> (const Lhs_T &amp;lhs={}, const Rhs_T &amp;rhs={})</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructs a greater than comparator for the given operands. <a href="#a0d3eb79b0fd8cd986a18ac77abb98192">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Operators Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a854f1034410a13b6d2673beec610604a">operator bool</a> () const</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Conversion operator to boolean. <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a854f1034410a13b6d2673beec610604a">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Member Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a503196c2296449a52b6f7995d4a647f5">lhs</a> (void) const</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Retrieves the left-hand operand. <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a503196c2296449a52b6f7995d4a647f5">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#adfe5734554daf4e5793f0708f3121284">rhs</a> (void) const</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Retrieves the right-hand operand. <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#adfe5734554daf4e5793f0708f3121284">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Private Member Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">const Lhs_T</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#ac3bcfee808c65ee0d6be74d564cbf58c">lhs_</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Stores the left-hand operand. <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#ac3bcfee808c65ee0d6be74d564cbf58c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">const Rhs_T</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#ab6217372c20998ca75fe5e7a73754d7c">rhs_</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Stores the right-hand operand. <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#ab6217372c20998ca75fe5e7a73754d7c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">const bool</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a2dd578daf62dde786b3e9e7beeac08bc">value_</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Stores the result of the comparison. <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a2dd578daf62dde786b3e9e7beeac08bc">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Greater than comparator struct template.</p>


<p>Derived from <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-">binary_op_</a></span>, this struct checks whether the left-hand operand is greater than the right-hand operand. It is used within test expressions to provide human-readable relational assertions with enhanced reporting of the actual and expected values upon failure.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>The type of the left-hand operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>The type of the right-hand operand.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Definition at line 369 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>.</p>


<div class="doxySectionDef">

## Public Constructors

### gt\_() {#a0d3eb79b0fd8cd986a18ac77abb98192}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::gt_&lt; Lhs_T, Rhs_T &gt;::gt_ (const Lhs_T &amp; lhs={}, const Rhs_T &amp; rhs={})</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel constexpr">constexpr</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Constructs a greater than comparator for the given operands.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">lhs</td>
<td class="doxyParamItemDescription"><p>The left-hand operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">rhs</td>
<td class="doxyParamItemDescription"><p>The right-hand operand.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Evaluates whether <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a503196c2296449a52b6f7995d4a647f5">lhs</a> &gt; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#adfe5734554daf4e5793f0708f3121284">rhs</a></span> inside an immediately invoked lambda and passes the boolean result to the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-">binary_op_</a></span> base class constructor. Supports types with static <span class="doxyComputerOutput">value</span> members and generic types.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l00377">377</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h/#l00318">318</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h">detail-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a0d3eb79b0fd8cd986a18ac77abb98192">318</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> <a href="#a0d3eb79b0fd8cd986a18ac77abb98192">gt_&lt;Lhs_T, Rhs_T&gt;::gt_</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Lhs_T&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a503196c2296449a52b6f7995d4a647f5">lhs</a>, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Rhs_T&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#adfe5734554daf4e5793f0708f3121284">rhs</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">319</span><span class="doxyLineContent"><span class="doxyHighlight">        : <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a9ba8011f48a2cb4e7ff928298594005a">binary_op_</a>&lt;Lhs_T, Rhs_T&gt;{ <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a503196c2296449a52b6f7995d4a647f5">lhs</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#adfe5734554daf4e5793f0708f3121284">rhs</a>, [&amp;]</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">320</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">321</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight">std::operator&gt;;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">322</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">323</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">324</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">325</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Wconversion"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">326</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Wdouble-promotion"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">327</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Wsign-compare"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">328</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">329</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wimplicit-int-float-conversion"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">330</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wpedantic"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">331</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">332</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">333</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/type-traits/has-value">type_traits::has_value&lt;Lhs_T&gt;</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">334</span><span class="doxyLineContent"><span class="doxyHighlight">                      and <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/type-traits/has-value">type_traits::has_value&lt;Rhs_T&gt;</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">335</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">336</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> Lhs_T::value &gt; Rhs_T::value;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">337</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">338</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">339</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">340</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac627271520bf2fe8a4c4774bcd9bf343">get</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a503196c2296449a52b6f7995d4a647f5">lhs</a>) &gt; <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac627271520bf2fe8a4c4774bcd9bf343">get</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#adfe5734554daf4e5793f0708f3121284">rhs</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">341</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">342</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">343</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">344</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">345</span><span class="doxyLineContent"><span class="doxyHighlight">      }() }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">346</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">347</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a9ba8011f48a2cb4e7ff928298594005a">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::binary_op_</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac627271520bf2fe8a4c4774bcd9bf343">micro_os_plus::micro_test_plus::detail::get</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a503196c2296449a52b6f7995d4a647f5">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::lhs</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#adfe5734554daf4e5793f0708f3121284">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::rhs</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Operators

### operator bool() {#a854f1034410a13b6d2673beec610604a}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::operator bool ()</td>
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

<p>Conversion operator to boolean.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The result of the comparison.</p></dd>
</dl>


<p>Returns the pre-computed boolean result stored by the derived comparator's constructor.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l00243">243</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h/#l00149">149</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h">detail-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">149</span><span class="doxyLineContent"><span class="doxyHighlight">    operator bool ()</span><span class="doxyHighlightKeyword"> const</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">150</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">    </span><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">151</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a2dd578daf62dde786b3e9e7beeac08bc">value_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">152</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a9ba8011f48a2cb4e7ff928298594005a">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::binary_op_</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a2dd578daf62dde786b3e9e7beeac08bc">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::value_</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Member Functions

### lhs() {#a503196c2296449a52b6f7995d4a647f5}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::lhs (void)</td>
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

<p>Retrieves the left-hand operand.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The extracted left-hand operand.</p></dd>
</dl>


<p>Returns the value of the left-hand operand, applying the generic getter to ensure correct extraction for both custom and standard types.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l00253">253</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h/#l00162">162</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h">detail-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a503196c2296449a52b6f7995d4a647f5">162</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a503196c2296449a52b6f7995d4a647f5">binary_op_&lt;Lhs_T, Rhs_T&gt;::lhs</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span><span class="doxyHighlightKeyword"> const</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">163</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">    </span><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">164</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac627271520bf2fe8a4c4774bcd9bf343">get</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#ac3bcfee808c65ee0d6be74d564cbf58c">lhs_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">165</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac627271520bf2fe8a4c4774bcd9bf343">micro_os_plus::micro_test_plus::detail::get</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#ac3bcfee808c65ee0d6be74d564cbf58c">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::lhs_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/and-/#acbcbff7fd569478a832ad3b18e94164f">micro_os_plus::micro_test_plus::detail::and_&lt; Lhs_T, Rhs_T &gt;::and_</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a9ba8011f48a2cb4e7ff928298594005a">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::binary_op_</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/eq-/#a527ae62e9ed62a3ebbc3efd243d602c3">micro_os_plus::micro_test_plus::detail::eq_&lt; Lhs_T, Rhs_T &gt;::eq_</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/ge-/#a75e4626f1ff8024c4d90ab3e545be62f">micro_os_plus::micro_test_plus::detail::ge_&lt; Lhs_T, Rhs_T &gt;::ge_</a>, <a href="#a0d3eb79b0fd8cd986a18ac77abb98192">micro_os_plus::micro_test_plus::detail::gt_&lt; Lhs_T, Rhs_T &gt;::gt_</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/le-/#a960d02b3adb732c12ddec1a3203c4a12">micro_os_plus::micro_test_plus::detail::le_&lt; Lhs_T, Rhs_T &gt;::le_</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/lt-/#ad710000ff9a19e330f1fb33fdb236696">micro_os_plus::micro_test_plus::detail::lt_&lt; Lhs_T, Rhs_T &gt;::lt_</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/ne-/#a6119b4adca8baf81aad4e2543b8902bc">micro_os_plus::micro_test_plus::detail::ne_&lt; Lhs_T, Rhs_T &gt;::ne_</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/or-/#ae023677ab7963bcd4302604292ec9871">micro_os_plus::micro_test_plus::detail::or_&lt; Lhs_T, Rhs_T &gt;::or_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#ae0eb957767a54644f4930e34027a362e">micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a49ea3643cc64e40ba7af178c0dcec7c8">micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#af9ac0ed027dc118daf43df623e7a6ad0">micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a0a9cc0662059203d266ac2fc8a0150bb">micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a8c1dff1037e52f38ba4bdd02b45a4a51">micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a162bb0f550fdbc2cf37bbc26b941c5d9">micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#adbd36b68734e55206edbdf9478dd2118">micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt;</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a87d4ae11bdf27d064c45d9dd12a94cea">micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt;</a>.</p>

</div>
</div>

### rhs() {#adfe5734554daf4e5793f0708f3121284}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::rhs (void)</td>
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

<p>Retrieves the right-hand operand.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The extracted right-hand operand.</p></dd>
</dl>


<p>Returns the value of the right-hand operand, applying the generic getter to ensure correct extraction for both custom and standard types.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l00263">263</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h/#l00175">175</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h">detail-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#adfe5734554daf4e5793f0708f3121284">175</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#adfe5734554daf4e5793f0708f3121284">binary_op_&lt;Lhs_T, Rhs_T&gt;::rhs</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span><span class="doxyHighlightKeyword"> const</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">176</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">    </span><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">177</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac627271520bf2fe8a4c4774bcd9bf343">get</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#ab6217372c20998ca75fe5e7a73754d7c">rhs_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">178</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac627271520bf2fe8a4c4774bcd9bf343">micro_os_plus::micro_test_plus::detail::get</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#ab6217372c20998ca75fe5e7a73754d7c">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::rhs_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/and-/#acbcbff7fd569478a832ad3b18e94164f">micro_os_plus::micro_test_plus::detail::and_&lt; Lhs_T, Rhs_T &gt;::and_</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a9ba8011f48a2cb4e7ff928298594005a">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::binary_op_</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/eq-/#a527ae62e9ed62a3ebbc3efd243d602c3">micro_os_plus::micro_test_plus::detail::eq_&lt; Lhs_T, Rhs_T &gt;::eq_</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/ge-/#a75e4626f1ff8024c4d90ab3e545be62f">micro_os_plus::micro_test_plus::detail::ge_&lt; Lhs_T, Rhs_T &gt;::ge_</a>, <a href="#a0d3eb79b0fd8cd986a18ac77abb98192">micro_os_plus::micro_test_plus::detail::gt_&lt; Lhs_T, Rhs_T &gt;::gt_</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/le-/#a960d02b3adb732c12ddec1a3203c4a12">micro_os_plus::micro_test_plus::detail::le_&lt; Lhs_T, Rhs_T &gt;::le_</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/lt-/#ad710000ff9a19e330f1fb33fdb236696">micro_os_plus::micro_test_plus::detail::lt_&lt; Lhs_T, Rhs_T &gt;::lt_</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/ne-/#a6119b4adca8baf81aad4e2543b8902bc">micro_os_plus::micro_test_plus::detail::ne_&lt; Lhs_T, Rhs_T &gt;::ne_</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/or-/#ae023677ab7963bcd4302604292ec9871">micro_os_plus::micro_test_plus::detail::or_&lt; Lhs_T, Rhs_T &gt;::or_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#ae0eb957767a54644f4930e34027a362e">micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a49ea3643cc64e40ba7af178c0dcec7c8">micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#af9ac0ed027dc118daf43df623e7a6ad0">micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a0a9cc0662059203d266ac2fc8a0150bb">micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a8c1dff1037e52f38ba4bdd02b45a4a51">micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a162bb0f550fdbc2cf37bbc26b941c5d9">micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#adbd36b68734e55206edbdf9478dd2118">micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt;</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a87d4ae11bdf27d064c45d9dd12a94cea">micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt;</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Private Member Attributes

### lhs\_ {#ac3bcfee808c65ee0d6be74d564cbf58c}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const Lhs_T micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::lhs_ {}</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Stores the left-hand operand.</p>



:::info
<p>Operands are stored by value; passing a large container will copy it into this member.</p>
:::


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l00272">272</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#ac3bcfee808c65ee0d6be74d564cbf58c">272</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Lhs_T <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#ac3bcfee808c65ee0d6be74d564cbf58c">lhs_</a>{};</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a9ba8011f48a2cb4e7ff928298594005a">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::binary_op_</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a503196c2296449a52b6f7995d4a647f5">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::lhs</a>.</p>

</div>
</div>

### rhs\_ {#ab6217372c20998ca75fe5e7a73754d7c}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const Rhs_T micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::rhs_ {}</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Stores the right-hand operand.</p>



:::info
<p>Operands are stored by value; passing a large container will copy it into this member.</p>
:::


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l00280">280</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#ab6217372c20998ca75fe5e7a73754d7c">280</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Rhs_T <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#ab6217372c20998ca75fe5e7a73754d7c">rhs_</a>{};</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a9ba8011f48a2cb4e7ff928298594005a">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::binary_op_</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#adfe5734554daf4e5793f0708f3121284">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::rhs</a>.</p>

</div>
</div>

### value\_ {#a2dd578daf62dde786b3e9e7beeac08bc}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const bool micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::value_ {}</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Stores the result of the comparison.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l00285">285</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a2dd578daf62dde786b3e9e7beeac08bc">285</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a2dd578daf62dde786b3e9e7beeac08bc">value_</a>{};</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a9ba8011f48a2cb4e7ff928298594005a">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::binary_op_</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a854f1034410a13b6d2673beec610604a">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::operator bool</a>.</p>

</div>
</div>

</div>

<hr/>

The documentation for this struct was generated from the following files:

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h">detail-inlines.h</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.1 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
