#include "../third-party/SirLYC-BPTree/BPTree.h"
#include "../src/cpp/header/test_header.hpp"

using namespace ds;
using namespace std::chrono_literals;

// ./<program> <size_in_2_power_of>
//
int main(int argc, char* argv[]) {
  auto size_in_2_power_of(
    get_size_in_2_power_of_from_main(argc, argv)
  );

  // B+ Tree with order 4
  //
  BPTree<int, int> db(4);
  urng<int> rng(1, 1 << 30);
  timer<timeunit::msec> tim;

  set_timeout(1h,
  // to process
    [&]() {
      for (auto t = from_2_power_of(size_in_2_power_of); t--;) {
        db.put(rng(), rng());
      }
    },

  // on success
    []() {

    },

  // on failure
    []() {

    }
  );

  return 0;
}