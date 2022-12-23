#ifndef ARRAY_OF_SORTED_ARRAYS
#define ARRAY_OF_SORTED_ARRAYS

#include "sorted_array.hpp"
#include <utility>
#include <iterator>

namespace ds {

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

  // typedef typename
  // std::pair<
  //   base_type::const_iterator, 
  //   block_type::const_iterator
  // >
  // const_iterator;

  // typedef typename 
  // std::pair<
  //   base_type::const_reverse_iterator, 
  //   block_type::const_reverse_iterator
  // >
  // const_reverse_iterator;

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
    reference operator*() const {
      return *this;
    }

    const_reference operator*() const {
      return *this;
    }

    pointer operator->() const {
      return this;
    }

    const_pointer operator->() const {
      return this;
    }

  public: // interface
    bool operator==(const_iterator const &other) const {
      return first == other.first &&
             second == other.second;
    }

    bool operator!=(const_iterator const &other) const {
      return !(*this == other);
    }
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
  

public: // interface
  void insert(const_reference value) {
     
  }

  const_iterator find(const_reference value) const {
    base_type::const_iterator
    base_it(base_type::cbegin()),
    base_end(base_type::cend());

    for (; base_it != base_end; base_it++) {
      block_type::const_iterator
      block_it(base_it->find(value)),
      block_end(base_it->cend());

      if (block_it != block_end) {
        return const_iterator(base_it, block_it); 
      }
    }

    return cend(); // [test] if not found, return cend (default constructed const_iterator)
  }

  void erase(const_iterator pos) {
    pos->(pos->
  }

public: // open read-only iterator
  using base_type::cbegin;
  using base_type::cend;
  using base_type::crbegin;
  using base_type::crend;

  inline const_iterator begin() const noexcept {
    return cbegin();
  }

  inline const_iterator end() const noexcept {
    return cend();
  }

  inline const_reverse_iterator rbegin() const noexcept {
    return crbegin();
  }

  inline const_reverse_iterator rend() const noexcept {
    return crend();
  }

public: // build
  array_of_sorted_arrays() = default;
  ~array_of_sorted_arrays() = default;
  array_of_sorted_arrays(array_of_sorted_arrays &&) = default;
  array_of_sorted_arrays(array_of_sorted_arrays const &) = default;
  array_of_sorted_arrays &operator=(array_of_sorted_arrays &&) = default;
  array_of_sorted_arrays &operator=(array_of_sorted_arrays const &) = default;

private:
  
};

} // namespace ds

#endif // ARRAY_OF_SORTED_ARRAYS
