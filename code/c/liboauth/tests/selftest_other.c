/**
 *  @brief self-test for liboauth.
 *  @file selftest.c
 *  @author Robin Gareus <robin@gareus.org>
 *
 * Copyright 2009 Robin Gareus <robin@gareus.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oauth.h>

#include "commontest.h"

int loglevel = 1; //< report each successful test

int main (int argc, char **argv) {
  int fail=0;

  if (loglevel) printf("\n *** testing liboauth for unusual parameters\n");

  fail|=test_request("GET", "http://example.com" 
      "?k1=v1"
      "&a1[ak1]=av1"
      "&a1[aa1][aak2]=aav2"
      "&a1[aa1][aak1]=aav1"
      "&k2=v2"
      "&a1[ak2]=av2",
  "GET&http%3A%2F%2Fexample.com%2F&a1%255Baa1%255D%255Baak1%255D%3Daav1%26a1%255Baa1%255D%255Baak2%255D%3Daav2%26a1%255Bak1%255D%3Dav1%26a1%255Bak2%255D%3Dav2%26k1%3Dv1%26k2%3Dv2");

  // report
  if (fail) {
    printf("\n !!! One or more extended test cases failed.\n\n");
  } else {
    printf(" *** extended test cases verified sucessfully.\n");
  }

  return (fail?1:0);
}