#ifndef UTEST_MULTI_TEST_CASE_H
#define UTEST_MULTI_TEST_CASE_H

#include <vector>
#include <iostream>

#include "TestCase.h"

namespace utest {

  template <class Self, class Base>
  class Nestable {
  public:
    Nestable<Self, Base>(Self* s): base_ptrs_(0), current_(s), previous_(s), this_(s) { }
    void register_instance(Base* b) {
      if (current_ == this_) {
        if (Self* s = dynamic_cast<Self*>(b)) {
          s->previous_ = this_;
          current_ = s;
          base_ptrs_.push_back(b);
        } else if (b == nullptr) {
          previous_->current_ = previous_;
        } else {
          base_ptrs_.push_back(b);
        }
      } else {
        current_->register_instance(b);
      }
    }
  protected:
    std::vector<Base*> base_ptrs_;
    Self* current_;
    Self* previous_;
    Self* this_;
  };

  class MultiTestCase : public TestCase,
                        public Nestable<MultiTestCase, TestBase> {
  public:
    MultiTestCase(const std::string& name = "") :
      TestCase(name), Nestable(this) { }
    void run() override {
      for (auto i: base_ptrs_) {
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
      for (auto i: base_ptrs_)
        i->report(r);
      r->previous_level();
    }    
  };

}

#endif //UTEST_MULTI_TEST_CASE_H
