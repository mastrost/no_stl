#include "./result_impl.h"
#include "cpp_tools/unittest.h"

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::result {//[mto.ns_begin]

template struct result_t<int, char const*>;

UNITTEST()
{
  auto r = result_t<int, double>(123);
  CHECK(r && *r == 123);
  auto r2 = r;
  r2 = 3.14;
  CHECK(!r2 && r2.get_error() == 3.14);

  r = r2;
}

}//[mto.ns_end]
