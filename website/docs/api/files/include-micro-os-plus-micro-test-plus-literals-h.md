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

<div class="doxyIncludesList">#include &lt;cstdint&gt;
#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/type-traits-h">type-traits.h</a>"
#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/math-h">math.h</a>"
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
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00053"></a>53</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#ifndef MICRO_TEST_PLUS_LITERALS_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00054"></a>54</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#define MICRO_TEST_PLUS_LITERALS_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00055"></a>55</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00056"></a>56</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00057"></a>57</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00058"></a>58</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#ifdef __cplusplus</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00059"></a>59</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00060"></a>60</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00061"></a>61</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00062"></a>62</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;cstdint&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00063"></a>63</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/type-traits-h">type-traits.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00064"></a>64</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/math-h">math.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00065"></a>65</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00066"></a>66</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00067"></a>67</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00068"></a>68</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00069"></a>69</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00070"></a>70</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Waggregate-return"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00071"></a>71</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00072"></a>72</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wc++98-compat"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00073"></a>73</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00074"></a>74</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00075"></a>75</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00076"></a>76</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00077"></a>77</span><span class="doxyLineContent"><span class="doxyHighlightComment">// =============================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00078"></a>78</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00079"></a>79</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00080"></a>80</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00081"></a>81</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00082"></a>82</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00108"></a>108</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/literals">literals</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00109"></a>109</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00120"></a>120</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00121"></a>121</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00122"></a>122</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga1613ccf081248c601bed0f3022fba652">_i</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00123"></a>123</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00134"></a>134</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00135"></a>135</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00136"></a>136</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga102b1f7c41452481e6be2bd8da63e4a0">_s</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00137"></a>137</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00148"></a>148</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00149"></a>149</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00150"></a>150</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gabd2f8b7401162835cb4735e4a7532c36">_c</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00151"></a>151</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00162"></a>162</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00163"></a>163</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00164"></a>164</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gacf10cd5dca8066e1df77e668b68f3272">_sc</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00165"></a>165</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00176"></a>176</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00177"></a>177</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00178"></a>178</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaaebf2b13e1742a894179deedf8ad82cc">_l</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00179"></a>179</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00190"></a>190</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00191"></a>191</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00192"></a>192</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6b000cfa2a8a4c8b04cf6d6f142a76a6">_ll</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00193"></a>193</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00204"></a>204</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00205"></a>205</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00206"></a>206</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga74b4ecee40263c6b4ac8a60fc6480fac">_u</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00207"></a>207</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00218"></a>218</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00219"></a>219</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00220"></a>220</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga1ef97880cc5f2e13eea8b4ebb888886a">_uc</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00221"></a>221</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00232"></a>232</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00233"></a>233</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00234"></a>234</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga67992fcc21a60e3dd1fb4c9c5ebc814a">_us</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00235"></a>235</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00246"></a>246</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00247"></a>247</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00248"></a>248</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9cb69b5dc7c394a57e1b09c919b0f6ab">_ul</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00249"></a>249</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00260"></a>260</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00261"></a>261</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00262"></a>262</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga0b9d74a6595fe7fdefca21255ab59dc8">_ull</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00263"></a>263</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00274"></a>274</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00275"></a>275</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00276"></a>276</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga3cb44c2b09802fbee17f324cbdf3f31e">_i8</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00277"></a>277</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00288"></a>288</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00289"></a>289</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00290"></a>290</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaec10ef24cb02dd0fb7f5e44227562d51">_i16</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00291"></a>291</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00302"></a>302</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00303"></a>303</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00304"></a>304</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga5d6deb61637f1d7350a69f62d2971bc3">_i32</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00305"></a>305</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00316"></a>316</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00317"></a>317</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00318"></a>318</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gae98aa89157544638f775d2a90a3ec774">_i64</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00319"></a>319</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00330"></a>330</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00331"></a>331</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00332"></a>332</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga2e2ad62d8c5d6e3abcfca9a897ae61de">_u8</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00333"></a>333</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00344"></a>344</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00345"></a>345</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00346"></a>346</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga07f83438e4c0c85efdeacd78668f3543">_u16</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00347"></a>347</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00358"></a>358</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00359"></a>359</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00360"></a>360</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaf66382b299dcf814298ae56b75b541d7">_u32</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00361"></a>361</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00372"></a>372</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00373"></a>373</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00374"></a>374</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gac654508c2894db262cbd0335f76b02bf">_u64</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00375"></a>375</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00386"></a>386</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00387"></a>387</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00388"></a>388</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gadcff4454bf86ea03c0c3d1be42b04e12">_f</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00389"></a>389</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00400"></a>400</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00401"></a>401</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00402"></a>402</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6ab8b464d71f15f55bd047dbfca50899">_d</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00403"></a>403</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00414"></a>414</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00415"></a>415</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00416"></a>416</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga79572e6e73076a155927ff0c3888ce76">_ld</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00417"></a>417</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00427"></a>427</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00428"></a>428</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga74e6e2bffc2fc2dea47f979b5b55ea64">_b</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* name, </span><span class="doxyHighlightKeyword">decltype</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight">)) size);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00429"></a>429</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00430"></a>430</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00431"></a>431</span><span class="doxyLineContent"><span class="doxyHighlight">  } </span><span class="doxyHighlightComment">// namespace literals</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00432"></a>432</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00433"></a>433</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00434"></a>434</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00435"></a>435</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00436"></a>436</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00437"></a>437</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00438"></a>438</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wdocumentation-deprecated-sync"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00439"></a>439</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00440"></a>440</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00441"></a>441</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00446"></a>446</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00463"></a>463</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00469"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga74e6e2bffc2fc2dea47f979b5b55ea64">469</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga74e6e2bffc2fc2dea47f979b5b55ea64">_b</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;bool&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00470"></a>470</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00476"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gabd2f8b7401162835cb4735e4a7532c36">476</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gabd2f8b7401162835cb4735e4a7532c36">_c</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;char&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00477"></a>477</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00483"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gacf10cd5dca8066e1df77e668b68f3272">483</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gacf10cd5dca8066e1df77e668b68f3272">_sc</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;signed char&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00484"></a>484</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00490"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga102b1f7c41452481e6be2bd8da63e4a0">490</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga102b1f7c41452481e6be2bd8da63e4a0">_s</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;short&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00491"></a>491</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00497"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga1613ccf081248c601bed0f3022fba652">497</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga1613ccf081248c601bed0f3022fba652">_i</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;int&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00498"></a>498</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00504"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaaebf2b13e1742a894179deedf8ad82cc">504</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaaebf2b13e1742a894179deedf8ad82cc">_l</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;long&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00505"></a>505</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00511"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6b000cfa2a8a4c8b04cf6d6f142a76a6">511</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6b000cfa2a8a4c8b04cf6d6f142a76a6">_ll</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;long long&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00512"></a>512</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00518"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga74b4ecee40263c6b4ac8a60fc6480fac">518</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga74b4ecee40263c6b4ac8a60fc6480fac">_u</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;unsigned&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00519"></a>519</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00525"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga1ef97880cc5f2e13eea8b4ebb888886a">525</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga1ef97880cc5f2e13eea8b4ebb888886a">_uc</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;unsigned char&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00526"></a>526</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00532"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga67992fcc21a60e3dd1fb4c9c5ebc814a">532</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga67992fcc21a60e3dd1fb4c9c5ebc814a">_us</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;unsigned short&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00533"></a>533</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00539"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9cb69b5dc7c394a57e1b09c919b0f6ab">539</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9cb69b5dc7c394a57e1b09c919b0f6ab">_ul</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;unsigned long&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00540"></a>540</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00546"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga0b9d74a6595fe7fdefca21255ab59dc8">546</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga0b9d74a6595fe7fdefca21255ab59dc8">_ull</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;unsigned long long&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00547"></a>547</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00553"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga3cb44c2b09802fbee17f324cbdf3f31e">553</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga3cb44c2b09802fbee17f324cbdf3f31e">_i8</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::int8_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00554"></a>554</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00560"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaec10ef24cb02dd0fb7f5e44227562d51">560</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaec10ef24cb02dd0fb7f5e44227562d51">_i16</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::int16_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00561"></a>561</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00567"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga5d6deb61637f1d7350a69f62d2971bc3">567</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga5d6deb61637f1d7350a69f62d2971bc3">_i32</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::int32_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00568"></a>568</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00574"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gae98aa89157544638f775d2a90a3ec774">574</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gae98aa89157544638f775d2a90a3ec774">_i64</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::int64_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00575"></a>575</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00581"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga2e2ad62d8c5d6e3abcfca9a897ae61de">581</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga2e2ad62d8c5d6e3abcfca9a897ae61de">_u8</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::uint8_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00582"></a>582</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00588"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga07f83438e4c0c85efdeacd78668f3543">588</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga07f83438e4c0c85efdeacd78668f3543">_u16</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::uint16_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00589"></a>589</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00595"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaf66382b299dcf814298ae56b75b541d7">595</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaf66382b299dcf814298ae56b75b541d7">_u32</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::uint32_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00596"></a>596</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00602"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gac654508c2894db262cbd0335f76b02bf">602</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gac654508c2894db262cbd0335f76b02bf">_u64</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::uint64_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00603"></a>603</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00608"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gadcff4454bf86ea03c0c3d1be42b04e12">608</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gadcff4454bf86ea03c0c3d1be42b04e12">_f</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;float&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00609"></a>609</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00614"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6ab8b464d71f15f55bd047dbfca50899">614</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6ab8b464d71f15f55bd047dbfca50899">_d</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;double&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00615"></a>615</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00621"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga79572e6e73076a155927ff0c3888ce76">621</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga79572e6e73076a155927ff0c3888ce76">_ld</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;long double&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00622"></a>622</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00639"></a>639</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00640"></a><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/-t">640</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">struct </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6195961d9ece2c2c91e8946d47d84a79">_t</a> : <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value</a>&lt;T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00641"></a>641</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00651"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6195961d9ece2c2c91e8946d47d84a79">651</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">explicit</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6195961d9ece2c2c91e8946d47d84a79">_t</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; t) : <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/type-traits">type_traits</a>::<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-f7399366cd6336ecbea702c3289d9432/#aa345a4fad8db58254b2f5b7a395d8e5b">value</a>&lt;T&gt;{ t }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00652"></a>652</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00653"></a>653</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00654"></a>654</span><span class="doxyLineContent"><span class="doxyHighlight">  };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00655"></a>655</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00656"></a>656</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00657"></a>657</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00658"></a>658</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00659"></a>659</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00685"></a>685</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00691"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6bdfe5c187140ee99d0bcabd5bb65156">691</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga6bdfe5c187140ee99d0bcabd5bb65156">to_b</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;bool&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00692"></a>692</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00698"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga5d14217f53925b323f4236298e3dcc90">698</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga5d14217f53925b323f4236298e3dcc90">to_c</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;char&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00699"></a>699</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00705"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gadb22be8fe019b5cd1ad56cfadea5f4ec">705</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gadb22be8fe019b5cd1ad56cfadea5f4ec">to_sc</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;signed char&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00706"></a>706</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00712"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga1b39571aeebcb8091bd410a9b247a571">712</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga1b39571aeebcb8091bd410a9b247a571">to_s</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;short&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00713"></a>713</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00719"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gab6ddb21470182cbdcf06436cde43718f">719</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gab6ddb21470182cbdcf06436cde43718f">to_i</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;int&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00720"></a>720</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00726"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaaf580ebebfba7cbe84a89db8574a6aa7">726</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaaf580ebebfba7cbe84a89db8574a6aa7">to_l</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;long&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00727"></a>727</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00733"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gab9d11644d3b22e2a9932e64853b5a59d">733</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gab9d11644d3b22e2a9932e64853b5a59d">to_ll</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;long long&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00734"></a>734</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00740"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gac8586b75498097cb06b404399c307960">740</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gac8586b75498097cb06b404399c307960">to_u</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;unsigned&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00741"></a>741</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00747"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9b60956f6c874e5597cdea6c0323fff1">747</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9b60956f6c874e5597cdea6c0323fff1">to_uc</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;unsigned char&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00748"></a>748</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00754"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gac9a34848b05859a18794ece696e37f26">754</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gac9a34848b05859a18794ece696e37f26">to_us</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;unsigned short&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00755"></a>755</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00761"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9f6f56950ba8bce6cc49037af83e443b">761</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9f6f56950ba8bce6cc49037af83e443b">to_ul</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;unsigned long&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00762"></a>762</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00768"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga595258f3c1b293284f79a88b2872d43d">768</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga595258f3c1b293284f79a88b2872d43d">to_ull</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;unsigned long long&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00769"></a>769</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00775"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaa61c255757e915cb05132602baea088b">775</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaa61c255757e915cb05132602baea088b">to_i8</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::int8_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00776"></a>776</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00782"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaf22a7774a4b05de9779d9084ed41a02a">782</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaf22a7774a4b05de9779d9084ed41a02a">to_i16</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::int16_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00783"></a>783</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00789"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9ca96b6c6d79560f8186c6206ac4f613">789</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga9ca96b6c6d79560f8186c6206ac4f613">to_i32</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::int32_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00790"></a>790</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00796"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga240591501696d181e105529c1f52b56c">796</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga240591501696d181e105529c1f52b56c">to_i64</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::int64_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00797"></a>797</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00803"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga8b683d809d600f5c5210bb16546a832e">803</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga8b683d809d600f5c5210bb16546a832e">to_u8</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::uint8_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00804"></a>804</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00810"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaa60006a01aa94a5fd755aebddd8ceec3">810</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaa60006a01aa94a5fd755aebddd8ceec3">to_u16</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::uint16_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00811"></a>811</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00817"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga3bf9f9c946f16b5e02f9f2c45739df42">817</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga3bf9f9c946f16b5e02f9f2c45739df42">to_u32</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::uint32_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00818"></a>818</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00824"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga5fba6fbb12941113aeff430609839ba4">824</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga5fba6fbb12941113aeff430609839ba4">to_u64</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::uint64_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00825"></a>825</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00831"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga3c89dfb65d916dfc34dfdfcb10334b5c">831</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga3c89dfb65d916dfc34dfdfcb10334b5c">to_f</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;float&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00832"></a>832</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00838"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga3b9d6825aa201bf1fdf9cbe8c0ad4bff">838</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga3b9d6825aa201bf1fdf9cbe8c0ad4bff">to_d</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;double&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00839"></a>839</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00845"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga33a096960b5dddee322e36c689ecbf47">845</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga33a096960b5dddee322e36c689ecbf47">to_ld</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;long double&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00846"></a>846</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00850"></a>850</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00881"></a>881</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00882"></a><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/to-t">882</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">struct </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaad9720f2d1e443d77cdfd1eb1151e924">to_t</a> : <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value</a>&lt;T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00883"></a>883</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00893"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaad9720f2d1e443d77cdfd1eb1151e924">893</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">explicit</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#gaad9720f2d1e443d77cdfd1eb1151e924">to_t</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; t) : <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/type-traits">type_traits</a>::<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-f7399366cd6336ecbea702c3289d9432/#aa345a4fad8db58254b2f5b7a395d8e5b">value</a>&lt;T&gt;{ t }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00894"></a>894</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00895"></a>895</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00896"></a>896</span><span class="doxyLineContent"><span class="doxyHighlight">  };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00897"></a>897</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00898"></a>898</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00899"></a>899</span><span class="doxyLineContent"><span class="doxyHighlight">} </span><span class="doxyHighlightComment">// namespace micro_os_plus::micro_test_plus</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00900"></a>900</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00901"></a>901</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00902"></a>902</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00903"></a>903</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00904"></a>904</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00905"></a>905</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00906"></a>906</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00907"></a>907</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// __cplusplus</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00908"></a>908</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00909"></a>909</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00910"></a>910</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00911"></a>911</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_TEST_PLUS_LITERALS_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00912"></a>912</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00913"></a>913</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.0.0 by <a href="https://www.doxygen.nl">Doxygen</a> 1.14.0.</p>

</div>
