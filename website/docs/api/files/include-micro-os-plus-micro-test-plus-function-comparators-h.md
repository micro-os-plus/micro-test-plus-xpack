---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/files/include/micro-os-plus/micro-test-plus/function-comparators-h
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - file

---

<div class="doxyPage">

# `function-comparators.h` File

<p>C++ header file with declarations for the µTest++ function comparators. <a href="#details">More...</a></p>

## Included Headers

<div class="doxyIncludesList">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>"
#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/function-comparators-inlines-h">inlines/function-comparators-inlines.h</a>"
</div>

## Namespaces Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">namespace</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus">micro_os_plus</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The primary namespace for the µOS++ framework. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">namespace</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_test_plus</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Primary namespace for the µTest++ testing framework. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T, class Epsilon_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-function-comparators/#gacae776e46a799b81af859ba9bb74e7d0">approx</a> (Lhs_T &amp;&amp;lhs, Rhs_T &amp;&amp;rhs, Epsilon_T &amp;&amp;epsilon)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Approximate equality comparator, with an explicit tolerance. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-function-comparators/#gacae776e46a799b81af859ba9bb74e7d0">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-logical-functions/#ga8c9c770da2ef632dec29c502651cb160">both</a> (Lhs_T &amp;&amp;lhs, Rhs_T &amp;&amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Generic logical <b>and</b> operation. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-logical-functions/#ga8c9c770da2ef632dec29c502651cb160">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-logical-functions/#gab9fbb94dec947fa60052531743114fa9">either</a> (Lhs_T &amp;&amp;lhs, Rhs_T &amp;&amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Generic logical (inclusive) <b>or</b> operation. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-logical-functions/#gab9fbb94dec947fa60052531743114fa9">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-function-comparators/#gaa7c7b6a7ad32856edc235a05e77d8c7f">eq</a> (Lhs_T &amp;&amp;lhs, Rhs_T &amp;&amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Generic equality comparator. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-function-comparators/#gaa7c7b6a7ad32856edc235a05e77d8c7f">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-function-comparators/#gab8da4228bc9a820546753b018a129a7e">ge</a> (Lhs_T &amp;&amp;lhs, Rhs_T &amp;&amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Generic greater than or equal comparator. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-function-comparators/#gab8da4228bc9a820546753b018a129a7e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-function-comparators/#ga9ae8e4747ff029faa7378110c8680278">gt</a> (Lhs_T &amp;&amp;lhs, Rhs_T &amp;&amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Generic greater than comparator. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-function-comparators/#ga9ae8e4747ff029faa7378110c8680278">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-function-comparators/#gae695dd46840f76a156aee70ff4df33fa">le</a> (Lhs_T &amp;&amp;lhs, Rhs_T &amp;&amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Generic less than or equal comparator. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-function-comparators/#gae695dd46840f76a156aee70ff4df33fa">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-function-comparators/#ga714ff07cd77e05898de4fd315770f901">lt</a> (Lhs_T &amp;&amp;lhs, Rhs_T &amp;&amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Generic less than comparator. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-function-comparators/#ga714ff07cd77e05898de4fd315770f901">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-function-comparators/#ga5bf176ef730172592095657417e5f039">ne</a> (Lhs_T &amp;&amp;lhs, Rhs_T &amp;&amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Generic non-equality comparator. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-function-comparators/#ga5bf176ef730172592095657417e5f039">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Expr_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-logical-functions/#ga6a0bb2654eb89c1b0a35134e8738eeb1">negate</a> (Expr_T &amp;&amp;expr)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Generic logical <b>not</b> operation. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-logical-functions/#ga6a0bb2654eb89c1b0a35134e8738eeb1">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>C++ header file with declarations for the µTest++ function comparators.</p>


<p>This header provides the declarations for the function comparator templates and logical operators used within the µTest++ framework. It defines the interfaces for the generic comparison functions, including equality, non-equality, greater than, less than, greater than or equal, and less than or equal, and the approximate comparison with an explicit tolerance (<span class="doxyComputerOutput">approx</span>). Additionally, it declares logical combinators such as conjunction (<span class="doxyComputerOutput">both</span>), disjunction (<span class="doxyComputerOutput">either</span>), and negation (<span class="doxyComputerOutput">negate</span>); their deprecated v5.0.1 names are declared in <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deprecated-h">deprecated.h</a></span>.</p>


<p>These comparators and logical operators enable expressive and type-safe test expectations and assertions. The C strings (<span class="doxyComputerOutput">char</span> arrays, including the string literals, and <span class="doxyComputerOutput">char</span> pointers) are compared by content; the other pointers and arrays are compared by address. The operands are not copied: the temporaries are moved into the returned expressions, and the named operands of class type are referred to, so the expressions must be checked before the named operands are destroyed, as they are in <span class="doxyComputerOutput">expect (eq (a, b))</span>. The logical combinators have descriptive names, since <span class="doxyComputerOutput">and</span>, <span class="doxyComputerOutput">or</span>, and <span class="doxyComputerOutput">not</span> are alternative tokens and cannot be used as identifiers.</p>


<p>All definitions reside within the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a></span> namespace, ensuring clear separation from user code and minimising the risk of naming conflicts.</p>


<p>The header files are organised within the <span class="doxyComputerOutput">include/micro-os-plus/micro-test-plus</span> folder to maintain a structured and modular codebase.</p>


<p>This file is intended solely for internal use within the framework and should not be included directly by user code.</p>


## File Listing

The file content with the documentation metadata removed is:

<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00001"></a>1</span><span class="doxyLineContent"><span class="doxyHighlightComment">/*</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00002"></a>2</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * This file is part of the µOS++ project (https://micro-os-plus.github.io/).</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00003"></a>3</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * Copyright (c) 2021-2026 Liviu Ionescu. All rights reserved.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00004"></a>4</span><span class="doxyLineContent"><span class="doxyHighlightComment"> *</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00005"></a>5</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * Permission to use, copy, modify, and/or distribute this software for any</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00006"></a>6</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * purpose is hereby granted, under the terms of the MIT license.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00007"></a>7</span><span class="doxyLineContent"><span class="doxyHighlightComment"> *</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00008"></a>8</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * If a copy of the license was not distributed with this file, it can be</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00009"></a>9</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * obtained from https://opensource.org/licenses/mit.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00010"></a>10</span><span class="doxyLineContent"><span class="doxyHighlightComment"> *</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00011"></a>11</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * Major parts of the code are inspired from v1.1.8 of the Boost UT project,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00012"></a>12</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * released under the terms of the Boost Version 1 Software License,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00013"></a>13</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * which can be obtained from https://www.boost.org/LICENSE_1_0.txt.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00014"></a>14</span><span class="doxyLineContent"><span class="doxyHighlightComment"> */</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00015"></a>15</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00016"></a>16</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00017"></a>17</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00056"></a>56</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00057"></a>57</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_FUNCTION_COMPARATORS_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00058"></a>58</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#define MICRO_OS_PLUS_MICRO_TEST_PLUS_FUNCTION_COMPARATORS_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00059"></a>59</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00060"></a>60</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00061"></a>61</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00062"></a>62</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__cplusplus)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00063"></a>63</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00064"></a>64</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00065"></a>65</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00066"></a>66</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if __has_include("micro-os-plus/project-config.h")</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00067"></a>67</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "micro-os-plus/project-config.h"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00068"></a>68</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// __has_include("micro-os-plus/project-config.h")</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00069"></a>69</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00070"></a>70</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if __has_include("micro-os-plus/micro-test-plus-defines.h")</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00071"></a>71</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "micro-os-plus/micro-test-plus-defines.h"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00072"></a>72</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// __has_include("micro-os-plus/micro-test-plus-defines.h")</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00073"></a>73</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00074"></a>74</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00075"></a>75</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00076"></a>76</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00077"></a>77</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00078"></a>78</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00079"></a>79</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00080"></a>80</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00081"></a>81</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Wpadded"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00082"></a>82</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Waggregate-return"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00083"></a>83</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00084"></a>84</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wc++98-compat"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00085"></a>85</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wpre-c++17-compat"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00086"></a>86</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wunknown-warning-option"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00087"></a>87</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00088"></a>88</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00089"></a>89</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00090"></a>90</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ===========================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00091"></a>91</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00092"></a>92</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00093"></a>93</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00094"></a>94</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00095"></a>95</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00120"></a>120</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Lhs_T, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Rhs_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00121"></a>121</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/printable">extension::printable&lt;Lhs_T&gt;</a> and <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/printable">extension::printable&lt;Rhs_T&gt;</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00122"></a>122</span><span class="doxyLineContent"><span class="doxyHighlight">  [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00123"></a>123</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-function-comparators/#gaa7c7b6a7ad32856edc235a05e77d8c7f">eq</a> (Lhs_T&amp;&amp; lhs, Rhs_T&amp;&amp; rhs);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00124"></a>124</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00136"></a>136</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Lhs_T, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Rhs_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00137"></a>137</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/printable">extension::printable&lt;Lhs_T&gt;</a> and <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/printable">extension::printable&lt;Rhs_T&gt;</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00138"></a>138</span><span class="doxyLineContent"><span class="doxyHighlight">  [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00139"></a>139</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-function-comparators/#ga5bf176ef730172592095657417e5f039">ne</a> (Lhs_T&amp;&amp; lhs, Rhs_T&amp;&amp; rhs);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00140"></a>140</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00152"></a>152</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Lhs_T, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Rhs_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00153"></a>153</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/printable">extension::printable&lt;Lhs_T&gt;</a> and <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/printable">extension::printable&lt;Rhs_T&gt;</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00154"></a>154</span><span class="doxyLineContent"><span class="doxyHighlight">  [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00155"></a>155</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-function-comparators/#ga9ae8e4747ff029faa7378110c8680278">gt</a> (Lhs_T&amp;&amp; lhs, Rhs_T&amp;&amp; rhs);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00156"></a>156</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00169"></a>169</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Lhs_T, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Rhs_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00170"></a>170</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/printable">extension::printable&lt;Lhs_T&gt;</a> and <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/printable">extension::printable&lt;Rhs_T&gt;</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00171"></a>171</span><span class="doxyLineContent"><span class="doxyHighlight">  [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00172"></a>172</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-function-comparators/#gab8da4228bc9a820546753b018a129a7e">ge</a> (Lhs_T&amp;&amp; lhs, Rhs_T&amp;&amp; rhs);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00173"></a>173</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00186"></a>186</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Lhs_T, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Rhs_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00187"></a>187</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/printable">extension::printable&lt;Lhs_T&gt;</a> and <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/printable">extension::printable&lt;Rhs_T&gt;</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00188"></a>188</span><span class="doxyLineContent"><span class="doxyHighlight">  [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00189"></a>189</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-function-comparators/#ga714ff07cd77e05898de4fd315770f901">lt</a> (Lhs_T&amp;&amp; lhs, Rhs_T&amp;&amp; rhs);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00190"></a>190</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00203"></a>203</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Lhs_T, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Rhs_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00204"></a>204</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/printable">extension::printable&lt;Lhs_T&gt;</a> and <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/printable">extension::printable&lt;Rhs_T&gt;</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00205"></a>205</span><span class="doxyLineContent"><span class="doxyHighlight">  [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00206"></a>206</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-function-comparators/#gae695dd46840f76a156aee70ff4df33fa">le</a> (Lhs_T&amp;&amp; lhs, Rhs_T&amp;&amp; rhs);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00207"></a>207</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00243"></a>243</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Lhs_T, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Rhs_T, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Epsilon_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00244"></a>244</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/approx-operand">detail::approx_operand&lt;Lhs_T&gt;</a> and <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/approx-operand">detail::approx_operand&lt;Rhs_T&gt;</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00245"></a>245</span><span class="doxyLineContent"><span class="doxyHighlight">              and <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/approx-operand">detail::approx_operand&lt;Epsilon_T&gt;</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00246"></a>246</span><span class="doxyLineContent"><span class="doxyHighlight">  [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00247"></a>247</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-function-comparators/#gacae776e46a799b81af859ba9bb74e7d0">approx</a> (Lhs_T&amp;&amp; lhs, Rhs_T&amp;&amp; rhs, Epsilon_T&amp;&amp; epsilon);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00248"></a>248</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00258"></a>258</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Expr_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00259"></a>259</span><span class="doxyLineContent"><span class="doxyHighlight">  [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00260"></a>260</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-logical-functions/#ga6a0bb2654eb89c1b0a35134e8738eeb1">negate</a> (Expr_T&amp;&amp; expr);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00261"></a>261</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00274"></a>274</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Lhs_T, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Rhs_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00275"></a>275</span><span class="doxyLineContent"><span class="doxyHighlight">  [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00276"></a>276</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-logical-functions/#ga8c9c770da2ef632dec29c502651cb160">both</a> (Lhs_T&amp;&amp; lhs, Rhs_T&amp;&amp; rhs);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00277"></a>277</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00290"></a>290</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Lhs_T, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Rhs_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00291"></a>291</span><span class="doxyLineContent"><span class="doxyHighlight">  [[nodiscard]] </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00292"></a>292</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-logical-functions/#gab9fbb94dec947fa60052531743114fa9">either</a> (Lhs_T&amp;&amp; lhs, Rhs_T&amp;&amp; rhs);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00293"></a>293</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00294"></a>294</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00295"></a>295</span><span class="doxyLineContent"><span class="doxyHighlight">} </span><span class="doxyHighlightComment">// namespace micro_os_plus::micro_test_plus</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00296"></a>296</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00297"></a>297</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00298"></a>298</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00299"></a>299</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00300"></a>300</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00301"></a>301</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00302"></a>302</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00303"></a>303</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__cplusplus)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00304"></a>304</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00305"></a>305</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ============================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00306"></a>306</span><span class="doxyLineContent"><span class="doxyHighlightComment">// Templates, inlines &amp; constexpr implementations.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00307"></a>307</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00308"></a>308</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/function-comparators-inlines-h">inlines/function-comparators-inlines.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00309"></a>309</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00310"></a>310</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00311"></a>311</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00312"></a>312</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_FUNCTION_COMPARATORS_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00313"></a>313</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00314"></a>314</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
