#include <ph/math/test.hpp>
#include <ph/math/math.hpp>

#include <ph/math/point.hpp>
#include <ph/math/vector.hpp>
#include <ph/math/plane.hpp>
#include <ph/math/line.hpp>

namespace ph::math
{




void Testing::run ()
{
      test_point();
      test_vector();
      test_line();
      test_plane();
}

void Testing::test_point ()
{
      point p4 (3, 4);
//      std::cout << p4.size() << std::endl;
//      std::cout << p4.magnitude() << std::endl;
}

void Testing::test_vector ()
{
      point p1 (0, 4);
      std::cout << typeid(p1).name();//::live () << std::endl;
      std::cout << p1 << std::endl;
      point posvec1 (-2, 2);

      vector v4 = posvec1;
      std::cout << v4 << std::endl;

      
      point p = v4.position_vector();
      vector v5 = {1, 2, 3, 4, 3};
      vector v6 = {3, 4, 5, 7, 8};
      std::cout << v5 << std::endl;
      std::cout << v5 << std::endl;
      v5 -= v6;
      std::cout << v5 << std::endl;
      std::cout << v6-v5 << std::endl;
      std::cout << dotproduct(v5, v6) << std::endl;
      std::cout << angle (v5, v6) << std::endl;
      std::cout << projection (v5, v6) << std::endl;
}

void Testing::test_line ()
{
      
}

void Testing::test_plane ()
{
      
}


}



