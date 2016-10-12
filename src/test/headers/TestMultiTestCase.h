#ifndef UTEST_MULTI_TEST_CASE_TEST_H
#define UTEST_MULTI_TEST_CASE_TEST_H

#include "MultiTestCase.h"
#include "TestCase.h"
#include "Utest.h"

#include <memory>

template <class Self>
struct ProvideStaticInstance {
  static Self* get_instance() {
    static Self instance;
    return &instance;
  }
};

struct CheckRunMock :
  public utest::TestCase,
  public ProvideStaticInstance<CheckRunMock> {
  CheckRunMock(): nruns(0) {};
  void run() override {
    nruns += 1;
  };
  int nruns;
};


UTEST_CASE(MultiTestCaseRunsAllTests) {
  utest::MultiTestCase m;
  m.register_test(CheckRunMock::get_instance());
  m.run();
  assertTrue(CheckRunMock::get_instance()->nruns == 1);
};

struct SuccessMock:
  public utest::TestCase,
  public ProvideStaticInstance<SuccessMock> {
  void run() override {}
};

struct FailMock:
  public utest::TestCase,
  public ProvideStaticInstance<FailMock> {
  void run() override {
    result_.fail();
  }
};

UTEST_CASE(MultiTestCaseRegistersFailsAndSuccesses) {
  utest::MultiTestCase m;
  m.register_test(SuccessMock::get_instance());
  m.register_test(FailMock::get_instance());
  m.run();
  assertFalse(m.result());
};

#endif // UTEST_MULTI_TEST_CASE_TEST_H
