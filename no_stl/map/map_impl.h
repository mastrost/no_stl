#pragma once

#include "./map.h"
#include "../tools/move.h"
#include <map>
#include <iostream>
#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::map {//[mto.ns_begin]

namespace {

template <typename key_t, typename value_t>
using impl_t = std::map<key_t, value_t>;

template <typename key_t, typename value_t> 
  impl_t<key_t, value_t> const & get_impl(map_t<key_t, value_t> const & _this)
{
  return (impl_t<key_t, value_t> const &)(_this.impl);
}

template <typename key_t, typename value_t> 
  impl_t<key_t, value_t> & get_impl(map_t<key_t, value_t> & _this)
{
  return (impl_t<key_t, value_t> &)(_this.impl);
}

template <typename key_t, typename value_t> 
  impl_t<key_t, value_t> && get_impl(map_t<key_t, value_t> && _this)
{
  return tools::move((impl_t<key_t, value_t> &&)(_this.impl));
}

}

template <typename key_t, typename value_t>
map_t<key_t, value_t>::map_t()
{
  new (impl) impl_t<key_t, value_t>();
}

template <typename key_t, typename value_t>
map_t<key_t, value_t>::map_t(std::initializer_list<value_type_t> const & l)
{
  new (impl) impl_t<key_t, value_t>();
  for(let & x : l)
    insert(x);
}

template <typename key_t, typename value_t>
map_t<key_t, value_t>::map_t(map_t const & o)
{
  new (impl) impl_t<key_t, value_t>(get_impl(o));
}

template <typename key_t, typename value_t>
map_t<key_t, value_t>::map_t(map_t && o)
{
  new (impl) impl_t<key_t, value_t>(get_impl(tools::move(o)));
}

template <typename key_t, typename value_t>
map_t<key_t, value_t> & map_t<key_t, value_t>::operator=(map_t const & o)
{
  get_impl(*this) = get_impl(o);
  return *this;
}

template <typename key_t, typename value_t>
map_t<key_t, value_t> & map_t<key_t, value_t>::operator=(map_t && o)
{
  get_impl(*this) = get_impl(tools::move(o));
  return *this;
}

template <typename key_t, typename value_t>
map_t<key_t, value_t>::~map_t()
{
  static_assert(impl_size == sizeof(impl_t<key_t, value_t>));
  static_assert(impl_align == alignof(impl_t<key_t, value_t>));

  let & x = get_impl(*this);
  x.~impl_t<key_t, value_t>();
}

template <typename key_t, typename value_t>
void map_t<key_t, value_t>::insert(map_t<key_t, value_t>::value_type_t const & x)
{
  get_impl(*this).insert({x.key, x.value});
}

template <typename key_t, typename value_t>
size_t map_t<key_t, value_t>::size() const
{
  return get_impl(*this).size();
}

/**
 */

template <typename key_t, typename value_t>
typename map_t<key_t, value_t>::const_iterator_t 
map_t<key_t, value_t>::find(key_t const & x) const
{
  //TODO: faire util pour copier vers type p_impl
  let std_it = get_impl(*this).find(x);
  const_iterator_t it;
  new (it.impl)(decltype(std_it))(std_it);
  return it;
}

template <typename key_t, typename value_t>
typename map_t<key_t, value_t>::const_iterator_t 
map_t<key_t, value_t>::begin() const
{
  let std_it = get_impl(*this).begin();
  const_iterator_t it;
  new (it.impl)(decltype(std_it))(std_it);
  return it;
}

template <typename key_t, typename value_t>
typename map_t<key_t, value_t>::const_iterator_t 
map_t<key_t, value_t>::end() const
{
  let std_it = get_impl(*this).end();
  const_iterator_t it;
  new (it.impl)(decltype(std_it))(std_it);
  return it;
}

template <typename key_t, typename value_t>
void map_t<key_t, value_t>::erase(typename map_t<key_t, value_t>::const_iterator_t const & it)
{
  typedef typename impl_t<key_t, value_t>::const_iterator it_impl_t ;
  let std_it = *(it_impl_t*)it.impl;
  get_impl(*this).erase(std_it);
}

template <typename key_t, typename value_t>
void map_t<key_t, value_t>::erase(key_t const & x)
{
  get_impl(*this).erase(x);
}


/**
 * const_iterator
 */
template <typename key_t, typename value_t> 
using it_impl_t = typename impl_t<key_t, value_t>::const_iterator;

template <typename key_t, typename value_t>
it_impl_t<key_t, value_t> & get_impl(typename map_t<key_t, value_t>::const_iterator_t & _this)
{
  return (it_impl_t<key_t, value_t>&)(_this.impl);
}

template <typename key_t, typename value_t>
it_impl_t<key_t, value_t> const & get_impl(typename map_t<key_t, value_t>::const_iterator_t const & _this)
{
  return (it_impl_t<key_t, value_t> const &)(_this.impl);
}

template <typename key_t, typename value_t>
map_t<key_t, value_t>::const_iterator_t::const_iterator_t()
{
  new (impl) it_impl_t<key_t, value_t>();
}

template <typename key_t, typename value_t>
map_t<key_t, value_t>::const_iterator_t::const_iterator_t(const_iterator_t const & o)
{
  new (impl) it_impl_t<key_t, value_t>(get_impl<key_t, value_t>(o));
}

template <typename key_t, typename value_t>
typename map_t<key_t, value_t>::const_iterator_t & 
map_t<key_t, value_t>::const_iterator_t::operator=(const_iterator_t const & o)
{
  get_impl<key_t, value_t>(*this) = get_impl<key_t, value_t>(o);
  return *this;
}

template <typename key_t, typename value_t>
map_t<key_t, value_t>::const_iterator_t::~const_iterator_t()
{
  typedef typename impl_t<key_t, value_t>::const_iterator it_impl_t ;

  static_assert(impl_size == sizeof(it_impl_t));
  static_assert(impl_align == alignof(it_impl_t));

  let x = (it_impl_t*)(impl);
  x->~it_impl_t();
}

template <typename key_t, typename value_t>
bool map_t<key_t, value_t>::const_iterator_t::operator==(map_t<key_t, value_t>::const_iterator_t const & o) const
{
  typedef typename impl_t<key_t, value_t>::const_iterator it_impl_t ;
  return (*(it_impl_t*)impl) == (*(it_impl_t*)(o.impl));
}

template <typename key_t, typename value_t>
bool map_t<key_t, value_t>::const_iterator_t::operator!=(map_t<key_t, value_t>::const_iterator_t const & o) const
{
  typedef typename impl_t<key_t, value_t>::const_iterator it_impl_t ;
  return (*(it_impl_t*)impl) != (*(it_impl_t*)(o.impl));
}

template <typename key_t, typename value_t>
void map_t<key_t, value_t>::const_iterator_t::operator++()
{
  typedef typename impl_t<key_t, value_t>::const_iterator it_impl_t ;
  ++(*(it_impl_t*)impl);
}

template <typename key_t, typename value_t>
typename map_t<key_t, value_t>::value_type_const_ref_t
map_t<key_t, value_t>::const_iterator_t::operator*() const
{
  typedef typename impl_t<key_t, value_t>::const_iterator it_impl_t ;
  it_impl_t* impl_ref = (it_impl_t*)impl;
  return {(*impl_ref)->first, (*impl_ref)->second};
}


}//[mto.ns_end]
