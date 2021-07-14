#pragma once

#include "./vector.h"

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::vector {//[mto.ns_begin]

template <typename _t>
bool operator==(vector_t<_t> const &, vector_t<_t> const &);

template <typename _t>
bool operator!=(vector_t<_t> const &, vector_t<_t> const &);

template <typename _t>
bool operator<(vector_t<_t> const &, vector_t<_t> const &);

}//[mto.ns_end]
