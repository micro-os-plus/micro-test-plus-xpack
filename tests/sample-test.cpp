/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2021 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#include <micro-os-plus/micro-test-plus.h>

using namespace os;

// ----------------------------------------------------------------------------

// Forward definitions of the test cases.
void
test_case_something (mtp::test& t);

void
test_case_exception (mtp::test& t);

// ----------------------------------------------------------------------------

// The test suite.
int
main (int argc, char* argv[])
{
  mtp::test t (argc, argv);

  t.start_suite ("Sample test");

  t.run_test_case (test_case_something, "Check various conditions");

  t.run_test_case (test_case_exception, "Check if exceptions are thrown");

  return t.result ();
}

// ----------------------------------------------------------------------------

// Simple examples of functions to be tested.
int
compute_one ()
{
  return 1;
}

char*
compute_aaa ()
{
  return (char*)"aaa";
}

bool
compute_condition ()
{
  return true;
}

// ----------------------------------------------------------------------------

// Test equality or logical conditions.
void
test_case_something (mtp::test& t)
{
  // Currently only int and long values can be compared.
  // For everything else use casts.
  MTP_EXPECT_EQ (t, compute_one (), 1, "compute_one() == 1");

  // Strings can also be compared (via `strcmp()`).
  MTP_EXPECT_EQ (t, compute_aaa (), "aaa", "compute_aaa() == 'aaa'");

  // More complex conditions are passed as booleans.
  MTP_EXPECT_TRUE (t, compute_condition (), "condition() is true");
}

// Test is something throws exceptions.
void
test_case_exception (mtp::test& t)
{
  try
    {
      // Do something that may throw
      // ...

      // If we reached here, everything is fine.
      MTP_PASS (t, "exception not thrown");
    }
  catch (...)
    {
      MTP_FAIL (t, "exception thrown");
    }
}

// ----------------------------------------------------------------------------
