---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/structs/micro-os-plus/micro-test-plus/type-traits/requires-
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - struct

---

<div class="doxyPage">

# `requires_` Struct Template

<p>Struct template for SFINAE requirements. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
template &lt;bool&gt;
struct micro_os_plus::micro_test_plus::type_traits::requires_&lt;bool&gt; { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include &lt;<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>&gt;
</div>

## Description {#details}

<p>Struct template for SFINAE requirements.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Cond</td>
<td class="doxyParamItemDescription"><p>The boolean condition to be checked at compile time.</p></td>
</tr>
</table>
</dd>
</dl>

<p>The <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/requires-">requires_</a></span> struct template is a utility for SFINAE (Substitution Failure Is Not An Error) in template metaprogramming. It is typically used to enable or disable template specialisations and function templates based on compile-time boolean conditions.</p>


<p>When the boolean template parameter is <span class="doxyComputerOutput">true</span>, the specialisation provides a nested <span class="doxyComputerOutput">type</span> alias, which can be used in conjunction with <span class="doxyComputerOutput">typename</span> and <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/type-traits/#a1cbbf299a006b4692df250ef2a6fc7c2">requires_t</a></span> to enforce requirements in template declarations.</p>


<p>Definition at line 627 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/type-traits-h">type-traits.h</a>.</p>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 1.1.0 by <a href="https://www.doxygen.nl">Doxygen</a> 1.14.0.</p>

</div>
