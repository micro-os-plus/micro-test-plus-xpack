---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/files/include/micro-os-plus/micro-test-plus/deferred-reporter-h
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - file

---

<div class="doxyPage">

# `deferred-reporter.h` File

<p>C++ header file with declarations for the µTest++ deferred reporter. <a href="#details">More...</a></p>

## Included Headers

<div class="doxyIncludesList">#include &lt;cstdio&gt;
#include &lt;string&gt;
#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/type-traits-h">type-traits.h</a>"
#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reflection-h">reflection.h</a>"
#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>"
#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/deferred-reporter-inlines-h">inlines/deferred-reporter-inlines.h</a>"
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

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">namespace</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail">detail</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Internal implementation details for the µTest++ framework. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Classes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter">deferred_reporter</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deferred reporter class for a specific expression. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base">deferred_reporter_base</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Base class for a deferred reporter that collects messages into a string. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>C++ header file with declarations for the µTest++ deferred reporter.</p>


<p>This header provides the two deferred-reporter classes used by <span class="doxyComputerOutput">expect()</span> and <span class="doxyComputerOutput">assume()</span> to capture a test-expression result and format the outcome only when the reporter object is destroyed (i.e. at the semicolon following the expression statement).</p>


<ul class="doxyList ">
<li><span class="doxyComputerOutput">deferred_reporter_base</span> stores the boolean result, the source location, an optional user-supplied message (accumulated via <span class="doxyComputerOutput">operator&lt;&lt;</span>), and a reference to the owning <span class="doxyComputerOutput">subtest</span>. Its destructor calls the reporter to emit a pass or fail line.</li>
<li><span class="doxyComputerOutput">deferred_reporter&lt;Expr_T&gt;</span> derives from the base and additionally stores the original expression object so that the reporter can print the actual and expected values on failure.</li>
</ul>

<p>Both classes live in the <span class="doxyComputerOutput">detail</span> namespace and are not part of the public API.</p>


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
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00042"></a>42</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00043"></a>43</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#ifndef MICRO_TEST_PLUS_DEFERRED_REPORTER_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00044"></a>44</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#define MICRO_TEST_PLUS_DEFERRED_REPORTER_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00045"></a>45</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00046"></a>46</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00047"></a>47</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00048"></a>48</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#ifdef __cplusplus</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00049"></a>49</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00050"></a>50</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00051"></a>51</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00052"></a>52</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;cstdio&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00053"></a>53</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;string&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00054"></a>54</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00055"></a>55</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/type-traits-h">type-traits.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00056"></a>56</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reflection-h">reflection.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00057"></a>57</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00058"></a>58</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00059"></a>59</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00060"></a>60</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00061"></a>61</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00062"></a>62</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00063"></a>63</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Wpadded"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00064"></a>64</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Waggregate-return"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00065"></a>65</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00066"></a>66</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wc++98-compat"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00067"></a>67</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00068"></a>68</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00069"></a>69</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00070"></a>70</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ============================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00071"></a>71</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00072"></a>72</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00073"></a>73</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00074"></a>74</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest">subtest</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00075"></a>75</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00076"></a>76</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00077"></a>77</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00078"></a><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail">78</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail">detail</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00079"></a>79</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00080"></a>80</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ========================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00081"></a>81</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00100"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base">100</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#abd34896d8d956db7223829bcbf9efb04">deferred_reporter_base</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00101"></a>101</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00102"></a>102</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00110"></a>110</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#abd34896d8d956db7223829bcbf9efb04">deferred_reporter_base</a> (</span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a0c0b059add8cbddb96e8f2fef8cba431">value</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00111"></a>111</span><span class="doxyLineContent"><span class="doxyHighlight">                              </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; location,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00112"></a>112</span><span class="doxyLineContent"><span class="doxyHighlight">                              <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest">subtest</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest">subtest</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00113"></a>113</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00117"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a6d40968632c7f86a73a8faf7c989d11e">117</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a6d40968632c7f86a73a8faf7c989d11e">deferred_reporter_base</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#abd34896d8d956db7223829bcbf9efb04">deferred_reporter_base</a>&amp;) = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00118"></a>118</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00122"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a114a6eeab81ca53c0428244882b5af8a">122</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a114a6eeab81ca53c0428244882b5af8a">deferred_reporter_base</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#abd34896d8d956db7223829bcbf9efb04">deferred_reporter_base</a>&amp;&amp;) = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00123"></a>123</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00127"></a>127</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#abd34896d8d956db7223829bcbf9efb04">deferred_reporter_base</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00128"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#aef0485fd5cb77a9c6b171c04e597bdbf">128</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#aef0485fd5cb77a9c6b171c04e597bdbf">operator=</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#abd34896d8d956db7223829bcbf9efb04">deferred_reporter_base</a>&amp;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00129"></a>129</span><span class="doxyLineContent"><span class="doxyHighlight">          = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00130"></a>130</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00134"></a>134</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#abd34896d8d956db7223829bcbf9efb04">deferred_reporter_base</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00135"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a08910483a88514bd3fc05eb63a5043b6">135</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#aef0485fd5cb77a9c6b171c04e597bdbf">operator=</a>(<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#abd34896d8d956db7223829bcbf9efb04">deferred_reporter_base</a>&amp;&amp;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00136"></a>136</span><span class="doxyLineContent"><span class="doxyHighlight">          = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00137"></a>137</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00141"></a>141</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a3a8503e793c807cbb882033cc5ff2831">~deferred_reporter_base</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00142"></a>142</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00151"></a>151</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00152"></a>152</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/type-traits/printable">type_traits::printable&lt;T&gt;</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00153"></a>153</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00154"></a>154</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a25895cdf53098c97033b5c476cdd7702">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; msg);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00155"></a>155</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00164"></a>164</span><span class="doxyLineContent"><span class="doxyHighlight">      [[nodiscard]] </span><span class="doxyHighlightKeywordType">bool</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00165"></a>165</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a0c0b059add8cbddb96e8f2fef8cba431">value</a> () </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00166"></a>166</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00167"></a>167</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">protected</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00171"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#af633053afa944173b47482786f9d9a7e">171</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#af633053afa944173b47482786f9d9a7e">value_</a>{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00172"></a>172</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00177"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#aa36fd4c36a94b04430599303e38a48bd">177</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#aa36fd4c36a94b04430599303e38a48bd">abort_</a> = </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00178"></a>178</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00182"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#aa22fa7a9c9f3f456d971728083dbcc6e">182</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#aa22fa7a9c9f3f456d971728083dbcc6e">has_expression_</a> = </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00183"></a>183</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00187"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a025498d9b9376056c56042cc98ed7afd">187</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a025498d9b9376056c56042cc98ed7afd">location_</a>{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00188"></a>188</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00193"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a0d4853e08c3106a270e951e56d876840">193</a></span><span class="doxyLineContent"><span class="doxyHighlight">      std::string <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a0d4853e08c3106a270e951e56d876840">deferred_output_</a>{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00194"></a>194</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00198"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#aae23103bf1232549780c69911239b781">198</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest">subtest</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#aae23103bf1232549780c69911239b781">subtest_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00199"></a>199</span><span class="doxyLineContent"><span class="doxyHighlight">    };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00200"></a>200</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00201"></a>201</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ========================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00202"></a>202</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00219"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter">219</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter/#a0d6bc295723916664b22f60d783b85b0">deferred_reporter</a> : </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#abd34896d8d956db7223829bcbf9efb04">deferred_reporter_base</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00220"></a>220</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00221"></a>221</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00233"></a>233</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Expr_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00234"></a>234</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter/#a0d6bc295723916664b22f60d783b85b0">deferred_reporter</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Expr_T&amp; expr, </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> abort,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00235"></a>235</span><span class="doxyLineContent"><span class="doxyHighlight">                         </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; location,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00236"></a>236</span><span class="doxyLineContent"><span class="doxyHighlight">                         <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest">subtest</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest">subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter">expression_formatter</a>&amp; expression);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00237"></a>237</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00241"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter/#a39821d33f3f3aa41b3df6f461258afb3">241</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter/#a39821d33f3f3aa41b3df6f461258afb3">~deferred_reporter</a> () = </span><span class="doxyHighlightKeywordFlow">default</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00242"></a>242</span><span class="doxyLineContent"><span class="doxyHighlight">    };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00243"></a>243</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00244"></a>244</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00245"></a>245</span><span class="doxyLineContent"><span class="doxyHighlight">  } </span><span class="doxyHighlightComment">// namespace detail</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00246"></a>246</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00247"></a>247</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00248"></a>248</span><span class="doxyLineContent"><span class="doxyHighlight">} </span><span class="doxyHighlightComment">// namespace micro_os_plus::micro_test_plus</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00249"></a>249</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00250"></a>250</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00251"></a>251</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00252"></a>252</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00253"></a>253</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00254"></a>254</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00255"></a>255</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00256"></a>256</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// __cplusplus</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00257"></a>257</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00258"></a>258</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ============================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00259"></a>259</span><span class="doxyLineContent"><span class="doxyHighlightComment">// Templates &amp; constexpr implementations.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00260"></a>260</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00261"></a>261</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/deferred-reporter-inlines-h">inlines/deferred-reporter-inlines.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00262"></a>262</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00263"></a>263</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00264"></a>264</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00265"></a>265</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_TEST_PLUS_DEFERRED_REPORTER_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00266"></a>266</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00267"></a>267</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.0 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
