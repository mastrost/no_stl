#include "./string.h"
#include "./std_hash.h"
#include "./std_stream.h"

#include "no_stl/unordered_set/unordered_set_impl.h"
#include "cpp_tools/unittest.h"

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::string {//[mto.ns_begin]

using namespace literal;

UNITTEST()
{
  {
    string_t s = "toto";
    CHECK(s.size() == 4);
    string_t s2 = s;
    CHECK(s == s2);
    s = "blabla"_s;
    CHECK(s == "blabla");
    s = s2;
    CHECK(s == "toto");

    s2 = "toto";
    s2 += "titi";
    s2 += "tutu"_s;
    CHECK(s2 == "tototititutu");

    s = "a"_s + "b"_s + "c";
    CHECK(s == "abc");

    unordered_set::unordered_set_t<string_t> ss;
    ss.insert("123");
  }

  {
    let s = "toto" + "titi"_s;
    CHECK(s == "tototiti");
  }
}

}//[mto.ns_end]
