// test.cpp
#include <fmt/core.h>
#include <sqlite3.h>
#include "calculator.h"
#include <cassert>
#include <cstdio>

// main function!
int main() {
  fmt::print("test!\n");
  fmt::print("{}\n", sqlite3_libversion());
  assert(add(2, 3) == 5);
  assert(add(-1, 1) == 0);
  return 0;
}
