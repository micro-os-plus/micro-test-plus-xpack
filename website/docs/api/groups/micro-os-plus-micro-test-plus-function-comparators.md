---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-os-plus-micro-test-plus-function-comparators
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# Function Comparators

<p>Functions for comparing actual and expected values in tests. <a href="#details">More...</a></p>

## Typedefs Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#gabecc05360d0941067222d827ff8e3f08">expression_formatter</a> = detail::expression_formatter</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Public name of the formatter used to report operand values. <a href="#gabecc05360d0941067222d827ff8e3f08">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T, class Epsilon_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#gacae776e46a799b81af859ba9bb74e7d0">approx</a> (Lhs_T &amp;&amp;lhs, Rhs_T &amp;&amp;rhs, Epsilon_T &amp;&amp;epsilon)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Approximate equality comparator, with an explicit tolerance. <a href="#gacae776e46a799b81af859ba9bb74e7d0">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#gaa7c7b6a7ad32856edc235a05e77d8c7f">eq</a> (Lhs_T &amp;&amp;lhs, Rhs_T &amp;&amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Generic equality comparator. <a href="#gaa7c7b6a7ad32856edc235a05e77d8c7f">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#gab8da4228bc9a820546753b018a129a7e">ge</a> (Lhs_T &amp;&amp;lhs, Rhs_T &amp;&amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Generic greater than or equal comparator. <a href="#gab8da4228bc9a820546753b018a129a7e">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ga9ae8e4747ff029faa7378110c8680278">gt</a> (Lhs_T &amp;&amp;lhs, Rhs_T &amp;&amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Generic greater than comparator. <a href="#ga9ae8e4747ff029faa7378110c8680278">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#gae695dd46840f76a156aee70ff4df33fa">le</a> (Lhs_T &amp;&amp;lhs, Rhs_T &amp;&amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Generic less than or equal comparator. <a href="#gae695dd46840f76a156aee70ff4df33fa">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ga714ff07cd77e05898de4fd315770f901">lt</a> (Lhs_T &amp;&amp;lhs, Rhs_T &amp;&amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Generic less than comparator. <a href="#ga714ff07cd77e05898de4fd315770f901">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ga5bf176ef730172592095657417e5f039">ne</a> (Lhs_T &amp;&amp;lhs, Rhs_T &amp;&amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Generic non-equality comparator. <a href="#ga5bf176ef730172592095657417e5f039">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Functions for comparing actual and expected values in tests.</p>


<p>While any boolean expression can be used in expectations and requirements, dedicated comparator functions such as <span class="doxyComputerOutput">eq</span>, <span class="doxyComputerOutput">ne</span>, <span class="doxyComputerOutput">lt</span>, <span class="doxyComputerOutput">le</span>, <span class="doxyComputerOutput">gt</span>, and <span class="doxyComputerOutput">ge</span> provide enhanced reporting by explicitly showing the compared values when a check fails.</p>


<p>Using these comparators ensures that failed checks report both actual and expected values, making issues easier to diagnose.</p>


<p>Comparators are available for both fundamental types and standard containers. When a container comparison fails, the elements of both containers are shown.</p>


<dl class="doxySectionUser">
<dt>Examples</dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ts.test (</span><span class="doxyHighlightStringLiteral">"Check various conditions"</span><span class="doxyHighlight">, [] (</span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; t) {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  t.expect (mt::eq (compute_answer (), 42)) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"answer is 42"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  t.expect (mt::ne (compute_answer (), 43)) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"answer is not 43"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  t.expect (mt::lt (compute_answer (), 43)) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"answer is &lt; 43"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  t.expect (mt::le (compute_answer (), 43)) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"answer is &lt;= 43"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  t.expect (mt::gt (compute_answer (), 41)) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"answer is &gt; 41"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  t.expect (mt::ge (compute_answer (), 42)) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"answer is &gt;= 42"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  t.expect (compute_condition ()) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"condition is true"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">});</span></span></div>

</div>


<p>If a comparator check fails, the output clearly indicates the actual and expected values:</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">Check failed comparisons</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  ✗ actual != 42 FAILED (unit-test.cpp:286, 42 != 42)</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  ✗ FAILED (unit-test.cpp:307, 42 != 42)</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  ✗ (actual == 42) and (actual != 42.0) FAILED (unit-test.cpp:781, (42 == 42 and 42 != 42.0))</span></span></div>

</div>


<p>The C strings (<span class="doxyComputerOutput">char</span> arrays, including the string literals, and <span class="doxyComputerOutput">char</span> pointers) are compared by content, also with <span class="doxyComputerOutput">std::string</span> and <span class="doxyComputerOutput">std::string_view</span>, so <span class="doxyComputerOutput">mt::eq (actual, "abc")</span> checks the characters, not the addresses; a null <span class="doxyComputerOutput">char</span> pointer is equal only to another null pointer (or <span class="doxyComputerOutput">nullptr</span>), not to an empty string. The other pointers and arrays (including <span class="doxyComputerOutput">uint8_t</span> buffers) are compared by address.</p>


<dl class="doxySectionUser">
<dt>Comparing Containers</dt>
<dd></dd>
</dl>


<p>Containers can be compared for equality or inequality using the same comparator functions. The comparison is performed with the standard <span class="doxyComputerOutput">==</span> operator, so the containers must be of the same type. The standard <span class="doxyComputerOutput">==</span> and <span class="doxyComputerOutput">!=</span> operators return a plain <span class="doxyComputerOutput">bool</span>, so a failed check could not show the elements.</p>


<dl class="doxySectionUser">
<dt>Examples</dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight">mt = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ts.test (</span><span class="doxyHighlightStringLiteral">"Check containers"</span><span class="doxyHighlight">, [] (</span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; t) {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  t.expect (mt::eq (std::vector&lt;int&gt;{ 1, 2 }, std::vector&lt;int&gt;{ 1, 2 }))</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">      &lt;&lt; </span><span class="doxyHighlightStringLiteral">"vector{ 1, 2 } eq vector{ 1, 2 }"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  t.expect (mt::ne (std::vector&lt;int&gt;{ 1, 2, 3 },</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                    std::vector&lt;int&gt;{ 1, 2, 4 }))</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">      &lt;&lt; </span><span class="doxyHighlightStringLiteral">"vector{ 1, 2, 3 } ne vector{ 1, 2, 4 }"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">});</span></span></div>

</div>


<div class="doxySectionDef">

## Typedefs

### expression\_formatter {#gabecc05360d0941067222d827ff8e3f08}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">using micro_os_plus::micro_test_plus::expression_formatter = detail::expression_formatter</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Public name of the formatter used to report operand values.</p>


<p>The function comparators and the custom operators report the values of their operands when a check fails. Values of user-defined types can be reported only if the application provides an <span class="doxyComputerOutput">operator&lt;&lt;</span> that writes them to this formatter, declared in the namespace of the type, so that it is found by argument-dependent lookup:</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight">app</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">struct </span><span class="doxyHighlight">point</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> x;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> y;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  };</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  operator== (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> point&amp; lhs, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> point&amp; rhs)</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> lhs.x == rhs.x &amp;&amp; lhs.y == rhs.y;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">inline</span><span class="doxyHighlight"> mt::expression_formatter&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  operator&lt;&lt; (mt::expression_formatter&amp; formatter, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> point&amp; p)</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> formatter &lt;&lt; </span><span class="doxyHighlightStringLiteral">"{ "</span><span class="doxyHighlight"> &lt;&lt; p.x &lt;&lt; </span><span class="doxyHighlightStringLiteral">", "</span><span class="doxyHighlight"> &lt;&lt; p.y &lt;&lt; </span><span class="doxyHighlightStringLiteral">" }"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">} </span><span class="doxyHighlightComment">// namespace app</span></span></div>

</div>


<p>Without such an operator, comparators such as <span class="doxyComputerOutput"><a href="#gaa7c7b6a7ad32856edc235a05e77d8c7f">eq()</a></span> do not compile for user-defined types, since the operand values cannot be formatted; only the scoped enumerations are formatted without it, by their underlying value. Plain boolean checks, such as <span class="doxyComputerOutput">expect (a == b)</span>, do not need it, but they report only the source location on failure. The same operator also writes the values appended to the messages of the checks (<span class="doxyComputerOutput">expect (a == b) &lt;&lt; "a is " &lt;&lt; a</span>).</p>


<p>Applications use the <span class="doxyComputerOutput">operator&lt;&lt;</span> overloads, and <span class="doxyComputerOutput">str()</span> to test their own operators; the functions that manage the buffer are private to the framework.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l01227">1227</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gabecc05360d0941067222d827ff8e3f08">1227</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="#gabecc05360d0941067222d827ff8e3f08">expression_formatter</a> = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter">detail::expression_formatter</a>;</span></span></div>

</div>

</div>
</div>

</div>

<div class="doxySectionDef">

## Functions

### approx() {#gacae776e46a799b81af859ba9bb74e7d0}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T, class Epsilon_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::approx (Lhs_T &amp;&amp; lhs, Rhs_T &amp;&amp; rhs, Epsilon_T &amp;&amp; epsilon)</td>
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

<p>Approximate equality comparator, with an explicit tolerance.</p>


<p>The comparison succeeds if the distance between <span class="doxyComputerOutput">lhs</span> and <span class="doxyComputerOutput">rhs</span> is less than <span class="doxyComputerOutput">epsilon</span>. The operands are numbers, integral or floating-point, possibly of different types, or the framework value wrappers and numeric literals, whose own tolerance is not used. For the integers, the distance is computed exactly, also for operands of different signedness, so <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gafe47800a219b00fcccf0a1dc596dbe20">approx</a> (0u, -1, 2)</span> succeeds; for the other types, in their common floating-point type. A failure is reported as <span class="doxyComputerOutput">lhs ~ (rhs +/- epsilon)</span>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">t.expect (mt::approx (read_adc (), 512, 3)) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"ADC reading"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">t.expect (mt::approx (compute_float (), 42.0f, 0.001f));</span></span></div>

</div>


<p>The <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gafe47800a219b00fcccf0a1dc596dbe20">approx</a> (value, epsilon)</span> form is a value wrapper instead, which applies its tolerance to the six comparisons and to the operators; it accepts only floating-point values.</p>


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
<tr class="doxyParamItem">
<td class="doxyParamItemName">Epsilon_T</td>
<td class="doxyParamItemDescription"><p>Type of the tolerance.</p></td>
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
<tr class="doxyParamItem">
<td class="doxyParamItemName">epsilon</td>
<td class="doxyParamItemDescription"><p>The tolerance; a negative one fails all comparisons.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A comparator object that evaluates to true if <span class="doxyComputerOutput">lhs</span> and <span class="doxyComputerOutput">rhs</span> differ by less than <span class="doxyComputerOutput">epsilon</span>.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Since</dt>
<dd><p>5.1.0</p></dd>
</dl>


<p>The <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gafe47800a219b00fcccf0a1dc596dbe20">approx</a></span> function template constructs a <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/approx-op">detail::approx_op</a></span> from the forwarded operands and tolerance; the operands are numbers, so <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a51e86043001b197561806d5c6297041b">detail::as_operand()</a></span>, which converts the C strings, is not needed.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/function-comparators-inlines-h/#l00196">196</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/function-comparators-inlines-h">function-comparators-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gacae776e46a799b81af859ba9bb74e7d0">196</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gafe47800a219b00fcccf0a1dc596dbe20">approx</a> (Lhs_T&amp;&amp; lhs, Rhs_T&amp;&amp; rhs, Epsilon_T&amp;&amp; epsilon)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">197</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">198</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/approx-op">detail::approx_op</a>{ std::forward&lt;Lhs_T&gt; (lhs),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">199</span><span class="doxyLineContent"><span class="doxyHighlight">                              std::forward&lt;Rhs_T&gt; (rhs),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">200</span><span class="doxyLineContent"><span class="doxyHighlight">                              std::forward&lt;Epsilon_T&gt; (epsilon) };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">201</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gafe47800a219b00fcccf0a1dc596dbe20">micro_os_plus::micro_test_plus::approx</a>.</p>

</div>
</div>

### eq() {#gaa7c7b6a7ad32856edc235a05e77d8c7f}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::eq (Lhs_T &amp;&amp; lhs, Rhs_T &amp;&amp; rhs)</td>
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

<p>Generic equality comparator.</p>


<p>The C strings (<span class="doxyComputerOutput">char</span> arrays, including the string literals, and <span class="doxyComputerOutput">char</span> pointers) are compared by content, also with <span class="doxyComputerOutput">std::string</span> and <span class="doxyComputerOutput">std::string_view</span>; a null <span class="doxyComputerOutput">char</span> pointer is equal only to another null pointer. The other arrays (e.g. byte buffers) are compared element by element, also with a container, and written as ranges; the other pointers are compared by address. The pointers and arrays of <span class="doxyComputerOutput">char8_t</span>, <span class="doxyComputerOutput">char16_t</span>, <span class="doxyComputerOutput">char32_t</span>, and <span class="doxyComputerOutput">wchar_t</span> are not treated as strings: the arrays are compared element by element, including the terminating null character, and the pointers by address.</p>


<p>Both operands must satisfy <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/printable">extension::printable</a></span>, since they are reported on failure; an application type needs an <span class="doxyComputerOutput">operator&lt;&lt;</span> for <span class="doxyComputerOutput">mt::expression_formatter</span>, otherwise the call is rejected, with a diagnostic that names the operand type.</p>


<p>The same rules apply to <span class="doxyComputerOutput"><a href="#ga5bf176ef730172592095657417e5f039">ne()</a></span>, <span class="doxyComputerOutput"><a href="#ga9ae8e4747ff029faa7378110c8680278">gt()</a></span>, <span class="doxyComputerOutput"><a href="#gab8da4228bc9a820546753b018a129a7e">ge()</a></span>, <span class="doxyComputerOutput"><a href="#ga714ff07cd77e05898de4fd315770f901">lt()</a></span>, and <span class="doxyComputerOutput"><a href="#gae695dd46840f76a156aee70ff4df33fa">le()</a></span>.</p>


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


<p>The <span class="doxyComputerOutput"><a href="#gaa7c7b6a7ad32856edc235a05e77d8c7f">eq</a></span> function template provides a generic equality comparator for any types. The operands are first passed to <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a51e86043001b197561806d5c6297041b">detail::as_operand()</a></span>, which converts the C strings to <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/c-string">detail::c_string</a></span>, so that they are compared by content. It constructs a comparator object, with the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/equal-to">detail::equal_to</a></span> tag, which evaluates to <span class="doxyComputerOutput">true</span> if the two values are equal, and which is reported with both values if not.</p>


<p>The operands are forwarded, so that the comparator moves the temporaries and refers to the named operands, without copying them.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/function-comparators-inlines-h/#l00091">91</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/function-comparators-inlines-h">function-comparators-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gaa7c7b6a7ad32856edc235a05e77d8c7f">91</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#gaa7c7b6a7ad32856edc235a05e77d8c7f">eq</a> (Lhs_T&amp;&amp; lhs, Rhs_T&amp;&amp; rhs)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">92</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">93</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/compare-op">detail::compare_op</a>{ <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a51e86043001b197561806d5c6297041b">detail::as_operand</a> (std::forward&lt;Lhs_T&gt; (lhs)),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">94</span><span class="doxyLineContent"><span class="doxyHighlight">                               <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a51e86043001b197561806d5c6297041b">detail::as_operand</a> (std::forward&lt;Rhs_T&gt; (rhs)),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">95</span><span class="doxyLineContent"><span class="doxyHighlight">                               <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/equal-to">detail::equal_to</a>{} };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">96</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a51e86043001b197561806d5c6297041b">micro_os_plus::micro_test_plus::detail::as_operand</a> and <a href="#gaa7c7b6a7ad32856edc235a05e77d8c7f">micro_os_plus::micro_test_plus::eq</a>.</p>


<p>Referenced by <a href="#gaa7c7b6a7ad32856edc235a05e77d8c7f">micro_os_plus::micro_test_plus::eq</a>.</p>

</div>
</div>

### ge() {#gab8da4228bc9a820546753b018a129a7e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::ge (Lhs_T &amp;&amp; lhs, Rhs_T &amp;&amp; rhs)</td>
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

<p>Generic greater than or equal comparator.</p>


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
<dd><p>A comparator object that evaluates to true if <span class="doxyComputerOutput">lhs</span> is greater than or equal to <span class="doxyComputerOutput">rhs</span>.</p></dd>
</dl>


<p>The operands are passed to <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a51e86043001b197561806d5c6297041b">detail::as_operand()</a></span>, as for <span class="doxyComputerOutput"><a href="#gaa7c7b6a7ad32856edc235a05e77d8c7f">eq()</a></span>, so that the C strings are compared by content. It constructs a comparator object, with the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/greater-equal">detail::greater_equal</a></span> tag, which evaluates to <span class="doxyComputerOutput">true</span> if <span class="doxyComputerOutput">lhs</span> is greater than or equal to <span class="doxyComputerOutput">rhs</span>, and which is reported with both values if not.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/function-comparators-inlines-h/#l00143">143</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/function-comparators-inlines-h">function-comparators-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gab8da4228bc9a820546753b018a129a7e">143</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#gab8da4228bc9a820546753b018a129a7e">ge</a> (Lhs_T&amp;&amp; lhs, Rhs_T&amp;&amp; rhs)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">144</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">145</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/compare-op">detail::compare_op</a>{ <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a51e86043001b197561806d5c6297041b">detail::as_operand</a> (std::forward&lt;Lhs_T&gt; (lhs)),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">146</span><span class="doxyLineContent"><span class="doxyHighlight">                               <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a51e86043001b197561806d5c6297041b">detail::as_operand</a> (std::forward&lt;Rhs_T&gt; (rhs)),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">147</span><span class="doxyLineContent"><span class="doxyHighlight">                               <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/greater-equal">detail::greater_equal</a>{} };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">148</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a51e86043001b197561806d5c6297041b">micro_os_plus::micro_test_plus::detail::as_operand</a> and <a href="#gab8da4228bc9a820546753b018a129a7e">micro_os_plus::micro_test_plus::ge</a>.</p>


<p>Referenced by <a href="#gab8da4228bc9a820546753b018a129a7e">micro_os_plus::micro_test_plus::ge</a>.</p>

</div>
</div>

### gt() {#ga9ae8e4747ff029faa7378110c8680278}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::gt (Lhs_T &amp;&amp; lhs, Rhs_T &amp;&amp; rhs)</td>
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

<p>Generic greater than comparator.</p>


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
<dd><p>A comparator object that evaluates to true if <span class="doxyComputerOutput">lhs</span> is greater than <span class="doxyComputerOutput">rhs</span>.</p></dd>
</dl>


<p>The operands are passed to <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a51e86043001b197561806d5c6297041b">detail::as_operand()</a></span>, as for <span class="doxyComputerOutput"><a href="#gaa7c7b6a7ad32856edc235a05e77d8c7f">eq()</a></span>, so that the C strings are compared by content. It constructs a comparator object, with the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/greater">detail::greater</a></span> tag, which evaluates to <span class="doxyComputerOutput">true</span> if <span class="doxyComputerOutput">lhs</span> is greater than <span class="doxyComputerOutput">rhs</span>, and which is reported with both values if not.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/function-comparators-inlines-h/#l00125">125</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/function-comparators-inlines-h">function-comparators-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga9ae8e4747ff029faa7378110c8680278">125</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ga9ae8e4747ff029faa7378110c8680278">gt</a> (Lhs_T&amp;&amp; lhs, Rhs_T&amp;&amp; rhs)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">126</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">127</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/compare-op">detail::compare_op</a>{ <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a51e86043001b197561806d5c6297041b">detail::as_operand</a> (std::forward&lt;Lhs_T&gt; (lhs)),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">128</span><span class="doxyLineContent"><span class="doxyHighlight">                               <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a51e86043001b197561806d5c6297041b">detail::as_operand</a> (std::forward&lt;Rhs_T&gt; (rhs)),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">129</span><span class="doxyLineContent"><span class="doxyHighlight">                               <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/greater">detail::greater</a>{} };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">130</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a51e86043001b197561806d5c6297041b">micro_os_plus::micro_test_plus::detail::as_operand</a> and <a href="#ga9ae8e4747ff029faa7378110c8680278">micro_os_plus::micro_test_plus::gt</a>.</p>


<p>Referenced by <a href="#ga9ae8e4747ff029faa7378110c8680278">micro_os_plus::micro_test_plus::gt</a>.</p>

</div>
</div>

### le() {#gae695dd46840f76a156aee70ff4df33fa}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::le (Lhs_T &amp;&amp; lhs, Rhs_T &amp;&amp; rhs)</td>
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

<p>Generic less than or equal comparator.</p>


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
<dd><p>A comparator object that evaluates to true if <span class="doxyComputerOutput">lhs</span> is less than or equal to <span class="doxyComputerOutput">rhs</span>.</p></dd>
</dl>


<p>The operands are passed to <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a51e86043001b197561806d5c6297041b">detail::as_operand()</a></span>, as for <span class="doxyComputerOutput"><a href="#gaa7c7b6a7ad32856edc235a05e77d8c7f">eq()</a></span>, so that the C strings are compared by content. It constructs a comparator object, with the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/less-equal">detail::less_equal</a></span> tag, which evaluates to <span class="doxyComputerOutput">true</span> if <span class="doxyComputerOutput">lhs</span> is less than or equal to <span class="doxyComputerOutput">rhs</span>, and which is reported with both values if not.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/function-comparators-inlines-h/#l00178">178</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/function-comparators-inlines-h">function-comparators-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gae695dd46840f76a156aee70ff4df33fa">178</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#gae695dd46840f76a156aee70ff4df33fa">le</a> (Lhs_T&amp;&amp; lhs, Rhs_T&amp;&amp; rhs)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">179</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">180</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/compare-op">detail::compare_op</a>{ <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a51e86043001b197561806d5c6297041b">detail::as_operand</a> (std::forward&lt;Lhs_T&gt; (lhs)),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">181</span><span class="doxyLineContent"><span class="doxyHighlight">                               <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a51e86043001b197561806d5c6297041b">detail::as_operand</a> (std::forward&lt;Rhs_T&gt; (rhs)),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">182</span><span class="doxyLineContent"><span class="doxyHighlight">                               <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/less-equal">detail::less_equal</a>{} };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">183</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a51e86043001b197561806d5c6297041b">micro_os_plus::micro_test_plus::detail::as_operand</a> and <a href="#gae695dd46840f76a156aee70ff4df33fa">micro_os_plus::micro_test_plus::le</a>.</p>


<p>Referenced by <a href="#gae695dd46840f76a156aee70ff4df33fa">micro_os_plus::micro_test_plus::le</a>.</p>

</div>
</div>

### lt() {#ga714ff07cd77e05898de4fd315770f901}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::lt (Lhs_T &amp;&amp; lhs, Rhs_T &amp;&amp; rhs)</td>
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

<p>Generic less than comparator.</p>


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
<dd><p>A comparator object that evaluates to true if <span class="doxyComputerOutput">lhs</span> is less than <span class="doxyComputerOutput">rhs</span>.</p></dd>
</dl>


<p>The operands are passed to <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a51e86043001b197561806d5c6297041b">detail::as_operand()</a></span>, as for <span class="doxyComputerOutput"><a href="#gaa7c7b6a7ad32856edc235a05e77d8c7f">eq()</a></span>, so that the C strings are compared by content. It constructs a comparator object, with the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/less">detail::less</a></span> tag, which evaluates to <span class="doxyComputerOutput">true</span> if <span class="doxyComputerOutput">lhs</span> is less than <span class="doxyComputerOutput">rhs</span>, and which is reported with both values if not.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/function-comparators-inlines-h/#l00160">160</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/function-comparators-inlines-h">function-comparators-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga714ff07cd77e05898de4fd315770f901">160</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ga714ff07cd77e05898de4fd315770f901">lt</a> (Lhs_T&amp;&amp; lhs, Rhs_T&amp;&amp; rhs)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">161</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">162</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/compare-op">detail::compare_op</a>{ <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a51e86043001b197561806d5c6297041b">detail::as_operand</a> (std::forward&lt;Lhs_T&gt; (lhs)),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">163</span><span class="doxyLineContent"><span class="doxyHighlight">                               <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a51e86043001b197561806d5c6297041b">detail::as_operand</a> (std::forward&lt;Rhs_T&gt; (rhs)),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">164</span><span class="doxyLineContent"><span class="doxyHighlight">                               <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/less">detail::less</a>{} };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">165</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a51e86043001b197561806d5c6297041b">micro_os_plus::micro_test_plus::detail::as_operand</a> and <a href="#ga714ff07cd77e05898de4fd315770f901">micro_os_plus::micro_test_plus::lt</a>.</p>


<p>Referenced by <a href="#ga714ff07cd77e05898de4fd315770f901">micro_os_plus::micro_test_plus::lt</a>.</p>

</div>
</div>

### ne() {#ga5bf176ef730172592095657417e5f039}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::ne (Lhs_T &amp;&amp; lhs, Rhs_T &amp;&amp; rhs)</td>
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

<p>Generic non-equality comparator.</p>


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


<p>The operands are passed to <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a51e86043001b197561806d5c6297041b">detail::as_operand()</a></span>, as for <span class="doxyComputerOutput"><a href="#gaa7c7b6a7ad32856edc235a05e77d8c7f">eq()</a></span>, so that the C strings are compared by content. It constructs a comparator object, with the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/not-equal-to">detail::not_equal_to</a></span> tag, which evaluates to <span class="doxyComputerOutput">true</span> if the two values are not equal, and which is reported with both values if not.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/function-comparators-inlines-h/#l00108">108</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/function-comparators-inlines-h">function-comparators-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga5bf176ef730172592095657417e5f039">108</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ga5bf176ef730172592095657417e5f039">ne</a> (Lhs_T&amp;&amp; lhs, Rhs_T&amp;&amp; rhs)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">109</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">110</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/compare-op">detail::compare_op</a>{ <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a51e86043001b197561806d5c6297041b">detail::as_operand</a> (std::forward&lt;Lhs_T&gt; (lhs)),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">111</span><span class="doxyLineContent"><span class="doxyHighlight">                               <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a51e86043001b197561806d5c6297041b">detail::as_operand</a> (std::forward&lt;Rhs_T&gt; (rhs)),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">112</span><span class="doxyLineContent"><span class="doxyHighlight">                               <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/not-equal-to">detail::not_equal_to</a>{} };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">113</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a51e86043001b197561806d5c6297041b">micro_os_plus::micro_test_plus::detail::as_operand</a> and <a href="#ga5bf176ef730172592095657417e5f039">micro_os_plus::micro_test_plus::ne</a>.</p>


<p>Referenced by <a href="#ga5bf176ef730172592095657417e5f039">micro_os_plus::micro_test_plus::ne</a>.</p>

</div>
</div>

</div>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
