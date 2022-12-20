#include "../src/cpp/header/csv.hpp"
#include <iostream>

using namespace std;
using namespace ds;

int main() {
  cout << csv({
    "structure_name",
    "size_in_2_power_of",
    "insert_time_in_millisecond",
    "search_time_in_millisecond"
  })
  .header_line() << flush;
}
