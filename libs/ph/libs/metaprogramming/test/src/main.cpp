#include <test/main.hpp>
#include <ph/metaprogramming/metaprogramming.hpp>
#include <ph/metaprogramming/test.hpp>
using namespace ph::metaprogramming;

int main(int argc, char** argv)
{
       
      Testing t;
      t.run();
      
      
      
      // constexpr auto s2 = Size<int, char>::value;
    return 0;
}
