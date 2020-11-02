#include <test/main.hpp>
#include <ph/metaprogramming/metaprogramming.hpp>
using namespace ph::metaprogramming;

int main(int argc, char** argv)
{
      constexpr auto s = Size<int, tuple<int, float, void>>::value;
      cout << s << endl;
    return 0;
}
