#ifndef CONVERSION_FOR_2_POWER_OF
#define CONVERSION_FOR_2_POWER_OF

#include <cstddef>
#include <cmath>
#include <algorithm>

namespace ds {

// convert to result
//
// from_2_power_of(10) -> 2^10
//
constexpr std::size_t 
from_2_power_of(std::size_t in_2_power_of) {
  return std::size_t(1) << in_2_power_of;
}

// convert to exponent
//
// in_2_power_of(2^10) -> 10
// in_2_power_of(1000) -> 10
// in_2_power_of(1100) -> 10
//
constexpr std::size_t 
in_2_power_of(std::size_t from_2_power_of) {
  return 
  std::round(
    std::log2(
      std::max(
        from_2_power_of, 
        std::size_t(1)
      )
    )
  );
}

} // namespace ds

#endif // CONVERSION_FOR_2_POWER_OF
