#ifndef SORTED_ARRAY
#define SORTED_ARRAY

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

#undef ENABLE_TEST
#define ENABLE_TEST 0
#if ENABLE_TEST
  #include <stdio.h>
  #include <assert.h>

  #undef dprint
  #define dprint(...) fprintf(stderr, __VA_ARGS__)
#else
  #undef assert
  #define assert(...) void(0);

  #undef dprint
  #define dprint(...) void(0);
#endif // ENABLE_TEST

namespace ds {

// introduction of namespace std
using std::move;
using std::copy;

template<
  typename _Tp, 
  typename _Comp = std::less<_Tp>
>
class sorted_array: 
  protected std::vector<_Tp> {

public: // type
  typedef _Comp                                       compare_type;
  typedef std::vector<_Tp>                            base_type;
  typedef typename base_type::size_type               size_type;
  typedef typename base_type::difference_type         difference_type;
  typedef typename base_type::value_type              value_type;
  typedef typename base_type::reference               reference;
  typedef typename base_type::const_reference         const_reference;
  typedef typename base_type::value_type &&           right_reference;

  typedef typename base_type::iterator                iterator;
  typedef typename base_type::const_iterator          const_iterator;
  typedef typename base_type::reverse_iterator        reverse_iterator;
  typedef typename base_type::const_reverse_iterator  const_reverse_iterator;

public: // read-only iterator
  using base_type::cbegin;
  using base_type::cend;
  using base_type::crbegin;
  using base_type::crend;

  const_iterator begin() const noexcept {
    return cbegin();
  }

  const_iterator end() const noexcept {
    return cend();
  }

  const_reverse_iterator rbegin() const noexcept {
    return crbegin();
  }

  const_reverse_iterator rend() const noexcept {
    return crend();
  }

public: // property
  using base_type::size;
  using base_type::empty;
  using base_type::capacity;

  size_type cap() const noexcept {
    return capacity();
  }

  size_type vacancy() const noexcept {
    return cap() - size();
  }

  bool full() const noexcept {
    return cap() == size();
  }

  explicit operator base_type() const {
    return *this;
  }

  base_type to_vector() const {
    return static_cast<base_type>(*this);
  }

private: // data
  compare_type __compare;

public: // open interface
  using base_type::erase; // no reallocation

  void double_cap() noexcept {
    reserve(cap() << 1);
  }

  // minimum required capacity: 1
  //
  void halve_cap() noexcept {
    size_type new_cap(
      std::max(
        cap() >> 1,
        static_cast<size_type>(1)
      )
    );

    if (size() <= new_cap) {
      shrink_to_fit();
      reserve(new_cap);
    }
  }

  // performs binary search using const_reference
  // if const_iterator `iter` satisfies `*iter == value`
  // returns `iter`; otherwise returns `cend()`
  //
  const_iterator find(const_reference value) const {
    const_iterator 
    iter(
      std::lower_bound(cbegin(), cend(), value, __compare)
    ),
    iter_end(cend());

    if (iter != iter_end && 
        not __compare(value, *iter)) {

      return iter;
    }
    return iter_end;
  }

  // ## brief:
  //
  // if `from` is not empty and `to` is not full,
  // it merges `from` into `to` and returns true
  // (back part or all of `from` are used)
  //
  // otherwise returns false
  // 
  // ## detail:
  //
  // * use_from    = min(to.cap() - to.size(), from.size())
  // * use_to      = to.size()
  // * cap_result  = to.cap()
  // * from_it     = from.end() - use_from
  // (it moves the back part of `from`)
  //
  // * to_it       = to.begin()
  //
  // in the only while loop, 
  // it compares `from_it` and `to_it`, 
  // and then pushs back to `result`
  // 
  // when loop ends, it checks `from_it` and `to_it`,
  // and copies the remaining part of either them to `result`
  // 
  // finally, it replaces `to` with `result`
  //
  // ### assertion: 
  //     cap_result == to.cap() >= use_to + use_from
  //
  friend bool merge(
      sorted_array const &from,
      sorted_array &to) { dprint("merge(copy)\n");

    if (from.empty()) { dprint("merge(copy): from.empty() --> return false\n");
      return false;
    }

    if (to.full()) { dprint("merge(copy): to.full() --> return false\n");
      return false;
    }

    base_type result;
    result.reserve(to.cap());

    difference_type size_used_in_from(
      std::min(to.vacancy(), from.size())
    );

    const_iterator
    from_it(from.cend() - size_used_in_from),
    from_end(from.cend());

    std::move_iterator<iterator>
    to_it(to.base_type::begin()),
    to_end(to.base_type::end());

    while (from_it != from_end && to_it != to_end) {
      if (to.__compare(*from_it, *to_it)) {
        result.push_back(*from_it++);
      } else {
        result.push_back(*to_it++);
      }
    }

    if (from_it != from_end) {
      difference_type remain_size(from_end - from_it);
      result.resize(result.size() + remain_size);
      copy(from_it, from_end, result.end() - remain_size);
    }

    if (to_it != to_end) {
      difference_type remain_size(to_end - to_it);
      result.resize(result.size() + remain_size);
      copy(to_it, to_end, result.end() - remain_size);
    }

    assert(result.capacity() == to.capacity());

    to.base_type::operator=(move(result));
    return true;
  }

  friend bool merge(
      sorted_array &&from,
      sorted_array &to) noexcept { dprint("merge(move)\n");

    if (&from == &to) { dprint("merge(move): cannot merge self --> return false\n");
      return false;
    }

    if (from.empty()) { dprint("merge(move): from.empty() --> return false\n");
      return false;
    }

    if (to.full()) { dprint("merge(move): to.full() --> return false\n");
      return false;
    }

    difference_type size_used_in_from(
      std::min(to.vacancy(), from.size())
    );

    std::move_iterator<iterator>
    from_it(from.base_type::end() - size_used_in_from),
    from_end(from.base_type::end());

    std::move_iterator<iterator>
    to_it(to.base_type::begin()),
    to_end(to.base_type::end());

    base_type result;
    result.reserve(to.cap());

    while (from_it != from_end && to_it != to_end) {
      if (to.__compare(*from_it, *to_it)) {
        result.push_back(*from_it++);
      } else {
        result.push_back(*to_it++);
      }
    }

    if (from_it != from_end) {
      difference_type remain_size(from_end - from_it);
      result.resize(result.size() + remain_size);
      copy(from_it, from_end, result.end() - remain_size);
    }

    if (to_it != to_end) {
      difference_type remain_size(to_end - to_it);
      result.resize(result.size() + remain_size);
      copy(to_it, to_end, result.end() - remain_size);
    }

    assert(result.capacity() == to.capacity());

    from.resize(from.size() - size_used_in_from);
    to.base_type::operator=(move(result));
    return true;
  }

  template<
    typename _SIntType = _Tp,
    typename std::enable_if<
      std::is_signed<_SIntType>::value
    >::type* = nullptr
  >
  friend std::istream &operator>>(
      std::istream &in, 
      sorted_array &other) { dprint("in(>>)\n");

    std::string input_string;
    std::getline(std::cin, input_string);
    std::stringstream strin(input_string);

    std::vector<std::string> split_string;
    for (std::string buffer; 
         std::getline(strin, buffer, ' '); ) {

      if (not buffer.empty()) {
        split_string.push_back(move(buffer));
      }
    }

    while (other.cap() < split_string.size()) {
      other.double_cap();
    }

    for (std::string const &str: split_string) {
      other.push_back(std::stoll(str));
    }

    std::sort(
      other.base_type::begin(), 
      other.base_type::end(), 
      other.__compare
    );
    return in;
  }

  template<
    typename _UIntType = _Tp,
    typename std::enable_if<
      std::is_unsigned<_UIntType>::value
    >::type* = nullptr
  >
  friend std::istream &operator>>(
      std::istream &in, 
      sorted_array &other) { dprint("in(>>)\n");

    std::string input_string;
    std::getline(std::cin, input_string);
    std::stringstream strin(input_string);

    std::vector<std::string> split_string;
    for (std::string buffer; 
         std::getline(strin, buffer, ' '); ) {

      if (not buffer.empty()) {
        split_string.push_back(move(buffer));
      }
    }

    while (other.cap() < split_string.size()) {
      other.double_cap();
    }

    for (std::string const &str: split_string) {
      other.push_back(std::stoull(str));
    }

    std::sort(
      other.base_type::begin(), 
      other.base_type::end(), 
      other.__compare
    );
    return in;
  }

  template<
    typename _Up = _Tp,
    typename std::enable_if<
      not std::is_integral<_Up>::value
    >::type* = nullptr
  >
  friend std::istream &operator>>(
      std::istream &in, 
      sorted_array &other) { dprint("in(>>)\n");

    std::string input_string;
    std::getline(std::cin, input_string);
    std::stringstream strin(input_string);

    std::vector<std::string> split_string;
    for (std::string buffer; 
         std::getline(strin, buffer, ' '); ) {

      if (not buffer.empty()) {
        split_string.push_back(move(buffer));
      }
    }

    while (other.cap() < split_string.size()) {
      other.double_cap();
    }

    for (std::string const &str: split_string) {
      other.push_back(static_cast<_Tp>(str.c_str()));
    }

    std::sort(
      other.base_type::begin(), 
      other.base_type::end(), 
      other.__compare
    );
    return in;
  }

  friend std::ostream &operator<<(
      std::ostream &out, 
      sorted_array const &other) { dprint("out(<<)\n");

    out << "[ SAR, '" << other.size() << "/" << other.cap()
        << "', { ";
    for (const_reference _: other) { 
      out << _ << " "; 
    }
    out << "} ]";

    return out;
  }

  template<typename _Tp_2, typename _Comp_2>
  bool operator==(
      sorted_array<_Tp_2, _Comp_2> const &other) const {

    if (size() != other.size()) { dprint("equivalance(==, !=): size() inequal --> (!=)\n");
      return false;
    }

    if (cap() != other.cap()) { dprint("equivalance(==, !=): cap() inequal --> (!=)\n");
      return false;
    }

    auto
    this_it(cbegin()),
    this_end(cend());

    auto
    other_it(other.cbegin()),
    other_end(other.cend());

    while (this_it != this_end) {
      if (*this_it++ != *other_it++) { dprint("equivalance(==, !=): any other inequal --> (!=)\n");
        return false;
      }
    }

    dprint("equivalance(==, !=) --> (==)\n");

    return true;
  }

  template<typename _Tp_2, typename _Comp_2>
  bool operator!=(
      sorted_array<_Tp_2, _Comp_2> const &other) const {

    return !(*this == other);
  }

protected: // internal interface
  using base_type::reserve;
  using base_type::push_back;
  using base_type::shrink_to_fit;

public: // custom simple build
  // initial capacity: 1
  // initial size: 0 or 1
  //
  sorted_array(const_reference initial):
      base_type(),
      __compare() { dprint("build(const_reference)\n");

    push_back(initial);
    reserve(1);
  }

  sorted_array(right_reference initial) noexcept:
      base_type(),
      __compare() { dprint("build(right_reference)\n");

    push_back(move(initial));
    reserve(1);
  }

  sorted_array(compare_type const &compare):
      base_type(),
      __compare(compare) { dprint("build(compare_type const &)\n");

    reserve(1);
  }

  sorted_array(compare_type &&compare) noexcept:
      base_type(),
      __compare(move(compare)) { dprint("build(compare_type &&)\n");

    reserve(1);
  }

public: // custom complicated build
  sorted_array(
      const_reference initial,
      compare_type const &compare):

      base_type(),
      __compare(compare) { dprint("build(const_reference, compare_type const &)\n");

    push_back(initial);
    reserve(1);
  }

  sorted_array(
      right_reference initial,
      compare_type const &compare) noexcept:

      base_type(),
      __compare(compare) { dprint("build(right_reference, compare_type const &)\n");

    push_back(move(initial));
    reserve(1);
  }

  sorted_array(
      const_reference initial,
      compare_type &&compare) noexcept:

      base_type(),
      __compare(move(compare)) { dprint("build(const_reference, compare_type &&)\n");

    push_back(initial);
    reserve(1);
  }

  sorted_array(
      right_reference initial,
      compare_type &&compare) noexcept:
      
      base_type(),
      __compare(move(compare)) { dprint("build(right_reference, compare_type &&)\n");

    push_back(move(initial));
    reserve(1);
  }

public: // general build
  sorted_array():
      base_type(),
      __compare() { dprint("build(default)\n");

    reserve(1);
  }

  sorted_array(sorted_array const &source):
      base_type(source),
      __compare(source.__compare) { dprint("build(copy)\n");

    reserve(source.cap());
  }
  
  sorted_array(sorted_array &&source) noexcept:
    base_type(move(source)),
    __compare(move(source.__compare)) { dprint("build(move)\n");
  }

  sorted_array &operator=(sorted_array const &other) noexcept { dprint("assign(copy)\n");
    base_type::operator=(other);
    __compare = other.__compare;

    shrink_to_fit();
    reserve(other.cap());
    return *this;
  }

  sorted_array &operator=(sorted_array &&other) noexcept { dprint("assign(move)\n");
    base_type::operator=(move(other));
    __compare = move(other.__compare);
    return *this;
  }
};

} // namespace ds

#endif // SORTED_ARRAY
