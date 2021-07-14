#pragma once

#include "./string.h"
#include <iosfwd>

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::string {//[mto.ns_begin]

std::ostream & operator<<(std::ostream &, string_t const &);

}//[mto.ns_end]
