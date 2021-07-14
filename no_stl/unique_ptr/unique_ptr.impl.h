#pragma once

#include "./unique_ptr.h"

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::unique_ptr {//[mto.ns_begin]

template <typename _t> 
template <typename _s> 
unique_ptr<_t>::unique_ptr(_s * p) : p(p)
{
}

template <typename _t> 
template <typename _s> 
unique_ptr<_t>::unique_ptr(unique_ptr<_s> && o)
{
  p = o.get();
  o.release();
}

template <typename _t> unique_ptr<_t>::~unique_ptr()
{
  delete p;
}

template <typename _t> _t & unique_ptr<_t>::operator*() const
{
  return *p;
}

template <typename _t> _t * unique_ptr<_t>::operator->() const
{
  return p;
}

template <typename _t> _t * unique_ptr<_t>::get() const
{
  return p;
}

template <typename _t> void unique_ptr<_t>::release()
{
  p = nullptr;
}

}//[mto.ns_end]
