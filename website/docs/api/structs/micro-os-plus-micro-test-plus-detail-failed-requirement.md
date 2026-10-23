---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/structs/micro-os-plus/micro-test-plus/detail/failed-requirement
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - struct

---

<div class="doxyPage">

# `failed_requirement` Struct

<p>The exception thrown to stop a test case after a failed <span class="doxyComputerOutput">require()</span>. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
struct micro_os_plus::micro_test_plus::detail::failed_requirement { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include &lt;<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h">check-result.h</a>&gt;
</div>

## Description {#details}

<p>The exception thrown to stop a test case after a failed <span class="doxyComputerOutput">require()</span>.</p>


<p>Thrown by the destructor of <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">check_result</a></span>, after the failure was reported and counted, when exceptions are enabled, and caught by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#adb4333ecb107fee477156b661f0b1512">test_case::run()</a></span>, which ends the test case normally; the run continues with the next test case.</p>


<p>It is deliberately not derived from <span class="doxyComputerOutput">std::exception</span>, so that a <span class="doxyComputerOutput">catch (const std::exception&amp;)</span> in the test case body does not stop it; a <span class="doxyComputerOutput">catch (...)</span> does, and should rethrow it.</p>


<p>Definition at line 99 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h">check-result.h</a>.</p>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
