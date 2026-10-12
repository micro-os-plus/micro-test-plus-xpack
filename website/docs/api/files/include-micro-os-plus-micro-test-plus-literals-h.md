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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaa2bfc74376f8c110053bfa6e06e40772">operator""_b</a> (const char *name, decltype(sizeof("")) size)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>User-defined literal operator to convert to <span class="doxyComputerOutput">bool</span>. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaa2bfc74376f8c110053bfa6e06e40772">More...</a></p>
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

## Deprecated Type Wrappers Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga74e6e2bffc2fc2dea47f979b5b55ea64">_b</a> = type_traits::value&lt; bool &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">bool</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga74e6e2bffc2fc2dea47f979b5b55ea64">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gabd2f8b7401162835cb4735e4a7532c36">_c</a> = type_traits::value&lt; char &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">char</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gabd2f8b7401162835cb4735e4a7532c36">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga6ab8b464d71f15f55bd047dbfca50899">_d</a> = type_traits::value&lt; double &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">double</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga6ab8b464d71f15f55bd047dbfca50899">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gadcff4454bf86ea03c0c3d1be42b04e12">_f</a> = type_traits::value&lt; float &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">float</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gadcff4454bf86ea03c0c3d1be42b04e12">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga1613ccf081248c601bed0f3022fba652">_i</a> = type_traits::value&lt; int &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">int</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga1613ccf081248c601bed0f3022fba652">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaec10ef24cb02dd0fb7f5e44227562d51">_i16</a> = type_traits::value&lt; std::int16_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::int16_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaec10ef24cb02dd0fb7f5e44227562d51">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga5d6deb61637f1d7350a69f62d2971bc3">_i32</a> = type_traits::value&lt; std::int32_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::int32_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga5d6deb61637f1d7350a69f62d2971bc3">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gae98aa89157544638f775d2a90a3ec774">_i64</a> = type_traits::value&lt; std::int64_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::int64_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gae98aa89157544638f775d2a90a3ec774">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga3cb44c2b09802fbee17f324cbdf3f31e">_i8</a> = type_traits::value&lt; std::int8_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::int8_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga3cb44c2b09802fbee17f324cbdf3f31e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaaebf2b13e1742a894179deedf8ad82cc">_l</a> = type_traits::value&lt; long &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">long</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaaebf2b13e1742a894179deedf8ad82cc">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga79572e6e73076a155927ff0c3888ce76">_ld</a> = type_traits::value&lt; long double &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">long double</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga79572e6e73076a155927ff0c3888ce76">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga6b000cfa2a8a4c8b04cf6d6f142a76a6">_ll</a> = type_traits::value&lt; long long &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">long long</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga6b000cfa2a8a4c8b04cf6d6f142a76a6">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga102b1f7c41452481e6be2bd8da63e4a0">_s</a> = type_traits::value&lt; short &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">short</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga102b1f7c41452481e6be2bd8da63e4a0">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gacf10cd5dca8066e1df77e668b68f3272">_sc</a> = type_traits::value&lt; signed char &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">signed char</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gacf10cd5dca8066e1df77e668b68f3272">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga74b4ecee40263c6b4ac8a60fc6480fac">_u</a> = type_traits::value&lt; unsigned &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">unsigned</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga74b4ecee40263c6b4ac8a60fc6480fac">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga07f83438e4c0c85efdeacd78668f3543">_u16</a> = type_traits::value&lt; std::uint16_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::uint16_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga07f83438e4c0c85efdeacd78668f3543">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaf66382b299dcf814298ae56b75b541d7">_u32</a> = type_traits::value&lt; std::uint32_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::uint32_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaf66382b299dcf814298ae56b75b541d7">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gac654508c2894db262cbd0335f76b02bf">_u64</a> = type_traits::value&lt; std::uint64_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::uint64_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gac654508c2894db262cbd0335f76b02bf">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga2e2ad62d8c5d6e3abcfca9a897ae61de">_u8</a> = type_traits::value&lt; std::uint8_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::uint8_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga2e2ad62d8c5d6e3abcfca9a897ae61de">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga1ef97880cc5f2e13eea8b4ebb888886a">_uc</a> = type_traits::value&lt; unsigned char &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">unsigned char</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga1ef97880cc5f2e13eea8b4ebb888886a">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9cb69b5dc7c394a57e1b09c919b0f6ab">_ul</a> = type_traits::value&lt; unsigned long &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">unsigned long</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9cb69b5dc7c394a57e1b09c919b0f6ab">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga0b9d74a6595fe7fdefca21255ab59dc8">_ull</a> = type_traits::value&lt; unsigned long long &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">unsigned long long</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga0b9d74a6595fe7fdefca21255ab59dc8">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga67992fcc21a60e3dd1fb4c9c5ebc814a">_us</a> = type_traits::value&lt; unsigned short &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">unsigned short</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga67992fcc21a60e3dd1fb4c9c5ebc814a">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga6bdfe5c187140ee99d0bcabd5bb65156">to_b</a> = type_traits::value&lt; bool &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">bool</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga6bdfe5c187140ee99d0bcabd5bb65156">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga5d14217f53925b323f4236298e3dcc90">to_c</a> = type_traits::value&lt; char &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">char</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga5d14217f53925b323f4236298e3dcc90">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga3b9d6825aa201bf1fdf9cbe8c0ad4bff">to_d</a> = type_traits::value&lt; double &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">double</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga3b9d6825aa201bf1fdf9cbe8c0ad4bff">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga3c89dfb65d916dfc34dfdfcb10334b5c">to_f</a> = type_traits::value&lt; float &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">float</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga3c89dfb65d916dfc34dfdfcb10334b5c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gab6ddb21470182cbdcf06436cde43718f">to_i</a> = type_traits::value&lt; int &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">int</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gab6ddb21470182cbdcf06436cde43718f">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaf22a7774a4b05de9779d9084ed41a02a">to_i16</a> = type_traits::value&lt; std::int16_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::int16_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaf22a7774a4b05de9779d9084ed41a02a">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9ca96b6c6d79560f8186c6206ac4f613">to_i32</a> = type_traits::value&lt; std::int32_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::int32_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9ca96b6c6d79560f8186c6206ac4f613">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga240591501696d181e105529c1f52b56c">to_i64</a> = type_traits::value&lt; std::int64_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::int64_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga240591501696d181e105529c1f52b56c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaa61c255757e915cb05132602baea088b">to_i8</a> = type_traits::value&lt; std::int8_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::int8_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaa61c255757e915cb05132602baea088b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaaf580ebebfba7cbe84a89db8574a6aa7">to_l</a> = type_traits::value&lt; long &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">long</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaaf580ebebfba7cbe84a89db8574a6aa7">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga33a096960b5dddee322e36c689ecbf47">to_ld</a> = type_traits::value&lt; long double &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">long double</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga33a096960b5dddee322e36c689ecbf47">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gab9d11644d3b22e2a9932e64853b5a59d">to_ll</a> = type_traits::value&lt; long long &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">long long</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gab9d11644d3b22e2a9932e64853b5a59d">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga1b39571aeebcb8091bd410a9b247a571">to_s</a> = type_traits::value&lt; short &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">short</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga1b39571aeebcb8091bd410a9b247a571">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gadb22be8fe019b5cd1ad56cfadea5f4ec">to_sc</a> = type_traits::value&lt; signed char &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">signed char</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gadb22be8fe019b5cd1ad56cfadea5f4ec">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gac8586b75498097cb06b404399c307960">to_u</a> = type_traits::value&lt; unsigned &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">unsigned</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gac8586b75498097cb06b404399c307960">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaa60006a01aa94a5fd755aebddd8ceec3">to_u16</a> = type_traits::value&lt; std::uint16_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::uint16_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaa60006a01aa94a5fd755aebddd8ceec3">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga3bf9f9c946f16b5e02f9f2c45739df42">to_u32</a> = type_traits::value&lt; std::uint32_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::uint32_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga3bf9f9c946f16b5e02f9f2c45739df42">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga5fba6fbb12941113aeff430609839ba4">to_u64</a> = type_traits::value&lt; std::uint64_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::uint64_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga5fba6fbb12941113aeff430609839ba4">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga8b683d809d600f5c5210bb16546a832e">to_u8</a> = type_traits::value&lt; std::uint8_t &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">std::uint8_t</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga8b683d809d600f5c5210bb16546a832e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9b60956f6c874e5597cdea6c0323fff1">to_uc</a> = type_traits::value&lt; unsigned char &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">unsigned char</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9b60956f6c874e5597cdea6c0323fff1">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9f6f56950ba8bce6cc49037af83e443b">to_ul</a> = type_traits::value&lt; unsigned long &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">unsigned long</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9f6f56950ba8bce6cc49037af83e443b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga595258f3c1b293284f79a88b2872d43d">to_ull</a> = type_traits::value&lt; unsigned long long &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">unsigned long long</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga595258f3c1b293284f79a88b2872d43d">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gac9a34848b05859a18794ece696e37f26">to_us</a> = type_traits::value&lt; unsigned short &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Strongly-typed wrapper for <span class="doxyComputerOutput">unsigned short</span> values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gac9a34848b05859a18794ece696e37f26">More...</a></p>
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
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00053"></a>53</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00054"></a>54</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_LITERALS_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00055"></a>55</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#define MICRO_OS_PLUS_MICRO_TEST_PLUS_LITERALS_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00056"></a>56</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00057"></a>57</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00058"></a>58</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00059"></a>59</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__cplusplus)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00060"></a>60</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00061"></a>61</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00062"></a>62</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00063"></a>63</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if __has_include("micro-os-plus/project-config.h")</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00064"></a>64</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "micro-os-plus/project-config.h"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00065"></a>65</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// __has_include("micro-os-plus/project-config.h")</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00066"></a>66</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00067"></a>67</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if __has_include("micro-os-plus/micro-test-plus-defines.h")</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00068"></a>68</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "micro-os-plus/micro-test-plus-defines.h"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00069"></a>69</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// __has_include("micro-os-plus/micro-test-plus-defines.h")</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00070"></a>70</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00071"></a>71</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/type-traits-h">type-traits.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00072"></a>72</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/math-h">math.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00073"></a>73</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00074"></a>74</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;cstdint&gt;</span></span></div>
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
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00119"></a>119</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/literals">literals</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00120"></a>120</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00131"></a>131</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00132"></a>132</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00133"></a>133</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga1613ccf081248c601bed0f3022fba652">_i</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00134"></a>134</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00145"></a>145</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00146"></a>146</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00147"></a>147</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga102b1f7c41452481e6be2bd8da63e4a0">_s</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00148"></a>148</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00159"></a>159</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00160"></a>160</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00161"></a>161</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gabd2f8b7401162835cb4735e4a7532c36">_c</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00162"></a>162</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00173"></a>173</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00174"></a>174</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00175"></a>175</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gacf10cd5dca8066e1df77e668b68f3272">_sc</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00176"></a>176</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00187"></a>187</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00188"></a>188</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00189"></a>189</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaaebf2b13e1742a894179deedf8ad82cc">_l</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00190"></a>190</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00201"></a>201</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00202"></a>202</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00203"></a>203</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga6b000cfa2a8a4c8b04cf6d6f142a76a6">_ll</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00204"></a>204</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00215"></a>215</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00216"></a>216</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00217"></a>217</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga74b4ecee40263c6b4ac8a60fc6480fac">_u</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00218"></a>218</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00229"></a>229</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00230"></a>230</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00231"></a>231</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga1ef97880cc5f2e13eea8b4ebb888886a">_uc</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00232"></a>232</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00243"></a>243</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00244"></a>244</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00245"></a>245</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga67992fcc21a60e3dd1fb4c9c5ebc814a">_us</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00246"></a>246</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00257"></a>257</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00258"></a>258</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00259"></a>259</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9cb69b5dc7c394a57e1b09c919b0f6ab">_ul</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00260"></a>260</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00271"></a>271</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00272"></a>272</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00273"></a>273</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga0b9d74a6595fe7fdefca21255ab59dc8">_ull</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00274"></a>274</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00285"></a>285</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00286"></a>286</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00287"></a>287</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga3cb44c2b09802fbee17f324cbdf3f31e">_i8</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00288"></a>288</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00299"></a>299</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00300"></a>300</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00301"></a>301</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaec10ef24cb02dd0fb7f5e44227562d51">_i16</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00302"></a>302</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00313"></a>313</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00314"></a>314</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00315"></a>315</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga5d6deb61637f1d7350a69f62d2971bc3">_i32</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00316"></a>316</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00327"></a>327</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00328"></a>328</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00329"></a>329</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gae98aa89157544638f775d2a90a3ec774">_i64</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00330"></a>330</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00341"></a>341</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00342"></a>342</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00343"></a>343</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga2e2ad62d8c5d6e3abcfca9a897ae61de">_u8</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00344"></a>344</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00355"></a>355</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00356"></a>356</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00357"></a>357</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga07f83438e4c0c85efdeacd78668f3543">_u16</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00358"></a>358</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00369"></a>369</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00370"></a>370</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00371"></a>371</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaf66382b299dcf814298ae56b75b541d7">_u32</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00372"></a>372</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00383"></a>383</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00384"></a>384</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00385"></a>385</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gac654508c2894db262cbd0335f76b02bf">_u64</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00386"></a>386</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00397"></a>397</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00398"></a>398</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00399"></a>399</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gadcff4454bf86ea03c0c3d1be42b04e12">_f</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00400"></a>400</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00411"></a>411</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00412"></a>412</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00413"></a>413</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga6ab8b464d71f15f55bd047dbfca50899">_d</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00414"></a>414</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00425"></a>425</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">... Cs&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00426"></a>426</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00427"></a>427</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga79572e6e73076a155927ff0c3888ce76">_ld</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00428"></a>428</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00438"></a>438</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00439"></a>439</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga74e6e2bffc2fc2dea47f979b5b55ea64">_b</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* name, </span><span class="doxyHighlightKeyword">decltype</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight">)) size);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00440"></a>440</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00441"></a>441</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00442"></a>442</span><span class="doxyLineContent"><span class="doxyHighlight">  } </span><span class="doxyHighlightComment">// namespace literals</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00443"></a>443</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00444"></a>444</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00445"></a>445</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00446"></a>446</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00447"></a>447</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00448"></a>448</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00449"></a>449</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00450"></a>450</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wdocumentation-deprecated-sync"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00451"></a>451</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00452"></a>452</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00453"></a>453</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00458"></a>458</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00475"></a>475</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00484"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga74e6e2bffc2fc2dea47f979b5b55ea64">484</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga74e6e2bffc2fc2dea47f979b5b55ea64">_b</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;bool&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00485"></a>485</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00494"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gabd2f8b7401162835cb4735e4a7532c36">494</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gabd2f8b7401162835cb4735e4a7532c36">_c</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;char&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00495"></a>495</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00504"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gacf10cd5dca8066e1df77e668b68f3272">504</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gacf10cd5dca8066e1df77e668b68f3272">_sc</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;signed char&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00505"></a>505</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00514"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga102b1f7c41452481e6be2bd8da63e4a0">514</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga102b1f7c41452481e6be2bd8da63e4a0">_s</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;short&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00515"></a>515</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00524"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga1613ccf081248c601bed0f3022fba652">524</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga1613ccf081248c601bed0f3022fba652">_i</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;int&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00525"></a>525</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00534"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaaebf2b13e1742a894179deedf8ad82cc">534</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaaebf2b13e1742a894179deedf8ad82cc">_l</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;long&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00535"></a>535</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00544"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga6b000cfa2a8a4c8b04cf6d6f142a76a6">544</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga6b000cfa2a8a4c8b04cf6d6f142a76a6">_ll</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;long long&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00545"></a>545</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00554"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga74b4ecee40263c6b4ac8a60fc6480fac">554</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga74b4ecee40263c6b4ac8a60fc6480fac">_u</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;unsigned&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00555"></a>555</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00564"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga1ef97880cc5f2e13eea8b4ebb888886a">564</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga1ef97880cc5f2e13eea8b4ebb888886a">_uc</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;unsigned char&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00565"></a>565</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00574"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga67992fcc21a60e3dd1fb4c9c5ebc814a">574</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga67992fcc21a60e3dd1fb4c9c5ebc814a">_us</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;unsigned short&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00575"></a>575</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00584"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9cb69b5dc7c394a57e1b09c919b0f6ab">584</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9cb69b5dc7c394a57e1b09c919b0f6ab">_ul</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;unsigned long&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00585"></a>585</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00594"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga0b9d74a6595fe7fdefca21255ab59dc8">594</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga0b9d74a6595fe7fdefca21255ab59dc8">_ull</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;unsigned long long&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00595"></a>595</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00604"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga3cb44c2b09802fbee17f324cbdf3f31e">604</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga3cb44c2b09802fbee17f324cbdf3f31e">_i8</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::int8_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00605"></a>605</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00614"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaec10ef24cb02dd0fb7f5e44227562d51">614</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaec10ef24cb02dd0fb7f5e44227562d51">_i16</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::int16_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00615"></a>615</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00624"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga5d6deb61637f1d7350a69f62d2971bc3">624</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga5d6deb61637f1d7350a69f62d2971bc3">_i32</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::int32_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00625"></a>625</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00634"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gae98aa89157544638f775d2a90a3ec774">634</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gae98aa89157544638f775d2a90a3ec774">_i64</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::int64_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00635"></a>635</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00644"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga2e2ad62d8c5d6e3abcfca9a897ae61de">644</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga2e2ad62d8c5d6e3abcfca9a897ae61de">_u8</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::uint8_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00645"></a>645</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00654"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga07f83438e4c0c85efdeacd78668f3543">654</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga07f83438e4c0c85efdeacd78668f3543">_u16</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::uint16_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00655"></a>655</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00664"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaf66382b299dcf814298ae56b75b541d7">664</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaf66382b299dcf814298ae56b75b541d7">_u32</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::uint32_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00665"></a>665</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00674"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gac654508c2894db262cbd0335f76b02bf">674</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gac654508c2894db262cbd0335f76b02bf">_u64</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::uint64_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00675"></a>675</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00684"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gadcff4454bf86ea03c0c3d1be42b04e12">684</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gadcff4454bf86ea03c0c3d1be42b04e12">_f</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;float&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00685"></a>685</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00694"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga6ab8b464d71f15f55bd047dbfca50899">694</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga6ab8b464d71f15f55bd047dbfca50899">_d</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;double&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00695"></a>695</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00704"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga79572e6e73076a155927ff0c3888ce76">704</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga79572e6e73076a155927ff0c3888ce76">_ld</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;long double&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00705"></a>705</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00722"></a>722</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00723"></a><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/-t">723</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">struct </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga6195961d9ece2c2c91e8946d47d84a79">_t</a> : <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value</a>&lt;T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00724"></a>724</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00730"></a>730</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">explicit</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga6195961d9ece2c2c91e8946d47d84a79">_t</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; t);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00731"></a>731</span><span class="doxyLineContent"><span class="doxyHighlight">  };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00732"></a>732</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00733"></a>733</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00734"></a>734</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00735"></a>735</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00736"></a>736</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00762"></a>762</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00772"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga6bdfe5c187140ee99d0bcabd5bb65156">772</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga6bdfe5c187140ee99d0bcabd5bb65156">to_b</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;bool&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00773"></a>773</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00783"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga5d14217f53925b323f4236298e3dcc90">783</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga5d14217f53925b323f4236298e3dcc90">to_c</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;char&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00784"></a>784</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00794"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gadb22be8fe019b5cd1ad56cfadea5f4ec">794</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gadb22be8fe019b5cd1ad56cfadea5f4ec">to_sc</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;signed char&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00795"></a>795</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00805"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga1b39571aeebcb8091bd410a9b247a571">805</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga1b39571aeebcb8091bd410a9b247a571">to_s</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;short&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00806"></a>806</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00816"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gab6ddb21470182cbdcf06436cde43718f">816</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gab6ddb21470182cbdcf06436cde43718f">to_i</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;int&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00817"></a>817</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00827"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaaf580ebebfba7cbe84a89db8574a6aa7">827</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaaf580ebebfba7cbe84a89db8574a6aa7">to_l</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;long&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00828"></a>828</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00838"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gab9d11644d3b22e2a9932e64853b5a59d">838</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gab9d11644d3b22e2a9932e64853b5a59d">to_ll</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;long long&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00839"></a>839</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00849"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gac8586b75498097cb06b404399c307960">849</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gac8586b75498097cb06b404399c307960">to_u</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;unsigned&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00850"></a>850</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00860"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9b60956f6c874e5597cdea6c0323fff1">860</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9b60956f6c874e5597cdea6c0323fff1">to_uc</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;unsigned char&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00861"></a>861</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00871"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gac9a34848b05859a18794ece696e37f26">871</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gac9a34848b05859a18794ece696e37f26">to_us</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;unsigned short&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00872"></a>872</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00882"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9f6f56950ba8bce6cc49037af83e443b">882</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9f6f56950ba8bce6cc49037af83e443b">to_ul</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;unsigned long&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00883"></a>883</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00893"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga595258f3c1b293284f79a88b2872d43d">893</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga595258f3c1b293284f79a88b2872d43d">to_ull</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;unsigned long long&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00894"></a>894</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00904"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaa61c255757e915cb05132602baea088b">904</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaa61c255757e915cb05132602baea088b">to_i8</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::int8_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00905"></a>905</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00915"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaf22a7774a4b05de9779d9084ed41a02a">915</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaf22a7774a4b05de9779d9084ed41a02a">to_i16</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::int16_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00916"></a>916</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00926"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9ca96b6c6d79560f8186c6206ac4f613">926</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga9ca96b6c6d79560f8186c6206ac4f613">to_i32</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::int32_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00927"></a>927</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00937"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga240591501696d181e105529c1f52b56c">937</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga240591501696d181e105529c1f52b56c">to_i64</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::int64_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00938"></a>938</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00948"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga8b683d809d600f5c5210bb16546a832e">948</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga8b683d809d600f5c5210bb16546a832e">to_u8</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::uint8_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00949"></a>949</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00959"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaa60006a01aa94a5fd755aebddd8ceec3">959</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaa60006a01aa94a5fd755aebddd8ceec3">to_u16</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::uint16_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00960"></a>960</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00970"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga3bf9f9c946f16b5e02f9f2c45739df42">970</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga3bf9f9c946f16b5e02f9f2c45739df42">to_u32</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::uint32_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00971"></a>971</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00981"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga5fba6fbb12941113aeff430609839ba4">981</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga5fba6fbb12941113aeff430609839ba4">to_u64</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;std::uint64_t&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00982"></a>982</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00992"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga3c89dfb65d916dfc34dfdfcb10334b5c">992</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga3c89dfb65d916dfc34dfdfcb10334b5c">to_f</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;float&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00993"></a>993</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01003"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga3b9d6825aa201bf1fdf9cbe8c0ad4bff">1003</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga3b9d6825aa201bf1fdf9cbe8c0ad4bff">to_d</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;double&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01004"></a>1004</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01014"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga33a096960b5dddee322e36c689ecbf47">1014</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga33a096960b5dddee322e36c689ecbf47">to_ld</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value&lt;long double&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01015"></a>1015</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01019"></a>1019</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01047"></a>1047</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01048"></a><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/to-t">1048</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">struct </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaad9720f2d1e443d77cdfd1eb1151e924">to_t</a> : <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">type_traits::value</a>&lt;T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01049"></a>1049</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01055"></a>1055</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">explicit</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gaad9720f2d1e443d77cdfd1eb1151e924">to_t</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; t);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01056"></a>1056</span><span class="doxyLineContent"><span class="doxyHighlight">  };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01057"></a>1057</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01058"></a>1058</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01059"></a>1059</span><span class="doxyLineContent"><span class="doxyHighlight">} </span><span class="doxyHighlightComment">// namespace micro_os_plus::micro_test_plus</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01060"></a>1060</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01061"></a>1061</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01062"></a>1062</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01063"></a>1063</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01064"></a>1064</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01065"></a>1065</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01066"></a>1066</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01067"></a>1067</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__cplusplus)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01068"></a>1068</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01069"></a>1069</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ============================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01070"></a>1070</span><span class="doxyLineContent"><span class="doxyHighlightComment">// Templates, inlines &amp; constexpr implementations.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01071"></a>1071</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01072"></a>1072</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/literals-inlines-h">inlines/literals-inlines.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01073"></a>1073</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01074"></a>1074</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01075"></a>1075</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01076"></a>1076</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_LITERALS_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01077"></a>1077</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01078"></a>1078</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.2 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
