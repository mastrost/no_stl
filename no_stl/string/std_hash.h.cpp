#include "./std_hash.h"
#include <string_view>

namespace std
{
  size_t hash<::mto::no_stl::string::string_t>::operator()(::mto::no_stl::string::string_t const & x) const noexcept
  {
    let view = std::string_view(x.data(), x.size());
    return std::hash<string_view>()(view);
  }
}
