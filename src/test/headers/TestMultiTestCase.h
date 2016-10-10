#ifndef UTEST_MULTI_TEST_CASE_TEST_H
#define UTEST_MULTI_TEST_CASE_TEST_H

#include "MultiTestCase.h"
#include "TestCase.h"

#include <memory>

class TestMultiTestCaseRunsAllTests : public utest::TestCase {

  struct CheckRunMock : public utest::TestCase {
    CheckRunMock(): nruns(0) {};
    void run() override {
      nruns += 1;
    };
    int nruns;
  };
public:
  void run() override {
    utest::MultiTestCase m;
    auto mock = std::make_shared<CheckRunMock>(); 
    m.register_test(mock);
    m.run();
    assertTrue(mock->nruns == 1);
  }
};

class TestMultiTestCaseRegistersFailsAndSuccesses : public utest::TestCase {

  struct SuccessMock : public utest::TestCase {
    void run() override {}
  };

  struct FailMock: public utest::TestCase {
    void run() override {
      result_.fail();
    }
  };

public:
  void run() override {
    utest::MultiTestCase m;
    m.register_test(std::make_shared<SuccessMock>());
    m.register_test(std::make_shared<FailMock>());
    m.run();
    assertFalse(m.result());
  }    
};

#endif // UTEST_MULTI_TEST_CASE_TEST_H
