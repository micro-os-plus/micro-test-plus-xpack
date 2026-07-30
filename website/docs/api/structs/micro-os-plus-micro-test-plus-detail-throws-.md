---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/structs/micro-os-plus/micro-test-plus/detail/throws-
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - struct

---

<div class="doxyPage">

# `throws_` Struct Template

<p>Operator struct template to check if an expression throws a specific exception. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
template &lt;class Callable_T, class Exception_T = void&gt;<br/>
struct micro_os_plus::micro_test_plus::detail::throws_&lt;Callable_T, Exception_T&gt; { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>"
</div>

## Base struct

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">struct</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/callable-op-">callable_op_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Common base struct for callable-wrapping operators. <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/callable-op-/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Constructors Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Callable_T, class Exception_T = void&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ab482b144c355eb68638dc872331145e7">throws_</a> (const Callable_T &amp;func)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructs an exception checking operator for the given callable. <a href="#ab482b144c355eb68638dc872331145e7">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Operators Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Callable_T, class Exception_T = void&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/callable-op-/#adbbcb62f9976b0f2f5461d52a89caf57">operator bool</a> () const</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Conversion operator to boolean. <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/callable-op-/#adbbcb62f9976b0f2f5461d52a89caf57">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Private Member Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Callable_T, class Exception_T = void&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">const bool</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/callable-op-/#a8b7760bde30950164a3c97632b468361">value_</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Stores the result of the callable invocation. <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/callable-op-/#a8b7760bde30950164a3c97632b468361">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Operator struct template to check if an expression throws a specific exception.</p>


<p>This specialisation checks whether invoking the given callable throws an exception of the specified type. The check is performed at construction time, with the result cached for reporting and composition. Use this when a test must verify that an operation raises an expected exception of a particular type.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Callable_T</td>
<td class="doxyParamItemDescription"><p>The type of the callable object to be invoked.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Exception_T</td>
<td class="doxyParamItemDescription"><p>The type of the exception to check for (defaults to <span class="doxyComputerOutput">void</span> for any exception).</p></td>
</tr>
</table>
</dd>
</dl>

<p>Definition at line 652 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>.</p>


<div class="doxySectionDef">

## Public Constructors

### throws\_() {#ab482b144c355eb68638dc872331145e7}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Callable_T, class Exception_T = void&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::throws_&lt; Callable_T, Exception_T &gt;::throws_ (const Callable_T &amp; func)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel explicit">explicit</span>
<span class="doxyMemberLabel constexpr">constexpr</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Constructs an exception checking operator for the given callable.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">func</td>
<td class="doxyParamItemDescription"><p>The callable object to be invoked.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Invokes <span class="doxyComputerOutput">func</span> inside a try/catch block. If <span class="doxyComputerOutput">func</span> throws an exception of type <span class="doxyComputerOutput">Exception_T</span>, the result is <span class="doxyComputerOutput">true</span>; if it throws any other exception the result is <span class="doxyComputerOutput">false</span>; if no exception is thrown the result is <span class="doxyComputerOutput">false</span>. The result is passed to the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/callable-op-">callable_op_</a></span> base class constructor.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l00660">660</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h/#l00564">564</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h">detail-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ab482b144c355eb68638dc872331145e7">564</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> <a href="#ab482b144c355eb68638dc872331145e7">throws_&lt;Callable_T, Exception_T&gt;::throws_</a> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">565</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Callable_T&amp; func)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">566</span><span class="doxyLineContent"><span class="doxyHighlight">        : <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/callable-op-/#a271baf62ae8e74f4801dc3da24b575ea">callable_op_</a>{ [&amp;func]</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">567</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">568</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">try</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">569</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">570</span><span class="doxyLineContent"><span class="doxyHighlight">            func ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">571</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">572</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">catch</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Exception_T&amp;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">573</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">574</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">575</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">576</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">catch</span><span class="doxyHighlight"> (...)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">577</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">578</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">579</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">580</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">581</span><span class="doxyLineContent"><span class="doxyHighlight">      }() }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">582</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">583</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/callable-op-/#a271baf62ae8e74f4801dc3da24b575ea">micro_os_plus::micro_test_plus::detail::callable_op_::callable_op_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/throws--6ce6a9ac7588b533a253fd8d8638e6be/#a8e97e74a695e9758034855ba462c2839">micro_os_plus::micro_test_plus::detail::throws_&lt; Callable_T, void &gt;::throws_</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Operators

### operator bool() {#adbbcb62f9976b0f2f5461d52a89caf57}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Callable_T, class Exception_T = void&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::callable_op_::operator bool ()</td>
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
<dd><p>The result of the callable invocation.</p></dd>
</dl>


<p>Returns the pre-computed boolean result stored by the derived operator's constructor.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l00623">623</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h/#l00548">548</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h">detail-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">548</span><span class="doxyLineContent"><span class="doxyHighlight">    operator bool ()</span><span class="doxyHighlightKeyword"> const</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">549</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">    </span><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">550</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/callable-op-/#a8b7760bde30950164a3c97632b468361">value_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">551</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/callable-op-/#a8b7760bde30950164a3c97632b468361">micro_os_plus::micro_test_plus::detail::callable_op_::value_</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Private Member Attributes

### value\_ {#a8b7760bde30950164a3c97632b468361}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Callable_T, class Exception_T = void&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const bool micro_os_plus::micro_test_plus::detail::callable_op_::value_ {}</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Stores the result of the callable invocation.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l00629">629</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/callable-op-/#a8b7760bde30950164a3c97632b468361">629</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/callable-op-/#a8b7760bde30950164a3c97632b468361">value_</a>{};</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/callable-op-/#a271baf62ae8e74f4801dc3da24b575ea">micro_os_plus::micro_test_plus::detail::callable_op_::callable_op_</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/callable-op-/#adbbcb62f9976b0f2f5461d52a89caf57">micro_os_plus::micro_test_plus::detail::callable_op_::operator bool</a>.</p>

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

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.2 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
