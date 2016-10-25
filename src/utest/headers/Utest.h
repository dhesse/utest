#ifndef UTEST_H
#define UTEST_H

#include "MultiTestCase.h"
#include "TestCase.h"

#include <memory>
#include <iostream>

#define UTEST_CASE(name) class name: public utest::TestCase { \
public:                                                       \
 name(): TestCase(#name) {                                    \
   utest::root().register_instance(this);                     \
 }                                                            \
 void run();                                                  \
private:                                                      \
 static name instance_;                                       \
};                                                            \
name name::instance_;                                         \
void name::run()                                           

#define UTEST_SUITE(name) class name: public utest::MultiTestCase { \
public:                                                             \
 name(): MultiTestCase(#name) {                                     \
   utest::root().register_instance(this);                           \
 }                                                                  \
private:                                                            \
 static name instance_;                                             \
};                                                                  \
name name::instance_;

#define UTEST_SUITE_END struct end__COUNTER__ { \
  end__COUNTER__() {                            \
    utest::root().register_instance(nullptr);   \
  }                                             \
  static end__COUNTER__ instance;               \
};                                              \
end__COUNTER__ end__COUNTER__::instance;
  

namespace utest {

  MultiTestCase& root() {
    static MultiTestCase instance("root");
    return instance;
  }

}

#endif //UTEST_H
