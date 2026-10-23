---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/classes/micro-os-plus/micro-test-plus/detail/callable-ref
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - class

---

<div class="doxyPage">

# `callable_ref` Class Template

<p>Non-owning reference to a callable invoked with a <span class="doxyComputerOutput">Self_T&amp;</span> argument. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
template &lt;typename Self_T&gt;<br/>
class micro_os_plus::micro_test_plus::detail::callable_ref&lt;Self_T&gt; { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>"
</div>

## Public Constructors Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;typename Callable_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemNoTypeNameTemplate" colspan="2" align="left" valign="top"><a href="#a3e789d4fded524d5d5d088618d615026">callable_ref</a> (Callable_T &amp;callable) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructs a reference to a callable. <a href="#a3e789d4fded524d5d5d088618d615026">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Operators Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;typename Self_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a10148eb90e3393d8166e8712468d32e2">operator()</a> (Self_T &amp;self) const</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Invokes the referred callable. <a href="#a10148eb90e3393d8166e8712468d32e2">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Private Member Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;typename Self_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">void *</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a7a5a1b1e001f34f819ac65e63c2d9567">callable_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The address of the referred callable. <a href="#a7a5a1b1e001f34f819ac65e63c2d9567">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;typename Self_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">void(*)</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a7ca4453fe089a72345a476490212ae59">invoke_</a>(void *callable, Self_T &self)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The function that invokes the referred callable. <a href="#a7ca4453fe089a72345a476490212ae59">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Private Static Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;typename Callable_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">static void</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#affde2e2f927df6b5ada7f5578f8d5c36">invoke_callable</a> (void *callable, Self_T &amp;self)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Invokes a callable of a given type, from its address. <a href="#affde2e2f927df6b5ada7f5578f8d5c36">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Non-owning reference to a callable invoked with a <span class="doxyComputerOutput">Self_T&amp;</span> argument.</p>


<p>Holds the address of the callable and a pointer to a function, instantiated for its type, which converts the address back and invokes the callable. Unlike a <span class="doxyComputerOutput">std::function</span>, it neither copies the callable nor allocates memory, so the callable must outlive the reference.</p>


<p>A test case refers to its body this way, since the body is a local object of <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#ad4ac49522cfd6e1608d9ac64ab7a8b91">runnable_base::create_test_case()</a></span>, which runs the test case and destroys it before returning.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Self_T</td>
<td class="doxyParamItemDescription"><p>The type referred to by the argument of the callable (<span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a></span>).</p></td>
</tr>
</table>
</dd>
</dl>

<p>Definition at line 836 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<div class="doxySectionDef">

## Public Constructors

### callable\_ref() {#a3e789d4fded524d5d5d088618d615026}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;typename Callable_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::callable_ref&lt; Self_T &gt;::callable_ref (Callable_T &amp; callable)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel explicit">explicit</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Constructs a reference to a callable.</p>


<p>The callable must be invocable with a <span class="doxyComputerOutput">Self_T&amp;</span> argument, and must outlive the reference.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Callable_T</td>
<td class="doxyParamItemDescription"><p>The type of the callable object.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Constraints</dt>
<dd><p><span class="doxyComputerOutput">Callable_T</span> is not a <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref">callable_ref</a></span>, so that the copy constructor is used for copies.</p></dd>
</dl>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">callable</td>
<td class="doxyParamItemDescription"><p>The callable object; a non-<span class="doxyComputerOutput">const</span> lvalue.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Stores the address of the callable, and the address of the <span class="doxyComputerOutput"><a href="#affde2e2f927df6b5ada7f5578f8d5c36">invoke_callable()</a></span> instantiation for its type.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00857">857</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00329">329</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a3e789d4fded524d5d5d088618d615026">329</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a3e789d4fded524d5d5d088618d615026">callable_ref&lt;Self_T&gt;::callable_ref</a> (Callable_T&amp; callable) noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">330</span><span class="doxyLineContent"><span class="doxyHighlight">        : <a href="#a7a5a1b1e001f34f819ac65e63c2d9567">callable_</a>{ std::addressof (callable) },</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">331</span><span class="doxyLineContent"><span class="doxyHighlight">          invoke_{ &amp;invoke_callable&lt;Callable_T&gt; }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">332</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">333</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="#a3e789d4fded524d5d5d088618d615026">micro_os_plus::micro_test_plus::detail::callable_ref&lt; Self_T &gt;::callable_ref</a> and <a href="#a7a5a1b1e001f34f819ac65e63c2d9567">micro_os_plus::micro_test_plus::detail::callable_ref&lt; Self_T &gt;::callable_</a>.</p>


<p>Referenced by <a href="#a3e789d4fded524d5d5d088618d615026">micro_os_plus::micro_test_plus::detail::callable_ref&lt; Self_T &gt;::callable_ref</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Operators

### operator()() {#a10148eb90e3393d8166e8712468d32e2}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;typename Self_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::callable_ref&lt; Self_T &gt;::operator() (Self_T &amp; self)</td>
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

<p>Invokes the referred callable.</p>


<p>Not <span class="doxyComputerOutput">noexcept</span>, since a failed <span class="doxyComputerOutput">require()</span> stops the body of a test case by throwing an exception.</p>


<p>Always inlined, so that, without optimisations, it adds no frame between <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#adb4333ecb107fee477156b661f0b1512">test_case::run()</a></span> and <span class="doxyComputerOutput"><a href="#affde2e2f927df6b5ada7f5578f8d5c36">invoke_callable()</a></span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">self</td>
<td class="doxyParamItemDescription"><p>The reference passed to the callable.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Passes the stored address and <span class="doxyComputerOutput">self</span> to the stored function.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00874">874</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00341">341</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a10148eb90e3393d8166e8712468d32e2">341</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a10148eb90e3393d8166e8712468d32e2">callable_ref&lt;Self_T&gt;::operator()</a>(Self_T&amp; self)</span><span class="doxyHighlightKeyword"> const</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">342</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">    </span><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">343</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="#a7ca4453fe089a72345a476490212ae59">invoke_</a> (<a href="#a7a5a1b1e001f34f819ac65e63c2d9567">callable_</a>, self);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">344</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="#a7a5a1b1e001f34f819ac65e63c2d9567">micro_os_plus::micro_test_plus::detail::callable_ref&lt; Self_T &gt;::callable_</a> and <a href="#a7ca4453fe089a72345a476490212ae59">micro_os_plus::micro_test_plus::detail::callable_ref&lt; Self_T &gt;::invoke_</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Private Member Attributes

### callable\_ {#a7a5a1b1e001f34f819ac65e63c2d9567}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;typename Self_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void* micro_os_plus::micro_test_plus::detail::callable_ref&lt; Self_T &gt;::callable_</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The address of the referred callable.</p>


<p>Its type is erased; only <span class="doxyComputerOutput"><a href="#a7ca4453fe089a72345a476490212ae59">invoke_</a></span> converts it back.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00901">901</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a7a5a1b1e001f34f819ac65e63c2d9567">901</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">* <a href="#a7a5a1b1e001f34f819ac65e63c2d9567">callable_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#a3e789d4fded524d5d5d088618d615026">micro_os_plus::micro_test_plus::detail::callable_ref&lt; Self_T &gt;::callable_ref</a> and <a href="#a10148eb90e3393d8166e8712468d32e2">micro_os_plus::micro_test_plus::detail::callable_ref&lt; Self_T &gt;::operator()</a>.</p>

</div>
</div>

### invoke\_ {#a7ca4453fe089a72345a476490212ae59}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;typename Self_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void(*) micro_os_plus::micro_test_plus::detail::callable_ref&lt; Self_T &gt;::invoke_(void *callable, Self_T &amp;self)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The function that invokes the referred callable.</p>


<p>The <span class="doxyComputerOutput"><a href="#affde2e2f927df6b5ada7f5578f8d5c36">invoke_callable()</a></span> instantiation for the type of the callable; it receives <span class="doxyComputerOutput"><a href="#a7a5a1b1e001f34f819ac65e63c2d9567">callable_</a></span> and the <span class="doxyComputerOutput">Self_T&amp;</span> argument.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00910">910</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a7ca4453fe089a72345a476490212ae59">910</a></span><span class="doxyLineContent"><span class="doxyHighlight">      void (*<a href="#a7ca4453fe089a72345a476490212ae59">invoke_</a>) (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">* callable, Self_T&amp; self);</span></span></div>

</div>


<p>Referenced by <a href="#a10148eb90e3393d8166e8712468d32e2">micro_os_plus::micro_test_plus::detail::callable_ref&lt; Self_T &gt;::operator()</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Private Static Functions

### invoke\_callable() {#affde2e2f927df6b5ada7f5578f8d5c36}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;typename Callable_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::callable_ref&lt; Self_T &gt;::invoke_callable (void * callable, Self_T &amp; self)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel static">static</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Invokes a callable of a given type, from its address.</p>


<p>Instantiated by the constructor for the type of the callable; its address is stored in <span class="doxyComputerOutput"><a href="#a7ca4453fe089a72345a476490212ae59">invoke_</a></span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Callable_T</td>
<td class="doxyParamItemDescription"><p>The type of the callable object.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">callable</td>
<td class="doxyParamItemDescription"><p>The address of the callable, with its type erased.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">self</td>
<td class="doxyParamItemDescription"><p>The reference passed to the callable.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Casts <span class="doxyComputerOutput">callable</span> back to <span class="doxyComputerOutput">Callable_T*</span>, the type it had when the reference was constructed, and invokes the callable through it, as an lvalue, with <span class="doxyComputerOutput">self</span>.</p>


<p>A function pointer or a function object is called directly, not through <span class="doxyComputerOutput">std::invoke()</span>, which, without optimisations, adds three frames to the call chain; a pointer to a member, which only <span class="doxyComputerOutput">std::invoke()</span> can call, is still passed to it.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00893">893</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00360">360</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#affde2e2f927df6b5ada7f5578f8d5c36">360</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#affde2e2f927df6b5ada7f5578f8d5c36">callable_ref&lt;Self_T&gt;::invoke_callable</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">* callable, Self_T&amp; self)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">361</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">362</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> (std::is_member_pointer_v&lt;Callable_T&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">363</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">364</span><span class="doxyLineContent"><span class="doxyHighlight">          std::invoke (*</span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">Callable_T*</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (callable), self);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">365</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">366</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">367</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">368</span><span class="doxyLineContent"><span class="doxyHighlight">          (*</span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">Callable_T*</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (callable)) (self);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">369</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">370</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>

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

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
