#include "TestTestResult.h"
#include "TestMultiTestCase.h"
#include "ReportResult.h"

#include <iostream>
#include <memory>

int main() {
  utest::MultiTestCase tests("root");
  tests.register_test(std::make_shared<TestTestResult>());
  tests.register_test(std::make_shared<TestMultiTestCaseRunsAllTests>());
  tests.register_test(std::make_shared<TestMultiTestCaseRegistersFailsAndSuccesses>());
  tests.run();
  auto reporter = std::make_shared<utest::BasicTestReporter>();
  tests.report(reporter);
  return tests.result() ? 0 : 1;
}
