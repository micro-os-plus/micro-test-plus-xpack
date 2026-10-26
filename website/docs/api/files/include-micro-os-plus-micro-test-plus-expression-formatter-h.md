---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - file

---

<div class="doxyPage">

# `expression-formatter.h` File

<p>C++ header file with declarations for the µTest++ expression formatter. <a href="#details">More...</a></p>

## Included Headers

<div class="doxyIncludesList">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>"
#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/extension-h">extension.h</a>"
#include &lt;charconv&gt;
#include &lt;chrono&gt;
#include &lt;cstdio&gt;
#include &lt;optional&gt;
#include &lt;string&gt;
#include &lt;tuple&gt;
#include &lt;type_traits&gt;
#include &lt;utility&gt;
#include &lt;vector&gt;
#include &lt;string_view&gt;
#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">inlines/expression-formatter-inlines.h</a>"
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
<td class="doxyMemberIndexItemType" align="left" valign="top">struct</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Colours used to highlight pass and fail results in test reports. <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter">expression_formatter</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Formats values and expressions into an owned string buffer. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">struct</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/plain-text">plain_text</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Writes values as text, as the messages of the checks are written. <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/plain-text/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Typedefs Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-function-comparators/#gabecc05360d0941067222d827ff8e3f08">expression_formatter</a> = detail::expression_formatter</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Public name of the formatter used to report operand values. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-function-comparators/#gabecc05360d0941067222d827ff8e3f08">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Variables Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">constexpr colours</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a48c790000ed3d766b705c6c5223d8767">colours_none</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Predefined colour set, without escape sequences. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a48c790000ed3d766b705c6c5223d8767">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">constexpr colours</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ad59e204218aa41581652a072be0e8a8a">colours_red_green</a> = ...</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Predefined colour set, with green for pass and red for fail. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ad59e204218aa41581652a072be0e8a8a">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>C++ header file with declarations for the µTest++ expression formatter.</p>


<p>This header provides the <span class="doxyComputerOutput">expression_formatter</span> class, which encapsulates all value-formatting logic used by the µTest++ framework. The class owns a <span class="doxyComputerOutput">std::string</span> buffer and exposes <span class="doxyComputerOutput">operator&lt;&lt;</span> overloads for every standard arithmetic type, character type, string, pointer, container, scoped enumeration, pair, tuple, optional, and framework expression type (see <span class="doxyComputerOutput">extension::is_op</span>).</p>


<p>By consolidating the formatting operators into a single class (using the shared <span class="doxyComputerOutput">detail::append_number()</span> helper for numbers), the <span class="doxyComputerOutput">reporter</span> is relieved of those responsibilities, and <span class="doxyComputerOutput">detail::check_result</span> can pre-format expression text at construction time without requiring <span class="doxyComputerOutput">reporter</span> or <span class="doxyComputerOutput">test_case</span> to be complete at that point.</p>


<p>The formatter shares the colour configuration of the owning <span class="doxyComputerOutput">reporter</span>: comparator expressions are wrapped in pass/fail colour codes, which are empty strings unless the reporter enables colours.</p>


<p>All definitions reside within the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a></span> namespace, ensuring clear separation from user code and minimising the risk of naming conflicts.</p>


<p>This file is intended solely for internal use within the framework and should not be included directly by user code.</p>


<div class="doxySectionDef">

## Variables

### colours\_none {#a48c790000ed3d766b705c6c5223d8767}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">colours micro_os_plus::micro_test_plus::detail::colours_none {}</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel constexpr">constexpr</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Predefined colour set, without escape sequences.</p>


<p>Used by the formatters that write the messages of the checks, which are never coloured; all members are empty strings.</p>


<p>Definition at line <a href="#l00163">163</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a48c790000ed3d766b705c6c5223d8767">163</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">inline</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a> <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a48c790000ed3d766b705c6c5223d8767">colours_none</a>{};</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a5c2acf2640374b8d971193eae264c26c">micro_os_plus::micro_test_plus::detail::expression_formatter::expression_formatter</a>.</p>

</div>
</div>

### colours\_red\_green {#ad59e204218aa41581652a072be0e8a8a}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">colours micro_os_plus::micro_test_plus::detail::colours_red_green</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel constexpr">constexpr</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Predefined colour set, with green for pass and red for fail.</p>

<dl class="doxySectionUser">
<dt>Initialiser</dt>
<dd>
<div class="doxyVerbatim">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;= {
&nbsp;&nbsp;"\033[0m", 
&nbsp;&nbsp;"\033[32m", 
&nbsp;&nbsp;"\033[31m" 
}
</div>
</dd>
</dl>


<p>Assigned by reporters that output to a colour-capable terminal; the members are, in order, the reset, pass, and fail ANSI escape sequences.</p>


<p>Definition at line <a href="#l00150">150</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ad59e204218aa41581652a072be0e8a8a">150</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">inline</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a> <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ad59e204218aa41581652a072be0e8a8a">colours_red_green</a> = {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">151</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightStringLiteral">"\033[0m"</span><span class="doxyHighlight">, </span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">152</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightStringLiteral">"\033[32m"</span><span class="doxyHighlight">, </span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">153</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightStringLiteral">"\033[31m"</span><span class="doxyHighlight"> </span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">154</span><span class="doxyLineContent"><span class="doxyHighlight">    };</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a82221fa355584dbaa75c7e66fbefa6b8">micro_os_plus::micro_test_plus::detail::reporter_human::reporter_human</a>.</p>

</div>
</div>

</div>

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
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00048"></a>48</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00049"></a>49</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_EXPRESSION_FORMATTER_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00050"></a>50</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#define MICRO_OS_PLUS_MICRO_TEST_PLUS_EXPRESSION_FORMATTER_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00051"></a>51</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00052"></a>52</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00053"></a>53</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00054"></a>54</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__cplusplus)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00055"></a>55</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00056"></a>56</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00057"></a>57</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00058"></a>58</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if __has_include("micro-os-plus/project-config.h")</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00059"></a>59</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "micro-os-plus/project-config.h"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00060"></a>60</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// __has_include("micro-os-plus/project-config.h")</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00061"></a>61</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00062"></a>62</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if __has_include("micro-os-plus/micro-test-plus-defines.h")</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00063"></a>63</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "micro-os-plus/micro-test-plus-defines.h"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00064"></a>64</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// __has_include("micro-os-plus/micro-test-plus-defines.h")</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00065"></a>65</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00066"></a>66</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00067"></a>67</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/extension-h">extension.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00068"></a>68</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00069"></a>69</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;charconv&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00070"></a>70</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;chrono&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00071"></a>71</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;cstdio&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00072"></a>72</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;optional&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00073"></a>73</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;string&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00074"></a>74</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;tuple&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00075"></a>75</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;type_traits&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00076"></a>76</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;utility&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00077"></a>77</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;vector&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00078"></a>78</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;string_view&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00079"></a>79</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00080"></a>80</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00081"></a>81</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00082"></a>82</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00083"></a>83</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00084"></a>84</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00085"></a>85</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Wpadded"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00086"></a>86</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Waggregate-return"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00087"></a>87</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00088"></a>88</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wc++98-compat"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00089"></a>89</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00090"></a>90</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00091"></a>91</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00092"></a>92</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00093"></a>93</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ============================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00094"></a>94</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00095"></a>95</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00096"></a>96</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00097"></a>97</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00098"></a>98</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00099"></a>99</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail">detail</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00100"></a>100</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00101"></a>101</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Forward definitions.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00102"></a>102</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">check_result</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00103"></a>103</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">struct </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/plain-text">plain_text</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00104"></a>104</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00105"></a>105</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00106"></a>106</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00133"></a><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">133</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">struct </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00134"></a>134</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00135"></a><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours/#a42937839aa8c23e1c5482582eaf2aeb7">135</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours/#a42937839aa8c23e1c5482582eaf2aeb7">none</a> = </span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight">; </span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00136"></a><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours/#ac3953ba58fbf322bd310c857844d17fe">136</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours/#ac3953ba58fbf322bd310c857844d17fe">pass</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00137"></a>137</span><span class="doxyLineContent"><span class="doxyHighlight">          = </span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight">; </span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00138"></a><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours/#a7cd442bbb5af0f5d53632101d5c2eb0b">138</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours/#a7cd442bbb5af0f5d53632101d5c2eb0b">fail</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00139"></a>139</span><span class="doxyLineContent"><span class="doxyHighlight">          = </span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight">; </span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00140"></a>140</span><span class="doxyLineContent"><span class="doxyHighlight">    };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00141"></a>141</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00150"></a><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ad59e204218aa41581652a072be0e8a8a">150</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">inline</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a> <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ad59e204218aa41581652a072be0e8a8a">colours_red_green</a> = {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00151"></a>151</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightStringLiteral">"\033[0m"</span><span class="doxyHighlight">, </span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00152"></a>152</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightStringLiteral">"\033[32m"</span><span class="doxyHighlight">, </span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00153"></a>153</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightStringLiteral">"\033[31m"</span><span class="doxyHighlight"> </span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00154"></a>154</span><span class="doxyLineContent"><span class="doxyHighlight">    };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00155"></a>155</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00163"></a><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a48c790000ed3d766b705c6c5223d8767">163</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">inline</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a> <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a48c790000ed3d766b705c6c5223d8767">colours_none</a>{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00164"></a>164</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00165"></a>165</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ========================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00166"></a>166</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00205"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter">205</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00206"></a>206</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00215"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#aec75a9652b7e98188d506c462aa73e19">215</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#aec75a9652b7e98188d506c462aa73e19">check_result</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00216"></a>216</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00224"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a97203c5c0e22fec0ca6a7cff1f911862">224</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">struct </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a97203c5c0e22fec0ca6a7cff1f911862">plain_text</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00225"></a>225</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00226"></a>226</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00233"></a>233</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a>&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a>) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00234"></a>234</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00241"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#aed6149e163549956985e23a3ee9e6282">241</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#aed6149e163549956985e23a3ee9e6282">expression_formatter</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;) = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00242"></a>242</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00249"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a7de3044d562926e79a6039bed6230794">249</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a7de3044d562926e79a6039bed6230794">expression_formatter</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;&amp;) = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00250"></a>250</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00257"></a>257</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00258"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a1a4f5fbbf1f7194b61b6d1cedf2b8a62">258</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a1a4f5fbbf1f7194b61b6d1cedf2b8a62">operator=</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00259"></a>259</span><span class="doxyLineContent"><span class="doxyHighlight">          = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00260"></a>260</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00267"></a>267</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00268"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#acf0a0ce3f89ee68096e5b104dfbd8481">268</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a1a4f5fbbf1f7194b61b6d1cedf2b8a62">operator=</a>(<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;&amp;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00269"></a>269</span><span class="doxyLineContent"><span class="doxyHighlight">          = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00270"></a>270</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00277"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a421fc77a0d2c9939ca7d2fdc1ba13358">277</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a421fc77a0d2c9939ca7d2fdc1ba13358">~expression_formatter</a> () = </span><span class="doxyHighlightKeywordFlow">default</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00278"></a>278</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00279"></a>279</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// ----------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00280"></a>280</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// Primitive operator&lt;&lt; overloads.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00281"></a>281</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00293"></a>293</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00294"></a>294</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(std::string_view sv);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00295"></a>295</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00310"></a>310</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00311"></a>311</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> c);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00312"></a>312</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00313"></a>313</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__cpp_char8_t)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00330"></a>330</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00331"></a>331</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">char8_t</span><span class="doxyHighlight"> c);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00332"></a>332</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__cpp_char8_t)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00333"></a>333</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00351"></a>351</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00352"></a>352</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">char16_t</span><span class="doxyHighlight"> c);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00353"></a>353</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00372"></a>372</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00373"></a>373</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">char32_t</span><span class="doxyHighlight"> c);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00374"></a>374</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00391"></a>391</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00392"></a>392</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">wchar_t</span><span class="doxyHighlight"> c);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00393"></a>393</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00405"></a>405</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00406"></a>406</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* s);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00407"></a>407</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00418"></a>418</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00419"></a>419</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/c-string">c_string</a>&amp; s);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00420"></a>420</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00431"></a>431</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00432"></a>432</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/named-bool">named_bool</a>&amp; b);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00433"></a>433</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00440"></a>440</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00441"></a>441</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00442"></a>442</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00448"></a>448</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(std::nullptr_t);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00449"></a>449</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00459"></a>459</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(std::nullopt_t);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00460"></a>460</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00467"></a>467</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00468"></a>468</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">signed</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> c);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00469"></a>469</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00476"></a>476</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00477"></a>477</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> c);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00478"></a>478</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00485"></a>485</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00486"></a>486</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">signed</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">short</span><span class="doxyHighlight"> v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00487"></a>487</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00494"></a>494</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00495"></a>495</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">short</span><span class="doxyHighlight"> v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00496"></a>496</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00503"></a>503</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00504"></a>504</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">signed</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00505"></a>505</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00512"></a>512</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00513"></a>513</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00514"></a>514</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00521"></a>521</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00522"></a>522</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">signed</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00523"></a>523</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00530"></a>530</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00531"></a>531</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00532"></a>532</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00539"></a>539</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00540"></a>540</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">signed</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00541"></a>541</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00548"></a>548</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00549"></a>549</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00550"></a>550</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00560"></a>560</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00561"></a>561</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">float</span><span class="doxyHighlight"> v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00562"></a>562</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00573"></a>573</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00574"></a>574</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">double</span><span class="doxyHighlight"> v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00575"></a>575</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00585"></a>585</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00586"></a>586</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">long</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">double</span><span class="doxyHighlight"> v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00587"></a>587</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00588"></a>588</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// ----------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00589"></a>589</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// Template operator&lt;&lt; overloads.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00590"></a>590</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00607"></a>607</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00608"></a>608</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (not std::is_same_v&lt;T, char&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00609"></a>609</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00610"></a>610</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlight">&lt;&lt; (T* v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00611"></a>611</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00630"></a>630</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00631"></a>631</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op&lt;T&gt;</a> and </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; v) { v.get (); })</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00632"></a>632</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00633"></a>633</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlight">&lt;&lt; (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; t);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00634"></a>634</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00649"></a>649</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00650"></a>650</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/formattable-range">detail::formattable_range&lt;T&gt;</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00651"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a0f53d49c9cf2bcbf4b5b35f136f769ce">651</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00652"></a>652</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; t);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00653"></a>653</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00673"></a>673</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00674"></a>674</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (std::is_enum_v&lt;T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00675"></a>675</span><span class="doxyLineContent"><span class="doxyHighlight">                  and not std::is_convertible_v&lt;T, std::underlying_type_t&lt;T&gt;&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00676"></a>676</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00677"></a>677</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlight">&lt;&lt; (T v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00678"></a>678</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00691"></a>691</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T1, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T2&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00692"></a>692</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00693"></a>693</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::pair&lt;T1, T2&gt;&amp; p);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00694"></a>694</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00706"></a>706</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight">... Ts&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00707"></a>707</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00708"></a>708</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::tuple&lt;Ts...&gt;&amp; t);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00709"></a>709</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00722"></a>722</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00723"></a>723</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00724"></a>724</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::optional&lt;T&gt;&amp; o);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00725"></a>725</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00739"></a>739</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Rep, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Period&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00740"></a>740</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00741"></a>741</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::chrono::duration&lt;Rep, Period&gt;&amp; d);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00742"></a>742</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00743"></a>743</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// ----------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00744"></a>744</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// Compound expression operator&lt;&lt; overloads (with pass/fail colours).</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00745"></a>745</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00759"></a>759</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Lhs_T, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Rhs_T, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Compare_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00760"></a>760</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00761"></a>761</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/compare-op">detail::compare_op&lt;Lhs_T, Rhs_T, Compare_T&gt;</a>&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00762"></a>762</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00777"></a>777</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Lhs_T, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Rhs_T, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Epsilon_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00778"></a>778</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00779"></a>779</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/approx-op">detail::approx_op&lt;Lhs_T, Rhs_T, Epsilon_T&gt;</a>&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00780"></a>780</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00793"></a>793</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Lhs_T, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Rhs_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00794"></a>794</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00795"></a>795</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/and-op">detail::and_op&lt;Lhs_T, Rhs_T&gt;</a>&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00796"></a>796</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00809"></a>809</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Lhs_T, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Rhs_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00810"></a>810</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00811"></a>811</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/or-op">detail::or_op&lt;Lhs_T, Rhs_T&gt;</a>&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00812"></a>812</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00820"></a>820</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00821"></a>821</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00822"></a>822</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/not-op">detail::not_op&lt;T&gt;</a>&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00823"></a>823</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00836"></a>836</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Predicate_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00837"></a>837</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00838"></a>838</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/predicate-op">detail::predicate_op&lt;T, Predicate_T&gt;</a>&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00839"></a>839</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00840"></a>840</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__cpp_exceptions)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00841"></a>841</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00851"></a>851</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Exception_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00852"></a>852</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00853"></a>853</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/throws-op">detail::throws_op&lt;Exception_T&gt;</a>&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00854"></a>854</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00861"></a>861</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00862"></a>862</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a937600e01855336e5ef437104e7ee688">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/nothrow-op">detail::nothrow_op</a>&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00863"></a>863</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00864"></a>864</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__cpp_exceptions)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00865"></a>865</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00866"></a>866</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// ----------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00867"></a>867</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00881"></a>881</span><span class="doxyLineContent"><span class="doxyHighlight">      [[nodiscard]] </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00882"></a>882</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a57a2737ff5f067461e4f220acd9fcd4b">str</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00883"></a>883</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00884"></a>884</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">private</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00897"></a>897</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">explicit</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4c72fc8eae7aab4545122235816eb03e">expression_formatter</a> (std::string&amp;&amp; buffer) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00898"></a>898</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00899"></a>899</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// ----------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00900"></a>900</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// Ownership by the checks.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00901"></a>901</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00915"></a>915</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00916"></a>916</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a433e0e309292ccc3e42a35076e32d6c3">begin_check</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">* owner);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00917"></a>917</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00926"></a>926</span><span class="doxyLineContent"><span class="doxyHighlight">      [[nodiscard]] </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00927"></a>927</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#ae0068f2e9d46a29c71fcc812f505fbce">check_text</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">* owner) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00928"></a>928</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00937"></a>937</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00938"></a>938</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#aa568154ec1095196010a66fec43a393f">end_check</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">* owner) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00939"></a>939</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00940"></a>940</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// ----------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00941"></a>941</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00948"></a>948</span><span class="doxyLineContent"><span class="doxyHighlight">      [[nodiscard]] </span><span class="doxyHighlightKeyword">inline</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00949"></a>949</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a2440544fb5674da8853708f9af9ccc14">colour</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> cond) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00950"></a>950</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00964"></a>964</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00965"></a>965</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a7b397504fbb760801d70b1a06186a599">append_decimal_point</a> (std::size_t start);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00966"></a>966</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00979"></a>979</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00980"></a>980</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a07bd2bc6c72722228701c2e5f3bfeed8">append_suffix</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* suffix);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00981"></a>981</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01006"></a>1006</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01007"></a>1007</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a1af5c2ffe3cd4eacad21667c2d4e3914">append_character</a> (std::string_view prefix, </span><span class="doxyHighlightKeywordType">char32_t</span><span class="doxyHighlight"> code,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01008"></a>1008</span><span class="doxyLineContent"><span class="doxyHighlight">                        std::size_t size);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01009"></a>1009</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01025"></a>1025</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight">Tuple_T, std::size_t... Is&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01026"></a>1026</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01027"></a>1027</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a2966189c9d09d874a21e069c10a23b44">append_elements</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Tuple_T&amp; t, std::index_sequence&lt;Is...&gt;);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01028"></a>1028</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01042"></a>1042</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01043"></a>1043</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01044"></a>1044</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a74bb5c3c4b3feacc77d1afe464a7c988">append_and_operand</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; t);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01045"></a>1045</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01055"></a>1055</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Lhs_T, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Rhs_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01056"></a>1056</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01057"></a>1057</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a74bb5c3c4b3feacc77d1afe464a7c988">append_and_operand</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/and-op">detail::and_op&lt;Lhs_T, Rhs_T&gt;</a>&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01058"></a>1058</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01070"></a>1070</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01071"></a>1071</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01072"></a>1072</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#abca8031b08daa1101165c0ba47709d8b">append_or_operand</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; t);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01073"></a>1073</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01083"></a>1083</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Lhs_T, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Rhs_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01084"></a>1084</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01085"></a>1085</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#abca8031b08daa1101165c0ba47709d8b">append_or_operand</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/or-op">detail::or_op&lt;Lhs_T, Rhs_T&gt;</a>&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01086"></a>1086</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01094"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a566350d8ec85e4c0b5d8a27ef61f819f">1094</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a566350d8ec85e4c0b5d8a27ef61f819f">colours_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01095"></a>1095</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01102"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a1e8f6c298a6a12d07bdb9afd47c9c52c">1102</a></span><span class="doxyLineContent"><span class="doxyHighlight">      std::string <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01103"></a>1103</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01111"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#aaa185fbbc82e45621ca924efea6c8a3c">1111</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">* <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#aaa185fbbc82e45621ca924efea6c8a3c">owner_</a>{ </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight"> };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01112"></a>1112</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01124"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a5efacef89d1d5150982bbce240ac625e">1124</a></span><span class="doxyLineContent"><span class="doxyHighlight">      std::vector&lt;std::pair&lt;const void*, std::string&gt;&gt; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a5efacef89d1d5150982bbce240ac625e">pending_</a>{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01125"></a>1125</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01134"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4a956e5994817535692a7684eb26e149">1134</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a4a956e5994817535692a7684eb26e149">plain_</a>{ </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight"> };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01135"></a>1135</span><span class="doxyLineContent"><span class="doxyHighlight">    };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01136"></a>1136</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01137"></a>1137</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01138"></a>1138</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01151"></a><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/plain-text">1151</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">struct </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/plain-text">plain_text</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01152"></a>1152</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01169"></a>1169</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01170"></a>1170</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/printable">extension::printable&lt;T&gt;</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01171"></a>1171</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01172"></a>1172</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/plain-text/#a63b3cc3a8e725c2921787180f1244824">append</a> (std::string&amp; text, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">value</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01173"></a>1173</span><span class="doxyLineContent"><span class="doxyHighlight">    };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01174"></a>1174</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01175"></a>1175</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01176"></a>1176</span><span class="doxyLineContent"><span class="doxyHighlight">  } </span><span class="doxyHighlightComment">// namespace detail</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01177"></a>1177</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01178"></a>1178</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01179"></a>1179</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01227"></a><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-function-comparators/#gabecc05360d0941067222d827ff8e3f08">1227</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-function-comparators/#gabecc05360d0941067222d827ff8e3f08">expression_formatter</a> = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter">detail::expression_formatter</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01228"></a>1228</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01229"></a>1229</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01230"></a>1230</span><span class="doxyLineContent"><span class="doxyHighlight">} </span><span class="doxyHighlightComment">// namespace micro_os_plus::micro_test_plus</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01231"></a>1231</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01232"></a>1232</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01233"></a>1233</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01234"></a>1234</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01235"></a>1235</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01236"></a>1236</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01237"></a>1237</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01238"></a>1238</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__cplusplus)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01239"></a>1239</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01240"></a>1240</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ============================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01241"></a>1241</span><span class="doxyLineContent"><span class="doxyHighlightComment">// Templates, inlines &amp; constexpr implementations.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01242"></a>1242</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01243"></a>1243</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/expression-formatter-inlines-h">inlines/expression-formatter-inlines.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01244"></a>1244</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01245"></a>1245</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01246"></a>1246</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01247"></a>1247</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_EXPRESSION_FORMATTER_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01248"></a>1248</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01249"></a>1249</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
