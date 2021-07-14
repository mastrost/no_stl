#pragma once

#include "no_stl/heap_variant/heap_variant.h"

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::result {//[mto.ns_begin]

namespace hv = ::mto::no_stl::heap_variant;

template <typename _t, typename error_t> 
struct result_t
{
  result_t(result_t const &);
  result_t(result_t &&);

  result_t(_t const &);
  result_t(_t &&);
  result_t(error_t const &);
  result_t(error_t &&);
  ~result_t();

  result_t & operator=(result_t const &);
  result_t & operator=(result_t &&);
  _t const & operator*() const;
  _t const & get() const;
  error_t const & get_error() const;
  _t const * get_ptr() const;
  error_t const * get_error_ptr() const;

  operator bool() const;

  hv::heap_variant_t<_t, error_t> v;
};

/**
 * Warning!
 * Prefer not to use GET_RES in sub expresssions.
 * In particular, a 'return' from the GET_RES "expression statement"
 * may not call the destructors of variables of other sibling GET_RES.
 * i.e. in the following example, the destructor of the variable returned
 * from 'f()' is never called when 'g()' returns an error.
 * return a_t {
 *   f(),
 *   GET_RES(g()),
 * }
 */
#define GET_RES(expr) \
  ({\
   let var##__res = (expr); \
   if(!(var##__res)) \
     return var##__res.get_error();\
   *var##__res;\
   })


}//[mto.ns_end]
