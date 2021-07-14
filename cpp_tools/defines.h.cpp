#include "defines.h"

#include <string>
#include <stdexcept>
#include <iostream>

void throw_ensure_exception(char const * expression, char const * file, int line)
{
  throw ::std::runtime_error(::std::string(expression) + " at " + file + ":" 
      + ::std::to_string(line) + " is false");
}

void throw_ensure_throws_exception(char const * expression, char const * file, int line)
{
  throw ::std::runtime_error(::std::string(expression) + " at " + file + ":" 
      + ::std::to_string(line) + " should throw");
}

void throw_check_exception(char const * expression, char const * file, int line)
{
  throw ::std::runtime_error("Precondition: '" + ::std::string(expression) 
      + "' at " + file + ":" + ::std::to_string(line) + " is false");
}

void print_not_impl(char const * file, int line)
{
  std::cerr << "NOT IMPLEMENTED at " << file << ":" << line << std::endl;
}

