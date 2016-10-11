#ifndef TEST_TEST_RESULT_H
#define TEST_TEST_RESULT_H

#include "TestResult.h"
#include "Utest.h"

UTEST_CASE(TestResult) {
  utest::TestResult r;
  assertTrue(r);
  r.fail();
  assertFalse(r);
}

#endif
