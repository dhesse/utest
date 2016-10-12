#ifndef UTEST_TEST_BASE_H
#define UTEST_TEST_BASE_H

namespace utest {

  class TestResult;
  class TestReporter;
  
  class TestBase {
  public:
    virtual void run() = 0;
    virtual void report(TestReporter*) const = 0;
    virtual const TestResult& result() const = 0;
  };
  
}

#endif // UTEST_TEST_BASE_H
