#ifndef UTEST_TESTRESULT_H
#define UTEST_TESTRESULT_H

namespace utest {
  class TestResult {
  public:
    TestResult() : nfails(0), nsuccesses(0) { }
    void fail() { nfails++; }
    void succeed() { nsuccesses++; }
    operator bool() const { return nfails == 0; }
  private:
    int nfails;
    int nsuccesses;
  };
}

#endif
