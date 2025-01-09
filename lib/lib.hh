#pragma once

#include <cassert>
#include <fstream>
#include <print>
#include <stdexcept>
#include <string>
#include <vector>
#include <ranges>

using std::println;
using std::string;
using std::vector;

using Lines = vector<string>;

inline Lines read_lines(const string &path) {
  std::ifstream file{path};
  if (!file) {
    throw errno;
  }
  string line;
  Lines result{};
  while (std::getline(file, line)) {
    result.push_back(line);
  }
  return result;
}
