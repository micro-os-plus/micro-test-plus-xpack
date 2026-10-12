---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-os-plus-micro-test-plus-utility-functions
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# Utility Functions

<p>Utility functions for advanced string handling in tests. <a href="#details">More...</a></p>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const char *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ga791f22f0c85b6436c9016821907b0653">extract_file_name</a> (const char *path) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Extracts the file name component from a full path. <a href="#ga791f22f0c85b6436c9016821907b0653">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#gaa2f0f4cff320a783ad2347c9ff3fc731">is_match</a> (std::string_view input, std::string_view pattern)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Check if a string matches a pattern with <span class="doxyComputerOutput">*</span> and <span class="doxyComputerOutput">?</span> wildcards. <a href="#gaa2f0f4cff320a783ad2347c9ff3fc731">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr T &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ga00ea8f3dfb7cb0ef39919065321cf62f">mut</a> (const T &amp;t) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Generic mutator to remove const qualification from a reference. <a href="#ga00ea8f3dfb7cb0ef39919065321cf62f">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T = std::string_view, class Delim_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">auto </td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ga1b860aa64be17658d1664de447e6e125">split</a> (T input, Delim_T delim) -&gt; std::vector&lt; T &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Split a string into a vector of sub-strings. <a href="#ga1b860aa64be17658d1664de447e6e125">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Utility functions for advanced string handling in tests.</p>


<p>These utilities simplify advanced string operations commonly required during test development. They support tasks such as partial string matching, splitting long strings for improved readability, and related manipulations that enhance the clarity and effectiveness of test code.</p>


<div class="doxySectionDef">

## Functions

### extract\_file\_name() {#ga791f22f0c85b6436c9016821907b0653}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const char * micro_os_plus::micro_test_plus::utility::extract_file_name (const char * path)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Extracts the file name component from a full path.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">path</td>
<td class="doxyParamItemDescription"><p>A null-terminated file path string.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A pointer to the first character of the file name within <span class="doxyComputerOutput">path</span>, or <span class="doxyComputerOutput">path</span> itself if no path separator (<span class="doxyComputerOutput">/</span> or <span class="doxyComputerOutput">\\endiskip</span>) is found.</p></dd>
</dl>


<p>The <span class="doxyComputerOutput"><a href="#ga791f22f0c85b6436c9016821907b0653">extract_file_name</a></span> function extracts the file name from a given file path, handling both Unix-style (<span class="doxyComputerOutput">/</span>) and Windows-style (<span class="doxyComputerOutput">\\endiskip</span>) path separators. It returns a pointer to the start of the file name within the input string, or the original string if no separators are found.</p>


<p>This utility is particularly useful for test reporting, allowing for concise display of file names without full paths.</p>


<dl class="doxySectionUser">
<dt>Example</dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* path = </span><span class="doxyHighlightStringLiteral">"/home/user/project/test.cpp"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* filename = <a href="#ga791f22f0c85b6436c9016821907b0653">utility::extract_file_name</a> (path);</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightComment">// filename now points to "test.cpp"</span></span></div>

</div>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/utility-cpp/#l00088">88</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/utility-cpp">utility.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga791f22f0c85b6436c9016821907b0653">88</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#ga791f22f0c85b6436c9016821907b0653">extract_file_name</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* path) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">89</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">90</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string_view sv{ path };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">91</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> pos = sv.find_last_of (</span><span class="doxyHighlightStringLiteral">"/\\"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">92</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (pos == std::string_view::npos)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">93</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">94</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> path; </span><span class="doxyHighlightComment">// No separators found, return original string.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">95</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">96</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> sv.substr (pos + 1).data ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">97</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#acfabd0e10d233ad305b6f4fc125a97f2">micro_os_plus::micro_test_plus::runner::initialise</a>.</p>

</div>
</div>

### is\_match() {#gaa2f0f4cff320a783ad2347c9ff3fc731}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::utility::is_match (std::string_view input, std::string_view pattern)</td>
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

<p>Check if a string matches a pattern with <span class="doxyComputerOutput">*</span> and <span class="doxyComputerOutput">?</span> wildcards.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">input</td>
<td class="doxyParamItemDescription"><p>The string view to be checked.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">pattern</td>
<td class="doxyParamItemDescription"><p>The string view containing the pattern to match.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p><span class="doxyComputerOutput">true</span> if the input string matches the pattern; otherwise, <span class="doxyComputerOutput">false</span>.</p></dd>
</dl>


<p>This function enables pattern-based string comparison for tests, supporting both exact matches and wildcard patterns. The pattern may include <span class="doxyComputerOutput">*</span> to match any sequence of characters (including an empty one) and <span class="doxyComputerOutput">?</span> to match any single character. This allows for flexible validation of string content in test assertions, accommodating variable or partially known values.</p>



:::warning
<p>The <span class="doxyComputerOutput">*</span> wildcard is handled via recursion with a linear loop, giving a worst-case complexity of <span class="doxyComputerOutput">O(n^k)</span>, for an input of length <span class="doxyComputerOutput">n</span> and a pattern with <span class="doxyComputerOutput">k</span> wildcards (e.g. a pattern such as <span class="doxyComputerOutput">"a*a*a*b"</span> against a long string of <span class="doxyComputerOutput">'a'</span> characters). For the typical short patterns used in a test framework this is not a concern, but callers should avoid patterns with many wildcards against long input strings.</p>
:::


<dl class="doxySectionUser">
<dt>Examples</dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight">mt = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">t.expect (mt::utility::is_match (</span><span class="doxyHighlightStringLiteral">"abc"</span><span class="doxyHighlight">, </span><span class="doxyHighlightStringLiteral">"a?c"</span><span class="doxyHighlight">)) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"abc matches a?c"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">t.expect (mt::utility::is_match (</span><span class="doxyHighlightStringLiteral">"abc"</span><span class="doxyHighlight">, </span><span class="doxyHighlightStringLiteral">"a*c"</span><span class="doxyHighlight">)) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"abc matches a*c"</span><span class="doxyHighlight">;</span></span></div>

</div>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/utility-cpp/#l00130">130</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/utility-cpp">utility.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gaa2f0f4cff320a783ad2347c9ff3fc731">130</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#gaa2f0f4cff320a783ad2347c9ff3fc731">is_match</a> (std::string_view input, std::string_view pattern)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">131</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">132</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (std::empty (pattern))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">133</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">134</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> std::empty (input);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">135</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">136</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">137</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (std::empty (input))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">138</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">139</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> pattern[0] == </span><span class="doxyHighlightCharLiteral">'*'</span><span class="doxyHighlight"> ? <a href="#gaa2f0f4cff320a783ad2347c9ff3fc731">is_match</a> (input, pattern.substr (1))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">140</span><span class="doxyLineContent"><span class="doxyHighlight">                                   : </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">141</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">142</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">143</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (pattern[0] != </span><span class="doxyHighlightCharLiteral">'?'</span><span class="doxyHighlight"> and pattern[0] != </span><span class="doxyHighlightCharLiteral">'*'</span><span class="doxyHighlight"> and pattern[0] != input[0])</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">144</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">145</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">146</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">147</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">148</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (pattern[0] == </span><span class="doxyHighlightCharLiteral">'*'</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">149</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">150</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">decltype</span><span class="doxyHighlight"> (std::size (input)) i = 0u; i &lt;= std::size (input);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">151</span><span class="doxyLineContent"><span class="doxyHighlight">               ++i)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">152</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">153</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#gaa2f0f4cff320a783ad2347c9ff3fc731">is_match</a> (input.substr (i), pattern.substr (1)))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">154</span><span class="doxyLineContent"><span class="doxyHighlight">                {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">155</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">156</span><span class="doxyLineContent"><span class="doxyHighlight">                }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">157</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">158</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">159</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">160</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">161</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#gaa2f0f4cff320a783ad2347c9ff3fc731">is_match</a> (input.substr (1), pattern.substr (1));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">162</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="#gaa2f0f4cff320a783ad2347c9ff3fc731">micro_os_plus::micro_test_plus::utility::is_match</a>.</p>


<p>Referenced by <a href="#gaa2f0f4cff320a783ad2347c9ff3fc731">micro_os_plus::micro_test_plus::utility::is_match</a>.</p>

</div>
</div>

### mut() {#ga00ea8f3dfb7cb0ef39919065321cf62f}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">T &amp; micro_os_plus::micro_test_plus::mut (const T &amp; t)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel constexpr">constexpr</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Generic mutator to remove const qualification from a reference.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The type of the input object.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">t</td>
<td class="doxyParamItemDescription"><p>The object from which to remove const qualification; it must not be an object originally declared as <span class="doxyComputerOutput">const</span>, if it is to be modified.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A non-const reference to the input object.</p></dd>
</dl>


<p>The <span class="doxyComputerOutput"><a href="#ga00ea8f3dfb7cb0ef39919065321cf62f">mut</a></span> function template provides a generic mechanism to remove the <span class="doxyComputerOutput">const</span> qualifier from a reference, via <span class="doxyComputerOutput">const_cast</span>. It returns a non-const reference to the input object, enabling modification of non-const objects accessed through a <span class="doxyComputerOutput">const</span> reference. This utility is particularly useful in testing scenarios where controlled mutation of test data is required.</p>



:::warning
<p>Modifying an object that was originally declared as <span class="doxyComputerOutput">const</span> through the returned reference is undefined behaviour.</p>
:::


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/function-comparators-inlines-h/#l00330">330</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/function-comparators-inlines-h">function-comparators-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga00ea8f3dfb7cb0ef39919065321cf62f">330</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ga00ea8f3dfb7cb0ef39919065321cf62f">mut</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; t) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight"> -&gt; T&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">331</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">332</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">const_cast&lt;</span><span class="doxyHighlight">T&amp;</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (t);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">333</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>

</div>
</div>

### split() {#ga1b860aa64be17658d1664de447e6e125}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T = std::string_view, class Delim_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::vector&lt; T &gt; micro_os_plus::micro_test_plus::utility::split (T input, Delim_T delim)</td>
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

<p>Split a string into a vector of sub-strings.</p>


<p>This function template facilitates string handling in tests by splitting a string into a vector of substrings, using the specified delimiter.</p>


<p>The function iterates through the input string, identifying the positions of any of the delimiter characters (via <span class="doxyComputerOutput">find_first_of()</span>) and extracting the substrings between them. Each non-empty substring is added to the output vector; empty substrings, such as those between consecutive delimiters, are omitted. This approach supports flexible parsing of delimited data, which is particularly useful for validating string processing logic in test cases.</p>


<p><b>Example</b></p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight">mt = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">t.expect (std::vector&lt;std::string_view&gt;{ </span><span class="doxyHighlightStringLiteral">"a"</span><span class="doxyHighlight">, </span><span class="doxyHighlightStringLiteral">"b"</span><span class="doxyHighlight"> }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">            == mt::utility::split&lt;std::string_view&gt; (</span><span class="doxyHighlightStringLiteral">"a.b"</span><span class="doxyHighlight">, </span><span class="doxyHighlightStringLiteral">"."</span><span class="doxyHighlight">))</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">        &lt;&lt; </span><span class="doxyHighlightStringLiteral">"a.b splits into [a,b]"</span><span class="doxyHighlight">;</span></span></div>

</div>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>Type of the input string.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Delim_T</td>
<td class="doxyParamItemDescription"><p>Type of the delimiter.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">input</td>
<td class="doxyParamItemDescription"><p>Input string to split.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">delim</td>
<td class="doxyParamItemDescription"><p>Delimiter characters; any of them separates sub-strings.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A vector containing the resulting sub-strings; empty sub-strings (e.g. between consecutive delimiters) are omitted.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/utility-inlines-h/#l00091">91</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/utility-inlines-h">utility-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga1b860aa64be17658d1664de447e6e125">91</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#ga1b860aa64be17658d1664de447e6e125">split</a> (T input, Delim_T delim) -&gt; std::vector&lt;T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">92</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">93</span><span class="doxyLineContent"><span class="doxyHighlight">      std::vector&lt;T&gt; output{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">94</span><span class="doxyLineContent"><span class="doxyHighlight">      std::size_t first{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">95</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">while</span><span class="doxyHighlight"> (first &lt; std::size (input))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">96</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">97</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> second = input.find_first_of (delim, first);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">98</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (first != second)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">99</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">100</span><span class="doxyLineContent"><span class="doxyHighlight">              output.emplace_back (input.substr (first, second - first));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">101</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">102</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (second == T::npos)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">103</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">104</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">105</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">106</span><span class="doxyLineContent"><span class="doxyHighlight">          first = second + 1;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">107</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">108</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> output;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">109</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>

</div>
</div>

</div>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.2 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
