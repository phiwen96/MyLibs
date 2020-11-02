#include <test/main.hpp>
#include <ph/metaprogramming/metaprogramming.hpp>
using namespace ph::metaprogramming;

int main(int argc, char** argv)
{
       constexpr size_t s = Size<tuple<int, float, void>>::value;
       cout << s << endl;
      vector<int> i = {1,2,3,4};
      
      
      
      // constexpr auto s2 = Size<int, char>::value;
    return 0;
}
