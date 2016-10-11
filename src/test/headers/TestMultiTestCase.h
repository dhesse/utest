#ifndef UTEST_MULTI_TEST_CASE_TEST_H
#define UTEST_MULTI_TEST_CASE_TEST_H

#include "MultiTestCase.h"
#include "TestCase.h"
#include "Utest.h"

#include <memory>

struct CheckRunMock : public utest::TestCase {
  CheckRunMock(): nruns(0) {};
  void run() override {
    nruns += 1;
  };
  int nruns;
};

UTEST_CASE(MultiTestCaseRunsAllTests) {
  utest::MultiTestCase m;
  auto mock = std::make_shared<CheckRunMock>(); 
  m.register_test(mock);
  m.run();
  assertTrue(mock->nruns == 1);
};


struct SuccessMock : public utest::TestCase {
  void run() override {}
};

struct FailMock: public utest::TestCase {
  void run() override {
    result_.fail();
  }
};

UTEST_CASE(MultiTestCaseRegistersFailsAndSuccesses) {
  utest::MultiTestCase m;
  m.register_test(std::make_shared<SuccessMock>());
  m.register_test(std::make_shared<FailMock>());
  m.run();
  assertFalse(m.result());
};

#endif // UTEST_MULTI_TEST_CASE_TEST_H
