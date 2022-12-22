#ifndef SET_TIMEOUT
#define SET_TIMEOUT

#include <mutex>
#include <string>
#include <chrono>
#include <thread>
#include <stdexcept>
#include <condition_variable>

namespace ds {

class timeout_error: public std::runtime_error {
public: // build
  timeout_error():
    std::runtime_error("timeout") {
  }

  timeout_error(std::string const &what):
    std::runtime_error(what) {
  }
};

// throws `timeout_error` if the time to process
// is greater than `max_duration`
// 
// reference: https://stackoverflow.com/a/40551227
//
template<
  typename _Rep, 
  typename _Period, 
  typename _Fp
>
void set_timeout(
    std::chrono::duration<_Rep, _Period> const &max_duration,
    _Fp &&process) {

  std::mutex m;
  std::condition_variable cv;

  std::thread t([&cv, &process]() 
  {
    process();
    cv.notify_one();
  });

  t.detach();

  {
    std::unique_lock<std::mutex> l(m);
    if (cv.wait_for(l, max_duration) == std::cv_status::timeout)
      throw timeout_error(
        "processing time "
        "exceeded max_duration in set_timeout"
      );
  }
}

} // namespace ds

#endif // SET_TIMEOUT
