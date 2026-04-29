---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/micro-test-plus/type-traits/has-epsilon
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `has_epsilon` Concept

<p>C++20 concept satisfied when <span class="doxyComputerOutput">T</span> provides an <span class="doxyComputerOutput">epsilon</span> member. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;class T&gt;<br/>
concept <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/type-traits/has-epsilon">micro_os_plus::micro_test_plus::type_traits::has_epsilon</a> =  requires (const T&amp; t) { t.epsilon; }    
</div>

## Description {#details}

<p>C++20 concept satisfied when <span class="doxyComputerOutput">T</span> provides an <span class="doxyComputerOutput">epsilon</span> member.</p>


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

<p>The <span class="doxyComputerOutput">has_epsilon</span> concept is satisfied when an instance of <span class="doxyComputerOutput">T</span> exposes an <span class="doxyComputerOutput">epsilon</span> member. It is used to detect floating point value-wrapper types such as <span class="doxyComputerOutput">floating_point_constant</span> and the floating point specialisation of <span class="doxyComputerOutput">value&lt;T&gt;</span>, enabling precision-aware comparisons.</p>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.1.0 by <a href="https://www.doxygen.nl">Doxygen</a> 1.15.0.</p>

</div>
