#pragma once

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::tools {//[mto.ns_begin]

template <typename _t> bool equals_0(_t const & x, _t const & y)
{
  return true;
}

template <typename _t> bool inf_0(_t const & x, _t const & y)
{
  return false;
}

template <typename _t> bool equals_1(_t const & x, _t const & y)
{
  let & [x0] = x;
  let & [y0] = y;
  return (x0 == y0);
}

template <typename _t> bool equals_2(_t const & x, _t const & y)
{
  let & [x0, x1] = x;
  let & [y0, y1] = y;
  return (x0 == y0) && (x1 == y1);
}

template <typename _t> bool inf_1(_t const & x, _t const & y)
{
  let & [x0] = x;
  let & [y0] = y;
  return (x0 < y0);
}

template <typename _t> bool inf_2(_t const & x, _t const & y)
{
  let & [x0, x1] = x;
  let & [y0, y1] = y;
  return (x0 < y0) || ( (x0 == y0) && (x1 < y1) );
}

}//[mto.ns_end]
