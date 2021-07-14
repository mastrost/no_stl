#pragma once

#include "./vector_comparison.h"
#include "./vector_impl.h"

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::vector {//[mto.ns_begin]

template <typename _t>
bool operator==(vector_t<_t> const & a, vector_t<_t> const & b)
{
  return get_impl(a) == get_impl(b);
}

template <typename _t>
bool operator!=(vector_t<_t> const & a, vector_t<_t> const & b)
{
  return get_impl(a) != get_impl(b);
}

template <typename _t>
bool operator<(vector_t<_t> const & a, vector_t<_t> const & b)
{
  return get_impl(a) < get_impl(b);
}


}//[mto.ns_end]

