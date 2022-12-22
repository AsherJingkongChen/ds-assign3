#include <cstdlib>
#include <fstream>
#include <iostream>
#include "../../third-party/BPlusTree/src/BTree.hpp"
#include "../../src/cpp/header/test_header.hpp"

using namespace std;
using namespace chrono_literals;
using namespace ds;

// ./<program> <size_in_2_power_of>
//
int main(int argc, char* argv[]) {
  check_main(argc, argv);

  // parse argument
  //
  size_t size_in_2_power_of(stoul(argv[1]));

  csv data({
    {"structure_name", "bptree"},
    {"operation_name", "insert"},
    {"size_in_2_power_of", argv[1]},
    {"time_in_millisecond", ""}
  });

  // skip the test if `do_skipping` 
  // (passed from the previous test) is true
  //
  if (do_skipping) {
    cout << data.row_line() << flush;
    return EXIT_FAILURE;
  }

  // timer set
  //
  urng<int> rng(1, 1 << 30);
  timer<timeunit::msec> clock;
  auto max_time(500ms);

  if (true) {
    BTree<int, int> st;

    set_timeout(max_time, // for test
      // insert
      //
      [&]() {
        size_t t(from_2_power_of(size_in_2_power_of));
        clock.reset();
        while (t--) {
          st.insert(rng(), rng());
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
  }

  if (true) {
    BTree<int, int> st;
    for (size_t t(from_2_power_of(size_in_2_power_of)); t--;) {
      st.insert(rng(), rng());
    }

    set_timeout(max_time, // for test
      // search
      //
      [&]() {
        clock.reset();
        for (size_t t(100000); t--;) {
          st.at(rng());
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
  }

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