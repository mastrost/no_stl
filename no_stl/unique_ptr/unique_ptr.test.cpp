#include "./unique_ptr.h"
#include "./unique_ptr.impl.h"
#include "cpp_tools/unittest.h"
#include <utility>
#include <cassert>

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::unique_ptr {//[mto.ns_begin]

template struct unique_ptr<int>;

struct i_t
{
  int x;
};

struct a_t : i_t
{
};

UNITTEST()
{
  auto p = unique_ptr<a_t>(new a_t{});
  (*p).x = 123;
  unique_ptr<i_t> q = std::move(p);
  assert(q->x == 123);
}

}//[mto.ns_end]
