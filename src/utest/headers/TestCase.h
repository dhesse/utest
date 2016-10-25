#ifndef UTEST_TESTCASE_H
#define UTEST_TESTCASE_H

#include <string>

#include "TestResult.h"
#include "TestBase.h"
#include "ReportResult.h"

namespace utest {

  class TestCase : public TestBase {
  public:
    TestCase(const std::string& name = "") : result_(name) { }

    const TestResult& result() const override { return result_; }

    virtual void report(TestReporter* r) const override {
      r->report(result_);
    }
  protected:
    void assertTrue(bool b) {
      if (b)
        result_.succeed();
      else
        result_.fail();
    }
    void assertFalse(bool b) { assertTrue(!b); }
    template <class T>
    void assertEqual(const T& t1, const T& t2) {
      assertTrue(t1 == t2);
    }
    TestResult result_;
  };

}

#endif
