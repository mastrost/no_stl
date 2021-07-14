#pragma once

#include "./unordered_set.h"

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::unordered_set {//[mto.ns_begin]

template <typename _t>
bool operator==(unordered_set_t<_t> const &, unordered_set_t<_t> const &);

template <typename _t>
bool operator!=(unordered_set_t<_t> const &, unordered_set_t<_t> const &);

}//[mto.ns_end]

