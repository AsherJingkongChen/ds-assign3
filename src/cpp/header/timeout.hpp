#ifndef TIMEOUT
#define TIMEOUT

#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>

namespace ds {

using namespace std::chrono;

// exclusive exception for `timeout`
//
struct timeout_error: public std::runtime_error {
  timeout_error(): 
    std::runtime_error("timeout") {
  }
};

// throws `timeout_error` if execution time 
// is greater than `max_second`
// 
// reference: https://stackoverflow.com/a/40551227
//
template<typename _Fp>
void timeout(_Fp &&nullary_pred, seconds const &max_second)
{
  std::mutex m;
  std::condition_variable cv;

  std::thread t([&cv, &nullary_pred]() 
  {
    nullary_pred();
    cv.notify_one();
  });

  t.detach();

  {
    std::unique_lock<std::mutex> l(m);
    if(cv.wait_for(l, max_second) == std::cv_status::timeout) 
      throw timeout_error();
  }
}

// for convenience
//
#ifndef TIMEOUT_WRAPPER
#define TIMEOUT_WRAPPER(nullary_pred, max_second) \
  try { \
    timeout(nullary_pred, max_second); \
\
  } catch (timeout_error &err) { \
    std::cout << err.what() << std::endl; \
  }

#endif // TIMEOUT_WRAPPER

} // namespace ds

#endif // TIMEOUT
