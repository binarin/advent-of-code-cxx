#include "lib.hh"

#include <openssl/md5.h>

using Num = long long;

int main(int argc, char **argv) {
  assert(argc > 1);
  auto lines = read_lines(argv[1]);
  assert(lines.size() == 1);
  string secret = lines[0];
  unsigned char md_out[MD5_DIGEST_LENGTH];
  Num seed{};
  while (true) {
    string cur = format("{}{}", secret, seed);
    MD5((const unsigned char *)cur.c_str(), cur.length(), md_out);
    if (md_out[0] == 0 && md_out[1] == 0  && (md_out[2] & 0xf0) == 0) {
      println("Found P1 {} - got {:02x}{:02x}{:02x}", seed, md_out[0], md_out[1],
              md_out[2]);
    }
    if (md_out[0] == 0 && md_out[1] == 0  && md_out[2] == 0) {
      println("Found P2 {} - got {:02x}{:02x}{:02x}", seed, md_out[0],
              md_out[1], md_out[2]);
      break;
    }
    ++seed;
    if (seed > 10000000)
      break;
  }
  println("Finished.");
}
