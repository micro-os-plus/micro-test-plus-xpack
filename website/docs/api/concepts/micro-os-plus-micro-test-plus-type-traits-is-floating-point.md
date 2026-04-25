---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/micro-test-plus/type-traits/is-floating-point
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `is_floating_point` Concept

<p>C++20 concept satisfied when <span class="doxyComputerOutput">T</span> is a standard floating point type. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;class T&gt;<br/>
concept <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/type-traits/is-floating-point">micro_os_plus::micro_test_plus::type_traits::is_floating_point</a> =  std::is_floating_point_v&lt;T&gt;    
</div>

## Description {#details}

<p>C++20 concept satisfied when <span class="doxyComputerOutput">T</span> is a standard floating point type.</p>


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

<p>The <span class="doxyComputerOutput">is_floating_point</span> concept is satisfied when <span class="doxyComputerOutput">T</span> is one of the standard floating point types (<span class="doxyComputerOutput">float</span>, <span class="doxyComputerOutput">double</span>, or <span class="doxyComputerOutput">long double</span>). It is the primary definition; <span class="doxyComputerOutput">is_floating_point_v</span> is derived from it for use in <span class="doxyComputerOutput">if constexpr</span> and non-concept contexts.</p>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.1.0-pre by <a href="https://www.doxygen.nl">Doxygen</a> 1.14.0.</p>

</div>
