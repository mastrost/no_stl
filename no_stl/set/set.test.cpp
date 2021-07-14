#include "./set_impl.h"
#include "./set_comparison_impl.h"
#include "cpp_tools/unittest.h"

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::set {//[mto.ns_begin]

template struct set_t<int>;

UNITTEST()
{
  set_t<int> s{1,2,3};
  CHECK(s.size() == 3);
  CHECK(s.find(2) != s.end());
  CHECK(s.find(8) == s.end());
  s.insert(123);
  s.insert(1000);
  CHECK(s.size() == 5);
  s.erase(s.find(123));
  let expected = set_t<int>{1,2,3,1000};
  CHECK(s == expected);
  s.erase(3);
  s.insert(8);
  CHECK(s.size() == 4);
  CHECK(s != expected);

  {
    auto ss = move(s);
    let expected = set_t<int>{7,8};
    ss = expected;
    CHECK(ss == expected);
  }
}

}//[mto.ns_end]
