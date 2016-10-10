#include <iostream>
#include "TestResult.h"
#include "TestCase.h"

class TestTestResult: public utest::TestCase {
public:
  void run() override {
    utest::TestResult r;
    assertTrue(r);
    r.fail();
    assertFalse(r);
  }
};

int main() {
  TestTestResult t;
  t.run();
  if(t.result()) {
    std::cout << "TestResult test passed!\n";
    return 0;
  }
  std::cout << "TestResult test failed!\n";
  return 1;
}
