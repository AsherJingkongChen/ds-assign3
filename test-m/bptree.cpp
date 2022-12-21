#include "../third-party/SirLYC-BPTree/BPTree.h"
#include "../src/cpp/header/test_header.hpp"
#include <iostream>
#include <fstream>

using namespace std;
using namespace chrono_literals;
using namespace ds;

// ./<program> <size_in_2_power_of> <do_skipping>
//
int main(int argc, char* argv[]) {
  check_main(argc, argv);

  // parse argument
  //
  size_t size_in_2_power_of(stoul(argv[1]));
  bool do_skipping(stoi(argv[2]));

  csv data({
    {"structure_name", "bptree"},
    {"size_in_2_power_of", argv[1]},
    {"insert_time_in_millisecond", ""},
    {"search_time_in_millisecond", ""}
  });

  // skip test if `do_skipping` 
  // (passed from the previous test) is true
  //
  if (do_skipping) {
    cout << data.row_line() << flush;
    return EXITCODE_SKIP;
  }

  // timer set
  //
  urng<int> rng(1, 1 << 30);
  timer<timeunit::msec> clock;
  auto max_time(200ms);

  // B Plus Tree with order 4
  //
  BPTree<int, int> st1(4);

  set_timeout(max_time, // for test
    // insert
    //
    [&]() {
      size_t t(from_2_power_of(size_in_2_power_of));
      clock.reset();
      while (t--) {
        st1.put(rng(), rng());
      }
      clock.pause();
    },

    // on success
    //
    [&]() {
      clock.pause();
      data["insert_time_in_millisecond"]
        = to_string(clock.elapsed());
    },
    [](){}
  );

  // B Plus Tree with order 4 and complete build
  //
  BPTree<int, int> st2(4);
  for (size_t t(from_2_power_of(size_in_2_power_of)); t--;) {
    st2.put(rng(), rng());
  }

  set_timeout(max_time, // for test
    // search
    //
    [&]() {
      clock.reset();
      for (size_t t(100000); t--;) {
        st2.get(rng());
      }
      clock.pause();
    },

    // on success
    //
    [&]() {
      clock.pause();
      data["search_time_in_millisecond"]
        = to_string(clock.elapsed());
    },
    [](){}
  );

  // output the test result
  //
  cout << data.row_line() << flush;

  // if all test timed-out, 
  // set true to `do_skipping` of the next test.
  // all the following test will skip 
  // bacause this early-exit pattern.
  //
  if (data[2].empty() && data[3].empty()) {
    return EXITCODE_SKIP;

  } else {
    return EXITCODE_PASS;
  }
}