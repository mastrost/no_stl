#pragma once

#include "./unordered_map.h"

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::unordered_map {//[mto.ns_begin]

template <typename key_t, typename value_t>
bool operator==(unordered_map_t<key_t, value_t> const &, unordered_map_t<key_t, value_t> const &);

template <typename key_t, typename value_t>
bool operator!=(unordered_map_t<key_t, value_t> const &, unordered_map_t<key_t, value_t> const &);

template <typename key_t, typename value_t>
bool operator<(unordered_map_t<key_t, value_t> const &, unordered_map_t<key_t, value_t> const &);

}//[mto.ns_end]
