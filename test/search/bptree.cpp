#include <iostream>
#include "../general/test_header.hpp"
#include "../../third-party/BPlusTree/src/BTree.hpp"

using namespace ds;
using namespace std;
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

  // setup
  //
  urng<int> rng(1, 1 << 30);
  timer<timeunit::msec> clock;

  // build structure
  //
  BTree<int, int> st;
  for (size_t t(from_2_power_of(size_in_2_power_of)); t--;) {
    st.insert(rng(), rng());
  }

  // start test
  //
  clock.reset();
  for (size_t t(100000); t--;) {
    auto k(rng());
    if (st.find(k) != st.end()) {
      _ = k;
    }
  }
  clock.pause();

  data["time_in_millisecond"]
    = to_string(clock.elapsed());

  // output the test result
  //
  cout << data.row_line() << flush;
  return EXITCODE_PASS;
}
