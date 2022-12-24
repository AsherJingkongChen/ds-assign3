#include <iostream>
#include "../test/general/general.hpp"

// header for this structure
//
#include "../third-party/BTree/btree/set.h"

#undef EXAMPLE_DIALOG_INSERT
#define EXAMPLE_DIALOG_INSERT() \
  std::cout << "we will build the structure " \
               "by inserting 8 numbers from 10 to 17" << std::endl;

#undef EXAMPLE_DIALOG_SEARCH
#define EXAMPLE_DIALOG_SEARCH() \
  std::cout << "we will find 8 numbers " \
               "and not find 8 numbers" << std::endl;

// example program
//
// please check that you are in the `example` directory by this command:
// > pwd
//
// please compile it with the command (GNU CXX COMPILER):
// > g++ -std=c++17 btree.cpp -o btree
//
// after compilation, please run with the command:
// > ./btree
//
// after running, please remove it with the command:
// > rm ./btree
//
// or just enter this one command:
// > g++ -std=c++17 btree.cpp -o btree && ./btree && rm ./btree
//
int main() {
  btree::set<int> structure;

  EXAMPLE_DIALOG_INSERT();

  for (std::size_t i(ds::from_2_power_of(3)); i--;) {
    structure.insert(i + 10);
  }

  EXAMPLE_DIALOG_SEARCH();

  for (std::size_t i(ds::from_2_power_of(4)); i--;) {
    auto it = structure.find(i + 10);
    if (it == structure.end()) {
      std::cout << i + 10 << " is not found" << std::endl;

    } else {
      std::cout << i + 10 << " is found, check it: " 
                << *it << std::endl;
    }
  }
}
