#include "./map_comparison.h"
#include "./map_impl.h"

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::map {//[mto.ns_begin]

template <typename key_t, typename value_t>
bool operator==(map_t<key_t, value_t> const & a, map_t<key_t, value_t> const & b)
{
  return get_impl(a) == get_impl(b);
}

template <typename key_t, typename value_t>
bool operator!=(map_t<key_t, value_t> const & a, map_t<key_t, value_t> const & b)
{
  return get_impl(a) != get_impl(b);
}

template <typename key_t, typename value_t>
bool operator<(map_t<key_t, value_t> const & a, map_t<key_t, value_t> const & b)
{
  return get_impl(a) < get_impl(b);
}


}//[mto.ns_end]
