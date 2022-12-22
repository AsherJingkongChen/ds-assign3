#ifndef CHECK_MAIN
#define CHECK_MAIN

#include <stdexcept>
#include <string>

namespace ds {

// test argument checker
// ./<program> <size_in_2_power_of>
// <size_in_2_power_of>: an integer in [10, 30]
//
void check_main(int argc, char* argv[]) {
  if (argc != 2) {
    throw std::invalid_argument(
      std::string("Missing arguments, usage: ") + 
      argv[0] + " <size_in_2_power_of> <do_skipping>\n"
    );
  }

  std::size_t size_in_2_power_of(std::stoul(argv[1]));

  if (size_in_2_power_of > 30 ||
      size_in_2_power_of < 10) {

    throw std::invalid_argument(
      "Invalid value for argument \"size_in_2_power_of\", "
      "it should be an integer from 10 to 30\n"
    );
  }
}

} // namespace ds

#endif // CHECK_MAIN
