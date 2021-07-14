#include "./std_stream.h"

#include <iostream>

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::string {//[mto.ns_begin]

ostream & operator<<(ostream & out, string_t const & str)
{
  for(size_t i=0 ; i<str.size() ; ++i)
    out << str[i];
  return out;
}

}//[mto.ns_end]
