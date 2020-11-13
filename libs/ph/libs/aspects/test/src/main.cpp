#include <test/main.hpp>
#include <ph/aspects/aspects.hpp>
#include <ph/aspects/test.hpp>
using namespace ph::aspects;

int main(int argc, char** argv)
{
      cout << "hi" << endl;
       
      
      Testing t;
      t.run ();
      
      
      // constexpr auto s2 = Size<int, char>::value;
    return 0;
}
