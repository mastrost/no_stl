#include "./unordered_set_impl.h"
#include "./unordered_set_comparison_impl.h"
#include "cpp_tools/unittest.h"

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::unordered_set {//[mto.ns_begin]

template struct unordered_set_t<int>;

UNITTEST()
{
  unordered_set_t<int> s{1,2,3};
  CHECK(s.size() == 3);
  s.insert(123);
  s.insert(1000);
  CHECK(s.size() == 5);
  s.erase(s.find(123));
  let expected = unordered_set_t<int>{1,2,3,1000};
  CHECK(s == expected);
  s.erase(3);
  s.insert(8);
  CHECK(s.size() == 4);
  CHECK(s != expected);

  auto it = s.begin();
  auto it2 = it;
  it = it2; 
}

}//[mto.ns_end]
