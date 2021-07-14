#include "./set_comparison.h"
#include "./set_impl.h"

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::set {//[mto.ns_begin]

template <typename _t>
bool operator==(set_t<_t> const & a, set_t<_t> const & b)
{
  return get_impl(a) == get_impl(b);
}

template <typename _t>
bool operator!=(set_t<_t> const & a, set_t<_t> const & b)
{
  return get_impl(a) != get_impl(b);
}

template <typename _t>
bool operator<(set_t<_t> const & a, set_t<_t> const & b)
{
  return get_impl(a) < get_impl(b);
}


}//[mto.ns_end]
