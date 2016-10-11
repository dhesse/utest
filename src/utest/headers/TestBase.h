#ifndef UTEST_TEST_BASE_H
#define UTEST_TEST_BASE_H

namespace utest {

  class TestResult;
  
  class TestBase {
  public:
    virtual void run() = 0;
    virtual void report(void(*)(const TestResult&)) const = 0;
    virtual const TestResult& result() const = 0;
  };
  
}

#endif // UTEST_TEST_BASE_H
