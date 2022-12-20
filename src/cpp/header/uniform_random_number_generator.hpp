#ifndef UNIFORM_RANDOM_NUMBER_GENERATOR
#define UNIFORM_RANDOM_NUMBER_GENERATOR

#include <random>

namespace ds {

// uniform random number generator 
// with specified range and integer type
//
template<typename _IntType>
class urng: public std::uniform_int_distribution<_IntType> {
public: // type
  typedef typename std::uniform_int_distribution<_IntType> base_type;
  typedef _IntType result_type;

public: // interface
  result_type operator()() {
    return base_type::operator()(__rng);
  }

public: // build
  urng(result_type from, result_type to):
    base_type(from, to),
    __rng(std::random_device{}()) {
  }

private: // data
  std::mt19937_64 __rng;
};

} // namespace ds

#endif // UNIFORM_RANDOM_NUMBER_GENERATOR
