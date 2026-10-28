---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/structs/micro-os-plus/micro-test-plus/type-traits/function-traits
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - struct

---

<div class="doxyPage">

# `function_traits` Struct Template

<p>Deprecated traits of the callable objects. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
template &lt;class T&gt;<br/>
struct micro_os_plus::micro_test_plus::type_traits::function_traits&lt;T&gt; { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include &lt;<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deprecated-h">deprecated.h</a>&gt;
</div>

## Description {#details}

<p>Deprecated traits of the callable objects.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The type of the callable object; its <span class="doxyComputerOutput">operator()</span> is inspected.</p></td>
</tr>
</table>
</dd>
</dl>

<p>The primary template applies to the lambdas and to the function objects, and forwards to the specialisation for the type of their <span class="doxyComputerOutput">operator()</span>. The specialisations expose the return type as <span class="doxyComputerOutput">result_type</span>, and the parameter types as <span class="doxyComputerOutput">args</span>, a <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/list">list</a></span>.</p>


<div class="doxyXrefSect">
<dl class="doxyXrefSectList">
<dt class="doxyXrefSectTitle"><a href=/micro-test-plus-xpack/docs/api/pages/deprecated/#_deprecated000101>Deprecated</a></dt>
<dd class="doxyXrefSectDescription">
<p>Not replaced (since 5.1.0).</p>
</dd>
</dl>
</div>

<p>Definition at line 1909 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deprecated-h">deprecated.h</a>.</p>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
