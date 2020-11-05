#pragma once
#include <ph/testing/testing.hpp>


namespace ph::math
{


struct Testing : ph::testing::Testing
{
      virtual void run () override;
      
private:
      void test_point ();
      void test_vector ();
    
};







}
