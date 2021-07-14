#pragma once

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::unique_ptr {//[mto.ns_begin]

template <typename _t> struct unique_ptr
{
  public:
    unique_ptr() = delete;
    unique_ptr(unique_ptr<_t> const &) = delete;
    unique_ptr<_t> & operator=(unique_ptr<_t> const &) = delete;

    template <typename _s> unique_ptr(_s * p);
    template <typename _s> unique_ptr(unique_ptr<_s> &&);
    ~unique_ptr();

    _t & operator*() const;
    _t * operator->() const;
    _t * get() const;
    void release();

  private:
    _t * p;
};

}//[mto.ns_end]
