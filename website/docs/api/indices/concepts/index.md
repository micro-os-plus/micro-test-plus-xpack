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
<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/type-traits">type_traits</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
Type trait utilities and metaprogramming support for the µTest++ testing framework
</td>
</tr>

<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">R</span></span>
<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/type-traits/any-op">any_op</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
C++20 concept satisfied when at least one of two types derives from <span class="doxyComputerOutput">op</span>
</td>
</tr>
<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">R</span></span>
<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/type-traits/checkable">checkable</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
C++20 concept satisfied when a type can be used as a test expression in <span class="doxyComputerOutput">expect()</span> or <span class="doxyComputerOutput">assume()</span>
</td>
</tr>
<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">R</span></span>
<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/type-traits/container-like">container_like</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
C++20 concept satisfied when <span class="doxyComputerOutput">T</span> provides both <span class="doxyComputerOutput">begin()</span> and <span class="doxyComputerOutput">end()</span> member functions
</td>
</tr>
<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">R</span></span>
<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/type-traits/has-epsilon">has_epsilon</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
C++20 concept satisfied when <span class="doxyComputerOutput">T</span> provides an <span class="doxyComputerOutput">epsilon</span> member
</td>
</tr>
<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">R</span></span>
<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/type-traits/has-npos">has_npos</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
C++20 concept satisfied when <span class="doxyComputerOutput">T</span> provides a <span class="doxyComputerOutput">npos</span> member
</td>
</tr>
<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">R</span></span>
<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/type-traits/has-value">has_value</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
C++20 concept satisfied when <span class="doxyComputerOutput">T</span> provides a <span class="doxyComputerOutput">value</span> member
</td>
</tr>
<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">R</span></span>
<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/type-traits/is-floating-point">is_floating_point</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
C++20 concept satisfied when <span class="doxyComputerOutput">T</span> is a standard floating point type
</td>
</tr>
<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">R</span></span>
<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/type-traits/is-op">is_op</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
C++20 concept satisfied when a type derives from <span class="doxyComputerOutput">op</span>
</td>
</tr>
<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<span class="doxyTreeIconBox"><span class="doxyTreeIcon">R</span></span>
<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/type-traits/printable">printable</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
C++20 concept satisfied when a type can be appended to the deferred reporter's output via <span class="doxyComputerOutput">operator&lt;&lt;</span>
</td>
</tr>

</table>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.0 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
