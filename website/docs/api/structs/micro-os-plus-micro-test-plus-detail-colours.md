---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/structs/micro-os-plus/micro-test-plus/detail/colours
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - struct

---

<div class="doxyPage">

# `colours` Struct

<p>Colours used to highlight pass and fail results in test reports. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
struct micro_os_plus::micro_test_plus::detail::colours { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include &lt;<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>&gt;
</div>

## Public Member Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const char *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a7cd442bbb5af0f5d53632101d5c2eb0b">fail</a> = ""</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Terminal colour sequence for failing tests. <a href="#a7cd442bbb5af0f5d53632101d5c2eb0b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const char *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a42937839aa8c23e1c5482582eaf2aeb7">none</a> = ""</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Terminal colour reset sequence. <a href="#a42937839aa8c23e1c5482582eaf2aeb7">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const char *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ac3953ba58fbf322bd310c857844d17fe">pass</a> = ""</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Terminal colour sequence for passing tests. <a href="#ac3953ba58fbf322bd310c857844d17fe">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Colours used to highlight pass and fail results in test reports.</p>


<p>The <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a></span> structure defines ANSI escape sequences for terminal output, enabling colour-coded highlighting of test outcomes. The <span class="doxyComputerOutput"><a href="#ac3953ba58fbf322bd310c857844d17fe">pass</a></span> member specifies the colour for successful results (typically green), while the <span class="doxyComputerOutput"><a href="#a7cd442bbb5af0f5d53632101d5c2eb0b">fail</a></span> member specifies the colour for failed results (typically red). The <span class="doxyComputerOutput"><a href="#a42937839aa8c23e1c5482582eaf2aeb7">none</a></span> member resets the colour to the terminal default.</p>


<p>By default all members are empty strings, so no escape sequences are emitted; reporters that support colours assign <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ad59e204218aa41581652a072be0e8a8a">colours_red_green</a></span>.</p>


<p>Definition at line 132 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>.</p>


<div class="doxySectionDef">

## Public Member Attributes

### fail {#a7cd442bbb5af0f5d53632101d5c2eb0b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const char* micro_os_plus::micro_test_plus::detail::colours::fail = ""</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Terminal colour sequence for failing tests.</p>


<p>ANSI escape sequence to set the terminal colour for failing results (red).</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00137">137</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">138</span><span class="doxyLineContent"><span class="doxyHighlight">          = </span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight">; </span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a66f620b093f92e0def6bf5297fb6d6ee">micro_os_plus::micro_test_plus::detail::reporter_human::abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a2440544fb5674da8853708f9af9ccc14">micro_os_plus::micro_test_plus::detail::expression_formatter::colour</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ace9c2dfffc49a97516b96dacaf87b943">micro_os_plus::micro_test_plus::detail::reporter_human::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#afd98d9a322823d67448d4ba301846392">micro_os_plus::micro_test_plus::detail::reporter_human::fail_suite</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a032be7e38aad40c8bc44b2376ad90e29">micro_os_plus::micro_test_plus::detail::reporter_human::output_fail_prefix</a>.</p>

</div>
</div>

### none {#a42937839aa8c23e1c5482582eaf2aeb7}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const char* micro_os_plus::micro_test_plus::detail::colours::none = ""</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Terminal colour reset sequence.</p>


<p>ANSI escape sequence to reset the terminal colour to default.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00134">134</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a42937839aa8c23e1c5482582eaf2aeb7">134</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* <a href="#a42937839aa8c23e1c5482582eaf2aeb7">none</a> = </span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight">; </span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a66f620b093f92e0def6bf5297fb6d6ee">micro_os_plus::micro_test_plus::detail::reporter_human::abort_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ace9c2dfffc49a97516b96dacaf87b943">micro_os_plus::micro_test_plus::detail::reporter_human::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#afd98d9a322823d67448d4ba301846392">micro_os_plus::micro_test_plus::detail::reporter_human::fail_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#ac7bb8541495fe98975132f546f5529bc">micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a7dbef1dcdbb8e4187ec4f28b41ed32fc">micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a91cd5a527853b70e7523e3180cb883f0">micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a69d49647528979d6927386cfb4ba29ec">micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a0ffe9183360b8f7e674f8546888ec5cc">micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a5a5535dbaa45481b3b6f74186d43152e">micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#af68e85825621bce88f656ced9be5396e">micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a6734ab254c188ce23514b5e84dd1232f">micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a032be7e38aad40c8bc44b2376ad90e29">micro_os_plus::micro_test_plus::detail::reporter_human::output_fail_prefix</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a043919044274838f8030d53630e3b1f5">micro_os_plus::micro_test_plus::detail::reporter_human::output_pass_prefix</a>.</p>

</div>
</div>

### pass {#ac3953ba58fbf322bd310c857844d17fe}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const char* micro_os_plus::micro_test_plus::detail::colours::pass = ""</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Terminal colour sequence for passing tests.</p>


<p>ANSI escape sequence to set the terminal colour for passing results (green).</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00135">135</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">136</span><span class="doxyLineContent"><span class="doxyHighlight">          = </span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight">; </span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a2440544fb5674da8853708f9af9ccc14">micro_os_plus::micro_test_plus::detail::expression_formatter::colour</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ace9c2dfffc49a97516b96dacaf87b943">micro_os_plus::micro_test_plus::detail::reporter_human::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af8dc976373fc0976c8486693d9b9f835">micro_os_plus::micro_test_plus::detail::reporter_human::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a043919044274838f8030d53630e3b1f5">micro_os_plus::micro_test_plus::detail::reporter_human::output_pass_prefix</a>.</p>

</div>
</div>

</div>

<hr/>

The documentation for this struct was generated from the following file:

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
