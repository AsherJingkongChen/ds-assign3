#include <iostream>
#include "../test/general/general.hpp"

// header for this structure
//
#include <unordered_set>

// example program
//
// please check that you are in the `example` directory by this command:
// > pwd
//
// please compile it with the command (GNU CXX COMPILER):
// > g++ -std=c++17 hashtable_load_factor.cpp -o hashtable_load_factor
//
// after compilation, please run with the command:
// > ./hashtable_load_factor
//
// after running, please remove it with the command:
// > rm ./hashtable_load_factor
//
// or just enter this one command:
// > g++ -std=c++17 hashtable_load_factor.cpp -o hashtable_load_factor && ./hashtable_load_factor && rm ./hashtable_load_factor
//
int main() {
  std::unordered_set<int> structure;

  // rehash occurs when `load_factor() >= max_load_factor()`
  // it's the worst case, which is O(N) time
  //
  // reference:
  // https://gcc.gnu.org/onlinedocs/gcc-12.2.0/libstdc++/api/a08942.html#a086929d624211470ff2b20a0ba23a86d
  //
  for (std::size_t i(ds::from_2_power_of(4)); i--;) {
    structure.insert(i + 10);
    std::cout << structure.load_factor() << std::endl;
  }
}
