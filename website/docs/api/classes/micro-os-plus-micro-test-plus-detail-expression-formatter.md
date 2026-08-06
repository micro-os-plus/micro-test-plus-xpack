---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - class

---

<div class="doxyPage">

# `expression_formatter` Class

<p>Formats values and expressions into an owned string buffer. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
class micro_os_plus::micro_test_plus::detail::expression_formatter { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>"
</div>

## Public Constructors Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> (colours &amp;colours) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructor with colour configuration. <a href="#a9c245af63c4f86b4583a82a0dd3ef674">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aed6149e163549956985e23a3ee9e6282">expression_formatter</a> (const expression_formatter &amp;)=delete</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deleted copy constructor to prevent copying. <a href="#aed6149e163549956985e23a3ee9e6282">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a7de3044d562926e79a6039bed6230794">expression_formatter</a> (expression_formatter &amp;&amp;)=delete</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deleted move constructor to prevent moving. <a href="#a7de3044d562926e79a6039bed6230794">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Destructor Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a421fc77a0d2c9939ca7d2fdc1ba13358">~expression_formatter</a> ()=default</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Default destructor. <a href="#a421fc77a0d2c9939ca7d2fdc1ba13358">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Operators Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a4b24176d3597d73506e5bf0b71bdab2a">operator&lt;&lt;</a> (bool v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends the string representation of a boolean value. <a href="#a4b24176d3597d73506e5bf0b71bdab2a">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a6df410b7ec951a5563b1fae75ed31350">operator&lt;&lt;</a> (char c)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends a single character to the buffer. <a href="#a6df410b7ec951a5563b1fae75ed31350">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#afd1a0e24d72c0525f04e102fc2e6fb78">operator&lt;&lt;</a> (const char *s)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends a null-terminated C string to the buffer. <a href="#afd1a0e24d72c0525f04e102fc2e6fb78">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ae0eb957767a54644f4930e34027a362e">operator&lt;&lt;</a> (const detail::and_&lt; Lhs_T, Rhs_T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats a logical AND as <span class="doxyComputerOutput">(lhs and rhs)</span>. <a href="#ae0eb957767a54644f4930e34027a362e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a49ea3643cc64e40ba7af178c0dcec7c8">operator&lt;&lt;</a> (const detail::eq_&lt; Lhs_T, Rhs_T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats an equality comparison as <span class="doxyComputerOutput">lhs == rhs</span>. <a href="#a49ea3643cc64e40ba7af178c0dcec7c8">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#af9ac0ed027dc118daf43df623e7a6ad0">operator&lt;&lt;</a> (const detail::ge_&lt; Lhs_T, Rhs_T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats a greater-than-or-equal comparison as <span class="doxyComputerOutput">lhs &gt;= rhs</span>. <a href="#af9ac0ed027dc118daf43df623e7a6ad0">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a0a9cc0662059203d266ac2fc8a0150bb">operator&lt;&lt;</a> (const detail::gt_&lt; Lhs_T, Rhs_T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats a greater-than comparison as <span class="doxyComputerOutput">lhs &gt; rhs</span>. <a href="#a0a9cc0662059203d266ac2fc8a0150bb">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a8c1dff1037e52f38ba4bdd02b45a4a51">operator&lt;&lt;</a> (const detail::le_&lt; Rhs_T, Lhs_T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats a less-than-or-equal comparison as <span class="doxyComputerOutput">lhs &lt;= rhs</span>. <a href="#a8c1dff1037e52f38ba4bdd02b45a4a51">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a162bb0f550fdbc2cf37bbc26b941c5d9">operator&lt;&lt;</a> (const detail::lt_&lt; Rhs_T, Lhs_T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats a less-than comparison as <span class="doxyComputerOutput">lhs &lt; rhs</span>. <a href="#a162bb0f550fdbc2cf37bbc26b941c5d9">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#adbd36b68734e55206edbdf9478dd2118">operator&lt;&lt;</a> (const detail::ne_&lt; Lhs_T, Rhs_T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats an inequality comparison as <span class="doxyComputerOutput">lhs != rhs</span>. <a href="#adbd36b68734e55206edbdf9478dd2118">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a18779725af09a98f96a5e392688123b5">operator&lt;&lt;</a> (const detail::not_&lt; T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats a logical NOT as <span class="doxyComputerOutput">not operand</span>. <a href="#a18779725af09a98f96a5e392688123b5">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Callable_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ab49b1ec8708d9427c275edd6fe72d6b8">operator&lt;&lt;</a> (const detail::nothrow_&lt; Callable_T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats a nothrow expression as <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-exceptions/#ga798bd28001c3938784073e60dd904148">nothrow</a></span>. <a href="#ab49b1ec8708d9427c275edd6fe72d6b8">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a87d4ae11bdf27d064c45d9dd12a94cea">operator&lt;&lt;</a> (const detail::or_&lt; Lhs_T, Rhs_T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats a logical OR as <span class="doxyComputerOutput">(lhs or rhs)</span>. <a href="#a87d4ae11bdf27d064c45d9dd12a94cea">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Callable_T, class Exception_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a3d84f0a15194ead914bbf07a6e657e67">operator&lt;&lt;</a> (const detail::throws_&lt; Callable_T, Exception_T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats a typed throws expression as <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-exceptions/#gaf8f7602f40119da514be2a0bfc4b70f5">throws</a>&lt;TypeName&gt;</span>. <a href="#a3d84f0a15194ead914bbf07a6e657e67">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Callable_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ac376d5e106a5b05bdad0588a4565d4b4">operator&lt;&lt;</a> (const detail::throws_&lt; Callable_T, void &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats an untyped throws expression as <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-exceptions/#gaf8f7602f40119da514be2a0bfc4b70f5">throws</a></span>. <a href="#ac376d5e106a5b05bdad0588a4565d4b4">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a22e785a2d26b4c2a957b927f114081b8">operator&lt;&lt;</a> (const T &amp;t)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends a container's elements enclosed in braces. <a href="#a22e785a2d26b4c2a957b927f114081b8">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a9004ba636b6ef57e6f474cc7feae6af7">operator&lt;&lt;</a> (const T &amp;t)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends the value of an op expression via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac627271520bf2fe8a4c4774bcd9bf343">detail::get</a></span>. <a href="#a9004ba636b6ef57e6f474cc7feae6af7">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a35c3c186dea0017fd5afe8a2adac98a3">operator&lt;&lt;</a> (const type_traits::genuine_integral_value&lt; T &gt; &amp;v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends a genuine integral value without a type suffix. <a href="#a35c3c186dea0017fd5afe8a2adac98a3">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ae35ae1fef3c1b19f78d9d01c46e389e5">operator&lt;&lt;</a> (double v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends a double value (no suffix). <a href="#ae35ae1fef3c1b19f78d9d01c46e389e5">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a28f6feb880950d846e9d527254e019cd">operator&lt;&lt;</a> (float v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends a float value with type suffix <span class="doxyComputerOutput">"f"</span>. <a href="#a28f6feb880950d846e9d527254e019cd">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#addfdc62bee977a9bec102e7babec03e1">operator&lt;&lt;</a> (long double v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends a long double value with type suffix <span class="doxyComputerOutput">"l"</span>. <a href="#addfdc62bee977a9bec102e7babec03e1">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a50d03426268411a1481d778952bdb8f4">operator&lt;&lt;</a> (signed char c)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends a signed char value with type suffix <span class="doxyComputerOutput">"c"</span>. <a href="#a50d03426268411a1481d778952bdb8f4">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a2852a7fdaabf1036ddbeb50b2e0a23bd">operator&lt;&lt;</a> (signed int v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends a signed int value (no suffix). <a href="#a2852a7fdaabf1036ddbeb50b2e0a23bd">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a93e6a5524f5cd912acd200cf7842ddf4">operator&lt;&lt;</a> (signed long long v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends a signed long long value with type suffix <span class="doxyComputerOutput">"ll"</span>. <a href="#a93e6a5524f5cd912acd200cf7842ddf4">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#adec3880ea2146b10b4b6ff188ad0a57c">operator&lt;&lt;</a> (signed long v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends a signed long value with type suffix <span class="doxyComputerOutput">"l"</span>. <a href="#adec3880ea2146b10b4b6ff188ad0a57c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a51879a69ec3bbd2d36614f05b7991748">operator&lt;&lt;</a> (signed short v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends a signed short value with type suffix <span class="doxyComputerOutput">"s"</span>. <a href="#a51879a69ec3bbd2d36614f05b7991748">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a9f9170708f0763a39314e19902843b4b">operator&lt;&lt;</a> (std::nullptr_t)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends the string <span class="doxyComputerOutput">"nullptr"</span>. <a href="#a9f9170708f0763a39314e19902843b4b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a> (std::string_view sv)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends a string view to the buffer. <a href="#a937600e01855336e5ef437104e7ee688">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;typename T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#abbeeb41944291af910132223e1ff5376">operator&lt;&lt;</a> (T *v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends the hexadecimal address of a pointer. <a href="#abbeeb41944291af910132223e1ff5376">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a41d15d145121a646d3ec8e2a53626658">operator&lt;&lt;</a> (unsigned char c)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends an unsigned char value with type suffix <span class="doxyComputerOutput">"uc"</span>. <a href="#a41d15d145121a646d3ec8e2a53626658">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a9943e733445290a4296bd236ba5b1294">operator&lt;&lt;</a> (unsigned int v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends an unsigned int value with type suffix <span class="doxyComputerOutput">"u"</span>. <a href="#a9943e733445290a4296bd236ba5b1294">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a2f40f5b293810e4c9c55340dd7074936">operator&lt;&lt;</a> (unsigned long long v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends an unsigned long long value with type suffix <span class="doxyComputerOutput">"ull"</span>. <a href="#a2f40f5b293810e4c9c55340dd7074936">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ac2b6dfdd70318f5005035667d19814b2">operator&lt;&lt;</a> (unsigned long v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends an unsigned long value with type suffix <span class="doxyComputerOutput">"ul"</span>. <a href="#ac2b6dfdd70318f5005035667d19814b2">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a60165c67928c5bab83c4dac211b50ec4">operator&lt;&lt;</a> (unsigned short v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends an unsigned short value with type suffix <span class="doxyComputerOutput">"us"</span>. <a href="#a60165c67928c5bab83c4dac211b50ec4">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a1a4f5fbbf1f7194b61b6d1cedf2b8a62">operator=</a> (const expression_formatter &amp;)=delete</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deleted copy assignment operator to prevent copying. <a href="#a1a4f5fbbf1f7194b61b6d1cedf2b8a62">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#acf0a0ce3f89ee68096e5b104dfbd8481">operator=</a> (expression_formatter &amp;&amp;)=delete</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deleted move assignment operator to prevent moving. <a href="#acf0a0ce3f89ee68096e5b104dfbd8481">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Member Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a0c168f5da97becb4710c597eda30e2e5">append</a> (size_t count, char ch)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends a sequence of identical characters to the buffer. <a href="#a0c168f5da97becb4710c597eda30e2e5">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const char *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a364c261933561156704213bbb05a53c5">c_str</a> () const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns a pointer to the null-terminated buffer contents. <a href="#a364c261933561156704213bbb05a53c5">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a53d35068a650f572f80e098221ad9aa1">clear</a> () noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Clears the internal buffer. <a href="#a53d35068a650f572f80e098221ad9aa1">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a83494f149f2788666ba3814dd524a097">empty</a> () const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns whether the internal buffer is empty. <a href="#a83494f149f2788666ba3814dd524a097">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ac6955a882234f9427ff8a86a00514850">reserve</a> (size_t capacity)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Reserves storage in the internal buffer. <a href="#ac6955a882234f9427ff8a86a00514850">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const std::string &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#abe6a45b88b55b765a462a9f4ba464d53">str</a> () const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns a const reference to the internal buffer. <a href="#abe6a45b88b55b765a462a9f4ba464d53">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Protected Member Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">auto</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a1af55ba27a4c7967801fb4e5e7c04e2c">colour_</a> (const bool cond) const</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Selects the appropriate colour code based on a condition. <a href="#a1af55ba27a4c7967801fb4e5e7c04e2c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Protected Member Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">std::string</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The internal output buffer. <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>ANSI colour codes for output formatting. <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Formats values and expressions into an owned string buffer.</p>


<p><span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter">expression_formatter</a></span> owns a <span class="doxyComputerOutput">std::string</span> buffer and provides <span class="doxyComputerOutput">operator&lt;&lt;</span> overloads for all standard arithmetic types, character types, strings, pointers, containers, and framework expression types derived from <span class="doxyComputerOutput">detail::op</span>.</p>


<p>The numeric overloads append a type suffix (e.g., <span class="doxyComputerOutput">42u</span>, <span class="doxyComputerOutput">3l</span>, <span class="doxyComputerOutput">1.0f</span>) matching the conventions used in the existing reporter output, so that the formatted text is identical whether produced by the reporter directly or pre-formatted by a deferred reporter.</p>


<p>The class is non-copyable and non-movable to avoid accidental copying of the internal buffer.</p>


<p>Definition at line 159 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>.</p>


<div class="doxySectionDef">

## Public Constructors

### expression\_formatter() {#a9c245af63c4f86b4583a82a0dd3ef674}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::expression_formatter::expression_formatter (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a> &amp; colours)</td>
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

<p>Constructor with colour configuration.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">colours</td>
<td class="doxyParamItemDescription"><p>Reference to a <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a></span> instance for output formatting.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Initializes the <span class="doxyComputerOutput"><a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a></span> reference with the provided <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a></span> instance. The internal buffer is default-initialized to an empty string.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00168">168</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00081">81</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a9c245af63c4f86b4583a82a0dd3ef674">81</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">inline</span><span class="doxyHighlight"> <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter::expression_formatter</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a>&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a>) noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">82</span><span class="doxyLineContent"><span class="doxyHighlight">      : <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">83</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">84</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a>.</p>


<p>Referenced by <a href="#aed6149e163549956985e23a3ee9e6282">expression_formatter</a>, <a href="#a7de3044d562926e79a6039bed6230794">expression_formatter</a>, <a href="#a421fc77a0d2c9939ca7d2fdc1ba13358">~expression_formatter</a>, <a href="#a4b24176d3597d73506e5bf0b71bdab2a">operator&lt;&lt;</a>, <a href="#a6df410b7ec951a5563b1fae75ed31350">operator&lt;&lt;</a>, <a href="#afd1a0e24d72c0525f04e102fc2e6fb78">operator&lt;&lt;</a>, <a href="#ae0eb957767a54644f4930e34027a362e">operator&lt;&lt;</a>, <a href="#a49ea3643cc64e40ba7af178c0dcec7c8">operator&lt;&lt;</a>, <a href="#af9ac0ed027dc118daf43df623e7a6ad0">operator&lt;&lt;</a>, <a href="#a0a9cc0662059203d266ac2fc8a0150bb">operator&lt;&lt;</a>, <a href="#a8c1dff1037e52f38ba4bdd02b45a4a51">operator&lt;&lt;</a>, <a href="#a162bb0f550fdbc2cf37bbc26b941c5d9">operator&lt;&lt;</a>, <a href="#adbd36b68734e55206edbdf9478dd2118">operator&lt;&lt;</a>, <a href="#a18779725af09a98f96a5e392688123b5">operator&lt;&lt;</a>, <a href="#ab49b1ec8708d9427c275edd6fe72d6b8">operator&lt;&lt;</a>, <a href="#a87d4ae11bdf27d064c45d9dd12a94cea">operator&lt;&lt;</a>, <a href="#a3d84f0a15194ead914bbf07a6e657e67">operator&lt;&lt;</a>, <a href="#ac376d5e106a5b05bdad0588a4565d4b4">operator&lt;&lt;</a>, <a href="#a22e785a2d26b4c2a957b927f114081b8">operator&lt;&lt;</a>, <a href="#a35c3c186dea0017fd5afe8a2adac98a3">operator&lt;&lt;</a>, <a href="#ae35ae1fef3c1b19f78d9d01c46e389e5">operator&lt;&lt;</a>, <a href="#a28f6feb880950d846e9d527254e019cd">operator&lt;&lt;</a>, <a href="#addfdc62bee977a9bec102e7babec03e1">operator&lt;&lt;</a>, <a href="#a50d03426268411a1481d778952bdb8f4">operator&lt;&lt;</a>, <a href="#a2852a7fdaabf1036ddbeb50b2e0a23bd">operator&lt;&lt;</a>, <a href="#a93e6a5524f5cd912acd200cf7842ddf4">operator&lt;&lt;</a>, <a href="#adec3880ea2146b10b4b6ff188ad0a57c">operator&lt;&lt;</a>, <a href="#a51879a69ec3bbd2d36614f05b7991748">operator&lt;&lt;</a>, <a href="#a9f9170708f0763a39314e19902843b4b">operator&lt;&lt;</a>, <a href="#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>, <a href="#abbeeb41944291af910132223e1ff5376">operator&lt;&lt;</a>, <a href="#a41d15d145121a646d3ec8e2a53626658">operator&lt;&lt;</a>, <a href="#a9943e733445290a4296bd236ba5b1294">operator&lt;&lt;</a>, <a href="#a2f40f5b293810e4c9c55340dd7074936">operator&lt;&lt;</a>, <a href="#ac2b6dfdd70318f5005035667d19814b2">operator&lt;&lt;</a>, <a href="#a60165c67928c5bab83c4dac211b50ec4">operator&lt;&lt;</a>, <a href="#a1a4f5fbbf1f7194b61b6d1cedf2b8a62">operator=</a> and <a href="#acf0a0ce3f89ee68096e5b104dfbd8481">operator=</a>.</p>

</div>
</div>

### expression\_formatter() {#aed6149e163549956985e23a3ee9e6282}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::expression_formatter::expression_formatter (const expression_formatter &amp;)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel delete">delete</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Deleted copy constructor to prevent copying.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00173">173</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>.</p>


<p>Reference <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>.</p>

</div>
</div>

### expression\_formatter() {#a7de3044d562926e79a6039bed6230794}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::expression_formatter::expression_formatter (expression_formatter &amp;&amp;)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel delete">delete</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Deleted move constructor to prevent moving.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00178">178</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>.</p>


<p>Reference <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Destructor

### \~expression\_formatter() {#a421fc77a0d2c9939ca7d2fdc1ba13358}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::expression_formatter::~expression_formatter ()</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel default">default</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Default destructor.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00197">197</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>.</p>


<p>Reference <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Operators

### operator&lt;&lt;() {#a4b24176d3597d73506e5bf0b71bdab2a}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (bool v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends the string representation of a boolean value.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">v</td>
<td class="doxyParamItemDescription"><p>The boolean value.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Appends the string <span class="doxyComputerOutput">"true"</span> or <span class="doxyComputerOutput">"false"</span> to the internal buffer based on the value of <span class="doxyComputerOutput">v</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00235">235</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00102">102</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">102</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">103</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">104</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (v ? </span><span class="doxyHighlightStringLiteral">"true"</span><span class="doxyHighlight"> : </span><span class="doxyHighlightStringLiteral">"false"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">105</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">106</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a6df410b7ec951a5563b1fae75ed31350}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (char c)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends a single character to the buffer.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">c</td>
<td class="doxyParamItemDescription"><p>The character to append.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Appends the single character <span class="doxyComputerOutput">c</span> to the internal buffer using <span class="doxyComputerOutput">buffer_.append(1, c)</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00217">217</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00078">78</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">78</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> c)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">79</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">80</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (1, c);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">81</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">82</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#afd1a0e24d72c0525f04e102fc2e6fb78}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (const char * s)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends a null-terminated C string to the buffer.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">s</td>
<td class="doxyParamItemDescription"><p>The C string to append.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Appends the null-terminated C string <span class="doxyComputerOutput">s</span> to the internal buffer using <span class="doxyComputerOutput">buffer_.append(s)</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00226">226</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00090">90</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">90</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* s)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">91</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">92</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (s);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">93</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">94</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#ae0eb957767a54644f4930e34027a362e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/and-">detail::and_</a>&lt; Lhs_T, Rhs_T &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Formats a logical AND as <span class="doxyComputerOutput">(lhs and rhs)</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>Left-hand operand type.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>Right-hand operand type.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">op</td>
<td class="doxyParamItemDescription"><p>The logical AND expression.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>This operator overload enables the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter">reporter</a></span> to output logical conjunction (AND) expressions in a clear and structured format.</p>


<p>The left-hand side and right-hand side expressions are enclosed in parentheses and separated by the word "and", with appropriate colour highlighting applied for improved readability in test reports and diagnostics. This presentation assists in quickly identifying the components of logical assertions and facilitates efficient debugging of test failures involving compound conditions.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00505">505</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00392">392</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">392</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/and-">detail::and_&lt;Lhs_T, Rhs_T&gt;</a>&amp; op)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">393</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">394</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> (*</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; </span><span class="doxyHighlightCharLiteral">'('</span><span class="doxyHighlight"> &lt;&lt; op.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a503196c2296449a52b6f7995d4a647f5">lhs</a> () &lt;&lt; <a href="#a1af55ba27a4c7967801fb4e5e7c04e2c">colour_</a> (op) &lt;&lt; </span><span class="doxyHighlightStringLiteral">" and "</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">395</span><span class="doxyLineContent"><span class="doxyHighlight">                  &lt;&lt; <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a>.none &lt;&lt; op.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#adfe5734554daf4e5793f0708f3121284">rhs</a> () &lt;&lt; </span><span class="doxyHighlightCharLiteral">')'</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">396</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>, <a href="#a1af55ba27a4c7967801fb4e5e7c04e2c">colour_</a>, <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a503196c2296449a52b6f7995d4a647f5">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::lhs</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#adfe5734554daf4e5793f0708f3121284">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::rhs</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a49ea3643cc64e40ba7af178c0dcec7c8}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/eq-">detail::eq_</a>&lt; Lhs_T, Rhs_T &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Formats an equality comparison as <span class="doxyComputerOutput">lhs == rhs</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>Left-hand operand type.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>Right-hand operand type.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">op</td>
<td class="doxyParamItemDescription"><p>The equality expression.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>This operator overload enables the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter">reporter</a></span> to output equality comparison expressions in a clear and expressive format.</p>


<p>The left-hand side and right-hand side values are formatted and separated by the equality operator (<span class="doxyComputerOutput">==</span>), with appropriate colour highlighting applied for improved readability in test reports and diagnostics. This structured output assists in quickly identifying the values involved in equality assertions and facilitates efficient debugging of test failures.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00433">433</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00271">271</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">271</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/eq-">detail::eq_&lt;Lhs_T, Rhs_T&gt;</a>&amp; op)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">272</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">273</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> (*</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="#a1af55ba27a4c7967801fb4e5e7c04e2c">colour_</a> (op) &lt;&lt; op.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a503196c2296449a52b6f7995d4a647f5">lhs</a> () &lt;&lt; </span><span class="doxyHighlightStringLiteral">" == "</span><span class="doxyHighlight"> &lt;&lt; op.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#adfe5734554daf4e5793f0708f3121284">rhs</a> ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">274</span><span class="doxyLineContent"><span class="doxyHighlight">                  &lt;&lt; <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a>.none);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">275</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>, <a href="#a1af55ba27a4c7967801fb4e5e7c04e2c">colour_</a>, <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a503196c2296449a52b6f7995d4a647f5">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::lhs</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#adfe5734554daf4e5793f0708f3121284">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::rhs</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#af9ac0ed027dc118daf43df623e7a6ad0}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/ge-">detail::ge_</a>&lt; Lhs_T, Rhs_T &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Formats a greater-than-or-equal comparison as <span class="doxyComputerOutput">lhs &gt;= rhs</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>Left-hand operand type.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>Right-hand operand type.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">op</td>
<td class="doxyParamItemDescription"><p>The greater-than-or-equal expression.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>This operator overload enables the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter">reporter</a></span> to output greater-than-or-equal-to comparison expressions in a clear and expressive format.</p>


<p>The left-hand side and right-hand side values are formatted and separated by the greater-than-or-equal-to operator (<span class="doxyComputerOutput">&gt;=</span>), with appropriate colour highlighting applied for improved readability in test reports and diagnostics. This structured output assists in quickly identifying the values involved in greater-than-or-equal-to assertions and facilitates efficient debugging of test failures.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00469">469</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00332">332</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">332</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/ge-">detail::ge_&lt;Lhs_T, Rhs_T&gt;</a>&amp; op)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">333</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">334</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> (*</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="#a1af55ba27a4c7967801fb4e5e7c04e2c">colour_</a> (op) &lt;&lt; op.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a503196c2296449a52b6f7995d4a647f5">lhs</a> () &lt;&lt; </span><span class="doxyHighlightStringLiteral">" &gt;= "</span><span class="doxyHighlight"> &lt;&lt; op.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#adfe5734554daf4e5793f0708f3121284">rhs</a> ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">335</span><span class="doxyLineContent"><span class="doxyHighlight">                  &lt;&lt; <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a>.none);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">336</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>, <a href="#a1af55ba27a4c7967801fb4e5e7c04e2c">colour_</a>, <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a503196c2296449a52b6f7995d4a647f5">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::lhs</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#adfe5734554daf4e5793f0708f3121284">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::rhs</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a0a9cc0662059203d266ac2fc8a0150bb}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/gt-">detail::gt_</a>&lt; Lhs_T, Rhs_T &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Formats a greater-than comparison as <span class="doxyComputerOutput">lhs &gt; rhs</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>Left-hand operand type.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>Right-hand operand type.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">op</td>
<td class="doxyParamItemDescription"><p>The greater-than expression.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>This operator overload enables the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter">reporter</a></span> to output greater-than comparison expressions in a clear and expressive format.</p>


<p>The left-hand side and right-hand side values are formatted and separated by the greater-than operator (<span class="doxyComputerOutput">&gt;</span>), with appropriate colour highlighting applied for improved readability in test reports and diagnostics. This structured output assists in quickly identifying the values involved in greater-than assertions and facilitates efficient debugging of test failures.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00457">457</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00311">311</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">311</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/gt-">detail::gt_&lt;Lhs_T, Rhs_T&gt;</a>&amp; op)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">312</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">313</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> (*</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="#a1af55ba27a4c7967801fb4e5e7c04e2c">colour_</a> (op) &lt;&lt; op.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a503196c2296449a52b6f7995d4a647f5">lhs</a> () &lt;&lt; </span><span class="doxyHighlightStringLiteral">" &gt; "</span><span class="doxyHighlight"> &lt;&lt; op.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#adfe5734554daf4e5793f0708f3121284">rhs</a> ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">314</span><span class="doxyLineContent"><span class="doxyHighlight">                  &lt;&lt; <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a>.none);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">315</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>, <a href="#a1af55ba27a4c7967801fb4e5e7c04e2c">colour_</a>, <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a503196c2296449a52b6f7995d4a647f5">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::lhs</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#adfe5734554daf4e5793f0708f3121284">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::rhs</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a8c1dff1037e52f38ba4bdd02b45a4a51}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/le-">detail::le_</a>&lt; Rhs_T, Lhs_T &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Formats a less-than-or-equal comparison as <span class="doxyComputerOutput">lhs &lt;= rhs</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>Left-hand operand type.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>Right-hand operand type.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">op</td>
<td class="doxyParamItemDescription"><p>The less-than-or-equal expression.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>This operator overload enables the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter">reporter</a></span> to output less-than-or-equal-to comparison expressions in a clear and expressive format.</p>


<p>The left-hand side and right-hand side values are formatted and separated by the less-than-or-equal-to operator (<span class="doxyComputerOutput">&lt;=</span>), with appropriate colour highlighting applied for improved readability in test reports and diagnostics. This structured output assists in quickly identifying the values involved in less-than-or-equal-to assertions and facilitates efficient debugging of test failures.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00493">493</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00372">372</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">372</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/le-">detail::le_&lt;Rhs_T, Lhs_T&gt;</a>&amp; op)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">373</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">374</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> (*</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="#a1af55ba27a4c7967801fb4e5e7c04e2c">colour_</a> (op) &lt;&lt; op.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a503196c2296449a52b6f7995d4a647f5">lhs</a> () &lt;&lt; </span><span class="doxyHighlightStringLiteral">" &lt;= "</span><span class="doxyHighlight"> &lt;&lt; op.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#adfe5734554daf4e5793f0708f3121284">rhs</a> ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">375</span><span class="doxyLineContent"><span class="doxyHighlight">                  &lt;&lt; <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a>.none);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">376</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>, <a href="#a1af55ba27a4c7967801fb4e5e7c04e2c">colour_</a>, <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a503196c2296449a52b6f7995d4a647f5">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::lhs</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#adfe5734554daf4e5793f0708f3121284">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::rhs</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a162bb0f550fdbc2cf37bbc26b941c5d9}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/lt-">detail::lt_</a>&lt; Rhs_T, Lhs_T &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Formats a less-than comparison as <span class="doxyComputerOutput">lhs &lt; rhs</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>Left-hand operand type.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>Right-hand operand type.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">op</td>
<td class="doxyParamItemDescription"><p>The less-than expression.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>This operator overload enables the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter">reporter</a></span> to output less-than comparison expressions in a clear and expressive format.</p>


<p>The left-hand side and right-hand side values are formatted and separated by the less-than operator (<span class="doxyComputerOutput">&lt;</span>), with appropriate colour highlighting applied for improved readability in test reports and diagnostics. This structured output assists in quickly identifying the values involved in less-than assertions and facilitates efficient debugging of test failures.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00481">481</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00351">351</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">351</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/lt-">detail::lt_&lt;Rhs_T, Lhs_T&gt;</a>&amp; op)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">352</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">353</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> (*</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="#a1af55ba27a4c7967801fb4e5e7c04e2c">colour_</a> (op) &lt;&lt; op.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a503196c2296449a52b6f7995d4a647f5">lhs</a> () &lt;&lt; </span><span class="doxyHighlightStringLiteral">" &lt; "</span><span class="doxyHighlight"> &lt;&lt; op.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#adfe5734554daf4e5793f0708f3121284">rhs</a> ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">354</span><span class="doxyLineContent"><span class="doxyHighlight">                  &lt;&lt; <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a>.none);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">355</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>, <a href="#a1af55ba27a4c7967801fb4e5e7c04e2c">colour_</a>, <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a503196c2296449a52b6f7995d4a647f5">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::lhs</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#adfe5734554daf4e5793f0708f3121284">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::rhs</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#adbd36b68734e55206edbdf9478dd2118}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/ne-">detail::ne_</a>&lt; Lhs_T, Rhs_T &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Formats an inequality comparison as <span class="doxyComputerOutput">lhs != rhs</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>Left-hand operand type.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>Right-hand operand type.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">op</td>
<td class="doxyParamItemDescription"><p>The inequality expression.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>This operator overload enables the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter">reporter</a></span> to output inequality comparison expressions in a clear and expressive format.</p>


<p>The left-hand side and right-hand side values are formatted and separated by the inequality operator (<span class="doxyComputerOutput">!=</span>), with appropriate colour highlighting applied for improved readability in test reports and diagnostics. This structured output assists in quickly identifying the values involved in inequality assertions and facilitates efficient debugging of test failures.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00445">445</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00291">291</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">291</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/ne-">detail::ne_&lt;Lhs_T, Rhs_T&gt;</a>&amp; op)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">292</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">293</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> (*</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="#a1af55ba27a4c7967801fb4e5e7c04e2c">colour_</a> (op) &lt;&lt; op.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a503196c2296449a52b6f7995d4a647f5">lhs</a> () &lt;&lt; </span><span class="doxyHighlightStringLiteral">" != "</span><span class="doxyHighlight"> &lt;&lt; op.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#adfe5734554daf4e5793f0708f3121284">rhs</a> ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">294</span><span class="doxyLineContent"><span class="doxyHighlight">                  &lt;&lt; <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a>.none);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">295</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>, <a href="#a1af55ba27a4c7967801fb4e5e7c04e2c">colour_</a>, <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a503196c2296449a52b6f7995d4a647f5">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::lhs</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#adfe5734554daf4e5793f0708f3121284">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::rhs</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a18779725af09a98f96a5e392688123b5}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/not-">detail::not_</a>&lt; T &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Formats a logical NOT as <span class="doxyComputerOutput">not operand</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The operand type.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">op</td>
<td class="doxyParamItemDescription"><p>The logical NOT expression.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>This operator overload enhances readability and clarity by formatting the output when handling negated expressions. It applies colour styling for improved distinction and appends the negated value accordingly, ensuring that logical negations are clearly represented in test reports and diagnostics.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00528">528</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00428">428</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">428</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/not-">detail::not_&lt;T&gt;</a>&amp; op)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">429</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">430</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> (*</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="#a1af55ba27a4c7967801fb4e5e7c04e2c">colour_</a> (op) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"not "</span><span class="doxyHighlight"> &lt;&lt; op.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/unary-op-/#a6dad81524f4cc61c26a91d28aafdd8b0">operand</a> () &lt;&lt; <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a>.none);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">431</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>, <a href="#a1af55ba27a4c7967801fb4e5e7c04e2c">colour_</a>, <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/unary-op-/#a6dad81524f4cc61c26a91d28aafdd8b0">micro_os_plus::micro_test_plus::detail::unary_op_&lt; T &gt;::operand</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#ab49b1ec8708d9427c275edd6fe72d6b8}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Callable_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/nothrow-">detail::nothrow_</a>&lt; Callable_T &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Formats a nothrow expression as <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-exceptions/#ga798bd28001c3938784073e60dd904148">nothrow</a></span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Callable_T</td>
<td class="doxyParamItemDescription"><p>The callable type.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">op</td>
<td class="doxyParamItemDescription"><p>The nothrow expression.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>This operator overload formats output for expressions that do not throw exceptions. It applies colour styling for clarity and ensures a structured and concise representation of exception safety within test reports.</p>


<p>The output highlights the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-exceptions/#ga798bd28001c3938784073e60dd904148">nothrow</a></span> qualifier, making it immediately apparent when an expression is guaranteed not to throw, thereby improving the readability and professionalism of the test output.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00565">565</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00486">486</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">486</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/nothrow-">detail::nothrow_&lt;Callable_T&gt;</a>&amp; op)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">487</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">488</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> (*</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="#a1af55ba27a4c7967801fb4e5e7c04e2c">colour_</a> (op) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"nothrow"</span><span class="doxyHighlight"> &lt;&lt; <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a>.none);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">489</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>, <a href="#a1af55ba27a4c7967801fb4e5e7c04e2c">colour_</a> and <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a87d4ae11bdf27d064c45d9dd12a94cea}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/or-">detail::or_</a>&lt; Lhs_T, Rhs_T &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Formats a logical OR as <span class="doxyComputerOutput">(lhs or rhs)</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>Left-hand operand type.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>Right-hand operand type.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">op</td>
<td class="doxyParamItemDescription"><p>The logical OR expression.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>This operator overload enables the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter">reporter</a></span> to output logical disjunction (OR) expressions in a clear and structured format.</p>


<p>The left-hand side and right-hand side expressions are enclosed in parentheses and separated by the word "or", with appropriate colour highlighting applied for improved readability in test reports and diagnostics. This presentation assists in quickly identifying the components of logical assertions and facilitates efficient debugging of test failures involving compound conditions.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00517">517</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00412">412</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">412</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/or-">detail::or_&lt;Lhs_T, Rhs_T&gt;</a>&amp; op)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">413</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">414</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> (*</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; </span><span class="doxyHighlightCharLiteral">'('</span><span class="doxyHighlight"> &lt;&lt; op.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a503196c2296449a52b6f7995d4a647f5">lhs</a> () &lt;&lt; <a href="#a1af55ba27a4c7967801fb4e5e7c04e2c">colour_</a> (op) &lt;&lt; </span><span class="doxyHighlightStringLiteral">" or "</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">415</span><span class="doxyLineContent"><span class="doxyHighlight">                  &lt;&lt; <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a>.none &lt;&lt; op.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#adfe5734554daf4e5793f0708f3121284">rhs</a> () &lt;&lt; </span><span class="doxyHighlightCharLiteral">')'</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">416</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>, <a href="#a1af55ba27a4c7967801fb4e5e7c04e2c">colour_</a>, <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#a503196c2296449a52b6f7995d4a647f5">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::lhs</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op-/#adfe5734554daf4e5793f0708f3121284">micro_os_plus::micro_test_plus::detail::binary_op_&lt; Lhs_T, Rhs_T &gt;::rhs</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a3d84f0a15194ead914bbf07a6e657e67}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Callable_T, class Exception_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/throws-">detail::throws_</a>&lt; Callable_T, Exception_T &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Formats a typed throws expression as <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-exceptions/#gaf8f7602f40119da514be2a0bfc4b70f5">throws</a>&lt;TypeName&gt;</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Callable_T</td>
<td class="doxyParamItemDescription"><p>The callable type.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Exception_T</td>
<td class="doxyParamItemDescription"><p>The expected exception type.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">op</td>
<td class="doxyParamItemDescription"><p>The throws expression.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>This operator overload provides structured output for expressions that may throw exceptions. It applies colour styling for clarity and includes the exception type name for precise identification.</p>


<p>When invoked, the output highlights the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-exceptions/#gaf8f7602f40119da514be2a0bfc4b70f5">throws</a></span> qualifier along with the specific exception type, making it immediately apparent which exception is expected. This enhances the readability and professionalism of test reports, and assists in the precise identification and debugging of exception-related test cases.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00543">543</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00448">448</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">448</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">449</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/throws-">detail::throws_&lt;Callable_T, Exception_T&gt;</a>&amp; op)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">450</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">451</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> (*</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="#a1af55ba27a4c7967801fb4e5e7c04e2c">colour_</a> (op) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"throws&lt;"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">452</span><span class="doxyLineContent"><span class="doxyHighlight">                  &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/reflection/#a6580ad54ad22a1d3ab43a1d9d49d1f26">reflection::type_name&lt;Exception_T&gt;</a> () &lt;&lt; </span><span class="doxyHighlightStringLiteral">"&gt;"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">453</span><span class="doxyLineContent"><span class="doxyHighlight">                  &lt;&lt; <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a>.none);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">454</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>, <a href="#a1af55ba27a4c7967801fb4e5e7c04e2c">colour_</a>, <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/reflection/#a6580ad54ad22a1d3ab43a1d9d49d1f26">micro_os_plus::micro_test_plus::reflection::type_name</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#ac376d5e106a5b05bdad0588a4565d4b4}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Callable_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/throws-">detail::throws_</a>&lt; Callable_T, void &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Formats an untyped throws expression as <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-exceptions/#gaf8f7602f40119da514be2a0bfc4b70f5">throws</a></span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Callable_T</td>
<td class="doxyParamItemDescription"><p>The callable type.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">op</td>
<td class="doxyParamItemDescription"><p>The throws expression.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>This operator overload formats output for expressions that may throw exceptions. It applies colour styling for clarity and ensures a structured representation of the exception handling mechanism.</p>


<p>When invoked, the output highlights the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-exceptions/#gaf8f7602f40119da514be2a0bfc4b70f5">throws</a></span> qualifier, making it immediately apparent when an expression is expected to throw, thereby improving the readability and professionalism of the test output.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00554">554</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00468">468</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">468</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">469</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/throws-">detail::throws_&lt;Callable_T, void&gt;</a>&amp; op)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">470</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">471</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> (*</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="#a1af55ba27a4c7967801fb4e5e7c04e2c">colour_</a> (op) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"throws"</span><span class="doxyHighlight"> &lt;&lt; <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a>.none);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">472</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>, <a href="#a1af55ba27a4c7967801fb4e5e7c04e2c">colour_</a> and <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a22e785a2d26b4c2a957b927f114081b8}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (const T &amp; t)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends a container's elements enclosed in braces.</p>


<p>Elements are formatted as <span class="doxyComputerOutput">{ e1, e2, … }</span> by iterating the container and recursing through <span class="doxyComputerOutput">operator&lt;&lt;</span> for each element.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>A container type satisfying <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/type-traits/container-like">type_traits::container_like</a></span> that does not have <span class="doxyComputerOutput">npos</span>.</p></td>
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
<td class="doxyParamItemDescription"><p>The container.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00418">418</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>.</p>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>, <a href="#a0c168f5da97becb4710c597eda30e2e5">append</a>, <a href="#a364c261933561156704213bbb05a53c5">c_str</a>, <a href="#a53d35068a650f572f80e098221ad9aa1">clear</a>, <a href="#a1af55ba27a4c7967801fb4e5e7c04e2c">colour_</a>, <a href="#a83494f149f2788666ba3814dd524a097">empty</a> and <a href="#ac6955a882234f9427ff8a86a00514850">reserve</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a9004ba636b6ef57e6f474cc7feae6af7}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (const T &amp; t)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends the value of an op expression via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac627271520bf2fe8a4c4774bcd9bf343">detail::get</a></span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>An expression type satisfying <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/type-traits/is-op">type_traits::is_op</a>&lt;T&gt;</span>.</p></td>
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
<td class="doxyParamItemDescription"><p>The expression object.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Delegates to <span class="doxyComputerOutput">detail::get(t)</span> to obtain the displayable value of an op expression, then streams it through <span class="doxyComputerOutput">operator&lt;&lt;</span> to format it into the buffer.</p>


<p>Iterates the container and formats each element separated by <span class="doxyComputerOutput">", "</span>, surrounded by <span class="doxyComputerOutput">{</span> and <span class="doxyComputerOutput">}</span>. Each element is streamed through <span class="doxyComputerOutput">operator&lt;&lt;</span>, which recurses as needed for nested types.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00389">389</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00213">213</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">213</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; t)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">214</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">215</span><span class="doxyLineContent"><span class="doxyHighlight">    *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac627271520bf2fe8a4c4774bcd9bf343">detail::get</a> (t);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">216</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">217</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac627271520bf2fe8a4c4774bcd9bf343">micro_os_plus::micro_test_plus::detail::get</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a35c3c186dea0017fd5afe8a2adac98a3}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/genuine-integral-value">type_traits::genuine_integral_value</a>&lt; T &gt; &amp; v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends a genuine integral value without a type suffix.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The underlying integral type.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">v</td>
<td class="doxyParamItemDescription"><p>The strongly-typed integral value.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Casts the underlying integral value to <span class="doxyComputerOutput">long long</span> and formats it without a type suffix, appending the result to the buffer.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00400">400</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00226">226</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">226</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">227</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/genuine-integral-value">type_traits::genuine_integral_value&lt;T&gt;</a>&amp; v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">228</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">229</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">detail::append_number_</a> (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (v.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-base-/#aedc41334c71b7711435aee0cb8f44fb3">get</a> ()));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">230</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">231</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">micro_os_plus::micro_test_plus::detail::append_number_</a>, <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value-base-/#aedc41334c71b7711435aee0cb8f44fb3">micro_os_plus::micro_test_plus::type_traits::value_base_&lt; T &gt;::get</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#ae35ae1fef3c1b19f78d9d01c46e389e5}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (double v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends a double value (no suffix).</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">v</td>
<td class="doxyParamItemDescription"><p>The double value.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Converts <span class="doxyComputerOutput">v</span> to its string representation via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">append_number_()</a></span> without a type suffix.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00350">350</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00267">267</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">267</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">double</span><span class="doxyHighlight"> v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">268</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">269</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">detail::append_number_</a> (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">270</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">271</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">micro_os_plus::micro_test_plus::detail::append_number_</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a28f6feb880950d846e9d527254e019cd}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (float v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends a float value with type suffix <span class="doxyComputerOutput">"f"</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">v</td>
<td class="doxyParamItemDescription"><p>The float value.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Converts <span class="doxyComputerOutput">v</span> to its string representation via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">append_number_()</a></span> and appends the type suffix <span class="doxyComputerOutput">"f"</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00341">341</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00254">254</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">254</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">float</span><span class="doxyHighlight"> v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">255</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">256</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">detail::append_number_</a> (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">257</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"f"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">258</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">259</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">micro_os_plus::micro_test_plus::detail::append_number_</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#addfdc62bee977a9bec102e7babec03e1}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (long double v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends a long double value with type suffix <span class="doxyComputerOutput">"l"</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">v</td>
<td class="doxyParamItemDescription"><p>The long double value.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Converts <span class="doxyComputerOutput">v</span> to its string representation via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">append_number_()</a></span> and appends the type suffix <span class="doxyComputerOutput">"l"</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00359">359</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00279">279</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">279</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">double</span><span class="doxyHighlight"> v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">280</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">281</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">detail::append_number_</a> (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">282</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"l"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">283</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">284</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">micro_os_plus::micro_test_plus::detail::append_number_</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a50d03426268411a1481d778952bdb8f4}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (signed char c)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends a signed char value with type suffix <span class="doxyComputerOutput">"c"</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">c</td>
<td class="doxyParamItemDescription"><p>The signed char value.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Converts <span class="doxyComputerOutput">c</span> to its decimal string representation via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">append_number_()</a></span> and appends the type suffix <span class="doxyComputerOutput">"c"</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00251">251</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00125">125</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">125</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">signed</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> c)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">126</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">127</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">detail::append_number_</a> (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, c);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">128</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"c"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">129</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">130</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">micro_os_plus::micro_test_plus::detail::append_number_</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a2852a7fdaabf1036ddbeb50b2e0a23bd}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (signed int v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends a signed int value (no suffix).</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">v</td>
<td class="doxyParamItemDescription"><p>The signed int value.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Converts <span class="doxyComputerOutput">v</span> to its decimal string representation via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">append_number_()</a></span> without a type suffix.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00287">287</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00177">177</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">177</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">signed</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">178</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">179</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">detail::append_number_</a> (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">180</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">181</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">micro_os_plus::micro_test_plus::detail::append_number_</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a93e6a5524f5cd912acd200cf7842ddf4}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (signed long long v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends a signed long long value with type suffix <span class="doxyComputerOutput">"ll"</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">v</td>
<td class="doxyParamItemDescription"><p>The signed long long value.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Converts <span class="doxyComputerOutput">v</span> to its decimal string representation via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">append_number_()</a></span> and appends the type suffix <span class="doxyComputerOutput">"ll"</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00323">323</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00228">228</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">228</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">signed</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">229</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">230</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">detail::append_number_</a> (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">231</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"ll"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">232</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">233</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">micro_os_plus::micro_test_plus::detail::append_number_</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#adec3880ea2146b10b4b6ff188ad0a57c}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (signed long v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends a signed long value with type suffix <span class="doxyComputerOutput">"l"</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">v</td>
<td class="doxyParamItemDescription"><p>The signed long value.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Converts <span class="doxyComputerOutput">v</span> to its decimal string representation via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">append_number_()</a></span> and appends the type suffix <span class="doxyComputerOutput">"l"</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00305">305</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00202">202</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">202</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">signed</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">203</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">204</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">detail::append_number_</a> (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">205</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"l"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">206</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">207</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">micro_os_plus::micro_test_plus::detail::append_number_</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a51879a69ec3bbd2d36614f05b7991748}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (signed short v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends a signed short value with type suffix <span class="doxyComputerOutput">"s"</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">v</td>
<td class="doxyParamItemDescription"><p>The signed short value.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Converts <span class="doxyComputerOutput">v</span> to its decimal string representation via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">append_number_()</a></span> and appends the type suffix <span class="doxyComputerOutput">"s"</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00269">269</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00151">151</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">151</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">signed</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">short</span><span class="doxyHighlight"> v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">152</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">153</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">detail::append_number_</a> (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">154</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"s"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">155</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">156</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">micro_os_plus::micro_test_plus::detail::append_number_</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a9f9170708f0763a39314e19902843b4b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (std::nullptr_t)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends the string <span class="doxyComputerOutput">"nullptr"</span>.</p>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Appends the string <span class="doxyComputerOutput">"nullptr"</span> to the internal buffer.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00243">243</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00113">113</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">113</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(std::nullptr_t)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">114</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">115</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"nullptr"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">116</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">117</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a937600e01855336e5ef437104e7ee688}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (std::string_view sv)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends a string view to the buffer.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">sv</td>
<td class="doxyParamItemDescription"><p>The string view to append.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Appends the contents of the <span class="doxyComputerOutput">std::string_view</span> directly to the internal buffer using <span class="doxyComputerOutput">buffer_.append(sv)</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00208">208</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00066">66</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">66</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(std::string_view sv)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">67</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">68</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (sv);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">69</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">70</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#abbeeb41944291af910132223e1ff5376}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;typename T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (T * v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends the hexadecimal address of a pointer.</p>


<p>Null pointers are rendered as <span class="doxyComputerOutput">"0x0"</span>. Non-null pointers are formatted with <span class="doxyComputerOutput">snprintf</span> using the <span class="doxyComputerOutput">p</span> specifier.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The type pointed to.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">v</td>
<td class="doxyParamItemDescription"><p>The pointer value.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Null pointers are rendered as <span class="doxyComputerOutput">"0x0"</span> to avoid platform-specific representations such as <span class="doxyComputerOutput">"(nil)"</span> on Linux/glibc. Non-null pointers are formatted as a hexadecimal address using <span class="doxyComputerOutput">snprintf</span> with the <span class="doxyComputerOutput">p</span> specifier.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00377">377</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00177">177</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">177</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(T* v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">178</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">179</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (v == </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">180</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">181</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"0x0"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">182</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">183</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">184</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">185</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">186</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">187</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">188</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">189</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">190</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">191</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">192</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">193</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> buff[20];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">194</span><span class="doxyLineContent"><span class="doxyHighlight">    snprintf (buff, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (buff), </span><span class="doxyHighlightStringLiteral">"%p"</span><span class="doxyHighlight">, </span><span class="doxyHighlightKeyword">reinterpret_cast&lt;</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">*</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (v));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">195</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (buff);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">196</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">197</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">198</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">199</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">200</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">201</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">202</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a41d15d145121a646d3ec8e2a53626658}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (unsigned char c)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends an unsigned char value with type suffix <span class="doxyComputerOutput">"uc"</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">c</td>
<td class="doxyParamItemDescription"><p>The unsigned char value.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Converts <span class="doxyComputerOutput">c</span> to its decimal string representation via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">append_number_()</a></span> and appends the type suffix <span class="doxyComputerOutput">"uc"</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00260">260</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00138">138</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">138</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> c)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">139</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">140</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">detail::append_number_</a> (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, c);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">141</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"uc"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">142</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">143</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">micro_os_plus::micro_test_plus::detail::append_number_</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a9943e733445290a4296bd236ba5b1294}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (unsigned int v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends an unsigned int value with type suffix <span class="doxyComputerOutput">"u"</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">v</td>
<td class="doxyParamItemDescription"><p>The unsigned int value.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Converts <span class="doxyComputerOutput">v</span> to its decimal string representation via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">append_number_()</a></span> and appends the type suffix <span class="doxyComputerOutput">"u"</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00296">296</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00189">189</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">189</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">190</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">191</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">detail::append_number_</a> (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">192</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"u"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">193</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">194</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">micro_os_plus::micro_test_plus::detail::append_number_</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a2f40f5b293810e4c9c55340dd7074936}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (unsigned long long v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends an unsigned long long value with type suffix <span class="doxyComputerOutput">"ull"</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">v</td>
<td class="doxyParamItemDescription"><p>The unsigned long long value.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Converts <span class="doxyComputerOutput">v</span> to its decimal string representation via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">append_number_()</a></span> and appends the type suffix <span class="doxyComputerOutput">"ull"</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00332">332</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00241">241</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">241</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">242</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">243</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">detail::append_number_</a> (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">244</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"ull"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">245</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">246</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">micro_os_plus::micro_test_plus::detail::append_number_</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#ac2b6dfdd70318f5005035667d19814b2}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (unsigned long v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends an unsigned long value with type suffix <span class="doxyComputerOutput">"ul"</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">v</td>
<td class="doxyParamItemDescription"><p>The unsigned long value.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Converts <span class="doxyComputerOutput">v</span> to its decimal string representation via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">append_number_()</a></span> and appends the type suffix <span class="doxyComputerOutput">"ul"</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00314">314</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00215">215</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">215</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">216</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">217</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">detail::append_number_</a> (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">218</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"ul"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">219</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">220</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">micro_os_plus::micro_test_plus::detail::append_number_</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a60165c67928c5bab83c4dac211b50ec4}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (unsigned short v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends an unsigned short value with type suffix <span class="doxyComputerOutput">"us"</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">v</td>
<td class="doxyParamItemDescription"><p>The unsigned short value.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Converts <span class="doxyComputerOutput">v</span> to its decimal string representation via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">append_number_()</a></span> and appends the type suffix <span class="doxyComputerOutput">"us"</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00278">278</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00164">164</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">164</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">short</span><span class="doxyHighlight"> v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">165</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">166</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">detail::append_number_</a> (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">167</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"us"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">168</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">169</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">micro_os_plus::micro_test_plus::detail::append_number_</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

</div>
</div>

### operator=() {#a1a4f5fbbf1f7194b61b6d1cedf2b8a62}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator= (const <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel delete">delete</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Deleted copy assignment operator to prevent copying.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00184">184</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>.</p>


<p>Reference <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>.</p>

</div>
</div>

### operator=() {#acf0a0ce3f89ee68096e5b104dfbd8481}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator= (<a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a> &amp;&amp;)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel delete">delete</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Deleted move assignment operator to prevent moving.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00191">191</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>.</p>


<p>Reference <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Member Functions

### append() {#a0c168f5da97becb4710c597eda30e2e5}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::expression_formatter::append (size_t count, char ch)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends a sequence of identical characters to the buffer.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">count</td>
<td class="doxyParamItemDescription"><p>The number of characters to append.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">ch</td>
<td class="doxyParamItemDescription"><p>The character to repeat.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Appends <span class="doxyComputerOutput">count</span> repetitions of <span class="doxyComputerOutput">ch</span> to the internal buffer by delegating to <span class="doxyComputerOutput">buffer_.append(count, ch)</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00624">624</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00150">150</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a0c168f5da97becb4710c597eda30e2e5">150</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a0c168f5da97becb4710c597eda30e2e5">expression_formatter::append</a> (</span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> count, </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> ch)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">151</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">152</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (count, ch);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">153</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>


<p>Referenced by <a href="#a22e785a2d26b4c2a957b927f114081b8">operator&lt;&lt;</a>.</p>

</div>
</div>

### c\_str() {#a364c261933561156704213bbb05a53c5}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const char * micro_os_plus::micro_test_plus::detail::expression_formatter::c_str ()</td>
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

<p>Returns a pointer to the null-terminated buffer contents.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Pointer to the null-terminated character array.</p></dd>
</dl>


<p>Returns <span class="doxyComputerOutput">buffer_.c_str()</span>, providing a pointer to the null-terminated contents of the internal buffer.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00591">591</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00117">117</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a364c261933561156704213bbb05a53c5">117</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a364c261933561156704213bbb05a53c5">expression_formatter::c_str</a> () const noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">118</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">119</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.c_str ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">120</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>


<p>Referenced by <a href="#a22e785a2d26b4c2a957b927f114081b8">operator&lt;&lt;</a>.</p>

</div>
</div>

### clear() {#a53d35068a650f572f80e098221ad9aa1}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::expression_formatter::clear ()</td>
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

<p>Clears the internal buffer.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Calls <span class="doxyComputerOutput">buffer_.clear()</span>, resetting the buffer length to zero without releasing the allocated storage.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00602">602</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00128">128</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a53d35068a650f572f80e098221ad9aa1">128</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a53d35068a650f572f80e098221ad9aa1">expression_formatter::clear</a> () noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">129</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">130</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.clear ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">131</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter/#a0d6bc295723916664b22f60d783b85b0">micro_os_plus::micro_test_plus::detail::deferred_reporter::deferred_reporter</a> and <a href="#a22e785a2d26b4c2a957b927f114081b8">operator&lt;&lt;</a>.</p>

</div>
</div>

### empty() {#a83494f149f2788666ba3814dd524a097}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::detail::expression_formatter::empty ()</td>
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

<p>Returns whether the internal buffer is empty.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Return Values</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">true</td>
<td class="doxyParamItemDescription"><p>The buffer contains no characters.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">false</td>
<td class="doxyParamItemDescription"><p>The buffer contains at least one character.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Returns <span class="doxyComputerOutput">buffer_.empty()</span>, indicating whether the accumulated string has zero length.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00613">613</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00139">139</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a83494f149f2788666ba3814dd524a097">139</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a83494f149f2788666ba3814dd524a097">expression_formatter::empty</a> () const noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">140</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">141</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.empty ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">142</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>


<p>Referenced by <a href="#a22e785a2d26b4c2a957b927f114081b8">operator&lt;&lt;</a>.</p>

</div>
</div>

### reserve() {#ac6955a882234f9427ff8a86a00514850}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::expression_formatter::reserve (size_t capacity)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Reserves storage in the internal buffer.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">capacity</td>
<td class="doxyParamItemDescription"><p>The minimum capacity to reserve.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Calls <span class="doxyComputerOutput">buffer_.reserve(capacity)</span> to pre-allocate storage, reducing subsequent dynamic allocations.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00634">634</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00161">161</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ac6955a882234f9427ff8a86a00514850">161</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ac6955a882234f9427ff8a86a00514850">expression_formatter::reserve</a> (</span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> capacity)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">162</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">163</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.reserve (capacity);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">164</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>


<p>Referenced by <a href="#a22e785a2d26b4c2a957b927f114081b8">operator&lt;&lt;</a>.</p>

</div>
</div>

### str() {#abe6a45b88b55b765a462a9f4ba464d53}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const std::string &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::str ()</td>
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

<p>Returns a const reference to the internal buffer.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Const reference to the accumulated string.</p></dd>
</dl>


<p>Returns a const reference to the internal <span class="doxyComputerOutput"><a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a></span> string.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00581">581</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00106">106</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#abe6a45b88b55b765a462a9f4ba464d53">106</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#abe6a45b88b55b765a462a9f4ba464d53">expression_formatter::str</a> () const noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">107</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">108</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">109</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Protected Member Functions

### colour\_() {#a1af55ba27a4c7967801fb4e5e7c04e2c}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::detail::expression_formatter::colour_ (const bool cond)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel protected">protected</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Selects the appropriate colour code based on a condition.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">cond</td>
<td class="doxyParamItemDescription"><p>Boolean value indicating pass (true) or fail (false).</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The corresponding ANSI colour code as a string.</p></dd>
</dl>


<p>Returns the ANSI colour code for pass or fail, depending on the boolean condition provided.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00644">644</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00094">94</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a1af55ba27a4c7967801fb4e5e7c04e2c">94</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a1af55ba27a4c7967801fb4e5e7c04e2c">expression_formatter::colour_</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> cond)</span><span class="doxyHighlightKeyword"> const</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">95</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">  </span><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">96</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> cond ? <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a>.pass : <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a>.fail;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">97</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a>.</p>


<p>Referenced by <a href="#ae0eb957767a54644f4930e34027a362e">operator&lt;&lt;</a>, <a href="#a49ea3643cc64e40ba7af178c0dcec7c8">operator&lt;&lt;</a>, <a href="#af9ac0ed027dc118daf43df623e7a6ad0">operator&lt;&lt;</a>, <a href="#a0a9cc0662059203d266ac2fc8a0150bb">operator&lt;&lt;</a>, <a href="#a8c1dff1037e52f38ba4bdd02b45a4a51">operator&lt;&lt;</a>, <a href="#a162bb0f550fdbc2cf37bbc26b941c5d9">operator&lt;&lt;</a>, <a href="#adbd36b68734e55206edbdf9478dd2118">operator&lt;&lt;</a>, <a href="#a18779725af09a98f96a5e392688123b5">operator&lt;&lt;</a>, <a href="#ab49b1ec8708d9427c275edd6fe72d6b8">operator&lt;&lt;</a>, <a href="#a87d4ae11bdf27d064c45d9dd12a94cea">operator&lt;&lt;</a>, <a href="#a3d84f0a15194ead914bbf07a6e657e67">operator&lt;&lt;</a>, <a href="#ac376d5e106a5b05bdad0588a4565d4b4">operator&lt;&lt;</a> and <a href="#a22e785a2d26b4c2a957b927f114081b8">operator&lt;&lt;</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Protected Member Attributes

### buffer\_ {#a1e8f6c298a6a12d07bdb9afd47c9c52c}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::string micro_os_plus::micro_test_plus::detail::expression_formatter::buffer_ {}</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel protected">protected</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The internal output buffer.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00654">654</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">654</a></span><span class="doxyLineContent"><span class="doxyHighlight">      std::</span><span class="doxyHighlightKeywordType">string</span><span class="doxyHighlight"> <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>{};</span></span></div>

</div>


<p>Referenced by <a href="#a0c168f5da97becb4710c597eda30e2e5">append</a>, <a href="#a364c261933561156704213bbb05a53c5">c_str</a>, <a href="#a53d35068a650f572f80e098221ad9aa1">clear</a>, <a href="#a83494f149f2788666ba3814dd524a097">empty</a>, <a href="#a4b24176d3597d73506e5bf0b71bdab2a">operator&lt;&lt;</a>, <a href="#a6df410b7ec951a5563b1fae75ed31350">operator&lt;&lt;</a>, <a href="#afd1a0e24d72c0525f04e102fc2e6fb78">operator&lt;&lt;</a>, <a href="#a35c3c186dea0017fd5afe8a2adac98a3">operator&lt;&lt;</a>, <a href="#ae35ae1fef3c1b19f78d9d01c46e389e5">operator&lt;&lt;</a>, <a href="#a28f6feb880950d846e9d527254e019cd">operator&lt;&lt;</a>, <a href="#addfdc62bee977a9bec102e7babec03e1">operator&lt;&lt;</a>, <a href="#a50d03426268411a1481d778952bdb8f4">operator&lt;&lt;</a>, <a href="#a2852a7fdaabf1036ddbeb50b2e0a23bd">operator&lt;&lt;</a>, <a href="#a93e6a5524f5cd912acd200cf7842ddf4">operator&lt;&lt;</a>, <a href="#adec3880ea2146b10b4b6ff188ad0a57c">operator&lt;&lt;</a>, <a href="#a51879a69ec3bbd2d36614f05b7991748">operator&lt;&lt;</a>, <a href="#a9f9170708f0763a39314e19902843b4b">operator&lt;&lt;</a>, <a href="#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>, <a href="#abbeeb41944291af910132223e1ff5376">operator&lt;&lt;</a>, <a href="#a41d15d145121a646d3ec8e2a53626658">operator&lt;&lt;</a>, <a href="#a9943e733445290a4296bd236ba5b1294">operator&lt;&lt;</a>, <a href="#a2f40f5b293810e4c9c55340dd7074936">operator&lt;&lt;</a>, <a href="#ac2b6dfdd70318f5005035667d19814b2">operator&lt;&lt;</a>, <a href="#a60165c67928c5bab83c4dac211b50ec4">operator&lt;&lt;</a>, <a href="#ac6955a882234f9427ff8a86a00514850">reserve</a> and <a href="#abe6a45b88b55b765a462a9f4ba464d53">str</a>.</p>

</div>
</div>

### colours\_ {#ae4fe1389ad411399cf776f2ed7a7cd11}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">colours&amp; micro_os_plus::micro_test_plus::detail::expression_formatter::colours_</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel protected">protected</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>ANSI colour codes for output formatting.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00649">649</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ae4fe1389ad411399cf776f2ed7a7cd11">649</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a>&amp; <a href="#ae4fe1389ad411399cf776f2ed7a7cd11">colours_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#a9c245af63c4f86b4583a82a0dd3ef674">expression_formatter</a>, <a href="#a1af55ba27a4c7967801fb4e5e7c04e2c">colour_</a>, <a href="#ae0eb957767a54644f4930e34027a362e">operator&lt;&lt;</a>, <a href="#a49ea3643cc64e40ba7af178c0dcec7c8">operator&lt;&lt;</a>, <a href="#af9ac0ed027dc118daf43df623e7a6ad0">operator&lt;&lt;</a>, <a href="#a0a9cc0662059203d266ac2fc8a0150bb">operator&lt;&lt;</a>, <a href="#a8c1dff1037e52f38ba4bdd02b45a4a51">operator&lt;&lt;</a>, <a href="#a162bb0f550fdbc2cf37bbc26b941c5d9">operator&lt;&lt;</a>, <a href="#adbd36b68734e55206edbdf9478dd2118">operator&lt;&lt;</a>, <a href="#a18779725af09a98f96a5e392688123b5">operator&lt;&lt;</a>, <a href="#ab49b1ec8708d9427c275edd6fe72d6b8">operator&lt;&lt;</a>, <a href="#a87d4ae11bdf27d064c45d9dd12a94cea">operator&lt;&lt;</a>, <a href="#a3d84f0a15194ead914bbf07a6e657e67">operator&lt;&lt;</a> and <a href="#ac376d5e106a5b05bdad0588a4565d4b4">operator&lt;&lt;</a>.</p>

</div>
</div>

</div>

<hr/>

The documentation for this class was generated from the following files:

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.2 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
