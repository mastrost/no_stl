#pragma once

#include "./vector.h"
#include "../tools/move.h"
#include <vector>

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::vector {//[mto.ns_begin]

namespace {

template <typename _t> using impl_t = std::vector<_t>;

template <typename _t> impl_t<_t> const & get_impl(vector_t<_t> const & _this)
{
  return (impl_t<_t> const &)(_this.impl);
}

template <typename _t> impl_t<_t> & get_impl(vector_t<_t> & _this)
{
  return (impl_t<_t> &)(_this.impl);
}

template <typename _t> impl_t<_t> && get_impl(vector_t<_t> && _this)
{
  return tools::move((impl_t<_t> &)(_this.impl));
}

}


template <typename _t> vector_t<_t>::vector_t()
{
  new (impl) std::vector<_t>();
}

template <typename _t> vector_t<_t>::vector_t(std::initializer_list<_t> const & l)
{
  new (impl) std::vector<_t>(l);
}

template <typename _t> vector_t<_t>::vector_t(vector_t const & o)
{
  new (impl) impl_t<_t>(get_impl(o));
}

template <typename _t> vector_t<_t>::vector_t(vector_t && o)
{
  new (impl) impl_t<_t>(get_impl(tools::move(o)));
}

template <typename _t> vector_t<_t> & vector_t<_t>::operator=(vector_t const & o)
{
  get_impl(*this) = get_impl(o);
  return *this;
}

template <typename _t> vector_t<_t> & vector_t<_t>::operator=(vector_t && o)
{
  get_impl(*this) = get_impl(tools::move(o));
  return *this;
}


template <typename _t> vector_t<_t>::~vector_t()
{
  static_assert(impl_size == sizeof(impl_t<_t>));
  static_assert(impl_align == alignof(impl_t<_t>));

  let & x = get_impl(*this);
  x.~impl_t<_t>();
}

template <typename _t> void vector_t<_t>::push_back(_t const & x)
{
  get_impl(*this).push_back(x);
}

template <typename _t> void vector_t<_t>::push_back(_t && x)
{
  get_impl(*this).push_back(tools::move(x));
}

template <typename _t>
_t const * vector_t<_t>::data() const
{
  return get_impl(*this).data();
}

template <typename _t>
_t const & vector_t<_t>::operator[](size_t i) const
{
  return get_impl(*this)[i];
}

template <typename _t>
_t & vector_t<_t>::operator[](size_t i)
{
  return get_impl(*this)[i];
}

template <typename _t>
size_t vector_t<_t>::size() const
{
  return get_impl(*this).size();
}

template <typename _t>
typename vector_t<_t>::const_iterator_t vector_t<_t>::begin() const
{
  return &(*this)[0];
}

template <typename _t>
typename vector_t<_t>::const_iterator_t vector_t<_t>::end() const
{
  return &(*this)[size()];
}

template <typename _t>
typename vector_t<_t>::iterator_t vector_t<_t>::begin()
{
  return &(*this)[0];
}

template <typename _t>
typename vector_t<_t>::iterator_t vector_t<_t>::end()
{
  return &(*this)[size()];
}


}//[mto.ns_end]
