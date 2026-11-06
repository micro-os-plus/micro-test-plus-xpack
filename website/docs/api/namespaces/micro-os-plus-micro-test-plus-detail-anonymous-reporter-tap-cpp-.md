---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-reporter-tap-cpp-
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - namespace

---

<div class="doxyPage">

# `anonymous{reporter-tap.cpp}` Namespace

<p>Local helpers of the TAP reporter. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
namespace micro_os_plus::micro_test_plus::detail::anonymous{reporter-tap.cpp} { ... }
</div>

## Classes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/anonymous-reporter-tap-cpp-/tap-name">tap_name</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>A name prepared for a single TAP line, without a copy when it needs no change. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/anonymous-reporter-tap-cpp-/tap-name/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">std::string</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aec79a35b7936b91bee63d9baf4f8c861">tap_text</a> (std::string_view text, bool escape)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Prepares a text for a single TAP line. <a href="#aec79a35b7936b91bee63d9baf4f8c861">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">std::string</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ae344ed13847263c08e39a3e9266c0109">yaml_double_quoted</a> (std::string_view text)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats a text as a YAML double-quoted scalar. <a href="#ae344ed13847263c08e39a3e9266c0109">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">std::string</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a27ca54c91d04ccb21bebc0f54b0c735b">yaml_scalar</a> (std::string_view text)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats a text as a YAML scalar, double-quoted only when needed. <a href="#a27ca54c91d04ccb21bebc0f54b0c735b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Local helpers of the TAP reporter.</p>


<p>The unnamed namespace gives the helpers internal linkage, so that they are visible only in this translation unit, and cannot conflict with the names of the application or of the other source files of the framework. They are not declared in any header.</p>


<p>It contains the functions that make the texts safe to write in the TAP output: <span class="doxyComputerOutput"><a href="#aec79a35b7936b91bee63d9baf4f8c861">tap_text()</a></span>, for the test point descriptions, the reasons, and the comments, and <span class="doxyComputerOutput"><a href="#ae344ed13847263c08e39a3e9266c0109">yaml_double_quoted()</a></span>, for the values of the YAML diagnostic blocks.</p>


<div class="doxySectionDef">

## Functions

### tap\_text() {#aec79a35b7936b91bee63d9baf4f8c861}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::string micro_os_plus::micro_test_plus::detail::anonymous{reporter-tap.cpp}::tap_text (std::string_view text, bool escape)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Prepares a text for a single TAP line.</p>


<p>Each line break (<span class="doxyComputerOutput">\\n</span>, <span class="doxyComputerOutput">\\r</span>, or the <span class="doxyComputerOutput">\\r\\n</span> pair) is replaced by a space, so that the text does not end the line. When <span class="doxyComputerOutput">escape</span> is true, each <span class="doxyComputerOutput">\\</span> is written as <span class="doxyComputerOutput">\\\\</span> and each <span class="doxyComputerOutput">#</span> as <span class="doxyComputerOutput">\\#</span>, as the TAP 14 specification recommends for the test point descriptions and the reasons, so that a <span class="doxyComputerOutput">#</span> in the text does not start a directive (for example <span class="doxyComputerOutput"># TODO</span>, which would hide a failure). The <span class="doxyComputerOutput"># Subtest:</span> comments are not escaped, since the specification defines no escapes in comments, and the node-tap parser uses their text as it is.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">text</td>
<td class="doxyParamItemDescription"><p>The text to prepare.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">escape</td>
<td class="doxyParamItemDescription"><p>Whether to escape the <span class="doxyComputerOutput">\\</span> and <span class="doxyComputerOutput">#</span> characters.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The text, without line breaks, and escaped if requested.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp/#l00104">104</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp">reporter-tap.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aec79a35b7936b91bee63d9baf4f8c861">104</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#aec79a35b7936b91bee63d9baf4f8c861">tap_text</a> (std::string_view text, </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> escape)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">105</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">106</span><span class="doxyLineContent"><span class="doxyHighlight">      std::string result;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">107</span><span class="doxyLineContent"><span class="doxyHighlight">      result.reserve (text.size ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">108</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">109</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> i = 0; i &lt; text.size (); ++i)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">110</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">111</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> c = text[i];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">112</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (c == </span><span class="doxyHighlightCharLiteral">'\n'</span><span class="doxyHighlight"> || c == </span><span class="doxyHighlightCharLiteral">'\r'</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">113</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">114</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightComment">// The `\r\n` pair is a single line break.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">115</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (c == </span><span class="doxyHighlightCharLiteral">'\r'</span><span class="doxyHighlight"> &amp;&amp; i + 1 &lt; text.size () &amp;&amp; text[i + 1] == </span><span class="doxyHighlightCharLiteral">'\n'</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">116</span><span class="doxyLineContent"><span class="doxyHighlight">                {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">117</span><span class="doxyLineContent"><span class="doxyHighlight">                  ++i;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">118</span><span class="doxyLineContent"><span class="doxyHighlight">                }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">119</span><span class="doxyLineContent"><span class="doxyHighlight">              result.push_back (</span><span class="doxyHighlightCharLiteral">' '</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">120</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">121</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (escape &amp;&amp; (c == </span><span class="doxyHighlightCharLiteral">'\\'</span><span class="doxyHighlight"> || c == </span><span class="doxyHighlightCharLiteral">'#'</span><span class="doxyHighlight">))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">122</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">123</span><span class="doxyLineContent"><span class="doxyHighlight">              result.push_back (</span><span class="doxyHighlightCharLiteral">'\\'</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">124</span><span class="doxyLineContent"><span class="doxyHighlight">              result.push_back (c);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">125</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">126</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">127</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">128</span><span class="doxyLineContent"><span class="doxyHighlight">              result.push_back (c);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">129</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">130</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">131</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">132</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> result;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">133</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="#aec79a35b7936b91bee63d9baf4f8c861">tap_text</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/anonymous-reporter-tap-cpp-/tap-name/#a5d67972734913f25068fffc292670c0c">micro_os_plus::micro_test_plus::detail::anonymous{reporter-tap.cpp}::tap_name::tap_name</a> and <a href="#aec79a35b7936b91bee63d9baf4f8c861">tap_text</a>.</p>

</div>
</div>

### yaml\_double\_quoted() {#ae344ed13847263c08e39a3e9266c0109}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::string micro_os_plus::micro_test_plus::detail::anonymous{reporter-tap.cpp}::yaml_double_quoted (std::string_view text)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Formats a text as a YAML double-quoted scalar.</p>


<p>The text is enclosed in <span class="doxyComputerOutput">"</span>, with each <span class="doxyComputerOutput">\\</span> written as <span class="doxyComputerOutput">\\\\</span>, each <span class="doxyComputerOutput">"</span> as <span class="doxyComputerOutput">\\"</span>, and each control character (including the line breaks, the tab, and <span class="doxyComputerOutput">DEL</span>) as a YAML escape sequence (<span class="doxyComputerOutput">\\0</span>, <span class="doxyComputerOutput">\\t</span>, <span class="doxyComputerOutput">\\n</span>, <span class="doxyComputerOutput">\\r</span>, <span class="doxyComputerOutput">\\e</span>, and so on, or <span class="doxyComputerOutput">\\xHH</span> for the others), so that the value is a single line, and is valid YAML whatever it contains. As plain scalars, the values starting with <span class="doxyComputerOutput">{</span>, <span class="doxyComputerOutput">[</span>, or <span class="doxyComputerOutput">'</span>, or containing <span class="doxyComputerOutput">: </span> or <span class="doxyComputerOutput"> #</span>, would be rejected or truncated by the YAML parsers used by the TAP consumers. The bytes above <span class="doxyComputerOutput">0x7F</span> are written as they are, since they are expected to be parts of UTF-8 sequences.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">text</td>
<td class="doxyParamItemDescription"><p>The text to format.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The double-quoted scalar.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp/#l00294">294</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp">reporter-tap.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ae344ed13847263c08e39a3e9266c0109">294</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#ae344ed13847263c08e39a3e9266c0109">yaml_double_quoted</a> (std::string_view text)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">295</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">296</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> std::string_view digits{ </span><span class="doxyHighlightStringLiteral">"0123456789ABCDEF"</span><span class="doxyHighlight"> };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">297</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">298</span><span class="doxyLineContent"><span class="doxyHighlight">      std::string result;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">299</span><span class="doxyLineContent"><span class="doxyHighlight">      result.reserve (text.size () + 2);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">300</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">301</span><span class="doxyLineContent"><span class="doxyHighlight">      result.push_back (</span><span class="doxyHighlightCharLiteral">'"'</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">302</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> c : text)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">303</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">304</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> u = </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (c);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">305</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">switch</span><span class="doxyHighlight"> (c)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">306</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">307</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> </span><span class="doxyHighlightCharLiteral">'\\'</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">308</span><span class="doxyLineContent"><span class="doxyHighlight">              result.append (</span><span class="doxyHighlightStringLiteral">"\\\\"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">309</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">310</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> </span><span class="doxyHighlightCharLiteral">'"'</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">311</span><span class="doxyLineContent"><span class="doxyHighlight">              result.append (</span><span class="doxyHighlightStringLiteral">"\\\""</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">312</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">313</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> </span><span class="doxyHighlightCharLiteral">'\0'</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">314</span><span class="doxyLineContent"><span class="doxyHighlight">              result.append (</span><span class="doxyHighlightStringLiteral">"\\0"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">315</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">316</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> </span><span class="doxyHighlightCharLiteral">'\a'</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">317</span><span class="doxyLineContent"><span class="doxyHighlight">              result.append (</span><span class="doxyHighlightStringLiteral">"\\a"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">318</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">319</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> </span><span class="doxyHighlightCharLiteral">'\b'</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">320</span><span class="doxyLineContent"><span class="doxyHighlight">              result.append (</span><span class="doxyHighlightStringLiteral">"\\b"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">321</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">322</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> </span><span class="doxyHighlightCharLiteral">'\t'</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">323</span><span class="doxyLineContent"><span class="doxyHighlight">              result.append (</span><span class="doxyHighlightStringLiteral">"\\t"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">324</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">325</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> </span><span class="doxyHighlightCharLiteral">'\n'</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">326</span><span class="doxyLineContent"><span class="doxyHighlight">              result.append (</span><span class="doxyHighlightStringLiteral">"\\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">327</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">328</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> </span><span class="doxyHighlightCharLiteral">'\v'</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">329</span><span class="doxyLineContent"><span class="doxyHighlight">              result.append (</span><span class="doxyHighlightStringLiteral">"\\v"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">330</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">331</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> </span><span class="doxyHighlightCharLiteral">'\f'</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">332</span><span class="doxyLineContent"><span class="doxyHighlight">              result.append (</span><span class="doxyHighlightStringLiteral">"\\f"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">333</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">334</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> </span><span class="doxyHighlightCharLiteral">'\r'</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">335</span><span class="doxyLineContent"><span class="doxyHighlight">              result.append (</span><span class="doxyHighlightStringLiteral">"\\r"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">336</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">337</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> </span><span class="doxyHighlightStringLiteral">'\x1B'</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">338</span><span class="doxyLineContent"><span class="doxyHighlight">              result.append (</span><span class="doxyHighlightStringLiteral">"\\e"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">339</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">340</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">default</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">341</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (u &lt; 0x20 || u == 0x7F)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">342</span><span class="doxyLineContent"><span class="doxyHighlight">                {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">343</span><span class="doxyLineContent"><span class="doxyHighlight">                  result.append (</span><span class="doxyHighlightStringLiteral">"\\x"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">344</span><span class="doxyLineContent"><span class="doxyHighlight">                  result.push_back (digits[</span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">std::size_t</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (u &gt;&gt; 4)]);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">345</span><span class="doxyLineContent"><span class="doxyHighlight">                  result.push_back (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">346</span><span class="doxyLineContent"><span class="doxyHighlight">                      digits[</span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">std::size_t</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (u &amp; 0x0F)]);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">347</span><span class="doxyLineContent"><span class="doxyHighlight">                }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">348</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">349</span><span class="doxyLineContent"><span class="doxyHighlight">                {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">350</span><span class="doxyLineContent"><span class="doxyHighlight">                  result.push_back (c);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">351</span><span class="doxyLineContent"><span class="doxyHighlight">                }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">352</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">353</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">354</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">355</span><span class="doxyLineContent"><span class="doxyHighlight">      result.push_back (</span><span class="doxyHighlightCharLiteral">'"'</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">356</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">357</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> result;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">358</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="#ae344ed13847263c08e39a3e9266c0109">yaml_double_quoted</a>.</p>


<p>Referenced by <a href="#ae344ed13847263c08e39a3e9266c0109">yaml_double_quoted</a> and <a href="#a27ca54c91d04ccb21bebc0f54b0c735b">yaml_scalar</a>.</p>

</div>
</div>

### yaml\_scalar() {#a27ca54c91d04ccb21bebc0f54b0c735b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::string micro_os_plus::micro_test_plus::detail::anonymous{reporter-tap.cpp}::yaml_scalar (std::string_view text)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Formats a text as a YAML scalar, double-quoted only when needed.</p>


<p>A text made only of letters, digits, and the characters <span class="doxyComputerOutput">_</span>, <span class="doxyComputerOutput">.</span>, <span class="doxyComputerOutput">+</span>, <span class="doxyComputerOutput">/</span>, and <span class="doxyComputerOutput">-</span>, and not starting with <span class="doxyComputerOutput">-</span>, is a valid plain scalar, whatever its meaning, and is returned unchanged, so that the usual values are written as before. Any other text, for example a file name with a space, a <span class="doxyComputerOutput">#</span>, or a <span class="doxyComputerOutput">:</span>, which a YAML parser would truncate, split, or reject as a plain scalar, is returned double-quoted, as <span class="doxyComputerOutput"><a href="#ae344ed13847263c08e39a3e9266c0109">yaml_double_quoted()</a></span> does.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">text</td>
<td class="doxyParamItemDescription"><p>The text to format.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The scalar.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp/#l00377">377</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp">reporter-tap.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a27ca54c91d04ccb21bebc0f54b0c735b">377</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a27ca54c91d04ccb21bebc0f54b0c735b">yaml_scalar</a> (std::string_view text)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">378</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">379</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> is_plain = !text.empty () &amp;&amp; text.front () != </span><span class="doxyHighlightCharLiteral">'-'</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">380</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> c : text)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">381</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">382</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> is_safe = (c &gt;= </span><span class="doxyHighlightCharLiteral">'a'</span><span class="doxyHighlight"> &amp;&amp; c &lt;= </span><span class="doxyHighlightCharLiteral">'z'</span><span class="doxyHighlight">) || (c &gt;= </span><span class="doxyHighlightCharLiteral">'A'</span><span class="doxyHighlight"> &amp;&amp; c &lt;= </span><span class="doxyHighlightCharLiteral">'Z'</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">383</span><span class="doxyLineContent"><span class="doxyHighlight">                               || (c &gt;= </span><span class="doxyHighlightCharLiteral">'0'</span><span class="doxyHighlight"> &amp;&amp; c &lt;= </span><span class="doxyHighlightCharLiteral">'9'</span><span class="doxyHighlight">) || c == </span><span class="doxyHighlightCharLiteral">'_'</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">384</span><span class="doxyLineContent"><span class="doxyHighlight">                               || c == </span><span class="doxyHighlightCharLiteral">'.'</span><span class="doxyHighlight"> || c == </span><span class="doxyHighlightCharLiteral">'+'</span><span class="doxyHighlight"> || c == </span><span class="doxyHighlightCharLiteral">'/'</span><span class="doxyHighlight"> || c == </span><span class="doxyHighlightCharLiteral">'-'</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">385</span><span class="doxyLineContent"><span class="doxyHighlight">          is_plain = is_plain &amp;&amp; is_safe;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">386</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">387</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">388</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> is_plain ? std::string{ text } : <a href="#ae344ed13847263c08e39a3e9266c0109">yaml_double_quoted</a> (text);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">389</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="#ae344ed13847263c08e39a3e9266c0109">yaml_double_quoted</a> and <a href="#a27ca54c91d04ccb21bebc0f54b0c735b">yaml_scalar</a>.</p>


<p>Referenced by <a href="#a27ca54c91d04ccb21bebc0f54b0c735b">yaml_scalar</a>.</p>

</div>
</div>

</div>

<hr/>

The documentation for this namespace was generated from the following file:

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/src/reporter-tap-cpp">reporter-tap.cpp</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.7 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
