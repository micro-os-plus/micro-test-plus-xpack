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

## Friends Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aec75a9652b7e98188d506c462aa73e19">check_result</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The check result, which formats its expression and its message. <a href="#aec75a9652b7e98188d506c462aa73e19">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">struct</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a97203c5c0e22fec0ca6a7cff1f911862">plain_text</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The plain text writer, for the names of the test cases. <a href="#a97203c5c0e22fec0ca6a7cff1f911862">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Constructors Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> (const colours &amp;colours) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructor with colour configuration. <a href="#a4c72fc8eae7aab4545122235816eb03e">More...</a></p>
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

## Private Constructors Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a5c2acf2640374b8d971193eae264c26c">expression_formatter</a> (std::string &amp;&amp;buffer) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructs a formatter in the plain mode, for a message. <a href="#a5c2acf2640374b8d971193eae264c26c">More...</a></p>
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
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
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
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a6df410b7ec951a5563b1fae75ed31350">operator&lt;&lt;</a> (char c)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends a character, as a quoted literal, to the buffer. <a href="#a6df410b7ec951a5563b1fae75ed31350">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a66178d7bc2ba82aa370731f91381e2e2">operator&lt;&lt;</a> (char16_t c)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends a UTF-16 code unit, as a quoted <span class="doxyComputerOutput">u</span> literal, to the buffer. <a href="#a66178d7bc2ba82aa370731f91381e2e2">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aa273723118d3fc995eb3e2929d78f280">operator&lt;&lt;</a> (char32_t c)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends a UTF-32 character, as a quoted <span class="doxyComputerOutput">U</span> literal, to the buffer. <a href="#aa273723118d3fc995eb3e2929d78f280">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a984d2b715e58437c9e2bd3455174ae60">operator&lt;&lt;</a> (const c_string &amp;s)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends a C string operand of a comparator. <a href="#a984d2b715e58437c9e2bd3455174ae60">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
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
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ac7bb8541495fe98975132f546f5529bc">operator&lt;&lt;</a> (const detail::and_op&lt; Lhs_T, Rhs_T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats a logical AND as <span class="doxyComputerOutput">(lhs and rhs)</span>. <a href="#ac7bb8541495fe98975132f546f5529bc">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T, class Epsilon_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a7dbef1dcdbb8e4187ec4f28b41ed32fc">operator&lt;&lt;</a> (const detail::approx_op&lt; Lhs_T, Rhs_T, Epsilon_T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats an approximate comparison as <span class="doxyComputerOutput">lhs ~ (rhs +/- epsilon)</span>. <a href="#a7dbef1dcdbb8e4187ec4f28b41ed32fc">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T, class Compare_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a91cd5a527853b70e7523e3180cb883f0">operator&lt;&lt;</a> (const detail::compare_op&lt; Lhs_T, Rhs_T, Compare_T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats a relational comparison as <span class="doxyComputerOutput">lhs <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a> rhs</span>. <a href="#a91cd5a527853b70e7523e3180cb883f0">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a69d49647528979d6927386cfb4ba29ec">operator&lt;&lt;</a> (const detail::not_op&lt; T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats a logical NOT as <span class="doxyComputerOutput">not operand</span>. <a href="#a69d49647528979d6927386cfb4ba29ec">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a0ffe9183360b8f7e674f8546888ec5cc">operator&lt;&lt;</a> (const detail::nothrow_op &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats a nothrow expression as <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-exceptions/#ga798bd28001c3938784073e60dd904148">nothrow</a></span>. <a href="#a0ffe9183360b8f7e674f8546888ec5cc">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a5a5535dbaa45481b3b6f74186d43152e">operator&lt;&lt;</a> (const detail::or_op&lt; Lhs_T, Rhs_T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats a logical OR as <span class="doxyComputerOutput">(lhs or rhs)</span>. <a href="#a5a5535dbaa45481b3b6f74186d43152e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T, class Predicate_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#af68e85825621bce88f656ced9be5396e">operator&lt;&lt;</a> (const detail::predicate_op&lt; T, Predicate_T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats a unary predicate as <span class="doxyComputerOutput">symbol operand</span>. <a href="#af68e85825621bce88f656ced9be5396e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Exception_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a6734ab254c188ce23514b5e84dd1232f">operator&lt;&lt;</a> (const detail::throws_op&lt; Exception_T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats a throws expression as <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-exceptions/#gaf8f7602f40119da514be2a0bfc4b70f5">throws</a>&lt;TypeName&gt;</span>, or as <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-exceptions/#gaf8f7602f40119da514be2a0bfc4b70f5">throws</a></span> when any exception is expected. <a href="#a6734ab254c188ce23514b5e84dd1232f">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a46392700e7eabfa2e18655ac6b04c670">operator&lt;&lt;</a> (const named_bool &amp;b)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends the name of a named boolean constant. <a href="#a46392700e7eabfa2e18655ac6b04c670">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Rep, class Period&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a533424913419f7a9a763cd4db9d1f87e">operator&lt;&lt;</a> (const std::chrono::duration&lt; Rep, Period &gt; &amp;d)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends a duration, as the count followed by the unit. <a href="#a533424913419f7a9a763cd4db9d1f87e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a0f70445853f493e198a1fcf11177823d">operator&lt;&lt;</a> (const std::optional&lt; T &gt; &amp;o)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends the value of an optional, or <span class="doxyComputerOutput">nullopt</span>. <a href="#a0f70445853f493e198a1fcf11177823d">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T1, class T2&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a2ca994c99c86ce1d5fdef788f9ece933">operator&lt;&lt;</a> (const std::pair&lt; T1, T2 &gt; &amp;p)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends the members of a pair, as <span class="doxyComputerOutput">(first, second)</span>. <a href="#a2ca994c99c86ce1d5fdef788f9ece933">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class... Ts&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a277c1153e2afdb1a09df62f9858e4976">operator&lt;&lt;</a> (const std::tuple&lt; Ts... &gt; &amp;t)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends the elements of a tuple, as <span class="doxyComputerOutput">(e1, e2, …)</span>. <a href="#a277c1153e2afdb1a09df62f9858e4976">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a0f53d49c9cf2bcbf4b5b35f136f769ce">operator&lt;&lt;</a> (const T &amp;t)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends a container's elements enclosed in braces. <a href="#a0f53d49c9cf2bcbf4b5b35f136f769ce">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a667715506ffe8f42c3243b7e290a9768">operator&lt;&lt;</a> (const T &amp;t)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends the value of a framework value wrapper via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a59eb53c96f68d26635c13df53b358ac8">detail::unwrap()</a></span>. <a href="#a667715506ffe8f42c3243b7e290a9768">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
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
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
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
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#addfdc62bee977a9bec102e7babec03e1">operator&lt;&lt;</a> (long double v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends a long double value with type suffix <span class="doxyComputerOutput">"ld"</span>. <a href="#addfdc62bee977a9bec102e7babec03e1">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a50d03426268411a1481d778952bdb8f4">operator&lt;&lt;</a> (signed char c)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends a signed char value with type suffix <span class="doxyComputerOutput">"sc"</span>. <a href="#a50d03426268411a1481d778952bdb8f4">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
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
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
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
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
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
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
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
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#afedb833a4ea9bd720a9c9f471ea8ab34">operator&lt;&lt;</a> (std::nullopt_t)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends the string <span class="doxyComputerOutput">"nullopt"</span>. <a href="#afedb833a4ea9bd720a9c9f471ea8ab34">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
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
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
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
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a965d6164f8c6d50cfb29545e794e9615">operator&lt;&lt;</a> (T *v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends the hexadecimal address of a pointer. <a href="#a965d6164f8c6d50cfb29545e794e9615">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a8499cebf8c9b3815b189c0e6e8ca2920">operator&lt;&lt;</a> (T v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends the underlying value of a scoped enumeration. <a href="#a8499cebf8c9b3815b189c0e6e8ca2920">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
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
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
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
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
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
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
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
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
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
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ad90b0391a9b4fb44cc89208745bdfe70">operator&lt;&lt;</a> (wchar_t c)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends a wide character, as a quoted <span class="doxyComputerOutput">L</span> literal, to the buffer. <a href="#ad90b0391a9b4fb44cc89208745bdfe70">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
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
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;</td>
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
<td class="doxyMemberIndexItemType" align="left" valign="top">const std::string &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a57a2737ff5f067461e4f220acd9fcd4b">str</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns the text written to the formatter. <a href="#a57a2737ff5f067461e4f220acd9fcd4b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Private Member Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a29db61e42922091f047726fcdb4ba5b7">append_and_operand</a> (const detail::and_op&lt; Lhs_T, Rhs_T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends the operands of a logical AND, separated by <span class="doxyComputerOutput">and</span>. <a href="#a29db61e42922091f047726fcdb4ba5b7">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a74bb5c3c4b3feacc77d1afe464a7c988">append_and_operand</a> (const T &amp;t)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends an operand of a chain of logical ANDs. <a href="#a74bb5c3c4b3feacc77d1afe464a7c988">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a1af5c2ffe3cd4eacad21667c2d4e3914">append_character</a> (std::string_view prefix, char32_t code, std::size_t size)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends a character, or a code unit, as a quoted literal. <a href="#a1af5c2ffe3cd4eacad21667c2d4e3914">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a7b397504fbb760801d70b1a06186a599">append_decimal_point</a> (std::size_t start)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Adds a decimal point to a floating-point value formatted as an integer. <a href="#a7b397504fbb760801d70b1a06186a599">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Tuple_T, std::size_t... Is&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a2966189c9d09d874a21e069c10a23b44">append_elements</a> (const Tuple_T &amp;t, std::index_sequence&lt; Is... &gt;)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends the elements of a tuple-like object, separated by commas. <a href="#a2966189c9d09d874a21e069c10a23b44">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a0f5470c06633dea5bd77ad15a578a380">append_or_operand</a> (const detail::or_op&lt; Lhs_T, Rhs_T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends the operands of a logical OR, separated by <span class="doxyComputerOutput">or</span>. <a href="#a0f5470c06633dea5bd77ad15a578a380">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#abca8031b08daa1101165c0ba47709d8b">append_or_operand</a> (const T &amp;t)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends an operand of a chain of logical ORs. <a href="#abca8031b08daa1101165c0ba47709d8b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a07bd2bc6c72722228701c2e5f3bfeed8">append_suffix</a> (const char *suffix)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends the type suffix of a number. <a href="#a07bd2bc6c72722228701c2e5f3bfeed8">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a433e0e309292ccc3e42a35076e32d6c3">begin_check</a> (const void *owner)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Prepares the buffer for the expression of a new check. <a href="#a433e0e309292ccc3e42a35076e32d6c3">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const std::string &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ae0068f2e9d46a29c71fcc812f505fbce">check_text</a> (const void *owner) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns the expression text of a check. <a href="#ae0068f2e9d46a29c71fcc812f505fbce">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">auto</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a2440544fb5674da8853708f9af9ccc14">colour</a> (const bool cond) const</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Selects the appropriate colour code based on a condition. <a href="#a2440544fb5674da8853708f9af9ccc14">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aa568154ec1095196010a66fec43a393f">end_check</a> (const void *owner) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Releases the expression text of a check, after it was reported. <a href="#aa568154ec1095196010a66fec43a393f">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Private Member Attributes Index

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
<td class="doxyMemberIndexItemType" align="left" valign="top">const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a566350d8ec85e4c0b5d8a27ef61f819f">colours_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>ANSI colour codes for output formatting. <a href="#a566350d8ec85e4c0b5d8a27ef61f819f">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const void *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aaa185fbbc82e45621ca924efea6c8a3c">owner_</a> { nullptr }</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The check whose expression is in the buffer. <a href="#aaa185fbbc82e45621ca924efea6c8a3c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">std::vector&lt; std::pair&lt; const void *, std::string &gt; &gt;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a5efacef89d1d5150982bbce240ac625e">pending_</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The expression texts of the pending checks whose buffer was reused. <a href="#a5efacef89d1d5150982bbce240ac625e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a4a956e5994817535692a7684eb26e149">plain_</a> { false }</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Whether the formatter writes a message. <a href="#a4a956e5994817535692a7684eb26e149">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Formats values and expressions into an owned string buffer.</p>


<p><span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter">expression_formatter</a></span> owns a <span class="doxyComputerOutput">std::string</span> buffer and provides <span class="doxyComputerOutput">operator&lt;&lt;</span> overloads for all standard arithmetic types, character types, strings, pointers, containers, scoped enumerations (including <span class="doxyComputerOutput">std::byte</span>), pairs, tuples, optionals, and framework expression types (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a></span>).</p>


<p>The numeric overloads append a type suffix named after the µTest++ literals (e.g., <span class="doxyComputerOutput">42u</span>, <span class="doxyComputerOutput">3l</span>, <span class="doxyComputerOutput">5sc</span>, <span class="doxyComputerOutput">1.5f</span>, <span class="doxyComputerOutput">1.5ld</span>); <span class="doxyComputerOutput">int</span> and <span class="doxyComputerOutput">double</span> have no suffix, and the floating-point values always have a decimal point or an exponent (<span class="doxyComputerOutput">42</span>), so that they can be distinguished from the integers.</p>


<p>The same overloads also write the messages appended to the checks (<span class="doxyComputerOutput">expect (...) &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">value</a></span>), so that a message accepts the same values as an expression, including the application types with an <span class="doxyComputerOutput">operator&lt;&lt;</span> for this formatter. For the messages, <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">check_result</a></span> uses a formatter in the plain mode, which writes the numbers without the type suffixes and without the added decimal point (<span class="doxyComputerOutput">42</span>, <span class="doxyComputerOutput">1.5</span>), and the <span class="doxyComputerOutput">char</span> values unchanged, without quotes, as text; the other values are written as in the expressions.</p>


<p>The class is non-copyable and non-movable to avoid accidental copying of the internal buffer.</p>


<p>Apart from the constructor, the public members are the <span class="doxyComputerOutput">operator&lt;&lt;</span> overloads and the read-only <span class="doxyComputerOutput"><a href="#a57a2737ff5f067461e4f220acd9fcd4b">str()</a></span>, so that the application <span class="doxyComputerOutput">operator&lt;&lt;</span> functions for user-defined types can only append text. The functions that assign the buffer to a check, and return and release its text, are private, and called only by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">check_result</a></span>, a friend; an application function calling them would corrupt the texts of the pending checks.</p>


<p>Definition at line 205 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>.</p>


<div class="doxySectionDef">

## Friends

### check\_result {#aec75a9652b7e98188d506c462aa73e19}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">friend class check_result</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The check result, which formats its expression and its message.</p>


<p>It assigns the buffer to the checks, retrieves and releases their texts, and uses the plain mode for the messages.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00215">215</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aec75a9652b7e98188d506c462aa73e19">215</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="#aec75a9652b7e98188d506c462aa73e19">check_result</a>;</span></span></div>

</div>


<p>Reference <a href="#aec75a9652b7e98188d506c462aa73e19">check_result</a>.</p>


<p>Referenced by <a href="#aec75a9652b7e98188d506c462aa73e19">check_result</a>.</p>

</div>
</div>

### plain\_text {#a97203c5c0e22fec0ca6a7cff1f911862}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">friend struct plain_text</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The plain text writer, for the names of the test cases.</p>


<p>It uses the plain mode, which is private, to write the values in the names generated by <span class="doxyComputerOutput">test_each()</span>.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00224">224</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a97203c5c0e22fec0ca6a7cff1f911862">224</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">struct </span><span class="doxyHighlight"><a href="#a97203c5c0e22fec0ca6a7cff1f911862">plain_text</a>;</span></span></div>

</div>


<p>Reference <a href="#a97203c5c0e22fec0ca6a7cff1f911862">plain_text</a>.</p>


<p>Referenced by <a href="#a97203c5c0e22fec0ca6a7cff1f911862">plain_text</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Constructors

### expression\_formatter() {#a4c72fc8eae7aab4545122235816eb03e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::expression_formatter::expression_formatter (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a> &amp; colours)</td>
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
<td class="doxyParamItemDescription"><p>Reference to a <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a></span> instance for output formatting; it must outlive the formatter.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Initialises the <span class="doxyComputerOutput"><a href="#a566350d8ec85e4c0b5d8a27ef61f819f">colours_</a></span> reference with the provided <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a></span> instance. The internal buffer is default-initialised to an empty string.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00233">233</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00080">80</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a4c72fc8eae7aab4545122235816eb03e">80</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">inline</span><span class="doxyHighlight"> <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter::expression_formatter</a> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">81</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a>&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a>) noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">82</span><span class="doxyLineContent"><span class="doxyHighlight">      : <a href="#a566350d8ec85e4c0b5d8a27ef61f819f">colours_</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">83</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">84</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a566350d8ec85e4c0b5d8a27ef61f819f">colours_</a>.</p>


<p>Referenced by <a href="#aed6149e163549956985e23a3ee9e6282">expression_formatter</a>, <a href="#a7de3044d562926e79a6039bed6230794">expression_formatter</a>, <a href="#a421fc77a0d2c9939ca7d2fdc1ba13358">~expression_formatter</a>, <a href="#a4b24176d3597d73506e5bf0b71bdab2a">operator&lt;&lt;</a>, <a href="#a6df410b7ec951a5563b1fae75ed31350">operator&lt;&lt;</a>, <a href="#a66178d7bc2ba82aa370731f91381e2e2">operator&lt;&lt;</a>, <a href="#aa273723118d3fc995eb3e2929d78f280">operator&lt;&lt;</a>, <a href="#a984d2b715e58437c9e2bd3455174ae60">operator&lt;&lt;</a>, <a href="#afd1a0e24d72c0525f04e102fc2e6fb78">operator&lt;&lt;</a>, <a href="#ac7bb8541495fe98975132f546f5529bc">operator&lt;&lt;</a>, <a href="#a7dbef1dcdbb8e4187ec4f28b41ed32fc">operator&lt;&lt;</a>, <a href="#a91cd5a527853b70e7523e3180cb883f0">operator&lt;&lt;</a>, <a href="#a69d49647528979d6927386cfb4ba29ec">operator&lt;&lt;</a>, <a href="#a0ffe9183360b8f7e674f8546888ec5cc">operator&lt;&lt;</a>, <a href="#a5a5535dbaa45481b3b6f74186d43152e">operator&lt;&lt;</a>, <a href="#af68e85825621bce88f656ced9be5396e">operator&lt;&lt;</a>, <a href="#a6734ab254c188ce23514b5e84dd1232f">operator&lt;&lt;</a>, <a href="#a46392700e7eabfa2e18655ac6b04c670">operator&lt;&lt;</a>, <a href="#a533424913419f7a9a763cd4db9d1f87e">operator&lt;&lt;</a>, <a href="#a0f70445853f493e198a1fcf11177823d">operator&lt;&lt;</a>, <a href="#a2ca994c99c86ce1d5fdef788f9ece933">operator&lt;&lt;</a>, <a href="#a277c1153e2afdb1a09df62f9858e4976">operator&lt;&lt;</a>, <a href="#a0f53d49c9cf2bcbf4b5b35f136f769ce">operator&lt;&lt;</a>, <a href="#ae35ae1fef3c1b19f78d9d01c46e389e5">operator&lt;&lt;</a>, <a href="#a28f6feb880950d846e9d527254e019cd">operator&lt;&lt;</a>, <a href="#addfdc62bee977a9bec102e7babec03e1">operator&lt;&lt;</a>, <a href="#a50d03426268411a1481d778952bdb8f4">operator&lt;&lt;</a>, <a href="#a2852a7fdaabf1036ddbeb50b2e0a23bd">operator&lt;&lt;</a>, <a href="#a93e6a5524f5cd912acd200cf7842ddf4">operator&lt;&lt;</a>, <a href="#adec3880ea2146b10b4b6ff188ad0a57c">operator&lt;&lt;</a>, <a href="#a51879a69ec3bbd2d36614f05b7991748">operator&lt;&lt;</a>, <a href="#afedb833a4ea9bd720a9c9f471ea8ab34">operator&lt;&lt;</a>, <a href="#a9f9170708f0763a39314e19902843b4b">operator&lt;&lt;</a>, <a href="#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>, <a href="#a965d6164f8c6d50cfb29545e794e9615">operator&lt;&lt;</a>, <a href="#a8499cebf8c9b3815b189c0e6e8ca2920">operator&lt;&lt;</a>, <a href="#a41d15d145121a646d3ec8e2a53626658">operator&lt;&lt;</a>, <a href="#a9943e733445290a4296bd236ba5b1294">operator&lt;&lt;</a>, <a href="#a2f40f5b293810e4c9c55340dd7074936">operator&lt;&lt;</a>, <a href="#ac2b6dfdd70318f5005035667d19814b2">operator&lt;&lt;</a>, <a href="#a60165c67928c5bab83c4dac211b50ec4">operator&lt;&lt;</a>, <a href="#ad90b0391a9b4fb44cc89208745bdfe70">operator&lt;&lt;</a>, <a href="#a1a4f5fbbf1f7194b61b6d1cedf2b8a62">operator=</a> and <a href="#acf0a0ce3f89ee68096e5b104dfbd8481">operator=</a>.</p>

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


<p>The formatter is owned by a reporter and refers to its colours.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00241">241</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>.</p>


<p>Reference <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>.</p>

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


<p>The formatter is owned by a reporter and refers to its colours.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00249">249</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>.</p>


<p>Reference <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Private Constructors

### expression\_formatter() {#a5c2acf2640374b8d971193eae264c26c}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::expression_formatter::expression_formatter (std::string &amp;&amp; buffer)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
<span class="doxyMemberLabel explicit">explicit</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Constructs a formatter in the plain mode, for a message.</p>


<p>Used only by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">check_result</a></span>, which moves its message into the buffer, appends a value, and moves the message back, so that no other buffer is allocated. The plain mode writes the numbers without the type suffixes and without the added decimal point, and the <span class="doxyComputerOutput">char</span> values unchanged; the messages are never coloured.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">buffer</td>
<td class="doxyParamItemDescription"><p>The text to which the values are appended.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Takes over the text of <span class="doxyComputerOutput">buffer</span>, without copying it, refers to the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a48c790000ed3d766b705c6c5223d8767">colours_none</a></span> set, and sets the plain mode.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00897">897</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00091">91</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a5c2acf2640374b8d971193eae264c26c">91</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">inline</span><span class="doxyHighlight"> <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter::expression_formatter</a> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">92</span><span class="doxyLineContent"><span class="doxyHighlight">      std::string&amp;&amp; buffer) noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">93</span><span class="doxyLineContent"><span class="doxyHighlight">      : <a href="#a566350d8ec85e4c0b5d8a27ef61f819f">colours_</a> (<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a48c790000ed3d766b705c6c5223d8767">colours_none</a>), <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a> (std::move (buffer)), <a href="#a4a956e5994817535692a7684eb26e149">plain_</a> (</span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">94</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">95</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, <a href="#a566350d8ec85e4c0b5d8a27ef61f819f">colours_</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a48c790000ed3d766b705c6c5223d8767">micro_os_plus::micro_test_plus::detail::colours_none</a> and <a href="#a4a956e5994817535692a7684eb26e149">plain_</a>.</p>

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


<p>Releases the internal buffer; the referenced colours are not owned.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00277">277</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>.</p>


<p>Reference <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>.</p>

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


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00440">440</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00346">346</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">346</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">347</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">348</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (v ? </span><span class="doxyHighlightStringLiteral">"true"</span><span class="doxyHighlight"> : </span><span class="doxyHighlightStringLiteral">"false"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">349</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">350</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

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

<p>Appends a character, as a quoted literal, to the buffer.</p>


<p>The character is written between single quotes, with the non-printable characters escaped (<span class="doxyComputerOutput">'a'</span>, <span class="doxyComputerOutput">' '</span>, <span class="doxyComputerOutput">'\\0'</span>, <span class="doxyComputerOutput">'\\x1b'</span>), so that it can be identified in the reports. To write a separator without quotes, use a string (<span class="doxyComputerOutput">" "</span>). In the plain mode, used for the messages, the character is appended unchanged.</p>


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


<p>The character is written as a C++ character literal, between single quotes, by <span class="doxyComputerOutput"><a href="#a1af5c2ffe3cd4eacad21667c2d4e3914">append_character()</a></span>, so that the spaces and the control characters are visible, and a zero does not end the text when it is printed as a C string. The values above <span class="doxyComputerOutput">127</span> (for example the bytes of the UTF-8 sequences) are written as two hexadecimal digits (<span class="doxyComputerOutput">'\\xc3'</span>).</p>


<p>In the plain mode, used for the messages, the character is appended unchanged, as text, without quotes and escapes.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00310">310</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00220">220</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">220</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> c)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">221</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">222</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a4a956e5994817535692a7684eb26e149">plain_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">223</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">224</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.push_back (c);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">225</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">226</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">227</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">228</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1af5c2ffe3cd4eacad21667c2d4e3914">append_character</a> (</span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight">, </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (c), </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (c));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">229</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">230</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>, <a href="#a1af5c2ffe3cd4eacad21667c2d4e3914">append_character</a>, <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a> and <a href="#a4a956e5994817535692a7684eb26e149">plain_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a66178d7bc2ba82aa370731f91381e2e2}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (char16_t c)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends a UTF-16 code unit, as a quoted <span class="doxyComputerOutput">u</span> literal, to the buffer.</p>


<p>The value is written with the <span class="doxyComputerOutput">u</span> prefix and the escapes of <span class="doxyComputerOutput">char</span> (<span class="doxyComputerOutput">u'a'</span>, <span class="doxyComputerOutput">u'\\n'</span>); the other values outside ASCII are written as universal character names (<span class="doxyComputerOutput">u'\\u00e9'</span>), and the surrogates, which are halves of the pairs, not characters, as four hexadecimal digits (<span class="doxyComputerOutput">u'\\xd83d'</span>). Without the overload, the value would be promoted to <span class="doxyComputerOutput">int</span> and written as a number. The plain mode, used for the messages, writes it in the same way, since it cannot be appended unchanged.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">c</td>
<td class="doxyParamItemDescription"><p>The code unit to append.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Written by <span class="doxyComputerOutput"><a href="#a1af5c2ffe3cd4eacad21667c2d4e3914">append_character()</a></span> with the <span class="doxyComputerOutput">u</span> prefix, also in the plain mode.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00351">351</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00252">252</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">252</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">char16_t</span><span class="doxyHighlight"> c)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">253</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">254</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1af5c2ffe3cd4eacad21667c2d4e3914">append_character</a> (</span><span class="doxyHighlightStringLiteral">"u"</span><span class="doxyHighlight">, </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">char32_t</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (c), </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (c));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">255</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">256</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> and <a href="#a1af5c2ffe3cd4eacad21667c2d4e3914">append_character</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#aa273723118d3fc995eb3e2929d78f280}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (char32_t c)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends a UTF-32 character, as a quoted <span class="doxyComputerOutput">U</span> literal, to the buffer.</p>


<p>The value is written with the <span class="doxyComputerOutput">U</span> prefix and the escapes of <span class="doxyComputerOutput">char</span> (<span class="doxyComputerOutput">U'a'</span>, <span class="doxyComputerOutput">U'\\n'</span>); the other values outside ASCII are written as universal character names (<span class="doxyComputerOutput">U'\\u00e9'</span>, <span class="doxyComputerOutput">U'\\U0001f600'</span>), and the values that are not Unicode characters (the surrogates and the values above <span class="doxyComputerOutput">1114111</span>) as eight hexadecimal digits (<span class="doxyComputerOutput">U'\\x0000d83d'</span>). Without the overload, the value would be promoted to <span class="doxyComputerOutput">unsigned int</span> and written as a number. The plain mode, used for the messages, writes it in the same way, since it cannot be appended unchanged.</p>


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


<p>Written by <span class="doxyComputerOutput"><a href="#a1af5c2ffe3cd4eacad21667c2d4e3914">append_character()</a></span> with the <span class="doxyComputerOutput">U</span> prefix, also in the plain mode.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00372">372</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00264">264</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">264</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">char32_t</span><span class="doxyHighlight"> c)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">265</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">266</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1af5c2ffe3cd4eacad21667c2d4e3914">append_character</a> (</span><span class="doxyHighlightStringLiteral">"U"</span><span class="doxyHighlight">, c, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (c));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">267</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">268</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> and <a href="#a1af5c2ffe3cd4eacad21667c2d4e3914">append_character</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a984d2b715e58437c9e2bd3455174ae60}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/c-string">c_string</a> &amp; s)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends a C string operand of a comparator.</p>


<p>Quoted and escaped as a string view; a null pointer is written as <span class="doxyComputerOutput">nullptr</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">s</td>
<td class="doxyParamItemDescription"><p>The operand.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Appends the characters of the string, quoted and escaped as the <span class="doxyComputerOutput">std::string_view</span> overload does (unchanged in the plain mode), or <span class="doxyComputerOutput">"nullptr"</span> for a null pointer, as the other operator overloads do for these values.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00418">418</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00315">315</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">315</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/c-string">c_string</a>&amp; s)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">316</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">317</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (s.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/c-string/#ab3ab63f34f2310d31484a226c92e32aa">is_null</a> ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">318</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">319</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"nullptr"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">320</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">321</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">322</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">323</span><span class="doxyLineContent"><span class="doxyHighlight">        *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; s.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/c-string/#ae80c2a30d372f12aac55094520d6f68b">view</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">324</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">325</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">326</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>, <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/c-string/#ab3ab63f34f2310d31484a226c92e32aa">micro_os_plus::micro_test_plus::detail::c_string::is_null</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/c-string/#ae80c2a30d372f12aac55094520d6f68b">micro_os_plus::micro_test_plus::detail::c_string::view</a>.</p>

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


<p>Also selected for the non-const <span class="doxyComputerOutput">char</span> pointers and arrays, which the pointer template does not accept. A null pointer is rendered as <span class="doxyComputerOutput">"nullptr"</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">s</td>
<td class="doxyParamItemDescription"><p>The C string to append, or a null pointer.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Appends the null-terminated C string <span class="doxyComputerOutput">s</span> to the internal buffer using <span class="doxyComputerOutput">buffer_.append(s)</span>, or <span class="doxyComputerOutput">"nullptr"</span> for a null pointer, as the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/c-string">c_string</a></span> overload does; the <span class="doxyComputerOutput">char*</span> values also reach this overload, and <span class="doxyComputerOutput">std::string::append()</span> must not be called with a null pointer.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00405">405</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00294">294</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">294</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* s)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">295</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">296</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (s == </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">297</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">298</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"nullptr"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">299</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">300</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">301</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">302</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (s);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">303</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">304</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">305</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#ac7bb8541495fe98975132f546f5529bc}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/and-op">detail::and_op</a>&lt; Lhs_T, Rhs_T &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Formats a logical AND as <span class="doxyComputerOutput">(lhs and rhs)</span>.</p>


<p>A chain of ANDs, as built by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-logical-functions/#gab9b9c26860ceafc1288ecb415f52aaaf">all_of()</a></span> for more than two operands, is written as a single group, <span class="doxyComputerOutput">(a and b and c)</span>.</p>


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


<p>The left-hand side and right-hand side expressions are formatted as they are, enclosed in parentheses, and separated by the word <span class="doxyComputerOutput">and</span>, written in the colour of the result of the conjunction.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00794">794</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00343">343</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">343</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/and-op">detail::and_op&lt;Lhs_T, Rhs_T&gt;</a>&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">344</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">345</span><span class="doxyLineContent"><span class="doxyHighlight">    *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; </span><span class="doxyHighlightStringLiteral">"("</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">346</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a74bb5c3c4b3feacc77d1afe464a7c988">append_and_operand</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">347</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> (*</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; </span><span class="doxyHighlightStringLiteral">")"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">348</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> and <a href="#a74bb5c3c4b3feacc77d1afe464a7c988">append_and_operand</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a7dbef1dcdbb8e4187ec4f28b41ed32fc}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T, class Epsilon_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/approx-op">detail::approx_op</a>&lt; Lhs_T, Rhs_T, Epsilon_T &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Formats an approximate comparison as <span class="doxyComputerOutput">lhs ~ (rhs +/- epsilon)</span>.</p>


<p>The notation is the one used by Boost UT, in ASCII, so that it is also valid in the TAP output.</p>


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
<tr class="doxyParamItem">
<td class="doxyParamItemName">Epsilon_T</td>
<td class="doxyParamItemDescription"><p>Tolerance type.</p></td>
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
<td class="doxyParamItemDescription"><p>The comparison expression.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Formats the operands of an approximate comparison as <span class="doxyComputerOutput">lhs ~ (rhs +/- epsilon)</span>, in the colour of the result, as the relational comparisons are.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00778">778</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00328">328</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">328</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">329</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/approx-op">detail::approx_op&lt;Lhs_T, Rhs_T, Epsilon_T&gt;</a>&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">330</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">331</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> (*</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="#a2440544fb5674da8853708f9af9ccc14">colour</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>) &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>.lhs () &lt;&lt; </span><span class="doxyHighlightStringLiteral">" ~ ("</span><span class="doxyHighlight"> &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>.rhs () &lt;&lt; </span><span class="doxyHighlightStringLiteral">" +/- "</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">332</span><span class="doxyLineContent"><span class="doxyHighlight">                  &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>.epsilon () &lt;&lt; </span><span class="doxyHighlightStringLiteral">")"</span><span class="doxyHighlight"> &lt;&lt; <a href="#a566350d8ec85e4c0b5d8a27ef61f819f">colours_</a>.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours/#a42937839aa8c23e1c5482582eaf2aeb7">none</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">333</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>, <a href="#a2440544fb5674da8853708f9af9ccc14">colour</a>, <a href="#a566350d8ec85e4c0b5d8a27ef61f819f">colours_</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours/#a42937839aa8c23e1c5482582eaf2aeb7">micro_os_plus::micro_test_plus::detail::colours::none</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a91cd5a527853b70e7523e3180cb883f0}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T, class Compare_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/compare-op">detail::compare_op</a>&lt; Lhs_T, Rhs_T, Compare_T &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Formats a relational comparison as <span class="doxyComputerOutput">lhs <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a> rhs</span>.</p>


<p>The operator symbol is taken from the tag (for example <span class="doxyComputerOutput">==</span> for <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/equal-to">detail::equal_to</a></span>).</p>


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
<tr class="doxyParamItem">
<td class="doxyParamItemName">Compare_T</td>
<td class="doxyParamItemDescription"><p>The tag that defines the comparison.</p></td>
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
<td class="doxyParamItemDescription"><p>The comparison expression.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>The left-hand side and right-hand side values are formatted and separated by the operator symbol of the tag (<span class="doxyComputerOutput">==</span>, <span class="doxyComputerOutput">!=</span>, <span class="doxyComputerOutput">&gt;</span>, <span class="doxyComputerOutput">&gt;=</span>, <span class="doxyComputerOutput">&lt;</span>, or <span class="doxyComputerOutput">&lt;=</span> for the built-in tags, or the symbol of an application tag), in the colour of the result (green for passed, red for failed, when colours are enabled).</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00760">760</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00313">313</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">313</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">314</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/compare-op">detail::compare_op&lt;Lhs_T, Rhs_T, Compare_T&gt;</a>&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">315</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">316</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> (*</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="#a2440544fb5674da8853708f9af9ccc14">colour</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>) &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>.lhs () &lt;&lt; Compare_T::symbol &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>.rhs ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">317</span><span class="doxyLineContent"><span class="doxyHighlight">                  &lt;&lt; <a href="#a566350d8ec85e4c0b5d8a27ef61f819f">colours_</a>.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours/#a42937839aa8c23e1c5482582eaf2aeb7">none</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">318</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>, <a href="#a2440544fb5674da8853708f9af9ccc14">colour</a>, <a href="#a566350d8ec85e4c0b5d8a27ef61f819f">colours_</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours/#a42937839aa8c23e1c5482582eaf2aeb7">micro_os_plus::micro_test_plus::detail::colours::none</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a69d49647528979d6927386cfb4ba29ec}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/not-op">detail::not_op</a>&lt; T &gt; &amp; op)</td>
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


<p>Writes the word <span class="doxyComputerOutput">not</span>, followed by the operand, in the colour of the result of the negation.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00821">821</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00424">424</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">424</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/not-op">detail::not_op&lt;T&gt;</a>&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">425</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">426</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> (*</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="#a2440544fb5674da8853708f9af9ccc14">colour</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"not "</span><span class="doxyHighlight"> &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>.operand () &lt;&lt; <a href="#a566350d8ec85e4c0b5d8a27ef61f819f">colours_</a>.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours/#a42937839aa8c23e1c5482582eaf2aeb7">none</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">427</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>, <a href="#a2440544fb5674da8853708f9af9ccc14">colour</a>, <a href="#a566350d8ec85e4c0b5d8a27ef61f819f">colours_</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours/#a42937839aa8c23e1c5482582eaf2aeb7">micro_os_plus::micro_test_plus::detail::colours::none</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a0ffe9183360b8f7e674f8546888ec5cc}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/nothrow-op">detail::nothrow_op</a> &amp; op)</td>
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

<p>Formats a nothrow expression as <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-exceptions/#ga798bd28001c3938784073e60dd904148">nothrow</a></span>.</p>


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


<p>Writes <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-exceptions/#ga798bd28001c3938784073e60dd904148">nothrow</a></span>, in the colour of the result.</p>


<p>It is defined inline, not in the library sources, so that it is available to the applications built with exceptions even when the library is built without them.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00861">861</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00477">477</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">477</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/nothrow-op">detail::nothrow_op</a>&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">478</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">479</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> (*</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="#a2440544fb5674da8853708f9af9ccc14">colour</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"nothrow"</span><span class="doxyHighlight"> &lt;&lt; <a href="#a566350d8ec85e4c0b5d8a27ef61f819f">colours_</a>.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours/#a42937839aa8c23e1c5482582eaf2aeb7">none</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">480</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>, <a href="#a2440544fb5674da8853708f9af9ccc14">colour</a>, <a href="#a566350d8ec85e4c0b5d8a27ef61f819f">colours_</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours/#a42937839aa8c23e1c5482582eaf2aeb7">micro_os_plus::micro_test_plus::detail::colours::none</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a5a5535dbaa45481b3b6f74186d43152e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/or-op">detail::or_op</a>&lt; Lhs_T, Rhs_T &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Formats a logical OR as <span class="doxyComputerOutput">(lhs or rhs)</span>.</p>


<p>A chain of ORs, as built by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-logical-functions/#gae6395736f05626ba6dcf79ecc523486c">any_of()</a></span> for more than two operands, is written as a single group, <span class="doxyComputerOutput">(a or b or c)</span>.</p>


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


<p>The left-hand side and right-hand side expressions are formatted as they are, enclosed in parentheses, and separated by the word <span class="doxyComputerOutput">or</span>, written in the colour of the result of the disjunction.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00810">810</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00384">384</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">384</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/or-op">detail::or_op&lt;Lhs_T, Rhs_T&gt;</a>&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">385</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">386</span><span class="doxyLineContent"><span class="doxyHighlight">    *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; </span><span class="doxyHighlightStringLiteral">"("</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">387</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#abca8031b08daa1101165c0ba47709d8b">append_or_operand</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">388</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> (*</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; </span><span class="doxyHighlightStringLiteral">")"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">389</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> and <a href="#abca8031b08daa1101165c0ba47709d8b">append_or_operand</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#af68e85825621bce88f656ced9be5396e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T, class Predicate_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/predicate-op">detail::predicate_op</a>&lt; T, Predicate_T &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Formats a unary predicate as <span class="doxyComputerOutput">symbol operand</span>.</p>


<p>The symbol is the one of the tag, written as defined by the application, so it includes the separating space.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The operand type.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Predicate_T</td>
<td class="doxyParamItemDescription"><p>The tag that defines the predicate.</p></td>
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
<td class="doxyParamItemDescription"><p>The predicate expression.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Writes the symbol of the tag, followed by the operand, with the same colour highlighting as the logical negation, so that the predicates of the application are reported as the built-in expressions are.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00837">837</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00437">437</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">437</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">438</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/predicate-op">detail::predicate_op&lt;T, Predicate_T&gt;</a>&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">439</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">440</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> (*</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="#a2440544fb5674da8853708f9af9ccc14">colour</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>) &lt;&lt; Predicate_T::symbol &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>.operand ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">441</span><span class="doxyLineContent"><span class="doxyHighlight">                  &lt;&lt; <a href="#a566350d8ec85e4c0b5d8a27ef61f819f">colours_</a>.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours/#a42937839aa8c23e1c5482582eaf2aeb7">none</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">442</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>, <a href="#a2440544fb5674da8853708f9af9ccc14">colour</a>, <a href="#a566350d8ec85e4c0b5d8a27ef61f819f">colours_</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours/#a42937839aa8c23e1c5482582eaf2aeb7">micro_os_plus::micro_test_plus::detail::colours::none</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a6734ab254c188ce23514b5e84dd1232f}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Exception_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/throws-op">detail::throws_op</a>&lt; Exception_T &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Formats a throws expression as <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-exceptions/#gaf8f7602f40119da514be2a0bfc4b70f5">throws</a>&lt;TypeName&gt;</span>, or as <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-exceptions/#gaf8f7602f40119da514be2a0bfc4b70f5">throws</a></span> when any exception is expected.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Exception_T</td>
<td class="doxyParamItemDescription"><p>The expected exception type, or <span class="doxyComputerOutput">void</span> for any exception.</p></td>
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


<p>Writes <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-exceptions/#gaf8f7602f40119da514be2a0bfc4b70f5">throws</a></span>, followed, when a specific exception type is expected, by its name between angle brackets, as returned by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/reflection/#a6580ad54ad22a1d3ab43a1d9d49d1f26">reflection::type_name()</a></span>, in the colour of the result.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00852">852</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00453">453</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">453</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/throws-op">detail::throws_op&lt;Exception_T&gt;</a>&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">454</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">455</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> (std::is_void_v&lt;Exception_T&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">456</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">457</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> (*</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="#a2440544fb5674da8853708f9af9ccc14">colour</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"throws"</span><span class="doxyHighlight"> &lt;&lt; <a href="#a566350d8ec85e4c0b5d8a27ef61f819f">colours_</a>.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours/#a42937839aa8c23e1c5482582eaf2aeb7">none</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">458</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">459</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">460</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">461</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// The type name is not a string operand, so it is not quoted.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">462</span><span class="doxyLineContent"><span class="doxyHighlight">        *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="#a2440544fb5674da8853708f9af9ccc14">colour</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"throws&lt;"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">463</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/reflection/#a6580ad54ad22a1d3ab43a1d9d49d1f26">reflection::type_name&lt;Exception_T&gt;</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">464</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> (*</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; </span><span class="doxyHighlightStringLiteral">"&gt;"</span><span class="doxyHighlight"> &lt;&lt; <a href="#a566350d8ec85e4c0b5d8a27ef61f819f">colours_</a>.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours/#a42937839aa8c23e1c5482582eaf2aeb7">none</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">465</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">466</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>, <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, <a href="#a2440544fb5674da8853708f9af9ccc14">colour</a>, <a href="#a566350d8ec85e4c0b5d8a27ef61f819f">colours_</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours/#a42937839aa8c23e1c5482582eaf2aeb7">micro_os_plus::micro_test_plus::detail::colours::none</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/reflection/#a6580ad54ad22a1d3ab43a1d9d49d1f26">micro_os_plus::micro_test_plus::reflection::type_name</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a46392700e7eabfa2e18655ac6b04c670}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/named-bool">named_bool</a> &amp; b)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends the name of a named boolean constant.</p>


<p>The constant, created by the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gad4203783cfbe141f41ee8515f7b2ea94">_b</a></span> literal, is reported by its name, not by its value, which is always <span class="doxyComputerOutput">true</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">b</td>
<td class="doxyParamItemDescription"><p>The named boolean constant.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Appends the name, as the <span class="doxyComputerOutput">std::string_view</span> overload does, so that the comparison is reported with the name instead of <span class="doxyComputerOutput">true</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00431">431</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00334">334</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">334</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/named-bool">named_bool</a>&amp; b)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">335</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">336</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (b.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/named-bool/#a00b50cd87531243cd42964982fc11bdd">name</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">337</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">338</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>, <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/named-bool/#a00b50cd87531243cd42964982fc11bdd">micro_os_plus::micro_test_plus::detail::named_bool::name</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a533424913419f7a9a763cd4db9d1f87e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Rep, class Period&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (const std::chrono::duration&lt; Rep, Period &gt; &amp; d)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends a duration, as the count followed by the unit.</p>


<p>The count is written without a type suffix, followed by the unit: <span class="doxyComputerOutput">ns</span>, <span class="doxyComputerOutput">us</span>, <span class="doxyComputerOutput">ms</span>, <span class="doxyComputerOutput">s</span>, <span class="doxyComputerOutput">min</span>, or <span class="doxyComputerOutput">h</span> for the standard periods, or the ratio, as <span class="doxyComputerOutput">[N/D]s</span>, for the other ones.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rep</td>
<td class="doxyParamItemDescription"><p>The type of the count.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Period</td>
<td class="doxyParamItemDescription"><p>The period of the duration.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">d</td>
<td class="doxyParamItemDescription"><p>The duration.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Writes the count with <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">append_number()</a></span>, without a type suffix, then the unit selected from the period; the periods without a standard unit are written as the ratio, <span class="doxyComputerOutput">[N/D]s</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00740">740</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00250">250</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">250</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">251</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::chrono::duration&lt;Rep, Period&gt;&amp; d)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">252</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">253</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">detail::append_number</a> (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, d.count ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">254</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">255</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> (std::is_same_v&lt;Period, std::nano&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">256</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">257</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; </span><span class="doxyHighlightStringLiteral">"ns"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">258</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">259</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> (std::is_same_v&lt;Period, std::micro&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">260</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">261</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; </span><span class="doxyHighlightStringLiteral">"us"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">262</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">263</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> (std::is_same_v&lt;Period, std::milli&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">264</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">265</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; </span><span class="doxyHighlightStringLiteral">"ms"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">266</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">267</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> (std::is_same_v&lt;Period, std::ratio&lt;1&gt;&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">268</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">269</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; </span><span class="doxyHighlightStringLiteral">"s"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">270</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">271</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> (std::is_same_v&lt;Period, std::ratio&lt;60&gt;&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">272</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">273</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; </span><span class="doxyHighlightStringLiteral">"min"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">274</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">275</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> (std::is_same_v&lt;Period, std::ratio&lt;3600&gt;&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">276</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">277</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; </span><span class="doxyHighlightStringLiteral">"h"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">278</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">279</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">280</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">281</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; </span><span class="doxyHighlightStringLiteral">"["</span><span class="doxyHighlight"> &lt;&lt; </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (Period::num) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"/"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">282</span><span class="doxyLineContent"><span class="doxyHighlight">                     &lt;&lt; </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (Period::den) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"]s"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">283</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">284</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">micro_os_plus::micro_test_plus::detail::append_number</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a0f70445853f493e198a1fcf11177823d}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (const std::optional&lt; T &gt; &amp; o)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends the value of an optional, or <span class="doxyComputerOutput">nullopt</span>.</p>


<p>A value is formatted through <span class="doxyComputerOutput">operator&lt;&lt;</span>, as the contained type, so an optional with a value is written as the value alone; an optional without a value is written as <span class="doxyComputerOutput">nullopt</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The type of the contained value.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">o</td>
<td class="doxyParamItemDescription"><p>The optional.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Streams the contained value through <span class="doxyComputerOutput">operator&lt;&lt;</span> if there is one, otherwise streams <span class="doxyComputerOutput">std::nullopt</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00723">723</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00233">233</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">233</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::optional&lt;T&gt;&amp; o)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">234</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">235</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (o.has_value ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">236</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">237</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; *o;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">238</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">239</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; std::nullopt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">240</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a2ca994c99c86ce1d5fdef788f9ece933}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T1, class T2&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (const std::pair&lt; T1, T2 &gt; &amp; p)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends the members of a pair, as <span class="doxyComputerOutput">(first, second)</span>.</p>


<p>Each member is formatted through <span class="doxyComputerOutput">operator&lt;&lt;</span>, so the pairs stored in the maps are also formatted, as <span class="doxyComputerOutput">{(1, 2), (3, 4)}</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T1</td>
<td class="doxyParamItemDescription"><p>The type of the first member.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">T2</td>
<td class="doxyParamItemDescription"><p>The type of the second member.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">p</td>
<td class="doxyParamItemDescription"><p>The pair.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Writes the opening parenthesis, the two members through <span class="doxyComputerOutput"><a href="#a2966189c9d09d874a21e069c10a23b44">append_elements()</a></span>, and the closing parenthesis.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00692">692</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00203">203</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">203</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::pair&lt;T1, T2&gt;&amp; p)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">204</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">205</span><span class="doxyLineContent"><span class="doxyHighlight">    *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; </span><span class="doxyHighlightStringLiteral">"("</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">206</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a2966189c9d09d874a21e069c10a23b44">append_elements</a> (p, std::index_sequence_for&lt;T1, T2&gt;{});</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">207</span><span class="doxyLineContent"><span class="doxyHighlight">    *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; </span><span class="doxyHighlightStringLiteral">")"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">208</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">209</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> and <a href="#a2966189c9d09d874a21e069c10a23b44">append_elements</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a277c1153e2afdb1a09df62f9858e4976}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class... Ts&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (const std::tuple&lt; Ts... &gt; &amp; t)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends the elements of a tuple, as <span class="doxyComputerOutput">(e1, e2, …)</span>.</p>


<p>Each element is formatted through <span class="doxyComputerOutput">operator&lt;&lt;</span>; an empty tuple is written as <span class="doxyComputerOutput">()</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Ts</td>
<td class="doxyParamItemDescription"><p>The types of the elements.</p></td>
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
<td class="doxyParamItemDescription"><p>The tuple.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Writes the opening parenthesis, the elements through <span class="doxyComputerOutput"><a href="#a2966189c9d09d874a21e069c10a23b44">append_elements()</a></span>, and the closing parenthesis.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00707">707</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00218">218</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">218</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::tuple&lt;Ts...&gt;&amp; t)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">219</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">220</span><span class="doxyLineContent"><span class="doxyHighlight">    *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; </span><span class="doxyHighlightStringLiteral">"("</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">221</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a2966189c9d09d874a21e069c10a23b44">append_elements</a> (t, std::index_sequence_for&lt;Ts...&gt;{});</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">222</span><span class="doxyLineContent"><span class="doxyHighlight">    *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; </span><span class="doxyHighlightStringLiteral">")"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">223</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">224</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> and <a href="#a2966189c9d09d874a21e069c10a23b44">append_elements</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a0f53d49c9cf2bcbf4b5b35f136f769ce}

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
<td class="doxyParamItemDescription"><p>A range type satisfying <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/formattable-range">detail::formattable_range</a></span>: with <span class="doxyComputerOutput">begin()</span> and <span class="doxyComputerOutput">end()</span> members or functions, not an array, not a string, without elements of its own type, and with printable elements.</p></td>
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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00651">651</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>.</p>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>, <a href="#a74bb5c3c4b3feacc77d1afe464a7c988">append_and_operand</a>, <a href="#a1af5c2ffe3cd4eacad21667c2d4e3914">append_character</a>, <a href="#a7b397504fbb760801d70b1a06186a599">append_decimal_point</a>, <a href="#a2966189c9d09d874a21e069c10a23b44">append_elements</a>, <a href="#abca8031b08daa1101165c0ba47709d8b">append_or_operand</a>, <a href="#a07bd2bc6c72722228701c2e5f3bfeed8">append_suffix</a>, <a href="#a433e0e309292ccc3e42a35076e32d6c3">begin_check</a>, <a href="#ae0068f2e9d46a29c71fcc812f505fbce">check_text</a>, <a href="#a2440544fb5674da8853708f9af9ccc14">colour</a>, <a href="#aa568154ec1095196010a66fec43a393f">end_check</a> and <a href="#a57a2737ff5f067461e4f220acd9fcd4b">str</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a667715506ffe8f42c3243b7e290a9768}

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

<p>Appends the value of a framework value wrapper via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a59eb53c96f68d26635c13df53b358ac8">detail::unwrap()</a></span>.</p>


<p>Only the wrappers with a <span class="doxyComputerOutput">get()</span> accessor (the <span class="doxyComputerOutput">to_*</span> wrappers and the literals) are accepted. Any other type satisfying <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a></span> must have its own overload, as the built-in expressions and <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/extension/compare-op">extension::compare_op</a></span> and <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/extension/predicate-op">extension::predicate_op</a></span> have; without it, <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a59eb53c96f68d26635c13df53b358ac8">detail::unwrap()</a></span> would return the expression itself, and this overload would call itself without end, so such a type is rejected at compile time.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>A value wrapper type satisfying <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a>&lt;T&gt;</span>, with a <span class="doxyComputerOutput">get()</span> accessor.</p></td>
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
<td class="doxyParamItemDescription"><p>The value wrapper.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Delegates to <span class="doxyComputerOutput">detail::unwrap(t)</span> to obtain the displayable value of a value wrapper, then streams it through <span class="doxyComputerOutput">operator&lt;&lt;</span> to format it into the buffer. The <span class="doxyComputerOutput">get()</span> constraint guarantees that <span class="doxyComputerOutput">detail::unwrap(t)</span> returns the wrapped value, not the wrapper itself, which would select this overload again.</p>


<p>Iterates the container and formats each element separated by <span class="doxyComputerOutput">", "</span>, surrounded by <span class="doxyComputerOutput">{</span> and <span class="doxyComputerOutput">}</span>. Each element is streamed through <span class="doxyComputerOutput">operator&lt;&lt;</span>, which recurses as needed for nested types.</p>


<p>The range-based <span class="doxyComputerOutput">for</span> statement uses the <span class="doxyComputerOutput">begin()</span> and <span class="doxyComputerOutput">end()</span> members, or, if there are none, the functions found by argument-dependent lookup, as <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/formattable-range">detail::formattable_range</a></span> does.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00632">632</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00149">149</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">149</span><span class="doxyLineContent"><span class="doxyHighlight">  expression_formatter::operator&lt;&lt; (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; t)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">150</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">151</span><span class="doxyLineContent"><span class="doxyHighlight">    *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a59eb53c96f68d26635c13df53b358ac8">detail::unwrap</a> (t);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">152</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">153</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a59eb53c96f68d26635c13df53b358ac8">micro_os_plus::micro_test_plus::detail::unwrap</a>.</p>

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


<p>An integral value is written with a decimal point (<span class="doxyComputerOutput">42</span>), to distinguish it from an <span class="doxyComputerOutput">int</span>.</p>


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


<p>Converts <span class="doxyComputerOutput">v</span> to its string representation via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">append_number()</a></span> and adds the decimal point if needed (via <span class="doxyComputerOutput"><a href="#a7b397504fbb760801d70b1a06186a599">append_decimal_point()</a></span>), without a type suffix.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00573">573</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00533">533</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">533</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">double</span><span class="doxyHighlight"> v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">534</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">535</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> start = <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.size ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">536</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">detail::append_number</a> (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">537</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a7b397504fbb760801d70b1a06186a599">append_decimal_point</a> (start);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">538</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">539</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>, <a href="#a7b397504fbb760801d70b1a06186a599">append_decimal_point</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">micro_os_plus::micro_test_plus::detail::append_number</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

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


<p>An integral value is written with a decimal point (<span class="doxyComputerOutput">42.0f</span>).</p>


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


<p>Converts <span class="doxyComputerOutput">v</span> to its string representation via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">append_number()</a></span>, adds the decimal point if needed (via <span class="doxyComputerOutput"><a href="#a7b397504fbb760801d70b1a06186a599">append_decimal_point()</a></span>), and appends the type suffix <span class="doxyComputerOutput">"f"</span>, unless the text is an infinity or a NaN, which would read as a misspelling (<span class="doxyComputerOutput">inff</span>).</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00560">560</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00514">514</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">514</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">float</span><span class="doxyHighlight"> v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">515</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">516</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> start = <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.size ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">517</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">detail::append_number</a> (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">518</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a7b397504fbb760801d70b1a06186a599">append_decimal_point</a> (start);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">519</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (std::isfinite (v))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">520</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">521</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a07bd2bc6c72722228701c2e5f3bfeed8">append_suffix</a> (</span><span class="doxyHighlightStringLiteral">"f"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">522</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">523</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">524</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>, <a href="#a7b397504fbb760801d70b1a06186a599">append_decimal_point</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">micro_os_plus::micro_test_plus::detail::append_number</a>, <a href="#a07bd2bc6c72722228701c2e5f3bfeed8">append_suffix</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

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

<p>Appends a long double value with type suffix <span class="doxyComputerOutput">"ld"</span>.</p>


<p>An integral value is written with a decimal point (<span class="doxyComputerOutput">42.0ld</span>).</p>


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


<p>Converts <span class="doxyComputerOutput">v</span> to its string representation via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">append_number()</a></span>, adds the decimal point if needed (via <span class="doxyComputerOutput"><a href="#a7b397504fbb760801d70b1a06186a599">append_decimal_point()</a></span>), and appends the type suffix <span class="doxyComputerOutput">"ld"</span>, the name of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#gacfe28c6fb7bfb47ca8891cb61e7f58d9">_ld</a></span> literal; the C++ suffix <span class="doxyComputerOutput">"l"</span> would suggest <span class="doxyComputerOutput">long</span>. The suffix is not appended to an infinity or a NaN, which would read as a misspelling (<span class="doxyComputerOutput">infld</span>).</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00585">585</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00551">551</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">551</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">double</span><span class="doxyHighlight"> v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">552</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">553</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> start = <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.size ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">554</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">detail::append_number</a> (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">555</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a7b397504fbb760801d70b1a06186a599">append_decimal_point</a> (start);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">556</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (std::isfinite (v))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">557</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">558</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a07bd2bc6c72722228701c2e5f3bfeed8">append_suffix</a> (</span><span class="doxyHighlightStringLiteral">"ld"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">559</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">560</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">561</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>, <a href="#a7b397504fbb760801d70b1a06186a599">append_decimal_point</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">micro_os_plus::micro_test_plus::detail::append_number</a>, <a href="#a07bd2bc6c72722228701c2e5f3bfeed8">append_suffix</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

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

<p>Appends a signed char value with type suffix <span class="doxyComputerOutput">"sc"</span>.</p>


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


<p>Converts <span class="doxyComputerOutput">c</span> to its decimal string representation via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">append_number()</a></span> and appends the type suffix <span class="doxyComputerOutput">"sc"</span>, the name of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga0cc4baab5f421ac7adee10218d8ee8a2">_sc</a></span> literal; the suffix <span class="doxyComputerOutput">"c"</span> would suggest <span class="doxyComputerOutput">char</span>, which is written as a character.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00467">467</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00383">383</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">383</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">signed</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> c)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">384</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">385</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">detail::append_number</a> (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, c);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">386</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a07bd2bc6c72722228701c2e5f3bfeed8">append_suffix</a> (</span><span class="doxyHighlightStringLiteral">"sc"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">387</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">388</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">micro_os_plus::micro_test_plus::detail::append_number</a>, <a href="#a07bd2bc6c72722228701c2e5f3bfeed8">append_suffix</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

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


<p>Converts <span class="doxyComputerOutput">v</span> to its decimal string representation via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">append_number()</a></span> without a type suffix.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00503">503</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00435">435</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">435</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">signed</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">436</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">437</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">detail::append_number</a> (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">438</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">439</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">micro_os_plus::micro_test_plus::detail::append_number</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

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


<p>Converts <span class="doxyComputerOutput">v</span> to its decimal string representation via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">append_number()</a></span> and appends the type suffix <span class="doxyComputerOutput">"ll"</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00539">539</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00486">486</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">486</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">signed</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">487</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">488</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">detail::append_number</a> (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">489</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a07bd2bc6c72722228701c2e5f3bfeed8">append_suffix</a> (</span><span class="doxyHighlightStringLiteral">"ll"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">490</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">491</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">micro_os_plus::micro_test_plus::detail::append_number</a>, <a href="#a07bd2bc6c72722228701c2e5f3bfeed8">append_suffix</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

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


<p>Converts <span class="doxyComputerOutput">v</span> to its decimal string representation via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">append_number()</a></span> and appends the type suffix <span class="doxyComputerOutput">"l"</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00521">521</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00460">460</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">460</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">signed</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">461</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">462</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">detail::append_number</a> (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">463</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a07bd2bc6c72722228701c2e5f3bfeed8">append_suffix</a> (</span><span class="doxyHighlightStringLiteral">"l"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">464</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">465</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">micro_os_plus::micro_test_plus::detail::append_number</a>, <a href="#a07bd2bc6c72722228701c2e5f3bfeed8">append_suffix</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

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


<p>Converts <span class="doxyComputerOutput">v</span> to its decimal string representation via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">append_number()</a></span> and appends the type suffix <span class="doxyComputerOutput">"s"</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00485">485</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00409">409</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">409</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">signed</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">short</span><span class="doxyHighlight"> v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">410</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">411</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">detail::append_number</a> (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">412</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a07bd2bc6c72722228701c2e5f3bfeed8">append_suffix</a> (</span><span class="doxyHighlightStringLiteral">"s"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">413</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">414</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">micro_os_plus::micro_test_plus::detail::append_number</a>, <a href="#a07bd2bc6c72722228701c2e5f3bfeed8">append_suffix</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#afedb833a4ea9bd720a9c9f471ea8ab34}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (std::nullopt_t)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends the string <span class="doxyComputerOutput">"nullopt"</span>.</p>


<p>Selected for <span class="doxyComputerOutput">std::nullopt</span>, so that an optional value can be compared with it (<span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-function-comparators/#gaa7c7b6a7ad32856edc235a05e77d8c7f">eq</a> (opt, std::nullopt)</span>).</p>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Appends the string <span class="doxyComputerOutput">"nullopt"</span> to the internal buffer; also used by the <span class="doxyComputerOutput">std::optional</span> template for the optionals without a value.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00459">459</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00369">369</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">369</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(std::nullopt_t)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">370</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">371</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"nullopt"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">372</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">373</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

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


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00448">448</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00357">357</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">357</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(std::nullptr_t)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">358</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">359</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"nullptr"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">360</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">361</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

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


<p>The string is written between double quotes, with the control characters, the double quote, and the backslash escaped. In the plain mode, used for the messages, it is appended unchanged.</p>


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


<p>The string is written as a C++ string literal, between double quotes, by <span class="doxyComputerOutput">append_quoted()</span>, so that the empty and blank strings are visible, and the control characters are escaped. In the plain mode, used for the messages, the contents are appended unchanged, using <span class="doxyComputerOutput">buffer_.append(sv)</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00293">293</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00194">194</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">194</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(std::string_view sv)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">195</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">196</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a4a956e5994817535692a7684eb26e149">plain_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">197</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">198</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (sv);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">199</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">200</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">201</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">202</span><span class="doxyLineContent"><span class="doxyHighlight">        append_quoted (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, sv);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">203</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">204</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">205</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>, <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a> and <a href="#a4a956e5994817535692a7684eb26e149">plain_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a965d6164f8c6d50cfb29545e794e9615}

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


<p>The <span class="doxyComputerOutput">char</span> pointers are excluded, so that they are written as strings by the <span class="doxyComputerOutput">const char*</span> overload, as the <span class="doxyComputerOutput">const char</span> pointers are; the <span class="doxyComputerOutput">signed char</span> and <span class="doxyComputerOutput">unsigned char</span> pointers, usually byte buffers, are written as addresses.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The type pointed to, other than <span class="doxyComputerOutput">char</span>.</p></td>
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


<p>The address is formatted by the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a622a2bb23e2c98ecfa3a2ccb53e19910">detail::append_pointer()</a></span> helper, shared with the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">detail::reporter</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00609">609</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00132">132</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">132</span><span class="doxyLineContent"><span class="doxyHighlight">  expression_formatter::operator&lt;&lt; (T* v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">133</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">134</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a622a2bb23e2c98ecfa3a2ccb53e19910">detail::append_pointer</a> (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">135</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">136</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a622a2bb23e2c98ecfa3a2ccb53e19910">micro_os_plus::micro_test_plus::detail::append_pointer</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a8499cebf8c9b3815b189c0e6e8ca2920}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (T v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends the underlying value of a scoped enumeration.</p>


<p>The value is converted to the underlying type and formatted as that type, with its suffix (for example <span class="doxyComputerOutput">1</span> for an <span class="doxyComputerOutput">int</span> and <span class="doxyComputerOutput">1uc</span> for <span class="doxyComputerOutput">std::byte</span>, whose underlying type is <span class="doxyComputerOutput">unsigned char</span>).</p>


<p>The unscoped enumerations are not selected, since they convert implicitly to an integer, and are formatted as one.</p>


<p>An <span class="doxyComputerOutput">operator&lt;&lt;</span> defined by the application for an enumeration, for example to write the names of the enumerators, is preferred to this template.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>A scoped enumeration type.</p></td>
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
<td class="doxyParamItemDescription"><p>The enumeration value.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to this instance.</p></dd>
</dl>


<p>Converts the value with <span class="doxyComputerOutput">static_cast</span> to the underlying type, and streams the result through <span class="doxyComputerOutput">operator&lt;&lt;</span>, which selects the overload of that type.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00676">676</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00191">191</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">191</span><span class="doxyLineContent"><span class="doxyHighlight">  expression_formatter::operator&lt;&lt; (T v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">192</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">193</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *this &lt;&lt; static_cast&lt;std::underlying_type_t&lt;T&gt;&gt; (v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">194</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>.</p>

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


<p>Converts <span class="doxyComputerOutput">c</span> to its decimal string representation via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">append_number()</a></span> and appends the type suffix <span class="doxyComputerOutput">"uc"</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00476">476</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00396">396</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">396</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> c)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">397</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">398</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">detail::append_number</a> (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, c);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">399</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a07bd2bc6c72722228701c2e5f3bfeed8">append_suffix</a> (</span><span class="doxyHighlightStringLiteral">"uc"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">400</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">401</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">micro_os_plus::micro_test_plus::detail::append_number</a>, <a href="#a07bd2bc6c72722228701c2e5f3bfeed8">append_suffix</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

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


<p>Converts <span class="doxyComputerOutput">v</span> to its decimal string representation via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">append_number()</a></span> and appends the type suffix <span class="doxyComputerOutput">"u"</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00512">512</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00447">447</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">447</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">448</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">449</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">detail::append_number</a> (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">450</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a07bd2bc6c72722228701c2e5f3bfeed8">append_suffix</a> (</span><span class="doxyHighlightStringLiteral">"u"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">451</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">452</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">micro_os_plus::micro_test_plus::detail::append_number</a>, <a href="#a07bd2bc6c72722228701c2e5f3bfeed8">append_suffix</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

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


<p>Converts <span class="doxyComputerOutput">v</span> to its decimal string representation via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">append_number()</a></span> and appends the type suffix <span class="doxyComputerOutput">"ull"</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00548">548</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00499">499</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">499</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">500</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">501</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">detail::append_number</a> (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">502</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a07bd2bc6c72722228701c2e5f3bfeed8">append_suffix</a> (</span><span class="doxyHighlightStringLiteral">"ull"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">503</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">504</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">micro_os_plus::micro_test_plus::detail::append_number</a>, <a href="#a07bd2bc6c72722228701c2e5f3bfeed8">append_suffix</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

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


<p>Converts <span class="doxyComputerOutput">v</span> to its decimal string representation via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">append_number()</a></span> and appends the type suffix <span class="doxyComputerOutput">"ul"</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00530">530</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00473">473</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">473</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">474</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">475</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">detail::append_number</a> (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">476</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a07bd2bc6c72722228701c2e5f3bfeed8">append_suffix</a> (</span><span class="doxyHighlightStringLiteral">"ul"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">477</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">478</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">micro_os_plus::micro_test_plus::detail::append_number</a>, <a href="#a07bd2bc6c72722228701c2e5f3bfeed8">append_suffix</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

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


<p>Converts <span class="doxyComputerOutput">v</span> to its decimal string representation via <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">append_number()</a></span> and appends the type suffix <span class="doxyComputerOutput">"us"</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00494">494</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00422">422</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">422</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">short</span><span class="doxyHighlight"> v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">423</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">424</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">detail::append_number</a> (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">425</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a07bd2bc6c72722228701c2e5f3bfeed8">append_suffix</a> (</span><span class="doxyHighlightStringLiteral">"us"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">426</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">427</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3abe0c9c597c7fe04a5f101022ecea5d">micro_os_plus::micro_test_plus::detail::append_number</a>, <a href="#a07bd2bc6c72722228701c2e5f3bfeed8">append_suffix</a> and <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#ad90b0391a9b4fb44cc89208745bdfe70}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator&lt;&lt; (wchar_t c)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends a wide character, as a quoted <span class="doxyComputerOutput">L</span> literal, to the buffer.</p>


<p>The value is written with the <span class="doxyComputerOutput">L</span> prefix, as a <span class="doxyComputerOutput">char16_t</span> value where <span class="doxyComputerOutput">wchar_t</span> has 16 bits (Windows), and as a <span class="doxyComputerOutput">char32_t</span> value elsewhere (<span class="doxyComputerOutput">L'a'</span>, <span class="doxyComputerOutput">L'\\u00e9'</span>); a negative value is written by its bits. Without the overload, the value would be promoted to an integer type and written as a number. The plain mode, used for the messages, writes it in the same way, since it cannot be appended unchanged.</p>


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


<p>Written by <span class="doxyComputerOutput"><a href="#a1af5c2ffe3cd4eacad21667c2d4e3914">append_character()</a></span> with the <span class="doxyComputerOutput">L</span> prefix, also in the plain mode. The value is first converted to the unsigned type of the same size, so that a negative value is not sign-extended to 32 bits.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00391">391</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00278">278</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">278</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a937600e01855336e5ef437104e7ee688">expression_formatter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">wchar_t</span><span class="doxyHighlight"> c)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">279</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">280</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1af5c2ffe3cd4eacad21667c2d4e3914">append_character</a> (</span><span class="doxyHighlightStringLiteral">"L"</span><span class="doxyHighlight">, </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">std::make_unsigned_t&lt;wchar_t&gt;</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (c),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">281</span><span class="doxyLineContent"><span class="doxyHighlight">                      </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (c));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">282</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">283</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> and <a href="#a1af5c2ffe3cd4eacad21667c2d4e3914">append_character</a>.</p>

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
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator= (const <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;)</td>
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


<p>The formatter is owned by a reporter and refers to its colours.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00258">258</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>.</p>


<p>Reference <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>.</p>

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
<td class="doxyMemberName">expression_formatter &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::operator= (<a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> &amp;&amp;)</td>
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


<p>The formatter is owned by a reporter and refers to its colours.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00268">268</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>.</p>


<p>Reference <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Member Functions

### str() {#a57a2737ff5f067461e4f220acd9fcd4b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const std::string &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::str (void)</td>
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

<p>Returns the text written to the formatter.</p>


<p>Intended for testing the application <span class="doxyComputerOutput">operator&lt;&lt;</span> functions with a formatter constructed for this purpose; since the formatter only appends, the text of each value starts where the previous one ended. The text cannot be modified through this reference.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Const reference to the accumulated string.</p></dd>
</dl>


<p>Returns a const reference to the internal <span class="doxyComputerOutput"><a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a></span> string.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00882">882</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00117">117</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a57a2737ff5f067461e4f220acd9fcd4b">117</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a57a2737ff5f067461e4f220acd9fcd4b">expression_formatter::str</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">118</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">119</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">120</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>


<p>Referenced by <a href="#a0f53d49c9cf2bcbf4b5b35f136f769ce">operator&lt;&lt;</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Private Member Functions

### append\_and\_operand() {#a29db61e42922091f047726fcdb4ba5b7}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::expression_formatter::append_and_operand (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/and-op">detail::and_op</a>&lt; Lhs_T, Rhs_T &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends the operands of a logical AND, separated by <span class="doxyComputerOutput">and</span>.</p>


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
<dd><p>Nothing.</p></dd>
</dl>


<p>The left operand is written first, as the operands of a chain if it is a logical AND too, then the word <span class="doxyComputerOutput">and</span>, coloured by the result of this operation, and the right operand.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l01057">1057</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00369">369</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a29db61e42922091f047726fcdb4ba5b7">369</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a74bb5c3c4b3feacc77d1afe464a7c988">expression_formatter::append_and_operand</a> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">370</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/and-op">detail::and_op&lt;Lhs_T, Rhs_T&gt;</a>&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">371</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">372</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a74bb5c3c4b3feacc77d1afe464a7c988">append_and_operand</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>.lhs ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">373</span><span class="doxyLineContent"><span class="doxyHighlight">    *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="#a2440544fb5674da8853708f9af9ccc14">colour</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>) &lt;&lt; </span><span class="doxyHighlightStringLiteral">" and "</span><span class="doxyHighlight"> &lt;&lt; <a href="#a566350d8ec85e4c0b5d8a27ef61f819f">colours_</a>.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours/#a42937839aa8c23e1c5482582eaf2aeb7">none</a> &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>.rhs ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">374</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a74bb5c3c4b3feacc77d1afe464a7c988">append_and_operand</a>, <a href="#a2440544fb5674da8853708f9af9ccc14">colour</a>, <a href="#a566350d8ec85e4c0b5d8a27ef61f819f">colours_</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours/#a42937839aa8c23e1c5482582eaf2aeb7">micro_os_plus::micro_test_plus::detail::colours::none</a>.</p>

</div>
</div>

### append\_and\_operand() {#a74bb5c3c4b3feacc77d1afe464a7c988}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::expression_formatter::append_and_operand (const T &amp; t)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends an operand of a chain of logical ANDs.</p>


<p>An operand that is itself a logical AND is written as the operands of a chain, without its own parentheses; any other operand is written as usual.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The type of the operand.</p></td>
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
<td class="doxyParamItemDescription"><p>The operand.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>The generic operand is written through the usual overloads.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l01044">1044</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00356">356</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a74bb5c3c4b3feacc77d1afe464a7c988">356</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a74bb5c3c4b3feacc77d1afe464a7c988">expression_formatter::append_and_operand</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; t)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">357</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">358</span><span class="doxyLineContent"><span class="doxyHighlight">    *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; t;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">359</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Referenced by <a href="#a29db61e42922091f047726fcdb4ba5b7">append_and_operand</a>, <a href="#ac7bb8541495fe98975132f546f5529bc">operator&lt;&lt;</a> and <a href="#a0f53d49c9cf2bcbf4b5b35f136f769ce">operator&lt;&lt;</a>.</p>

</div>
</div>

### append\_character() {#a1af5c2ffe3cd4eacad21667c2d4e3914}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::expression_formatter::append_character (std::string_view prefix, char32_t code, std::size_t size)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends a character, or a code unit, as a quoted literal.</p>


<p>Shared by the overloads of all the character types, so that they escape the values in the same way. The usual escape sequences are used for <span class="doxyComputerOutput">'\\0'</span>, <span class="doxyComputerOutput">'\\a'</span>, <span class="doxyComputerOutput">'\\b'</span>, <span class="doxyComputerOutput">'\\t'</span>, <span class="doxyComputerOutput">'\\n'</span>, <span class="doxyComputerOutput">'\\v'</span>, <span class="doxyComputerOutput">'\\f'</span>, <span class="doxyComputerOutput">'\\r'</span>, <span class="doxyComputerOutput">'\\''</span>, and <span class="doxyComputerOutput">'\\\\'</span>, and the other control characters and <span class="doxyComputerOutput">DEL</span> are written as two hexadecimal digits (<span class="doxyComputerOutput">'\\x1b'</span>). The values that are not characters by themselves (the values above <span class="doxyComputerOutput">127</span> of the 8-bit types, the surrogates, and the values above <span class="doxyComputerOutput">1114111</span>) are written with <span class="doxyComputerOutput">\\x</span> and all the hexadecimal digits of their type, and the other values outside ASCII as universal character names, <span class="doxyComputerOutput">\\u</span> with four digits, or <span class="doxyComputerOutput">\\U</span> with eight. The printable ASCII characters are written unchanged. The hexadecimal digits are lowercase.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">prefix</td>
<td class="doxyParamItemDescription"><p>The prefix of the literal (<span class="doxyComputerOutput">""</span>, <span class="doxyComputerOutput">"u8"</span>, <span class="doxyComputerOutput">"u"</span>, <span class="doxyComputerOutput">"U"</span>, or <span class="doxyComputerOutput">"L"</span>).</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">code</td>
<td class="doxyParamItemDescription"><p>The value, converted without the sign extension.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">size</td>
<td class="doxyParamItemDescription"><p>The size of the character type, in bytes.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>A value of an 8-bit type above <span class="doxyComputerOutput">127</span> is a part of a multi-byte sequence; for the wider types, the surrogates (<span class="doxyComputerOutput">55296</span> to <span class="doxyComputerOutput">57343</span>) and the values above <span class="doxyComputerOutput">1114111</span> are not Unicode characters, and cannot be written as universal character names. They are written with <span class="doxyComputerOutput">\\x</span> and twice as many hexadecimal digits as the bytes of the type, so that the width of the type is visible. The control characters keep the two digits of <span class="doxyComputerOutput">char</span>, since they are the same in all the encodings.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l01007">1007</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00625">625</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a1af5c2ffe3cd4eacad21667c2d4e3914">625</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a1af5c2ffe3cd4eacad21667c2d4e3914">expression_formatter::append_character</a> (std::string_view prefix,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">626</span><span class="doxyLineContent"><span class="doxyHighlight">                                          </span><span class="doxyHighlightKeywordType">char32_t</span><span class="doxyHighlight"> code, std::size_t size)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">627</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">628</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (prefix);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">629</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.push_back (</span><span class="doxyHighlightCharLiteral">'\''</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">630</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">switch</span><span class="doxyHighlight"> (code)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">631</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">632</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> U</span><span class="doxyHighlightCharLiteral">'\0'</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">633</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"\\0"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">634</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">635</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> U</span><span class="doxyHighlightCharLiteral">'\a'</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">636</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"\\a"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">637</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">638</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> U</span><span class="doxyHighlightCharLiteral">'\b'</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">639</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"\\b"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">640</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">641</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> U</span><span class="doxyHighlightCharLiteral">'\t'</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">642</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"\\t"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">643</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">644</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> U</span><span class="doxyHighlightCharLiteral">'\n'</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">645</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"\\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">646</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">647</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> U</span><span class="doxyHighlightCharLiteral">'\v'</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">648</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"\\v"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">649</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">650</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> U</span><span class="doxyHighlightCharLiteral">'\f'</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">651</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"\\f"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">652</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">653</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> U</span><span class="doxyHighlightCharLiteral">'\r'</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">654</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"\\r"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">655</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">656</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> U</span><span class="doxyHighlightCharLiteral">'\''</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">657</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"\\'"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">658</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">659</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">case</span><span class="doxyHighlight"> U</span><span class="doxyHighlightCharLiteral">'\\'</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">660</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"\\\\"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">661</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">662</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">default</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">663</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (code &lt; 32 || code == 0x7F)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">664</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">665</span><span class="doxyLineContent"><span class="doxyHighlight">            append_hex (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, code, </span><span class="doxyHighlightStringLiteral">"\\x"</span><span class="doxyHighlight">, 2);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">666</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">667</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (code &lt; 0x7F)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">668</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">669</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.push_back (</span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (code));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">670</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">671</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (size == 1 || (code &gt;= 55296 &amp;&amp; code &lt;= 0xDFFF)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">672</span><span class="doxyLineContent"><span class="doxyHighlight">                 || code &gt; 0x10FFFF)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">673</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">674</span><span class="doxyLineContent"><span class="doxyHighlight">            append_hex (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, code, </span><span class="doxyHighlightStringLiteral">"\\x"</span><span class="doxyHighlight">, size * 2);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">675</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">676</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (code &lt;= 0xFFFF)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">677</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">678</span><span class="doxyLineContent"><span class="doxyHighlight">            append_hex (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, code, </span><span class="doxyHighlightStringLiteral">"\\u"</span><span class="doxyHighlight">, 4);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">679</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">680</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">681</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">682</span><span class="doxyLineContent"><span class="doxyHighlight">            append_hex (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, code, </span><span class="doxyHighlightStringLiteral">"\\U"</span><span class="doxyHighlight">, 8);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">683</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">684</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">break</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">685</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">686</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.push_back (</span><span class="doxyHighlightCharLiteral">'\''</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">687</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.</p>


<p>Referenced by <a href="#a6df410b7ec951a5563b1fae75ed31350">operator&lt;&lt;</a>, <a href="#a66178d7bc2ba82aa370731f91381e2e2">operator&lt;&lt;</a>, <a href="#aa273723118d3fc995eb3e2929d78f280">operator&lt;&lt;</a>, <a href="#a0f53d49c9cf2bcbf4b5b35f136f769ce">operator&lt;&lt;</a> and <a href="#ad90b0391a9b4fb44cc89208745bdfe70">operator&lt;&lt;</a>.</p>

</div>
</div>

### append\_decimal\_point() {#a7b397504fbb760801d70b1a06186a599}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::expression_formatter::append_decimal_point (std::size_t start)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Adds a decimal point to a floating-point value formatted as an integer.</p>


<p>Called after a floating-point value was appended to the buffer; <span class="doxyComputerOutput">".0"</span> is appended only if the value was written with digits only, and not in the plain mode.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">start</td>
<td class="doxyParamItemDescription"><p>The position in the buffer where the value begins.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>The shortest representation of a floating-point value with an integral value has no decimal point (<span class="doxyComputerOutput">42</span> is formatted as <span class="doxyComputerOutput">42</span>), so it cannot be distinguished from an integer. If the text appended since <span class="doxyComputerOutput">start</span> contains only digits, after an optional sign, <span class="doxyComputerOutput">".0"</span> is appended. The text with a decimal point or an exponent, and the infinities and NaNs, are left unchanged, as is all text in the plain mode, used for the messages.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00965">965</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00574">574</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a7b397504fbb760801d70b1a06186a599">574</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a7b397504fbb760801d70b1a06186a599">expression_formatter::append_decimal_point</a> (std::size_t start)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">575</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">576</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a4a956e5994817535692a7684eb26e149">plain_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">577</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">578</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">579</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">580</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (start &lt; <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.size ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">581</span><span class="doxyLineContent"><span class="doxyHighlight">        &amp;&amp; (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>[start] == </span><span class="doxyHighlightCharLiteral">'-'</span><span class="doxyHighlight"> || <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>[start] == </span><span class="doxyHighlightCharLiteral">'+'</span><span class="doxyHighlight">))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">582</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">583</span><span class="doxyLineContent"><span class="doxyHighlight">        ++start;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">584</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">585</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (start == <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.size ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">586</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">587</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">588</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">589</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> i = start; i &lt; <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.size (); ++i)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">590</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">591</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>[i] &lt; </span><span class="doxyHighlightCharLiteral">'0'</span><span class="doxyHighlight"> || <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>[i] &gt; </span><span class="doxyHighlightCharLiteral">'9'</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">592</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">593</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">594</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">595</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">596</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">".0"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">597</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a> and <a href="#a4a956e5994817535692a7684eb26e149">plain_</a>.</p>


<p>Referenced by <a href="#a0f53d49c9cf2bcbf4b5b35f136f769ce">operator&lt;&lt;</a>, <a href="#ae35ae1fef3c1b19f78d9d01c46e389e5">operator&lt;&lt;</a>, <a href="#a28f6feb880950d846e9d527254e019cd">operator&lt;&lt;</a> and <a href="#addfdc62bee977a9bec102e7babec03e1">operator&lt;&lt;</a>.</p>

</div>
</div>

### append\_elements() {#a2966189c9d09d874a21e069c10a23b44}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Tuple_T, std::size_t... Is&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::expression_formatter::append_elements (const Tuple_T &amp; t, std::index_sequence&lt; Is... &gt;)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends the elements of a tuple-like object, separated by commas.</p>


<p>Shared by the pair and tuple overloads; the elements are obtained with <span class="doxyComputerOutput">std::get&lt;Is&gt;()</span> and formatted through <span class="doxyComputerOutput">operator&lt;&lt;</span>, without the enclosing parentheses.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Tuple_T</td>
<td class="doxyParamItemDescription"><p>A type accepted by <span class="doxyComputerOutput">std::get</span> (a pair or a tuple).</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Is</td>
<td class="doxyParamItemDescription"><p>The indices of the elements.</p></td>
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
<td class="doxyParamItemDescription"><p>The tuple-like object.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Expands the indices in a fold expression over the comma operator, so the elements are written in order; the separator is omitted before the first element. For an empty tuple, nothing is written.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l01027">1027</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00294">294</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a2966189c9d09d874a21e069c10a23b44">294</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a2966189c9d09d874a21e069c10a23b44">expression_formatter::append_elements</a> ([[maybe_unused]] </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Tuple_T&amp; t,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">295</span><span class="doxyLineContent"><span class="doxyHighlight">                                         std::index_sequence&lt;Is...&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">296</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">297</span><span class="doxyLineContent"><span class="doxyHighlight">    ((*</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; (Is == 0 ? </span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight"> : </span><span class="doxyHighlightStringLiteral">", "</span><span class="doxyHighlight">) &lt;&lt; std::get&lt;Is&gt; (t)), ...);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">298</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Referenced by <a href="#a2ca994c99c86ce1d5fdef788f9ece933">operator&lt;&lt;</a>, <a href="#a277c1153e2afdb1a09df62f9858e4976">operator&lt;&lt;</a> and <a href="#a0f53d49c9cf2bcbf4b5b35f136f769ce">operator&lt;&lt;</a>.</p>

</div>
</div>

### append\_or\_operand() {#a0f5470c06633dea5bd77ad15a578a380}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::expression_formatter::append_or_operand (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/or-op">detail::or_op</a>&lt; Lhs_T, Rhs_T &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends the operands of a logical OR, separated by <span class="doxyComputerOutput">or</span>.</p>


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
<dd><p>Nothing.</p></dd>
</dl>


<p>The left operand is written first, as the operands of a chain if it is a logical OR too, then the word <span class="doxyComputerOutput">or</span>, coloured by the result of this operation, and the right operand.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l01085">1085</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00410">410</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a0f5470c06633dea5bd77ad15a578a380">410</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#abca8031b08daa1101165c0ba47709d8b">expression_formatter::append_or_operand</a> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">411</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/or-op">detail::or_op&lt;Lhs_T, Rhs_T&gt;</a>&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">412</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">413</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#abca8031b08daa1101165c0ba47709d8b">append_or_operand</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>.lhs ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">414</span><span class="doxyLineContent"><span class="doxyHighlight">    *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="#a2440544fb5674da8853708f9af9ccc14">colour</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>) &lt;&lt; </span><span class="doxyHighlightStringLiteral">" or "</span><span class="doxyHighlight"> &lt;&lt; <a href="#a566350d8ec85e4c0b5d8a27ef61f819f">colours_</a>.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours/#a42937839aa8c23e1c5482582eaf2aeb7">none</a> &lt;&lt; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>.rhs ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">415</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#abca8031b08daa1101165c0ba47709d8b">append_or_operand</a>, <a href="#a2440544fb5674da8853708f9af9ccc14">colour</a>, <a href="#a566350d8ec85e4c0b5d8a27ef61f819f">colours_</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours/#a42937839aa8c23e1c5482582eaf2aeb7">micro_os_plus::micro_test_plus::detail::colours::none</a>.</p>

</div>
</div>

### append\_or\_operand() {#abca8031b08daa1101165c0ba47709d8b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::expression_formatter::append_or_operand (const T &amp; t)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends an operand of a chain of logical ORs.</p>


<p>Like <span class="doxyComputerOutput"><a href="#a74bb5c3c4b3feacc77d1afe464a7c988">append_and_operand()</a></span>, for the logical OR.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The type of the operand.</p></td>
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
<td class="doxyParamItemDescription"><p>The operand.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>The generic operand is written through the usual overloads.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l01072">1072</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00397">397</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#abca8031b08daa1101165c0ba47709d8b">397</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#abca8031b08daa1101165c0ba47709d8b">expression_formatter::append_or_operand</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; t)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">398</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">399</span><span class="doxyLineContent"><span class="doxyHighlight">    *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; t;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">400</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Referenced by <a href="#a0f5470c06633dea5bd77ad15a578a380">append_or_operand</a>, <a href="#a5a5535dbaa45481b3b6f74186d43152e">operator&lt;&lt;</a> and <a href="#a0f53d49c9cf2bcbf4b5b35f136f769ce">operator&lt;&lt;</a>.</p>

</div>
</div>

### append\_suffix() {#a07bd2bc6c72722228701c2e5f3bfeed8}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::expression_formatter::append_suffix (const char * suffix)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends the type suffix of a number.</p>


<p>Called after a number was appended to the buffer; in the plain mode, used for the messages, nothing is appended.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">suffix</td>
<td class="doxyParamItemDescription"><p>The suffix, named after the µTest++ literal of the type (e.g. <span class="doxyComputerOutput">"u"</span>, <span class="doxyComputerOutput">"ll"</span>, <span class="doxyComputerOutput">"f"</span>).</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Appends <span class="doxyComputerOutput">suffix</span>, unless the formatter is in the plain mode, used for the messages, which writes the numbers without suffixes.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00980">980</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00605">605</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a07bd2bc6c72722228701c2e5f3bfeed8">605</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a07bd2bc6c72722228701c2e5f3bfeed8">expression_formatter::append_suffix</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* suffix)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">606</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">607</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (not <a href="#a4a956e5994817535692a7684eb26e149">plain_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">608</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">609</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.append (suffix);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">610</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">611</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a> and <a href="#a4a956e5994817535692a7684eb26e149">plain_</a>.</p>


<p>Referenced by <a href="#a0f53d49c9cf2bcbf4b5b35f136f769ce">operator&lt;&lt;</a>, <a href="#a28f6feb880950d846e9d527254e019cd">operator&lt;&lt;</a>, <a href="#addfdc62bee977a9bec102e7babec03e1">operator&lt;&lt;</a>, <a href="#a50d03426268411a1481d778952bdb8f4">operator&lt;&lt;</a>, <a href="#a93e6a5524f5cd912acd200cf7842ddf4">operator&lt;&lt;</a>, <a href="#adec3880ea2146b10b4b6ff188ad0a57c">operator&lt;&lt;</a>, <a href="#a51879a69ec3bbd2d36614f05b7991748">operator&lt;&lt;</a>, <a href="#a41d15d145121a646d3ec8e2a53626658">operator&lt;&lt;</a>, <a href="#a9943e733445290a4296bd236ba5b1294">operator&lt;&lt;</a>, <a href="#a2f40f5b293810e4c9c55340dd7074936">operator&lt;&lt;</a>, <a href="#ac2b6dfdd70318f5005035667d19814b2">operator&lt;&lt;</a> and <a href="#a60165c67928c5bab83c4dac211b50ec4">operator&lt;&lt;</a>.</p>

</div>
</div>

### begin\_check() {#a433e0e309292ccc3e42a35076e32d6c3}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::expression_formatter::begin_check (const void * owner)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Prepares the buffer for the expression of a new check.</p>


<p>If the text in the buffer belongs to a check that was not reported yet (its result was kept in a variable), the text is first moved aside, so that this check can still report it. The buffer is then cleared and assigned to <span class="doxyComputerOutput">owner</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">owner</td>
<td class="doxyParamItemDescription"><p>The check that will format its expression next.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>In the usual case, the previous check was already reported (its <span class="doxyComputerOutput"><a href="#aa568154ec1095196010a66fec43a393f">end_check()</a></span> reset <span class="doxyComputerOutput"><a href="#aaa185fbbc82e45621ca924efea6c8a3c">owner_</a></span>), and the buffer is only cleared, keeping its capacity. Otherwise the text of the previous, still pending, check is moved into <span class="doxyComputerOutput"><a href="#a5efacef89d1d5150982bbce240ac625e">pending_</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00916">916</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00699">699</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a433e0e309292ccc3e42a35076e32d6c3">699</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a433e0e309292ccc3e42a35076e32d6c3">expression_formatter::begin_check</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">* owner)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">700</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">701</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#aaa185fbbc82e45621ca924efea6c8a3c">owner_</a> != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">702</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">703</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a5efacef89d1d5150982bbce240ac625e">pending_</a>.emplace_back (<a href="#aaa185fbbc82e45621ca924efea6c8a3c">owner_</a>, std::move (<a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">704</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">705</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">706</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>.clear ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">707</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#aaa185fbbc82e45621ca924efea6c8a3c">owner_</a> = owner;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">708</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, <a href="#aaa185fbbc82e45621ca924efea6c8a3c">owner_</a> and <a href="#a5efacef89d1d5150982bbce240ac625e">pending_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result/#a3c6ef4e73f3bf898f1682187dc86919d">micro_os_plus::micro_test_plus::detail::check_result::check_result</a> and <a href="#a0f53d49c9cf2bcbf4b5b35f136f769ce">operator&lt;&lt;</a>.</p>

</div>
</div>

### check\_text() {#ae0068f2e9d46a29c71fcc812f505fbce}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const std::string &amp; micro_os_plus::micro_test_plus::detail::expression_formatter::check_text (const void * owner)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Returns the expression text of a check.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">owner</td>
<td class="doxyParamItemDescription"><p>The check that formatted the expression.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The text in the buffer, if it still belongs to <span class="doxyComputerOutput">owner</span>, otherwise the text moved aside for it; it remains valid until <span class="doxyComputerOutput"><a href="#aa568154ec1095196010a66fec43a393f">end_check()</a></span>.</p></dd>
</dl>


<p>Searches <span class="doxyComputerOutput"><a href="#a5efacef89d1d5150982bbce240ac625e">pending_</a></span> only when the buffer belongs to another check. If the check is not found (which does not happen when the calls are paired), an empty string is returned.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00927">927</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00717">717</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ae0068f2e9d46a29c71fcc812f505fbce">717</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ae0068f2e9d46a29c71fcc812f505fbce">expression_formatter::check_text</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">* owner) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">718</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">719</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (owner == <a href="#aaa185fbbc82e45621ca924efea6c8a3c">owner_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">720</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">721</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">722</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">723</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">724</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> i = 0; i &lt; <a href="#a5efacef89d1d5150982bbce240ac625e">pending_</a>.size (); ++i)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">725</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">726</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a5efacef89d1d5150982bbce240ac625e">pending_</a>[i].first == owner)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">727</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">728</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a5efacef89d1d5150982bbce240ac625e">pending_</a>[i].second;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">729</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">730</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">731</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">732</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string empty{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">733</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> empty;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">734</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>, <a href="#aaa185fbbc82e45621ca924efea6c8a3c">owner_</a> and <a href="#a5efacef89d1d5150982bbce240ac625e">pending_</a>.</p>


<p>Referenced by <a href="#a0f53d49c9cf2bcbf4b5b35f136f769ce">operator&lt;&lt;</a>.</p>

</div>
</div>

### colour() {#a2440544fb5674da8853708f9af9ccc14}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::detail::expression_formatter::colour (const bool cond)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
<span class="doxyMemberLabel nodiscard">nodiscard</span>
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


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00949">949</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h/#l00105">105</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">expression-formatter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a2440544fb5674da8853708f9af9ccc14">105</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a2440544fb5674da8853708f9af9ccc14">expression_formatter::colour</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> cond)</span><span class="doxyHighlightKeyword"> const</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">106</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">  </span><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">107</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> cond ? <a href="#a566350d8ec85e4c0b5d8a27ef61f819f">colours_</a>.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours/#ac3953ba58fbf322bd310c857844d17fe">pass</a> : <a href="#a566350d8ec85e4c0b5d8a27ef61f819f">colours_</a>.<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours/#a7cd442bbb5af0f5d53632101d5c2eb0b">fail</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">108</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a566350d8ec85e4c0b5d8a27ef61f819f">colours_</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours/#a7cd442bbb5af0f5d53632101d5c2eb0b">micro_os_plus::micro_test_plus::detail::colours::fail</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours/#ac3953ba58fbf322bd310c857844d17fe">micro_os_plus::micro_test_plus::detail::colours::pass</a>.</p>


<p>Referenced by <a href="#a29db61e42922091f047726fcdb4ba5b7">append_and_operand</a>, <a href="#a0f5470c06633dea5bd77ad15a578a380">append_or_operand</a>, <a href="#a7dbef1dcdbb8e4187ec4f28b41ed32fc">operator&lt;&lt;</a>, <a href="#a91cd5a527853b70e7523e3180cb883f0">operator&lt;&lt;</a>, <a href="#a69d49647528979d6927386cfb4ba29ec">operator&lt;&lt;</a>, <a href="#a0ffe9183360b8f7e674f8546888ec5cc">operator&lt;&lt;</a>, <a href="#af68e85825621bce88f656ced9be5396e">operator&lt;&lt;</a>, <a href="#a6734ab254c188ce23514b5e84dd1232f">operator&lt;&lt;</a> and <a href="#a0f53d49c9cf2bcbf4b5b35f136f769ce">operator&lt;&lt;</a>.</p>

</div>
</div>

### end\_check() {#aa568154ec1095196010a66fec43a393f}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::expression_formatter::end_check (const void * owner)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel noexcept">noexcept</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Releases the expression text of a check, after it was reported.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">owner</td>
<td class="doxyParamItemDescription"><p>The check that formatted the expression.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>If the buffer belongs to <span class="doxyComputerOutput">owner</span>, it is released (and reused by the next check); otherwise the text moved aside for <span class="doxyComputerOutput">owner</span> is removed from <span class="doxyComputerOutput"><a href="#a5efacef89d1d5150982bbce240ac625e">pending_</a></span>, by moving the last entry into its place.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l00938">938</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp/#l00743">743</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/expression-formatter-cpp">expression-formatter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aa568154ec1095196010a66fec43a393f">743</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#aa568154ec1095196010a66fec43a393f">expression_formatter::end_check</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">* owner) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">744</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">745</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (owner == <a href="#aaa185fbbc82e45621ca924efea6c8a3c">owner_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">746</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">747</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#aaa185fbbc82e45621ca924efea6c8a3c">owner_</a> = </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">748</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">749</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">750</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">751</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Use indices and `swap()` + `pop_back()` (both returning void) rather</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">752</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// than iterators and `erase()`, which returns an iterator object and</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">753</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// triggers -Waggregate-return; the order of the entries is irrelevant.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">754</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> i = 0; i &lt; <a href="#a5efacef89d1d5150982bbce240ac625e">pending_</a>.size (); ++i)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">755</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">756</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a5efacef89d1d5150982bbce240ac625e">pending_</a>[i].first == owner)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">757</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">758</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (i + 1 != <a href="#a5efacef89d1d5150982bbce240ac625e">pending_</a>.size ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">759</span><span class="doxyLineContent"><span class="doxyHighlight">              {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">760</span><span class="doxyLineContent"><span class="doxyHighlight">                <a href="#a5efacef89d1d5150982bbce240ac625e">pending_</a>[i].swap (<a href="#a5efacef89d1d5150982bbce240ac625e">pending_</a>.back ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">761</span><span class="doxyLineContent"><span class="doxyHighlight">              }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">762</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="#a5efacef89d1d5150982bbce240ac625e">pending_</a>.pop_back ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">763</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">764</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">765</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">766</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#aaa185fbbc82e45621ca924efea6c8a3c">owner_</a> and <a href="#a5efacef89d1d5150982bbce240ac625e">pending_</a>.</p>


<p>Referenced by <a href="#a0f53d49c9cf2bcbf4b5b35f136f769ce">operator&lt;&lt;</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Private Member Attributes

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
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The internal output buffer.</p>


<p>Accumulates the formatted text; cleared by <span class="doxyComputerOutput"><a href="#a433e0e309292ccc3e42a35076e32d6c3">begin_check()</a></span>.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l01102">1102</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">1102</a></span><span class="doxyLineContent"><span class="doxyHighlight">      std::string <a href="#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>{};</span></span></div>

</div>


<p>Referenced by <a href="#a5c2acf2640374b8d971193eae264c26c">expression_formatter</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/plain-text/#a63b3cc3a8e725c2921787180f1244824">micro_os_plus::micro_test_plus::detail::plain_text::append</a>, <a href="#a1af5c2ffe3cd4eacad21667c2d4e3914">append_character</a>, <a href="#a7b397504fbb760801d70b1a06186a599">append_decimal_point</a>, <a href="#a07bd2bc6c72722228701c2e5f3bfeed8">append_suffix</a>, <a href="#a433e0e309292ccc3e42a35076e32d6c3">begin_check</a>, <a href="#ae0068f2e9d46a29c71fcc812f505fbce">check_text</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result/#a44b0e35cd70af1cd0bfe333ffd6629e9">micro_os_plus::micro_test_plus::detail::check_result::operator&lt;&lt;</a>, <a href="#a4b24176d3597d73506e5bf0b71bdab2a">operator&lt;&lt;</a>, <a href="#a6df410b7ec951a5563b1fae75ed31350">operator&lt;&lt;</a>, <a href="#a984d2b715e58437c9e2bd3455174ae60">operator&lt;&lt;</a>, <a href="#afd1a0e24d72c0525f04e102fc2e6fb78">operator&lt;&lt;</a>, <a href="#a6734ab254c188ce23514b5e84dd1232f">operator&lt;&lt;</a>, <a href="#a46392700e7eabfa2e18655ac6b04c670">operator&lt;&lt;</a>, <a href="#a533424913419f7a9a763cd4db9d1f87e">operator&lt;&lt;</a>, <a href="#ae35ae1fef3c1b19f78d9d01c46e389e5">operator&lt;&lt;</a>, <a href="#a28f6feb880950d846e9d527254e019cd">operator&lt;&lt;</a>, <a href="#addfdc62bee977a9bec102e7babec03e1">operator&lt;&lt;</a>, <a href="#a50d03426268411a1481d778952bdb8f4">operator&lt;&lt;</a>, <a href="#a2852a7fdaabf1036ddbeb50b2e0a23bd">operator&lt;&lt;</a>, <a href="#a93e6a5524f5cd912acd200cf7842ddf4">operator&lt;&lt;</a>, <a href="#adec3880ea2146b10b4b6ff188ad0a57c">operator&lt;&lt;</a>, <a href="#a51879a69ec3bbd2d36614f05b7991748">operator&lt;&lt;</a>, <a href="#afedb833a4ea9bd720a9c9f471ea8ab34">operator&lt;&lt;</a>, <a href="#a9f9170708f0763a39314e19902843b4b">operator&lt;&lt;</a>, <a href="#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>, <a href="#a965d6164f8c6d50cfb29545e794e9615">operator&lt;&lt;</a>, <a href="#a41d15d145121a646d3ec8e2a53626658">operator&lt;&lt;</a>, <a href="#a9943e733445290a4296bd236ba5b1294">operator&lt;&lt;</a>, <a href="#a2f40f5b293810e4c9c55340dd7074936">operator&lt;&lt;</a>, <a href="#ac2b6dfdd70318f5005035667d19814b2">operator&lt;&lt;</a>, <a href="#a60165c67928c5bab83c4dac211b50ec4">operator&lt;&lt;</a> and <a href="#a57a2737ff5f067461e4f220acd9fcd4b">str</a>.</p>

</div>
</div>

### colours\_ {#a566350d8ec85e4c0b5d8a27ef61f819f}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const colours&amp; micro_os_plus::micro_test_plus::detail::expression_formatter::colours_</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>ANSI colour codes for output formatting.</p>


<p>A reference to the colours of the owning reporter, so that later changes (e.g. enabling colours) are picked up automatically.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l01094">1094</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a566350d8ec85e4c0b5d8a27ef61f819f">1094</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a>&amp; <a href="#a566350d8ec85e4c0b5d8a27ef61f819f">colours_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>, <a href="#a5c2acf2640374b8d971193eae264c26c">expression_formatter</a>, <a href="#a29db61e42922091f047726fcdb4ba5b7">append_and_operand</a>, <a href="#a0f5470c06633dea5bd77ad15a578a380">append_or_operand</a>, <a href="#a2440544fb5674da8853708f9af9ccc14">colour</a>, <a href="#a7dbef1dcdbb8e4187ec4f28b41ed32fc">operator&lt;&lt;</a>, <a href="#a91cd5a527853b70e7523e3180cb883f0">operator&lt;&lt;</a>, <a href="#a69d49647528979d6927386cfb4ba29ec">operator&lt;&lt;</a>, <a href="#a0ffe9183360b8f7e674f8546888ec5cc">operator&lt;&lt;</a>, <a href="#af68e85825621bce88f656ced9be5396e">operator&lt;&lt;</a> and <a href="#a6734ab254c188ce23514b5e84dd1232f">operator&lt;&lt;</a>.</p>

</div>
</div>

### owner\_ {#aaa185fbbc82e45621ca924efea6c8a3c}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const void* micro_os_plus::micro_test_plus::detail::expression_formatter::owner_ { nullptr }</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The check whose expression is in the buffer.</p>


<p>Set by <span class="doxyComputerOutput"><a href="#a433e0e309292ccc3e42a35076e32d6c3">begin_check()</a></span> and reset by <span class="doxyComputerOutput"><a href="#aa568154ec1095196010a66fec43a393f">end_check()</a></span>; <span class="doxyComputerOutput">nullptr</span> when the text in the buffer does not belong to a pending check.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l01111">1111</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aaa185fbbc82e45621ca924efea6c8a3c">1111</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">* <a href="#aaa185fbbc82e45621ca924efea6c8a3c">owner_</a>{ </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight"> };</span></span></div>

</div>


<p>Referenced by <a href="#a433e0e309292ccc3e42a35076e32d6c3">begin_check</a>, <a href="#ae0068f2e9d46a29c71fcc812f505fbce">check_text</a> and <a href="#aa568154ec1095196010a66fec43a393f">end_check</a>.</p>

</div>
</div>

### pending\_ {#a5efacef89d1d5150982bbce240ac625e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::vector&lt;std::pair&lt;const void*, std::string&gt; &gt; micro_os_plus::micro_test_plus::detail::expression_formatter::pending_ {}</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The expression texts of the pending checks whose buffer was reused.</p>


<p>Normally empty: a check is reported at the end of its statement, before the next check begins. Only when the result of a check is kept in a variable does a later check move its text here, keyed by the check, so that the check objects themselves do not need to own a copy, which would increase the stack usage of the test functions.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l01124">1124</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a5efacef89d1d5150982bbce240ac625e">1124</a></span><span class="doxyLineContent"><span class="doxyHighlight">      std::vector&lt;std::pair&lt;const void*, std::string&gt;&gt; <a href="#a5efacef89d1d5150982bbce240ac625e">pending_</a>{};</span></span></div>

</div>


<p>Referenced by <a href="#a433e0e309292ccc3e42a35076e32d6c3">begin_check</a>, <a href="#ae0068f2e9d46a29c71fcc812f505fbce">check_text</a> and <a href="#aa568154ec1095196010a66fec43a393f">end_check</a>.</p>

</div>
</div>

### plain\_ {#a4a956e5994817535692a7684eb26e149}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const bool micro_os_plus::micro_test_plus::detail::expression_formatter::plain_ { false }</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Whether the formatter writes a message.</p>


<p>Set only by the private constructor used by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">check_result</a></span>; in this mode the numbers have no type suffixes and no added decimal point, and the <span class="doxyComputerOutput">char</span> values are not quoted.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h/#l01134">1134</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a4a956e5994817535692a7684eb26e149">1134</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="#a4a956e5994817535692a7684eb26e149">plain_</a>{ </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight"> };</span></span></div>

</div>


<p>Referenced by <a href="#a5c2acf2640374b8d971193eae264c26c">expression_formatter</a>, <a href="#a7b397504fbb760801d70b1a06186a599">append_decimal_point</a>, <a href="#a07bd2bc6c72722228701c2e5f3bfeed8">append_suffix</a>, <a href="#a6df410b7ec951a5563b1fae75ed31350">operator&lt;&lt;</a> and <a href="#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>.</p>

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

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
