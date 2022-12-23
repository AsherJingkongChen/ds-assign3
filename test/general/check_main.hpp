#ifndef CHECK_MAIN
#define CHECK_MAIN

#include <stdexcept>
#include <string>

namespace ds {

static constexpr int EXITCODE_PASS = 0;
static constexpr int EXITCODE_SKIP = 1;

// test argument checker
// ./<program> <size_in_2_power_of> <do_skipping>
// <size_in_2_power_of>: an integer in [10, 30]
// <do_skipping>: a integer to be converted to boolean
//
void check_main(int argc, char* argv[]) {
  if (argc != 3) {
    throw std::invalid_argument(
      std::string("Missing arguments, usage: ") + 
      argv[0] + " <size_in_2_power_of> <do_skipping>\n"
    );
  }

  std::size_t size_in_2_power_of;

  try {
    size_in_2_power_of = std::stoul(argv[1]);

  } catch (...) {
    throw std::invalid_argument(
      "Invalid value for argument \"size_in_2_power_of\", "
      "it should be an integer from 10 to 30\n"
    );
  }

  if (size_in_2_power_of > 30 ||
      size_in_2_power_of < 10) {

    throw std::invalid_argument(
      "Invalid value for argument \"size_in_2_power_of\", "
      "it should be an integer from 10 to 30\n"
    );
  }

  try {
    int do_skipping(std::stoi(argv[2]));
  
  } catch (...) {
    throw std::invalid_argument(
      "Invalid value for argument \"do_skipping\", "
      "it should be an integer to be converted to boolean\n"
    );
  }
}

} // namespace ds

#endif // CHECK_MAIN
