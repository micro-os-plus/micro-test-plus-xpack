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
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt; ... &gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#ga6f792d4a05a9b4e2e5b15c21905639f4">operator and</a> (const Lhs_T &amp;lhs, const Rhs_T &amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Logical <span class="doxyComputerOutput">&amp;&amp;</span> (and) operator. Matches only if at least one operand is of local type (derived from local <span class="doxyComputerOutput">op</span>). <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#ga6f792d4a05a9b4e2e5b15c21905639f4">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt; ... &gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#ga76287e126ef9eaf3039d970d70f3a436">operator not</a> (const T &amp;t)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Logical <span class="doxyComputerOutput">!</span> (not) operator. Matches only if the operand is of local type (derived from local <span class="doxyComputerOutput">op</span>). <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#ga76287e126ef9eaf3039d970d70f3a436">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt; ... &gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#gaaad46363338988f9080425b0d327b779">operator or</a> (const Lhs_T &amp;lhs, const Rhs_T &amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Logical <span class="doxyComputerOutput">||</span> (or) operator. Matches only if at least one operand is of local type (derived from local <span class="doxyComputerOutput">op</span>). <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#gaaad46363338988f9080425b0d327b779">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt; ... &gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#gae2090b8535bb7860e6104347b2d9f4e6">operator!=</a> (const Lhs_T &amp;lhs, const Rhs_T &amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Non-equality operator for custom types. Matches only if at least one operand is of local type. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#gae2090b8535bb7860e6104347b2d9f4e6">More...</a></p>
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
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt; ... &gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-container-operators/#gac48b765b41388c3ebe1a996f9a05aaf8">operator!=</a> (T &amp;&amp;lhs, T &amp;&amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Non-equality operator for containers. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-container-operators/#gac48b765b41388c3ebe1a996f9a05aaf8">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt; ... &gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#gad934faf2be89b200f4d286c26c043a29">operator&lt;</a> (const Lhs_T &amp;lhs, const Rhs_T &amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Less than operator. Matches only if at least one operand is of local type (derived from local <span class="doxyComputerOutput">op</span>). <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#gad934faf2be89b200f4d286c26c043a29">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt; ... &gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#ga7862426cbe47cb764473e8bc9f49c0a9">operator&lt;=</a> (const Lhs_T &amp;lhs, const Rhs_T &amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Less than or equal operator. Matches only if at least one operand is of local type (derived from local <span class="doxyComputerOutput">op</span>). <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#ga7862426cbe47cb764473e8bc9f49c0a9">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt; ... &gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#ga26bc1232c48df9b79463025f66da5f1f">operator==</a> (const Lhs_T &amp;lhs, const Rhs_T &amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Equality operator for custom types. Matches only if at least one operand is of local type. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#ga26bc1232c48df9b79463025f66da5f1f">More...</a></p>
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
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt; ... &gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-container-operators/#gaac06b4166dbd6e2b62a744878903eee8">operator==</a> (T &amp;&amp;lhs, T &amp;&amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Equality operator for containers. <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-container-operators/#gaac06b4166dbd6e2b62a744878903eee8">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt; ... &gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#gabd2a0c082adee2dbdd69043ba8d34dcd">operator&gt;</a> (const Lhs_T &amp;lhs, const Rhs_T &amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Greater than operator. Matches only if at least one operand is of local type (derived from local <span class="doxyComputerOutput">op</span>). <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#gabd2a0c082adee2dbdd69043ba8d34dcd">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt; ... &gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#ga676092b57233f1137778ee9c38e24a46">operator&gt;=</a> (const Lhs_T &amp;lhs, const Rhs_T &amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Greater than or equal operator. Matches only if at least one operand is of local type (derived from local <span class="doxyComputerOutput">op</span>). <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-operators/#ga676092b57233f1137778ee9c38e24a46">More...</a></p>
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

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 1.1.0 by <a href="https://www.doxygen.nl">Doxygen</a> 1.14.0.</p>

</div>
