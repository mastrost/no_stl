#pragma once

#include "./string.h"
#include <functional>

namespace std
{
  template <>
  struct hash<::mto::no_stl::string::string_t>
  {
    size_t operator()(::mto::no_stl::string::string_t const & x) const noexcept;
  };
}

