---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

title: Concepts
slug: /api/concepts
description: The C++20 concepts defined in the project
custom_edit_url: null
keywords:
  - doxygen
  - concepts
  - reference

---

<div class="doxyPage">

The C++20 concepts used by this project are:

<table class="doxyTreeTable">
<colgroup><col style="width:40%"><col></colgroup>

<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 12px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">N</span></span>
<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus">micro_os_plus</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
The primary namespace for the µOS++ framework
</td>
</tr>


<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 24px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">N</span></span>
<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_test_plus</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
Primary namespace for the µTest++ testing framework
</td>
</tr>


<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 36px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">N</span></span>
<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail">detail</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
Internal implementation details for the µTest++ framework
</td>
</tr>

<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">R</span></span>
<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/approx-operand">approx_operand</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
C++20 concept satisfied when <span class="doxyComputerOutput">T</span> is a valid operand of the approximate comparator
</td>
</tr>
<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">R</span></span>
<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/container-like">container_like</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
C++20 concept satisfied when <span class="doxyComputerOutput">T</span> provides both <span class="doxyComputerOutput">begin()</span> and <span class="doxyComputerOutput">end()</span> member functions
</td>
</tr>
<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">R</span></span>
<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/formattable-range">formattable_range</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
C++20 concept satisfied when <span class="doxyComputerOutput">T</span> is a range that the formatter writes element by element
</td>
</tr>
<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">R</span></span>
<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/free-range">free_range</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
C++20 concept satisfied when <span class="doxyComputerOutput">T</span> provides <span class="doxyComputerOutput">begin()</span> and <span class="doxyComputerOutput">end()</span> only as functions found by argument-dependent lookup
</td>
</tr>
<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">R</span></span>
<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/has-npos">has_npos</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
C++20 concept satisfied when <span class="doxyComputerOutput">T</span> provides a <span class="doxyComputerOutput">npos</span> member
</td>
</tr>
<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">R</span></span>
<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/has-value">has_value</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
C++20 concept satisfied when <span class="doxyComputerOutput">T</span> is a framework compile-time constant
</td>
</tr>
<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">R</span></span>
<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/lazy-message">lazy_message</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
C++20 concept satisfied when <span class="doxyComputerOutput">T</span> is a callable object that returns a printable message
</td>
</tr>
<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">R</span></span>
<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/static-suite-body">static_suite_body</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
The body of a static suite written for v5.0.1, whose first parameter is a <span class="doxyComputerOutput">static_suite&amp;</span> reference
</td>
</tr>
<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">R</span></span>
<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-values-range">test_values_range</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
C++20 concept satisfied when <span class="doxyComputerOutput">T</span> is a range of values for <span class="doxyComputerOutput">test_each()</span>
</td>
</tr>
<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">R</span></span>
<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-values-tuple">test_values_tuple</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
C++20 concept satisfied when <span class="doxyComputerOutput">T</span> is a tuple of values for <span class="doxyComputerOutput">test_each()</span>
</td>
</tr>

<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 36px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">N</span></span>
<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/extension">extension</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
The concepts for extending the µTest++ testing framework
</td>
</tr>

<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">R</span></span>
<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/any-op">any_op</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
C++20 concept satisfied when at least one of two types is a framework expression type
</td>
</tr>
<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">R</span></span>
<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/checkable">checkable</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
C++20 concept satisfied when a type can be used as a test expression in <span class="doxyComputerOutput">expect()</span> or <span class="doxyComputerOutput">require()</span>
</td>
</tr>
<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">R</span></span>
<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/has-epsilon">has_epsilon</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
C++20 concept satisfied when <span class="doxyComputerOutput">T</span> is a framework floating-point wrapper with a tolerance
</td>
</tr>
<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">R</span></span>
<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">is_op</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
C++20 concept satisfied when a type is a framework expression type
</td>
</tr>
<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">R</span></span>
<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/printable">printable</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
C++20 concept satisfied when a type can be appended to the message of a check result via <span class="doxyComputerOutput">operator&lt;&lt;</span>
</td>
</tr>

<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 36px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">N</span></span>
<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/type-traits">type_traits</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
Deprecated v5.0.1 namespace of the concepts and of the value wrapper templates
</td>
</tr>

<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">R</span></span>
<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/type-traits/has-value">has_value</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
Deprecated C++20 concept satisfied when <span class="doxyComputerOutput">T</span> has a member named <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/value">value</a></span>
</td>
</tr>
<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">R</span></span>
<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/type-traits/is-floating-point">is_floating_point</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
Deprecated C++20 concept satisfied when <span class="doxyComputerOutput">T</span> is a floating-point type
</td>
</tr>

</table>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
