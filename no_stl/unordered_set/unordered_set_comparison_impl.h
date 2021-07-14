#include "./unordered_set_comparison.h"
#include "./unordered_set_impl.h"

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::unordered_set {//[mto.ns_begin]

template <typename _t>
bool operator==(unordered_set_t<_t> const & a, unordered_set_t<_t> const & b)
{
  return get_impl(a) == get_impl(b);
}

template <typename _t>
bool operator!=(unordered_set_t<_t> const & a, unordered_set_t<_t> const & b)
{
  return get_impl(a) != get_impl(b);
}


}//[mto.ns_end]

