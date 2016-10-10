#include "TestTestResult.h"
#include "TestMultiTestCase.h"

#include <iostream>
#include <memory>

int main() {
  utest::MultiTestCase tests;
  tests.register_test(std::make_shared<TestTestResult>());
  tests.register_test(std::make_shared<TestMultiTestCaseRunsAllTests>());
  tests.register_test(std::make_shared<TestMultiTestCaseRegistersFailsAndSuccesses>());
  tests.run();
  if(tests.result()){
    std::cout << "TestResult test passed!\n";
    return 0;
  }
  std::cout << "TestResult test failed!\n";
  return 1;
}
