#include "./heap_variant_impl.h"
#include "cpp_tools/unittest.h"

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::heap_variant {//[mto.ns_begin]

template struct heap_variant_t<int, char const*>;

UNITTEST()
{
  heap_variant_t<int, char const*> v = 123;
  CHECK(v.is<int>());
  CHECK(!v.is<char const *>());
  CHECK((v.as<int>() == 123));

  heap_variant_t<int, double> w = 3.14;
  CHECK(w.is<double>());

  w.visit([](let & x)
      {
      return "coucou";
      });

  auto z = v;
}

}//[mto.ns_end]
