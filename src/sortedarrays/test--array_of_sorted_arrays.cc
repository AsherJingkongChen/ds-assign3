#include "array_of_sorted_arrays.h"

using ds::sorted_array;

#undef ENABLE_TEST
#define ENABLE_TEST 1
#if ENABLE_TEST
  #include <stdio.h>
  #include <assert.h>

  #undef dprint
  #define dprint(...) printf(__VA_ARGS__)
#else
  #undef assert
  #define assert(...) void(0);

  #undef dprint
  #define dprint(...) void(0);
#endif // ENABLE_TEST

int main() {
  for (sorted_array<int> sa1, sa2; 
       std::cin >> sa1 >> sa2; sa1 = sa2 = {}) {

    std::cout << sa1 << std::endl
              << sa2 << std::endl;

    bool merged;

//
    merged = merge(move(sa2), sa1); 
    dprint("merged (1 << 2) (in)\n");

    if (merged) { goto eoc_; }
//

//
    merged = merge(move(sa1), sa2);
    dprint("merged (1 >> 2) (out)\n");

    if (merged || true) { goto eoc_; }
//

    sa1.double_cap();

    merged = merge(move(sa2), sa1); 
    dprint("merged (1 << 2) (rmd)\n");

eoc_:
    std::cout << sa1 << std::endl
              << sa2 << std::endl << std::endl;
  }
}
