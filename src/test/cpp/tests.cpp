#include "TestTestResult.h"
#include "TestMultiTestCase.h"
#include "ReportResult.h"
#include "TestTestCase.h"

#include "Utest.h"

#include <iostream>
#include <memory>

int main() {
  utest::BasicTestReporter reporter;
  utest::root().run();
  utest::root().report(&reporter);
  return utest::root().result() ? 0 : 1;
}
