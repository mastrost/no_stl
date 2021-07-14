#pragma once

#include "./set.h"
#include "../tools/move.h"
#include <set>

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::set {//[mto.ns_begin]

namespace {

template <typename _t> using impl_t = std::set<_t>;

template <typename _t> impl_t<_t> const & get_impl(set_t<_t> const & _this)
{
  return (impl_t<_t> const &)(_this.impl);
}

template <typename _t> impl_t<_t> & get_impl(set_t<_t> & _this)
{
  return (impl_t<_t> &)(_this.impl);
}

template <typename _t> impl_t<_t> && get_impl(set_t<_t> && _this)
{
  return tools::move((impl_t<_t> &&)(_this.impl));
}

}

template <typename _t> set_t<_t>::set_t()
{
  new (impl) impl_t<_t>();
}

template <typename _t> set_t<_t>::set_t(std::initializer_list<_t> const & l)
{
  new (impl) impl_t<_t>(l);
}

template <typename _t> set_t<_t>::set_t(set_t const & o)
{
  new (impl) impl_t<_t>(get_impl(o));
}

template <typename _t> set_t<_t>::set_t(set_t && o)
{
  new (impl) impl_t<_t>(get_impl(tools::move(o)));
}

template <typename _t> set_t<_t> & set_t<_t>::operator=(set_t const & o)
{
  get_impl(*this) = get_impl(o);
  return *this;
}

template <typename _t> set_t<_t> & set_t<_t>::operator=(set_t && o)
{
  get_impl(*this) = get_impl(tools::move(o));
  return *this;
}

template <typename _t> set_t<_t>::~set_t()
{
  static_assert(impl_size == sizeof(impl_t<_t>));
  static_assert(impl_align == alignof(impl_t<_t>));

  let & x = get_impl(*this);
  x.~impl_t<_t>();
}

template <typename _t> void set_t<_t>::insert(_t const & x)
{
  get_impl(*this).insert(x);
}

template <typename _t> size_t set_t<_t>::size() const
{
  return get_impl(*this).size();
}

template <typename _t>
typename set_t<_t>::iterator_t set_t<_t>::begin() const
{
  let std_it = get_impl(*this).begin();
  iterator_t it;
  new (it.impl)(decltype(std_it))(std_it);
  return it;
}

template <typename _t>
typename set_t<_t>::iterator_t set_t<_t>::end() const
{
  let std_it = get_impl(*this).end();
  //TODO: faire util pour copier vers type p_impl
  iterator_t it;
  new (it.impl)(decltype(std_it))(std_it);
  return it;
}

template <typename _t>
typename set_t<_t>::iterator_t set_t<_t>::find(_t const & x) const
{
  let std_it = get_impl(*this).find(x);
  //TODO: faire util pour copier vers type p_impl
  iterator_t it;
  new (it.impl)(decltype(std_it))(std_it);
  return it;
}

template <typename _t>
void set_t<_t>::erase(typename set_t<_t>::iterator_t const & it)
{
  typedef typename impl_t<_t>::iterator it_impl_t;
  let std_it = *(it_impl_t*)it.impl;
  get_impl(*this).erase(std_it);
}

template <typename _t>
void set_t<_t>::erase(_t const & x)
{
  get_impl(*this).erase(x);
}


/**
 * iterator
 */
template <typename _t> 
using it_impl_t = typename impl_t<_t>::iterator;

template <typename _t>
it_impl_t<_t> & get_impl(typename set_t<_t>::iterator_t & _this)
{
  return (it_impl_t<_t>&)(_this.impl);
}

template <typename _t>
it_impl_t<_t> const & get_impl(typename set_t<_t>::iterator_t const & _this)
{
  return (it_impl_t<_t> const &)(_this.impl);
}

template <typename _t>
set_t<_t>::iterator_t::iterator_t()
{
  new (impl) it_impl_t<_t>();
}

template <typename _t>
set_t<_t>::iterator_t::iterator_t(iterator_t const & o)
{
  new (impl) it_impl_t<_t>(get_impl<_t>(o));
}

template <typename _t>
typename set_t<_t>::iterator_t & 
set_t<_t>::iterator_t::operator=(iterator_t const & o)
{
  get_impl<_t>(*this) = get_impl<_t>(o);
  return *this;
}

template <typename _t>
set_t<_t>::iterator_t::~iterator_t()
{
  typedef typename impl_t<_t>::iterator it_impl_t ;

  static_assert(impl_size == sizeof(it_impl_t));
  static_assert(impl_align == alignof(it_impl_t));

  let x = (it_impl_t*)(impl);
  x->~it_impl_t();
}

template <typename _t>
bool set_t<_t>::iterator_t::operator==(set_t<_t>::iterator_t const & o) const
{
  typedef typename impl_t<_t>::iterator it_impl_t ;
  return (*(it_impl_t*)impl) == (*(it_impl_t*)(o.impl));
}

template <typename _t>
bool set_t<_t>::iterator_t::operator!=(set_t<_t>::iterator_t const & o) const
{
  typedef typename impl_t<_t>::iterator it_impl_t ;
  return (*(it_impl_t*)impl) != (*(it_impl_t*)(o.impl));
}

template <typename _t>
void set_t<_t>::iterator_t::operator++()
{
  typedef typename impl_t<_t>::iterator it_impl_t ;
  ++(*(it_impl_t*)impl);
}

template <typename _t>
_t const & set_t<_t>::iterator_t::operator*() const
{
  typedef typename impl_t<_t>::iterator it_impl_t;
  return *(*(it_impl_t*)impl);
}

}//[mto.ns_end]
