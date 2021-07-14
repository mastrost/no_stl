#pragma once

#include "./set.h"

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::set {//[mto.ns_begin]

template <typename _t>
bool operator==(set_t<_t> const &, set_t<_t> const &);

template <typename _t>
bool operator!=(set_t<_t> const &, set_t<_t> const &);

template <typename _t>
bool operator<(set_t<_t> const &, set_t<_t> const &);

}//[mto.ns_end]
