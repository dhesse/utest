#ifndef UTEST_TERMINAL_COLOR_H
#define UTEST_TERMINAL_COLOR_H

#include <string>

namespace utest {

  enum class TextColor {
    black = 30,
    red = 31,
    green = 32,
    yellow = 33,
    blue = 34,
    magenta = 35,
    cyan = 36,
    white = 37,
    reset = 39
  };

  std::string select_color(TextColor c) {
    return "\033[" + std::to_string(static_cast<int>(c)) + "m";
  }

  std::string colorize(const std::string& s, TextColor c) {
    return select_color(c) + s + select_color(TextColor::reset);
  }

}

#endif // UTEST_TERMINAL_COLOR_H
