#pragma once

#include "../vector/vector.h"

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::string {//[mto.ns_begin]

struct string_t
{
  string_t();
  string_t(string_t const &);
  string_t(string_t &&);
  string_t(char const *);
  string_t(char const * p, size_t n);
  ~string_t();

  char const* data() const;
  size_t size() const;
  char operator[](size_t) const;
  string_t & operator=(string_t const &);
  string_t & operator=(string_t &&);

  void operator+=(char);
  void operator+=(char const *);
  void operator+=(string_t const &);
  void operator+=(string_t &&);

  string_t operator+(char const *) const;
  string_t operator+(string_t const &) const;
  string_t operator+(string_t &&) const;

  bool operator==(string_t const &) const;
  bool operator!=(string_t const &) const;
  bool operator<(string_t const &) const;

  vector::vector_t<char> buf;
};

string_t operator+(char const *, string_t const &);

namespace literal
{
  string_t operator"" _s(const char* str, size_t);
}

}//[mto.ns_end]
