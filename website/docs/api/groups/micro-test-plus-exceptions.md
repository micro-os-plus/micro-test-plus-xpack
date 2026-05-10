---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-test-plus-exceptions
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# Checking Exceptions

<p>Functions for verifying exceptions in test cases. <a href="#details">More...</a></p>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Callable_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ga798bd28001c3938784073e60dd904148">nothrow</a> (const Callable_T &amp;func)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Check if a callable does not throw an exception. <a href="#ga798bd28001c3938784073e60dd904148">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Callable_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ga8bf54756e4122c6a0bd123b4621e60e2">throws</a> (const Callable_T &amp;func)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Check if a callable throws an exception (any exception). <a href="#ga8bf54756e4122c6a0bd123b4621e60e2">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Exception_T, class Callable_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#gaf8f7602f40119da514be2a0bfc4b70f5">throws</a> (const Callable_T &amp;func)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Check if a callable throws a specific exception. <a href="#gaf8f7602f40119da514be2a0bfc4b70f5">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Functions for verifying exceptions in test cases.</p>


<p>Dedicated exception-check utilities verify whether expressions or function calls throw. These utilities support robust testing of error handling and exceptional conditions in C++ code.</p>


<p>Developers can assert that exceptions are thrown, or not thrown, as expected, improving the reliability and safety of software components. The framework supports both generic checks and type-specific verification, allowing precise and expressive test cases.</p>


<p>For advanced scenarios, such as handling multiple expected exception types, use explicit <span class="doxyComputerOutput">try</span> blocks with multiple <span class="doxyComputerOutput">catch</span> statements and report results with <span class="doxyComputerOutput">expect(true)</span> or <span class="doxyComputerOutput">expect(false)</span>. This approach enables comprehensive coverage of exception-handling logic.</p>


<dl class="doxySectionUser">
<dt>Examples</dt>
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


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ts.test (</span><span class="doxyHighlightStringLiteral">"Check exceptions explicitly"</span><span class="doxyHighlight">, [] (</span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; t) {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordFlow">try</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">      compute_answer ();</span></span></div>
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

### nothrow() {#ga798bd28001c3938784073e60dd904148}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Callable_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::nothrow (const Callable_T &amp; func)</td>
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

<p>Check if a callable does not throw an exception.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Callable_T</td>
<td class="doxyParamItemDescription"><p>The type of the callable object to be invoked.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] func</td>
<td class="doxyParamItemDescription"><p>The callable object to check for exception safety.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>An output stream to write optional messages.</p></dd>
</dl>


<p>The <span class="doxyComputerOutput"><a href="#ga798bd28001c3938784073e60dd904148">nothrow</a></span> function template verifies whether invoking the provided callable object does not result in the throwing of any exception within the µTest++ framework. This is useful for testing exception safety and ensuring that code under test does not unexpectedly signal error conditions.</p>


<p>The function returns an output stream, allowing optional messages to be appended to the test report for diagnostic purposes.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/exceptions-inline-h/#l00115">115</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/exceptions-inline-h">exceptions-inline.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga798bd28001c3938784073e60dd904148">115</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ga798bd28001c3938784073e60dd904148">nothrow</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Callable_T&amp; func)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">116</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">117</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/nothrow-">detail::nothrow_&lt;Callable_T&gt;</a>{ func };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">118</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>

</div>
</div>

### throws() {#ga8bf54756e4122c6a0bd123b4621e60e2}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Callable_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::throws (const Callable_T &amp; func)</td>
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

<p>Check if a callable throws an exception (any exception).</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Callable_T</td>
<td class="doxyParamItemDescription"><p>The type of the callable object to be invoked.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] func</td>
<td class="doxyParamItemDescription"><p>The callable object to check for exception throwing behaviour.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>An output stream to write optional messages.</p></dd>
</dl>


<p>The <span class="doxyComputerOutput"><a href="#gaf8f7602f40119da514be2a0bfc4b70f5">throws</a></span> function template verifies whether invoking the provided callable object results in the throwing of any exception within the µTest++ framework. This is useful for testing general exception safety and ensuring that code under test properly signals error conditions.</p>


<p>The function returns an output stream, allowing optional messages to be appended to the test report for diagnostic purposes.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/exceptions-inline-h/#l00097">97</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/exceptions-inline-h">exceptions-inline.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga8bf54756e4122c6a0bd123b4621e60e2">97</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordFlow">throws</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Callable_T&amp; func)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">98</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">99</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/throws-">detail::throws_&lt;Callable_T&gt;</a>{ func };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">100</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>

</div>
</div>

### throws() {#gaf8f7602f40119da514be2a0bfc4b70f5}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Exception_T, class Callable_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::throws (const Callable_T &amp; func)</td>
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

<p>Check if a callable throws a specific exception.</p>


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
<td class="doxyParamItemDescription"><p>The type of the callable object to be invoked.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] func</td>
<td class="doxyParamItemDescription"><p>The callable object to check for exception throwing behaviour.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>An output stream to write optional messages.</p></dd>
</dl>


<p>The <span class="doxyComputerOutput"><a href="#gaf8f7602f40119da514be2a0bfc4b70f5">throws</a></span> function template verifies whether invoking the provided callable object results in the throwing of a specific exception type within the µTest++ framework. This is useful for testing error handling and exception safety in code under test.</p>


<p>The function returns an output stream, allowing optional messages to be appended to the test report for diagnostic purposes.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/exceptions-inline-h/#l00080">80</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/exceptions-inline-h">exceptions-inline.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gaf8f7602f40119da514be2a0bfc4b70f5">80</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordFlow">throws</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Callable_T&amp; func)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">81</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">82</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/throws-">detail::throws_&lt;Callable_T, Exception_T&gt;</a>{ func };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">83</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>

</div>
</div>

</div>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.0 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
