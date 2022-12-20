#ifndef GET_SIZE_IN_2_POWER_OF_FROM_MAIN
#define GET_SIZE_IN_2_POWER_OF_FROM_MAIN

#include <stdexcept>
#include <string>

namespace ds {

// execution argument handler
//
std::size_t get_size_in_2_power_of_from_main(
    int argc, 
    char* argv[]) {

  if (argc != 2) {
    throw std::invalid_argument(
      std::string("Missing arguments, usage: ") + 
      argv[0] + " <size_in_2_power_of>\n"
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

  return size_in_2_power_of;
}

} // namespace ds

#endif // GET_SIZE_IN_2_POWER_OF_FROM_MAIN
