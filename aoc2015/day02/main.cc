#include "lib.hh"

#include <array>
#include <regex>
#include <stdexcept>
#include <algorithm>

template <int n> auto get_numbers(const std::string &s) -> std::array<int, n> {
  std::array<int, n> result{};
  std::regex num_re{"-?\\d+"};
  auto s_begin = std::sregex_iterator(s.begin(), s.end(), num_re);
  auto s_end = std::sregex_iterator();

  for (auto [idx, match] : std::ranges::subrange(s_begin, s_end) | std::views::enumerate) {
    if (idx >= n) {
      throw std::runtime_error("Too many matches");
    }
    result[idx] = std::stoi(match.str());
    if (idx + 1 == n) {
      return result;
    }
  }

  throw std::runtime_error("Not enough matches");
}

int main(int argc, char **argv) {
  assert(argc > 1);
  auto input{read_lines(argv[1])};

  auto to_int = [](const auto &range) -> int {
    return std::stoi(std::string(std::string_view(range)));
  };

  int total{};
  for (auto line : input) {
    auto [l, w, h] = get_numbers<3>(line);
    int s1 = l * w;
    int s2 = w * h;
    int s3 = l * h;

    total += 2 * s1 + 2 * s2 + 2 * s3 + std::min(s1, std::min(s2, s3));
  }
  println("P1 {}", total);

  int ribbon_total{};
  for (auto line : input) {
    auto ns = get_numbers<3>(line);
    std::ranges::sort(ns);
    ribbon_total += ns[0]*2 + ns[1]*2 + ns[0]*ns[1]*ns[2];
  }
  println("P2 {}", ribbon_total);
  println("Finished.");
}
