---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/structs/micro-os-plus/micro-test-plus/detail/math/integer-literal
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - struct

---

<div class="doxyPage">

# `integer_literal` Struct

<p>The result of parsing the characters of an integer literal. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
struct micro_os_plus::micro_test_plus::detail::math::integer_literal { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include &lt;<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/math-h">math.h</a>&gt;
</div>

## Public Member Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ac09f666f846defca3cb8bd6e1b33c60e">is_integer</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Whether the characters form an integer literal. <a href="#ac09f666f846defca3cb8bd6e1b33c60e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a94438561fe06662519cf9687cc734fdb">is_too_large</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Whether the value exceeds <span class="doxyComputerOutput">unsigned long long</span>. <a href="#a94438561fe06662519cf9687cc734fdb">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">unsigned long long</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a79fda0403a1ee1c8fafecbab9e80c815">value</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The value of the literal. <a href="#a79fda0403a1ee1c8fafecbab9e80c815">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>The result of parsing the characters of an integer literal.</p>


<p>Returned by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/math/#a9292deab69ef8584bc2604e76316ecfd">parse_integer_literal()</a></span>; the checks of <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/math/#a4f5af9be6a23a49f942e72de92adc91e">integer_magnitude()</a></span> are based on it.</p>


<p>Definition at line 270 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/math-h">math.h</a>.</p>


<div class="doxySectionDef">

## Public Member Attributes

### is\_integer {#ac09f666f846defca3cb8bd6e1b33c60e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::detail::math::integer_literal::is_integer</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Whether the characters form an integer literal.</p>


<p>False for the floating-point literals (with a decimal point or an exponent), which the literal operator templates also receive.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/math-h/#l00287">287</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/math-h">math.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ac09f666f846defca3cb8bd6e1b33c60e">287</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="#ac09f666f846defca3cb8bd6e1b33c60e">is_integer</a>;</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/math/#a4f5af9be6a23a49f942e72de92adc91e">micro_os_plus::micro_test_plus::detail::math::integer_magnitude</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/math/#a9292deab69ef8584bc2604e76316ecfd">micro_os_plus::micro_test_plus::detail::math::parse_integer_literal</a>.</p>

</div>
</div>

### is\_too\_large {#a94438561fe06662519cf9687cc734fdb}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::detail::math::integer_literal::is_too_large</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Whether the value exceeds <span class="doxyComputerOutput">unsigned long long</span>.</p>


<p>Detected while the digits are accumulated.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/math-h/#l00295">295</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/math-h">math.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a94438561fe06662519cf9687cc734fdb">295</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="#a94438561fe06662519cf9687cc734fdb">is_too_large</a>;</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/math/#a4f5af9be6a23a49f942e72de92adc91e">micro_os_plus::micro_test_plus::detail::math::integer_magnitude</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/math/#a9292deab69ef8584bc2604e76316ecfd">micro_os_plus::micro_test_plus::detail::math::parse_integer_literal</a>.</p>

</div>
</div>

### value {#a79fda0403a1ee1c8fafecbab9e80c815}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">unsigned long long micro_os_plus::micro_test_plus::detail::math::integer_literal::value</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The value of the literal.</p>


<p>Valid only if <span class="doxyComputerOutput"><a href="#ac09f666f846defca3cb8bd6e1b33c60e">is_integer</a></span> is true and <span class="doxyComputerOutput"><a href="#a94438561fe06662519cf9687cc734fdb">is_too_large</a></span> is false.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/math-h/#l00278">278</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/math-h">math.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a79fda0403a1ee1c8fafecbab9e80c815">278</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> <a href="#a79fda0403a1ee1c8fafecbab9e80c815">value</a>;</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/math/#a4f5af9be6a23a49f942e72de92adc91e">micro_os_plus::micro_test_plus::detail::math::integer_magnitude</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/math/#a9292deab69ef8584bc2604e76316ecfd">micro_os_plus::micro_test_plus::detail::math::parse_integer_literal</a>.</p>

</div>
</div>

</div>

<hr/>

The documentation for this struct was generated from the following file:

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/math-h">math.h</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
