#ifndef ARRAY_OF_SORTED_ARRAYS
#define ARRAY_OF_SORTED_ARRAYS

#include "sorted_array.hpp"
#include <utility>
#include <iterator>

namespace ds {

// to maintain the entire array's structure,
// it is important to keep shorter arrays vacant
//
template<
  typename _Tp, 
  typename _Comp = std::less<_Tp>
>
class array_of_sorted_arrays:
  protected std::vector<sorted_array<_Tp, _Comp>> {

public: // open type 
  typedef std::vector<sorted_array<_Tp, _Comp>>       base_type;
  typedef sorted_array<_Tp, _Comp>                    block_type;
  typedef typename block_type::compare_type           compare_type;
  typedef typename block_type::size_type              size_type;
  typedef typename block_type::difference_type        difference_type;
  typedef typename block_type::value_type             value_type;
  typedef typename block_type::reference              reference;
  typedef typename block_type::const_reference        const_reference;
  typedef typename block_type::value_type &&          right_reference;

protected: // internal type
  template<typename _It, typename _Jt>
  class _iterator_wrapper: public std::pair<_It, _Jt> {

  public: // type
    typedef std::pair<_It, _Jt>   base_type;
    typedef base_type*            pointer;
    typedef const base_type*      const_pointer;
    typedef base_type &           reference;
    typedef base_type const &     const_reference;

  public: // property
    reference operator*() {
      return *this;
    }

    const_reference operator*() const {
      return *this;
    }

    pointer operator->() {
      return this;
    }

    const_pointer operator->() const {
      return this;
    }

  public: // interface
    bool operator==(_iterator_wrapper const &other) const {
      return base_type::first == other.base_type::first &&
             base_type::second == other.base_type::second;
    }

    bool operator!=(_iterator_wrapper const &other) const {
      return !(*this == other);
    }

  public: // build
    using base_type::base_type;
  };

public: // open type
  typedef _iterator_wrapper<
    typename base_type::const_iterator,
    typename block_type::const_iterator
  >
  const_iterator;

  typedef _iterator_wrapper<
    typename base_type::const_reverse_iterator,
    typename block_type::const_reverse_iterator
  >
  const_reverse_iterator;

  typedef const_iterator          iterator;
  typedef const_reverse_iterator  reverse_iterator;

public: // read-only iterator
  const_iterator cbegin() const noexcept {
    return const_iterator(
      base_type::cbegin(),
      base_type::cbegin()->cbegin()
    );
  }

  const_iterator cend() const noexcept {
    return const_iterator(
      base_type::cend(),
      base_type::crbegin()->cend()
    );
  }

  const_reverse_iterator crbegin() const noexcept {
    return const_reverse_iterator(
      base_type::crbegin(),
      base_type::crbegin()->crbegin()
    );
  }

  const_reverse_iterator crend() const noexcept {
    return const_reverse_iterator(
      base_type::crend(),
      base_type::cbegin()->crend()
    );
  }

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

  inline size_type cap() const noexcept {
    return capacity();
  }

  inline size_type vacancy() const noexcept {
    return cap() - size();
  }

  inline bool full() const noexcept {
    return cap() == size();
  }

  inline explicit operator base_type() const {
    return *this;
  }

  inline base_type to_vector() const {
    return static_cast<base_type>(*this);
  }

private: // data
  compare_type __compare;

public: // interface
  // `target` = new sorted_array with one inserted `value`
  //
  // `target` walk from the shortest sorted_array
  // to the following longer ones each iteration
  //
  // `insert()` do the opposite to `erase()`,
  // `target` prones to clear itself
  // (it's for maintaining the entire structure to 
  //  keep shorter arrays vacant)
  //
  // note that in each iteration,
  // `target` has always the double capacity to
  // the other sorted_array
  //
  // if merging `target` to the other sorted_array succeeds:
  //   if `target` is empty:
  //     the iteration stops
  //   else the iteration continues
  // else:
  //   merging the other sorted_array to `target`
  //   the iteration continues
  //
  // before going to the next iteration:
  //   `target` gets capacity doubled
  //
  // a new sorted_array will be built 
  // if the iteration is over and `target` is not empty
  //
  void insert(const_reference value) {
    block_type target(value);
    target.double_cap();

    typename base_type::iterator
    base_other(base_type::begin()),
    base_end(base_type::end());

    for (; base_other != base_end; base_other++) {
      if (merge(move(target), *base_other)) {
        if (target.empty()) {
          return;
        }
      } else if (merge(move(*base_other), target)) {
      } else {
        throw "bug";
      }
      target.double_cap();
    }

    if (not target.empty()) {
      // cut off the capacity allocated at the last iteration
      //
      target.halve_cap();
      push_back(target);
    }
  }

  // it returns the first found const_iterator `it`
  // that walk from the shortest sorted_array 
  // to the following longer ones and `*it == value`
  //
  const_iterator find(const_reference value) const {
    typename base_type::const_iterator
    base_it(base_type::cbegin()),
    base_end(base_type::cend());

    for (; base_it != base_end; base_it++) {
      typename block_type::const_iterator
      block_it(base_it->find(value)),
      block_end(base_it->cend());

      if (block_it != block_end) {
        return const_iterator(base_it, block_it); 
      }
    }
    return cend();
  }

  // `target` = erased sorted_array
  //
  // `target` walk from the shortest sorted_array
  // to the following longer ones each iteration
  //
  // `erase()` do the opposite to `insert()`,
  // `target` prones to fulfill itself
  // (it's for maintaining the entire structure to 
  //  keep shorter arrays vacant)
  //
  // if merging the other sorted_array to `target` succeeds:
  //   if `target` is fulfilled:
  //     the iteration stops
  //   else the iteration continues
  // else the iteration continues
  //
  // if `pos` is not dereferenceable, 
  // this method does no effect
  //
  void erase(const_iterator pos) {
    if (pos->first == cend()->first) {
      return;
    }

    non_const_base_iterator(pos->first)
      ->erase(pos->second);

    typename base_type::iterator
    base_other(base_type::begin()),
    base_target(non_const_base_iterator(pos->first));

    for (; base_other != base_target; base_other++) {
      if (merge(move(*base_other), *base_target) &&
          base_target->full()) {

        return;
      }
    }
  }

  friend std::ostream &operator<<(
      std::ostream &out, 
      array_of_sorted_arrays const &other) {

    out << "[ AR_SAR, '" << other.size() << "/" << other.cap()
        << "', {\n";
    for (auto &sa: other.to_vector()) { 
      out << "  " << sa << "\n"; 
    }
    out << "} ]";
    return out;
  }

protected: // internal interface
  using base_type::reserve;
  using base_type::push_back;
  using base_type::shrink_to_fit;

  typename base_type::iterator
  non_const_base_iterator(
      typename base_type::const_iterator iter) {

    return base_type::erase(iter, iter);
  }

public: // custom build
  // initial size: 1 (the shortest sorted_array)
  //
  array_of_sorted_arrays(compare_type const &compare):
    base_type(1),
    __compare(compare) {
  }

  array_of_sorted_arrays(compare_type &&compare) noexcept:
    base_type(1),
    __compare(move(compare)) {
  }

public: // general build
  array_of_sorted_arrays():
    base_type(1) {
  }

  array_of_sorted_arrays(
      array_of_sorted_arrays const &source):

      base_type(source) {

    reserve(source.capacity());
  }

  array_of_sorted_arrays(
    array_of_sorted_arrays &&source) noexcept:

    base_type(move(source)) {
  }

  array_of_sorted_arrays &
  operator=(array_of_sorted_arrays const &other) {
    base_type::operator=(other);

    shrink_to_fit();
    reserve(other.capacity());
    return *this;
  }

  array_of_sorted_arrays &
  operator=(array_of_sorted_arrays &&other) {
    base_type::operator=(move(other));
    return *this;
  }
};

} // namespace ds

#endif // ARRAY_OF_SORTED_ARRAYS
