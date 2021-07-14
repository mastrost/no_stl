#include "./map_impl.h"
#include "./map_comparison_impl.h"

#include "cpp_tools/unittest.h"

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::map {//[mto.ns_begin]

UNITTEST()
{
  {
    map_t<int, double> m;
    m.insert({123, 3.14});
    CHECK(m.size() == 1);

    CHECK(m.find(66) == m.end());
  }

  {
    map_t<int, double> m = { {1,10.}, {2,20.}, {3,30} };
    int i=0;
    double x=0;
    for(let & e : m)
    {
      i += e.key;
      x += e.value;
    }
    CHECK(i == 6 && x == 60.);
    m.erase(2);
    CHECK(m.size() == 2);
    m.erase(m.find(3));
    CHECK(m.size() == 1);
  }

  {
    map_t<char, int> m = {{'c', 12}, {'x',66}};
    auto p = m;
    CHECK(p == m);
    let q = move(m);
    CHECK(q == p);
    CHECK(q == p);
    CHECK(m.size() == 0);

    auto a = map_t<char, int>{{'x', 0}, {'y', 1}};
    p = a;
    CHECK(p == a);
    p = std::move(a);
    CHECK(a.size() == 0);
  }
}

}//[mto.ns_end]
