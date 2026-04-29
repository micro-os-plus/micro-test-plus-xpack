---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/namespaces/micro-os-plus/micro-test-plus/operators
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - namespace

---

<div class="doxyPage">

# `operators` Namespace

<p>Custom operator overloads for expressive and type-safe test assertions. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
namespace micro_os_plus::micro_test_plus::operators { ... }
</div>

## Operators Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#gaa188c33047f559e28dc95dbb465e19a8">operator and</a> (const Lhs_T &amp;lhs, const Rhs_T &amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Logical <span class="doxyComputerOutput">&amp;&amp;</span> (and) operator. Matches only if at least one operand is of local type (derived from local <span class="doxyComputerOutput">op</span>). <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#gaa188c33047f559e28dc95dbb465e19a8">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#ga00db5f149865ed9fd8d73f2db44542b0">operator not</a> (const T &amp;t)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Logical <span class="doxyComputerOutput">!</span> (not) operator. Matches only if the operand is of local type (derived from local <span class="doxyComputerOutput">op</span>). <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#ga00db5f149865ed9fd8d73f2db44542b0">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#ga0fe9ef52ecfb0de402da9e7454d7c20b">operator or</a> (const Lhs_T &amp;lhs, const Rhs_T &amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Logical <span class="doxyComputerOutput">||</span> (or) operator. Matches only if at least one operand is of local type (derived from local <span class="doxyComputerOutput">op</span>). <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#ga0fe9ef52ecfb0de402da9e7454d7c20b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#ga445025eccd3ef529af191aab5aad91a9">operator!=</a> (const Lhs_T &amp;lhs, const Rhs_T &amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Non-equality operator for custom types. Matches only if at least one operand is of local type. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#ga445025eccd3ef529af191aab5aad91a9">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-container-operators/#gac2449b2b9f07c550b1218456ba1da2db">operator!=</a> (const Lhs_T &amp;lhs, const Rhs_T &amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Non-equality operator for containers. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-container-operators/#gac2449b2b9f07c550b1218456ba1da2db">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-string-operators/#ga179e971d5e37795c036ad66aa35f1654">operator!=</a> (std::string_view lhs, std::string_view rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Non-equality operator for <span class="doxyComputerOutput">string_view</span> objects. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-string-operators/#ga179e971d5e37795c036ad66aa35f1654">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#ga675d31a23d8f0dfed775466ef1463a80">operator&lt;</a> (const Lhs_T &amp;lhs, const Rhs_T &amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Less than operator. Matches only if at least one operand is of local type (derived from local <span class="doxyComputerOutput">op</span>). <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#ga675d31a23d8f0dfed775466ef1463a80">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#ga15235adceff30c6e3aa382696aea23cb">operator&lt;=</a> (const Lhs_T &amp;lhs, const Rhs_T &amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Less than or equal operator. Matches only if at least one operand is of local type (derived from local <span class="doxyComputerOutput">op</span>). <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#ga15235adceff30c6e3aa382696aea23cb">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#gaae177a6c59286d4d7e4f85ffa6579e56">operator==</a> (const Lhs_T &amp;lhs, const Rhs_T &amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Equality operator for custom types. Matches only if at least one operand is of local type. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#gaae177a6c59286d4d7e4f85ffa6579e56">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-container-operators/#gab8c44f8115524296fbaf21688dd7f389">operator==</a> (const Lhs_T &amp;lhs, const Rhs_T &amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Equality operator for containers. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-container-operators/#gab8c44f8115524296fbaf21688dd7f389">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-string-operators/#gaabe34a842bf38ea2913a4164d2b0a9cb">operator==</a> (std::string_view lhs, std::string_view rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Equality operator for <span class="doxyComputerOutput">string_view</span> objects. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-string-operators/#gaabe34a842bf38ea2913a4164d2b0a9cb">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#gac0afc8d658f73e3b5f136a5c60d1fbd1">operator&gt;</a> (const Lhs_T &amp;lhs, const Rhs_T &amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Greater than operator. Matches only if at least one operand is of local type (derived from local <span class="doxyComputerOutput">op</span>). <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#gac0afc8d658f73e3b5f136a5c60d1fbd1">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#gabfc165fd00e9f53bbf7b63f71b9d5020">operator&gt;=</a> (const Lhs_T &amp;lhs, const Rhs_T &amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Greater than or equal operator. Matches only if at least one operand is of local type (derived from local <span class="doxyComputerOutput">op</span>). <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#gabfc165fd00e9f53bbf7b63f71b9d5020">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Custom operator overloads for expressive and type-safe test assertions.</p>


<p>The <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/operators">micro_os_plus::micro_test_plus::operators</a></span> namespace provides a comprehensive set of custom operator overloads designed to enable expressive, concise, and type-safe test assertions within the µTest++ framework.</p>


<p>This namespace includes equality, inequality, relational, and logical operators tailored for use with the framework’s custom types, containers, and string views. These operators facilitate the creation of clear and readable test expressions, supporting both strongly-typed constants (via user-defined literals) and dynamic values (via wrappers).</p>



:::warning
<p>Please be aware that these operators may conflict with other operators defined within the application under test.</p>
:::


<p>To minimise conflicts with application-defined operators, these overloads are enabled only for specific types recognised by the framework, such as those derived from the local <span class="doxyComputerOutput">op</span> base type or identified as containers or string views. Constants typically require a literal suffix (e.g., <span class="doxyComputerOutput">1<a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-literals/#ga1613ccf081248c601bed0f3022fba652">_i</a></span>), while dynamic values should be wrapped using the provided casting utilities (e.g., <span class="doxyComputerOutput">mt::to_i{...}</span>).</p>


<p>All definitions within this namespace are implemented in the <span class="doxyComputerOutput">include/micro-os-plus/micro-test-plus</span> folder, ensuring a modular and maintainable codebase.</p>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.1.0 by <a href="https://www.doxygen.nl">Doxygen</a> 1.15.0.</p>

</div>
