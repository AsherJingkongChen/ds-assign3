#include "../third-party/SirLYC-BPTree/BPTree.h"
#include "../src/cpp/header/test_header.hpp"

using namespace ds;

// ./<program> <size_in_2_power_of>
//
int main(int argc, char* argv[]) {
  auto size_in_2_power_of(
    get_size_in_2_power_of_from_main(argc, argv)
  );

  // B+ Tree with order 4
  //
  BPTree<int, int> structure(4);

  TIMEOUT_WRAPPER([&]() {
    for (auto t = from_2_power_of(size_in_2_power_of); t--;) {
      structure.put()
    }

  }, 3600s);

  return 0;
}