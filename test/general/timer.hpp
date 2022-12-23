#ifndef TIMER
#define TIMER

#include <chrono>

namespace ds {

  namespace timeunit {

  typedef std::chrono::nanoseconds    nsec;
  typedef std::chrono::microseconds   usec;
  typedef std::chrono::milliseconds   msec;
  typedef std::chrono::seconds        sec;
  typedef std::chrono::minutes        min;
  typedef std::chrono::hours          hour;

  } // namespace timeunit

// two-state timer, paused or not paused
//
template<typename _Duration>
struct timer {
public: // type
  typedef std::chrono::steady_clock   clock_type;
  typedef _Duration                   duration_type;
  typedef typename _Duration::rep     result_type;

public: // interface
  // initial state
  //
  void reset() {
    __elapsed = 0;
    __paused = false;
    __begin = clock_type::now();
  }

  // non-paused state
  // set `begin`
  //
  void resume() { 
    if (__paused) {
      __paused = false;
      __begin = clock_type::now();
    }
  }

  // paused state
  // add `elapsed`
  //
  void pause() { 
    if (not __paused) {
      __elapsed += std::chrono::duration_cast<duration_type>
                 (clock_type::now() - __begin).count();
      __paused = true;
    }
  }

  // non-paused state
  // add `elapsed`
  // set `begin`
  //
  result_type elapsed() {
    if (not __paused) {
      __elapsed += std::chrono::duration_cast<duration_type>
                 (clock_type::now() - __begin).count();
      __begin = clock_type::now();
    }
    return __elapsed;
  }

public: // build
  timer() {
    reset();
  }

private: // data
  result_type __elapsed;
  bool __paused;
  clock_type::time_point __begin;
};

} // namespace ds

#endif // TIMER
