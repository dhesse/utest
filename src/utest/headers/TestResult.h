#ifndef UTEST_TESTRESULT_H
#define UTEST_TESTRESULT_H

#include <string>

namespace utest {
  class TestResult {
  public:
    TestResult(std::string name = "") :
      nfails_(0), nsuccesses_(0), name_(name) { }
    void fail() { nfails_++; }
    void succeed() { nsuccesses_++; }

    int fails() const { return nfails_; }
    int successes() const { return nsuccesses_; }
    const std::string& name() const { return name_; }

    operator bool() const { return nfails_ == 0; }

  private:
    int nfails_;
    int nsuccesses_;
    std::string name_;
  };
}

#endif
