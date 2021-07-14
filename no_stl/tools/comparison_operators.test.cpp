#include "./comparison_operators.h"
#include "./cpp_tools/unittest.h"

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::tools {//[mto.ns_begin]

struct a0_t
{
};

struct a1_t
{
  int x;
};

struct a2_t
{
  int x;
  float y;
};

UNITTEST()
{
  CHECK(equals_0(a0_t{}, a0_t{}));
  CHECK(!inf_0(a0_t{}, a0_t{}));

  CHECK(equals_1(a1_t{12}, a1_t{12}));
  CHECK(!equals_1(a1_t{11}, a1_t{12}));
  CHECK(inf_1(a1_t{12}, a1_t{13}));
  CHECK(!inf_1(a1_t{13}, a1_t{13}));
  CHECK(!inf_1(a1_t{14}, a1_t{13}));

  CHECK(equals_2(a2_t{12, 3.}, a2_t{12, 3.}));
  CHECK(!equals_2(a2_t{13, 3.}, a2_t{12, 3.}));
  CHECK(!equals_2(a2_t{12, 3.}, a2_t{12, 4.}));
  CHECK(inf_2(a2_t{11, 4.}, a2_t{12, 3.}));
  CHECK(inf_2(a2_t{12, 2.}, a2_t{12, 3.}));
  CHECK(!inf_2(a2_t{12, 3.}, a2_t{12, 3.}));
  CHECK(!inf_2(a2_t{13, 3.}, a2_t{12, 3.}));
  CHECK(inf_2(a2_t{12, 2.}, a2_t{12, 4.}));
}

}//[mto.ns_end]
