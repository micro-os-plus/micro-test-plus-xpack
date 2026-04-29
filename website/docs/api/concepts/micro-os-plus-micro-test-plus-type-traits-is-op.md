---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/micro-test-plus/type-traits/is-op
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `is_op` Concept

<p>C++20 concept satisfied when a type derives from <span class="doxyComputerOutput">op</span>. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;class T&gt;<br/>
concept <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/type-traits/is-op">micro_os_plus::micro_test_plus::type_traits::is_op</a> =  std::is_base_of_v&lt;<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/op">type_traits::op</a>, T&gt;    
</div>

## Description {#details}

<p>C++20 concept satisfied when a type derives from <span class="doxyComputerOutput">op</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The type to be checked.</p></td>
</tr>
</table>
</dd>
</dl>

<p>The <span class="doxyComputerOutput">is_op</span> concept is satisfied when <span class="doxyComputerOutput">T</span> is derived from the <span class="doxyComputerOutput">type_traits::op</span> base struct. It is the primary definition used throughout the framework; <span class="doxyComputerOutput">is_op_v</span> is derived from it for use in <span class="doxyComputerOutput">if constexpr</span> and boolean contexts.</p>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.1.0 by <a href="https://www.doxygen.nl">Doxygen</a> 1.15.0.</p>

</div>
