#include <ph/math/test.hpp>
#include <ph/math/math.hpp>

#include <ph/math/point.hpp>
#include <ph/math/vector.hpp>
#include <ph/math/plane.hpp>
#include <ph/math/line.hpp>
#include <ph/math/matrix.hpp>

namespace ph::math
{




void Testing::run ()
{
//      test_point();
//      test_vector();
//      test_line();
//      test_plane();
      test_matrix();
}

template<size_t S, typename T>
struct A
{
      A (std::array<T, S> d) : d(d)
      {
            
      }
      A(){}
      
      T d[S];
      
};

//template<class T, class... U>
//struct B
//{
//
////      template <typename std::enable_if_t<std::is_integral<T...>::value, bool> = true>
//      B (T, U...)
//      {
//
//      }
//
////      friend ostream& operator<< (ostream& os, const B& b)
////      {
////            os <<
////      }
//
//
//
//};

//template <class T>
//B (vector<T> v) -> B<std::integer_sequence<T, v.size()>>;

//template <class T>
//A (const std::initializer_list<T>& i) -> A<i.size(), T>;

//template <class T>
//A (const std::initializer_list<T>& i) -> A<i.size(), T>;

//template <class T, class... U>
//A (T, U...) -> A<sizeof...(U) + 1, T>;

//template <class T, class... U>
//A (T t, U... u) -> A(std::array<T, sizeof...(U) + 1>{t, u...}>;

void Testing::test_point ()
{
     
      auto i1 = {1, 2, 3};
//      static_assert(std::is_same<decltype(i1), std::initializer_list<double>>::value, "wtf");
//      A a0 {1, 2};
//      A a1 (i1);
//      A a2 (1, 2);
      
//      B b1(true);
//      B b2 (std::vector<int>{1, 2});
      
      
      
      point p0 (3, 4);
      point p1 (2, 3);
      point p2 = {1, 2, 3};
      std::cout << typeid(p1).name() << "\n" << typeid(p2).name() << std::endl;
      double p6[] = {1, 4, 5};
      auto f = {1, 2, 3};
      std::initializer_list<double> k = {1, 2, 3};
      
      point p7 (k);
      std::cout << typeid(f).name() << "\n" << typeid(p6).name() << std::endl;
      std::cout << p6 << std::endl;
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
      vector v5 = point{1, 2, 3, 4, 3};
      vector v6 = point{3, 4, 5, 7, 8};
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

void Testing::test_matrix ()
{
      using namespace std;
      
//      Row<3, double> r1 (1, 2, 3);
//      Row<3, float> r2 (4, 5, 6);
//      Row<3, float> r3 (r1);
//      Row<3, float> r4 (r2);
//
//      constexpr int x = 3;
//      constexpr int y = 4;
      Row<3, int> a (1, 2, 3);
      cout << a[1] << endl;
      cout << a - 6 << endl;
      Column<3, int> a2 = a;
      cout << a << endl;
      cout << a2 << endl;
      Column<3, int> b = a;
      cout << b << endl;
      Column<3, int> a1 (1, 2, 3);
      Column<3, int> a3 (1, 2, 3);
//      cout << (a + a1) << endl;
      
      a1 *= a;
      cout << a << endl;
     
      
      Matrix<2, 3, int> m1 = {
            {1, 2, 3},
            {4, 5, 6}
      };
      cout << m1 << endl;
      
      Matrix<3, 2, int> m2 = {
            {7, 8},
            {9, 10},
            {11, 2}
      };
     

//      cout << m2 << endl;
//      auto i = m1 * m2;
//      cout << i << endl;

      
      
      
      
      
//      _Matrix<2, 3, float> m1;
//      _Matrix<2, 3, float> m2 (r2, r3);
      
//      cout << m1 << endl;
//      cout << m2 << endl;
      
//      _Matrix<3, 3, double> m1 (r2);

      
      
}


}



