#pragma once

#include <initializer_list>

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::set {//[mto.ns_begin]

template <typename _t>
struct set_t
{
  set_t();
  set_t(std::initializer_list<_t> const &);
  set_t(set_t const &);
  set_t(set_t &&);
  set_t & operator=(set_t const &);
  set_t & operator=(set_t &&);

  ~set_t();

  struct iterator_t
  {
    iterator_t();
    iterator_t(iterator_t const &);
    iterator_t & operator=(iterator_t const &);
    ~iterator_t();

    bool operator==(iterator_t const &) const;
    bool operator!=(iterator_t const &) const;
    void operator++();
    _t const & operator*() const;

    static constexpr int impl_size = 8;
    static constexpr int impl_align = 8;
    alignas(impl_align) char impl[impl_size];
  };

  void insert(_t const &);
  size_t size() const;

  iterator_t find(_t const &) const;
  iterator_t begin() const;
  iterator_t end() const;
  void erase(iterator_t const & it);
  void erase(_t const &);

  static constexpr int impl_size = 48;
  static constexpr int impl_align = 8;
  alignas(impl_align) char impl[impl_size];
};

}//[mto.ns_end]

