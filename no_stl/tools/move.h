#pragma once

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::tools {//[mto.ns_begin]
template<typename T>
struct remove_reference
{
  typedef T type;
};
template<typename T>
struct remove_reference<T&>
{
  typedef T type;
};
template<typename T>
struct remove_reference<T&&>
{
  typedef T type;
};
template<typename T>
constexpr typename remove_reference<T>::type&&
move(T&& arg) noexcept
{
  return static_cast<typename remove_reference<T>::type&&>(arg);
}
}//[mto.ns_end]
