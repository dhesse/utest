#include "TestTestResult.h"
#include "TestMultiTestCase.h"
#include "ReportResult.h"
#include "Utest.h"

#include <iostream>
#include <memory>

int main() {
  auto reporter = std::make_shared<utest::BasicTestReporter>();
  utest::root().run();
  utest::root().report(reporter);
  return utest::root().result() ? 0 : 1;
}
