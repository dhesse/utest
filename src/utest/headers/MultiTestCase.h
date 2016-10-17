#ifndef UTEST_MULTI_TEST_CASE_H
#define UTEST_MULTI_TEST_CASE_H

#include <vector>
#include <iostream>

#include "TestCase.h"

namespace utest {

  class MultiTestCase : public TestCase {
  public:
    MultiTestCase(const std::string& name = "") :
      TestCase(name), tests_(0), current_ (this), previous_(this) { }
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
      if (current_ == this) {
        if (MultiTestCase* m = dynamic_cast<MultiTestCase*>(t)) {
          m->previous_ = this;
          current_ = m;
          tests_.push_back(t);
        } else if (t == nullptr) {
          previous_->current_ = previous_;
        } else {
          tests_.push_back(t);
        }
      } else {
        current_->register_test(t);
      }
    }
  private:
    std::vector<TestBase* > tests_;
  protected:
    MultiTestCase* current_;
    MultiTestCase* previous_;
  };

}

#endif //UTEST_MULTI_TEST_CASE_H
