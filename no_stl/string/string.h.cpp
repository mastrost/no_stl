#include "./string.h"
#include "../vector/vector_impl.h"
#include "../vector/vector_comparison_impl.h"
#include "../tools/move.h"

#include "cpp_tools/defines.h"//[mto]
namespace mto::no_stl::string {//[mto.ns_begin]

namespace 
{
  void append_c_str(string_t & s, char const * str)
  {
    while(*str != 0)
      s.buf.push_back(*str++);
  }
}

string_t::string_t()
{
}

string_t::string_t(string_t const & o)
{
  buf = o.buf;
}

string_t::string_t(string_t && o)
{
  buf = tools::move(o.buf);
}

string_t::string_t(char const * str)
{
  append_c_str(*this, str);
}

string_t::string_t(char const * p, size_t n)
{
  for(size_t i=0 ; i<n ; ++i)
    buf.push_back(*p++);
}

string_t::~string_t()
{
}

char const* string_t::data() const
{
  return buf.data();
}

size_t string_t::size() const
{
  return buf.size();
}

char string_t::operator[](size_t i) const
{
  return buf[i];
}

string_t & string_t::operator=(string_t const & o)
{
  buf = o.buf;
  return *this;
}

string_t & string_t::operator=(string_t && o)
{
  buf = tools::move(o.buf);
  return *this;
}

void string_t::operator+=(char c)
{
  buf.push_back(c);
}

void string_t::operator+=(char const * o)
{
  append_c_str(*this, o);
}

void string_t::operator+=(string_t const & o)
{
  for(size_t i=0 ; i<o.size() ; ++i)
    buf.push_back(o.buf[i]);
}

void string_t::operator+=(string_t && o)
{
  for(size_t i=0 ; i<o.size() ; ++i)
    buf.push_back(o.buf[i]);
}

string_t string_t::operator+(char const * o) const
{
  string_t res = *this;
  res += o;
  return res;
}

string_t string_t::operator+(string_t const & o) const
{
  string_t res = *this;
  res += o;
  return res;
}

string_t string_t::operator+(string_t && o) const
{
  string_t res = *this;
  res += tools::move(o);
  return res;
}

bool string_t::operator==(string_t const & o) const
{
  return buf == o.buf;
}

bool string_t::operator!=(string_t const & o) const
{
  return buf != o.buf;
}

bool string_t::operator<(string_t const & o) const
{
  return buf < o.buf;
}

string_t operator+(char const * c_str, string_t const & str)
{
  string_t res(c_str);
  res += str;
  return res;
}

namespace literal
{
  string_t operator""_s(const char* p, size_t n)
  {
    return string_t(p, n);
  }
}

}//[mto.ns_end]

