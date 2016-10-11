#ifndef UTEST_H
#define UTEST_H

#include "MultiTestCase.h"
#include "TestCase.h"

#include <memory>

#define UTEST_CASE(name) class name: public utest::TestCase { \
public:                                                       \
 name(): TestCase(#name) {                                    \
   auto p = std::shared_ptr<name> (this, [](name* p){});      \
   utest::root().register_test(p);                            \
 }                                                            \
 void run();                                                  \
private:                                                      \
 static name instance_;                                       \
};                                                            \
name name::instance_;                                         \
void name::run()                                           


namespace utest {

  MultiTestCase& root() {
    static MultiTestCase instance("root");
    return instance;
  }

}

#endif //UTEST_H
