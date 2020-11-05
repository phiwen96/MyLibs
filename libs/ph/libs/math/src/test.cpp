#include <ph/math/test.hpp>
#include <ph/math/math.hpp>

#include <ph/math/point.hpp>
#include <ph/math/vector.hpp>


namespace ph::math
{
struct A
{
      A (){}
      template <class H, class... U>
      A (H, U...){}
//      A (const A&){}
//      A (A&&){}
//      A& operator= (A){return *this;}
//      friend void swap(A&, A&){using std::swap;}
};

struct B
{
//      B (const A& a){}
      B (A&& a){}
      
};



void Testing::run ()
{
      B b1({1, 2, 4});
      
      
//      test_point();
      test_vector();
}

void Testing::test_point ()
{
//      float f = 10;
//      point p1(f, 10.5f, 23.87f);
//      std::cout << p1.size() << std::endl;
//      point p2(-1, -2, -3);
//      std::cout << p2.size() << std::endl;
//      point p3(1, 2, 3);
//
//
//      p1 += p2;
//      std::cout << p2 << std::endl;
//      std::cout << p3 << std::endl;
//
//      std::cout << p2 + p3 << std::endl;
//
//      std::cout << p2 << std::endl;
//      std::cout << p3 << std::endl;
      
      
      // test magnitude
      point p4 (3, 4);
      std::cout << p4.size() << std::endl;
      std::cout << p4.magnitude() << std::endl;
}

void Testing::test_vector ()
{
//      vector v1 (sqrt(5), point(1/sqrt(5), 2/sqrt(5)));
//      std::cout << v1.position_vector() << std::endl;
//      vector v2 (sqrt(5), point(2/sqrt(5), 1/sqrt(5)));
//      std::cout << v2.position_vector() << std::endl;
//      v2 += v1;
//      std::cout << v1 << std::endl;
//      std::cout << v1.position_vector() << std::endl;
      
      point posvec1 (-2, 2);
//      vector v3 (posvec1.magnitude(), posvec1/posvec1.magnitude());
//      std::cout << v3 << std::endl;
      
      vector v4 = posvec1;
      std::cout << v4 << std::endl;
      
//      v4 += v3;
//      std::cout << v4 << std::endl;
      
//      v4 += v3;
//      std::cout << v4 << std::endl;
      
//      v4 -= v3;
//      std::cout << v4 << std::endl;
      
      point p = v4.position_vector();

//      point p2 = v4;
//      point p1 (v4);
//      std::cout << p;
      
      vector v5 = {1, 2, 3, 4, 3};
      vector v6 = {3, 4, 5, 7, 8};
//      v6 = v5;
      std::cout << v5 << std::endl;
      v5 += v6;
      std::cout << v5 << std::endl;
      v5 -= v6;
//      v4 += v6;
      std::cout << v5 << std::endl;
      std::cout << v6-v5 << std::endl;
//      std::cout << v5.dotproduct(v6) << std::endl;
      std::cout << dotproduct(v5, v6) << std::endl;
      std::cout << angle (v5, v6) << std::endl;
      std::cout << projection (v5, v6) << std::endl;
      
      
  

      
}


}



