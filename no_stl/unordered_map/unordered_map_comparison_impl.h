#include "./unordered_map_comparison.h"
#include "./unordered_map_impl.h"

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::unordered_map {//[mto.ns_begin]

template <typename key_t, typename value_t>
bool operator==(unordered_map_t<key_t, value_t> const & a, unordered_map_t<key_t, value_t> const & b)
{
  return get_impl(a) == get_impl(b);
}

template <typename key_t, typename value_t>
bool operator!=(unordered_map_t<key_t, value_t> const & a, unordered_map_t<key_t, value_t> const & b)
{
  return get_impl(a) != get_impl(b);
}

template <typename key_t, typename value_t>
bool operator<(unordered_map_t<key_t, value_t> const & a, unordered_map_t<key_t, value_t> const & b)
{
  return get_impl(a) < get_impl(b);
}


}//[mto.ns_end]
