#pragma once

#include <initializer_list>

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::map {//[mto.ns_begin]

template <typename key_t, typename value_t>
struct map_t
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

  map_t();
  map_t(std::initializer_list<value_type_t> const &);
  map_t(map_t const &);
  map_t(map_t &&);
  map_t & operator=(map_t const &);
  map_t & operator=(map_t &&);

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

  ~map_t();

  void insert(value_type_t const &);
  size_t size() const;

  const_iterator_t find(key_t const &) const;
  const_iterator_t begin() const;
  const_iterator_t end() const;
  void erase(const_iterator_t const & it);
  void erase(key_t const &);

  static constexpr int impl_size = 48;
  static constexpr int impl_align = 8;
  alignas(impl_align) char impl[impl_size];
};

}//[mto.ns_end]
