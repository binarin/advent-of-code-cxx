#include "lib.hh"

#include <map>
#include <ranges>

void go_dir(char dir, int &x, int &y) {
    switch (dir) {
    case '<': --x; break;
    case '>': ++x; break;
    case '^': --y; break;
    case 'v': ++y; break;
    }
}

int main(int argc, char **argv) {
  assert(argc > 1);
  auto input = read_lines(argv[1]);
  assert(input.size() == 1);

  int cx{}, cy{};
  std::map<std::pair<int, int>, int> deliveries{{{cx, cy}, 1}};

  // input[0] = ">";
  // input[0] = "^>v<";

  for (char inst : input[0]) {
    go_dir(inst, cx, cy);
    ++deliveries[{cx, cy}];
  }

  println("P1 {}", deliveries.size());

  cx = 0;
  cy = 0;
  int rx{cx}, ry{cy};

  deliveries.clear();
  deliveries[{rx, ry}] = 1;

  for (auto range : input[0] | std::views::chunk(2)) {
    char si = *range.begin();
    char ri = *(range.begin()+1);

    go_dir(si, cx, cy);
    go_dir(ri, rx, ry);
    ++deliveries[{rx, ry}];
    ++deliveries[{cx, cy}];
  }
  println("P2 {}", deliveries.size());


  println("Finished.");
}
