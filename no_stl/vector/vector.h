#pragma once

#include <initializer_list>

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::vector {//[mto.ns_begin]

template <typename _t> struct vector_t
{
  vector_t();
  vector_t(std::initializer_list<_t> const &);
  vector_t(vector_t const &);
  vector_t(vector_t &&);
  vector_t & operator=(vector_t const &);
  vector_t & operator=(vector_t &&);

  ~vector_t();

  void push_back(_t const &);
  void push_back(_t &&);
  _t const * data() const;
  _t const & operator[](size_t i) const;
  _t & operator[](size_t i);
  size_t size() const;

  typedef _t const * const_iterator_t;
  typedef _t * iterator_t;

  const_iterator_t begin() const;
  const_iterator_t end() const;
  iterator_t begin();
  iterator_t end();

  static constexpr int impl_size = 24;
  static constexpr int impl_align = 8;
  alignas(impl_align) char impl[impl_size];
};

}//[mto.ns_end]

