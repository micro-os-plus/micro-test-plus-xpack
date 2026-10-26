---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/namespaces/micro-os-plus/micro-test-plus/detail/anonymous-expression-formatter-cpp-
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - namespace

---

<div class="doxyPage">

# `anonymous{expression-formatter.cpp}` Namespace

<p>Local helpers of the expression formatter. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
namespace micro_os_plus::micro_test_plus::detail::anonymous{expression-formatter.cpp} { ... }
</div>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a2736611c9676822f8e948dc473f748f1">append_hex</a> (std::string &amp;buffer, char32_t code, std::string_view escape, std::size_t count)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends an escape and a fixed number of hexadecimal digits. <a href="#a2736611c9676822f8e948dc473f748f1">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a82575d5d4e13eb8c54fd209ab830cd7d">append_quoted</a> (std::string &amp;buffer, std::string_view sv)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends a string, as a quoted literal. <a href="#a82575d5d4e13eb8c54fd209ab830cd7d">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Local helpers of the expression formatter.</p>


<p>The unnamed namespace gives the helpers internal linkage, so that they are visible only in this translation unit, and cannot conflict with the names of the application or of the other source files of the framework. They are not declared in any header.</p>


<p>It contains <span class="doxyComputerOutput"><a href="#a2736611c9676822f8e948dc473f748f1">append_hex()</a></span>, which writes the hexadecimal escapes of the characters that cannot be printed as they are, and <span class="doxyComputerOutput"><a href="#a82575d5d4e13eb8c54fd209ab830cd7d">append_quoted()</a></span>, which writes a string between double quotes.</p>


<div class="doxySectionDef">

## Functions

### append\_hex() {#a2736611c9676822f8e948dc473f748f1}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::anonymous{expression-formatter.cpp}::append_hex (std::string &amp; buffer, char32_t code, std::string_view escape, std::size_t count)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends an escape and a fixed number of hexadecimal digits.</p>


<p>Used by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a1af5c2ffe3cd4eacad21667c2d4e3914">expression_formatter::append_character()</a></span>; the digits are lowercase, the most significant first, and the leading zeros are kept, so that the number of digits shows the size of the type.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">buffer</td>
<td class="doxyParamItemDescription"><p>The text to which the escape is appended.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">code</td>
<td class="doxyParamItemDescription"><p>The value to write.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">escape</td>
<td class="doxyParamItemDescription"><p>The escape before the digits (<span class="doxyComputerOutput">"\\x"</span>, <span class="doxyComputerOutput">"\\u"</span>, or <span class="doxyComputerOutput">"\\U"</span>).</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">count</td>
<td class="doxyParamItemDescription"><p>The number of digits.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00098">98</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a2736611c9676822f8e948dc473f748f1">98</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a2736611c9676822f8e948dc473f748f1">append_hex</a> (std::string&amp; buffer, </span><span class="doxyHighlightKeywordType">char32_t</span><span class="doxyHighlight"> code, std::string_view escape,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">99</span><span class="doxyLineContent"><span class="doxyHighlight">                std::size_t count)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">100</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">101</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> std::string_view digits{ </span><span class="doxyHighlightStringLiteral">"0123456789abcdef"</span><span class="doxyHighlight"> };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">102</span><span class="doxyLineContent"><span class="doxyHighlight">      buffer.append (escape);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">103</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (std::size_t i = count; i &gt; 0; --i)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">104</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">105</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightComment">// The promoted type of `code` is `std::size_t` on some</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">106</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightComment">// platforms, so a cast would be reported as useless.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">107</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> nibble = (code &gt;&gt; ((i - 1) * 4)) &amp; 0x0Fu;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">108</span><span class="doxyLineContent"><span class="doxyHighlight">          buffer.push_back (digits[nibble]);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">109</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">110</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="#a2736611c9676822f8e948dc473f748f1">append_hex</a>.</p>


<p>Referenced by <a href="#a2736611c9676822f8e948dc473f748f1">append_hex</a> and <a href="#a82575d5d4e13eb8c54fd209ab830cd7d">append_quoted</a>.</p>

</div>
</div>

### append\_quoted() {#a82575d5d4e13eb8c54fd209ab830cd7d}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::anonymous{expression-formatter.cpp}::append_quoted (std::string &amp; buffer, std::string_view sv)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends a string, as a quoted literal.</p>


<p>Used by the string operands, so that the empty strings and the leading or trailing spaces are visible, and the control characters do not reach the console. The escapes are those of the character literals, with the double quote escaped instead of the single quote. The bytes above <span class="doxyComputerOutput">127</span> are written unchanged, so that the UTF-8 text remains readable.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">buffer</td>
<td class="doxyParamItemDescription"><p>The text to which the literal is appended.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">sv</td>
<td class="doxyParamItemDescription"><p>The string to write; it may contain <span class="doxyComputerOutput">'\\0'</span>.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00129">129</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a82575d5d4e13eb8c54fd209ab830cd7d">129</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a82575d5d4e13eb8c54fd209ab830cd7d">append_quoted</a> (std::string&amp; buffer, std::string_view sv)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">130</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">131</span><span class="doxyLineContent"><span class="doxyHighlight">      buffer.push_back (</span><span class="doxyHighlightCharLiteral">'"'</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">132</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> c : sv)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">133</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">134</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">switch</span><span class="doxyHighlight"> (c)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">135</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">136</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> </span><span class="doxyHighlightCharLiteral">'\0'</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">137</span><span class="doxyLineContent"><span class="doxyHighlight">              buffer.append (</span><span class="doxyHighlightStringLiteral">"\\0"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">138</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">139</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> </span><span class="doxyHighlightCharLiteral">'\a'</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">140</span><span class="doxyLineContent"><span class="doxyHighlight">              buffer.append (</span><span class="doxyHighlightStringLiteral">"\\a"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">141</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">142</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> </span><span class="doxyHighlightCharLiteral">'\b'</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">143</span><span class="doxyLineContent"><span class="doxyHighlight">              buffer.append (</span><span class="doxyHighlightStringLiteral">"\\b"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">144</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">145</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> </span><span class="doxyHighlightCharLiteral">'\t'</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">146</span><span class="doxyLineContent"><span class="doxyHighlight">              buffer.append (</span><span class="doxyHighlightStringLiteral">"\\t"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">147</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">148</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> </span><span class="doxyHighlightCharLiteral">'\n'</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">149</span><span class="doxyLineContent"><span class="doxyHighlight">              buffer.append (</span><span class="doxyHighlightStringLiteral">"\\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">150</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">151</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> </span><span class="doxyHighlightCharLiteral">'\v'</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">152</span><span class="doxyLineContent"><span class="doxyHighlight">              buffer.append (</span><span class="doxyHighlightStringLiteral">"\\v"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">153</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">154</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> </span><span class="doxyHighlightCharLiteral">'\f'</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">155</span><span class="doxyLineContent"><span class="doxyHighlight">              buffer.append (</span><span class="doxyHighlightStringLiteral">"\\f"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">156</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">157</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> </span><span class="doxyHighlightCharLiteral">'\r'</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">158</span><span class="doxyLineContent"><span class="doxyHighlight">              buffer.append (</span><span class="doxyHighlightStringLiteral">"\\r"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">159</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">160</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> </span><span class="doxyHighlightCharLiteral">'"'</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">161</span><span class="doxyLineContent"><span class="doxyHighlight">              buffer.append (</span><span class="doxyHighlightStringLiteral">"\\\""</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">162</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">163</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> </span><span class="doxyHighlightCharLiteral">'\\'</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">164</span><span class="doxyLineContent"><span class="doxyHighlight">              buffer.append (</span><span class="doxyHighlightStringLiteral">"\\\\"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">165</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">166</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">default</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">167</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (c) &lt; 32 || c == 0x7F)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">168</span><span class="doxyLineContent"><span class="doxyHighlight">                {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">169</span><span class="doxyLineContent"><span class="doxyHighlight">                  <a href="#a2736611c9676822f8e948dc473f748f1">append_hex</a> (buffer, </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (c), </span><span class="doxyHighlightStringLiteral">"\\x"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">170</span><span class="doxyLineContent"><span class="doxyHighlight">                              2);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">171</span><span class="doxyLineContent"><span class="doxyHighlight">                }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">172</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">173</span><span class="doxyLineContent"><span class="doxyHighlight">                {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">174</span><span class="doxyLineContent"><span class="doxyHighlight">                  buffer.push_back (c);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">175</span><span class="doxyLineContent"><span class="doxyHighlight">                }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">176</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">177</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">178</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">179</span><span class="doxyLineContent"><span class="doxyHighlight">      buffer.push_back (</span><span class="doxyHighlightCharLiteral">'"'</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">180</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="#a2736611c9676822f8e948dc473f748f1">append_hex</a> and <a href="#a82575d5d4e13eb8c54fd209ab830cd7d">append_quoted</a>.</p>


<p>Referenced by <a href="#a82575d5d4e13eb8c54fd209ab830cd7d">append_quoted</a>.</p>

</div>
</div>

</div>

<hr/>

The documentation for this namespace was generated from the following file:

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
