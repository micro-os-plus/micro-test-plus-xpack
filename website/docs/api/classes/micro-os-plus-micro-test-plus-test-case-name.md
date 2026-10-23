---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/classes/micro-os-plus/micro-test-plus/test-case-name
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - class

---

<div class="doxyPage">

# `test_case_name` Class

<p>The name of a test case, with the location of its definition. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
class micro_os_plus::micro_test_plus::test_case_name { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>"
</div>

## Public Constructors Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a86534273fcfac3a3edd7fbae2f04e5ea">test_case_name</a> (const char *name, const reflection::source_location &amp;location=reflection::source_location::current()) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructs the name from a C string, capturing the location of the caller. <a href="#a86534273fcfac3a3edd7fbae2f04e5ea">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ae590d4402a8065342fa591ff78b81797">test_case_name</a> (const std::string &amp;name, const reflection::source_location &amp;location=reflection::source_location::current()) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructs the name from a standard string, capturing the location of the caller. <a href="#ae590d4402a8065342fa591ff78b81797">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Member Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#abfb91a55df657bbfbfb5fe774f46329b">location</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Gets the location of the call to <span class="doxyComputerOutput">test()</span>. <a href="#abfb91a55df657bbfbfb5fe774f46329b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const char *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a624bdd72fd18db434a64993818bb5466">name</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Gets the test case name. <a href="#a624bdd72fd18db434a64993818bb5466">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Private Member Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ab9ecf89d495d71f224e182228eaec66e">location_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The location of the call to <span class="doxyComputerOutput">test()</span>. <a href="#ab9ecf89d495d71f224e182228eaec66e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const char *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a2941ef285834b5d22e0300238473e648">name_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The test case name. <a href="#a2941ef285834b5d22e0300238473e648">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>The name of a test case, with the location of its definition.</p>


<p>The first parameter of <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a402696dc4d4978ff3c050427890cfe01">suite::test()</a></span> and <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#aac23ee148d8e5946cd87e0de036e9fb8">test_case::test()</a></span>. The constructors are not explicit, so a string literal, a <span class="doxyComputerOutput">const char*</span>, or a <span class="doxyComputerOutput">std::string</span> passed as the test case name converts implicitly; the default argument of the constructors is evaluated at the place of the conversion, which is the call to <span class="doxyComputerOutput">test()</span> in the user code, so the location of the test case is captured without an additional argument (which could not follow the variadic arguments of <span class="doxyComputerOutput">test()</span>).</p>


<p>The location is used to report a failure that is not associated with a check, such as an exception escaping the test case body.</p>


<p>The name is not copied. Since the test cases run immediately, within the call to <span class="doxyComputerOutput">test()</span>, a temporary string passed as the argument, which lives until the end of the full expression, remains valid while the test case runs; a named <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name">test_case_name</a></span> object must not outlive the string it was constructed from.</p>


<p>A <span class="doxyComputerOutput">std::string_view</span> is not accepted, since it is not guaranteed to be null-terminated; pass <span class="doxyComputerOutput">std::string (sv)</span> instead.</p>


<p>Since a conversion sequence may include only one user-defined conversion, an argument that converts to <span class="doxyComputerOutput">const char*</span> or to <span class="doxyComputerOutput">std::string</span> via a user-defined conversion operator must be converted explicitly.</p>


<p>A helper function that adds test cases on behalf of its caller can take a <span class="doxyComputerOutput">const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name">test_case_name</a>&amp;</span> parameter and pass it to <span class="doxyComputerOutput">test()</span>, so that the reported location is that of the call to the helper, not that of the call to <span class="doxyComputerOutput">test()</span> inside the helper.</p>


<dl class="doxySectionUser">
<dt>Example</dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight">mt = micro_os_plus::micro_test_plus;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">check_answer (mt::suite&amp; ts, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> mt::test_case_name&amp; <a href="#a624bdd72fd18db434a64993818bb5466">name</a>, </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  ts.test (<a href="#a624bdd72fd18db434a64993818bb5466">name</a>, [v] (</span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; t) { t.expect (mt::eq (v, 42)); });</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">}</span></span></div>

</div>


<p>Definition at line 156 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<div class="doxySectionDef">

## Public Constructors

### test\_case\_name() {#a86534273fcfac3a3edd7fbae2f04e5ea}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::test_case_name::test_case_name (const char * name, const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> &amp; location=<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a>())</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Constructs the name from a C string, capturing the location of the caller.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">name</td>
<td class="doxyParamItemDescription"><p>The test case name or description, used in reports; it must remain valid while the test case runs.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">location</td>
<td class="doxyParamItemDescription"><p>The location of the conversion, defaulting to the call to <span class="doxyComputerOutput">test()</span> in the user code.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Stores the name pointer and the location; when called implicitly, the location is the place of the conversion, in the user code.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00168">168</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00100">100</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a86534273fcfac3a3edd7fbae2f04e5ea">100</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">inline</span><span class="doxyHighlight"> <a href="#a86534273fcfac3a3edd7fbae2f04e5ea">test_case_name::test_case_name</a> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">101</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* <a href="#a624bdd72fd18db434a64993818bb5466">name</a>, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; <a href="#abfb91a55df657bbfbfb5fe774f46329b">location</a>) noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">102</span><span class="doxyLineContent"><span class="doxyHighlight">      : <a href="#a2941ef285834b5d22e0300238473e648">name_</a>{ <a href="#a624bdd72fd18db434a64993818bb5466">name</a> }, location_{ location }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">103</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">104</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#abfb91a55df657bbfbfb5fe774f46329b">location</a>, <a href="#a624bdd72fd18db434a64993818bb5466">name</a> and <a href="#a2941ef285834b5d22e0300238473e648">name_</a>.</p>

</div>
</div>

### test\_case\_name() {#ae590d4402a8065342fa591ff78b81797}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::test_case_name::test_case_name (const std::string &amp; name, const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> &amp; location=<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a>())</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Constructs the name from a standard string, capturing the location of the caller.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">name</td>
<td class="doxyParamItemDescription"><p>The test case name or description, used in reports; it must remain valid, and not be modified, while the test case runs.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">location</td>
<td class="doxyParamItemDescription"><p>The location of the conversion, defaulting to the call to <span class="doxyComputerOutput">test()</span> in the user code.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Stores the pointer returned by <span class="doxyComputerOutput">name.c_str()</span>, which remains valid while the string is neither destroyed nor modified, and the location; when called implicitly, the location is the place of the conversion, in the user code.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00181">181</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00113">113</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ae590d4402a8065342fa591ff78b81797">113</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">inline</span><span class="doxyHighlight"> <a href="#a86534273fcfac3a3edd7fbae2f04e5ea">test_case_name::test_case_name</a> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">114</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string&amp; <a href="#a624bdd72fd18db434a64993818bb5466">name</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">115</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; <a href="#abfb91a55df657bbfbfb5fe774f46329b">location</a>) noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">116</span><span class="doxyLineContent"><span class="doxyHighlight">      : <a href="#a2941ef285834b5d22e0300238473e648">name_</a>{ <a href="#a624bdd72fd18db434a64993818bb5466">name</a>.c_str () }, location_{ location }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">117</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">118</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#abfb91a55df657bbfbfb5fe774f46329b">location</a>, <a href="#a624bdd72fd18db434a64993818bb5466">name</a> and <a href="#a2941ef285834b5d22e0300238473e648">name_</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Member Functions

### location() {#abfb91a55df657bbfbfb5fe774f46329b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const reflection::source_location &amp; micro_os_plus::micro_test_plus::test_case_name::location (void)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Gets the location of the call to <span class="doxyComputerOutput">test()</span>.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A reference to the stored source location.</p></dd>
</dl>


<p>Returns a reference to the location stored in <span class="doxyComputerOutput"><a href="#ab9ecf89d495d71f224e182228eaec66e">location_</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00203">203</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00135">135</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#abfb91a55df657bbfbfb5fe774f46329b">135</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#abfb91a55df657bbfbfb5fe774f46329b">test_case_name::location</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">136</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">137</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#ab9ecf89d495d71f224e182228eaec66e">location_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">138</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#ab9ecf89d495d71f224e182228eaec66e">location_</a>.</p>


<p>Referenced by <a href="#a86534273fcfac3a3edd7fbae2f04e5ea">test_case_name</a>, <a href="#ae590d4402a8065342fa591ff78b81797">test_case_name</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#acb0858a0ba8b635ff89c4cb00c532ce8">micro_os_plus::micro_test_plus::detail::test_each_value</a>.</p>

</div>
</div>

### name() {#a624bdd72fd18db434a64993818bb5466}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const char * micro_os_plus::micro_test_plus::test_case_name::name (void)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Gets the test case name.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A pointer to the null-terminated test case name.</p></dd>
</dl>


<p>Returns the pointer stored in <span class="doxyComputerOutput"><a href="#a2941ef285834b5d22e0300238473e648">name_</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00193">193</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00125">125</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a624bdd72fd18db434a64993818bb5466">125</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a624bdd72fd18db434a64993818bb5466">test_case_name::name</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">126</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">127</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a2941ef285834b5d22e0300238473e648">name_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">128</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a2941ef285834b5d22e0300238473e648">name_</a>.</p>


<p>Referenced by <a href="#a86534273fcfac3a3edd7fbae2f04e5ea">test_case_name</a>, <a href="#ae590d4402a8065342fa591ff78b81797">test_case_name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a402696dc4d4978ff3c050427890cfe01">micro_os_plus::micro_test_plus::suite::test</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#aac23ee148d8e5946cd87e0de036e9fb8">micro_os_plus::micro_test_plus::test_case::test</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#acb0858a0ba8b635ff89c4cb00c532ce8">micro_os_plus::micro_test_plus::detail::test_each_value</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Private Member Attributes

### location\_ {#ab9ecf89d495d71f224e182228eaec66e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">reflection::source_location micro_os_plus::micro_test_plus::test_case_name::location_</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The location of the call to <span class="doxyComputerOutput">test()</span>.</p>


<p>Captured by the default argument of the constructor, at the place of the conversion to <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name">test_case_name</a></span>.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00221">221</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ab9ecf89d495d71f224e182228eaec66e">221</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> <a href="#ab9ecf89d495d71f224e182228eaec66e">location_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#abfb91a55df657bbfbfb5fe774f46329b">location</a>.</p>

</div>
</div>

### name\_ {#a2941ef285834b5d22e0300238473e648}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const char* micro_os_plus::micro_test_plus::test_case_name::name_</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The test case name.</p>


<p>Not owned; test cases run immediately, while the name is valid.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00212">212</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a2941ef285834b5d22e0300238473e648">212</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* <a href="#a2941ef285834b5d22e0300238473e648">name_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#a86534273fcfac3a3edd7fbae2f04e5ea">test_case_name</a>, <a href="#ae590d4402a8065342fa591ff78b81797">test_case_name</a> and <a href="#a624bdd72fd18db434a64993818bb5466">name</a>.</p>

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
