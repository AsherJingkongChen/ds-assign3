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

  csv_row data({
    "structure_name",
    "operation_name",
    "size_in_2_power_of",
    "time_in_millisecond"
  });

  data[0] = "bptree";
  data[1] = "search";
  data[2] = argv[1];

  // skip the test if `do_skipping` 
  // (passed from the previous test) is true
  //
  if (do_skipping) {
    cout << data.line() << flush;
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
  cout << data.line() << flush;
  return EXITCODE_PASS;
}
