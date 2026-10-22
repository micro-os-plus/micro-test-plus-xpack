---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/classes/micro-os-plus/micro-test-plus/detail/bound-callable
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - class

---

<div class="doxyPage">

# `bound_callable` Class Template

<p>Function object that holds a callable and the additional arguments it is invoked with. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
template &lt;typename Self_T, typename Callable_T, typename... Args_T&gt;<br/>
class micro_os_plus::micro_test_plus::detail::bound_callable&lt;Self_T, Callable_T, Args_T&gt; { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>"
</div>

## Public Constructors Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;typename C, typename... A&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#aa9be536ae51bc405cb4fb0d8f015ebfc">bound_callable</a> (C &amp;&amp;callable, A &amp;&amp;... arguments)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructs the function object from a callable and the arguments. <a href="#aa9be536ae51bc405cb4fb0d8f015ebfc">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Operators Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;typename Self_T, typename Callable_T, typename... Args_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a65c86f89bf9e216b5e2e3dae5f599a49">operator()</a> (Self_T &amp;self)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Invokes the stored callable. <a href="#a65c86f89bf9e216b5e2e3dae5f599a49">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Private Member Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;std::size_t... Is&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#aa0583b5d4d54c56f1460c18e88e43aa2">invoke</a> (Self_T &amp;self, std::index_sequence&lt; Is... &gt;)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Invokes the stored callable with the stored arguments, unpacked by their indices. <a href="#aa0583b5d4d54c56f1460c18e88e43aa2">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Private Member Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;typename Self_T, typename Callable_T, typename... Args_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">std::tuple&lt; Args_T... &gt;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a674485f271757aa111f6cbf39bfa12f8">arguments_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The stored arguments. <a href="#a674485f271757aa111f6cbf39bfa12f8">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;typename Self_T, typename Callable_T, typename... Args_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">Callable_T</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ae9058f5a50afba3eafc6b86d68957fdb">callable_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The stored callable. <a href="#ae9058f5a50afba3eafc6b86d68957fdb">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Function object that holds a callable and the additional arguments it is invoked with.</p>


<p>Returned by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a6abb44ef8226b1f80aad8010b5ef1a5c">bind_callable()</a></span> when there are additional arguments. When invoked with a <span class="doxyComputerOutput">Self_T&amp;</span> reference, it invokes the stored callable with that reference, followed by the stored arguments, as non-<span class="doxyComputerOutput">const</span> lvalues.</p>


<p>It replaces a lambda, since the function call operator of a lambda cannot be marked as always inlined in a way accepted by all the supported compilers; without optimisations, a separate frame for it would make the call chain of each nested test case longer.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Self_T</td>
<td class="doxyParamItemDescription"><p>The type referred to by the first parameter of the callable (<span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a></span> or <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a></span>).</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Callable_T</td>
<td class="doxyParamItemDescription"><p>The type of the stored callable (decayed).</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Args_T</td>
<td class="doxyParamItemDescription"><p>The types of the stored arguments (decayed).</p></td>
</tr>
</table>
</dd>
</dl>

<p>Definition at line 733 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<div class="doxySectionDef">

## Public Constructors

### bound\_callable() {#aa9be536ae51bc405cb4fb0d8f015ebfc}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;typename C, typename... A&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::bound_callable&lt; Self_T, Callable_T, Args_T &gt;::bound_callable (C &amp;&amp; callable, A &amp;&amp;... arguments)</td>
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

<p>Constructs the function object from a callable and the arguments.</p>


<p>Copies (or moves) the callable and the arguments into the object.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">C</td>
<td class="doxyParamItemDescription"><p>The type of the callable, as passed.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">A</td>
<td class="doxyParamItemDescription"><p>The types of the arguments, as passed.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Constraints</dt>
<dd><p>One argument for each stored argument, so that the copy and move constructors are used for copies (there is always at least one stored argument).</p></dd>
</dl>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">callable</td>
<td class="doxyParamItemDescription"><p>The callable object.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">arguments</td>
<td class="doxyParamItemDescription"><p>The arguments passed to the callable after the leading reference.</p></td>
</tr>
</table>
</dd>
</dl>

<p>The callable and the arguments are forwarded to the constructors of the members, which store decayed copies.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00757">757</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00276">276</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aa9be536ae51bc405cb4fb0d8f015ebfc">276</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> <a href="#aa9be536ae51bc405cb4fb0d8f015ebfc">bound_callable&lt;Self_T, Callable_T, Args_T...&gt;::bound_callable</a> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">277</span><span class="doxyLineContent"><span class="doxyHighlight">        C&amp;&amp; callable, A&amp;&amp;... arguments)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">278</span><span class="doxyLineContent"><span class="doxyHighlight">        : <a href="#ae9058f5a50afba3eafc6b86d68957fdb">callable_</a> (std::forward&lt;C&gt; (callable)),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">279</span><span class="doxyLineContent"><span class="doxyHighlight">          <a href="#a674485f271757aa111f6cbf39bfa12f8">arguments_</a> (std::forward&lt;A&gt; (arguments)...)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">280</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">281</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="#aa9be536ae51bc405cb4fb0d8f015ebfc">micro_os_plus::micro_test_plus::detail::bound_callable&lt; Self_T, Callable_T, Args_T &gt;::bound_callable</a>, <a href="#a674485f271757aa111f6cbf39bfa12f8">micro_os_plus::micro_test_plus::detail::bound_callable&lt; Self_T, Callable_T, Args_T &gt;::arguments_</a> and <a href="#ae9058f5a50afba3eafc6b86d68957fdb">micro_os_plus::micro_test_plus::detail::bound_callable&lt; Self_T, Callable_T, Args_T &gt;::callable_</a>.</p>


<p>Referenced by <a href="#aa9be536ae51bc405cb4fb0d8f015ebfc">micro_os_plus::micro_test_plus::detail::bound_callable&lt; Self_T, Callable_T, Args_T &gt;::bound_callable</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Operators

### operator()() {#a65c86f89bf9e216b5e2e3dae5f599a49}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;typename Self_T, typename Callable_T, typename... Args_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::bound_callable&lt; Self_T, Callable_T, Args_T &gt;::operator() (Self_T &amp; self)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Invokes the stored callable.</p>


<p>Always inlined, so that, without optimisations, it adds no frame between <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref/#affde2e2f927df6b5ada7f5578f8d5c36">callable_ref::invoke_callable()</a></span> and the callable.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">self</td>
<td class="doxyParamItemDescription"><p>The reference passed as the first argument.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Unpacks the stored arguments by their indices.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00771">771</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00289">289</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a65c86f89bf9e216b5e2e3dae5f599a49">289</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a65c86f89bf9e216b5e2e3dae5f599a49">bound_callable&lt;Self_T, Callable_T, Args_T...&gt;::operator()</a>(Self_T&amp; self)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">290</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">291</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="#aa0583b5d4d54c56f1460c18e88e43aa2">invoke</a> (self, std::index_sequence_for&lt;Args_T...&gt;{});</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">292</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="#aa0583b5d4d54c56f1460c18e88e43aa2">micro_os_plus::micro_test_plus::detail::bound_callable&lt; Self_T, Callable_T, Args_T &gt;::invoke</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Private Member Functions

### invoke() {#aa0583b5d4d54c56f1460c18e88e43aa2}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;std::size_t... Is&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::bound_callable&lt; Self_T, Callable_T, Args_T &gt;::invoke (Self_T &amp; self, std::index_sequence&lt; Is... &gt;)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Invokes the stored callable with the stored arguments, unpacked by their indices.</p>


<p>Always inlined, as the function call operator.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Is</td>
<td class="doxyParamItemDescription"><p>The indices of the stored arguments.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">self</td>
<td class="doxyParamItemDescription"><p>The reference passed as the first argument.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>A function, a function pointer, or a function object is called directly, not through <span class="doxyComputerOutput">std::invoke()</span>, which, without optimisations, adds three frames to the call chain; a pointer to a member, which only <span class="doxyComputerOutput">std::invoke()</span> can call, is still passed to it.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00789">789</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00305">305</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aa0583b5d4d54c56f1460c18e88e43aa2">305</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#aa0583b5d4d54c56f1460c18e88e43aa2">bound_callable&lt;Self_T, Callable_T, Args_T...&gt;::invoke</a> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">306</span><span class="doxyLineContent"><span class="doxyHighlight">        Self_T&amp; self, std::index_sequence&lt;Is...&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">307</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">308</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> (std::is_member_pointer_v&lt;Callable_T&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">309</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">310</span><span class="doxyLineContent"><span class="doxyHighlight">          std::invoke (<a href="#ae9058f5a50afba3eafc6b86d68957fdb">callable_</a>, self, std::get&lt;Is&gt; (<a href="#a674485f271757aa111f6cbf39bfa12f8">arguments_</a>)...);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">311</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">312</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">313</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">314</span><span class="doxyLineContent"><span class="doxyHighlight">          <a href="#ae9058f5a50afba3eafc6b86d68957fdb">callable_</a> (self, std::get&lt;Is&gt; (<a href="#a674485f271757aa111f6cbf39bfa12f8">arguments_</a>)...);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">315</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">316</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="#a674485f271757aa111f6cbf39bfa12f8">micro_os_plus::micro_test_plus::detail::bound_callable&lt; Self_T, Callable_T, Args_T &gt;::arguments_</a> and <a href="#ae9058f5a50afba3eafc6b86d68957fdb">micro_os_plus::micro_test_plus::detail::bound_callable&lt; Self_T, Callable_T, Args_T &gt;::callable_</a>.</p>


<p>Referenced by <a href="#a65c86f89bf9e216b5e2e3dae5f599a49">micro_os_plus::micro_test_plus::detail::bound_callable&lt; Self_T, Callable_T, Args_T &gt;::operator()</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Private Member Attributes

### arguments\_ {#a674485f271757aa111f6cbf39bfa12f8}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;typename Self_T, typename Callable_T, typename... Args_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::tuple&lt;Args_T...&gt; micro_os_plus::micro_test_plus::detail::bound_callable&lt; Self_T, Callable_T, Args_T &gt;::arguments_</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The stored arguments.</p>


<p>Copies of the arguments passed to <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a6abb44ef8226b1f80aad8010b5ef1a5c">bind_callable()</a></span>, decayed; a reference parameter of the callable refers to the copy.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00807">807</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a674485f271757aa111f6cbf39bfa12f8">807</a></span><span class="doxyLineContent"><span class="doxyHighlight">      std::tuple&lt;Args_T...&gt; <a href="#a674485f271757aa111f6cbf39bfa12f8">arguments_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#aa9be536ae51bc405cb4fb0d8f015ebfc">micro_os_plus::micro_test_plus::detail::bound_callable&lt; Self_T, Callable_T, Args_T &gt;::bound_callable</a> and <a href="#aa0583b5d4d54c56f1460c18e88e43aa2">micro_os_plus::micro_test_plus::detail::bound_callable&lt; Self_T, Callable_T, Args_T &gt;::invoke</a>.</p>

</div>
</div>

### callable\_ {#ae9058f5a50afba3eafc6b86d68957fdb}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;typename Self_T, typename Callable_T, typename... Args_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">Callable_T micro_os_plus::micro_test_plus::detail::bound_callable&lt; Self_T, Callable_T, Args_T &gt;::callable_</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The stored callable.</p>


<p>A copy of the callable passed to <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a6abb44ef8226b1f80aad8010b5ef1a5c">bind_callable()</a></span>, decayed, so a function is stored as a pointer.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00798">798</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ae9058f5a50afba3eafc6b86d68957fdb">798</a></span><span class="doxyLineContent"><span class="doxyHighlight">      Callable_T <a href="#ae9058f5a50afba3eafc6b86d68957fdb">callable_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#aa9be536ae51bc405cb4fb0d8f015ebfc">micro_os_plus::micro_test_plus::detail::bound_callable&lt; Self_T, Callable_T, Args_T &gt;::bound_callable</a> and <a href="#aa0583b5d4d54c56f1460c18e88e43aa2">micro_os_plus::micro_test_plus::detail::bound_callable&lt; Self_T, Callable_T, Args_T &gt;::invoke</a>.</p>

</div>
</div>

</div>

<hr/>

The documentation for this class was generated from the following files:

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.4 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
