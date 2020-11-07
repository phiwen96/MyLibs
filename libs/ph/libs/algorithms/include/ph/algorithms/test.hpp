#pragma once
#include <ph/testing/testing.hpp>
#include <ph/algorithms/algorithms.hpp>
#include <ph/utility/utility.hpp>
using namespace ph::utility;

namespace ph::algorithms
{


struct Testing : ph::testing::Testing
{
      virtual void run () override
      {
            test_insertion_sort ();
            test_selection_sort ();
      }
      
      void test_insertion_sort ()
      {
            vector<int> v = {5, 2, 4, 6, 1, 3};
            
            cout << "first: ";
            cout << "\t" << v << endl << endl;
            
            insertion_sort(v, [](int i, int j)->bool{return i > j;});
            
            cout << "second: " << "\t" << v << endl << endl;
            
            insertion_sort(v, [](int i, int j)->bool{return i < j;});
            
            cout << "third: " << "\t" << v << endl << endl;
            
      }
      
      void test_selection_sort ()
      {
            vector<int> A = {5, 2, 4, 6, 1, 3};
            
            cout << "first: ";
            cout << "\t" << A << endl << endl;
            
            selection_sort(A, [](int candidate, int current)->bool{return candidate < current;});
            
            cout << "second: " << "\t" << A << endl << endl;
            
      }
      
private:
      
};







}
