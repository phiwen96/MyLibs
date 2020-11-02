#pragma once
#include <ph/testing/testing.hpp>

namespace ph::metaprogramming
{


struct Testing : ph::testing::Testing
{
      virtual void run () override;
      
private:
      void test_Size ();
      void test_push_back ();
      void test_pop_front ();
      void test_rename ();
      void test_concat ();
};







}
