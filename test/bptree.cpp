#include "../third-party/SirLYC-BPTree/BPTree.h"
#include "../src/cpp/header/test_header.hpp"
#include <iostream>
#include <fstream>

using namespace std;
using namespace chrono_literals;
using namespace ds;

// ./<program> <size_in_2_power_of>
//
int main(int argc, char* argv[]) {
  size_t size_in_2_power_of(
    get_size_in_2_power_of_from_main(argc, argv)
  );

  // B+ Tree with order 4
  //
  BPTree<int, int> st(4);
  urng<int> rng(1, 1 << 30);
  timer<timeunit::msec> clock;
  csv data({
    {"structure_name", "bplustree"},
    {"size_in_2_power_of", to_string(size_in_2_power_of)},
    {"insert_time_in_millisecond", {}},
    {"search_time_in_millisecond", {}}
  });

  set_timeout(1s, // for test
  // to process
    [&]() {
      clock.reset();
      for (size_t t(from_2_power_of(size_in_2_power_of)); t--;) {
        st.put(rng(), rng());
      }
      clock.pause();
    },

  // on success
    [&data, &clock]() { data[2] = to_string(clock.elapsed()); },

  // on failure
    [&data]() { data[2] = ""; }
  );

  set_timeout(1s, // for test
  // to process
    [&]() {
      clock.reset();
      for (size_t t(100000); t--;) {
        st.get(rng());
      }
      clock.pause();
    },

  // on success
    [&data, &clock]() { data[3] = to_string(clock.elapsed()); },

  // on failure
    [&data]() { data[3] = ""; }
  );

  cout << data.row_line() << flush;

  return 0;
}