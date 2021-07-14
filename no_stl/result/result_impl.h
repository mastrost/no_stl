#pragma once

#include "./result.h"
#include "../tools/move.h"
#include "no_stl/heap_variant/heap_variant_impl.h"

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::result {//[mto.ns_begin]

template <typename _t, typename error_t>
result_t<_t, error_t>::result_t(result_t const & o) : v(o.v)
{
}

template <typename _t, typename error_t>
result_t<_t, error_t>::result_t(result_t && o) : v(tools::move(o.v))
{
}

template <typename _t, typename error_t>
result_t<_t, error_t>::result_t(_t const & x) : v(x)
{
}

template <typename _t, typename error_t>
result_t<_t, error_t>::result_t(_t && x) : v(tools::move(x))
{
}

template <typename _t, typename error_t>
result_t<_t, error_t>::result_t(error_t const & x) : v(x)
{
}

template <typename _t, typename error_t>
result_t<_t, error_t>::result_t(error_t && x) : v(tools::move(x))
{
}

template <typename _t, typename error_t>
result_t<_t, error_t>::~result_t()
{
}

template <typename _t, typename error_t>
result_t<_t, error_t> & 
result_t<_t, error_t>::operator=(result_t<_t, error_t> const & o)
{
  v = o.v;
  return *this;
}

template <typename _t, typename error_t>
result_t<_t, error_t> & 
result_t<_t, error_t>::operator=(result_t<_t, error_t> && o)
{
  v = tools::move(o.v);
  return *this;
}

template <typename _t, typename error_t>
_t const & result_t<_t, error_t>::operator*() const
{
  return v.template as<_t>();
}

template <typename _t, typename error_t>
_t const & result_t<_t, error_t>::get() const
{
  return v.template as<_t>();
}

template <typename _t, typename error_t>
error_t const & result_t<_t, error_t>::get_error() const
{
  return v.template as<error_t>();
}

template <typename _t, typename error_t>
_t const * result_t<_t, error_t>::get_ptr() const
{
  return v.template as_ptr<_t>();
}

template <typename _t, typename error_t>
error_t const * result_t<_t, error_t>::get_error_ptr() const
{
  return v.template as_ptr<error_t>();
}

template <typename _t, typename error_t>
result_t<_t, error_t>::operator bool() const
{
  return v.template as_ptr<_t>() != nullptr;
}

}//[mto.ns_end]
