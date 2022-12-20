#ifndef SET_TIMEOUT
#define SET_TIMEOUT

#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>

namespace ds {

// throws `timeout_error` if execution time 
// is greater than `max_duration`
// 
// reference: https://stackoverflow.com/a/40551227
//
template<
  typename _Rep, 
  typename _Period, 
  typename _Fp,
  typename _Gp,
  typename _Hp
>
void set_timeout(
    std::chrono::duration<_Rep, _Period> const &max_duration,
    _Fp &&to_process,
    _Gp &&on_success,
    _Hp &&on_failure) {

  std::mutex m;
  std::condition_variable cv;

  std::thread t([&cv, &to_process]() 
  {
    to_process();
    cv.notify_one();
  });

  t.detach();

  std::unique_lock<std::mutex> l(m);
  if (cv.wait_for(l, max_duration) == std::cv_status::timeout) {
    on_failure();

  } else {
    on_success();
  }
}

} // namespace ds

#endif // SET_TIMEOUT
