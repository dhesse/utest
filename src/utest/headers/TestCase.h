#ifndef UTEST_TESTCASE_H
#define UTEST_TESTCASE_H

#include <string>
#include <memory>

#include "TestResult.h"
#include "TestBase.h"
#include "ReportResult.h"

namespace utest {

  class TestCase : public TestBase {
  public:
    TestCase(const std::string& name = "") : result_(name) { }

    const TestResult& result() const override { return result_; }

    virtual void report(std::shared_ptr<TestReporter> r) const override {
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
    TestResult result_;
  };

}

#endif
