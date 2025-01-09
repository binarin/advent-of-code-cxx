#include "lib.hh"

int main(int argc, char **argv) {
  assert(argc > 1);
  auto input{read_lines(argv[1])};
  assert(input.size() == 1);

  int floor{0};
  for (const auto c : input[0]) {
    switch (c) {
    case '(':
      ++floor;
      break;
    case ')':
      --floor;
      break;
    default:
      throw std::runtime_error("bad char");
    }
  }
  println("P1 {}", floor);


  floor = 0;
  int basement_idx{};
  for (auto [idx, c] : std::views::enumerate(input[0])) {
    floor += c == '(' ? 1 : -1;
    if (floor == -1) {
      basement_idx = idx + 1;
      break;
    }
  }
  println("P2 {}", basement_idx);

  println("Finished {}.", floor);
  return 0;
}
