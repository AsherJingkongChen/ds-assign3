#include <iostream>
#include "../../src/cpp/header/test_header.hpp"
#include "../../third-party/Skiplist/include/chef_base/chef_skiplist.hpp"

using namespace ds;
using namespace std;
using namespace chef;
using namespace chrono_literals;

// ./<program> <size_in_2_power_of> <do_skipping>
// see `void check_main(int argc, char* argv[])`
//
int main(int argc, char* argv[]) {
  int _;
  check_main(argc, argv);

  // parse argument
  //
  size_t size_in_2_power_of(stoul(argv[1]));
  bool do_skipping(stoi(argv[2]));

  csv data({
    {"structure_name", "skiplist"},
    {"operation_name", "insert"},
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
  skiplist<int, int> st;

  try {
    set_timeout(
      max_time,
      [&]() {
        size_t t(from_2_power_of(size_in_2_power_of));
        clock.reset();
        while (t--) {
          st.insert({rng(), rng()});
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

  } catch (const char*) {
    // if all test timed-out,
    // leave the cell `time_in_millisecond` in data blank,
    // and set true to `do_skipping` of all the following test.
    //
    cout << data.row_line() << flush;
    return EXITCODE_SKIP;
  }
}