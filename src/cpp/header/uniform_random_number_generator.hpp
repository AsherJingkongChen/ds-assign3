#ifndef UNIFORM_RANDOM_NUMBER_GENERATOR
#define UNIFORM_RANDOM_NUMBER_GENERATOR

#include <random>

// uniform random number generator 
// with specific range and integer type
//
template<typename _IntType>
class urng: public std::uniform_int_distribution<_IntType> {
public: // type
  typedef typename std::uniform_int_distribution<_IntType> base_type;

public: // interface
  _IntType operator()() {
    return base_type::operator()(rng);
  }

public: // build
  urng(_IntType from, _IntType to):
    base_type(from, to),
    rng(std::random_device{}()) {
  }
private: // data
  std::mt19937_64 rng;
};

#endif // UNIFORM_RANDOM_NUMBER_GENERATOR
