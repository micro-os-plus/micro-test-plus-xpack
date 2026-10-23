---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/structs/micro-os-plus/micro-test-plus/detail/range-element
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - struct

---

<div class="doxyPage">

# `range_element` Struct Template

<p>The type of the elements of a range, as iterated by a range-based <span class="doxyComputerOutput">for</span> statement. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
template &lt;class T&gt;<br/>
struct micro_os_plus::micro_test_plus::detail::range_element&lt;T&gt; { ... }
</div>

## Description {#details}

<p>The type of the elements of a range, as iterated by a range-based <span class="doxyComputerOutput">for</span> statement.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The range type, satisfying <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/container-like">container_like</a></span> or <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/free-range">free_range</a></span>.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Only declared; the partial specialisations define the member <span class="doxyComputerOutput">type</span>, for the two ways of iterating a range. Used by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/formattable-range">formattable_range</a></span>.</p>


<p>Definition at line 324 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/extension-h">extension.h</a>.</p>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
