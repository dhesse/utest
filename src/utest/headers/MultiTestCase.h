#ifndef UTEST_MULTI_TEST_CASE_H
#define UTEST_MULTI_TEST_CASE_H

#include <vector>
#include <memory>

#include "TestCase.h"

namespace utest {

  class MultiTestCase : public TestCase {
  public:
    void run() override {
      for (auto i: tests_) {
        i->run();
        if (i->result())
          result_.succeed();
        else
          result_.fail();
      }
    }
    void report(void (*f)(const TestResult&)) const override {
      for (auto i: tests_) {
        i->report(f);
      }
    }    
    void register_test(std::shared_ptr<TestCase> t) {
      tests_.push_back(t);
    }
  private:
    std::vector<std::shared_ptr<TestCase> > tests_;
  };

}

#endif //UTEST_MULTI_TEST_CASE_H
