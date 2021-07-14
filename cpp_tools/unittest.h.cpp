#include "unittest.h"

#include <vector>
#include <string>
#include <functional>
#include "cpp_tools/memory_leak_detector.h"
#include <stdexcept>

#include "cpp_tools/defines.h"//[mto]
namespace mto::cpp_tools {//[mto.ns_begin]

struct test_fn_t
{
  function<void()> f;
  bool check_memory_leak;
};

struct unittests_t
{
  void insert(test_fn_t f, char const * test_name)
  {
    tests.push_back({test_name, f});
  }

  void run()
  {
    for(let & f : tests)
    {
      if(f.second.check_memory_leak)
      {
        int allocs0 = g_num_allocs;
        f.second.f();
        int allocs1 = g_num_allocs;
        if(allocs0 != allocs1)
          throw runtime_error("Memory leak detected");
      }
      else
        f.second.f();
    }
  }

  vector<pair<string, test_fn_t>> tests;

  static unittests_t * get_instance()
  {
    static unittests_t instance;
    return &instance;
  }
};

test_t::test_t(void (*f)(), char const * test_name, bool check_memory_leak)
{
  unittests_t::get_instance()->insert({f, check_memory_leak}, test_name);
}

}//[mto.ns_end]

int main()
{
  try
  {
    ::mto::cpp_tools::unittests_t::get_instance()->run();
    return 0;
  }
  catch(std::exception const & e)
  {
    fprintf(stderr, "test failed: \n");
    fprintf(stderr, "%s\n", e.what());
    return 1;
  }
  catch(std::string const & str)
  {
    fprintf(stderr, "test failed: \n");
    fprintf(stderr, "%s\n", str.c_str());
    return 1;
  }
  catch(char const * str)
  {
    fprintf(stderr, "test failed: \n");
    fprintf(stderr, "%s\n", str);
    return 1;
  }
  catch(...)
  {
    fprintf(stderr, "test failed: \n");
    fprintf(stderr, "UNKNOWN REASON\n");
    return 1;
  }
}
