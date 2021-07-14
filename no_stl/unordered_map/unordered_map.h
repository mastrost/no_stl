#pragma once

#include <initializer_list>

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::unordered_map {//[mto.ns_begin]

template <typename key_t, typename value_t>
struct unordered_map_t
{
  struct value_type_t
  {
    key_t const key;
    value_t value;
  };

  struct value_type_const_ref_t
  {
    key_t const & key;
    value_t const & value;
  };

  unordered_map_t();
  unordered_map_t(std::initializer_list<value_type_t> const &);
  unordered_map_t(unordered_map_t const &);
  unordered_map_t(unordered_map_t &&);
  unordered_map_t & operator=(unordered_map_t const &);
  unordered_map_t & operator=(unordered_map_t &&);

  struct const_iterator_t
  {
    const_iterator_t();
    const_iterator_t(const_iterator_t const &);
    const_iterator_t & operator=(const_iterator_t const &);
    ~const_iterator_t();

    bool operator==(const_iterator_t const &) const;
    bool operator!=(const_iterator_t const &) const;
    void operator++();
    value_type_const_ref_t operator*() const;

    static constexpr int impl_size = 8;
    static constexpr int impl_align = 8;
    alignas(impl_align) char impl[impl_size];
  };

  ~unordered_map_t();

  void insert(value_type_t const &);
  size_t size() const;

  const_iterator_t find(key_t const &) const;
  const_iterator_t begin() const;
  const_iterator_t end() const;
  void erase(const_iterator_t const & it);
  void erase(key_t const &);

  static constexpr int impl_size = 56;
  static constexpr int impl_align = 8;
  alignas(impl_align) char impl[impl_size];
};

}//[mto.ns_end]
