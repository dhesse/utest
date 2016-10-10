#ifndef UTEST_TESTCASE_H
#define UTEST_TESTCASE_H

#include "TestResult.h"

namespace utest {
  
  class TestCase {
  public:
    virtual void run() = 0;
    const TestResult& result() const { return result_; }

    virtual void report( void(*f)(const TestResult&)) const {
      f(result_);
    }
  protected:
    void assertTrue(bool b) {
      if (b)
        result_.succeed();
      else
        result_.fail();
    }
    void assertFalse(bool b) { assertTrue(!b); }
    TestResult result_;
  };
}

#endif
