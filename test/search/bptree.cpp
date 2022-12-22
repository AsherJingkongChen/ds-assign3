#include <iostream>
#include "../../third-party/BPlusTree/src/BTree.hpp"
#include "../../src/cpp/header/test_header.hpp"

using namespace std;
using namespace chrono_literals;
using namespace ds;

// ./<program> <size_in_2_power_of> <do_skipping>
// see `void check_main(int argc, char* argv[])`
//
int main(int argc, char* argv[]) {
  check_main(argc, argv);

  // parse argument
  //
  size_t size_in_2_power_of(stoul(argv[1]));
  bool do_skipping(stoi(argv[2]));

  csv data({
    {"structure_name", "bptree"},
    {"operation_name", "search"},
    {"size_in_2_power_of", argv[1]},
    {"time_in_millisecond", ""}
  });

  // skip the test if `do_skipping` 
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
  auto max_time(1h);

  // build structure
  //
  BTree<int, int> st;
  for (size_t t(from_2_power_of(size_in_2_power_of)); t--;) {
    st.insert(rng(), rng());
  }

  try {
    set_timeout(
      max_time,
      [&]() {
        clock.reset();
        for (size_t t(100000); t--;) {
          st.at(rng());
        }
        clock.pause();
      }
    );

    clock.pause();
    data["time_in_millisecond"] 
      = to_string(clock.elapsed());

    // output the test result
    //
    cout << data.row_line() << flush;
    return EXITCODE_PASS;

  } catch (timeout_error &err) {
    // if all test timed-out,
    // leave the cell `time_in_millisecond` in data blank,
    // and set true to `do_skipping` of all the following test.
    //
    cout << data.row_line() << flush;
    return EXITCODE_SKIP;
  }
}
