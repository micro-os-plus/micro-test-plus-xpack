---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/files/include/micro-os-plus/micro-test-plus/timings-h
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - file

---

<div class="doxyPage">

# `timings.h` File

<p>C++ header file with declarations for the µTest++ timing utilities. <a href="#details">More...</a></p>

## Included Headers

<div class="doxyIncludesList">#include &lt;cstdint&gt;
#include &lt;optional&gt;
#include &lt;ctime&gt;
#include "<a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/timings-inlines-h">inlines/timings-inlines.h</a>"
</div>

## Namespaces Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">namespace</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack-webpreview/docs/api/namespaces/micro-os-plus">micro_os_plus</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The primary namespace for the µOS++ framework. <a href="/micro-test-plus-xpack-webpreview/docs/api/namespaces/micro-os-plus/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">namespace</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack-webpreview/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_test_plus</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Primary namespace for the µTest++ testing framework. <a href="/micro-test-plus-xpack-webpreview/docs/api/namespaces/micro-os-plus/micro-test-plus/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">namespace</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack-webpreview/docs/api/namespaces/micro-os-plus/micro-test-plus/detail">detail</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Internal implementation details for the µTest++ framework. <a href="/micro-test-plus-xpack-webpreview/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#details">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp">timestamp</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>A single point-in-time measurement, wrapping a <span class="doxyComputerOutput">timespec</span> value. <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps">timestamps</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>A begin/end timestamp pair used to measure elapsed time. <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>C++ header file with declarations for the µTest++ timing utilities.</p>


<p>This header provides two lightweight classes used to measure the elapsed time of test suites and test sessions within the µTest++ framework:</p>


<ul class="doxyList ">
<li><span class="doxyComputerOutput">timestamp</span> wraps a single <span class="doxyComputerOutput">timespec</span> value and records one point in time. It is default-constructible and trivially copyable.</li>
<li><span class="doxyComputerOutput">timestamps</span> pairs a begin and an end <span class="doxyComputerOutput">timestamp</span> (both stored as <span class="doxyComputerOutput">std::optional&lt;timestamp&gt;</span>) and exposes methods for recording the start and finish of an operation, querying whether both timestamps are available, and computing the elapsed time in milliseconds and microseconds.</li>
</ul>

<p>Timing support relies on <span class="doxyComputerOutput">clock_gettime(CLOCK_MONOTONIC_RAW, ...)</span> when available; if the clock is not present (e.g. on bare-metal targets without an RTC) the timestamps are simply omitted and no timing information is reported.</p>


<p>All definitions reside within the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack-webpreview/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a></span> namespace, ensuring clear separation from user code and minimising the risk of naming conflicts.</p>


<p>This file is intended solely for internal use within the framework and should not be included directly by user code.</p>


## File Listing

The file content with the documentation metadata removed is:

<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00001"></a>1</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00002"></a>2</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00003"></a>3</span><span class="doxyLineContent"><span class="doxyHighlightComment">/*</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00004"></a>4</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * This file is part of the µOS++ project (https://micro-os-plus.github.io/).</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00005"></a>5</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * Copyright (c) 2021-2026 Liviu Ionescu. All rights reserved.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00006"></a>6</span><span class="doxyLineContent"><span class="doxyHighlightComment"> *</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00007"></a>7</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * Permission to use, copy, modify, and/or distribute this software for any</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00008"></a>8</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * purpose is hereby granted, under the terms of the MIT license.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00009"></a>9</span><span class="doxyLineContent"><span class="doxyHighlightComment"> *</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00010"></a>10</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * If a copy of the license was not distributed with this file, it can be</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00011"></a>11</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * obtained from https://opensource.org/licenses/mit.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00012"></a>12</span><span class="doxyLineContent"><span class="doxyHighlightComment"> */</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00013"></a>13</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00014"></a>14</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00015"></a>15</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00044"></a>44</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00045"></a>45</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#ifndef MICRO_TEST_PLUS_TIMINGS_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00046"></a>46</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#define MICRO_TEST_PLUS_TIMINGS_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00047"></a>47</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00048"></a>48</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00049"></a>49</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00050"></a>50</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#ifdef __cplusplus</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00051"></a>51</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00052"></a>52</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00053"></a>53</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00054"></a>54</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;cstdint&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00055"></a>55</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;optional&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00056"></a>56</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;ctime&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00057"></a>57</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00058"></a>58</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00059"></a>59</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00060"></a>60</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00061"></a>61</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00062"></a>62</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00063"></a>63</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wc++98-compat"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00064"></a>64</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wpre-c++17-compat"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00065"></a>65</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00066"></a>66</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00067"></a>67</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00068"></a>68</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ============================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00069"></a>69</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00070"></a>70</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack-webpreview/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00071"></a>71</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00072"></a>72</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00073"></a>73</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00074"></a>74</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack-webpreview/docs/api/namespaces/micro-os-plus/micro-test-plus/detail">detail</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00075"></a>75</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00076"></a>76</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ========================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00077"></a>77</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00093"></a><a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp">93</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp/#a3021a3477870bda369e22bdf085bf7a7">timestamp</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00094"></a>94</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00095"></a>95</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00099"></a>99</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp/#a3021a3477870bda369e22bdf085bf7a7">timestamp</a> () </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00100"></a>100</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00106"></a>106</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp/#a3021a3477870bda369e22bdf085bf7a7">timestamp</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> timespec&amp; ts) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00107"></a>107</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00108"></a>108</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// `timespec` is trivially copyable, so copy and move are safe to</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00109"></a>109</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// default. Defaulting these operations allows `timestamp` to be used in</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00110"></a>110</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// contexts that require copyability or movability (e.g. containers,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00111"></a>111</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// algorithms).</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00115"></a><a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp/#a25cc87189f5ec1dbdef3302de6408d62">115</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp/#a25cc87189f5ec1dbdef3302de6408d62">timestamp</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp/#a3021a3477870bda369e22bdf085bf7a7">timestamp</a>&amp;) = </span><span class="doxyHighlightKeywordFlow">default</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00116"></a>116</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00120"></a><a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp/#a78ec32dd29a858de635f6be2a4fd3f8f">120</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp/#a78ec32dd29a858de635f6be2a4fd3f8f">timestamp</a> (<a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp/#a3021a3477870bda369e22bdf085bf7a7">timestamp</a>&amp;&amp;) = </span><span class="doxyHighlightKeywordFlow">default</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00121"></a>121</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00125"></a>125</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp/#a3021a3477870bda369e22bdf085bf7a7">timestamp</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00126"></a><a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp/#a91c4b65a10407ab3c2a65343b924902b">126</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp/#a91c4b65a10407ab3c2a65343b924902b">operator=</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp/#a3021a3477870bda369e22bdf085bf7a7">timestamp</a>&amp;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00127"></a>127</span><span class="doxyLineContent"><span class="doxyHighlight">          = </span><span class="doxyHighlightKeywordFlow">default</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00128"></a>128</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00132"></a>132</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp/#a3021a3477870bda369e22bdf085bf7a7">timestamp</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00133"></a><a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp/#a790a0f4322a690f7ab6591ada80222a0">133</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp/#a91c4b65a10407ab3c2a65343b924902b">operator=</a>(<a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp/#a3021a3477870bda369e22bdf085bf7a7">timestamp</a>&amp;&amp;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00134"></a>134</span><span class="doxyLineContent"><span class="doxyHighlight">          = </span><span class="doxyHighlightKeywordFlow">default</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00135"></a>135</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00139"></a><a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp/#a1edc35b9931f3fdb714daf9cae3da73e">139</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp/#a1edc35b9931f3fdb714daf9cae3da73e">~timestamp</a> () = </span><span class="doxyHighlightKeywordFlow">default</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00140"></a>140</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00149"></a>149</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">bool</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00150"></a>150</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp/#ae5494fb57bcc3b577c914a0cc95ff667">has_clock</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00151"></a>151</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00159"></a>159</span><span class="doxyLineContent"><span class="doxyHighlight">      [[nodiscard]] timespec&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00160"></a>160</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp/#a3d67310c280413bdd857d975daa84eac">value</a> () noexcept;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00161"></a>161</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00169"></a>169</span><span class="doxyLineContent"><span class="doxyHighlight">      [[nodiscard]] const timespec&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00170"></a>170</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp/#a3d67310c280413bdd857d975daa84eac">value</a> () const noexcept;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00171"></a>171</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00172"></a>172</span><span class="doxyLineContent"><span class="doxyHighlight">    protected:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00176"></a><a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp/#a62c9539975cee7a03be62eb0a903bbf3">176</a></span><span class="doxyLineContent"><span class="doxyHighlight">      timespec <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp/#a62c9539975cee7a03be62eb0a903bbf3">value_</a>{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00177"></a>177</span><span class="doxyLineContent"><span class="doxyHighlight">    };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00178"></a>178</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00179"></a>179</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ========================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00180"></a>180</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00204"></a><a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps">204</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#a28411e9d980b53accf2a8c5221a1861f">timestamps</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00205"></a>205</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00206"></a>206</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00210"></a><a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#a28411e9d980b53accf2a8c5221a1861f">210</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#a28411e9d980b53accf2a8c5221a1861f">timestamps</a> () = </span><span class="doxyHighlightKeywordFlow">default</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00211"></a>211</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00215"></a><a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#ad9bb8bdb44def63c7ace6e25efa6150e">215</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#ad9bb8bdb44def63c7ace6e25efa6150e">timestamps</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#a28411e9d980b53accf2a8c5221a1861f">timestamps</a>&amp;) = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00216"></a>216</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00220"></a><a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#aed7caa5ea1c202dd12403ae9a5b38167">220</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#aed7caa5ea1c202dd12403ae9a5b38167">timestamps</a> (<a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#a28411e9d980b53accf2a8c5221a1861f">timestamps</a>&amp;&amp;) = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00221"></a>221</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00225"></a>225</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#a28411e9d980b53accf2a8c5221a1861f">timestamps</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00226"></a><a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#aa003cc61308004bc8e22ce2097e4564b">226</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#aa003cc61308004bc8e22ce2097e4564b">operator=</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#a28411e9d980b53accf2a8c5221a1861f">timestamps</a>&amp;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00227"></a>227</span><span class="doxyLineContent"><span class="doxyHighlight">          = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00228"></a>228</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00232"></a>232</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#a28411e9d980b53accf2a8c5221a1861f">timestamps</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00233"></a><a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#afe37704a6659bbaeb5a21372b5b53b60">233</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#aa003cc61308004bc8e22ce2097e4564b">operator=</a>(<a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#a28411e9d980b53accf2a8c5221a1861f">timestamps</a>&amp;&amp;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00234"></a>234</span><span class="doxyLineContent"><span class="doxyHighlight">          = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00235"></a>235</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00239"></a><a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#a29791422e99ae1b77c0d0cefa97bbd88">239</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#a29791422e99ae1b77c0d0cefa97bbd88">~timestamps</a> () = </span><span class="doxyHighlightKeywordFlow">default</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00240"></a>240</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00249"></a>249</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00250"></a>250</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#a1b2077718469ade9fda2e257a0d06293">timestamp_begin</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00251"></a>251</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00259"></a>259</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00260"></a>260</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#a1b2077718469ade9fda2e257a0d06293">timestamp_begin</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> timespec&amp; ts) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00261"></a>261</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00270"></a>270</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00271"></a>271</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#aeb4873587b5be066c69c0ef26d64640b">timestamp_end</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00272"></a>272</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00280"></a>280</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00281"></a>281</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#aeb4873587b5be066c69c0ef26d64640b">timestamp_end</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> timespec&amp; ts) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00282"></a>282</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00291"></a>291</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">bool</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00292"></a>292</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#aa0947e2e891064a6b0c36e55dcfc900b">has_begin</a> () const noexcept;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00293"></a>293</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00302"></a>302</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">bool</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00303"></a>303</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#a66eaffb91df2a7b6b70b8c8005791954">has_end</a> () const noexcept;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00304"></a>304</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00315"></a>315</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">bool</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00316"></a>316</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#a125c87d852257c18749074be3b698ed1">has_timestamps</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) const noexcept;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00317"></a>317</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00325"></a>325</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00326"></a>326</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#a7e7ade6bb02af23d65e5ceaa958052dd">compute_elapsed_time</a> (uint32_t&amp; milliseconds,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00327"></a>327</span><span class="doxyLineContent"><span class="doxyHighlight">                            uint32_t&amp; microseconds) const;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00328"></a>328</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00329"></a>329</span><span class="doxyLineContent"><span class="doxyHighlight">    protected:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00333"></a><a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#ac621973713cc6e574f7aa70566a4e960">333</a></span><span class="doxyLineContent"><span class="doxyHighlight">      std::optional&lt;<a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp">timestamp</a>&gt; <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#ac621973713cc6e574f7aa70566a4e960">begin_time_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00334"></a>334</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00338"></a><a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#a85749791b2161ff48e9a1de82c532017">338</a></span><span class="doxyLineContent"><span class="doxyHighlight">      std::optional&lt;<a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamp">timestamp</a>&gt; <a href="/micro-test-plus-xpack-webpreview/docs/api/classes/micro-os-plus/micro-test-plus/detail/timestamps/#a85749791b2161ff48e9a1de82c532017">end_time_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00339"></a>339</span><span class="doxyLineContent"><span class="doxyHighlight">    };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00340"></a>340</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00341"></a>341</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00342"></a>342</span><span class="doxyLineContent"><span class="doxyHighlight">  } </span><span class="doxyHighlightComment">// namespace detail</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00343"></a>343</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// ==========================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00344"></a>344</span><span class="doxyLineContent"><span class="doxyHighlight">} </span><span class="doxyHighlightComment">// namespace micro_os_plus::micro_test_plus</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00345"></a>345</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00346"></a>346</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00347"></a>347</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00348"></a>348</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00349"></a>349</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00350"></a>350</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00351"></a>351</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00352"></a>352</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// __cplusplus</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00353"></a>353</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00354"></a>354</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ============================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00355"></a>355</span><span class="doxyLineContent"><span class="doxyHighlightComment">// Templates, inlines &amp; constexpr implementations.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00356"></a>356</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00357"></a>357</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack-webpreview/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/timings-inlines-h">inlines/timings-inlines.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00358"></a>358</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00359"></a>359</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00360"></a>360</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00361"></a>361</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_TEST_PLUS_TIMINGS_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00362"></a>362</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00363"></a>363</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.1 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
