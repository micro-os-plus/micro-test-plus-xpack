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

<div class="doxyIncludesList">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/extension-h">extension.h</a>"
#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/math-h">math.h</a>"
#include &lt;cstdint&gt;
#include &lt;type_traits&gt;
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
<p>User-defined literals for the µTest++ testing framework. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/literals/#details">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaa2bfc74376f8c110053bfa6e06e40772">operator""_b</a> (const char *name, decltype(sizeof("")) size)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to create a named boolean constant. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaa2bfc74376f8c110053bfa6e06e40772">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gae521cebfd48332f44d01e4f880b4aafa">operator""_c</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">char</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gae521cebfd48332f44d01e4f880b4aafa">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9d9b0d77e96cc46e7c9fabbb6cf671da">operator""_d</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">double</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9d9b0d77e96cc46e7c9fabbb6cf671da">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gab9d0b5fe567e9ea4b2cf4e7edd6ec2ef">operator""_f</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">float</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gab9d0b5fe567e9ea4b2cf4e7edd6ec2ef">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga366a0d47aec3241e659816067c94fcdf">operator""_i</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">int</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga366a0d47aec3241e659816067c94fcdf">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gabce6e838737bf25be6e7527f69e75590">operator""_i16</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">int16_t</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gabce6e838737bf25be6e7527f69e75590">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga6a192d3dfff5a4a98aa7532d36d1b1bd">operator""_i32</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">int32_t</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga6a192d3dfff5a4a98aa7532d36d1b1bd">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gab0bb5d1e37cbe8de6477c11ecd60956d">operator""_i64</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">int64_t</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gab0bb5d1e37cbe8de6477c11ecd60956d">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9ca6fecc72b6da90acee52977eb077d7">operator""_i8</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">int8_t</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9ca6fecc72b6da90acee52977eb077d7">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga96e891b439024e116cb845bc65bc9c4f">operator""_l</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">long</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga96e891b439024e116cb845bc65bc9c4f">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaecd8c981d99602a0d0a44ebf6d1d4f75">operator""_ld</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">long double</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaecd8c981d99602a0d0a44ebf6d1d4f75">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaf5ab66b00c9486ade5d49f34a83783f5">operator""_ll</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">long long</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaf5ab66b00c9486ade5d49f34a83783f5">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga812816a2e9b23de1f8d8b2d86553d96d">operator""_s</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">short</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga812816a2e9b23de1f8d8b2d86553d96d">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga57d27f1a76de2d2b2a067134cbe61457">operator""_sc</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">signed char</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga57d27f1a76de2d2b2a067134cbe61457">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaf45bf641153a462a1ba7c12b908e667f">operator""_u</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">unsigned</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaf45bf641153a462a1ba7c12b908e667f">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga96d12d563093f297a73a8b984ae7a3a5">operator""_u16</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">uint16_t</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga96d12d563093f297a73a8b984ae7a3a5">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga3171e605b5c2e1d9a0e55ae34e904674">operator""_u32</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">uint32_t</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga3171e605b5c2e1d9a0e55ae34e904674">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga622b4808b7ebfc26ddf9db9128533f28">operator""_u64</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">uint64_t</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga622b4808b7ebfc26ddf9db9128533f28">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga80f43260f6a1afd8260355136858df48">operator""_u8</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">uint8_t</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga80f43260f6a1afd8260355136858df48">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga6c1b46d4b967bdbc573e3192c2d9f98a">operator""_uc</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">unsigned char</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga6c1b46d4b967bdbc573e3192c2d9f98a">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaef96b19b140b5007ec33a944c3b72cae">operator""_ul</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">unsigned long</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaef96b19b140b5007ec33a944c3b72cae">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga01adcd3866da43c393b7fba8a5e72bb2">operator""_ull</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">unsigned long long</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga01adcd3866da43c393b7fba8a5e72bb2">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9017debdc1eafd64e3c53c80157ad6f5">operator""_us</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">unsigned short</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9017debdc1eafd64e3c53c80157ad6f5">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto </td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gafe47800a219b00fcccf0a1dc596dbe20">approx</a> (T value, std::type_identity_t&lt; T &gt; epsilon) noexcept -&gt; detail::value&lt; T &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Wraps a floating-point value with an explicit comparison tolerance. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gafe47800a219b00fcccf0a1dc596dbe20">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga5570e36fb3e73be3edf734ac80a23d93">to_b</a> = detail::value&lt; bool &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">bool</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga5570e36fb3e73be3edf734ac80a23d93">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga6ccf42d05ae14c445f602128f8ffd831">to_c</a> = detail::value&lt; char &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">char</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga6ccf42d05ae14c445f602128f8ffd831">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9608f4a6f0a61bc159a66a46fb8cd630">to_d</a> = detail::value&lt; double &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">double</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9608f4a6f0a61bc159a66a46fb8cd630">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga5368740b47e92605914b6c38ea88aebf">to_f</a> = detail::value&lt; float &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">float</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga5368740b47e92605914b6c38ea88aebf">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaf3ee271cefcffa625e40d476305da62f">to_i</a> = detail::value&lt; int &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">int</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaf3ee271cefcffa625e40d476305da62f">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga5cc1961eb074bb0740d8a593c411e0f9">to_i16</a> = detail::value&lt; std::int16_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::int16_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga5cc1961eb074bb0740d8a593c411e0f9">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga201eeff58867ba58d3312ae56113ef06">to_i32</a> = detail::value&lt; std::int32_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::int32_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga201eeff58867ba58d3312ae56113ef06">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaead55f5e265634a742633261f9f2aa3f">to_i64</a> = detail::value&lt; std::int64_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::int64_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaead55f5e265634a742633261f9f2aa3f">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga52ad3a0a454c230f9fcfb01e5d73e6db">to_i8</a> = detail::value&lt; std::int8_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::int8_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga52ad3a0a454c230f9fcfb01e5d73e6db">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga09028a1e0e713723257afba48b9ee551">to_l</a> = detail::value&lt; long &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">long</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga09028a1e0e713723257afba48b9ee551">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaeba32254fdd8159523b525745b13bfa9">to_ld</a> = detail::value&lt; long double &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">long double</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaeba32254fdd8159523b525745b13bfa9">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga0d0ae1e784a8a4da6630ab06addcad34">to_ll</a> = detail::value&lt; long long &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">long long</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga0d0ae1e784a8a4da6630ab06addcad34">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gabc8f58b457f42435bcb51f53e6fe6b78">to_s</a> = detail::value&lt; short &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">short</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gabc8f58b457f42435bcb51f53e6fe6b78">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gae3838e23c60edeadbafdd4a22d1b1516">to_sc</a> = detail::value&lt; signed char &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">signed char</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gae3838e23c60edeadbafdd4a22d1b1516">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9e7a52d8850ef68e6e0f6f9ca64a4ce5">to_u</a> = detail::value&lt; unsigned &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">unsigned</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9e7a52d8850ef68e6e0f6f9ca64a4ce5">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga87bb08ab5e58f481ee911e872108f8e0">to_u16</a> = detail::value&lt; std::uint16_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::uint16_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga87bb08ab5e58f481ee911e872108f8e0">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gafe7f9ec77325e0ae6111967bf8c5f29a">to_u32</a> = detail::value&lt; std::uint32_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::uint32_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gafe7f9ec77325e0ae6111967bf8c5f29a">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaf7cbf6fdcdeae86203faebdf9df7a201">to_u64</a> = detail::value&lt; std::uint64_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::uint64_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaf7cbf6fdcdeae86203faebdf9df7a201">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaceb70f41ddfa8f5805dbe9be2adf2289">to_u8</a> = detail::value&lt; std::uint8_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::uint8_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaceb70f41ddfa8f5805dbe9be2adf2289">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gae0c0ed1401416ce6ee417ec86d8d2a89">to_uc</a> = detail::value&lt; unsigned char &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">unsigned char</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gae0c0ed1401416ce6ee417ec86d8d2a89">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga5d2d6a69c090569866a779672772b48f">to_ul</a> = detail::value&lt; unsigned long &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">unsigned long</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga5d2d6a69c090569866a779672772b48f">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gae1438b74ec39a793d5ad516a7c2c7788">to_ull</a> = detail::value&lt; unsigned long long &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">unsigned long long</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gae1438b74ec39a793d5ad516a7c2c7788">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga8c22086f0e7e89d753cf7846ef7229d4">to_us</a> = detail::value&lt; unsigned short &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">unsigned short</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga8c22086f0e7e89d753cf7846ef7229d4">More...</a></p>
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


<p>In addition to literal operators, this header declares the <span class="doxyComputerOutput">to_*</span> type wrappers for explicit type conversion, supporting enhanced clarity and type safety in test conditions. Their deprecated <span class="doxyComputerOutput">_i</span>, <span class="doxyComputerOutput">_u8</span>, etc. aliases, kept for backwards compatibility, are declared in <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deprecated-h">deprecated.h</a></span>.</p>


<p>The literal operators reside within the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/literals">micro_os_plus::micro_test_plus::literals</a></span> namespace, and the type wrappers within the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a></span> namespace, ensuring clear separation from user code and minimising the risk of naming conflicts.</p>


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
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00070"></a>70</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/extension-h">extension.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00071"></a>71</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/math-h">math.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00072"></a>72</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00073"></a>73</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;cstdint&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00074"></a>74</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;type_traits&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00075"></a>75</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00076"></a>76</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00077"></a>77</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00078"></a>78</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00079"></a>79</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00080"></a>80</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00081"></a>81</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Waggregate-return"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00082"></a>82</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00083"></a>83</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wc++98-compat"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00084"></a>84</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00085"></a>85</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00086"></a>86</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00087"></a>87</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00088"></a>88</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ============================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00089"></a>89</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00090"></a>90</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00091"></a>91</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00092"></a>92</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00093"></a>93</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00117"></a>117</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/literals">literals</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00118"></a>118</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00129"></a>129</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00130"></a>130</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00131"></a>131</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga8468610e763177a8f569f7d618851288">_i</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00132"></a>132</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00143"></a>143</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00144"></a>144</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00145"></a>145</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga461a956b7e308ed6e8c64afa3cf160f2">_s</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00146"></a>146</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00157"></a>157</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00158"></a>158</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00159"></a>159</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gafdd897d040f92df9cd42e551ebc88cd8">_c</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00160"></a>160</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00171"></a>171</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00172"></a>172</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00173"></a>173</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga0cc4baab5f421ac7adee10218d8ee8a2">_sc</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00174"></a>174</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00185"></a>185</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00186"></a>186</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00187"></a>187</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga429a848542fc4ffafd3dd22bc1832654">_l</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00188"></a>188</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00199"></a>199</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00200"></a>200</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00201"></a>201</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9c597ca04848620b8570c29a4741e77d">_ll</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00202"></a>202</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00213"></a>213</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00214"></a>214</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00215"></a>215</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaaa486af2418a24076237fbe26940f5ae">_u</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00216"></a>216</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00227"></a>227</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00228"></a>228</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00229"></a>229</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaa8bb559065ea34a9645fdfd6339b9b7a">_uc</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00230"></a>230</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00241"></a>241</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00242"></a>242</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00243"></a>243</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga65aea7fc6324806cc029041a1c785611">_us</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00244"></a>244</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00255"></a>255</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00256"></a>256</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00257"></a>257</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga32c7eef01fcaef2f1a9478427d951f62">_ul</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00258"></a>258</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00269"></a>269</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00270"></a>270</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00271"></a>271</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gada8a165060d3d3b3ab51272b9da58761">_ull</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00272"></a>272</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00283"></a>283</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00284"></a>284</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00285"></a>285</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga265f8609ef3d6ead78c7a66825553e24">_i8</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00286"></a>286</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00297"></a>297</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00298"></a>298</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00299"></a>299</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gad2d95793c99112ad2889c6663789d1e3">_i16</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00300"></a>300</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00311"></a>311</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00312"></a>312</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00313"></a>313</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga917a1759e37cd0d3fe3786da11729a4b">_i32</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00314"></a>314</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00325"></a>325</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00326"></a>326</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00327"></a>327</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga290a150eae030e183ca2e14e9095c93b">_i64</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00328"></a>328</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00339"></a>339</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00340"></a>340</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00341"></a>341</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaf27e37e2e29af1a3ffd5c4fb07e77ff9">_u8</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00342"></a>342</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00353"></a>353</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00354"></a>354</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00355"></a>355</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga97f7bc9a25eb4b7c663bd2388ade01ae">_u16</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00356"></a>356</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00367"></a>367</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00368"></a>368</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00369"></a>369</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga4afa32150456241245bfc641a6f17bbc">_u32</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00370"></a>370</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00381"></a>381</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00382"></a>382</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00383"></a>383</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga1241e84fc4457af1b4df5f053eec6aa5">_u64</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00384"></a>384</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00395"></a>395</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00396"></a>396</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00397"></a>397</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga231cd51e76a2f426703275739d605ad4">_f</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00398"></a>398</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00409"></a>409</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00410"></a>410</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00411"></a>411</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga7c6c0169d894a7dd589d96df49e8df26">_d</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00412"></a>412</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00423"></a>423</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00424"></a>424</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00425"></a>425</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gacfe28c6fb7bfb47ca8891cb61e7f58d9">_ld</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00426"></a>426</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00437"></a>437</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00438"></a>438</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gad4203783cfbe141f41ee8515f7b2ea94">_b</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* name, </span><span class="doxyHighlightKeyword">decltype</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight">)) size);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00439"></a>439</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00440"></a>440</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00441"></a>441</span><span class="doxyLineContent"><span class="doxyHighlight">  } </span><span class="doxyHighlightComment">// namespace literals</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00442"></a>442</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00443"></a>443</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00444"></a>444</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00449"></a>449</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00478"></a>478</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00488"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga5570e36fb3e73be3edf734ac80a23d93">488</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga5570e36fb3e73be3edf734ac80a23d93">to_b</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">detail::value&lt;bool&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00489"></a>489</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00499"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga6ccf42d05ae14c445f602128f8ffd831">499</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga6ccf42d05ae14c445f602128f8ffd831">to_c</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">detail::value&lt;char&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00500"></a>500</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00510"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gae3838e23c60edeadbafdd4a22d1b1516">510</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gae3838e23c60edeadbafdd4a22d1b1516">to_sc</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">detail::value&lt;signed char&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00511"></a>511</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00521"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gabc8f58b457f42435bcb51f53e6fe6b78">521</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gabc8f58b457f42435bcb51f53e6fe6b78">to_s</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">detail::value&lt;short&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00522"></a>522</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00532"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaf3ee271cefcffa625e40d476305da62f">532</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaf3ee271cefcffa625e40d476305da62f">to_i</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">detail::value&lt;int&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00533"></a>533</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00543"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga09028a1e0e713723257afba48b9ee551">543</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga09028a1e0e713723257afba48b9ee551">to_l</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">detail::value&lt;long&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00544"></a>544</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00554"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga0d0ae1e784a8a4da6630ab06addcad34">554</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga0d0ae1e784a8a4da6630ab06addcad34">to_ll</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">detail::value&lt;long long&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00555"></a>555</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00565"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9e7a52d8850ef68e6e0f6f9ca64a4ce5">565</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9e7a52d8850ef68e6e0f6f9ca64a4ce5">to_u</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">detail::value&lt;unsigned&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00566"></a>566</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00576"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gae0c0ed1401416ce6ee417ec86d8d2a89">576</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gae0c0ed1401416ce6ee417ec86d8d2a89">to_uc</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">detail::value&lt;unsigned char&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00577"></a>577</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00587"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga8c22086f0e7e89d753cf7846ef7229d4">587</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga8c22086f0e7e89d753cf7846ef7229d4">to_us</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">detail::value&lt;unsigned short&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00588"></a>588</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00598"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga5d2d6a69c090569866a779672772b48f">598</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga5d2d6a69c090569866a779672772b48f">to_ul</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">detail::value&lt;unsigned long&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00599"></a>599</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00609"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gae1438b74ec39a793d5ad516a7c2c7788">609</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gae1438b74ec39a793d5ad516a7c2c7788">to_ull</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">detail::value&lt;unsigned long long&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00610"></a>610</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00620"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga52ad3a0a454c230f9fcfb01e5d73e6db">620</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga52ad3a0a454c230f9fcfb01e5d73e6db">to_i8</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">detail::value&lt;std::int8_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00621"></a>621</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00631"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga5cc1961eb074bb0740d8a593c411e0f9">631</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga5cc1961eb074bb0740d8a593c411e0f9">to_i16</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">detail::value&lt;std::int16_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00632"></a>632</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00642"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga201eeff58867ba58d3312ae56113ef06">642</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga201eeff58867ba58d3312ae56113ef06">to_i32</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">detail::value&lt;std::int32_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00643"></a>643</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00653"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaead55f5e265634a742633261f9f2aa3f">653</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaead55f5e265634a742633261f9f2aa3f">to_i64</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">detail::value&lt;std::int64_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00654"></a>654</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00664"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaceb70f41ddfa8f5805dbe9be2adf2289">664</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaceb70f41ddfa8f5805dbe9be2adf2289">to_u8</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">detail::value&lt;std::uint8_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00665"></a>665</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00675"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga87bb08ab5e58f481ee911e872108f8e0">675</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga87bb08ab5e58f481ee911e872108f8e0">to_u16</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">detail::value&lt;std::uint16_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00676"></a>676</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00686"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gafe7f9ec77325e0ae6111967bf8c5f29a">686</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gafe7f9ec77325e0ae6111967bf8c5f29a">to_u32</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">detail::value&lt;std::uint32_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00687"></a>687</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00697"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaf7cbf6fdcdeae86203faebdf9df7a201">697</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaf7cbf6fdcdeae86203faebdf9df7a201">to_u64</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">detail::value&lt;std::uint64_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00698"></a>698</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00708"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga5368740b47e92605914b6c38ea88aebf">708</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga5368740b47e92605914b6c38ea88aebf">to_f</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">detail::value&lt;float&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00709"></a>709</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00719"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9608f4a6f0a61bc159a66a46fb8cd630">719</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9608f4a6f0a61bc159a66a46fb8cd630">to_d</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">detail::value&lt;double&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00720"></a>720</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00730"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaeba32254fdd8159523b525745b13bfa9">730</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaeba32254fdd8159523b525745b13bfa9">to_ld</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">detail::value&lt;long double&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00731"></a>731</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00735"></a>735</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00739"></a>739</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00767"></a>767</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00768"></a><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/to-t">768</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">struct </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/to-t/#aad9720f2d1e443d77cdfd1eb1151e924">to_t</a> : <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">detail::value</a>&lt;T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00769"></a>769</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00775"></a>775</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">explicit</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/to-t/#aad9720f2d1e443d77cdfd1eb1151e924">to_t</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; t);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00776"></a>776</span><span class="doxyLineContent"><span class="doxyHighlight">  };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00777"></a>777</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00808"></a>808</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00809"></a>809</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> std::is_floating_point_v&lt;T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00810"></a>810</span><span class="doxyLineContent"><span class="doxyHighlight">  [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00811"></a>811</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-function-comparators/#gacae776e46a799b81af859ba9bb74e7d0">approx</a> (T value, std::type_identity_t&lt;T&gt; epsilon) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00812"></a>812</span><span class="doxyLineContent"><span class="doxyHighlight">      -&gt; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">detail::value&lt;T&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00813"></a>813</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00814"></a>814</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00815"></a>815</span><span class="doxyLineContent"><span class="doxyHighlight">} </span><span class="doxyHighlightComment">// namespace micro_os_plus::micro_test_plus</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00816"></a>816</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00817"></a>817</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00818"></a>818</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00819"></a>819</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00820"></a>820</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00821"></a>821</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00822"></a>822</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00823"></a>823</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__cplusplus)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00824"></a>824</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00825"></a>825</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ============================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00826"></a>826</span><span class="doxyLineContent"><span class="doxyHighlightComment">// Templates, inlines &amp; constexpr implementations.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00827"></a>827</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00828"></a>828</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/literals-inlines-h">inlines/literals-inlines.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00829"></a>829</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00830"></a>830</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00831"></a>831</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00832"></a>832</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_LITERALS_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00833"></a>833</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00834"></a>834</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
