---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/files/include/micro-os-plus/micro-test-plus/literals-h
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - file

---

<div class="doxyPage">

# `literals.h` File

<p>C++ header file with declarations for the µTest++ user-defined literals and type wrappers. <a href="#details">More...</a></p>

## Included Headers

<div class="doxyIncludesList">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/type-traits-h">type-traits.h</a>"
#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/math-h">math.h</a>"
#include &lt;cstdint&gt;
#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/literals-inlines-h">inlines/literals-inlines.h</a>"
</div>

## Namespaces Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">namespace</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus">micro_os_plus</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The primary namespace for the µOS++ framework. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">namespace</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_test_plus</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Primary namespace for the µTest++ testing framework. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">namespace</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/literals">literals</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literals and type wrappers for the µTest++ testing framework. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/literals/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Classes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">struct</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/-t">_t&lt;T&gt;</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deprecated generic strongly-typed wrapper for explicit type conversion. <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/-t/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">struct</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/to-t">to_t&lt;T&gt;</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Generic strongly-typed wrapper for explicit type conversion. <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/to-t/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Operators Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaa2bfc74376f8c110053bfa6e06e40772">operator""_b</a> (const char *name, decltype(sizeof("")) size)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">bool</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaa2bfc74376f8c110053bfa6e06e40772">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gae521cebfd48332f44d01e4f880b4aafa">operator""_c</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">char</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gae521cebfd48332f44d01e4f880b4aafa">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9d9b0d77e96cc46e7c9fabbb6cf671da">operator""_d</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">double</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9d9b0d77e96cc46e7c9fabbb6cf671da">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gab9d0b5fe567e9ea4b2cf4e7edd6ec2ef">operator""_f</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">float</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gab9d0b5fe567e9ea4b2cf4e7edd6ec2ef">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga366a0d47aec3241e659816067c94fcdf">operator""_i</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">int</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga366a0d47aec3241e659816067c94fcdf">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gabce6e838737bf25be6e7527f69e75590">operator""_i16</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">int16_t</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gabce6e838737bf25be6e7527f69e75590">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6a192d3dfff5a4a98aa7532d36d1b1bd">operator""_i32</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">int32_t</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6a192d3dfff5a4a98aa7532d36d1b1bd">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gab0bb5d1e37cbe8de6477c11ecd60956d">operator""_i64</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">int64_t</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gab0bb5d1e37cbe8de6477c11ecd60956d">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9ca6fecc72b6da90acee52977eb077d7">operator""_i8</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">int8_t</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9ca6fecc72b6da90acee52977eb077d7">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga96e891b439024e116cb845bc65bc9c4f">operator""_l</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">long</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga96e891b439024e116cb845bc65bc9c4f">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaecd8c981d99602a0d0a44ebf6d1d4f75">operator""_ld</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">long double</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaecd8c981d99602a0d0a44ebf6d1d4f75">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaf5ab66b00c9486ade5d49f34a83783f5">operator""_ll</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">long long</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaf5ab66b00c9486ade5d49f34a83783f5">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga812816a2e9b23de1f8d8b2d86553d96d">operator""_s</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">short</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga812816a2e9b23de1f8d8b2d86553d96d">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga57d27f1a76de2d2b2a067134cbe61457">operator""_sc</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">signed char</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga57d27f1a76de2d2b2a067134cbe61457">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaf45bf641153a462a1ba7c12b908e667f">operator""_u</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">unsigned</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaf45bf641153a462a1ba7c12b908e667f">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga96d12d563093f297a73a8b984ae7a3a5">operator""_u16</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">uint16_t</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga96d12d563093f297a73a8b984ae7a3a5">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga3171e605b5c2e1d9a0e55ae34e904674">operator""_u32</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">uint32_t</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga3171e605b5c2e1d9a0e55ae34e904674">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga622b4808b7ebfc26ddf9db9128533f28">operator""_u64</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">uint64_t</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga622b4808b7ebfc26ddf9db9128533f28">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga80f43260f6a1afd8260355136858df48">operator""_u8</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">uint8_t</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga80f43260f6a1afd8260355136858df48">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6c1b46d4b967bdbc573e3192c2d9f98a">operator""_uc</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">unsigned char</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6c1b46d4b967bdbc573e3192c2d9f98a">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaef96b19b140b5007ec33a944c3b72cae">operator""_ul</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">unsigned long</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaef96b19b140b5007ec33a944c3b72cae">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga01adcd3866da43c393b7fba8a5e72bb2">operator""_ull</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">unsigned long long</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga01adcd3866da43c393b7fba8a5e72bb2">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;char... Cs&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9017debdc1eafd64e3c53c80157ad6f5">operator""_us</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">unsigned short</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9017debdc1eafd64e3c53c80157ad6f5">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Deprecated Type Wrappers Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga74e6e2bffc2fc2dea47f979b5b55ea64">_b</a> = type_traits::value&lt; bool &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">bool</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga74e6e2bffc2fc2dea47f979b5b55ea64">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gabd2f8b7401162835cb4735e4a7532c36">_c</a> = type_traits::value&lt; char &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">char</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gabd2f8b7401162835cb4735e4a7532c36">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6ab8b464d71f15f55bd047dbfca50899">_d</a> = type_traits::value&lt; double &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">double</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6ab8b464d71f15f55bd047dbfca50899">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gadcff4454bf86ea03c0c3d1be42b04e12">_f</a> = type_traits::value&lt; float &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">float</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gadcff4454bf86ea03c0c3d1be42b04e12">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga1613ccf081248c601bed0f3022fba652">_i</a> = type_traits::value&lt; int &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">int</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga1613ccf081248c601bed0f3022fba652">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaec10ef24cb02dd0fb7f5e44227562d51">_i16</a> = type_traits::value&lt; std::int16_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::int16_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaec10ef24cb02dd0fb7f5e44227562d51">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga5d6deb61637f1d7350a69f62d2971bc3">_i32</a> = type_traits::value&lt; std::int32_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::int32_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga5d6deb61637f1d7350a69f62d2971bc3">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gae98aa89157544638f775d2a90a3ec774">_i64</a> = type_traits::value&lt; std::int64_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::int64_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gae98aa89157544638f775d2a90a3ec774">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga3cb44c2b09802fbee17f324cbdf3f31e">_i8</a> = type_traits::value&lt; std::int8_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::int8_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga3cb44c2b09802fbee17f324cbdf3f31e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaaebf2b13e1742a894179deedf8ad82cc">_l</a> = type_traits::value&lt; long &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">long</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaaebf2b13e1742a894179deedf8ad82cc">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga79572e6e73076a155927ff0c3888ce76">_ld</a> = type_traits::value&lt; long double &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">long double</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga79572e6e73076a155927ff0c3888ce76">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6b000cfa2a8a4c8b04cf6d6f142a76a6">_ll</a> = type_traits::value&lt; long long &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">long long</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6b000cfa2a8a4c8b04cf6d6f142a76a6">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga102b1f7c41452481e6be2bd8da63e4a0">_s</a> = type_traits::value&lt; short &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">short</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga102b1f7c41452481e6be2bd8da63e4a0">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gacf10cd5dca8066e1df77e668b68f3272">_sc</a> = type_traits::value&lt; signed char &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">signed char</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gacf10cd5dca8066e1df77e668b68f3272">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga74b4ecee40263c6b4ac8a60fc6480fac">_u</a> = type_traits::value&lt; unsigned &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">unsigned</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga74b4ecee40263c6b4ac8a60fc6480fac">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga07f83438e4c0c85efdeacd78668f3543">_u16</a> = type_traits::value&lt; std::uint16_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::uint16_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga07f83438e4c0c85efdeacd78668f3543">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaf66382b299dcf814298ae56b75b541d7">_u32</a> = type_traits::value&lt; std::uint32_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::uint32_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaf66382b299dcf814298ae56b75b541d7">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gac654508c2894db262cbd0335f76b02bf">_u64</a> = type_traits::value&lt; std::uint64_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::uint64_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gac654508c2894db262cbd0335f76b02bf">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga2e2ad62d8c5d6e3abcfca9a897ae61de">_u8</a> = type_traits::value&lt; std::uint8_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::uint8_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga2e2ad62d8c5d6e3abcfca9a897ae61de">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga1ef97880cc5f2e13eea8b4ebb888886a">_uc</a> = type_traits::value&lt; unsigned char &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">unsigned char</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga1ef97880cc5f2e13eea8b4ebb888886a">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9cb69b5dc7c394a57e1b09c919b0f6ab">_ul</a> = type_traits::value&lt; unsigned long &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">unsigned long</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9cb69b5dc7c394a57e1b09c919b0f6ab">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga0b9d74a6595fe7fdefca21255ab59dc8">_ull</a> = type_traits::value&lt; unsigned long long &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">unsigned long long</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga0b9d74a6595fe7fdefca21255ab59dc8">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga67992fcc21a60e3dd1fb4c9c5ebc814a">_us</a> = type_traits::value&lt; unsigned short &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">unsigned short</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga67992fcc21a60e3dd1fb4c9c5ebc814a">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Type Wrappers Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6bdfe5c187140ee99d0bcabd5bb65156">to_b</a> = type_traits::value&lt; bool &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">bool</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6bdfe5c187140ee99d0bcabd5bb65156">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga5d14217f53925b323f4236298e3dcc90">to_c</a> = type_traits::value&lt; char &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">char</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga5d14217f53925b323f4236298e3dcc90">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga3b9d6825aa201bf1fdf9cbe8c0ad4bff">to_d</a> = type_traits::value&lt; double &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">double</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga3b9d6825aa201bf1fdf9cbe8c0ad4bff">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga3c89dfb65d916dfc34dfdfcb10334b5c">to_f</a> = type_traits::value&lt; float &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">float</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga3c89dfb65d916dfc34dfdfcb10334b5c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gab6ddb21470182cbdcf06436cde43718f">to_i</a> = type_traits::value&lt; int &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">int</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gab6ddb21470182cbdcf06436cde43718f">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaf22a7774a4b05de9779d9084ed41a02a">to_i16</a> = type_traits::value&lt; std::int16_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::int16_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaf22a7774a4b05de9779d9084ed41a02a">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9ca96b6c6d79560f8186c6206ac4f613">to_i32</a> = type_traits::value&lt; std::int32_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::int32_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9ca96b6c6d79560f8186c6206ac4f613">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga240591501696d181e105529c1f52b56c">to_i64</a> = type_traits::value&lt; std::int64_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::int64_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga240591501696d181e105529c1f52b56c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaa61c255757e915cb05132602baea088b">to_i8</a> = type_traits::value&lt; std::int8_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::int8_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaa61c255757e915cb05132602baea088b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaaf580ebebfba7cbe84a89db8574a6aa7">to_l</a> = type_traits::value&lt; long &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">long</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaaf580ebebfba7cbe84a89db8574a6aa7">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga33a096960b5dddee322e36c689ecbf47">to_ld</a> = type_traits::value&lt; long double &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">long double</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga33a096960b5dddee322e36c689ecbf47">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gab9d11644d3b22e2a9932e64853b5a59d">to_ll</a> = type_traits::value&lt; long long &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">long long</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gab9d11644d3b22e2a9932e64853b5a59d">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga1b39571aeebcb8091bd410a9b247a571">to_s</a> = type_traits::value&lt; short &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">short</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga1b39571aeebcb8091bd410a9b247a571">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gadb22be8fe019b5cd1ad56cfadea5f4ec">to_sc</a> = type_traits::value&lt; signed char &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">signed char</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gadb22be8fe019b5cd1ad56cfadea5f4ec">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gac8586b75498097cb06b404399c307960">to_u</a> = type_traits::value&lt; unsigned &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">unsigned</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gac8586b75498097cb06b404399c307960">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaa60006a01aa94a5fd755aebddd8ceec3">to_u16</a> = type_traits::value&lt; std::uint16_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::uint16_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaa60006a01aa94a5fd755aebddd8ceec3">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga3bf9f9c946f16b5e02f9f2c45739df42">to_u32</a> = type_traits::value&lt; std::uint32_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::uint32_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga3bf9f9c946f16b5e02f9f2c45739df42">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga5fba6fbb12941113aeff430609839ba4">to_u64</a> = type_traits::value&lt; std::uint64_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::uint64_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga5fba6fbb12941113aeff430609839ba4">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga8b683d809d600f5c5210bb16546a832e">to_u8</a> = type_traits::value&lt; std::uint8_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::uint8_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga8b683d809d600f5c5210bb16546a832e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9b60956f6c874e5597cdea6c0323fff1">to_uc</a> = type_traits::value&lt; unsigned char &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">unsigned char</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9b60956f6c874e5597cdea6c0323fff1">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9f6f56950ba8bce6cc49037af83e443b">to_ul</a> = type_traits::value&lt; unsigned long &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">unsigned long</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9f6f56950ba8bce6cc49037af83e443b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga595258f3c1b293284f79a88b2872d43d">to_ull</a> = type_traits::value&lt; unsigned long long &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">unsigned long long</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga595258f3c1b293284f79a88b2872d43d">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gac9a34848b05859a18794ece696e37f26">to_us</a> = type_traits::value&lt; unsigned short &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">unsigned short</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gac9a34848b05859a18794ece696e37f26">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>C++ header file with declarations for the µTest++ user-defined literals and type wrappers.</p>


<p>This header provides the declarations for the user-defined literal operators and type wrappers used within the µTest++ framework. It defines interfaces for generating strongly-typed integral, floating-point, and boolean constants at compile time, enabling expressive and type-safe test expressions.</p>


<p>The declared literal operators support a wide range of C++ fundamental types, allowing constants to be suffixed with type-specific identifiers (such as <span class="doxyComputerOutput">_i</span>, <span class="doxyComputerOutput">_u16</span>, <span class="doxyComputerOutput">_f</span>, <span class="doxyComputerOutput">_d</span>, <span class="doxyComputerOutput">_b</span>, etc.) to produce values that integrate seamlessly with the µTest++ comparators and reporting mechanisms.</p>


<p>In addition to literal operators, this header declares both deprecated and modern type wrappers for explicit type conversion, supporting enhanced clarity and type safety in test conditions. The preferred <span class="doxyComputerOutput">to_*</span> forms are recommended for new code, while the older <span class="doxyComputerOutput">_i</span>, <span class="doxyComputerOutput">_u8</span>, etc. aliases are retained for backwards compatibility.</p>


<p>All definitions reside within the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/literals">micro_os_plus::micro_test_plus::literals</a></span> namespace, ensuring clear separation from user code and minimising the risk of naming conflicts.</p>


<p>The header files are organised within the <span class="doxyComputerOutput">include/micro-os-plus/micro-test-plus</span> folder to maintain a structured and modular codebase.</p>


<p>This file is intended for internal use within the framework and should not be included directly by user code.</p>


## File Listing

The file content with the documentation metadata removed is:

<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00001"></a>1</span><span class="doxyLineContent"><span class="doxyHighlightComment">/*</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00002"></a>2</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * This file is part of the µOS++ project (https://micro-os-plus.github.io/).</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00003"></a>3</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * Copyright (c) 2021-2026 Liviu Ionescu. All rights reserved.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00004"></a>4</span><span class="doxyLineContent"><span class="doxyHighlightComment"> *</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00005"></a>5</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * Permission to use, copy, modify, and/or distribute this software for any</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00006"></a>6</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * purpose is hereby granted, under the terms of the MIT license.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00007"></a>7</span><span class="doxyLineContent"><span class="doxyHighlightComment"> *</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00008"></a>8</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * If a copy of the license was not distributed with this file, it can be</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00009"></a>9</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * obtained from https://opensource.org/licenses/mit.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00010"></a>10</span><span class="doxyLineContent"><span class="doxyHighlightComment"> *</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00011"></a>11</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * Major parts of the code are inspired from v1.1.8 of the Boost UT project,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00012"></a>12</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * released under the terms of the Boost Version 1 Software License,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00013"></a>13</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * which can be obtained from https://www.boost.org/LICENSE_1_0.txt.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00014"></a>14</span><span class="doxyLineContent"><span class="doxyHighlightComment"> */</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00015"></a>15</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00016"></a>16</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00017"></a>17</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00052"></a>52</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00053"></a>53</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_LITERALS_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00054"></a>54</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#define MICRO_OS_PLUS_MICRO_TEST_PLUS_LITERALS_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00055"></a>55</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00056"></a>56</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00057"></a>57</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00058"></a>58</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__cplusplus)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00059"></a>59</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00060"></a>60</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00061"></a>61</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00062"></a>62</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if __has_include("micro-os-plus/project-config.h")</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00063"></a>63</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "micro-os-plus/project-config.h"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00064"></a>64</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// __has_include("micro-os-plus/project-config.h")</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00065"></a>65</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00066"></a>66</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if __has_include("micro-os-plus/micro-test-plus-defines.h")</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00067"></a>67</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "micro-os-plus/micro-test-plus-defines.h"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00068"></a>68</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// __has_include("micro-os-plus/micro-test-plus-defines.h")</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00069"></a>69</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00070"></a>70</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/type-traits-h">type-traits.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00071"></a>71</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/math-h">math.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00072"></a>72</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00073"></a>73</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;cstdint&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00074"></a>74</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00075"></a>75</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00076"></a>76</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00077"></a>77</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00078"></a>78</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00079"></a>79</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Waggregate-return"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00080"></a>80</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00081"></a>81</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wc++98-compat"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00082"></a>82</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00083"></a>83</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00084"></a>84</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00085"></a>85</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00086"></a>86</span><span class="doxyLineContent"><span class="doxyHighlightComment">// =============================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00087"></a>87</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00088"></a>88</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00089"></a>89</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00090"></a>90</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00091"></a>91</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00117"></a>117</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/literals">literals</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00118"></a>118</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00129"></a>129</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00130"></a>130</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00131"></a>131</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga1613ccf081248c601bed0f3022fba652">_i</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00132"></a>132</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00143"></a>143</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00144"></a>144</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00145"></a>145</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga102b1f7c41452481e6be2bd8da63e4a0">_s</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00146"></a>146</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00157"></a>157</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00158"></a>158</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00159"></a>159</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gabd2f8b7401162835cb4735e4a7532c36">_c</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00160"></a>160</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00171"></a>171</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00172"></a>172</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00173"></a>173</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gacf10cd5dca8066e1df77e668b68f3272">_sc</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00174"></a>174</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00185"></a>185</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00186"></a>186</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00187"></a>187</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaaebf2b13e1742a894179deedf8ad82cc">_l</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00188"></a>188</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00199"></a>199</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00200"></a>200</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00201"></a>201</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6b000cfa2a8a4c8b04cf6d6f142a76a6">_ll</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00202"></a>202</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00213"></a>213</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00214"></a>214</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00215"></a>215</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga74b4ecee40263c6b4ac8a60fc6480fac">_u</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00216"></a>216</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00227"></a>227</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00228"></a>228</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00229"></a>229</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga1ef97880cc5f2e13eea8b4ebb888886a">_uc</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00230"></a>230</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00241"></a>241</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00242"></a>242</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00243"></a>243</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga67992fcc21a60e3dd1fb4c9c5ebc814a">_us</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00244"></a>244</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00255"></a>255</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00256"></a>256</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00257"></a>257</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9cb69b5dc7c394a57e1b09c919b0f6ab">_ul</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00258"></a>258</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00269"></a>269</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00270"></a>270</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00271"></a>271</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga0b9d74a6595fe7fdefca21255ab59dc8">_ull</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00272"></a>272</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00283"></a>283</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00284"></a>284</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00285"></a>285</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga3cb44c2b09802fbee17f324cbdf3f31e">_i8</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00286"></a>286</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00297"></a>297</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00298"></a>298</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00299"></a>299</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaec10ef24cb02dd0fb7f5e44227562d51">_i16</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00300"></a>300</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00311"></a>311</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00312"></a>312</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00313"></a>313</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga5d6deb61637f1d7350a69f62d2971bc3">_i32</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00314"></a>314</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00325"></a>325</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00326"></a>326</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00327"></a>327</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gae98aa89157544638f775d2a90a3ec774">_i64</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00328"></a>328</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00339"></a>339</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00340"></a>340</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00341"></a>341</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga2e2ad62d8c5d6e3abcfca9a897ae61de">_u8</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00342"></a>342</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00353"></a>353</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00354"></a>354</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00355"></a>355</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga07f83438e4c0c85efdeacd78668f3543">_u16</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00356"></a>356</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00367"></a>367</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00368"></a>368</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00369"></a>369</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaf66382b299dcf814298ae56b75b541d7">_u32</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00370"></a>370</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00381"></a>381</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00382"></a>382</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00383"></a>383</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gac654508c2894db262cbd0335f76b02bf">_u64</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00384"></a>384</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00395"></a>395</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00396"></a>396</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00397"></a>397</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gadcff4454bf86ea03c0c3d1be42b04e12">_f</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00398"></a>398</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00409"></a>409</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00410"></a>410</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00411"></a>411</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6ab8b464d71f15f55bd047dbfca50899">_d</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00412"></a>412</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00423"></a>423</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00424"></a>424</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00425"></a>425</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga79572e6e73076a155927ff0c3888ce76">_ld</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00426"></a>426</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00436"></a>436</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00437"></a>437</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga74e6e2bffc2fc2dea47f979b5b55ea64">_b</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* name, </span><span class="doxyHighlightKeyword">decltype</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight">)) size);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00438"></a>438</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00439"></a>439</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00440"></a>440</span><span class="doxyLineContent"><span class="doxyHighlight">  } </span><span class="doxyHighlightComment">// namespace literals</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00441"></a>441</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00442"></a>442</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00443"></a>443</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00444"></a>444</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00445"></a>445</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00446"></a>446</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00447"></a>447</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wdocumentation-deprecated-sync"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00448"></a>448</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00449"></a>449</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00450"></a>450</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00455"></a>455</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00472"></a>472</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00478"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga74e6e2bffc2fc2dea47f979b5b55ea64">478</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga74e6e2bffc2fc2dea47f979b5b55ea64">_b</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;bool&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00479"></a>479</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00485"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gabd2f8b7401162835cb4735e4a7532c36">485</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gabd2f8b7401162835cb4735e4a7532c36">_c</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;char&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00486"></a>486</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00492"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gacf10cd5dca8066e1df77e668b68f3272">492</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gacf10cd5dca8066e1df77e668b68f3272">_sc</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;signed char&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00493"></a>493</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00499"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga102b1f7c41452481e6be2bd8da63e4a0">499</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga102b1f7c41452481e6be2bd8da63e4a0">_s</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;short&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00500"></a>500</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00506"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga1613ccf081248c601bed0f3022fba652">506</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga1613ccf081248c601bed0f3022fba652">_i</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;int&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00507"></a>507</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00513"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaaebf2b13e1742a894179deedf8ad82cc">513</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaaebf2b13e1742a894179deedf8ad82cc">_l</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;long&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00514"></a>514</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00520"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6b000cfa2a8a4c8b04cf6d6f142a76a6">520</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6b000cfa2a8a4c8b04cf6d6f142a76a6">_ll</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;long long&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00521"></a>521</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00527"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga74b4ecee40263c6b4ac8a60fc6480fac">527</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga74b4ecee40263c6b4ac8a60fc6480fac">_u</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;unsigned&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00528"></a>528</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00534"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga1ef97880cc5f2e13eea8b4ebb888886a">534</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga1ef97880cc5f2e13eea8b4ebb888886a">_uc</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;unsigned char&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00535"></a>535</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00541"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga67992fcc21a60e3dd1fb4c9c5ebc814a">541</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga67992fcc21a60e3dd1fb4c9c5ebc814a">_us</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;unsigned short&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00542"></a>542</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00548"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9cb69b5dc7c394a57e1b09c919b0f6ab">548</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9cb69b5dc7c394a57e1b09c919b0f6ab">_ul</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;unsigned long&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00549"></a>549</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00555"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga0b9d74a6595fe7fdefca21255ab59dc8">555</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga0b9d74a6595fe7fdefca21255ab59dc8">_ull</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;unsigned long long&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00556"></a>556</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00562"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga3cb44c2b09802fbee17f324cbdf3f31e">562</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga3cb44c2b09802fbee17f324cbdf3f31e">_i8</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::int8_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00563"></a>563</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00569"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaec10ef24cb02dd0fb7f5e44227562d51">569</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaec10ef24cb02dd0fb7f5e44227562d51">_i16</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::int16_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00570"></a>570</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00576"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga5d6deb61637f1d7350a69f62d2971bc3">576</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga5d6deb61637f1d7350a69f62d2971bc3">_i32</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::int32_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00577"></a>577</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00583"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gae98aa89157544638f775d2a90a3ec774">583</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gae98aa89157544638f775d2a90a3ec774">_i64</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::int64_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00584"></a>584</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00590"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga2e2ad62d8c5d6e3abcfca9a897ae61de">590</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga2e2ad62d8c5d6e3abcfca9a897ae61de">_u8</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::uint8_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00591"></a>591</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00597"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga07f83438e4c0c85efdeacd78668f3543">597</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga07f83438e4c0c85efdeacd78668f3543">_u16</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::uint16_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00598"></a>598</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00604"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaf66382b299dcf814298ae56b75b541d7">604</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaf66382b299dcf814298ae56b75b541d7">_u32</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::uint32_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00605"></a>605</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00611"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gac654508c2894db262cbd0335f76b02bf">611</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gac654508c2894db262cbd0335f76b02bf">_u64</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::uint64_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00612"></a>612</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00617"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gadcff4454bf86ea03c0c3d1be42b04e12">617</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gadcff4454bf86ea03c0c3d1be42b04e12">_f</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;float&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00618"></a>618</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00623"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6ab8b464d71f15f55bd047dbfca50899">623</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6ab8b464d71f15f55bd047dbfca50899">_d</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;double&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00624"></a>624</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00630"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga79572e6e73076a155927ff0c3888ce76">630</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga79572e6e73076a155927ff0c3888ce76">_ld</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;long double&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00631"></a>631</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00648"></a>648</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00649"></a><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/-t">649</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">struct </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6195961d9ece2c2c91e8946d47d84a79">_t</a> : <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value</a>&lt;T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00650"></a>650</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00656"></a>656</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">explicit</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6195961d9ece2c2c91e8946d47d84a79">_t</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; t);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00657"></a>657</span><span class="doxyLineContent"><span class="doxyHighlight">  };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00658"></a>658</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00659"></a>659</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00660"></a>660</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00661"></a>661</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00662"></a>662</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00688"></a>688</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00694"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6bdfe5c187140ee99d0bcabd5bb65156">694</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6bdfe5c187140ee99d0bcabd5bb65156">to_b</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;bool&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00695"></a>695</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00701"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga5d14217f53925b323f4236298e3dcc90">701</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga5d14217f53925b323f4236298e3dcc90">to_c</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;char&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00702"></a>702</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00708"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gadb22be8fe019b5cd1ad56cfadea5f4ec">708</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gadb22be8fe019b5cd1ad56cfadea5f4ec">to_sc</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;signed char&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00709"></a>709</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00715"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga1b39571aeebcb8091bd410a9b247a571">715</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga1b39571aeebcb8091bd410a9b247a571">to_s</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;short&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00716"></a>716</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00722"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gab6ddb21470182cbdcf06436cde43718f">722</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gab6ddb21470182cbdcf06436cde43718f">to_i</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;int&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00723"></a>723</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00729"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaaf580ebebfba7cbe84a89db8574a6aa7">729</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaaf580ebebfba7cbe84a89db8574a6aa7">to_l</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;long&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00730"></a>730</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00736"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gab9d11644d3b22e2a9932e64853b5a59d">736</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gab9d11644d3b22e2a9932e64853b5a59d">to_ll</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;long long&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00737"></a>737</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00743"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gac8586b75498097cb06b404399c307960">743</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gac8586b75498097cb06b404399c307960">to_u</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;unsigned&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00744"></a>744</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00750"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9b60956f6c874e5597cdea6c0323fff1">750</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9b60956f6c874e5597cdea6c0323fff1">to_uc</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;unsigned char&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00751"></a>751</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00757"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gac9a34848b05859a18794ece696e37f26">757</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gac9a34848b05859a18794ece696e37f26">to_us</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;unsigned short&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00758"></a>758</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00764"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9f6f56950ba8bce6cc49037af83e443b">764</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9f6f56950ba8bce6cc49037af83e443b">to_ul</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;unsigned long&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00765"></a>765</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00771"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga595258f3c1b293284f79a88b2872d43d">771</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga595258f3c1b293284f79a88b2872d43d">to_ull</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;unsigned long long&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00772"></a>772</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00778"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaa61c255757e915cb05132602baea088b">778</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaa61c255757e915cb05132602baea088b">to_i8</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::int8_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00779"></a>779</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00785"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaf22a7774a4b05de9779d9084ed41a02a">785</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaf22a7774a4b05de9779d9084ed41a02a">to_i16</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::int16_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00786"></a>786</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00792"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9ca96b6c6d79560f8186c6206ac4f613">792</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9ca96b6c6d79560f8186c6206ac4f613">to_i32</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::int32_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00793"></a>793</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00799"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga240591501696d181e105529c1f52b56c">799</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga240591501696d181e105529c1f52b56c">to_i64</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::int64_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00800"></a>800</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00806"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga8b683d809d600f5c5210bb16546a832e">806</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga8b683d809d600f5c5210bb16546a832e">to_u8</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::uint8_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00807"></a>807</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00813"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaa60006a01aa94a5fd755aebddd8ceec3">813</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaa60006a01aa94a5fd755aebddd8ceec3">to_u16</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::uint16_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00814"></a>814</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00820"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga3bf9f9c946f16b5e02f9f2c45739df42">820</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga3bf9f9c946f16b5e02f9f2c45739df42">to_u32</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::uint32_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00821"></a>821</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00827"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga5fba6fbb12941113aeff430609839ba4">827</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga5fba6fbb12941113aeff430609839ba4">to_u64</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::uint64_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00828"></a>828</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00834"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga3c89dfb65d916dfc34dfdfcb10334b5c">834</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga3c89dfb65d916dfc34dfdfcb10334b5c">to_f</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;float&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00835"></a>835</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00841"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga3b9d6825aa201bf1fdf9cbe8c0ad4bff">841</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga3b9d6825aa201bf1fdf9cbe8c0ad4bff">to_d</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;double&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00842"></a>842</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00848"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga33a096960b5dddee322e36c689ecbf47">848</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga33a096960b5dddee322e36c689ecbf47">to_ld</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;long double&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00849"></a>849</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00853"></a>853</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00884"></a>884</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00885"></a><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/to-t">885</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">struct </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaad9720f2d1e443d77cdfd1eb1151e924">to_t</a> : <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value</a>&lt;T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00886"></a>886</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00892"></a>892</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">explicit</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaad9720f2d1e443d77cdfd1eb1151e924">to_t</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; t);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00893"></a>893</span><span class="doxyLineContent"><span class="doxyHighlight">  };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00894"></a>894</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00895"></a>895</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00896"></a>896</span><span class="doxyLineContent"><span class="doxyHighlight">} </span><span class="doxyHighlightComment">// namespace micro_os_plus::micro_test_plus</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00897"></a>897</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00898"></a>898</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00899"></a>899</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00900"></a>900</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00901"></a>901</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00902"></a>902</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00903"></a>903</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00904"></a>904</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__cplusplus)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00905"></a>905</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00906"></a>906</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ============================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00907"></a>907</span><span class="doxyLineContent"><span class="doxyHighlightComment">// Templates, inlines &amp; constexpr implementations.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00908"></a>908</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00909"></a>909</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/literals-inlines-h">inlines/literals-inlines.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00910"></a>910</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00911"></a>911</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00912"></a>912</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00913"></a>913</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_LITERALS_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00914"></a>914</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00915"></a>915</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.1 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
