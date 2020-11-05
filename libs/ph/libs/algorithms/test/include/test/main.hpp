#pragma once
#include <ph/algorithms/algorithms.hpp>
#include <ph/utility/utility.hpp>
using namespace ph::utility;

struct Test
{
      void run ()
      {
            test_insertion_sort ();
      }
      
      void test_insertion_sort ()
      {
            vector<int> v = {5, 2, 4, 6, 1, 3};
            cout << "before:\n";
            cout << v << endl;
            
      }
      
      
};
