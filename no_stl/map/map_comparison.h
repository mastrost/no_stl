#pragma once

#include "./map.h"

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::map {//[mto.ns_begin]

template <typename key_t, typename value_t>
bool operator==(map_t<key_t, value_t> const &, map_t<key_t, value_t> const &);

template <typename key_t, typename value_t>
bool operator!=(map_t<key_t, value_t> const &, map_t<key_t, value_t> const &);

template <typename key_t, typename value_t>
bool operator<(map_t<key_t, value_t> const &, map_t<key_t, value_t> const &);

}//[mto.ns_end]
