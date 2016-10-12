#ifndef UTEST_MULTI_TEST_CASE_H
#define UTEST_MULTI_TEST_CASE_H

#include <vector>
#include <iostream>

#include "TestCase.h"

namespace utest {

  class MultiTestCase : public TestCase {
  public:
    MultiTestCase(const std::string& name = "") :
      TestCase(name) { }
    void run() override {
      for (auto i: tests_) {
        i->run();
        if (i->result())
          result_.succeed();
        else
          result_.fail();
      }
    }
    void report(TestReporter* r) const override {
      r->report(result_);
      r->next_level();
      for (auto i: tests_)
        i->report(r);
      r->previous_level();
    }    
    void register_test(TestBase* t) {
      tests_.push_back(t);
    }
  private:
    std::vector<TestBase* > tests_;
  };

}

#endif //UTEST_MULTI_TEST_CASE_H
