#pragma once

#define let auto const 
#define let_mutable auto

#include <cstdint>

using namespace std;

void throw_ensure_exception(char const * expression, char const * file, int line);

#define ENSURE(expr) \
	if(!(expr)) \
        throw_ensure_exception(#expr, __FILE__, __LINE__)

void throw_ensure_throws_exception(char const * expression, char const * file, int line);

#define ENSURE_THROWS(expr) \
		{ \
			bool hasThrown = false; \
			try { (expr); } \
			catch(...) { hasThrown = true; } \
			if(!hasThrown) \
                throw_ensure_throws_exception(#expr, __FILE__, __LINE__); \
		}

void throw_check_exception(char const * expression, char const * file, int line);

#define CHECK(expr) \
	if(!(expr)) \
        throw_check_exception(#expr, __FILE__, __LINE__)

void print_not_impl(char const * file, int line);

#define EXIT_NOT_IMPL() \
{ \
  print_not_impl( __FILE__, __LINE__); \
  exit(1); \
}

