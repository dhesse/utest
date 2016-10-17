#ifndef TEST_TEST_CASE_H
#define TEST_TEST_CASE_H

#include "Utest.h"
#include "ReportResult.h"

struct MockTestReporter: public utest::TestReporter {
  MockTestReporter(): called(false) { }
  void report(const utest::TestResult&) const override {
    const_cast<MockTestReporter*>(this)->called = true;
  }
  void next_level() override { }
  void previous_level() override { }
  bool called;
};

struct MockTestCase: public utest::TestCase {
  void run() override { }
};

UTEST_CASE(TestCaseCallsReport) {
  MockTestReporter r;
  MockTestCase c;
  c.report(&r);
  assertTrue(r.called);
}

#endif // TEST_TEST_CASE_H
