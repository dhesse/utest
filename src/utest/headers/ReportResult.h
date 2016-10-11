#ifndef UTEST_REPORT_RESULTS_H
#define UTEST_REPORT_RESULTS_H

#include <string>
#include <iostream>

#include "TestResult.h"
#include "TerminalColor.h"

namespace utest {

  void report(const TestResult& r) {

    std::string pass = colorize("[PASS]", TextColor::green);
    std::string fail = colorize("[FAIL]", TextColor::red);
    std::cout << (r ? pass : fail)
              << " (" << r.successes() << "/"
              << r.fails() + r.successes() << ") "
              << r.name() << std::endl;
  }

}

#endif
