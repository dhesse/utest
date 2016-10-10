#ifndef TEST_TEST_RESULT_H
#define TEST_TEST_RESULT_H

#include "TestResult.h"
#include "TestCase.h"

class TestTestResult: public utest::TestCase {
public:
  void run() override {
    utest::TestResult r;
    assertTrue(r);
    r.fail();
    assertFalse(r);
  }
};

#endif
