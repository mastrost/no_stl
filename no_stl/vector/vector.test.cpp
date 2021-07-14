#include "./vector_impl.h"
#include "./vector_comparison_impl.h"
#include "no_stl/heap_variant/heap_variant_common.h"
#include "no_stl/heap_variant/heap_variant_impl.h"
#include "cpp_tools/unittest.h"
#include <iostream>

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::vector {//[mto.ns_begin]

using mto::no_stl::heap_variant::heap_variant_t;

template struct vector_t<int>;

struct a_t
{
  int x;
  double y;
  char const * s;
};

bool operator==(a_t const &, a_t const &)
{
  return false;
}

typedef vector_t<heap_variant_t<int, a_t>> v_t;
template struct vector_t<heap_variant_t<int, a_t>>;

template
bool operator==(v_t const &, v_t const &);

UNITTEST()
{
  {
    auto u = vector_t<int>{1,2,3,4};

    CHECK(u[2] == 3);

    for(let & i : u)
      cout << i << endl;
  }
}

}//[mto.ns_end]
