---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-os-plus-micro-test-plus-cpp-api-exceptions
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# Checking exceptions

<p>Functions for verifying exceptions in test cases. <a href="#details">More...</a></p>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Callable_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ga2989618cf5adca7a767c966895ab37a0">nothrow</a> (Callable_T &amp;&amp;func)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Checks whether a callable does not throw any exception, for <span class="doxyComputerOutput">expect()</span> or <span class="doxyComputerOutput">require()</span>. <a href="#ga2989618cf5adca7a767c966895ab37a0">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Callable_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ga8fdcab2fe2567f6d6a735e89b936298d">throws</a> (Callable_T &amp;&amp;func)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Checks whether a callable throws any exception, for <span class="doxyComputerOutput">expect()</span> or <span class="doxyComputerOutput">require()</span>. <a href="#ga8fdcab2fe2567f6d6a735e89b936298d">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Exception_T, class Callable_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ga6a0ca4f8b757ea511c494189212812b3">throws</a> (Callable_T &amp;&amp;func)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Checks whether a callable throws a specific exception, for <span class="doxyComputerOutput">expect()</span> or <span class="doxyComputerOutput">require()</span>. <a href="#ga6a0ca4f8b757ea511c494189212812b3">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Functions for verifying exceptions in test cases.</p>


<p>Three functions check what a callable throws, and are used as the conditions of <span class="doxyComputerOutput">expect()</span> or <span class="doxyComputerOutput">require()</span>:</p>


<ul class="doxyList ">
<li><span class="doxyComputerOutput">mt::throws (callable)</span> is true when the callable throws any exception;</li>
<li><span class="doxyComputerOutput">mt::throws&lt;E&gt; (callable)</span> is true when it throws an exception of type <span class="doxyComputerOutput">E</span>, or of a type derived from it;</li>
<li><span class="doxyComputerOutput">mt::nothrow (callable)</span> is true when it throws nothing.</li>
</ul>

<p>The exception is caught by the check, so it does not leave the test case. When the check fails, the report states why, for example:</p>


<ul class="doxyList ">
<li><span class="doxyComputerOutput">throws&lt;std::runtime_error&gt;, but nothing was thrown</span>;</li>
<li><span class="doxyComputerOutput">throws&lt;std::runtime_error&gt;, but a std::exception was thrown: "what"</span>, with the text returned by its <span class="doxyComputerOutput">what()</span>;</li>
<li><span class="doxyComputerOutput">nothrow, but an exception of unknown type was thrown</span>.</li>
</ul>

<p>A failed <span class="doxyComputerOutput">require()</span> inside the callable is not an exception of the callable: it stops the test case, as it does elsewhere, and does not satisfy <span class="doxyComputerOutput">throws()</span> or fail <span class="doxyComputerOutput">nothrow()</span>.</p>


<dl class="doxySectionUser">
<dt>Example</dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ts.test (</span><span class="doxyHighlightStringLiteral">"Check if exceptions are thrown"</span><span class="doxyHighlight">, [] (</span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; t) {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  t.expect (mt::throws ([] { exercise_throw (</span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">); }))</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">      &lt;&lt; </span><span class="doxyHighlightStringLiteral">"exception thrown"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  t.expect (mt::throws&lt;std::runtime_error&gt; ([]</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    { </span><span class="doxyHighlightKeywordFlow">throw</span><span class="doxyHighlight"> std::runtime_error{ </span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"> }; }))</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">      &lt;&lt; </span><span class="doxyHighlightStringLiteral">"std::runtime_error thrown"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  t.expect (mt::nothrow ([] { exercise_throw (</span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">); }))</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">      &lt;&lt; </span><span class="doxyHighlightStringLiteral">"exception not thrown"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">});</span></span></div>

</div>


<dl class="doxySectionUser">
<dt>Availability</dt>
<dd><p>The functions are declared only when the compiler defines <span class="doxyComputerOutput">__cpp_exceptions</span>. In a build without exceptions (for example with <span class="doxyComputerOutput">-fno-exceptions</span>), the code under test cannot throw, the functions do not exist, and a test case that calls them does not compile; guard such test cases with <span class="doxyComputerOutput">#if defined(__cpp_exceptions)</span>.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Several exception types</dt>
<dd><p>To accept one of several exception types, use a <span class="doxyComputerOutput">try</span> block with a <span class="doxyComputerOutput">catch</span> for each type, and report each outcome with <span class="doxyComputerOutput">expect (true)</span> or <span class="doxyComputerOutput">expect (false)</span>. Check the normal path too, after the call in the <span class="doxyComputerOutput">try</span> block; otherwise a call that throws nothing passes with no check:</p></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ts.test (</span><span class="doxyHighlightStringLiteral">"Check exceptions explicitly"</span><span class="doxyHighlight">, [] (</span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; t) {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordFlow">try</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">      compute_answer ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">      t.expect (</span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"no exception thrown"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordFlow">catch</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::overflow_error&amp; e)</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">      t.expect (</span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"std::overflow_error thrown"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordFlow">catch</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::runtime_error&amp; e)</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">      t.expect (</span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"std::runtime_error thrown"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordFlow">catch</span><span class="doxyHighlight"> (...)</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">      t.expect (</span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"unknown exception thrown"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">});</span></span></div>

</div>


<div class="doxySectionDef">

## Functions

### nothrow() {#ga2989618cf5adca7a767c966895ab37a0}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Callable_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::nothrow (Callable_T &amp;&amp; func)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel nodiscard">nodiscard</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Checks whether a callable does not throw any exception, for <span class="doxyComputerOutput">expect()</span> or <span class="doxyComputerOutput">require()</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Callable_T</td>
<td class="doxyParamItemDescription"><p>The type of the callable object to be invoked; it must be invocable without arguments, as an lvalue, so a <span class="doxyComputerOutput">mutable</span> lambda is accepted.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">func</td>
<td class="doxyParamItemDescription"><p>The callable object to check.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>An object of an unspecified type, holding the result, to be passed to <span class="doxyComputerOutput">expect()</span> or <span class="doxyComputerOutput">require()</span>.</p></dd>
</dl>


<p>The <span class="doxyComputerOutput"><a href="#ga2989618cf5adca7a767c966895ab37a0">nothrow</a></span> function template verifies whether invoking the provided callable object does not result in the throwing of any exception within the µTest++ framework. This is useful for ensuring that code under test does not unexpectedly signal error conditions.</p>


<p>The callable is invoked immediately, when the comparator is constructed; the result is reported when the comparator is passed to <span class="doxyComputerOutput">expect()</span> or <span class="doxyComputerOutput">require()</span>, which also accept optional messages.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/exceptions-inlines-h/#l00116">116</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/exceptions-inlines-h">exceptions-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga2989618cf5adca7a767c966895ab37a0">116</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ga2989618cf5adca7a767c966895ab37a0">nothrow</a> (Callable_T&amp;&amp; func)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">117</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">118</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/nothrow-op">detail::nothrow_op</a>{ func };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">119</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#ga2989618cf5adca7a767c966895ab37a0">micro_os_plus::micro_test_plus::nothrow</a>.</p>


<p>Referenced by <a href="#ga2989618cf5adca7a767c966895ab37a0">micro_os_plus::micro_test_plus::nothrow</a>.</p>

</div>
</div>

### throws() {#ga8fdcab2fe2567f6d6a735e89b936298d}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Callable_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::throws (Callable_T &amp;&amp; func)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel nodiscard">nodiscard</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Checks whether a callable throws any exception, for <span class="doxyComputerOutput">expect()</span> or <span class="doxyComputerOutput">require()</span>.</p>


<p>The callable is invoked once, immediately. The check passes if it throws an exception of any type.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Callable_T</td>
<td class="doxyParamItemDescription"><p>The type of the callable object to be invoked; it must be invocable without arguments, as an lvalue, so a <span class="doxyComputerOutput">mutable</span> lambda is accepted.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">func</td>
<td class="doxyParamItemDescription"><p>The callable object to check for exception throwing behaviour.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>An object of an unspecified type, holding the result, to be passed to <span class="doxyComputerOutput">expect()</span> or <span class="doxyComputerOutput">require()</span>.</p></dd>
</dl>


<p>The <span class="doxyComputerOutput"><a href="#ga6a0ca4f8b757ea511c494189212812b3">throws</a></span> function template verifies whether invoking the provided callable object results in the throwing of any exception within the µTest++ framework. This is useful for ensuring that code under test properly signals error conditions.</p>


<p>The callable is invoked immediately, when the comparator is constructed; the result is reported when the comparator is passed to <span class="doxyComputerOutput">expect()</span> or <span class="doxyComputerOutput">require()</span>, which also accept optional messages.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/exceptions-inlines-h/#l00097">97</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/exceptions-inlines-h">exceptions-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga8fdcab2fe2567f6d6a735e89b936298d">97</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordFlow">throws</span><span class="doxyHighlight"> (Callable_T&amp;&amp; func)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">98</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">99</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/throws-op">detail::throws_op&lt;&gt;</a>{ func };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">100</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>

</div>
</div>

### throws() {#ga6a0ca4f8b757ea511c494189212812b3}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Exception_T, class Callable_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::throws (Callable_T &amp;&amp; func)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel nodiscard">nodiscard</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Checks whether a callable throws a specific exception, for <span class="doxyComputerOutput">expect()</span> or <span class="doxyComputerOutput">require()</span>.</p>


<p>The callable is invoked once, immediately. The check passes if it throws an exception of type <span class="doxyComputerOutput">Exception_T</span> or of a type derived from it, so <span class="doxyComputerOutput"><a href="#ga6a0ca4f8b757ea511c494189212812b3">throws</a>&lt;std::exception&gt;()</span> passes for any standard exception. An exception of another type, or no exception, fails the check, and the report states what was thrown.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Exception_T</td>
<td class="doxyParamItemDescription"><p>The type of the exception expected to be thrown.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Callable_T</td>
<td class="doxyParamItemDescription"><p>The type of the callable object to be invoked; it must be invocable without arguments, as an lvalue, so a <span class="doxyComputerOutput">mutable</span> lambda is accepted.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">func</td>
<td class="doxyParamItemDescription"><p>The callable object to check for exception throwing behaviour.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>An object of an unspecified type, holding the result, to be passed to <span class="doxyComputerOutput">expect()</span> or <span class="doxyComputerOutput">require()</span>.</p></dd>
</dl>


<p>The <span class="doxyComputerOutput"><a href="#ga6a0ca4f8b757ea511c494189212812b3">throws</a></span> function template verifies whether invoking the provided callable object results in the throwing of a specific exception type within the µTest++ framework. This is useful for testing error handling in code under test. Exceptions of other types are reported as failures.</p>


<p>The callable is invoked immediately, when the comparator is constructed; the result is reported when the comparator is passed to <span class="doxyComputerOutput">expect()</span> or <span class="doxyComputerOutput">require()</span>, which also accept optional messages.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/exceptions-inlines-h/#l00078">78</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/exceptions-inlines-h">exceptions-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga6a0ca4f8b757ea511c494189212812b3">78</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordFlow">throws</span><span class="doxyHighlight"> (Callable_T&amp;&amp; func)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">79</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">80</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/throws-op">detail::throws_op&lt;Exception_T&gt;</a>{ func };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">81</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>

</div>
</div>

</div>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.7 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
