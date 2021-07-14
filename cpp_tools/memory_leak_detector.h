#pragma once

#include <new>
#include <cstdlib>
#include <atomic>

std::atomic<int> g_num_allocs = 0;

void * operator new(std::size_t n)
{
  ++g_num_allocs;
  return malloc(n);
}

void operator delete(void * p) noexcept
{
  --g_num_allocs;
  free(p);
}

void *operator new[](std::size_t n)
{
  ++g_num_allocs;
  return malloc(n);
}

void operator delete[](void *p) noexcept
{
  --g_num_allocs;
  free(p);
}

