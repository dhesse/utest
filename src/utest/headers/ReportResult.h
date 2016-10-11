#ifndef UTEST_REPORT_RESULTS_H
#define UTEST_REPORT_RESULTS_H

#include <string>
#include <iostream>

#include "TestResult.h"
#include "TerminalColor.h"

namespace utest {

  class TestReporter {
  public:
    virtual void report(const TestResult& r) const = 0;
    virtual void next_level() = 0;
    virtual void previous_level() = 0;
  };

  class BasicTestReporter: public TestReporter {
  public:
    BasicTestReporter(): level_(0) { }
    void report(const TestResult& r) const override {

    std::string pass = colorize("[PASS]", TextColor::green);
    std::string fail = colorize("[FAIL]", TextColor::red);
    std::cout << std::string(level_ * 2, ' ')
              << (r ? pass : fail)
              << " (" << r.successes() << "/"
              << r.fails() + r.successes() << ") "
              << r.name() << std::endl;
    }

    void next_level() override { level_ += 1; }
    void previous_level() override { level_ -= 1; }

  private:
    int level_;
  };

}

#endif
