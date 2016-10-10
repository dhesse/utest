#ifndef UTEST_REPORT_RESULTS_H
#define UTEST_REPORT_RESULTS_H

#include <string>
#include <iostream>

#include "TestResult.h"

namespace utest {

  void report(const TestResult& r) {
    std::cout << r.name()
              << (r ? " [PASS] (" : " [FAIL] (")
              << r.successes() << "/"
              << r.fails() + r.successes() << ")\n";
  }

}

#endif
