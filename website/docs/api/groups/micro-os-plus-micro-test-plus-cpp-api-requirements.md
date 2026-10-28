---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-os-plus-micro-test-plus-cpp-api-requirements
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# Requirements

<p>Requirements are checks that stop the test case when they fail.</p>

## Description {#details}


<p>When a precondition of the following checks does not hold, the test case cannot continue meaningfully. A failed requirement is reported and counted like a failed expectation, and then the rest of the test case body is skipped; the run continues with the next test case.</p>


<p>This is the behaviour of the fatal assertions of most C++ test frameworks (<span class="doxyComputerOutput">ASSERT_*</span> in GoogleTest, <span class="doxyComputerOutput">REQUIRE()</span> in Catch2 and doctest, <span class="doxyComputerOutput">BOOST_REQUIRE()</span> in Boost.Test). The test case is stopped with an exception; without exceptions, it cannot be stopped alone, so the results of the test case are reported, ending with the failed requirement (followed, with the TAP reporter, by a <span class="doxyComputerOutput">Bail out!</span> line), and the whole test execution is aborted with <span class="doxyComputerOutput">runner::abort()</span>, as Catch2 does; the remaining test cases do not run, and no totals are written.</p>


<p><span class="doxyComputerOutput">assume()</span> is a deprecated alias of <span class="doxyComputerOutput">require()</span>; in JUnit or Hypothesis, an unmet assumption skips the test instead of failing it.</p>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
