---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/micro-test-plus/type-traits/printable
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `printable` Concept

<p>C++20 concept satisfied when a type can be appended to the deferred reporter's output via <span class="doxyComputerOutput">operator&lt;&lt;</span>. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;class T&gt;<br/>
concept <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/type-traits/printable">micro_os_plus::micro_test_plus::type_traits::printable</a> =  std::is_arithmetic_v&lt;T&gt;<br/>
                        or std::is_convertible_v&lt;T, std::string_view&gt;    
</div>

## Description {#details}

<p>C++20 concept satisfied when a type can be appended to the deferred reporter's output via <span class="doxyComputerOutput">operator&lt;&lt;</span>.</p>


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

<p>The <span class="doxyComputerOutput">printable</span> concept is satisfied when <span class="doxyComputerOutput">T</span> is an arithmetic type or is implicitly convertible to <span class="doxyComputerOutput">std::string_view</span>. It constrains the <span class="doxyComputerOutput">operator&lt;&lt;</span> overload of <span class="doxyComputerOutput">deferred_reporter_base</span>, ensuring that only types that can be meaningfully appended to the output message are accepted.</p>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.1.0 by <a href="https://www.doxygen.nl">Doxygen</a> 1.15.0.</p>

</div>
