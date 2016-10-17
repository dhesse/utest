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
  m.register_instance(CheckRunMock::get_instance());
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
  m.register_instance(SuccessMock::get_instance());
  m.register_instance(FailMock::get_instance());
  m.run();
  assertFalse(m.result());
};

struct MultiMock:
  public utest::MultiTestCase,
  public ProvideStaticInstance<MultiMock> {
  utest::MultiTestCase const* get_current() const { return current_; }
  utest::MultiTestCase const* get_previous() const { return previous_; }
};

UTEST_CASE(MultiTestCaseGoesToNextLevel) {
  MultiMock m, n;
  m.register_instance(&n);
  assertTrue(m.get_current() == &n);
  assertTrue(n.get_current() == &n);
}

UTEST_CASE(MultiTestComesBackToPreviousOnNull) {
  MultiMock m, n;
  m.register_instance(&n);
  m.register_instance(nullptr);
  assertTrue(m.get_current() == &m);
}

UTEST_CASE(MultiTestPassesToThirdLevel) {
  MultiMock m, n, o;
  m.register_instance(&n);
  m.register_instance(&o);
  assertTrue(n.get_current() == &o);
  m.register_instance(nullptr);
  assertTrue(n.get_current() == &n);
}

#endif // UTEST_MULTI_TEST_CASE_TEST_H
