#include <test/main.hpp>
#include <ph/math/math.hpp>
#include <ph/math/point.hpp>
#include <ph/math/test.hpp>
#include <ph/math/point.hpp>
#include <ph/math/vector.hpp>
#include <ph/math/plane.hpp>
#include <ph/math/line.hpp>
#include <ph/math/matrix.hpp>
#include <vector>


int random (int f, int l)
{
      std::random_device dev;
      std::mt19937 rng(dev());
      std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6); // distribution in range [1, 6]
      
      std::cout << dist6(rng) << std::endl;
      return dist6(rng);
}











      
using namespace ph::math;

struct T{};

int main(int argc, char** argv)
{
      
       
      Matrix<2, 3, int> m1 = {{1, 2, 3}, {4, 5, 6}};
      Matrix<3, 2, int> m2 = {{7, 8}, {9, 10}, {11, 12}};
      
      
      Matrix<4, 2, int> m3 = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
      Matrix<2, 4, int> m4 = {{9, 10, 11, 12}, {13, 14, 15, 16}};
      
      Matrix<1, 3, int> m5 = {1, 2, 3};
      Matrix<3, 1, int> m6 = {4, 5, 6};
     
      Matrix<2, 2, int> m7 = {{1, 2}, {3, 4}};
      Matrix<2, 2, int> m8 = {{5, 6}, {7, 8}};
      
      

      
//      int i = get_right_distribution<int>(1, 6)(gen);
//
//      auto float_dis = get_right_distribution(1.F, 6.F);
//      std::cout << float_dis(gen) << "\n";
      
      
      
      auto i = m1 * m2;
//      cout << i << endl;
      
    

//      cout << i << endl;
      
      
      
//      cout << m1 << endl;
//      cout << m1_transposed << endl;
    return 0;
}
